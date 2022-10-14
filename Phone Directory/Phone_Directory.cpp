#include <bits/stdc++.h>
using namespace std;

int validatePhoneNumber(string number);
bool isValid(string);
bool isValidName(string);

class dnode
{
public:
    string number;
    string gmail;
    string name;
    dnode *prev, *next;
    dnode(string n, string r, string g)
    {
        name = n;
        number = r;
        gmail = g;
        next = NULL;
        prev = NULL;
    }
};

class dlist
{
    dnode *head, *temp, *ptr;
    dnode *p1, *p2, *p;

public:
    dnode *prevn;

    void insert();
    void sort();
    void deletecontact(string n);
    void deletesamenumber();
    void deletesamename();
    void deletesamegmail();
    void searchbyname(string p);
    void searchbynumber(string no);
    void searchbygmail(string g);
    void accept();
    void display();
    void update(string ch);

    dlist()
    {
        head = NULL;
        temp = NULL;
        ptr = NULL;
        p1 = NULL;
        p2 = NULL;
        p = NULL;
    }
};

void dlist::accept()
{
    string number;
    string gmail;
    string name;
    char ans;
    do
    {
        cout << "Enter Name      : ";
        cin >> name;
        while (!isValidName(name))
        {
            cout << "Enter Valid Name  : ";
            cin >> name;
        }
        cout << "Enter Number    : ";
        cin >> number;
        while (!validatePhoneNumber(number))
        {
            cout << "Enter Valid Number  : ";
            cin >> number;
        }
        cout << "Enter G-Mail    : ";
        cin >> gmail;
        while (!isValid(gmail))
        {
            cout << "Enter Valid E-Mail   : ";
            cin >> gmail;
        }

        temp = new dnode(name, number, gmail);
        if (head == NULL)
        {
            head = temp;
        }
        else
        {
            ptr = head;
            while (ptr->next != NULL)
            {
                ptr = ptr->next;
            }
            ptr->next = temp;
            temp->prev = ptr;
        }
        cout << "Do You Want To Continue? (y/n) ";
        cin >> ans;
    } while (ans == 'y');
}
void dlist::display()
{
    ptr = head;         // start the node
    while (ptr != NULL) // traverse till last
    {
        cout << "\n\nName  ::\t" << ptr->name;
        cout << "\nNumber::\t+91-" << ptr->number;
        cout << "\nG-Mail::\t" << ptr->gmail;
        ptr = ptr->next;
    }
}
void dlist::insert()
{
    accept();
}
void dlist::sort()
{
    dnode *i, *j;
    int temp;
    string n;
    for (i = head; i->next != NULL; i = i->next)
    {
        for (j = i->next; j != NULL; j = j->next)
        {
            temp = (i->name).compare(j->name);
            if (temp > 0)
            {
                n = i->name;
                i->name = j->name;
                j->name = n;

                n = i->gmail;
                i->gmail = j->gmail;
                j->gmail = n;

                n = i->number;
                i->number = j->number;
                j->number = n;
            }
        }
    }
}
void dlist::deletecontact(string s)
{
    int c = 0;
    ptr = head;
    while (ptr != NULL)
    {
        if (s.compare(ptr->name) == 0)
        {
            c = 1;
            break;
        }
        else
        {
            c = 2;
        }
        ptr = ptr->next;
    }
    if (c == 1)
    {
        if (ptr != head && ptr->next != NULL)
        {
            ptr->prev->next = ptr->next;
            ptr->next->prev = ptr->prev;
            delete (ptr);
            cout << "Your Contact is Successfully Deleted\n\n";
        }
        if (ptr == head)
        {
            head = head->next;
            head->prev = NULL;
            delete (ptr);
            cout << "Your Contact is Successfully Deleted\n\n";
        }
        if (ptr->next == NULL)
        {
            ptr->prev->next = NULL;
            ptr->prev = NULL;
            delete (ptr);
            cout << "Your Contact is Successfully Deleted\n\n";
        }
    }
    else if (c == 2)
    {
        cout << "Your Entered Name is Not in The List...";
    }
    else
        cout << "Phone Book is Empty.";
}
void dlist::deletesamename()
{
    p1 = head;
    while (p1 != NULL && p1->next != NULL)
    {
        p2 = p1;
        while (p2->next != NULL)
        {
            if (p1->name.compare(p2->next->name) == 0)
            {
                p = p2->next;
                p2->next = p2->next->next;
                if (p->next)
                    p->next->prev = p2;
                delete (p);
            }
            else
                p2 = p2->next;
        }
        p1 = p1->next;
    }
}
void dlist::deletesamegmail()
{
    p1 = head;
    while (p1 != NULL && p1->next != NULL)
    {
        p2 = p1;
        while (p2->next != NULL)
        {
            if (p1->gmail.compare(p2->next->gmail) == 0)
            {
                p = p2->next;
                p2->next = p2->next->next;
                delete (p);
            }
            else
            {
                p2 = p2->next;
            }
        }
        p1 = p1->next;
    }
}
void dlist::deletesamenumber()
{
    p1 = head;
    while (p1 != NULL && p1->next != NULL)
    {
        p2 = p1;
        while (p2->next != NULL)
        {
            if (p1->number.compare(p2->next->number) == 0)
            {
                p = p2->next;
                p2->next = p2->next->next;
                if (p->next)
                    p->next->prev = p2;
                delete (p);
            }
            else
            {
                p2 = p2->next;
            }
        }
        p1 = p1->next;
    }
}
void dlist::searchbyname(string na)
{
    ptr = head;
    bool ch = false;
    while (ptr != NULL)
    {
        if (na.compare(ptr->name) == 0)
        {
            ch = true;
            cout << "Name Found" << endl;
            cout << "Contact Details Are Below:\n"
                 << endl;
            cout << "\n\nName  ::\t" << ptr->name;
            cout << "\nNumber::\t+91-" << ptr->number;
            cout << "\nG-Mail::\t" << ptr->gmail;
        }
        ptr = ptr->next;
    }
    if (!ch)
        cout << "Your Entered Name is Not in The List...";
}
void dlist::searchbynumber(string num)
{
    ptr = head;
    bool ch = false;
    while (ptr != NULL)
    {
        if (num.compare(ptr->number) == 0)
        {
            bool ch = false;
            cout << "Number Found\n"
                 << endl;
            cout << "Contact Details Are Below:\n"
                 << endl;
            cout << "\n\nName  ::\t" << ptr->name;
            cout << "\nNumber::\t+91-" << ptr->number;
            cout << "\nG-Mail::\t" << ptr->gmail;
        }
        ptr = ptr->next;
    }
    if (!ch)
        cout << "Your Entered Number is Not in The List...";
}
void dlist::searchbygmail(string gm)
{
    ptr = head;
    bool ch = false;
    while (ptr != NULL)
    {
        if (gm.compare(ptr->gmail) == 0)
        {
            ch = true;
            cout << "G-Mail Found\n"
                 << endl;
            cout << "Contact Details Are Below:\n"
                 << endl;
            cout << "\n\nName  ::\t" << ptr->name;
            cout << "\nNumber::\t+91-" << ptr->number;
            cout << "\nG-Mail::\t" << ptr->gmail;
        }
        ptr = ptr->next;
    }
    if (!ch)
        cout << "Your Entered Mail-ID is Not in The List...";
}
void dlist::update(string n)
{
    char ans;
    int c;
    bool ch = false;
    ptr = head;
    while (ptr != NULL)
    {
        if (n.compare(ptr->name) == 0)
        {
            ch = true;
            do
            {
                cout << "\nWhat Do You Want to Update?\n1.Name\n2.Phone Number\n3.G-Mail\n";
                cin >> c;
                switch (c)
                {
                case 1:
                    cout << "Enter New-Name : ";
                    cin >> ptr->name;
                    while (!isValidName(ptr->name))
                    {
                        cout << "Enter Valid Name : ";
                        cin >> ptr->name;
                    }
                    break;
                case 2:
                    cout << "Enter New Phone-Number?";
                    cin >> ptr->number;
                    while (!validatePhoneNumber(ptr->number))
                    {
                        cout << "Enter Valid Number :";
                        cin >> ptr->number;
                    }
                    break;
                case 3:
                    cout << "Enter New G-Mail";
                    cin >> ptr->gmail;
                    while (!isValid(ptr->gmail))
                    {
                        cout << "Enter Valid E-Mail   : ";
                        cin >> ptr->gmail;
                    }
                    break;
                }
                cout << "Do You Want to Continue Updating?";
                cin >> ans;
            } while (ans == 'y');
        }
        ptr = ptr->next;
    }
    if (!ch)
        cout << "Your Entered Name is Not in The List...\n";
}

int validatePhoneNumber(string num)
{
    if(num[0] == '0')
        return 0;
    if (num.length() != 10)
        return 0;
    for (int i = 0; i < 10; i++)
        if ((num[i] < '0' || num[i] > '9'))
            return 0;
    return 1;
}

bool isValidName(string name){
    
    for(int i=0; i<name.length(); i++){
        if(isalpha(name[i]))
            continue;
        else
            return false;
    }
    return true;
}

bool isValid(string email)
{
    int at = 0;
    int dot = 0;
    int cnt = 0;

    if (email[0] == '@')
        return 0;

    for (int i = 0; i < email.length(); i++)
    {
        if (email[i] == '@')
        {
            at = i;
            cnt++;
        }

        if (email[i] == '.')
            dot = i;
    }

    if (at == 0 || cnt > 1)
        return 0;

    return (dot - at > 1);
};

int main()
{
    system("cls");
    string n, name, number, gmail;
    dlist d1;
    char ans;
    int ch, a;
    cout << "\n\t\tPHONE BOOK";
    cout << "\n\nWhat is Your Name?\n";
    cin >> name;
    while (!isValidName(name))
    {
        cout << "Enter Valid Name : ";
        cin >> name;
    }
    cout << "\n\n!!!!!!!!!!!!!!!!!!!!!!!   Welcome " << name << "   !!!!!!!!!!!!!!!!!!!!!";
    cout << "\n\n\nLet's Create Our Phonebook " << name << "  \n\n";
    d1.accept();
    d1.sort();
    do
    {
        cout << "1) Display Your Phone Book" << endl;
        cout << "2) Insert New Contact" << endl;
        cout << "3) Update Details on Existing Contact" << endl;
        cout << "4) Delete Contact" << endl;
        cout << "5) Delete Same Name in Phonebook" << endl;
        cout << "6) Delete Same Number in Phonebook" << endl;
        cout << "7) Delete Same E-Mail in Phonebook" << endl;
        cout << "8) Search" << endl;
        cout << "9) Exit" << endl;

        cin >> ch;
        switch (ch)
        {
        case 1:
            d1.display();
            break;
        case 2:
            d1.insert();
            d1.sort();
            break;
        case 3:
            cout << "\n\nEnter The Name of Person Whose Details You Want to Update...\n";
            cin >> n;
            d1.update(n);
            d1.sort();
            break;
        case 4:
            cout << "\nEnter The Name You Want to Delete From Phonebook\n";
            cin >> name;
            d1.deletecontact(name);
            break;
        case 5:
            d1.deletesamename();
            d1.display();
            break;
        case 6:
            d1.deletesamenumber();
            d1.display();
            break;
        case 7:
            d1.deletesamegmail();
            d1.display();
            break;
        case 8:
            do
            {
                cout << "1.Search by Name\n";
                cout << "2.Search by Number\n";
                cout << "3.Search by Gmail\n";
                cin >> a;
                switch (a)
                {
                case 1:
                    cout << "Enter The Name to be Searched\n";
                    cin >> name;
                    d1.searchbyname(name);
                    break;
                case 2:
                    cout << "Enter The Number to be Searched\n";
                    cin >> number;
                    while (!validatePhoneNumber(number)){
                        cout << "Enter Valid Phone number";
                        cin >> number;
                    }
                        d1.searchbynumber(number);
                    break;
                case 3:
                    cout << "Enter The Mail Address to be Searched\n";
                    cin >> gmail;
                    while (!isValid(gmail))
                    {
                        cout << "Enter Valid E-Mail   : ";
                        cin >> gmail;
                    }
                    d1.searchbygmail(gmail);
                    break;
                default:
                    cout << "\nNo Proper Input Given.....\n";
                }
                cout << "Do You Want to Contunue Searching? ";
                cin >> ans;
            } while (ans == 'y');
            break;
        
        case 9:
            exit(0);
            
        default:
            cout << "\nNo Proper Input Given..\n";
        }
        cout << "\n\nDo You Want to Continue Operations? (Y/N) ";
        cin >> ans;
    } while (ans == 'y' || ans == 'Y');
    
    return 0;
}