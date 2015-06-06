#include "stdafx.h"

using namespace std;

class Array{
private:
	int N;
	int* pA;
public:
	Array(int* Arr, int size);
	void FillArray();
	void ShowArray();
	void PushBack(int item);
	void PushBack(int* pArr, int item);
	Array(const Array &Right);
	void SortArray();
	int* GetArrayPtr();
	~Array();
};

Array::Array(int* Arr, int size) : N(5) {
	cout << endl << "Array Constructor" << endl << endl;
	pA = Arr;
	N = size;
}

Array::Array(const Array &Right){
	cout << endl << "Constructor Copying" << endl;
	N = Right.N;
	pA = new int[Right.N];
	memcpy(pA, Right.pA, sizeof(int)*Right.N);
	cout << "Array copy const " << this << " from " << &Right << endl;
}

int* Array::GetArrayPtr(){
	return pA;
}

void Array::FillArray(){
	for (int i = 0; i < N; i++){
		pA[i] = rand() % 100;
	}
}

void Array::ShowArray(){
	cout << "Array:" << endl;
	for (int i = 0; i < N; i++){
		cout << pA[i] << " ";
	}
	cout << endl;
}

void Array::PushBack(int item){
	int *temp = new int[N + 1];
	memcpy(temp, pA, sizeof(int)*N);
	temp[N] = item;
	N++;
	delete[]pA;
	pA = temp;
}

void Array::PushBack(int *pArr, int item){
	int *temp = new int[N + 1];
	memcpy(temp, pA, sizeof(int)*N);
	temp[N] = item;
	N++;
	delete[]pA;
	pA = temp;
}

Array::~Array(){
	cout << endl << "Array Destructor" << endl;
	delete[] pA;
}

void Array::SortArray(){
	int min = 0;
	int temp = 0;
	for (int j = 0; j < N; j++){
		min = pA[0];
		for (int i = j + 1; i < N; i++){
			if (pA[j] > pA[i]){
				min = pA[i];
				pA[i] = pA[j];
				pA[j] = min;
			}
		}
	}
}