#include <iostream>

class list{
    int arr[5];
    int current;
    int size;
    public:
        list(){
            current=-1;
            size=5;
        }
        int insert_beg(int ele){
            if (current==size-1){
                return 0;
            }
            else{
                int temp=current;
                temp++;
                while (temp!=0){
                    arr[temp]=arr[temp-1];
                    temp--;
                }
                arr[temp]=ele;
                current++;
                return 1;
            }
        }

        int insert_end(int ele){
            if (current==size-1){
                return 0;
            }
            else{
                current++;
                arr[current]=ele;
                return 1;
            }
        }

        int insert_pos(int ele,int pos){
            if (pos>current||current==size-1){
                return 0;
            }else{
                if (pos==0){
                    insert_beg(ele);
                    return 1;
                }
                else{    
                    current++;
                    int temp=current;
                    while(temp!=pos){
                        arr[temp]=arr[temp-1];
                        temp--;
                    }
                        arr[temp]=ele;
                        return 1;
                }
            }
        }

        int delete_beg(){
            if (current==-1){
                printf("Failure");
                return 0;
            }else{
                int pop=arr[0];
                int temp=0;
                while(temp<current){
                    arr[temp]=arr[temp+1];
                    temp++;
                }
                current--;
                return pop;
            }
        }

        int delete_end(){
            if (current==-1){
                printf("Failure");
                return 0;
            }else{
                int pop=arr[current];
                current--;
                return pop;
            }
        }

        int delete_position(int pos){
            if (current==-1||pos>current){
                printf("Failure");
                return 0;
            }else{
                if (pos==0){
                    delete_beg();
                    return 1;
                }else{
                    int pop=arr[pos];
                    int temp=pos;
                    while(temp<current){
                        arr[temp]=arr[temp+1];
                        temp++;  
                    }
                    current--;
                    return pop;
                }
            }
        }

        int search(int ele){
            int bool1=0;
            if (current==-1){
                printf("Failure");
            }else{
                for (int i=0;i<=current;i++){
                    if (arr[i]==ele){
                        bool1=1;
                    }
                }
            }
            return bool1;
        }

        void rotate(int k){
            for (int i=0;i<k;i++){
                insert_beg(delete_end());
            }
        }
        void display(){
            printf("\n");
            for (int i=0;i<(current+1);i++){
                printf("-->%d",arr[i]);
            }
        }    
};

int main(){
    list l1;
    int choice;
    int ele;
    int pos;
    int k;
    while (1){
        printf("\n1.Insert at Beginning\n2.Insert at end\n3.Insert at Position");
        printf("\n4.Delete at Beginning\n5.Delete at End\n6.Delete at Position\n7.Search");
        printf("\n8.Display\n10.Exit");
        printf("\nEnter Choice: ");
        scanf("%d",&choice);
        if(choice==1){
            printf("\nEnter Element to be inserted: ");
            scanf("%d",&ele);
            if(l1.insert_beg(ele)){
                printf("\nSuccessfully Inserted");
            }else{
                printf("\nFailure");
            }
        }
        else if(choice==2){
            printf("\nEnter Element to be inserted: ");
            scanf("%d",&ele);
            if(l1.insert_end(ele)){
                printf("\nSuccessfully Inserted");
            }else{
                printf("\nFailure");
            }
        }
        else if (choice==3){
            printf("\nEnter Element to be inserted: ");
            scanf("%d",&ele);
            printf("\nEnter Position: ");
            scanf("%d",&pos);
            if(l1.insert_pos(ele,pos)){
                printf("\nSuccessfully Inserted");
            }else{
                printf("\nFailure");
            }
        }
        else if (choice==4){
            if(l1.delete_beg()){
                printf("\nSuccessfully Deleted");
            }else{
                printf("\nFailure");
            }
        }
        else if(choice==5){
            if(l1.delete_end()){
                printf("\nSuccessfully Deleted");
            }else{
                printf("\nFailure");
            }
        }
        else if(choice==6){
            printf("\nEnter Position: ");
            scanf("%d",&pos);
            if(l1.delete_position(pos)){
                printf("\nSuccessfully Deleted");
            }else{
                printf("\nFailure");
            }
        }
        else if (choice==7){
            printf("\nEnter Element to be searched: ");
            scanf("%d",&ele);
            if(l1.search(ele)){
                printf("\nElement is Present.");
            }else{
                printf("\nElement is not found.");
            }
        }
        else if(choice==8){
            l1.display();
        }
        else if(choice==9){
            printf("\nEnter Element to be searched: ");
            scanf("%d",&k);
            l1.rotate(k);
        }
        else if(choice==10){
            break;
        }
    
    }
    l1.insert_beg(2);
    l1.insert_beg(3);
    l1.insert_end(1);
    l1.display();
    
}