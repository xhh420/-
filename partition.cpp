#include <bits/stdc++.h>
using namespace std;

int partition(int a[],int l,int r){
	int i=l,j=l+1;
	for(j;j<=r;j++){
		if(a[j]<=a[l]){
			i++;
			swap(a[j],a[i]);
		}
	}
	swap(a[i],a[l]);
	return i;
}

void qqsort(int a[],int l,int r,int i){
	if(l<=r){
		int p=partition(a,l,r);
		if(i<p) qqsort(a,l,p-1,i);
		else if(i>p) qqsort(a,p+1,r,i);
		else if(i==p) return ;
	}
}

int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++) cin>>a[i];
	qqsort(a,0,n-1,n/2);
	int m1=0,m2=0;
	for(int i=0;i<n/2;i++) m1+=a[i];
	for(int i=n/2;i<n;i++) m2+=a[i];
	m2=abs(m1-m2);
	cout<<m2;
	return 0;
}
