## C++ Note

### Const 修饰符

	const int bufferSize = 512;  // 不可变
	
非`const`变量默认为`extern`，对于`const`变量，要想在其他文件中进行访问，那么要显式地指定它为`extern`


### 数组和指针

尽量不要使用指针和数组：目前很多程序是采用`vector`类型和迭代器来替代一般的数组，对于`C`字符串可以使用`string`来代替

#### 指针和引用的区别
* 引用总是指向一个对象，定义引用没有初始化是错误的
* 给引用赋值修改的是该引用所关联对象的值

对于：指针

	int ival = 1024;   int ival2 = 2048;
	int *p1 = &ival;   int *p2 = &ival2;
	p1 = p2;  // 这个时候p1所指向对象ival值不变，p1指向了另一个对象
	
对于：引用

	int &r1 = ival;  int &r2 = ival2;
	r1 = r2;     // 这个时候ival的值发生了改变，引用指向的还是原来的对象
	
关于指针的运算
	
	ptrdiff_t n = p1 - p2;
首先都是`unsigned`类型，`size_t`指明数组的长度，为正数，`ptrdiff_t`是两个指针之间的差距，可以为正、负数

	
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

#### string 对象的操作

	string.empty() 
	string.size()
	string[i]
	str1 + str2

#### string::size_type 类型
配套类型：库类型的使用与机器无关，`string::size_type`就是配套类型中的一个。我们不知道他的具体类型，但是知道它是`unsign`的，可以保证足够大的来保存`string`的长度，为了避免溢出，使用`string::size_type`是最安全的。

	for(string::size_type index = 0; index != s.size(); index++){
		// I just want to have a girl friend
	}

### vector

`vector`不是一种数据类型，是一种类模版，可用于定义多种数据类型，而`vector<int>`这种才算是具体的数据类型。

####  vector 对象初始化

	vector<T> v1
	vector<T> v2(v1);    // v2是v1的副本
	vector<T> v3(n, i);  // 包含n个为i的元素
	vector<T> v4(n);

例如：

	vector<int> vec(10);   // 就是代表10个元素，每个元素为0
	
#### vector 对象的操作

	v.empty()
	v.size()
	v.push_back(value)
	v[i]
	
#### 迭代器
标准库为每一种标准容器都定义了一种迭代类型。所有的容器都定义了相应的迭代器类型，而只有少数类型支持下标操作

	vector<int>:: iterator iter;
	
	for(vector<int>:: iterator iter = vec.begin(); iter != vec.end(); iter++){
		//i love you
	}

每种容器还定义了一种const_iterator类型，该类型只能够读取，无法修改其值

# 容器

### 初始化为一段元素的副本

	list<string> slist(vec.begin(), vec.end());
	deque<string> back(mid, vec.end());

在用下标访问元素时，`vector`使用`vector::size_type`作为下标类型，而数组下标的正确类型则是`size_t`。`vector`使用的下标实际也是`size_t`，源码是`typedef size_t size_type`。

### 迭代器

所有迭代器容器都支持以解运算从容器中读入一个元素

`vector `和 `deque` 都支持随机快速访问，可以进行一些算数运算，但是`list`不可以

容器都提供了`erase`函数，提供删除容器内的元素功能

# 关联容器

