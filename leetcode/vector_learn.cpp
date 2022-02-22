#include<iostream>
#include<vector>
#include<string>
using namespace std;


int main1() {

	vector<int> v1 = { 1, 2, 3, 4, 5 };
	for (int i = 0; i < 3; i++)
	{
		v1.push_back(0);
	}

	cout << *(v1.end()-1) << endl;


	// inster返回的指针指向 插入值，插入值插的位置是 iterator 前一个位置
	auto p = v1.insert(v1.begin(), 0);

	// 指针可以直接加一个数字，跳到另一个位置上,相当于给指针++
	cout << *(p+2) << endl;

	// 可以用 *指针 对容器中的元素赋值
	*v1.begin() = 99;
	cout << *v1.begin() << endl;

	string s;
	// string类可以看为char类型的vector容器，可以push_back一个char
	s.push_back('a');
	cout << s << endl;

	vector<int> v3 = { 1 };
	// v3.insert(v3.begin() + 3, 2); 插入的位置不能大于当前vector的size
	// 但是可以给end指针的位置插入
	// 注意：给vector中插入元素的时候会超过一开始预留的size，vector就会重新开辟一块空间去放所有的元素
	// 因此，容器的首地址在插入和pushback的过程中可能会改变
	v3.insert(v3.end(), 2);


	// 测试c++的数字运算特性
	// 给整数赋值小数，会自动截断小数部分
	int c = 2.1;
	cout << "c=" << c << endl;
	// 两个整数相除，结果是整数，除法运算中有一个小数，运算结果就是小数
	float d = 1 / 2.;
	cout << "d=" << d << endl;
	c = 1 % 2;
	cout << "c=" << c << endl;

	// a是97，返回的是数字
	int a = 'a';
	bool b = 'a' > 'b';
	// 字符和数字之间的关系
	cout << "字符和数字的关系" << a  << b << endl;

	// vector中存放空指针可以遍历嘛？ 的确可以遍历
	vector<int*> vp = { nullptr };
	for (auto p : vp)
	{
		cout << "空指针可以遍历" << endl;
	}

	return 0;
}