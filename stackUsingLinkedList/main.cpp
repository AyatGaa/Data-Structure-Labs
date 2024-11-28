#include <iostream>
#include <string.h>


using namespace std;
struct Employee {
    int id;
    char name[20];
};

struct Node {
    Employee emp;
    Node* previous;

};
Node* tail;

Node* createNode(Employee e);
int push(Employee e);
Employee pop();
void printstack();

void printEmployee(Employee e);
Employee fillEmployee();


int main()
{
    cout<<"Welcome To Stack Using Linked List\n";
    int choice;
    int returnValue;
    Employee e;
    Node* n;
    do{
        cout<<"**********************************\n";
        cout<<"Select Operations From Menu \n";
        cout<<"1- Push\n2- Pop\n";
        cout<<"3- Print Stack\n4- Quit\n";
        cout<<"Enter Your Choice: \n";
        cin>>choice;

        switch(choice)
        {
            case 1:{
                        e = fillEmployee();
                        returnValue = push(e);
                        if(returnValue == 1){
                            cout<<"Employee add successfully!\n";
                        }else
                        {
                             cout<<"Wrong action!\n";
                        }
                    }
            break;

            case 2: e = pop();
                    printEmployee(e);
            break;

            case 3: printstack();
            break;
            case 4: cout<<"Program End\n";
            break;
            default: cout<<"Enter Valid Number from 1 to 4 \n";

        }

    }while(choice != 4 );

    return 0;
}


Node* createNode(Employee e){
    Node* ptr;
    ptr = new (Node);

    if(ptr != NULL){
        ptr->emp.id = e.id;
        strcpy(ptr->emp.name, e.name);

        ptr->previous = NULL;
    }
    return ptr;
}

int push(Employee e){
    Node* ptr;
    int isPushed = 0;
    ptr  =createNode(e);
    if(ptr)
    {
        isPushed = 1;
        if(tail == NULL)  //first node
        {
            tail = ptr;
            ptr->previous = NULL;

        }else //not last element
        {
            ptr->previous = tail;
            tail = ptr;
        }
    }
    return isPushed;
}
Employee pop(){
    Employee temp;
    Node* ptr;
    ptr = tail;
    if(ptr)
    {
        temp = ptr->emp;

        if(tail->previous == NULL) //one element in stack
        {
            tail =NULL;
            delete(ptr);

        }else // more than one element
        {
            tail = tail->previous;
            ptr->previous = NULL;
            delete(ptr);
        }
            if(tail == NULL)
            {
                cout<<"Empty Stack\n";
            }
    }
    return temp;
}
void printstack(){
   Node* ptr;
   ptr = tail;
   int  i = 0;
   while(ptr != NULL){
    cout<<"NODE : "<<i;
    cout<<" => Employee NAME :"<<ptr->emp.name<<"  Employee ID :"<<ptr->emp.id<<endl;
    ptr = ptr->previous;
    i++;
   }
}

void printEmployee(Employee e){
    cout<<"Employee Id: " << e.id<<endl;
    cout<<"Employee Name: "<<e.name<<endl;
}

Employee fillEmployee(){
    Employee e;
    int i,g;
    char n[20];
    cout<<"Enter Employee Id: ";
    cin>>i;
    e.id = i;
    cout<<"Enter Employee Name: ";
    cin>>n;
    strcpy(e.name, n);

    return e;
}
