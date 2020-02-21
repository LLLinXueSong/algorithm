#include <string>
#include <iostream>
using namespace std;
string s = "ABC";
string res;
bool use[100];
void Permute(string a,int begin,int end,string res){
    if(begin == end){
        cout<<res<<endl;
        return;
    }else{
        for(int i = 0;i<end;i++){
            if(!use[i]){
                use[i] = true;
                 res += s[i];
                 Permute(a,begin+1,end,res);
                 res.erase(res.length()-1);
                 use[i] = false;
            }
        }
    }
}
int main(){
    memset(use,0,sizeof(use));
    Permute(s,0,s.length(),res);
    return 0;
}
