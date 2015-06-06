/*
Array a1 = a;
cout << "a1:" << endl;
a1.ShowArray();
a1.FillArray();
a1.ShowArray();
*/

/*
int IntSort(const void *pV1, const void *pV2){
int *pI1 = (int*)pV1;
int *pI2 = (int*)pV2;

return (*pI1 - *pI2);
}

typedef int(*ForQsortT)(const void *, const void *);

int IntSortTypeDef(int *p1, int *p2){
return (*p1 - *p2);
}

int DoubleSortTypeDef(double *p1, double *p2){
if (*p1 - *p2) return 1;
else
if (*p1 - *p2) return 0;
else
if (*p2 - *p1) return -1;
}
*/

/*int size = 16;
int *mas = new int[size];
Array a = Array(mas, size);
a.FillArray();
a.ShowArray();
a.PushBack(67);
a.ShowArray();
//qsort(mas, size, sizeof(int), (ForQsortT)IntSortTypeDef);
qsort(a.GetArrayPtr(), size, sizeof(int), IntSort);

a.ShowArray();

double *pD = new double[10];
for (int i = 0; i < 10; i++){
pD[i] = (rand() % 100) * 0.1; /// (rand() % 5);
}

for (int i = 0; i < 10; i++){
cout << pD[i] << endl;
}
cout << "**********" << endl;
qsort(pD, 10, sizeof(double), (ForQsortT)DoubleSortTypeDef);

for (int i = 0; i < 10; i++){
cout << pD[i] << endl;
}

delete[] pD;*/