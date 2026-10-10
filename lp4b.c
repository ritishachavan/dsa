#include<stdio.h>
#include<math.h>
void tower(int n,char a,char b,char c){
    if(n==1){
        printf("Disk moves from %c to %c/",a,c);
        return;
    }
    tower(n-1,a,c,b);
    printf("disk moves from %c to %c\n",a,c);
    tower(n-1,b,a,c);
}
void main(){
    int n;
    printf("enter the number of disks:");
    scanf("%d",&n);
    tower(n,'A','B','C');
    int x=pow(2,n)-1;
    printf("total number of moves: %d",x);

}