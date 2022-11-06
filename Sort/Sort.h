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
	int i;
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
	delete []s, r;
}

template<class T>
void TreeSort(T L[],int n) {
	int h = (int)(log(n) / log(2))+1;
	int k = (int)pow(2, h) - 1, i, j,p;
	int start=0, end=0;
	T* tree = new T[long(k + n + 2)];
	for (i = 1; i <= k; i++)
		tree[i] = INT_MAX;
	tree[k + n + 1] = INT_MAX;
	for (i = k + 1; i <= k + n; i++)
		tree[i] = L[i - k];

	//构建完全二叉树
	for (i = h; i >= 1; i--) {
		start = (int)pow(2, i);
		end = (int)pow(2, i + 1);
		for (j = start; j < end && j <= k + n; j += 2) 
			tree[j / 2] = tree[j] < tree[j + 1] ? tree[j] : tree[j + 1];
	}

	for (i = 1; i <= n; i++) {
		cout << tree[1]<<" ";
		j = 1;
		while (tree[2 * j] == tree[1] || tree[2 * j + 1] == tree[1]) {
			j *= 2;
			if (tree[j] != tree[1])j++;
		}
		tree[j] = INT_MAX;
		for (p = j; p > 1; p /= 2) {
			if (p % 2)j = tree[p - 1];
			else j = tree[p+1];
			if (j < tree[p])tree[p / 2] = j;
			else tree[p/ 2] = tree[p];
		}
	}
}

template<class T>
class RadixNode {
public:
	T data;
	T data1;//辅助变量
	RadixNode* next;

	RadixNode(T e1, T e2) {
		data = e1;
		data1 = e2;
		next = NULL;
	}
	RadixNode() { data = 0; data1 = 0; this->next = NULL; }
};

template<class T>
class RadixHead {
public:
	RadixNode<T> H[10];
	RadixNode<T> R[10];
};

template<class T>
void RadixSort(RadixNode<T>* L, int n) {
	int radix = 10,i,j,k=0,l;
	RadixNode<T>* p,*r;
	RadixHead<T> head;
	
	p = L->next;
	while (p) {
		i = p->data;
		j = 0;
		while (i) {
			i /= radix;
			j++;
		}
		if (j > k)
			k = j;
		p = p->next;
	}
	for (l = 0; l < k; l++) {
		head = RadixHead<T>();
		p = L->next;
		//分配算法
		while (p) {
			i = p->data1 % radix;
			r = new RadixNode<T>(p->data, p->data1/radix);
			if (!head.H[i].next)head.H[i].next = r;
			else head.R[i].next->next = r;
			head.R[i].next = r;
			p = p->next;
		}
		//收集算法
		j = 0;
		while (!head.H[j].next)j++;
		L->next = head.H[j].next;
		for (i = j + 1; i < radix; i++) {
			if (!head.H[i].next)continue;
			head.R[j].next->next = head.H[i].next;
			j = i;
		}
	}
	p = L->next;
	while (p) {
		cout << p->data << " ";
		p = p->next;
	}
}
#endif // !_SORT_H
