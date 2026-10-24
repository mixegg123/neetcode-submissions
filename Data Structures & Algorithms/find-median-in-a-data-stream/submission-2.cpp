class MedianFinder {
    priority_queue<long> MaxHeap;
    priority_queue<long, vector<long>, greater<long>> MinHeap;

public:
    MedianFinder() {
        //[MaxHeap][MinHeap]
        //max.top and min.top to find the median
        //1 2 2 3 4 5 1 2
        //1->122 in Max, 345 in Min
        //2->12->min pop 1 ->[1][2]
        //2->[1,2][2] even Max.top
        //3->[1,2][2,3] max.top min.top/2
        //4->[1,2][2,3,4] min.top
        //5->[1,2][2,3,4,5] [1,2,2][3,4,5] /2
        //1->[1,1,2,2] [3,4,5] max.top
        //2->[1,1,2,2,2] [3,4,5] pop [1,1,2,2] [2,3,4,5] /2
        //so check condition, push, reblamnce get median
    }
    
    void addNum(int num) {
        if(MinHeap.empty())
            MinHeap.push(num);
        else{
            if(MinHeap.top() < num)
                MinHeap.push(num);
            else
                //>=num
                MaxHeap.push(num);
        }
        
        //rebalnce
        if(MinHeap.size() > MaxHeap.size()+1)
        {
            MaxHeap.push(MinHeap.top());
            MinHeap.pop();
        } else if(MaxHeap.size() > MinHeap.size()+1)
        {
            MinHeap.push(MaxHeap.top());
            MaxHeap.pop();
        }
    }
    
    double findMedian() {
        if(MaxHeap.size() == MinHeap.size())
        {
            return (MaxHeap.top()+MinHeap.top())/2.0;
        } else if (MaxHeap.size() > MinHeap.size())
        {
            return MaxHeap.top();
        } else
            return MinHeap.top();
    }
};
