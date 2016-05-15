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

