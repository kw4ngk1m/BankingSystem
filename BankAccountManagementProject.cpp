#include <iostream>
using namespace std;

void Menu();
void CreateAccount(); //Menu 1
void Deposit(); //Menu 2
void Withdrawl(); //Menu 3
void Info(); //Menu 4

struct Account //Storing Account Id, Account Number, Account Balance in a group called Account
{
    string AccId; //Acc Name
    int AccNum; //Acc Number
    int Balance; //Acc Balance
};

Account NumofAccounts[100]; //Array for Struct Account with a cap or 100 indices
int AmountofAccounts = 0; //Number of account created

int menu;

int main()
{
    while(true)
    {
        Menu();

        if(menu == 1)
            CreateAccount();
        else if(menu == 2)
            Deposit();
        else if(menu == 3)
            Withdrawl();
        else if(menu == 4)
            Info();
        else if(menu == 5)
        {
            cout<<"좋은 하루 되세요"<<endl;
            break;
        }
        else
            cout<<"없는 옵션입니다.\n";
    }
    return 0;
}

void Menu() //Menu screen
{
        cout<<"----- M E N U -----\n";
        cout<<"1. 계좌계설\n";
        cout<<"2. 입금\n";
        cout<<"3. 출금\n";
        cout<<"4. 계좌정보 전체 출력\n";
        cout<<"5. 프로그램 종료\n";
        cout<<"선택: ";
        cin>>menu;
        cout<<"\n";
}

void CreateAccount() //What the CreateAccount() will do
{
    cout<<"[계 좌 계 설]"<<endl;
    cout<<"이릅(Name): "; cin>>NumofAccounts[AmountofAccounts].AccId; // In array NumofAccounts, save the name in the AccId section
    cout<<"원하는 게좌번호: "; cin>>NumofAccounts[AmountofAccounts].AccNum; // In array NumofAccounts, save the account number and save it in the AccNum section
    cout<<"입금(First Deposit): "; cin>>NumofAccounts[AmountofAccounts].Balance; // In array NumofAccounts, save the Balance information in the Balance section

    cout<<"----- 계 설 완 료! -----"<<endl;
    AmountofAccounts++;
}

void Deposit()
{
    int Number;
    int DepositAmount;

    cout<<"입     금"<<endl; 
    for(int i=0; i<AmountofAccounts; i++) // By accessing to the array AmountofAccounts,
    {
        cout<<"계좌번호 입력: "; cin>>Number; 
        if(Number == NumofAccounts[i].AccNum) // Check if number written is in NUmofAccounts.AccNUm
        {
            cout<<"안녕하세요 "<<NumofAccounts[i].AccId<<"님!"<<endl; // If the number is the same, make it able to deposit
            cout<<"입금할 금액 쓰시요: "; cin>>DepositAmount;

            if(DepositAmount <= 0)
            {
                cout<<"입금 금액은 0원보다 커야 합니다."<<endl;
            }

            NumofAccounts[i].Balance += DepositAmount; // Add and save the new Balance into the array
            cout<<"현재 잔고: "<<NumofAccounts[i].Balance<<endl;
            return;
        }

        if(Number != NumofAccounts[AmountofAccounts].AccNum) // If the numbers dont match, make it so they have to keep trying
        {
            cout<<"없는 아이디 입니다. 다시 써주세요."<<endl; 
        }
    }
}

void Withdrawl() // Same idea as the Deposit function except now when the amount taken from the account is more than the amount left in the account the money will not be withdrawled
{
    int Number;
    int WithdrawlAmount;

    cout<<"출     금\n";
    {

    for(int i=0; i<AmountofAccounts; i++)
    {
        cout<<"계좌번호 입력: "; cin>>Number;
        if(Number == NumofAccounts[i].AccNum)
        {
            cout<<"안녕하세요 "<<NumofAccounts[i].AccId<<"님!"<<endl;
            cout<<"출금할 금액 쓰시요: "; cin>>WithdrawlAmount;

            if(WithdrawlAmount<= 0)
            {
                cout<<"입금 금액은 0원보다 커야 합니다."<<endl;
            }

            if (NumofAccounts[i].Balance - WithdrawlAmount < 0)
            {
                cout<<"계좌에 충분한 금액이 없습니다."<<endl;
            }
            else
            {
                NumofAccounts[i].Balance -= WithdrawlAmount;
                cout<<"현재 잔고: "<<NumofAccounts[i].Balance<<endl;
            }
            return;
        }

        if(Number != NumofAccounts[AmountofAccounts].AccNum)
        {
            cout<<"없는 아이디 입니다. 다시 써주세요."<<endl;
        }
    }
}
}

void Info()
{
    if(AmountofAccounts == 0) // If the amount of account is equal to zero then print that there is no existing account
    {
        cout<<"[등록된 계좌 없습니다]\n"<<endl;
        return;
    }

    cout<<"[전체 계좌 정보]"<<endl; // If there is, print all accounts' names, bank id and how much money they have
    for(int i=0; i<AmountofAccounts; i++)
    {
        cout<<"이름:"<<NumofAccounts[i].AccId<<" ";
        cout<<"계좌번호:"<<NumofAccounts[i].AccNum<<" ";
        cout<<"잔액:"<<NumofAccounts[i].Balance<<endl;
    }
}