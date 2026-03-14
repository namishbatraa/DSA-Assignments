#include <iostream>
#include <string>
using namespace std;

//Creating Node Class
class Node {
    public:
        int id;
        string sender;
        string receiver;
        float weight;
        int priority;
        Node* next;
        Node(int i, string s, string r, float w, int p){
            id=i;
            sender=s;
            receiver=r;
            weight=w;
            priority=p;
            next=nullptr;
        }
};

//Creating Stack Class
class Stack{
    Node* top;
    public:
        Stack(){
            top=nullptr;
        }
        //Creating push function
        Node* add_parcel(int i, string s, string r, float w, int p){
            Node* new_top=new Node(i,s,r,w,p);
            Node* temp=top;
            if (! new_top){
                cout<<"Stack Overflow"<<endl;
                return top;
            }
            if (top==nullptr || new_top->priority < top->priority || (new_top->priority==top->priority && new_top->id<top->id)){
                new_top->next=top;
                top=new_top;
            }
            else{
                while (temp->next != nullptr && (temp->next->priority < new_top->priority ||(temp->next->priority == new_top->priority && temp->next->id < new_top->id))){
                    temp=temp->next;
                }
                new_top->next=temp->next;
                temp->next=new_top;
            }
            return top;
        }

        //Creating pop function
        Node* dispatch_parcel(){
            if (top==nullptr){
                cout<<"Nothing present on stack"<<endl;
            }
            else{
            int top_id=top->id;
            string top_sender=top->sender;
            string top_receiver=top->receiver;
            float top_weight=top->weight;
            int top_priority=top->priority;

            cout<<"Popped element details: "<<endl;
            cout<<"Id: "<<top_id<<endl;
            cout<<"Sender: "<<top_sender<<endl;
            cout<<"Receiver: "<<top_receiver<<endl;
            cout<<"Weight: "<<top_weight<<endl;
            cout<<"Priority: "<<top_priority<<endl;

            Node* temp=top;
            top=temp->next;
            temp->next=NULL;
            delete temp;
            return top;
        }
    }

        //Creating view function
        void view_parcel(){
            if (top==nullptr){
                cout<<"Nothing present on stack"<<endl;
                return;
            }
            int top_id=top->id;
            string top_sender=top->sender;
            string top_receiver=top->receiver;
            float top_weight=top->weight;
            int top_priority=top->priority;

            cout<<"Details of next parcel to be dispatched: "<<endl;
            cout<<"Id: "<<top_id<<endl;
            cout<<"Sender: "<<top_sender<<endl;
            cout<<"Receiver: "<<top_receiver<<endl;
            cout<<"Weight: "<<top_weight<<endl;
            cout<<"Priority: "<<top_priority<<endl;
        }

        //Creating display function
        void display_parcels(){
            if (top==nullptr){
                cout<<"Nothing present on stack"<<endl;
                return;
            }
            else{
            Node* temp=top;
            cout<<"Details of all parcels are: "<<endl;
            int count;
            count=1;
            while(temp!=nullptr){
                cout<<"Details of parcel "<<count<<" :"<<endl;
                cout<<"Id: "<<temp->id<<endl;
                cout<<"Sender: "<<temp->sender<<endl;
                cout<<"Receiver: "<<temp->receiver<<endl;
                cout<<"Weight: "<<temp->weight<<endl;
                cout<<"Priority: "<<temp->priority<<endl;
                cout<<endl;
                temp=temp->next;
                count++;
            }
        }
    }

        //Creating count function
        void count_parcels(){
            if (top==nullptr){
                cout<<"Nothing present on stack"<<endl;
                return;
            }
            else{
                int count1=0;
                int count2=0;
                int count3=0;
                Node* temp=top;
                while(temp!=nullptr){
                    if (temp->priority==1){
                        count1++;
                    }
                    else if (temp->priority==2){
                        count2++;
                    }
                    else{
                        count3++;
                    }
                    temp=temp->next;
                }
                cout<<"Counting done..."<<endl;
                cout<<"Number of High Priority Parcels: "<<count1<<endl;
                cout<<"Number of Medium Priority Parcels: "<<count2<<endl;
                cout<<"Number of Low Priority Parcels: "<<count3<<endl;
            }
        }

        //Creating search function
        void search_parcel(int i){
            if (top==nullptr){
                cout<<"Nothing present on stack"<<endl;
                return;
            }
            Node* temp=top;
            while (temp!=NULL){
                if (temp->id==i){
                    cout<<"Id Found, Following are its complete details: "<<endl;
                    cout<<"Sender: "<<temp->sender<<endl;
                    cout<<"Receiver: "<<temp->receiver<<endl;
                    cout<<"Weight: "<<temp->weight<<endl;
                    cout<<"Priority: "<<temp->priority<<endl;
                    return;
                }
                else{
                    cout<<"Id does not match, moving to next...."<<endl;
                    temp=temp->next;
                }
            }
        }
};

//Main Function
int main(){
    cout<<"Function Menu: "<<endl;
    cout<<"1. Add Parcel"<<endl;
    cout<<"2. Dispatch Parcel"<<endl;
    cout<<"3. View Parcel"<<endl;
    cout<<"4. Display all parcels"<<endl;
    cout<<"5. Count Parcels by priority"<<endl;
    cout<<"6. Search Parcel by id"<<endl;
    cout<<"7. Exit"<<endl;
    Stack Parcels; 
    int ans;
    while (true){
        cout<<"What you want to do? (1/2/3/4/5/6/7): ";
        cin>>ans;
        if (ans==1){
            Node* top;
            int i;
            cout<<"Enter id: ";
            cin>>i;
            cout<<endl;

            string s;
            cout<<"Enter sender: ";
            cin>>s;
            cout<<endl;

            string r;
            cout<<"Enter receiver: ";
            cin>>r;
            cout<<endl;

            float w;
            cout<<"Enter weight: ";
            cin>>w;
            cout<<endl;

            int p;
            cout<<"Enter Priority (1: High, 2: Medium, 3: Low): ";
            cin>>p;
            cout<<endl;

            cout<<"Parcel "<<i<<" added successfully"<<endl;
            Parcels.add_parcel(i, s, r, w, p);
        }

        else if (ans==2){
            Parcels.dispatch_parcel();
        }

        else if (ans==3){
            Parcels.view_parcel();
        }

        else if (ans==4){
            Parcels.display_parcels();
        }

        else if (ans==5){
            Parcels.count_parcels();
        }

        else if (ans==6){
            int i;
            cout<<"Enter id you are looking for: "<<endl;
            cin>>i;
            cout<<endl;
            Parcels.search_parcel(i);
        }

        else if (ans==7){
            cout<<"Exiting the system..."<<endl;
            break;
        }

        else{
            cout<<"Kindly choose a valid option"<<endl;
        }
    }
}







