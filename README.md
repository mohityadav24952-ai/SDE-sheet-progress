# SDE-sheet-progress
Consistent efforts

#DAY-4

LEETCODE 88 MERGE TWO SORTED ARRAYS WITHOUT EXTRA SPACE 

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
       
       int left = m - 1;
       int right = 0;

       while(left >= 0 && right < n){
            if(nums1[left] > nums2[right]){
                swap(nums1[left], nums2[right]);
                left--;
                right++;
            }
            else{
                break;
            }
       }

       sort(nums1.begin(), nums1.begin() + m);
       sort(nums2.begin(), nums2.end());

       for(int i = 0; i < n; i++){
            nums1[m + i] = nums2[i];
       }
    }
};





LEETCODE 287---------FIND DUPLICATE NUMBER

// Treat array as a linked list:
// index -> nums[index]

// Duplicate number creates a cycle.

// Phase 1:
// Find intersection point inside cycle
// using slow and fast pointers.

// Phase 2:
// Put one pointer at start.
// Move both one step at a time.
// Meeting point = duplicate number.

class Solution {
public:
    int findDuplicate(vector<int>& nums) {

        // Floyd's Cycle Detection (Tortoise and Hare)

        int slow = nums[0];
        int fast = nums[0];

        // Step 1: Find the meeting point inside the cycle
        do {
            slow = nums[slow];           // move 1 step
            fast = nums[nums[fast]];     // move 2 steps
        } while (slow != fast);

        // Step 2: Move one pointer back to the start
        // and keep the other at the meeting point.
        // Both now move 1 step at a time.
        fast = nums[0];

        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }

        // The point where they meet again
        // is the duplicate number.
        return slow;
    }
};





PUSHED 13 LEETCODE PROBLEMS TODAYYYYY !!!!!!!!!!!!!!!!!!!!!!!!!!!



PUSHED 15 LEETCODE PROBLEMS TODAY !!!!!!!!!!!!! 14/06/26

I'LL BECOME THE BLOODY BESTTT

<!---LeetCode Topics Start-->
# LeetCode Topics
## Array
|  |
| ------- |
| [0066-plus-one](https://github.com/mohityadav24952-ai/SDE-sheet-progress/tree/master/0066-plus-one) |
| [0494-target-sum](https://github.com/mohityadav24952-ai/SDE-sheet-progress/tree/master/0494-target-sum) |
## Math
|  |
| ------- |
| [0066-plus-one](https://github.com/mohityadav24952-ai/SDE-sheet-progress/tree/master/0066-plus-one) |
## Dynamic Programming
|  |
| ------- |
| [0494-target-sum](https://github.com/mohityadav24952-ai/SDE-sheet-progress/tree/master/0494-target-sum) |
| [3699-number-of-zigzag-arrays-i](https://github.com/mohityadav24952-ai/SDE-sheet-progress/tree/master/3699-number-of-zigzag-arrays-i) |
## Prefix Sum
|  |
| ------- |
| [3699-number-of-zigzag-arrays-i](https://github.com/mohityadav24952-ai/SDE-sheet-progress/tree/master/3699-number-of-zigzag-arrays-i) |
## Backtracking
|  |
| ------- |
| [0494-target-sum](https://github.com/mohityadav24952-ai/SDE-sheet-progress/tree/master/0494-target-sum) |
<!---LeetCode Topics End-->