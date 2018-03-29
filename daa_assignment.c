#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void* intal_create(const char* str)
{
	char* intal = (char*)malloc(strlen(str));
	strcpy(intal,str);
	return intal;	
}
void intal_destroy(void* intal)
{
	free(intal);
}

char* intal2str(void* intal)
{
	return (intal);
}

void* intal_increment(void* intal)
{
	char* str = (char*)intal;
	int n = strlen(str),i=n-1;
	while(str[i]=='9' && i>=0)
	{
		str[i]='0';
		i--;
	}
	if(i<0)
	{
		char* new = (char*)malloc(strlen(str)+2);
		new[0]='1';
		strcpy(new+1,str);
		
		//printf("%s %s",new,str);
		new[n+1]='\0';
		free(str);
		return new;
		
	}
	else
	{
		str[i]=((str[i]-'0')+1)+'0';
		return str;
	}
}

void* intal_decrement(void* intal)
{
    char* str = (char*)intal;
	int n= strlen(intal);
	int i=n-1;
	while(str[i]=='0' && i>0)
	{
		str[i]='9';
		i--;
	}
	if(i>=0)
	{
		str[i]=((str[i]-'0')-1)+'0';
        
	}
    if(str[0]=='0')
    {
        return str+1;
    }
    return str;
}

//Adds two intals and returns their sum.
void* intal_add(void* intal1, void* intal2)
{
    char* num1 = intal2str(intal1);
    char* num2 = intal2str(intal2);
    char* num;
    int n1=strlen(num1),n2=strlen(num2);
    int i=n1-1,j=n2-1,max=0,min=0 ,x=0;
    if(n1>n2)
    {
        max=n1;
        min=n2;
        num = (char*)malloc(n1);
        strcpy(num,num1);
    }
    else
    {
        max = n2;
        min=n1;
        num = (char*)malloc(n2);
        strcpy(num,num2);
    }
    char* sum = (char*)malloc(max+2);
    for(i=0;i<max+1;i++)
        sum[i]='0';
    sum[max+1]='\0';
     int d = max-min;
    printf("sum: %s  min: %d  max: %d  d: %d\n", sum,min,max,d);
    
   
    i=n1-1;
    
    while(max>=d && i>=0 && j>=0)
    {
      if(max!=0)
      {
        sum[max]=((num1[i]-'0')+(num2[j]-'0')+(sum[max]-'0'))+'0';
        printf("c:%d  ",sum[max]-'0');
        if(sum[max]-'0'>9)
        {
            sum[max]=((sum[max]-'0')-10)+'0';
            sum[max-1]='1';
        }
        printf("sum[%d]:%c sum[%d]:%c    ",max-1,sum[max-1],max,sum[max]);
        i--;
        j--;
        max--;
        printf("sum:%s   ",sum);
        printf("%d %d %d\n",i,j,max);
     }
    else
        break;
    }
    
    for(x=max-1;x>=0;x--)
    {
        printf("x:%d  ",x);
        sum[max]=((num[x]-'0')+(sum[max]-'0'))+'0';
        
        if(sum[max]-'0'>9)
        {
            sum[max]=((sum[max]-'0')-10)+'0';
            sum[max-1]='1';
            
        }
        max--;
        printf("sum[%d]:%c sum[%d]:%c    ",max-1,sum[max-1],max,sum[max]);
        printf("%s   \n",sum);
    }
    printf("z:z  ");
    printf("sum[%d]:%c sum[%d]:%c    ",max-1,sum[max-1],max,sum[max]);
    printf("%s   \n",sum);
    if(sum[0]=='0')
        return sum+1;
    return sum;
}

//Returns the difference (obviously, nonnegative) of two intals.
void* intal_diff(void* intal1, void* intal2)
{
    char* num1 = intal2str(intal1);
    char* num2 = intal2str(intal2);
    int n1=strlen(num1);
    int n2=strlen(num2);
    int i=0;
    return 0;
}

//Multiplies two intals and returns the product.
void* intal_multiply(void* intal1, void* intal2)
{
    char* num1 = intal2str(intal1);
    char* num2 = intal2str(intal2);
    int n1=strlen(num1);
    int n2=strlen(num2);
    int i=0;
    return 0;
    
}

//Integer division
//Returns the integer part of the quotient of intal1/intal2.
//Returns "null" if intal2 is zero. A "null" pointer represents a NaN (not a number).
void* intal_divide(void* intal1, void* intal2)
{
    char* num1 = intal2str(intal1);
    char* num2 = intal2str(intal2);
    int n1=strlen(num1);
    int n2=strlen(num2);
    int i=0;
    return 0;
}

//Returns -1, 0, +1
//Returns 0 when both are equal.
//Returns +1 when intal1 is greater, and -1 when intal2 is greater.
int intal_compare(void* intal1, void* intal2)
{
    char* num1 =(char*)intal1;
    char* num2 =(char*)intal2;
    int i=0;
    int n1=strlen(num1);
    int n2=strlen(num2);
    
    if (n1<n2)
        return -1;
    else if(n1>n2)
        return 1;
    else
    {
        while(num1[i]==num2[i])
            i++;
        if (i==n1-1)
            return 0;
        else
        {
            if(num1[i]<num2[i])
                return -1;
            else if(num1[i]>num2[i])
                return 1;
        }
    }
    return 0;
}

//Returns intal1^intal2.
//It could be a really long integer for higher values of intal2.
//0^n = 0. where n is any intal.
void* intal_pow(void* intal1, void* intal2)
{
    char* num1 = intal2str(intal1);
    char* num2 = intal2str(intal2);
    int n1=strlen(num1);
    int n2=strlen(num2);
    int i=0;
    return 0;
}

int main(int argc, char const *argv[]) {
	char *str1 = "998";
	char *str2 = "100001";
	void *intal1;
	void *intal2;
	void *sum;
	void *diff;
	void *product;
	void *quotient;
	void *exp;

	intal1 = intal_create(str1); //4999
	intal2 = intal_create(str2); //2001

	printf("First intal: %s\n", intal2str(intal1)); //4999
	printf("Second intal: %s\n", intal2str(intal2)); //2001

	intal1 = intal_increment(intal1); //5000
	intal2 = intal_decrement(intal2); //2000

	printf("Two intals after increment and decrement:\n");
	printf("%s\n", intal2str(intal1)); //5000
	printf("%s\n", intal2str(intal2)); //2000

	//printf("Max of two intals: %s\n", //5000
	//	(intal_compare(intal1, intal2) > 0) ? intal2str(intal1) : intal2str(intal2));

	sum = intal_add(intal1, intal2); //7000
	printf("Sum: %s\n", intal2str(sum));
/*
	diff = intal_diff(intal1, intal2); //3000
	printf("Diff: %s\n", intal2str(diff));

	product = intal_multiply(intal1, intal2); //10000000
	printf("Product: %s\n", intal2str(product));

	quotient = intal_divide(intal1, intal2); //2
	printf("Quotient: %s\n", intal2str(quotient));

	exp = intal_pow(intal1, quotient); //5000^2 = 25000000
	printf("%s ^ %s: %s\n", intal2str(intal1), intal2str(quotient), intal2str(exp));

	//Make sure you destroy all the intals created.
	intal_destroy(sum);
	intal_destroy(diff);
	intal_destroy(product);
	intal_destroy(quotient);
	intal_destroy(exp);
	intal_destroy(intal1);	
	intal_destroy(intal2);
	return 0;
    */
    
}



