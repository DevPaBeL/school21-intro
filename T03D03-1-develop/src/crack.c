#include <stdio.h>
 
double crack(double x, double y);
 
int main() {
double x, y;
if(scanf("%lf%lf", &x, &y) != 2){
    printf("n/a");
    return 0;
}
if(crack(x,y)){
    printf("GOTCHA");
}else{
    printf("MISS");
}
}
double crack(double x, double y) {
    return (x*x + y*y <= 25);
}
