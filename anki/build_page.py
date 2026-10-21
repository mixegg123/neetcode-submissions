"""Build the review page (HTML) from anki/neetcode.tsv.

Usage: python3 -I anki/build_page.py OUTPUT.html
Run from the repo root. Each card's date comes from its date:: tag, its
problem from its src:: tag, and the solution link points at the highest
numbered submission in that problem's folder.
"""
import datetime
import json
import os
import re
import sys
from urllib.parse import quote

DSA = "Data Structures & Algorithms"
TSV = "anki/neetcode.tsv"
REPO = "https://github.com/mixegg123/neetcode-submissions/blob/main/"

TOPIC_NAMES = {
    "dp-1d": "1D DP", "dp-2d": "2D DP", "graph": "Graph", "tree": "Tree",
    "bit": "Bit", "hashing": "Hashing", "math": "Math", "two-pointers": "Two Pointers",
    "backtracking": "Backtracking", "linked-list": "Linked List",
    "binary-search": "Binary Search", "heap": "Heap", "greedy": "Greedy",
}


def latest_submission(folder):
    path = os.path.join(DSA, folder)
    nums = [int(m.group(1)) for f in os.listdir(path)
            if (m := re.fullmatch(r"submission-(\d+)\.\w+", f))]
    n = max(nums)
    name = next(f for f in os.listdir(path) if f.startswith(f"submission-{n}."))
    return n, REPO + quote(f"{DSA}/{folder}/{name}")


def load_cards():
    cards = []
    for line in open(TSV, encoding="utf-8").read().splitlines():
        if line.startswith("#") or not line.strip():
            continue
        guid, front, back, tags = line.split("\t")
        tags = tags.split()
        date = next(t[6:] for t in tags if t.startswith("date::"))
        src = next((t[5:] for t in tags if t.startswith("src::")), None)
        topics = [TOPIC_NAMES.get(t[10:], t[10:]) for t in tags if t.startswith("neetcode::")]
        kind = ("pattern" if "pattern" in tags else "habit" if "habit" in tags
                else "cpp" if "cpp" in tags else "problem")
        if kind == "cpp":
            topics.append("C++")
        card = {"id": guid, "front": front, "back": back, "date": date,
                "topics": topics, "kind": kind, "pitfall": "pitfall" in tags}
        if src:
            n, url = latest_submission(src)
            card.update(src=src, problem="https://neetcode.io/problems/" + src,
                        solution=url, sub=n)
        cards.append(card)
    cards.sort(key=lambda c: c["date"], reverse=True)
    return cards


def main(out):
    cards = load_cards()
    data = json.dumps(cards, ensure_ascii=False).replace("</", "<\\/")
    built = datetime.date.today().isoformat()
    html = PAGE.replace("__DATA__", data).replace("__BUILT__", built)
    with open(out, "w", encoding="utf-8") as f:
        f.write(html)
    print(f"{len(cards)} cards -> {out}")


PAGE = r"""<title>NeetCode 複習卡</title>
<link rel="preconnect" href="https://fonts.googleapis.com">
<link rel="preconnect" href="https://fonts.gstatic.com" crossorigin>
<link rel="stylesheet" href="https://fonts.googleapis.com/css2?family=JetBrains+Mono:wght@400;600&family=Noto+Sans+TC:wght@400;500;700&display=swap">
<style>
/* Layout: one reading column of ruled index cards, grouped by study date, under a sticky filter bar. */
:root {
  --bg: #eef1f4; --surface: #ffffff; --ink: #18212b; --muted: #5a6674;
  --line: #d6dde5; --accent: #1d58b8; --accent-soft: #e3ecfa;
  --rule: #d2454f; --rule-soft: #fbe7e8; --ok: #2c7548; --ok-soft: #e2f2e7;
  --sans: "Noto Sans TC", "PingFang TC", "Microsoft JhengHei", system-ui, sans-serif;
  --mono: "JetBrains Mono", ui-monospace, "SFMono-Regular", Menlo, monospace;
}
@media (prefers-color-scheme: dark) { :root:not([data-theme="light"]) {
  --bg: #0f141a; --surface: #182029; --ink: #e5eaf0; --muted: #98a4b2;
  --line: #2a3542; --accent: #82aaf5; --accent-soft: #1d2b42;
  --rule: #f0848b; --rule-soft: #3a2125; --ok: #79c995; --ok-soft: #1c3326;
  color-scheme: dark; } }
:root[data-theme="dark"] {
  --bg: #0f141a; --surface: #182029; --ink: #e5eaf0; --muted: #98a4b2;
  --line: #2a3542; --accent: #82aaf5; --accent-soft: #1d2b42;
  --rule: #f0848b; --rule-soft: #3a2125; --ok: #79c995; --ok-soft: #1c3326;
  color-scheme: dark; }
* { box-sizing: border-box; }
body { background: var(--bg); color: var(--ink); font-family: var(--sans); font-size: 15px; line-height: 1.65; }
.wrap { max-width: 760px; margin: 0 auto; padding-inline: 16px; padding-block: 20px 48px; }
header h1 { font-size: 1.6rem; line-height: 1.25; margin: 0; text-wrap: balance; letter-spacing: .01em; }
header p { margin: .25rem 0 0; color: var(--muted); font-size: .85rem; }
.mono { font-family: var(--mono); font-variant-numeric: tabular-nums; }
.bar { position: sticky; top: env(safe-area-inset-top, 0px); z-index: 2; background: var(--bg);
  display: flex; flex-wrap: wrap; gap: 8px; align-items: center; padding-block: 12px; margin-top: 12px;
  border-bottom: 1px solid var(--line); }
.chip { font: inherit; font-size: .85rem; border: 1px solid var(--line); background: var(--surface); color: var(--ink);
  border-radius: 999px; padding: 4px 12px; cursor: pointer; }
.chip[aria-pressed="true"] { background: var(--accent); border-color: var(--accent); color: var(--surface); }
.chip:focus-visible, button:focus-visible, select:focus-visible, a:focus-visible { outline: 2px solid var(--accent); outline-offset: 2px; }
.chip .n { font-family: var(--mono); opacity: .75; margin-left: 4px; }
select { font: inherit; font-size: .85rem; border: 1px solid var(--line); background: var(--surface); color: var(--ink);
  border-radius: 999px; padding: 4px 10px; }
.sep { width: 1px; height: 20px; background: var(--line); }
section { display: grid; gap: 14px; margin-top: 28px; }
section h2 { font-size: .8rem; letter-spacing: .08em; color: var(--muted); margin: 0; font-weight: 500;
  display: flex; gap: 10px; align-items: baseline; }
section h2 .d { font-family: var(--mono); font-size: 1rem; color: var(--ink); letter-spacing: 0; font-weight: 600; }
.card { background: var(--surface); border: 1px solid var(--line); border-radius: 6px;
  background-image: linear-gradient(var(--rule), var(--rule)); background-size: 100% 2px;
  background-position: 0 44px; background-repeat: no-repeat; min-width: 0; }
.meta { display: flex; flex-wrap: wrap; gap: 6px; align-items: center; padding: 10px 16px; min-height: 44px; font-size: .78rem; color: var(--muted); }
.tag { border: 1px solid var(--line); border-radius: 4px; padding: 0 6px; }
.tag.pit { border-color: var(--rule); color: var(--rule); background: var(--rule-soft); }
.meta .when { font-family: var(--mono); margin-left: auto; }
.front { padding: 14px 16px 4px; font-size: 1.02rem; font-weight: 500; }
.actions { display: flex; flex-wrap: wrap; gap: 10px; align-items: center; padding: 10px 16px 14px; }
.reveal { font: inherit; font-size: .9rem; font-weight: 500; border: 1px solid var(--accent); color: var(--accent);
  background: transparent; border-radius: 6px; padding: 5px 14px; cursor: pointer; }
.links { display: flex; flex-wrap: wrap; gap: 14px; margin-left: auto; font-size: .85rem; }
.links a { color: var(--accent); text-decoration: none; }
.links a:hover { text-decoration: underline; }
.back { border-top: 1px dashed var(--line); padding: 12px 16px 14px; }
.back .ans { min-width: 0; overflow-wrap: anywhere; }
code { font-family: var(--mono); font-size: .88em; background: var(--accent-soft); border-radius: 3px; padding: 1px 4px; }
.rate { display: flex; flex-wrap: wrap; gap: 8px; align-items: center; margin-top: 12px; font-size: .82rem; color: var(--muted); }
.rate button { font: inherit; font-size: .85rem; border-radius: 6px; padding: 3px 12px; cursor: pointer; border: 1px solid var(--line); background: var(--surface); color: var(--ink); }
.rate button.again[aria-pressed="true"] { background: var(--rule-soft); border-color: var(--rule); color: var(--rule); }
.rate button.good[aria-pressed="true"] { background: var(--ok-soft); border-color: var(--ok); color: var(--ok); }
.empty { margin-top: 40px; text-align: center; color: var(--muted); }
.empty button { margin-top: 10px; }
@media (prefers-reduced-motion: no-preference) { .back { animation: in .18s ease-out; } }
@keyframes in { from { opacity: .4; transform: translateY(-3px); } to { opacity: 1; transform: none; } }
</style>

<div class="wrap">
  <header>
    <h1>NeetCode 複習卡</h1>
    <p>共 <span class="mono" id="total"></span> 張 · 更新於 <span class="mono">__BUILT__</span> · 先自己回答,再按「看答案」</p>
  </header>

  <div class="bar" role="toolbar" aria-label="篩選">
    <button class="chip" id="r3" data-range="3">最近 3 天<span class="n"></span></button>
    <button class="chip" id="r7" data-range="7">最近 7 天<span class="n"></span></button>
    <button class="chip" id="rall" data-range="all">全部<span class="n"></span></button>
    <span class="sep" aria-hidden="true"></span>
    <button class="chip" id="pit" aria-pressed="false">只看易錯</button>
    <button class="chip" id="miss" aria-pressed="false">只看「還不會」</button>
    <select id="topic" aria-label="類型"><option value="">所有類型</option></select>
    <button class="chip" id="openall" aria-pressed="false">全部展開</button>
  </div>

  <main id="list"></main>
  <div class="empty" id="empty" hidden>
    <p>這個範圍沒有卡片。</p>
    <button class="chip" id="showall">看全部卡片</button>
  </div>
</div>

<script>
const CARDS = __DATA__;
const WD = ["日", "一", "二", "三", "四", "五", "六"];
const store = {
  get(k, d) { try { const v = localStorage.getItem(k); return v ? JSON.parse(v) : d; } catch (e) { return d; } },
  set(k, v) { try { localStorage.setItem(k, JSON.stringify(v)); } catch (e) {} },
};
let state = Object.assign({ range: "3", pit: false, miss: false, topic: "", openAll: false }, store.get("nc-filter", {}));
let ratings = store.get("nc-ratings", {});
const opened = new Set();

function today() { const d = new Date(); return new Date(d.getFullYear(), d.getMonth(), d.getDate()); }
function parse(s) { const [y, m, d] = s.split("-").map(Number); return new Date(y, m - 1, d); }
function ageDays(s) { return Math.round((today() - parse(s)) / 86400000); }
function inRange(c, r) { return r === "all" || ageDays(c.date) < Number(r); }
function label(s) { const d = parse(s); return `${d.getMonth() + 1}/${d.getDate()}(${WD[d.getDay()]})`; }

function matches(c, r) {
  if (!inRange(c, r)) return false;
  if (state.pit && !c.pitfall) return false;
  if (state.miss && (ratings[c.id] || {}).r !== "again") return false;
  if (state.topic && !c.topics.includes(state.topic)) return false;
  return true;
}

function el(tag, cls, html) { const e = document.createElement(tag); if (cls) e.className = cls; if (html != null) e.innerHTML = html; return e; }
function text(tag, cls, t) { const e = document.createElement(tag); if (cls) e.className = cls; e.textContent = t; return e; }

function cardView(c) {
  const art = el("article", "card");
  const meta = el("div", "meta");
  c.topics.forEach(t => meta.append(text("span", "tag", t)));
  if (c.kind === "pattern") meta.append(text("span", "tag", "模版"));
  if (c.kind === "habit") meta.append(text("span", "tag", "習慣"));
  if (c.pitfall) meta.append(text("span", "tag pit", "易錯"));
  meta.append(text("span", "when", c.date));
  art.append(meta, el("div", "front", c.front));

  const actions = el("div", "actions");
  const btn = text("button", "reveal", "看答案");
  btn.type = "button";
  actions.append(btn);
  if (c.src) {
    const links = el("div", "links");
    const a1 = text("a", null, "題目 ↗"); a1.href = c.problem; a1.target = "_blank"; a1.rel = "noopener";
    const a2 = text("a", null, `我的解答 #${c.sub} ↗`); a2.href = c.solution; a2.target = "_blank"; a2.rel = "noopener";
    links.append(a1, a2);
    actions.append(links);
  }
  art.append(actions);

  const back = el("div", "back");
  back.append(el("div", "ans", c.back));
  const rate = el("div", "rate");
  const again = text("button", "again", "還不會");
  const good = text("button", "good", "會了");
  again.type = good.type = "button";
  const note = text("span", null, "");
  function paint() {
    const r = ratings[c.id];
    again.setAttribute("aria-pressed", String(r && r.r === "again"));
    good.setAttribute("aria-pressed", String(r && r.r === "good"));
    note.textContent = r ? `上次標記:${r.d}` : "自評後會記在這台裝置上";
  }
  function mark(v) { ratings[c.id] = { r: v, d: new Date().toISOString().slice(0, 10) }; store.set("nc-ratings", ratings); paint(); updateCounts(); }
  again.onclick = () => mark("again");
  good.onclick = () => mark("good");
  paint();
  rate.append(again, good, note);
  back.append(rate);

  const isOpen = () => state.openAll || opened.has(c.id);
  back.hidden = !isOpen();
  btn.textContent = isOpen() ? "收起答案" : "看答案";
  btn.setAttribute("aria-expanded", String(isOpen()));
  btn.onclick = () => {
    opened.has(c.id) ? opened.delete(c.id) : opened.add(c.id);
    back.hidden = !isOpen();
    btn.textContent = isOpen() ? "收起答案" : "看答案";
    btn.setAttribute("aria-expanded", String(isOpen()));
  };
  art.append(back);
  return art;
}

function updateCounts() {
  document.querySelectorAll("[data-range]").forEach(b => {
    b.setAttribute("aria-pressed", String(b.dataset.range === state.range));
    b.querySelector(".n").textContent = CARDS.filter(c => matches(c, b.dataset.range)).length;
  });
}

function render() {
  store.set("nc-filter", state);
  document.getElementById("pit").setAttribute("aria-pressed", String(state.pit));
  document.getElementById("miss").setAttribute("aria-pressed", String(state.miss));
  document.getElementById("openall").setAttribute("aria-pressed", String(state.openAll));
  document.getElementById("topic").value = state.topic;
  updateCounts();
  const list = document.getElementById("list");
  list.replaceChildren();
  const shown = CARDS.filter(c => matches(c, state.range));
  const byDate = new Map();
  shown.forEach(c => { if (!byDate.has(c.date)) byDate.set(c.date, []); byDate.get(c.date).push(c); });
  byDate.forEach((cs, d) => {
    const sec = el("section");
    const h = el("h2");
    h.append(text("span", "d", label(d)), text("span", null, `${cs.length} 張`));
    sec.append(h);
    cs.forEach(c => sec.append(cardView(c)));
    list.append(sec);
  });
  document.getElementById("empty").hidden = shown.length > 0;
}

document.getElementById("total").textContent = CARDS.length;
const topics = [...new Set(CARDS.flatMap(c => c.topics))].sort();
const sel = document.getElementById("topic");
topics.forEach(t => { const o = text("option", null, t); o.value = t; sel.append(o); });
if (state.topic && !topics.includes(state.topic)) state.topic = "";
document.querySelectorAll("[data-range]").forEach(b => b.onclick = () => { state.range = b.dataset.range; render(); });
document.getElementById("pit").onclick = () => { state.pit = !state.pit; render(); };
document.getElementById("miss").onclick = () => { state.miss = !state.miss; render(); };
document.getElementById("openall").onclick = () => { state.openAll = !state.openAll; opened.clear(); render(); };
sel.onchange = () => { state.topic = sel.value; render(); };
document.getElementById("showall").onclick = () => { state = Object.assign(state, { range: "all", pit: false, miss: false, topic: "" }); render(); };
render();
</script>
"""

if __name__ == "__main__":
    main(sys.argv[1])
