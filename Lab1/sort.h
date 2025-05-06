void selection(int arr[],int len){
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

void insertion(int arr[],int len){
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


void bubble(int arr[],int len){
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
