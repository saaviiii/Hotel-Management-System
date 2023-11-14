#include<iostream>
using namespace std;
class Hotel
{
private:
    struct Node
    {
        int id,date;
        string name, roomtype;
        Node*next;
    };
    
public:
    Node* head = NULL;
    void insert();
    void menu();
    void update();
    void search();
    void del();
    void sort();
    void show();
};

void Hotel::menu()
{
    int choice;
    cout<<"\n";
    cout<<"\tWelcome to Hotel Management System Application\n"<< endl;
    cout<<"\n\t_______Hotel Management System______";
    cout<<"\n\nS.no      Functions                Description"<< endl;
    cout<<"\n1\tAllocate Rooms\t\t\tInsert New Room";
    cout<<"\n2\tSearch Room\t\t\tSearch Room with RoomID";
    cout<<"\n3\tUpdate Room\t\t\tUpdate Room Record";
    cout<<"\n4\tDelete Room\t\t\tDelete Room with RoomID";
    cout<<"\n5\tShow Room Records\t\t\tShow Room Records that we added";
    cout<<"\n6\tExit"<<endl;


    cout<<"Enter Your Choice"<< endl;
    cin>>choice;
    switch (choice)
    {
    case 1:
        insert();
        menu();
        break;
    case 2:
        search();
        menu();
        break;   
    case 3:
        update();
        menu();
        break;  
    case 4:
        del();
        menu();
        break;    
    case 5:
        sort();
        show();
        menu();
        default:

        cout<<"Invalid Choice";
    }
    

}

void Hotel::insert()
{
    cout<<"\n\tHotel Management System"<<endl;
    Node* new_Node = new Node;
    cout<<"Enter RoomID "<<endl;
    cin>>new_Node->id;
    cout<<"Enter Customer Name "<<endl;
    cin>>new_Node->name;
    cout<<"Enter Allocted Date "<<endl;
    cin>>new_Node->date;
    cout<<"Enter Room Type(Single/Double/Twin) "<<endl;
    cin>>new_Node->roomtype;

    if (head== NULL)
    {
        head = new_Node;
    }
    else
    {
        Node* ptr= head;
        while(ptr->next != NULL){
            ptr= ptr->next;
        }
        ptr->next = new_Node;
    }
    cout<<"\n\n\t\t New Room Inserted";
    

}
void Hotel::search()
{
    cout<<"\n\t______Hotel Management System"; 
    int t_id;
   
    if (head== NULL)
    {
        cout<<"\n\n Linked List is empty";
    }
    else
    {
        cout<<"\n\nRoomID";
        cin>> t_id;
        Node* ptr = head;
        while(ptr!= NULL)
        {
            if(t_id==ptr->id)
            {
                cout<<"\n\n RoomID"<<ptr->id;
                cout<<"\n\n Customer Name"<<ptr->name;
                cout<<"\n\n Allocated Date"<<ptr->date;
                cout<<"\n\n Room Type"<<ptr->roomtype;
            }
            ptr = ptr->next;
        }
    }
}

void Hotel::update()
{
    cout<<"\n\tHotel Management System"; 
    int t_id;
   
    if (head== NULL)
    {
        cout<<"\n\n Linked List is empty";
    }
    else
    {
        cout<<"\n\n RoomID";
        cin>>t_id;
        Node*ptr = head;
        while(ptr!=NULL)
        {
            if(t_id==ptr->id)
            {
                cout<<"\n\n RoomID";
                cin>>ptr->id;
                cout<<"\n\n Customer Name";
                cin>>ptr->name;
                cout<<"\n\n Allocated Date";
                cin>>ptr->date;
                cout<<"\n\n Room Type";
                cin>>ptr->roomtype;

                cout<<"\n\n\t\t Updated Record Succesfully";
            }
            ptr = ptr->next;
        }
    }
}

void Hotel::del()
{
    cout<<"\n\t______Hotel Management System"; 
    int t_id;
   
    if (head== NULL)
    {
        cout<<"\n\n Linked List is empty";
    }
    else
    {
        cout<<"\n\n RoomID";
        cin>>t_id;
        if(t_id == head->id)
        {
            Node*ptr = head;
            head = head->next;
            delete ptr;
            cout<<"Deleted Room Record Successfully";
        }
        else
        {
            Node* pre = head;
            Node* ptr = head;
            while(ptr!=NULL)
            {
                if(t_id == ptr->id)
                {
                    pre->next = ptr->next;
                    delete ptr;
                    cout<<"Deleted Room Record Successfully";
                    break;
                }
                pre = ptr;
                ptr = ptr->next;
            } 
        }
    }    
} 
void Hotel::show()   
{
    Node* ptr= head;
    while(ptr!=NULL){
        cout<<"\n\nRoomID"<<ptr->id;
        cout<<"\n\nCustomer Nme"<<ptr->name;
        cout<<"\n\nAllocated Date"<<ptr->date;
        cout<<"\n\nRoom Type"<<ptr->roomtype;
        ptr = ptr->next;

    }
}
void Hotel::sort()
{
    if(head == NULL)
    {
        cout<<"\n\n Linked List is Empty";
        menu();
    }
    int count = 0, t_date,t_id;
    string t_name , t_roomtype;
    Node*ptr = head;
    while(ptr!= NULL)
    {
        count++;
        ptr = ptr->next;
    }
    for(int i=0;i<= count;i++)
    {
        Node*ptr = head;
        for(int j=1;j<count;j++)
        {
            if(ptr->id > ptr->next->id)
            {
                t_id = ptr->id;
                t_name = ptr->name;
                t_date = ptr->date;
                t_roomtype = ptr->roomtype;
                // Save Date into current node
                ptr->id = ptr->next->id;
                ptr->name = ptr->next->name;
                ptr->date = ptr->next->date;
                ptr->roomtype = ptr->next->roomtype;

                // save date into next node
                ptr->next->id = t_id;
                ptr->next->name = t_name;
                ptr->next->date = t_date;
                ptr->next->roomtype = t_roomtype;
            }
            ptr = ptr->next;
        }
    }
} 

int main(){
    Hotel h;
    h.menu();
}