// Kth Largest Element in an Array (#215)

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // Min-heap to store the k largest elements
        priority_queue<int, vector<int>, greater<int>> minHeap;
        // Iterate through the array
        for (int num : nums) {
            minHeap.push(num); // Push current number
            // If heap size exceeds k, remove the smallest
            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }
        // Top of the heap is the kth largest element
        return minHeap.top();
    }
};