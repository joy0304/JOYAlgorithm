## LeetCode：Array－TwoSum

	vector<int> twoSum(vector<int>& nums, int target) {
	    vector<int> result(2);
	    map<int, int> hash;
	    
	    for(int i = 0;i < nums.size();i++){
	        hash[nums[i]] = i;
	    }
	    
	    for (int j = 0; j < nums.size(); j++) {
	        // end 是末尾，里面没有实际元素
	        if ((hash.find(target - nums[j]) != hash.end()) && (hash[target - nums[j]] != j)) {
	            result[0] = j;
	            result[1] = hash[target - nums[j]];
	            break;
	        }
	    }
	    return result;
	}
	
	
### 补充关于