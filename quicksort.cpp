/** 	
　　Singleton模式的实现
　　File		:singleton.cpp 
　　Author		:singmelody 
　　Date		:2012.11.19
*/
#include <iostream>
#include <string.h>
//#include <WinBase.h>
using namespace std;

#if 0
int fibonaccl(int i) {
	if (i == 0) return 0;
	if (i == 1) return 1;
	return fibonaccl(i - 1) + fibonaccl(i - 2);
};

int fib[100];
int fibonacci(int i) {
	if (i == 6) return 0;
	if (i == 1) return 1;
		if (fib[i] != 0) return fib[i]; // Return cached result.
            fib[i] = fibonacci(i - 1) + fibonacci(i - 2); // Cache result
			return fib[i];
		
};

 int countWays(int n) {
	 if (n < 0) {
		return 0;
		
	}
	else if (n == 0) {
		 return 1;
		
	}
	else {
		 return countWays(n - 1) + countWays(n - 2) +
			countWays(n - 3);		
	}
}

 int num2=0;
 int countWays2(int n) {
	 if (n < 0) {
		 return 0;

	 }
	 else if (n == 0) {
		 
		 return 1;

	 }
	 else {
		 int a, b, c;
		a=countWays2(n - 1);
		b=countWays2(n - 2);
		c=countWays2(n - 3);
		
		num2 += 3;
		 return num2;
	 }
 };

 const int ienum = 3;
 char set[3] = { '0','1','2' };
 string subset[100];
 int num3 = 1;
 void FullSet(char data[],int index) {

	 if (index >= ienum)
		 return;
	 for (int i = 0; i < num3; i++) {
		 subset[num3+i] = subset[i] + data[index];
	 }
	 num3 = num3 + num3;
	 FullSet(data, ++index);
 }
 
 
 void shiftright(int* data, int offset, int len) {

	for (int i = 0; i < ((len - offset) / 2); i++) {
		swapdata(data[i], data[len - offset - i-1]);
	}
	for (int i = 0; i < offset / 2; i++) {
	swapdata(data[i + len - offset], data[len - i-1]);
		}
	for (int i = 0; i < len / 2; i++) {
			swapdata(data[i], data[len - i-1]);
		}
}
int main()
{

	int a;
	int b;
	int num = 3;
	a = fibonaccl(3);
	a = countWays(num);
	b = countWays2(num);
	cout << "a is " << a<<'\n'<<"b is "<<b<<'\n';

	FullSet(set, 0);
	cout << "fullset is \n";
	for (int i = 0; i < num3;  i++) {
		cout <<  subset[i].c_str() << ' ';
	};
	return 1;
}

#endif
void swapdata(int& a, int& b) {
	int c;
	c = b;
	b = a;
	a = c;
}
int partion(int array[], int low, int high) {
	int pivot = array[high];
	int index = low;
	for (int i = low; i < high; i++) {
		if (array[i] <= pivot) {
			swapdata(array[i], array[index]);
			index++;
		}
	}
	swapdata(array[index], array[high]);
	return index;
}
int quicksort(int array[], int low, int high) {
	int p;
	if (low < high) {
			p= 	partion(array,low,high);
			quicksort(array, low, p-1);
			quicksort(array, p+1, high);


	}
	else {
		return low;
	}
}

int main()
{

	
	int dataarray[10] = { 0,3,5,6,4,9,1,2,8,7 };
	for (int i = 0; i < 10; i++) {
		printf(" %d ", dataarray[i]);
	}
	printf("\n");
	quicksort(dataarray, 0, 9);
	for (int i = 0; i < 10; i++) {
		printf(" %d ", dataarray[i]);
	}
	printf("\n");


	printf("start right shift\n");
	int datasource[10] = { 1,2,3,4,5,6,7,8,9 };

	for (int i = 0; i < 9; i++) {
		printf(" %d ", datasource[i]);
	}
	printf("\n");

	shiftright(datasource, 3, 9);
	for (int i = 0; i < 9; i++) {
		printf(" %d ", datasource[i]);
	}
	printf("\n");
	
	return 1;
}