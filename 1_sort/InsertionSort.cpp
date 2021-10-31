#include <iostream>
#include <vector>

using namespace std;

void insertion_sort(vector<int> &a) {
    int n = a.size();
    for(int j=1; j<n; j++) {
        int key = a[j];
        int i = j-1;
        while(i >= 0 && a[i] > key) {
            a[i+1] = a[i];
            --i;
        }
        a[i+1] = key;
    }
}
