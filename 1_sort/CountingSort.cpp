#include <vector>

using namespace std;

void counting_sort(vector<int> &a) {
    int n = a.size();
    if (n == 0) return;

    int k = a[0];
    for(int i=1; i<n; i++) {
        if(a[i] > k) {
            k = a[i];
        }
    }

    int counter[k+1];
    for(int i=0; i<=k; i++) {
        counter[i] = 0;
    }

    for(int i=0; i<n; i++) {
        counter[a[i]]++;
    }

    int i = 0;
    for(int j=0; j<=k; j++) {
        if(counter[j] > 0) {
            for(int x=0; x<counter[j]; x++) {
                a[i] = j;
                i++;
            }
        }
    }
}

