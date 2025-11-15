class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        /*
        The idea here is that as we iterate of the list, we will check 
          if target minus the number in the current iteration exists in 
          the tracking set. If it does, that means we have found the 2 
          numbers that make up the target. If target - current_num is not 
          in the set, we put the current_num in the set so future numbers
          in the iteration can check if their difference makes up the sum.

        Once we find the first number that has an associated number in the 
          set (that adds to target), we put the current numbers index into 
          the res list. Now we have to find the index of the original number.
          To do this, we can iterate over the list again from 0 to the index
          of the number we just found and check to see if the curr number
          in the new iteration + the number at the previous index adds to 
          the target. If it does, we know that the curr_num is the other index.

        We put this other number into the vector and return this result. 
        */
        vector<int> res;
        int i=0;
        unordered_set<int> tr;
        for(i=0; i<nums.size(); i++) {
            if(tr.find(target-nums[i]) != tr.end()) {
                res.push_back(i);
                break;
            }
            tr.insert(nums[i]);
        }

        for (int j=0; j<i; j++) {
            if(nums[j]+nums[i] == target) {
                res.push_back(j);
                break;
            }
        }
        return res;
    }
};
