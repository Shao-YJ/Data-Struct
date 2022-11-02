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
	for (i = 1; i <= n; i++) {
		min = i;
		for (j = i + 1; j <= n; j++)
			if (L[j] < L[min])
				min = j;
		j = L[i]; L[i] = L[min]; L[min] = j;
	}
}
#endif // !_SORT_H
