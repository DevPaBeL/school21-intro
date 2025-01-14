#include <stdio.h>
#include <math.h>

double important_function(double x);

int main() {
double x;
if(scanf("%lf", &x) != 1 || x == 0){
printf("n/a");
return 0;
}else{
printf("%.1lf", important_function(x));
}
}

double important_function(double x){
    return (7e-3 * pow(x,4) + ((22.8 * pow(x,1/3) - 1e3) * x + 3) / (x * x / 2) - x * pow((10 + x),(2/x)) - 1.01);
}
