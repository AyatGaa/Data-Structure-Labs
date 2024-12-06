#include <iostream>
#include <string.h>


using namespace std;
struct Employee {
    int id;
    char name[20];
};

void mergeSortById(Employee *emp, int low, int high);
void mereg(Employee *emp, int low, int mid, int high);

void bubbleSortByName(Employee *emp, int empSize);

int searchByEmployeeID(Employee *emp, int low, int high, int value);
int searchByEmployeeName(Employee *emp, int low, int high, char value []);

void printAllEmployee(Employee *emp, int empSize);
void printEmployee(Employee *e, int indx);
Employee fillEmployee();


int main()
{
 cout<<"Welcome To Employee Linked List\n";
    int choice;

    Employee e[5];
    int empSize = 5;
    int index;
    int id;

    do
    {
        cout<<"**********************************\n";
        cout<<"Select Operations From Menu \n";
        cout<<"1- Fill Employee\n2- Sort By Employee Id\n";
        cout<<"3- Sort By Employee Name\n4- Search by Employee Id\n";
        cout<<"5- Search by Employee Name\n6- Print Employee List\n";
        cout<<"7- Quit\n";
        cout<<"Enter Your Choice: \n";
        cin>>choice;

        switch(choice)
        {
            case 1:
                    {
                        for (int i = 0 ; i<empSize; i++)
                        {
                            e[i] = fillEmployee();
                        }
                    }
            break;

            case 2:
                    {
                        mergeSortById(e, 0,4 );
                        cout<<"Merge Sort Done\n" ;
                    }
            break;

            case 3:     bubbleSortByName(e, 5);
                        cout<<"Bubble Sort Done\n" ;
            break;

            case 4:{
                        cout<<"Enter Employee Id: \n";
                        cin>>id;
                        index = searchByEmployeeID( e, 0,4,id);

                        printEmployee(e, index);
                      }
            break;

            case 5:
                    {
                        cout<<"Enter Employee Name: \n";
                        char name[20];
                        cin>>name;
                        index = searchByEmployeeName(e,0,4,name);


                        printEmployee(e, index);
                    }
            break;

            case 6: printAllEmployee( e, empSize);
            break;

            case 7: cout<<"Program End\n";
            break;

            default: cout<<"Enter Valid Number from 1 to 7 \n";

        }

    }while(choice != 7);


      return 0;
}


void mergeSortById(Employee *emp, int low, int high)
{
    int mid;
    if(high > low)
    {
        mid = (low + high )/2;
        mergeSortById(emp, low, mid);
        mergeSortById(emp, mid+1, high);
        mereg(emp,low, mid, high);

    }

}



void mereg(Employee *emp, int low, int mid, int high)
{
    Employee temp[5];
    int i ,list1, list2;
    i = low ; list1 = low;
    list2 = mid + 1;

    while(list1<= mid && list2<= high)
    {
        if(emp[list1].id < emp[list2].id)
        {
            temp[i] = emp[list1];
            i++; list1++;
        }
        else
        {
            temp[i] = emp[list2];
            i++; list2++;
        }

    }
     while(list1<=mid) // rest element of any lsit
        {
            temp[i] = emp[list1];
            i++; list1++;
        }
          while(list2<=high)
        {
            temp[i] = emp[list2];
            i++; list2++;
        }
    for(int i = low ; i<= high ; i++)
    {
        emp[i] = temp[i];
    }


}
void bubbleSortByName(Employee *emp, int empSize){
    int i, j;
    Employee temp;
    for(i = 0 ; i<empSize-1 ; i++)
    {

        for(j = 0 ; j<empSize-1-i; j++)
        {
            int cmpValue = strcmp(emp[j].name, emp[j+1].name);
            if(cmpValue > 0) // +ve = s1 > s2
            {
             // swap(emp[j], emp[j+1]);
                temp = emp[j];
                emp[j] = emp[j+1];
                emp[j+1] = temp;

            }
        }
    }
}

int searchByEmployeeID(Employee *emp, int low, int high, int value)
{
    int index = -1;
    int mid;

    while(low <= high && index == -1)
    {

        mid = (low + high) /2;
        if(emp[mid].id == value)
        {
            index = mid ;
        }else if (emp[mid].id > value)
        {
            high = mid - 1 ;
        }else
        {
            low = mid + 1 ;
        }
    }
        return index;
}

int searchByEmployeeName(Employee *emp, int low, int high, char value [])
{

    int index = -1;
    int mid;

    while(low <= high && index == -1)
    {

        mid = (low + high) /2;
        int cmpValue = strcmp(emp[mid].name, value);
        if(cmpValue == 0)
        {
            index = mid ;

        }
        else if (cmpValue > 0)
        {
            high = mid - 1 ;
        }else
        {
            low = mid + 1 ;
        }
    }
        return index;
}


void printAllEmployee(Employee *emp, int empSize){

    for(int i = 0 ; i< empSize ;i++)
    {
        cout<<emp[i].id<<" "<<emp[i].name<<endl;
    }

}



void printEmployee(Employee *e, int indx){
    cout<<e[indx].id<<" "<<e[indx].name<<endl;
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
