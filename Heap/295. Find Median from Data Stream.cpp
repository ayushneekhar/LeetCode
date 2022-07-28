// Median: the value at the center on a sorted list;
// Median for even = both the middle elements / 2;

// Why heap?
// to fidn the median we know that the number need to be in a sorted order, if we were to take a normal vector
// we'd have to sort the the vector everytime we need to insert a new element, this would take O(n*nlogn), instead if we
// were to use a heap, it'll only take us O(logn) to insert which is far better than normal vector.

// Why do we take two heaps?
// Since finding the middle element for the median it's better to take 2 heaps since accessing only the top element
// if O(1) time only

// Why is one heap Max and other Min?
// When trying to access the element in between, if we were to take both the heaps as min, one of the middle elemnts would
// end up at the bottom of a heap while other at the top. Getting the bottom element will incerease time complexity in this
// case, hence it's better to have 2 heaps, this way the element we need will always be at the top with O(1) complexity to
// access them
// {1,2,3,4,5,6,7,8} => {4,3,2,1} & {5,6,7,8} and we only need elements 4 and 5 for median!

class MedianFinder
{
    priority_queue<double> small;                                  // Max heap
    priority_queue<double, vector<double>, greater<double>> large; // Min heap
public:
    void addNum(int num)
    {
        small.push(num);

        // Make sure all the elements in the small heap is are less than all the elements in the large heap
        if (small.size() > 0 && large.size() > 0 && small.top() > large.top())
        {
            large.push(small.top());
            small.pop();
        }

        // Deal with uneven length of heaps, where the larger size heap has atleast 2 more elements than the smaller size one
        if (small.size() > large.size() + 1)
        {
            large.push(small.top());
            small.pop();
        }

        if (large.size() > small.size() + 1)
        {
            small.push(large.top());
            large.pop();
        }
    }

    double findMedian()
    {
        if (small.size() > large.size())
            return small.top();
        if (large.size() > small.size())
            return large.top();
        return (small.top() + large.top()) / 2;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */