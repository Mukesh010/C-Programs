#include<stdio.h>
void Heapify(int a[],int n,int i);

void buildheap(int a[],int n){
    int i;
    for(i=n/2-1;i>=0;i--)
        Heapify(a,n,i);
}

void Heapify(int a[],int n,int i){
    int left,right,max,temp;
    left=2*i+1;
    right=2*i+2;
    max=i;
    if((left<n)&&(a[left]>a[max]))
        max=left;
    if((right<=n-1)&&(a[right]>a[max]))
        max=right;
    if(i!=max){
        temp=a[i];
        a[i]=a[max];
        a[max]=temp;
        Heapify(a,n,max);
    }

}
void Heapsort(int a[],int n){

    int temp,i,size;
    buildheap(a,n);
    size=n;
    for(i=n-1;i>0;i--){
        temp=a[0];
        a[0]=a[size-1];
        a[size-1]=temp;
        size--;
        Heapify(a,size,0);
    }

}

int main(){
    int i,N=10;
    int a[]={5,3,7,23,11,6,34,9,1,2};
    Heapsort(a,N);
    for(i=0;i<N;i++)
        printf("%d  ",a[i]);
}
