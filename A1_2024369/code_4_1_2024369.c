//Theory part of this question is submitted with other theory questions
//Additional test cases has been submitted in another pdf file

#include <stdio.h>

//Recursive function to find the last remaining citizen ie the first element of the array finally
int eliminate(int num,int arr[]){
	//Base condition
    if (num==1){
        return arr[0];
    }

	//Swapping the desired values in the first half of the array 
    int k=1;
    for (int j=0;j<num/2;j++){
        arr[j]=arr[k];
        k+=2;
    }

	//Recursively calling the function again in order to obtain the desired result
    return eliminate(num/2,arr);
}

int main(){
	int n;
	printf("Enter the number of citizens (n): ");
	scanf("%d",&n);

	//Creating an array containing integers : 1-->n
	int arr[n];
    for (int i=0;i<n;i++){
        arr[i]=i+1;
    }

	//Printing the result
    if (n%4==0 | (n-1)%4==0){
	printf("Position of last remaining citizen is: %d",eliminate(n,arr)-2);
    }
    else{
        printf("Position of last remaining citizen is: %d",eliminate(n,arr));
    }
}