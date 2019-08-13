//RC05

#include <iostream>
#include <stdlib.h> 
#include <cmath> 
using namespace std;

int main(){

	int dataWord[30],codeWord[30];
	int bitsAdd = 0,totBits = 0,pbit = 0,count = 1,inc = 0, flag = 0, flag2 = 0;
	
	cout << "\nEnter total number Of Bits : ";
	cin >> totBits;
	
	
	while((totBits + bitsAdd + 1) > pow(2,bitsAdd)){
	 bitsAdd++;
	}
	
	cout << "\nTotal Number Of Bits to Add  : " << bitsAdd << endl;
	
	cout << "\nEnter your data word : ";
	for(int i = 0; i < totBits; i++){
		cin >> dataWord[i];
	}
	
	for(int i = 0, j = 0, k = 0; k < totBits; i++){
		
		if((i+1) == pow(2,j)){
		   codeWord[i] = 2;
		   j++;
		}
		else{
		   codeWord[i] = dataWord[k];
		   k++; 
		}
	}
	
	cout<<"\nCodeWord : ";
	for(int i = 0 ; i < (totBits + bitsAdd) ; i++){
		cout << codeWord[i];
	}
	
	for(int i = 0; i < (totBits+bitsAdd) ; i++){
		if(codeWord[i] == 2){
	
			count = pow(2,inc);
			inc++;
			cout <<	"\nCount : " << count <<endl;

			for(int j = i + 1 ; j < (totBits + bitsAdd); j += (2*(i+1))){
		//		cout << "\nJ - loop : " << j;
				if((j - 1) == 0){
				  j = j + 1;
				  pbit = codeWord[j];
				  cout << "\npbit : " << pbit << " j : " << j << " " << codeWord[j];
				  flag = 1;				
				}
				else{
					if(i >= 3 && flag2 != 0){
		//			  cout << " \nj & i: " << j << " "<< i << endl;
					  j = j - 1;
					}
															
					for(int k = 0; k < count && ((j+k) < (totBits + bitsAdd)); k++){
						if( k == 0 && codeWord[j+k]!=2 && flag!=1){
						 pbit = codeWord[j+k];
						 flag = 1;
						 flag2 = 1;
						 cout << "\nJ+K : " << j+k;
						}
						else if(codeWord[j + k] != 2){
							if(flag == 0){
							   pbit = codeWord[j+k];
							   flag = 1;							
							} 
							else{
								if(i == 1 && j == 6){
		//						   cout << "\nsetting j at i=1"<<endl;						  
		  						   j = j - 1;	
								} 
								pbit = pbit ^ codeWord[j + k];
								flag2 = 0;						
		 cout << "\ni + 1: " << i+1 <<" pbit : " << pbit << " j : " << j << " k : " << k << " j + k : " << j+k;
							}						
						}
					}
					if(j == 4 && i == 3){
					   j = j-1;	
					}	
				}
			}		
			cout << "\nPbit " << i+1 << " : " << pbit <<endl;
			codeWord[i] = pbit;
			flag = 0;
		}
	}

	cout<<"\nCodeWord : ";
	for(int i = 0;i < (totBits + bitsAdd);i++){
		cout << codeWord[i];
	}
	cout<<"\n";	
}

