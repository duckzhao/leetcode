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


	// inster���ص�ָ��ָ�� ����ֵ������ֵ���λ���� iterator ǰһ��λ��
	auto p = v1.insert(v1.begin(), 0);

	// ָ�����ֱ�Ӽ�һ�����֣�������һ��λ����,�൱�ڸ�ָ��++
	cout << *(p+2) << endl;

	// ������ *ָ�� �������е�Ԫ�ظ�ֵ
	*v1.begin() = 99;
	cout << *v1.begin() << endl;

	string s;
	// string����Կ�Ϊchar���͵�vector����������push_backһ��char
	s.push_back('a');
	cout << s << endl;

	vector<int> v3 = { 1 };
	// v3.insert(v3.begin() + 3, 2); �����λ�ò��ܴ��ڵ�ǰvector��size
	// ���ǿ��Ը�endָ���λ�ò���
	// ע�⣺��vector�в���Ԫ�ص�ʱ��ᳬ��һ��ʼԤ����size��vector�ͻ����¿���һ��ռ�ȥ�����е�Ԫ��
	// ��ˣ��������׵�ַ�ڲ����pushback�Ĺ����п��ܻ�ı�
	v3.insert(v3.end(), 2);


	// ����c++��������������
	// ��������ֵС�������Զ��ض�С������
	int c = 2.1;
	cout << "c=" << c << endl;
	// ������������������������������������һ��С��������������С��
	float d = 1 / 2.;
	cout << "d=" << d << endl;
	c = 1 % 2;
	cout << "c=" << c << endl;

	// a��97�����ص�������
	int a = 'a';
	bool b = 'a' > 'b';
	// �ַ�������֮��Ĺ�ϵ
	cout << "�ַ������ֵĹ�ϵ" << a  << b << endl;

	// vector�д�ſ�ָ����Ա���� ��ȷ���Ա���
	vector<int*> vp = { nullptr };
	for (auto p : vp)
	{
		cout << "��ָ����Ա���" << endl;
	}

	return 0;
}