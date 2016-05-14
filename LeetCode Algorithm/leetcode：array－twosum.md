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
	
	
## 补充关于标准库

`string`：支持长度可变的字符串

`vector`：可保存一组制定类型的数组

### 命名空间

`::` 是作用域指示符－含义是右操作符的名字可以在左操作符的作用域中找到

### String

#### string的读写
	int main(){
	    string s;
	    cin >> s;
	    cout << "------" << endl;
	    cout << s << endl;
	}
看这段代码，对于cin 输入有以下注意点：

* 读取并忽略开头所有的空白字符（空格、制表符、换行符）
* 遇到空白字符时，终止

打印结果为：

	 hello world
	----------------
	hello
	
#### 可以使用getline来读取整行文本
	
	 string s;
     while (getline(cin, s)) {
        cout << s << endl;
     }
输出结果为：

	 hello world
	 hello world

#### string对象的操作

	string.empty() 
	string.size()
	string[i]
	str1 + str2

#### string::size_type类型
配套类型：库类型的使用与机器无关，`string::size_type`就是配套类型中的一个。我们不知道他的具体类型，但是知道它是`unsign`的，可以保证足够大的来保存`string`的长度，为了避免溢出，使用`string::size_type`是最安全的。

### vector

`vector`不是一种数据类型，是一种类模版，可用于定义多种数据类型，而`vector<int>`这种才算是具体的数据类型。

####  vector对象初始化

	vector<T> v1
	vector<T> v2(v1);    // v2是v1的副本
	vector<T> v3(n, i);  // 包含n个为i的元素
	

