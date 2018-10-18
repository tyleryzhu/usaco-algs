/** Bugs to check for:
    1. Integer overflow (just use long longs)

**/
#include <bits/stdc++.h>

using namespace std;

// Common Data types
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef set<int> si;
typedef map<string, int> msi;

#define FOR(i, a, b) \
    for (int i = int(a); i < int(b); i++)
#define FORB(i, a, b) \
    for (int i = int(a); i >= int(b); i--)
#define TRvi(c, it) \
    for (vi::iterator it = (c).begin(); it != (c).end(); it++)
#define TRvii(c, it) \
    for (vii::iterator it = (c).begin(); it != (c).end(); it++)
#define TRmsi(c, it) \
    for (msi::iterator it = (c).begin(); it != (c).end(); it++)

const int INF = 2e9;
// Using memset
const int MEMSET_INF = 127;  //2B
const int MEMSET_HALF_INF = 63; //1B
//memset(dist, MEMSET_INF, sizeof dist); //Shortest path distance init
//memset(dp_memo, -1, sizeof dp_memo);  //useful to initialize DP memo table
//memset(arrs, 0, sizeof arrs); //useful for clearing an array


int main() {



}
