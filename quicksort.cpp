#include<iostream>
using namespace std;
int partition(int s,int e, int *a){
	int i=s-1;
	for (int j=s;j<=e;j++){
		if(a[j]<a[e]){
			i++;
			swap(a[i],a[j]);
		}

	}
	swap(a[i+1],a[e]);
	return i+1;

}
void quicksort(int*a, int s,int e){
	
}
int main(){
	return 0;

}