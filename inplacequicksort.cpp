//inplacequicksort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
using namespace std;
#include"vector.h"
template<typename T>
void quicksort(vector<T>& array);
template<typename T>
void quicksortstep(vector<T>& array,int left,int right);
template<typename T>
const T& median(vector<T>& array, int left, int right);
template<typename T>
void swap(T& value1, T& value2);
int main()
{
	int value;
	vector<int> obj;
	int arr[] ={16,17,8,1,4,3,9,3,13,5,2,7,14,0};
	for (int i =0; i < 14; i++)
	{
		obj.push_back(arr[i]);
	}
	cout << "before sorting\n";
	for (auto it : obj)
	{
		cout << it << endl;
	}
	quicksort(obj);
	cout << "AFTER QUICK SORT VALUES ARE\n";
	for (auto it : obj)
	{
		cout << it << endl;
	}
	system("pause");
}
template<typename T>
void swap(T* value1, T* value2)
{
	T temp = *value1;
	*value1 = *value2;
	*value2 = temp;
}
template<typename T>
const T& median(vector<T>& array, int left, int right)
{
	int center = (left + right)/2;
     if(array[right]<array[center])
		 swap(&array[center], &array[right]);
	swap(&array[center],&array[right]);
	return array[right];
}
template<typename T>
void quicksort(vector<T>& array)
{
	quicksortstep(array, 0, array.size()-1);
}
template<typename T>
void quicksortstep(vector<T>& array, int left, int right)
{
	if (left >=right)
		return;
	T pivot = median(array,left,right);
	int l = left;
	int r = right - 1;
	while (l<r)
	{
		while (l<r && array[l] < pivot)
			++l;
		while (r>l && array[r] > pivot)
			r--;
		if (l < r)
		{
			swap(&array[l], &array[r]);
		}
		else
			break;
	}
	swap(&array[l],&array[right]);
	quicksortstep(array, left, l - 1);
	quicksortstep(array,l+1, right);
}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
