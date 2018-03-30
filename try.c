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
    //printf("sum: %s  min: %d  max: %d  d: %d\n", sum,min,max,d);
    
    
    i=n1-1;
    
    while(max>=d && i>=0 && j>=0)
    {
        if(max!=0)
        {
            sum[max]=((num1[i]-'0')+(num2[j]-'0')+(sum[max]-'0'))+'0';
            //printf("c:%d  ",sum[max]-'0');
            if(sum[max]-'0'>9)
            {
                sum[max]=((sum[max]-'0')-10)+'0';
                sum[max-1]='1';
            }
            //printf("sum[%d]:%c sum[%d]:%c    ",max-1,sum[max-1],max,sum[max]);
            i--;
            j--;
            max--;
            //printf("sum:%s   ",sum);
            //printf("%d %d %d\n",i,j,max);
        }
        else
            break;
    }
    
    for(x=max-1;x>=0;x--)
    {
        //printf("x:%d  ",x);
        sum[max]=((num[x]-'0')+(sum[max]-'0'))+'0';
        
        if(sum[max]-'0'>9)
        {
            sum[max]=((sum[max]-'0')-10)+'0';
            sum[max-1]='1';
            
        }
        max--;
        //printf("sum[%d]:%c sum[%d]:%c    ",max-1,sum[max-1],max,sum[max]);
        //printf("%s   \n",sum);
    }
    /*printf("z:z  ");
     printf("sum[%d]:%c sum[%d]:%c    ",max-1,sum[max-1],max,sum[max]);
     printf("%s   \n",sum);*/
    if(sum[0]=='0')
        return sum+1;
    return sum;
}

//Returns the difference (obviously, nonnegative) of two intals.
void* intal_diff(void* intal1, void* intal2)
{
    char* num1 = intal2str(intal1);
    char* num2 = intal2str(intal2);
    
    //printf("COMPARE %d \n",strcmp(num2,num1));
    
    char* int1,*int2;
    int n1=strlen(num1),n2=strlen(num2);
    int i,j,max=0,min=0 ,x=0,temp=0;
    if(n1>n2 || ((n1==n2)&&(strcmp(num2,num1)<0)))
    {
        max=n1;
        min=n2;
        i=n1-1;
        j=n2-1;
        int1 = (char*)malloc(n1);
        int2 = (char*)malloc(n2);
        strcpy(int1,num1);
        strcpy(int2,num2);
    }
    else if(n2>n1 ||((n1==n2)&&(strcmp(num2,num1)>=0)))
    {
        max=n2;
        min=n1;
        j=n1-1;
        i=n2-1;
        int1 = (char*)malloc(n2);
        int2 = (char*)malloc(n1);
        strcpy(int1,num2);
        strcpy(int2,num1);
    }
    free(num1);
    free(num2);
    char* diff = (char*)malloc(max+1);
    for(x=0;x<max;x++)
        diff[x]='0';
    diff[max+1]='\0';
    int d = max-min;
    /*printf("\nint1: %s   int2:%s\n",int1,int2);
     printf("diff: %s  min: %d  max: %d  d: %d  i:%d  j:%d\n", diff,min,max,d,i,j);*/
    
    max--;
    while(max>=d && i>=0 && j>=0)
    {
        temp = ((int1[i]-'0')-(int2[j]-'0')-(diff[max]-'0'));
        //printf("t:%2d  ",temp);
        if(temp<0)
        {
            diff[max]=(temp+10)+'0';
            diff[max-1]='1';
        }
        else
        {
            diff[max]=temp+'0';
        }
        /*printf("diff[%d]:%c diff[%d]:%c    ",max-1,diff[max-1],max,diff[max]);
         printf("diff:%s   ",diff);*/
        i--;
        j--;
        max--;
        //printf("%d %d %d\n",i,j,max);
    }
    for(x=max;x>=0;x--)
    {
        //printf("x:%2d  ",x);
        diff[max]=((int1[x]-'0')-(diff[max]-'0'))+'0';
        /*printf("diff[%d]:%c diff[%d]:%c    ",max-1,diff[max-1],max,diff[max]);
         printf("%s   \n",diff);*/
        max--;
        
    }
    /*printf("y:%2d  ",x);
     printf("diff[%d]:%c diff[%d]:%c    ",max-1,diff[max-1],max,diff[max]);
     printf("%s   \n",diff);*/
    x=0;
    while(diff[x]=='0'&& diff[x]!='\0')
        x++;
    //printf("x: %d, diff:%lu\n",x,strlen(diff));
    if(x==strlen(diff))
        return "0";
    return diff+x;
}

//Multiplies two intals and returns the product.
char* rev(char* str)
{
    int i = 0,temp=0;
    int j = strlen(str) - 1;
    
    while (i < j) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }
    return str;
}

void* intal_multiply(void* intal1, void* intal2)
{
    char* num1 = intal2str(intal1);
    char* num2 = intal2str(intal2);
    int n1=strlen(num1),n2=strlen(num2);
    int max=0,i,j,tmp=0;
    char a[n1],b[n2];
    int* mul=(int*)malloc(n1+n2);
    
    printf("\nProduct: ");
    char* product = (char*)malloc(n1+n2+1);
    for(i=0;i<n1+n2;i++)
        product[i]='0';
    product[n1+n2+1]='\0';
    printf("%s\n",product);
    
    printf("n1:%d  n2:%d  \n",n1,n2);
    
    for(i=n1-1,j=0;i>=0;i--,j++)
    {
        a[j] = num1[i]-'0';
    }
    for(i=n2-1,j=0;i>=0;i--,j++)
    {
        b[j] = num2[i]-'0';
    }
    for(i=0;i<n1;i++)
    {
        printf("a,b: %d  %d  ",a[i],b[i]);
    }
    printf("\nMul: ");
    for(i=0;i<n1+n2;i++)
    {
        mul[i]=0;
        printf("%d",mul[i]);
    }
    printf("\n\nMultiplying all the integers: \n");
    for(i=0;i<n2;i++)
    {
        for(j=0;j<n1;j++)
        {
            printf("a:%2d b:%2d mul:%3d ==> ",a[j],b[i],mul[i+j]);
            mul[i+j] += b[i]*a[j];
            printf("%2d %2d %3d\n",a[j],b[i],mul[i+j]);
        }
    }
    for(i=n1+n2-1;i>=0;i--)
    {
        printf("%d",mul[i]);
    }
    printf("\nTransferring the carry's:\n");
    for(i=0;i<n1+n2;i++)
    {
        tmp = mul[i]/10;
        mul[i] = mul[i]%10;
        mul[i+1] = mul[i+1] + tmp;
        printf("%d ",mul[i]);
    }
    printf("\n");
    for(i=0;i<n1+n2;i++)
    {
        printf("%d ",mul[i]);
    }
    printf("\n");
    //Extra zeroes in the beginning.
    for(i=n1+n2-1;i>=0;i--)
    {
        if(mul[i] > 0)
        {
            printf("%d-%d  ",mul[i],i);
            break;
        }
    }
    max=n1+n2-1;
    
    j=i;
    printf("\nP: max:%d j:%d i:%d\n",max,j,i);
    for(j=i;j>=0;j--)
    {
        product[j]=mul[j]+'0';
        printf("mul[%d]=%3d product[%d]=%3c\n",j,mul[j],j,product[j]);
    }
    printf("p: %s\n",product);
    product=rev(product);
    free(mul);
    i=0;
    while(product[i]=='0')
        i++;
    printf("%s\n",product);
    return product+i;
}
/*char* karatsuba(char* num1,char* num2)
 {
 int n1=strlen(num1),n2=strlen(num2),max=0,i=0;
 
 if(num1[i]-'0'<10 && num2[i]-'0'<10)
 return ((num1[i]-'0')*(num2[i]-'0'))+'0';
 
 if(n1>n2)
 {
 max=n1;
 int1 = (char*)malloc(max+1);
 int2 = (char*)malloc(max+1);
 
 strcpy(int1,num1);
 strcpy(int2+(n1-n2),num2);
 for(i=(n1-n2);i>0;i--)
 int2[i]='0';
 
 int1[max]='\0';
 int2[max]='\0';
 }
 else if(n1<n2)
 {
 max=n2;
 int1 = (char*)malloc(max+1);
 int2 = (char*)malloc(max+1);
 
 strcpy(int2,num2);
 strcpy(int1+(n2-n1),num1);
 for(i=(n2-n1);i>0;i--)
 int1[i]='0';
 
 int1[max]='\0';
 int2[max]='\0';
 }
 free(num1);
 free(num2);
 else
 max=n2;
 int half = max/2;
 
 
 char* num1_low = int1.substr(0,half);
 char* num2_low = int2.substr(half,max-half);
 char* num1_high = int1.substr(0,half);
 char* num2_high = int2.substr(half,max-half);
 
 void* a1 = intal_create(num1_low);
 void* a2 = intal_create(num1_high);
 void* b1 = intal_create(num2_low);
 void* b2 = intal_create(num2_high);
 
 char* p0 = karatsuba(num1_low,num2_low);
 char* p1 = karatsuba(num1_high,num2_high);
 char* p2 = karatsuba(intal_add(a1,a2),intal_add(b1,b2));
 char* p3 = intal_diff(intal_create(p2),intal_add(intal_create(p0),intal_create(p1)));
 
 }*/

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
    char *str1 = "1040";
    char *str2 = "1079";
    void *intal1;
    void *intal2;
    void *sum;
    void *diff;
    void *product;
    void *quotient;
    void *exp;
    
    intal1 = intal_create(str1);
    intal2 = intal_create(str2);
    
    printf("First intal: %s\n", intal2str(intal1));
    printf("Second intal: %s\n", intal2str(intal2));
    
    /*intal1 = intal_increment(intal1);
     intal2 = intal_decrement(intal2);
     
     printf("Two intals after increment and decrement:\n");
     printf("%s\n", intal2str(intal1));
     printf("%s\n", intal2str(intal2));
     
     printf("Max of two intals: %s\n", (intal_compare(intal1, intal2) > 0) ? intal2str(intal1) : intal2str(intal2));
     
     sum = intal_add(intal1, intal2);
     printf("Sum: %s\n", intal2str(sum));
     
     diff = intal_diff(intal1, intal2);
     printf("Diff: %s\n", intal2str(diff));
     */
    
    product = intal_multiply(intal1, intal2);
    printf("Product: %s\n", intal2str(product));
    
    /*quotient = intal_divide(intal1, intal2);
     printf("Quotient: %s\n", intal2str(quotient));
     
     exp = intal_pow(intal1, quotient);
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



