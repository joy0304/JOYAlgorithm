## Array_Contains Duplicate 


	bool containsDuplicate(vector<int>& nums) {
	    
	    return nums.size() > set<int>(nums.begin(), nums.end()).size();
	}
	
	
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> mp; 
        for (int i = 0; i < nums.size(); i++) {
            if (mp.find(nums[i]) != mp.end() && i - mp[nums[i]] <= k)
                return true;
            mp[nums[i]] = i; 
        }
        return false; 
    }
    
###  容器

