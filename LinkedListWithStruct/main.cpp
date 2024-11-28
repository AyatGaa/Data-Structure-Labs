#include <iostream>
#include <string.h>

using namespace std;

struct Employee {
    int id;
    char name[20];
};

struct Node {
    Employee emp;
    Node* next;
    Node* previous;

};

    Node* createNode(Employee e);
    int addEmployee(Employee e);
    void freeList();
    Node* searchEmployeeById(int id);
    Node* searchEmployeeByName(char name[20]);
    int insertEmployee(Employee e, int index);
    void printAllEmployee();


Node* head;
Node* tail;


void printEmployee(Employee e);
Employee fillEmployee();

int main()
{
    cout<<"Welcome To Employee Linked List\n";
    int choice;

        Employee e;
        Node* n;
    do{
        cout<<"**********************************\n";
        cout<<"Select Operations From Menu \n";
        cout<<"1- Add Employee \n 2- Insert Employee\n";
        cout<<"3- Print Employees \n 4- Search by Employee Id\n";
        cout<<"5- Search by Employee Name \n 6- Free Employee List\n";
        cout<<"7- Delete Employee\n";
        cout<<"8- Quit\n";
        cout<<"**********************************\n";
        cout<<"Enter Your Choice: \n";
        cin>>choice;

        switch(choice)
        {
            case 1: e = fillEmployee();
                    addEmployee(e);
            break;

            case 2: e = fillEmployee();
                    cout<<"Enter Index to be inserted in: \n";
                    int idx;
                    cin>>idx;
                    insertEmployee(e,idx );
            break;

            case 3: printAllEmployee();
            break;

            case 4:{ cout<<"Enter Employee Id: \n";
                    int id;
                    cin>>id;
                        n = searchEmployeeById(id);
                        printEmployee(n->emp);
                    }
            break;
            case 5:{cout<<"Enter Employee Name: \n";
                    char name[20];
                    cin>>name;
                    n = searchEmployeeByName(name);
                    printEmployee(n->emp);
                   // cout<<n->emp.name<<"=> name"<<endl;
                    }
            break;
            case 6: freeList();
            break;
            case 7: cout<<"Program End\n";
            break;
            default: cout<<"Enter Valid Number from 1 to 7 \n";

        }

    }while(choice != 7);

    return 0;
}


Node* createNode(Employee e){
    Node* ptr;
    ptr = new (Node);

    if(ptr != NULL){
        ptr->emp.id = e.id;
        strcpy(ptr->emp.name, e.name);

        ptr->previous = NULL;
        ptr->next = NULL;
    }
    return ptr;
}


int addEmployee(Employee e){
    int added = 0;
    Node* ptr;
    ptr = createNode(e);
    if(ptr)
    {
        added = 1;
        if(head == NULL)
        {
            head = tail = ptr;
        }else
        {
            tail->next = ptr;
            ptr->previous = tail;
            tail = ptr;
        }
    }
    if(added == 1)
    {
        cout<<"Employee Added\n";
    }else
    {
        cout<<"Employee NOT Added!\n";
    }
    return added;
}

void freeList(){
    Node* ptr;
    if(head == NULL)
    {
        cout<<"List Already Empty !\n";

    }
    else
    {
        while(head != NULL)
        {
            ptr = head;
            head = head->next;
            delete (ptr);
        }

        tail = NULL;
        cout<<"List Cleared Successfully !\n";
    }
}


Node* searchEmployeeById(int id){
    Node* ptr;
    ptr = head;
    if(head == NULL)
    {
        cout<<"Empty List, NO Employee to Search \n";
    }
    else{
        while( ptr != NULL && ptr->emp.id != id )
        {
            ptr = ptr->next;
        }
    }
    if(ptr == NULL){
            cout<<"NOT Found!!\n";
        }
    return ptr;
}

Node* searchEmployeeByName(char name[20]){
    Node* ptr;
    ptr = head;
    if(head == NULL)
    {
        cout<<"Empty List, NO Employee to Search \n";
    }
    else
    {
        while( ptr != NULL && strcmp(ptr->emp.name, name) != 0 )
        {
            ptr = ptr->next;
        }
        //ptr = ptr->next;
        if(ptr == NULL){
            cout<<"NOT Found !\n";
        }
    }
    return ptr;
}

int insertEmployee(Employee e, int index){

    int added = 0;
    Node* temp;
    Node* ptr;
    ptr = createNode(e);
    if(ptr)
    {
        added = 1;
        if(head == NULL) // insert for first time
        {
            head = tail = ptr;
        }else // list is exist already
        {
            if(index == 0) //insert at first
            {
                ptr->next = head;
                head->previous = ptr;
                head = ptr;
            }else //mid or last node
            {
                temp = head;
                for (int i = 0; i<index-1 && temp != NULL ; i++)
                {
                    temp = temp->next;
                }

                if(temp == tail || temp == NULL) // last element
                {
                    tail-> next = ptr;
                    ptr->previous = tail;
                    tail = ptr;
                }else // middle node
                {
                    ptr->next = temp->next; //1 ptr->next = temp->next
                    (temp->next) ->previous = ptr; //2
                    temp->next = ptr;
                    ptr->previous = temp;

                }
            }
        }

    }

     if(added == 1)
    {
        cout<<"Employee Inserted \n";
    }else
    {
        cout<<"Employee NOT Inserted!\n";
    }
    return added;
}
void printAllEmployee(){
    Node* ptr;
    ptr = head;

    if(head == NULL)
    {
        cout<<"Empty List, NO Employee to show \n";
    }else
    {
        while(ptr != NULL )
        {
            cout<<"Employee Name: "<<ptr->emp.name <<" " <<"Employee id: "<<ptr->emp.id<<endl;
            ptr= ptr->next;
        }

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
