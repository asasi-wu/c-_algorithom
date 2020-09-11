#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//Question description:f(i)=min{min(f(i+1)+1),f(i)}
//The inside min value can be obtained by if i-j is a Palindrome
class Solution{
public:
    int minCut(const string& s){
        const int n=s.size();
        int f[n+1];
        bool p[n][n];
        fill_n(&p[0][0],n*n,false);
        //the worst case is cutting by each char
        for (int i=0;i<=n;i++){
            f[i]=n-1-i;
            cout<<f[i]<<endl;}
        for (int i=n-1;i>=0;i--){
            for (int j=i;j<n;j++){
                if(s[i]==s[j]&&(j-i<2||p[i+1][j-1])){
                    p[i][j]=true;
                    f[i]=min(f[i],f[j+1]+1);
                }
            }
        }
       return f[0];

    }

};


int main() {
    string name="sasaasacccccc";
    Solution solution;
    int number=solution.minCut(name);
    cout<<number<<endl;
    return 0;
}
