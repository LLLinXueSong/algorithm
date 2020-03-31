#include <string>
#include <iostream>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
using namespace std;
vector<int> b;
void MergeSort(int a[],int low,int hig){
    if(low>=hig) return;
    int mid = (hig+low)>>1;
    MergeSort(a,low,mid);
    MergeSort(a,mid+1,hig);
    int cnt = 0;
    int i = low;
    int j = mid+1;
    while(i<=mid && j<=hig){
        if(a[i]>a[j]){
            b[cnt++] = a[j++];
        }else{
            b[cnt++] = a[i++];
        }
    }
    while(i<=mid){
        b[cnt++] = a[i++];
    }
    while(j<=hig){
        b[cnt++] = a[j++];
    }
    i = 0;
    while(low<=hig){
        a[low++] = b[i++];
    }
}
int getIndex(int a[],int low, int hig){
    int temp = a[low];
    while(low<hig){
         while(low<hig && a[hig]>=temp){
        hig--;
    }
    a[low] = a[hig];
    while(low<hig && a[low]<temp){
        low++;
    }
    a[hig] = a[low];

    }
    a[low] = temp;
    return low;
}
void quickSort(int a[],int low,int hig){
    if(low<hig){
        int index = getIndex(a,low,hig);
        quickSort(a,low,index-1);
        quickSort(a,index+1,hig);
    }
}
int main(){
    int a[10] = {2,4,5,1,0,9,7,6,5};
    int d[10] = {2,4,5,1,0,9,7,6,5};
    b.resize(10,0);
    MergeSort(a,0,9);
    quickSort(d,0,9);
    for(int i = 0;i<10;i++){
        cout<<a[i];
    }
    cout<<endl;
    for(int i = 0;i<10;i++){
        cout<<d[i];
    }
    return 0;
}
