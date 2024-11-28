#include <iostream>
#include <string.h>


using namespace std;
struct Employee {
    int id;
    char name[20];
};


int enQueue(Employee e);
Employee deQueue();
void printQueue();

void printEmployee(Employee e);
Employee fillEmployee();


Employee emp[10];
int toq;

using namespace std;
int main()
{
    cout<<"Welcome To Queue Using Array\n";
    int choice;
    int returnValue;
    Employee e;

    do{
        cout<<"**********************************\n";
        cout<<"Select Operations From Menu \n";
        cout<<"1- EnQueue\n2- DeQueue\n";
        cout<<"3- Print Queue\n4- Quit\n";
        cout<<"Enter Your Choice: \n";
        cin>>choice;

        switch(choice)
        {
            case 1:{
                        e = fillEmployee();
                        returnValue = enQueue(e);
                        if(returnValue == 1){
                            cout<<"Employee add successfully!\n";
                        }else
                        {
                             cout<<"Wrong action!\n";
                        }
                    }
            break;

            case 2: {
                        e = deQueue();
                        if(e.id == -1){
                            cout<<"Empty Queue \n";
                        }
                        else
                        {
                            printEmployee(e);
                        }
                    }
            break;

            case 3: printQueue();
            break;
            case 4: cout<<"Program End\n";
            break;
            default: cout<<"Enter Valid Number from 1 to 4 \n";

        }

    }while(choice != 4 );
    return 0;
}


int enQueue(Employee e)
{
    int isenQueued = 0;
    int empSize =10;
    if(toq >= 0  && toq <empSize)
    {
        emp[toq].id = e.id;
        strcpy(emp[toq].name, e.name);
        toq++;
        isenQueued = 1;
    }
    return isenQueued;

}

Employee deQueue()
{
    Employee temp;
    if(toq >=0){
        temp = emp[0];

        for(int i = 0; i< toq  ;i++)
        {
            emp[i] = emp[i+1];
        }
        toq--;
    }else{
        temp.id = -1;
    }
    return temp;
}

void printQueue(){
    for(int i = 0; i<toq ; i++)
    {
        cout<< "EMP ID : "<<emp[i].id<<" Emp Name : "<<emp[i].name<<endl;
    }

}

void printEmployee(Employee e){
    if(emp){
        cout<<"Employee Id: " << e.id<<endl;
        cout<<"Employee Name: "<<e.name<<endl;
    }
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
