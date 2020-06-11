#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int test_cases;
    cin >> test_cases;
    while(test_cases--){
      int n;
	cin >> n;
	int money[n];
	for(int i =0; i<n; i++){
			cin >> money[i];
	}
	int flag = 1;
	int n5 = 0;
	int n10 = 0;
	int k = 0;
	int balance;
	int reg;
   do{
		reg = 5*n5 + 10*n10;	/*returnable amount in register*/
		balance = money[k]-5;	/*amount to return*/
		if(balance > reg){
			flag = 0;
		}else{
			if(money[k]==5){
				n5 = n5 + 1;
				k++;
			}else{
				if(money[k]==10){
					/*money = 10*/
					if(n5==0){
						flag = 0;
					}else{
						n10 = n10 + 1;
						n5 = n5 - 1;
						k ++;
					}
				}else{
					/*money = 15*/
					if((n5<2)&&(n10==0)){
						flag = 0;
					}else{
						if(n10>0){
							n10 = n10 - 1;
							k ++;
						}else{
							n5 = n5 - 2;
							k ++;
						}
					}
				}
			}
		}
	}while((k<n)&&(flag!=0));
	if(flag==0){
			cout << "NO" << endl;
	}else{
			cout << "YES" << endl;
	}   
    }
    return 0;
}
