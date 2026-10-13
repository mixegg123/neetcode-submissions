# CLAUDE.md

這個 repo 是 NeetCode 自動同步的刷題紀錄(C++)。`Data Structures & Algorithms/<題目>/submission-N.cpp`
每個檔案是一次提交,不論是否通過。NeetCode 直接推到 `main`,不要手動修改這些解答檔。

## 使用者背景

- 回覆用繁體中文,直接、精簡、專家口吻。
- 在職,每週約 6–7 小時。目標:2028/9 起刷 Google tag 題,目標公司 Google、Apple、NVIDIA、Meta、Microsoft,
  方向是軟體端的 embedded / TPU / 加速器(firmware、驅動、runtime)。
- 兩年計畫:
  - P1 2026/10–2027/4:補完 NeetCode 150
  - P2 2027/5–9:Medium/Hard、NC150 外補充清單、低階實作題(ring buffer、memory pool、bitset 等)
  - P3 2027/10–2028/3:C++/concurrency、OS/計算機架構、ML 加速器與 GPU、領域設計
  - P4 2028/4–8:模擬面試(含 Meta 的速度訓練)
- 已知要改的習慣:把 Submit 當 debugger(短時間內連續提交)、提交時留著 `printf`。

## 「整理」流程

使用者說「整理」時,依序做:

1. `git fetch origin main`,讀 `anki/last_processed` 裡的 commit,列出它之後的新提交。
2. 每題讀最新一份 submission,檢查正確性、複雜度、C++ 細節。
3. 依下方規則產生 Anki 卡片,**追加**到 `anki/neetcode.tsv`。已有的 GUID 不要改。
4. 回報:新增題目表格(題目、類型、提交數、評價)、累計題數、對照計畫的進度、要改的習慣。
5. 把 `anki/last_processed` 更新成 `origin/main` 的最新 commit,commit 並推送,開 PR 後問使用者要不要合併。
6. 在 repo 根目錄執行 `python3 -I anki/build_page.py <scratchpad>/neetcode-review.html`,再用 Artifact 工具以
   `url: https://claude.ai/artifact/4VFTvEmFEwVTsvdLowdxKE` 重新發布,把連結給使用者。使用者是從這個網頁看卡片的。

## Anki 卡片規則

- 一張卡只問一件事。正面要逼使用者回想,不要讓人光看就認得出答案。背面不超過 4 行。
- 每題通常 1–2 張:
  - **題型辨識**:正面描述題目特徵(盡量不寫題名),背面寫方法和狀態定義。
  - **核心邏輯**:轉移式、模版、關鍵不變量,以及「為什麼這樣做」。
- 有證據才做**易錯點卡**,例如提交數 ≥ 3 或程式碼裡看得到的錯誤。背面寫具體的坑和正確做法。
- 跨題的模版和習慣用獨立的卡片(tag `pattern` 或 `habit`),不要重複產生。
- 只為使用者已經做過的內容做卡。還沒學的東西寫在回報裡當待辦,不做成卡。

## `anki/neetcode.tsv` 格式

- Tab 分隔,四欄:`GUID`、`Front`、`Back`、`Tags`。檔頭的 `#` 行不要動。
- GUID 格式:`nc-<題目>-<簡短用途>`,例如 `nc-edit-distance-transition`;模版卡用 `pattern-...`、習慣卡用 `habit-...`。
  GUID 固定不變,使用者重新匯入時 Anki 才會更新原卡,而不是新增重複卡。
- 欄位內不能有 Tab 或換行,換行用 `<br>`。
- HTML 已開啟,文字裡的 `<`、`>`、`&` 一律寫成 `&lt;`、`&gt;`、`&amp;`。程式碼用 `<code>`。
- Tags 用空白分隔,類型用 `neetcode::<類型>`,例如 `neetcode::dp-2d`、`neetcode::tree`。
- 每張卡都要有 `date::YYYY-MM-DD`:該題最新一次提交的日期(`git log -1 --format=%ad --date=short -- <資料夾>`)。
- 有來源題目的卡加 `src::<題目資料夾名>`,網頁靠它產生題目和解答連結。易錯點卡加 `pitfall`。
