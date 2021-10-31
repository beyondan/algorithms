#include <algorithm>
#include <vector>

using namespace std;

int partition(vector<int> &a, int l, int r) {
    int pivot = a[r];
    int i=l-1;
    for(int j=l; j<=r; j++) {
        if(a[j] <= pivot || j == r) {
            i++;
            swap(a[j], a[i]);
        }
    }
    return i;
}

void qsort(vector<int> &a, int l, int r) {
    if(l >= r) return;
    int p = partition(a, l, r);
    qsort(a, l, p-1);
    qsort(a, p+1, r);
}

void quick_sort(vector<int> &a) {
    qsort(a, 0, a.size()-1);
}