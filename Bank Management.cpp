#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <cstdlib>
#include <conio.h>
#define ll long long
using namespace std;
//----------------------------------------------------------------------------------------
ll int i = 0;
//-------------------------------------------------------------------------------------------
string detail[10][4] = {"Nitesh", "Kumar", "nk", "nkp"}; // 0=fname,1=lname,2= userid,3=password
ll int tran[10][4] = {26022003, 7007943478, 0};          // Dob,Phone,number,amount,
ll int atm[10][3] = {1234, 88, 1000};                    // card,pin,limit
int input;

//--------------------------------------------------------------------------------------
void forget();
void withdraw();
void atmcard(ll int puser);
void money();
void dash(ll int puser);
void dash(ll int puser);
void db(ll int puser);
void create();
void dash(ll int puser);
void login();
void deactivate(ll int puser);
void cr(ll int puser);
void limit(ll int puser);
void buy(ll int puser);
void pass(ll int puser);
void logout();
void money(ll int puser);
void at();
void gpg();
void bal();
//================================================================================
//================================================================================
int main()
{
    ll int ch;
    do
    {
        system("CLS");
        system("Color 70");
        cout << "\tWelcome\t";
        cout << "\n|--------------------|\n|   1. login         |\n|   2. Create        |\n|   3. Forget        |\n|   4. ATM           |\n|   5. Exit          |\n> ";
        cin >> ch;
        cout << "|--------------------|\n";

        switch (ch)
        {
        case 1:
            login();
            break;
        case 2:
            create();
            break;
        case 3:
            forget();
            break;
        case 4:
            at();
            break;
        case 5:
            exit(0);
            break;
        default:
            cout << "\nChoose valid option: " << endl;
        }
    } while (ch != 5);
}
//================================================================================
//================================================================================
void login()
{

    string temp, temp1;
    ll int temp2, v, flag = 10, pflag = 10, puser;
    system("CLS");
    cout << "|--------------------|\n";
    cout << "> User id : ";
    cin >> temp;

    for (ll int m = 0; m < 10; m++)
    {
        ll int count = 1;
        if (temp == detail[m][2])
        {
            flag = 20;
            puser = m;
            pass(puser);
        }
        else if (m == 9 && flag != 20)
        {
            system("Color C0");
            cout << "\nNo, Such user found!\n\n";
            getch();
        }
    }
}
//================================================================================
void create()
{

    system("CLS");
    cout << "|--------------------|\n";
    i++;
    string fname, lname, id, pass;
    ll int dob, phone;
    cout << "  First name : ";
    cin >> fname;
    cout << "  Last name : ";
    cin >> lname;
    cout << "  Enter DOB (DDMMYYYY) : ";
    cin >> dob;
    cout << "  Enter phone : ";
    cin >> phone;
    ll int count = 0;
    do
    {
        count = 0;

        cout << "User Id (Unique) : ";
        cin >> id;
        for (ll int m = 0; m < 10; m++)
        {
            if (id == detail[m][2])
            {
                count = 1;
            }
        }

    } while (count != 0);

    cout << "Password : ";
    cin >> pass;

    detail[i][0] = fname;
    detail[i][1] = lname;
    detail[i][2] = id;
    detail[i][3] = pass;
    tran[i][0] = dob;
    tran[i][1] = phone;
    atm[i][0] = rand() % 8999 + 1000;
    atm[i][2] = 1000;

    system("CLS");
    system("Color 20");
    cout << "\n=======================================================================================\n";
    cout << "Account created succesfully\n";
    cout << "\nCustomer No. " << i << "  |  "
         << "Username : " << id << " |  Password : " << pass << " |  ATM : " << atm[i][0];
    cout << "\n=======================================================================================\n";
    getch();
    system("CLS");
    system("Color 0F");
}
//================================================================================
void forget()
{

    system("CLS");
    system("Color 75");
    string temp;
    ll int temp2;
    cout << "User id : ";
    cin >> temp;
    for (ll int m = 0; m < 10; m++)
    {
        if (temp == detail[m][2])
        {
            cout << "Dob (DDMMYYYY) : ";
            cin >> temp2;

            if (temp2 == tran[m][0])
            {
                cout << "\n___________________________________________"
                     << endl;

                cout << "Password : " << detail[m][3];
                cout << "\n___________________________________________"
                     << endl;
            }
        }
    }
}
//================================================================================
void dash(ll int puser)
{

    ll int dch;
    do
    {
        system("Color B0");
        system("CLS");
        cout << "Hi," << detail[puser][0] << "\t\t\tBal." << tran[puser][3] << endl;
        cout << "-------------------------------------------\n";

        cout << "  1. ATM \n  2. Add Money \n  3. Log out\n> ";
        cin >> dch;

        switch (dch)
        {
        case 1:
            atmcard(puser);
            break;
        case 2:
            money(puser);
            break;
        case 3:
            puser = -1;
            logout();
            break;
        default:
            cout << "Choose valid option: " << endl;
        }
    } while (dch != 3);
}
//================================================================================
void logout()
{

    ll int ch;
    do
    {
        system("CLS");
        system("Color 70");
        cout << "\tWelcome\t";
        cout << "\n|--------------------|\n|   1. login         |\n|   2. Create        |\n|   3. Forget        |\n|   4. ATM           |\n|   5. Exit          |\n> ";
        cin >> ch;
        cout << "|--------------------|\n";

        switch (ch)
        {
        case 1:
            login();
            break;
        case 2:
            create();
            break;
        case 3:
            forget();
            break;
        case 4:
            at();
            break;
        case 5:
            exit(0);
            break;
        default:
            cout << "\nChoose valid option: " << endl;
        }
    } while (ch != 5);
}

//================================================================================

void pass(ll int puser)
{

    string temp1, temp2;
    cout << "\nPassword : ";
    cin >> temp2;
    temp1 = temp2;
    if (temp1 == detail[puser][3])
    {
        cout << "\nLogged in" << endl;
        dash(puser);
    }
    else
    {
        system("Color 04");
        cout << "\nWrong Password....\n\nPress any key to cont...";
    }
    getch();
    system("CLS");
    system("Color 0F");
}

void atmcard(ll int puser)
{
    do
    {
        system("CLS");
        cout << "Hi, " << detail[puser][0] << "\t\tBal. " << tran[puser][3] << endl;
        cout << "________________________________________\n";

        cout << "  1. Limit\n  2. Deactivate\n  3. Back\n> ";
        cin >> input;
        switch (input)
        {
        case 1:
            limit(puser);
            break;
        case 2:
            deactivate(puser);
            break;
        case 3:
            dash(puser);
            break;
        case 4:
            exit(0);
            break;
        default:
            cout << "Invalid choose... ";
        }
    } while (input != 4);
}

void limit(ll int puser)
{
    system("CLS");
    cout << "Hi, " << detail[puser][0] << "\t\tCurrent Limit. " << atm[puser][2] << endl;
    cout << "________________________________________\n";
    cout << "  1. Set Limit\n  2. Back\n > ";
    cin >> input;
    if (input == 1)
    {
        cout << "New Limit: ";
        cin >> input;
        atm[puser][2] = input;
    }
    else if (input == 2)
    {
        atmcard(puser);
    }
}

void deactivate(ll int puser)
{
}

void money(ll int puser)
{

    ll int mch;
    do
    {
        system("CLS");
        cout << "Hi, " << detail[puser][0] << "\t\tBal. " << tran[puser][3] << endl;
        cout << "\n___________________________________________" << endl;

        cout << "\n1. Add Money( Credit ) \n2. Withdraw( Debit )\n3. Back  \n> ";
        cin >> mch;

        switch (mch)
        {
        case 1:
            system("CLS");
            cout << "Hi, " << detail[puser][0] << "\t\tBal. " << tran[puser][3] << endl;
            cout << "\n___________________________________________" << endl;
            cout << "Enter the Amount (Deposite): ";
            cin >> input;
            tran[puser][3] += input;
            cout << "  Transaction Completed";
            getch();
            break;
        case 2:
            system("CLS");
            cout << "Hi, " << detail[puser][0] << "\t\tBal. " << tran[puser][3] << endl;
            cout << "\n___________________________________________" << endl;
            cout << "Enter the Amount (Withdraw): ";
            cin >> input;
            if (tran[puser][3] >= input)
            {
                tran[puser][3] -= input;
                cout << "  Amount: " << input << "\n  Collect your Cash..";
                getch();
            }
            else
            {
                cout << "Insufficient Balance...\n  Press any key to cont. ";
                getch();
            }
            getch();
            break;
        case 3:
            dash(puser);
            break;
        default:
            cout << "Choose valid option: " << endl;
        }
    } while (mch != 3);
}

void at()
{
    ll int ch;
    do
    {
        system("CLS");
        system("Color 70");
        cout << "\tWelcome to ATM\t";
        cout << "\n|--------------------------|\n|   1. Withdraw            |\n|   2. Green Pin Genrate   |\n|   3. Balance             |\n|   4. Back                |\n> ";
        cin >> ch;
        cout << "|--------------------|\n";

        switch (ch)
        {
        case 1:
            withdraw();
            break;
        case 2:
            gpg();
            break;
        case 3:
            bal();
            break;

        case 4:
            logout();
            break;
        default:
            cout << "\nChoose valid option: " << endl;
        }
    } while (ch != 5);
}

void withdraw()
{
    int puser, count;
    system("CLS");
    system("Color 70");
    cout << "\tWelcome to ATM\t";
    cout << "\n|--------------------------|\n  Enter the card Number: ";
    cin >> input;
    for (int i = 0; i < 10; i++)
    {
        if (atm[i][0] == input)
        {
            puser = i;
            count = 1;
        }
    }
    if (count == 1)
    {
        cout << "  Enter the PIN: ";
        cin >> input;
        if (atm[puser][1] == input)
        {
            cout << "  Enter the Amount: ";
            cin >> input;
            if (tran[puser][3] >= input && input <= atm[puser][2])
            {
                cout << "  Collect your amount: " << input;
                tran[puser][3] -= input;

                getch();
            }
            else if (tran[puser][3] <= input)
            {
                cout << "  Insufficient Balance... \n  press any key to cont..";
                getch();
            }
            else
            {
                cout << "   Out of limit... ";
                getch();
            }
        }
        else
        {
            withdraw();
        }
    }

    cout << "|--------------------|\n";
}
void gpg()
{
    system("CLS");
    system("Color D0");
    cout << "\tWelcome to ATM\t";
    cout << "\nGreen PIN generate / PIN Change\t";
    cout << "\n|-----------------------------|\n  Enter the card Number: ";
    cin >> input;
    int puser;
    for (int i = 0; i < 10; i++)
    {
        if (atm[i][0] == input)
        {
            puser = i;
            cout << "\n  Enter the DOB: ";
            cin >> input;
            if (tran[puser][0] == input)
            {
                cout << "\n  Enter the New PIN: ";
                cin >> input;
                atm[puser][1] = input;

                system("Color 20");
                cout << "\n  PIN change Successfully...\n  Press any key to continue.. ";
                getch();
            }
        }
    }
}

void bal()
{
    int puser, count;
    system("CLS");
    system("Color 70");
    cout << "\tWelcome to ATM\t";
    cout << "\n|--------------------------|\n  Enter the card Number: ";
    cin >> input;
    for (int i = 0; i < 10; i++)
    {
        if (atm[i][0] == input)
        {
            puser = i;
            count = 1;
        }
    }
    if (count == 1)
    {
        cout << "  Enter the PIN: ";
        cin >> input;
        if (atm[puser][1] == input)
        {
            cout << "  Balance : " << tran[puser][3] << "\n  Press any key to cont... ";
            getch();
        }
        else
        {
            at();
        }
    }
}
