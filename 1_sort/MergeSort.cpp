#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<int> merge(vector<int> &a, int l, int h) {
    if(l >= h) {
        return vector<int> {a[l]};
    }
    vector<int> merged;
    int m = (l+h)/2;

    vector<int> left = merge(a, l, m);
    vector<int> right = merge(a, m+1, h);

    int nleft = left.size();
    int nright = right.size();
    int i=0, j=0;
    while(i < nleft && j < nright) {
        if(left[i] < right[j]) {
            merged.push_back(left[i]);
            i++;
        }
        else {
            merged.push_back(right[j]);
            j++;
        }
    }
    while(i < nleft) {
        merged.push_back(left[i]);
        i++;
    }
    while(j < nright) {
        merged.push_back(right[j]);
        j++;
    }

    return merged;
}

vector<int> merge_sort(vector<int> &a) {
    return merge(a, 0, a.size()-1);
}
