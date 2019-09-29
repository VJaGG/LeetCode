#include<iostream>
#include<vector>
using namespace std;

//�ݹ�ʵ����ǵݹ飬�ݹ�ʱ�临�Ӷ�����n�ı仯��������2^n
//��һ��ת���Ĺ���
int Fibonacci1(int n) {
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	vector<int> array(n+1);
	array[0] = 0;
	array[1] = 1;
	for (int i = 2; i <=n; i++) {
		array[i] = array[i - 1] + array[i - 2];
	}
	return array[n];
}
int Fibobacci2(int n) {
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	int first = 0, second = 1, result;
	for (int i = 2; i <= n; i++) {
		result = first + second;
		first = second;
		second = result;
	}
	return result;
		

}
int Fibonacci(int n) {
	//�ݹ�ʵ�ֵ�
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	int num = Fibonacci(n - 1) + Fibonacci(n - 2);
	return num;
}

int main() {
	int num;
	cout << "please enter the num: ";
	cin >> num;
	int result = Fibobacci2(num);
	cout << result<<endl;
	system("pause");
	return 0;


}