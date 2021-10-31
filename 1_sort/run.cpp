#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

void bucket_sort(vector<int> &a);
void counting_sort(vector<int> &a);
void insertion_sort(vector<int> &a);
void heap_sort(vector<int> &a);
vector<int> merge_sort(vector<int> &a);
void quick_sort(vector<int> &a);
void radix_sort(vector<int> &a);

string vtos(vector<int> &a) {
    int n = a.size();
    if(n == 0) return "[]";

    stringstream ss;

    ss << "[";
    for(int i=0; i<n-1; i++) {
       ss << to_string(a[i]) + ", "; 
    }
    ss << to_string(a[n-1]) + "]";
    return ss.str();
}

void test(vector<int> &a) {
    if(is_sorted(a.begin(), a.end())) {
        cout << "PASSED" << endl;
    }
    else {
        vector<int> a_sorted = vector<int>(a);
        sort(a_sorted.begin(), a_sorted.end());

        cout << "FAILED:" << endl;
        cout << "My answer : " << vtos(a) << endl;
        cout << "Expected  : " << vtos(a_sorted) << endl;
        cout << endl;
    }
}

int main() {
    vector<int> a { 31, 12, 25, 0, 44, 2, 92, 12, 63, 12, 23, 0, 75, 18, 12, 2, 16, 15, 7, 59 };

    cout << "===== INSERTION SORT =====" << endl;
    vector<int> a_insertion(a);
    insertion_sort(a_insertion);
    test(a_insertion);

    cout << "===== MERGE SORT =====" << endl;
    vector<int> a_merge = merge_sort(a);
    test(a_merge);

    cout << "===== HEAP SORT =====" << endl;
    vector<int> a_heap(a);
    heap_sort(a_heap);
    test(a_heap);

    cout << "==== QUICK SORT ====" << endl;
    vector<int> a_quick(a);
    quick_sort(a_quick);
    test(a_quick);

    cout << "==== COUNTING SORT ====" << endl;
    vector<int> a_counting(a);
    counting_sort(a_counting);
    test(a_counting);

    cout << "==== RADIX SORT ====" << endl;
    vector<int> a_radix(a);
    radix_sort(a_radix);
    test(a_radix);

    cout << "==== BUCKET SORT ====" << endl;
    vector<int> a_bucket(a);
    bucket_sort(a_bucket);
    test(a_bucket);

    return 0;
}
