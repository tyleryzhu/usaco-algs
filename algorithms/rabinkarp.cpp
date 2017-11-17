// Implementation of Rabin-Karp String Searching Algorithm
// Time Complexity: O(n+m) best & avg, O(nm) worst where 
//                  n = txt length, m = pattern length

#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> RabinKarp(string pat, string txt, int p) {
    /**
     * Returns a vector of all instances of the pattern 'pat' in string 'txt'
     * Uses input p as prime for hash 
    **/
    int b = 256; //size of alphabet (base)
    vector<int> occ; //keep track of occurences

    // Compute b^( len(pat)-1 ) and store it as h
    int l = pat.size(); 
    int h = 1; 
    for (int i = 0; i < l-1; i++){
        h = (h*b) % p; 
    }
    
    // Compute the hash of the pattern and the hash of the first l chars
    int patHash = 0; 
    int curHash = 0; 
    for (int i = 0; i < l; i++){
        patHash = (patHash*b+pat[i]) % p; 
        curHash = (curHash*b+txt[i]) % p; 
    }

    // Now slide over the text string 
    for (int i = 0; i <= txt.size() - l; i++) {
        // If Hashes match, check chars individually
        if (patHash == curHash) {
            for (int j = 0; j < l; j++){
                if (pat[j] != txt[i+j]) 
                    break; 

                // If successful
                if (j == l-1) {
                    occ.push_back(i); 
                }
            }
        }

        // Compute Rolling Hash for next substring
        if (i < txt.size() - l) {
            curHash = ((curHash - txt[i]*h)*b + txt[i+l]) % p; 
            curHash = (curHash + p) % p; //in case negative
        }
    }
    return occ; 
}


int main() {
    string txt = "ABBCABAAAB";
    string pat = "AB";  
    int p = 1e6+3;  //1e5+3, 1e9+7, all valid
    vector<int> occ = RabinKarp(pat, txt, p); 
    for (int i = 0; i < occ.size(); i++){
        cout << occ[i] << endl; 
    }
}
