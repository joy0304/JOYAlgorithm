## array_rotate(189)

	void reverse(int *left, int *right){
	    if (left == NULL || right == NULL) {
	        return;
	    }
	    
	    while (left < right) {
	        int temp = *left;
	        *left = * right;
	        *right = temp;
	        
	        left++;
	        right--;
	    }
	}
	
	void arrRotate(int *nums, int k , int n) {
	    
	    if (n == 0 || k < 0) {
	        return;
	    }
	    
	    reverse(nums, nums + n);
	    reverse(nums, nums + k);
	    reverse(nums + k, nums + n);
	}