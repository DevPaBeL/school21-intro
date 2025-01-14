#include <stdio.h>

int max(int a, int b);

int main() {
int a, b;
if(scanf("%d%d", &a, &b) != 2){
    printf("n/a");
    return 0;
}else{
    printf("%d",max(a,b));
}
}
int max(int a, int b){
if(a > b){
    return a;
}else{
    return b;
}
}
