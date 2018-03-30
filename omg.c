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
typedef unsigned int uint32;

enum PaddingType { LEFT, RIGHT };
bool isZero(const string& oper) {
    for (size_t i = 0, l = oper.size(); i < l; i++)
        if (oper[i] != '0') return false;
    return true;
}
char* padString(const string& toPad, size_t paddingCountToAdd, char paddingChar, PaddingType paddingType = RIGHT) {
    string s(paddingCountToAdd, paddingChar);
    return paddingType == LEFT ? s + toPad : toPad + s;
}
char* removeLeftZeros(const string& value) {
    // Delete '0's from the left
    if (value.size() > 1 && value[0] == '0') {
        for (size_t i = 0, l = value.size(); i < l; i++) {
            if (value[i] == '0')
                continue;
            return value.substr(i, l - i);
        }
    }
    return value;
}
char*mulIntStringByChar(const string& op1, const char op2) {
    if (op2 == '0') return "0";
    if (op2 == '1') return op1;
    
    int carry = 0;
    int d0 = op2 - '0';
    char*r = "";
    for (int j = op1.size() - 1; j >= 0; j--) {
        int d1 = op1[j] - '0';
        int d = (d0 * d1) + carry;
        carry = d / 10;
        d %= 10;
        r += d + '0';
    }
    if (carry) r += carry + '0';
    reverse(r.begin(), r.end());
    return r;
}
char* subIntStrings(const string& op1, const string& op2) {
    if (op2 == "") return op1;
    
    char*total = "";
    size_t op1Size = op1.size();
    size_t op2Size = op2.size();
    
    uint32 carry = 0;
    for (int i = 0; i < op1Size; i++) {
        int c0 = op1[op1Size - 1 - i] - '0' - carry;
        int c1 = i < op2Size ? op2[op2Size - 1 - i] - '0' : 0;
        carry = 0;
        if (c0 < c1) {
            carry = 1;
            c0 += 10;
        }
        total += (c0 - c1) + '0';
    }
    reverse(total.begin(), total.end());
    return isZero(total) ? "0" : removeLeftZeros(total);
}
char* sumIntStrings(const string& op1, const string& op2) {
    if (op2 == "") return op1;
    if (op1 == "") return op2;
    char*total = "";
    size_t op1Size = op1.size();
    size_t op2Size = op2.size();
    size_t m = max(op1Size, op2Size);
    
    uint32 carry = 0;
    for (int i = 0; i < static_cast<int>(m); i++) {
        uint32 c0 = i < op1Size ? op1[op1Size - 1 - i] - '0' : 0;
        uint32 c1 = i < op2Size ? op2[op2Size - 1 - i] - '0' : 0;
        uint32 c = c0 + c1 + carry;
        carry = c / 10;
        total += (c % 10) + '0';
    }
    if (carry) total += carry + '0';
    reverse(total.begin(), total.end());
    return total;
}
char*multKaratsuba(const string& oper1, const string& oper2) {
    // 2 * O(n)
    if (isZero(oper1) || isZero(oper2)) {
        return "0";
    }
    
    // 2 * O(n)
    char*op1 = removeLeftZeros(oper1);
    char*op2 = removeLeftZeros(oper2);
    
    // O(1) (theoritically)
    size_t l1 = op1.size();
    size_t l2 = op2.size();
    
    if (l1 == 1 || l2 == 1)
        // O(1)
        return mulIntStringByChar(l1 == 1 ? op2 : op1, l1 == 1 ? op1[0] : op2[0]);
    
    // Divide
    size_t n = max(l1, l2);
    n += (n & 1);
    
    // 2 * O(n)
    op1 = padString(op1, n - l1, '0', LEFT);
    op2 = padString(op2, n - l2, '0', LEFT);
    
    size_t n2 = n / 2;
    
    // 4 * O(n)
    char*a = op1.substr(0, n2);
    char*b = op1.substr(n2, n2);
    char*c = op2.substr(0, n2);
    char*d = op2.substr(n2, n2);
    
    // 2 recursive calls
    char*ac = multKaratsuba(a, c);
    char*bd = multKaratsuba(b, d);
    
    // 2 * O(n)
    char*_ab = sumIntStrings(a, b);
    char*_cd = sumIntStrings(c, d);
    
    // another call
    char*abcd = multKaratsuba(_ab, _cd);
    
    // 2 * O(n)
    abcd = subIntStrings(abcd, ac);
    abcd = subIntStrings(abcd, bd);
    
    // 5 * O(n)
    ac = padString(ac, n, '0', RIGHT);
    abcd = padString(abcd, n2, '0', RIGHT);
    char*res = sumIntStrings(ac, abcd);
    res = sumIntStrings(res, bd);
    return removeLeftZeros(res);
}

void* intal_multiply(void* intal1, void* intal2)
{
    char* num1 = (char*) intal1;
    char* num2 = (char*)intal2;
    char* product = multKaratsuba(num1,num2);
    return product;
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
    char *str1 = "10435415";
    char *str2 = "1075125125312";
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
    
    product = intal_multiply1(intal1, intal2);
    printf("Product: %s\n", intal2str(product));
    quotient = intal_divide(intal1, intal2);
     printf("Quotient: %s\n", intal2str(quotient));
     /*
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



