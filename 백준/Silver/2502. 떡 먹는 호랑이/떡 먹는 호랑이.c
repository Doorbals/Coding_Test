#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int coef_check_a(int day){
	if(day <= 2)
		return 1;
	
	else
		return coef_check_a(day - 1) + coef_check_a(day - 2);
}
int coef_check_b(int day){
	if(day <= 2)
		return (day - 1);
	
	else
		return coef_check_b(day - 1) + coef_check_b(day - 2) + 1;
}

int main(){
	int i, j, k, day, count, coef_a, coef_b, a = 0, b = 0;
	scanf("%d %d", &day, &count);
	coef_a = coef_check_a(day) - coef_check_a(day - 1);
	coef_b = coef_check_b(day) - coef_check_b(day - 1);
	
	for(i = 1 ; (coef_b * i <= count); i++){
		for(j = 1 ; i >= j; j++){
			if(coef_a * j + coef_b * i == count){
				a = j;
				b = i;
				goto EXIT;
			}
		}
			
	}
EXIT:	
	printf("%d\n", a);
	printf("%d\n", b);
	return 0;
}