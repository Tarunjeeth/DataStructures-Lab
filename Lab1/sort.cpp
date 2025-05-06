#include <iostream>

void selection(int arr[],int len){                      //function to sort the elements using selection sort
    for (int i=0;i<len-1;i++){
        int imin=i;
        for (int j=i;j<len;j++){
            if (arr[imin]>arr[j]){
                imin=j;
            }
        }
        if (imin!=i){
            int temp=arr[i];
            arr[i]=arr[imin];
            arr[imin]=temp;
        }
    }
}

void insertion(int arr[],int len){                             //function to sort the elements using insertion sort                 
    for (int i=0;i<len;i++){
        int key=arr[i];
        int j=i-1;
            while(j>=0 && key<arr[j]){
                arr[j+1]=arr[j];
                j--;
            }
            arr[j+1]=key;
        }
    }


void bubble(int arr[],int len){                                 //function to sort the elements using bubble sort
    for (int i=0;i<len;i++){
        for (int j=0;j<len-1;j++){
            if (arr[j]>arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}

void display(int arr[],int len){                                //function to display the elements of the array
    printf("\n");
    for(int i=0;i<len;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}

int main(){
    int choice;
    int len;
    printf("\nEnter length of the array :");                    //taking array as an input
    scanf("%d",&len);
    int arr[len];
    for (int i=0;i<len;i++){
        printf("\nEnter element no.%d :",i);
        scanf("%d",&arr[i]);
    }

    while(1){                                                   //menu driven
        printf("\n1.Insertion Sort\n2.Selection Sort\n3.Bubble Sort\n4.Display\n5.Quit\nEnter Choice : ");
        scanf("%d",&choice);
        if (choice==1){
            insertion(arr,len);
        }
        else if(choice==2){
            selection(arr,len);
        }
        else if(choice==3){
            bubble(arr,len);
        }
        else if(choice==4){
            display(arr,len);
        }
        else{
            break;
        }
        
    }
}
