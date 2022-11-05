#ifndef _SORT_H
#define _SORT_H

template<class T>
void InsertSort(T list[], int n) {
	int i, j;
	for (i = 2; i <= n; i++) {
		list[0] = list[i];
		for (j = i - 1; list[j] > list[0]; j--)
			list[j + 1] = list[j];
		list[j + 1] = list[0];
	}
}

template<class T>
void ShellInsert(T L[], int n, int m)
{
	int i, j, k;
	for (i = 1; i <= m; ++i)
	{
		for (j = i + m; j <= n; j += m)
		{
			L[0] = L[j];
			for (k = j - m; k > 0 && L[k] > L[0];k -= m) 
				L[k + m] = L[k];  //记录后移
			L[k + m] = L[0];  //插入到相应位置
		}
	}
} //算法时间复杂度为O(n2/m)

template<class T>
void ShellSort(T L[], int n, int delta[], int t) {
	//t为delta长度
	for (int m = 0; m < t; m++)
		ShellInsert<T>(L, n, delta[m]);
}

template<class T>
void SelectSort(T L[], int n) {
	int i, j, min;
	T t;
	for (i = 1; i <= n; i++) {
		min = i;
		for (j = i + 1; j <= n; j++)
			if (L[j] < L[min])
				min = j;
		t = L[i]; L[i] = L[min]; L[min] = t;
	}
}

template<class T>
void BubbleSort(T L[],int n) {
	int i, j;
	T t;
	for (i = n; i > 1; i--) {
		int count = 0;
		for (j = 1; j < i; j++)
			if (L[j] > L[j + 1]) {
				t = L[j]; L[j] = L[j + 1]; 
				L[j + 1] = t; count = j;
			}
		if (count == 0)
			break;
	}
}

template<class T>
void GnomeSort(T L[], int n)
{
	int i = 0;
	T temp;
	while (i < n)
	{
		if (i == 0 || L[i - 1] <= L[i]) i++;
		else
		{
			temp = L[i];
			L[i] = L[i - 1];
			L[i - 1] = temp;
			i--;
		}
	}
} //算法的时间复杂度为O(n^2)

template<class T>
void Merge(T L[], int p, int q, int r) {
	int i = p, j = q + 1,k=0;
	T* temp = new T[r-p+1];
	while (i <= q && j <= r) 
		if (L[i] <= L[j])
			temp[k++] = L[i++];
		else temp[k++] = L[j++];
	while (i <= q)
		temp[k++] = L[i++];
	while (j <= r)
		temp[k++] = L[j++];
	for (i = p; i <= r; i++)
		L[i] = temp[i - p];
	delete []temp;
}

template<class T>
void MergeSort(T L[],int s,int t,int n) {
	if (s >= t)return;
	int m = (s + t) / 2;
	MergeSort(L, s, m,n+1);
	MergeSort(L, m + 1, t,n+1);
	Merge(L, s, m, t);
}//时间复杂度为O(nlog2n)

template<class T>
int QuickPass(T L[], int l, int r) {
	T x = L[l];
	while (l < r) {
		while (l<r && L[r]>x)r--;
		L[l] = L[r];
		while (l < r && L[l] < x)l++;
		L[r] = L[l];
	}
	L[l] = x;
	return l;
}

template<class T>
void QuickSort(T L[], int l, int r) {
	if (l > r)return;
	int m = QuickPass(L, l, r);
	QuickSort(L, l, m - 1);
	QuickSort(L, m + 1, r);
}

template<class T>
void HeapAdjust(T L[], int s, int t) {
	int j;
	for (j = 2 * s; j <=t; j *= 2) {
		if (L[j] > L[j + 1]&&j+1<=t)j++;
		if (L[s] < L[j])break;
		swap<T>(L[s], L[j]);
		s = j;
	}
}

template<class T>
void HeapSort(T L[], int n) {
	for (int i = n / 2; i > 0; i--) 
		HeapAdjust<T>(L, i, n);
	for (int i = n; i > 1; i--) {
		cout << L[1] << " ";
		swap<T>(L[1], L[i]);
		HeapAdjust<T>(L, 1, i-1);
	}
	cout << L[1]<<endl;
}

template<class T>
void CountSort(T L[], int n) {
	int min = INT_MAX, max = INT_MIN;
	int i, j;
	T* r = new T[n];
	for (i = 1; i <= n; i++) {
		if (L[i] < min)min = L[i];
		if (L[i] > max)max = L[i];
	}
	int m = max - min + 1;
	T* s = new T[m]{ 0 };
	for (i = 1; i <= n; i++)
		s[L[i] - min]++;
	for (i = 1; i < m; i++)
		s[i] += s[i - 1];
	for (i = n; i > 0; i--) {
		r[s[L[i] - min]-1] = L[i];
		s[L[i] - min]--;
	}
	for (i = 0; i < n; i++)
		L[i+1] = r[i];
	delete s, r;
}
#endif // !_SORT_H
