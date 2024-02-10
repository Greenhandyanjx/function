#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;
//一元谓词
// bool为函数返回值的函数对象(谓词),参数列表有一个为一元谓词
class Greaterfive {
public:
	int operator()(int val) {
		return val > 5;
	}

};
class m_compare {
public:
	//二元谓词要在参数列表后加const,利用仿函数改变排序规则
	bool operator()(int v1, int v2)const {
		return v1>v2;
	}
};
//也有内建的仿函数,算术,关系,,
int main()
{
	vector <int>v;
	for (int i=0;i<10;i++)
	{
		v.push_back(i);
	}
	vector<int>::iterator itb = find_if(v.begin(), v.end(), Greaterfive());
	//直接改变
	sort(v.begin(), v.end(), greater<int>());
	//后面类型为Pred_last为仿函数
	//函数对象
	cout << "greater than 5: " << *itb << endl;;	
	return 0;
}
//函数对象的三个性质,又叫仿函数,实际上是一个类
//1.和普通函数一样,使用是有函数列表,也有返回值
//2.可以有自己的状态
//3.可以作为参数传递
//class Myadd {
//public:
//	Myadd()
//	{
//		this->count = 0;
//	}
//	int operator()(int a, int b) {
//		this->count++;
//		cout << count << endl;
//		return a + b;
//	}
//	int count;
//};
//int main()
//{
//	Myadd m;
//	cout << m(10, 10) << endl;
//	cout << m(10, 10) << endl;
//
//	return 0;
//}