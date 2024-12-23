#include<iostream>
using namespace std;
void prime_seive(int n,int p[]){
	//first mark all the odd number`s prime
	for(int i=3;i<=1000000;i+=2){
		p[i]=1;

	}
	for(int i=3;i<1000000;i+=2){
		//if the current is not marked
		if(p[i]==1){
			//mark the multiples of i as not primes
			for(ll j=i*i;j<1000000;j=j+i){
				p[j]=0;
			}
		}
	}
	p[2]=1;
	p[1]=p[0]=0;
}
int main(){
	return 0;
}
