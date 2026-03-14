//Theory part of this question is submitted with the other theory questions...
//Additional test cases has been submitted in another pdf file

#include <stdio.h>

//Binary Search function to obtain the left most identifier
int Search_left_most(int arr[],int length,int key){
    int low=0;
    int high=length-1;
    //ans=-1 if key is not found
    int ans=-1;
    while (low<=high){
        int mid=(low+high)/2;  
        if (arr[mid]==key){
            ans=mid;
            //continue search on the left is the mid value is the ans
            high=mid-1; 
        }
        else if (arr[mid]<key){
            //search towards right side of mid
            low=mid+1;
        }
        else{
            //search towards left side of mid
            high=mid-1;
        }
    }
    return ans;
}

//Binary Search function to obtain the right most identifier
int Search_right_most(int arr[],int length,int key){
    int low=0;
    int high=length-1;
    //ans=-1 if key is not found
    int ans=-1;
    while (low<=high){
        int mid=(low+high)/2;
        if (arr[mid]==key){
            ans=mid;
            //continue search on the right
            low=mid+1;
        }
        else if (arr[mid]<key){
            //search towards right side of mid
            low=mid+1;
        }
        else{
            //search towards left side of mid
            high=mid-1;
        }
    }
    return ans;
}

//Main Function
int main(){
    //Taking length of the array as input
    int length;
    printf("Enter number of scrolls: \n");
    scanf("%d",&length);

    int scrolls[length];
    printf("Enter values of the scrolls (separated by a space): \n");

    //Taking the values of scrolls as input 
    for (int i=0;i<length;i+=1){
        scanf("%d",&scrolls[i]);
    }

    int target;
    printf("Enter the target identifier: \n");

    //Taking target identifer as input
    scanf("%d",&target);

    //Calling the respective functions
    int start=Search_left_most(scrolls,length,target);
    if (start==-1){
        //Printing the result as [-1,-1] if the target is not found
        printf("Result: [-1,-1]");
    }
    else{
    int end=Search_right_most(scrolls,length,target);

    //Printing the desired result if the target is found  
    printf("Result: ");
    printf("[");
    printf("%d",start);
    printf(",");
    printf("%d",end);
    printf("]");
    }

    return 0;
}