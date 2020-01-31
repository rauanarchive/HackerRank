#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n, q;
    cin >> n >> q;
    vector < vector <int > > arr;
    for (int i=0; i<n; i++)
    {
        int a_i_k;
        vector<int> a_i; 
        int k;
        for (int j=0; j<k; j++)
        {
            int a_i_k;
            cin >> a_i_k;
            a_i.push_back(a_i_k);
        }
        arr.push_back(a_i);
    }
    // i_1, j_1
    // i_2, j_2
    vector < vector<int> > queries;
    for (int i=0; i<q; i++)
    {
      int i_1, j_1;
      // a[i_1][j_1]
      vector<int> query;
      cin >> i_1 >> j_1;
      query.push_back(i_1);
      query.push_back(j_1);
      cout << arr[i_1][j_1];
      queries.push_back(query);
    }
    return 0;
}


