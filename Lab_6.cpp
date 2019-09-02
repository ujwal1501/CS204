
#include <bits/stdc++.h>
typedef long long int lli;
typedef unsigned long long int ulli;
typedef long double ldb;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define pb push_back
#define popb pop_back()
#define pf push_front
#define popf pop_front()
#define si size()
#define be begin()s
#define en end()
#define all(v) v.be, v.en
#define le length()
#define mp make_pair
#define mt make_tuple
#define F first
#define S second

#define forz(i, n) for (int i = 0; i < n; i++)
#define forzm(i, m, n) for (int i = m; i < n; i++)
#define rforz(i, n) for (int i = n - 1; i >= 0; i--)
#define rforzm(i, m, n) for (int i = n - 1; i >= m; i--)
#define deci(n) fixed << setprecision(n)
#define high(n) __builtin_popcount(n)
#define parity(n) __builtin_parity(n)
#define ctz(n) __builtin_ctz(n)
#define lb lower_bound
#define ub upper_bound
#define er equal_range
#define maxe *max_element
#define mine *min_element
#define mod 1000000007
#define mod2 998244353
#define kira ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

#define endl "\n"
#define p0(a) cout << a << " "
#define p1(a) cout << a << endl
#define p2(a, b) cout << a << " " << b << endl
#define p3(a, b, c) cout << a << " " << b << " " << c << endl
#define p4(a, b, c, d) cout << a << " " << b << " " << c << " " << d << endl

#define oset tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
#define osetlli tree<lli, null_type, less<lli>, rb_tree_tag, tree_order_statistics_node_update>
//member functions :
//1. order_of_key(k) : number of elements strictly lesser than k
//2. find_by_order(k) : k-th element in the set
#define ofk order_of_key
#define fbo find_by_order
using namespace std;

int binary_search(vector<int> arr, int i, int j, int key) {
    if(i > j) {
        return -1;
    }

    int m = (i + j) / 2;
    if(arr[m] < key) {
        return binary_search(arr, m+1, j, key);
    } else if(arr[m] > key) {
        return binary_search(arr, i, m-1, key);
    }
    return m;
}

int main() {
    int n;
    cin >> n;
    int t;
    cin >> t;
    int q[t][3];
    vector<int> users;
    for(int i = 0; i < t; ++i) {
        cin >> q[i][0];
        if(q[i][0] == 1) {
            cin >> q[i][1] >> q[i][2];
            users.push_back(q[i][1]);
        }
    }

    sort(users.begin(), users.end());
    int j = 1;
    for(unsigned int i = 1; i < users.size(); ++i) {
        if(users[i] != users[i-1]) {
            users[j] = users[i];
            j++;
        }
    }

    int max_user_id = -1;
    int max_amount = 0;
    vector<int> amount(j, 0);

    for(int i = 0; i < t; ++i) {
        if(q[i][0] == 1) {
            int index = binary_search(users, 0, j-1, q[i][1]);
            amount[index] += q[i][2];
            if(max_amount < amount[index]) {
                max_amount = amount[index];
                max_user_id = q[i][1];
            }
        } else {
            if(max_amount) {
                cout << max_user_id << '\n';
            } else {
                cout << "No data available." << '\n';
            }
        }
    }


    return 0;
}