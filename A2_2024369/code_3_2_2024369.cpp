#include <iostream>
#include <string>
using namespace std;

//Creating node class
class Node{
    public:
    int x;
    int y;
    Node* next;

    Node(int x_coord, int y_coord){
        x=x_coord;
        y=y_coord;
        next=NULL;
    }
};

//Creating Hashtable class
class HashTable{
    private:
    int Bucket;
    Node** table;

    public:
    HashTable(int M){
        Bucket=M;
        table=new Node*[Bucket];
        for(int i=0;i<Bucket;i++){
            table[i]=NULL;
        }
    }

    //Creating hash_function
    int Hash_Function(int x, int y){
        return ((x+y)%10);
    }

    //Creating function to insert coordinates
    void insert_coordinates(int x, int y){
        int hash=Hash_Function(x,y);
        Node* temp=new Node(x,y);

        if(table[hash]==NULL){
            table[hash]=temp;
        }
        else{
            Node* ptr=table[hash];
            while(ptr->next!=NULL){
                ptr=ptr->next;
            }
            ptr->next=temp;
        }
    }

    //Creating function to display coordinates
    void display_coordinates(){
        for (int i=0;i<Bucket;i++){
            if (table[i]!=NULL){
                Node* p=table[i];
                while (p!=NULL){
                    cout<<"("<<p->x<<","<<p->y<<")"<<" ";
                    p=p->next;
                }
            }
            else{
                cout<<"Empty";
            }
            cout<<endl;
        }
    }

    //Creating function to search coordinates
    bool search_coordinates(int x, int y){
        int hash=Hash_Function(x,y);
        Node* ptr=table[hash];
        int pos=0;

        while (ptr!=NULL){
            if (ptr->x==x && ptr->y==y){
                cout << "Coordinates (" << x << "," << y << ") found in bucket " << hash << " at position " << pos << "." << endl;
                return true;
            }
            ptr=ptr->next;
            pos++;
        }
        return false;
    }
};

//Main Function
int main(){
    cout<<"Function Menu: "<<endl;
    cout<<"1. Add a coordinate"<<endl;
    cout<<"2. Display all coordinates"<<endl;
    cout<<"3. Search for a coordinate"<<endl;
    cout<<"4. Exit"<<endl;

    // int table_size;
    // cout<<"Enter table size: ";
    // cin>>table_size;
    // HashTable table(table_size);

    HashTable table(10);                  //In test cases, it was taken 10 (we can take input too, I have commented that code)
    int ans;
    while (true){
        cout<<"What you want to do? (1/2/3/4): "<<endl;
        cin>>ans;
        if (ans==1){
            int x_coord, y_coord;
            cout<<"Enter x coordinate: ";
            cin>>x_coord;

            cout<<"Enter y coordinate: ";
            cin>>y_coord;

            cout<<"Inserting coordinates...."<<endl;
            table.insert_coordinates(x_coord, y_coord);
            cout<<"Current Table: "<<endl;
            table.display_coordinates();
        }
        else if (ans==2){
            cout<<"Displaying all coordinates..."<<endl;
            table.display_coordinates();
        }
        else if (ans==3){
            int x_coord, y_coord;
            cout<<"Enter x coordinate you want to search: ";
            cin>>x_coord;

            cout<<"Enter y coordinate you want to search: ";
            cin>>y_coord;

            cout<<"Searching..."<<endl;
            bool found=table.search_coordinates(x_coord, y_coord);
            if (found==false){
                cout << "Treasure Not Found!!" << endl;
            }
        }
        else if (ans==4){
            cout<<"Exiting the system..."<<endl;
            break;
        }
        else{
            cout<<"Kindly choose a valid option"<<endl;
        }
    }
}