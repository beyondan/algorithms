#include <vector>
#include <iostream>

using namespace std;

void radix_sort(vector<int> &a) {
    int n = a.size();
    int maxdigits = 0;
    for(int i=0; i<n; i++) {
        int ndigits = 0;
        int x = a[i];
        while(x > 0) {
            ndigits++;
            x /= 10;
        }
        if(ndigits > maxdigits) {
            maxdigits = ndigits;
        }
    }

    for(int d=0; d<maxdigits; d++) {
        vector<int> counter[10];

        int div = 10;
        for(int i=0; i<d; i++) {
            div *= 10;
        }

        for(int i=0; i<n; i++) {
            int digit = (a[i] % div) / (div/10);
            counter[digit].push_back(a[i]);
        }

        int i = 0;
        for(int j=0; j<10; j++) {
            int count = counter[j].size();
            for(int k=0; k<count; k++) {
                a[i] = counter[j][k];
                i++;
            }
        }
    }
}