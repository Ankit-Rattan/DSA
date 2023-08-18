#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
        int n;
        cin>>n;
        vector<string> v(n);
        for(int i=0; i<n; i++){
            cin>>v[i];
        }
        int maxi = 0;
    string temp2; string temp1;
        for(int i=0; i<n-1; i++){
            temp1= v [i];
            temp2= v[i+1];
            for(int j=0; j<10; j++){
                if(temp1[j]==temp2[j] && temp1[j] == 1){
                        temp1[j]=0;
                        temp2[j]=0;
                }
                // if((temp1[j]==1 && temp2[j]==0) || (temp1[j]==0 && temp2[j]==1)){
                //     temp1[j]=0;
                //     temp2[j]=1;
                // }
                else{
                    temp1[j]=0;
                    temp2[j]=1;
                }
            }
            v[i+1]=temp2;
        }
        
            // maxi = max(cnt, maxi);
            int cnt=0;
            for(int i=0; i<10; i++){
              if(temp2[i]=='1'){
                cnt++;
              }
            }
    
        cout<<cnt<<endl;
        
	
	}
	return 0;
}