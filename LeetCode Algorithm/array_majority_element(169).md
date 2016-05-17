
## array_Majority Element(169)
	int majorityElement (int array[], int n) {
	    if (array == NULL || n <= 0 ){
	        return -1;
	    }
	    
	    int temp = array[0];
	    int nums = 1;
	    for (int i = 1; i < n; i++) {
	        
	        if (temp == array[i]) {
	            nums++;
	        }
	        else {
	            nums--;
	            if (nums == 0) {
	                temp = array[i];
	                nums = 1;
	            }
	        }
	    }
	    if (nums > 0) {
	        return temp;
	    }
	    else {
	        return -1;
	    }
	
	}