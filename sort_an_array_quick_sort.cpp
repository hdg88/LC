class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        qSort(0, nums.size()-1, nums);
        return nums;
    }

    /*
    The algorithm used is quick sort. Basically, from the vector,
      we pick a pivot index. The idea is to ensure that all values 
      less than the pivot are to the left of the pivot, and all 
      values to the right of the pivot are greater than the pivot.
      Once the pivot is picked, we swap it with the last element 
      in the vector. Then we use a 2 pointer approach to (1) swap 
      smaller values with larger values, and (2) keep track of the 
      last smallest value in the range, which will then be used to 
      increment and swap with the last index (formerly, the pivot). 
      This is easier to visualize:
      (see https://www.geeksforgeeks.org/dsa/quick-sort-algorithm/).

      Then we recursively pass in the items left of the pivot and 
      the same algorithm is carried ou ton this smaller set. 
      Then we pass in the items right of the pivot. The base case 
      here is when the start and end indexes of a set being passed 
      in are the same or the lower is greater than the higher. 
    */
    void qSort(int i, int j, vector<int>& nums) {
        if (i>=j) return;
        int pivot = (i+j)/2;

        swap (nums[pivot], nums[j]);
        int l = i-1;
        int r = i;

        while (r<j) {
            if (nums[r]<nums[j]) {
                l++;
                swap (nums[l], nums[r]);
            }
            r++;
        }
        l++;
        swap (nums[l], nums[j]);

        qSort(i, l-1, nums);
        qSort(l+1, j, nums);
    }

};
