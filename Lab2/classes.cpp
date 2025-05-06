#include <iostream>

class prop{
    int len,bre,hei;
    public:
    prop(){
        len=1;
        bre=1;
        hei=1;
    }
    void set_hei(int);
    void set_len(int);
    void set_bre(int);
    int get_area_sq(){
        return len*len;
    }
    int get_area_cube(){
        return len*len*6;
    }
    int get_area_rect(){
        return len*bre;
    }
    int get_area_cuboi(){
        return 2*((len*bre)+(bre*hei)+(hei*len));
    }
};

void prop::set_hei(int height){
    hei=height;
}

void prop::set_len(int length){
    len=length;
}

void prop::set_bre(int breadth){
    bre=breadth;
}

int main(){
    class prop shape;
    int choice;
    int length;
    int breadth;
    int height;
    while (1){
        printf("\nEnter Shape\n1)Square\n2)Cube\n3)Rectangle\n4)Cuboid\n5)Exit\n");
        scanf("%d",&choice);
        if (choice==5){
            break;
        }
        printf("Enter Length: ");
        scanf("%d",&length);
        shape.set_len(length);
        if (choice==1){
            printf("\nArea of square is %d.\n",shape.get_area_sq());
        }
        else if (choice==2){
            printf("\nArea of cube is %d.\n",shape.get_area_cube());
        }
        else if(choice==3){
            printf("Enter breadth: ");
            scanf("%d",&breadth);
            shape.set_bre(breadth);
            printf("\nArea of rectangle is %d.\n",shape.get_area_rect());
        }
        else if(choice==4){
            printf("Enter breadth: ");
            scanf("%d",&breadth);
            shape.set_bre(breadth);
            printf("Enter height: ");
            scanf("%d",&height);
            shape.set_hei(height);
            printf("\nArea of rectangle is %d.\n",shape.get_area_cuboi());
        }
    }
}