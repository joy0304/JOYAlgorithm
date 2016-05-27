## array_missingNumber

	int missingNumber(vector<int>& nums) {
	    
	    if (nums.size() < 1) {
	        return -1;
	    }
	    
	    int result = 0;
	    for (size_t i = 0; i < nums.size(); i++) {
	        result ^= nums[i] ^ i;
	    }
	    result ^= nums.size();
	    return result;
	}
	
	
	int main(){
	 
	    vector<int> vec(10);
	    for (int i = 0; i < 10; i++) {
	        vec[i] = i;
	    }
	    
	    vec.erase(vec.begin() + 5);
	    
	    int result = missingNumber(vec);
	    
	    cout<< result <<endl;
	}
	
	
对于异或的经常用法

* 实现两个数的交换
* 在一排数中找到独一无二的一个数
* 判断两个数是否相等