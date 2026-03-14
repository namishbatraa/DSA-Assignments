#include <iostream>
using namespace std;

class Heap{
    public:
    void build_max_heap(int arr[], int n) {
        for (int i=(n/2)-1;i>=0;i--){
            heapify(arr, n, i);
        }
    }
    private:
    void heapify(int arr[], int n, int i){
        int largest=i;
        int left=2*i+1;
        int right=2*i+2;
        if (left<n && arr[left]>arr[largest]){
            largest=left;
        }
        if (right<n && arr[right]>arr[largest]){
            largest=right;
        }
        if (largest!=i){
            swap(arr[i], arr[largest]);
            heapify(arr, n, largest);
        }
    }
};

int main(){
    Heap h;
    int n,k;
    cout<<"Enter total number of towers: ";
    cin>>n;

    cout<<"Enter size of window: ";
    cin>>k;
    
    if (k>n || k<=0){
        cout<<"Invalid size of window"<<endl;
        return 0;
    }
    int arr[n];
    cout<<"Enter the heights (separated by a space): ";
    for (int i=0; i<n; i++){
        cin>>arr[i];
    }
    int result[n-k+1];
    for (int i=0;i<=n-k;i++){
        int window[k];
        for (int j=0;j<k;j++){
            window[j]=arr[i+j];
        }
        h.build_max_heap(window, k);
        result[i]=window[0];
    }

    cout<<"Tallest towers : ";
    for (int i=0; i<= n-k; i++){
        cout<<result[i]<<" ";
    }
    return 0;
}