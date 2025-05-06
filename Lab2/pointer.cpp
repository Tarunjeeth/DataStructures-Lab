#include <iostream>
#include <stdlib.h>

int palindrome(int* num){
    int *number_c;
    number_c=(int *)malloc(sizeof(int));
    *number_c=*num;
    int *number_2;
    number_2=(int *)malloc(sizeof(int));
    *number_2=0;
    while ((*number_c)!=0){
        (*number_2)=(*number_2)*10+(*number_c)%10;
        *number_c/=10;
    }
    if ((*number_2)==(*num)){
        return 1;
    }
    else{
        return 0;
    }
}

int leng(int *num){
    int *number_c;
    number_c=(int *)malloc(sizeof(int));
    *number_c=*num;
    int *length;
    length=(int *)malloc(sizeof(int));
    *length=0;

    while(*number_c!=0){
        *number_c/=10;
        *length+=1;
    }
    return *length;
}

int power(int *num,int *len){
    int *res; 
    res=(int *)malloc(sizeof(int));
    *res=1;

    int *len_c;
    len_c=(int *)malloc(sizeof(int));
    *len_c=*len;

    while (*len_c!=0){
        *res=(*res)*(*num);
        *len_c-=1;
    }
    return *res;
}

int amstrong(int* num){
    int *number_c;
    number_c=(int *)malloc(sizeof(int));
    *number_c=*num;
    int *number_2;
    number_2=(int *)malloc(sizeof(int));
    *number_2=0;
    int *number_bit;
    number_bit=(int *)malloc(sizeof(int));
    int *len;
    len=(int *)malloc(sizeof(int));
    *len=leng(num);
    while (*number_c!=0){
        *number_bit=(*number_c)%10;
        (*number_2)+=power(number_bit,len);
        *number_c/=10;;
    }

    if ((*number_2)==(*num)){
        return 1;
    }
    else{
        return 0;
    }
}

int perfect(int *num){
    int *number_2;
    number_2=(int *)malloc(sizeof(int));
    *number_2=0;

    int *i;
    i=(int *)malloc(sizeof(int));
    for (*i=1;*i<(*num);(*i)++){
        if (*num%(*i)==0){
            *number_2+=*i;
        }
    }
    if ((*number_2)==(*num)){
        return 1;
    }
    else{
        return 0;
    }
}

int main(){
    int *choice;
    choice=(int *)malloc(sizeof(int));
    int *number;
    number=(int *)malloc(sizeof(int));
    int *val;
    val=(int *)malloc(sizeof(int));
    while (1){
        printf("\n\nNumber Property\n1)Palindrome Number\n2)Amstrong Number\n3)Perfect Number\n4)Exit\nEnter Choice: ");
        scanf("%d",choice);
        if(*choice==4){
            break;
        }
        printf("\nEnter Number: ");
        scanf("%d",number);
        if (*choice==1){
            *val=palindrome(number);
            if (*val==1){
                printf("\n%d is a Palindrome Number.",*number);
            }else{
                printf("\n%d is not a Palindrome Number.",*number);
            }
        }
        else if(*choice==2){
            *val=amstrong(number);
            if (*val==1){
                printf("\n%d is an Armstrong Number.",*number);
            }else{
                printf("\n%d is not an Armstrong Number.",*number);
            } 
        }
        else if(*choice==3){
            *val=perfect(number);
            if (*val==1){
                printf("\n%d is a Perfect Number.",*number);
            }else{
                printf("\n%d is not a Perfect Number.",*number);
            } 
        }
        }

    return 0;
}