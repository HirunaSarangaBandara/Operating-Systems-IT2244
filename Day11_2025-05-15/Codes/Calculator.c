#include<stdio.h>
int main(){

	int a;
	printf("\nEnter number 1:");
	scanf("%d",&a);
	printf("Number 1 is:%d",a);

	int b;
	printf("\nEnter number 2:");
	scanf("%d",&b);
	printf("Number 2 is:%d",b);

	int add = a+b;
	printf("\nAddition:%d",add);

	int sub = a-b;
	printf("\nSubtraction:%d",sub);

	int mul = a*b;
	printf("\nMultiplication:%d",mul);

	int div = a/b;
	printf("\nDivision:%d",div);

	int reminder = a%b;
	printf("\nReminder:%d\n",reminder);
}