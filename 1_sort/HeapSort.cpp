#include <algorithm>
#include <iostream>
#include <vector>

#define PARENT(i) ((i-1)/2)
#define LEFT(i) ((2*i)+1)
#define RIGHT(i) ((2*i)+2)

using namespace std;

string vtos(vector<int> &a);

void heapify(vector<int> &a, int i, int asize=0) {
    int l = LEFT(i);
    int r = RIGHT(i);
    int maxi = i;
    int n = a.size();
    if(asize > 0) {
        n = asize;
    }
    if(l < n && a[l] > a[i]) {
        maxi = l;
    }
    if(r < n && a[r] > a[maxi]) {
        maxi = r;
    }
    if(maxi == i) return;
    swap(a[i], a[maxi]);
    heapify(a, maxi, n);
}

void build_maxheap(vector<int> &a) {
    for(int i=a.size()/2-1; i>=0; i--) {
        heapify(a, i);
    }
}

void heap_sort(vector<int> &a) {
    build_maxheap(a);
    int n = a.size();
    for(int i=n-1; i>=1; i--) {
        swap(a[i], a[0]);
        heapify(a, 0, i);
    }
}
