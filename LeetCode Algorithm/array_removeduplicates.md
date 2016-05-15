## Array_removeDuplicates


	int removeDuplicates(vector<int>& nums) {
	    if (nums.size() < 2) {
	        return (int)nums.size();
	    }
	    int index = 0;
	    for (int i = 1; i < nums.size(); i++) {
	        if (nums[i] != nums[i-1]) {
	            nums[index++] = nums[i-1];
	        }
	    }
	    return index + 1;
	}
