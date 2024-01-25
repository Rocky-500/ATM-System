#include<iostream>
#include<string>
#include<conio.h>
using namespace std;

class atm{
    private:
        long int accountNo;
        string name;
        int pin;
        double balance;
        string mobileNo;

    public:
        atm(long int accNo,string name,int pin,double bal,string mobNo):
           accountNo(accNo), name(name), pin(pin), balance(bal), mobileNo(mobNo) {}

        long int getAccountNo(){
            return accountNo;
        }
        string getName(){
            return name;
        }
        int getPin(){
            return pin;
        }
        double showBalance(){
            return balance;
        }
        string showMobileNo(){
            return mobileNo;
        }

        void updateMobileNo(string prevMobNo,string newMobNo){
            if(prevMobNo == mobileNo){
                mobileNo = newMobNo;
                cout<<endl<<"Successfully updated the mobile number."<<endl;
                _getch();   //it holds the screen, untill user press any key
            }
            else{
                cout<<"Invalid previous mobile number. Please Enter the correct previous mobile number"<<endl;
            }
        }

        void cashWithdrawl(int wAmount){
            if(wAmount>0 && wAmount<balance){
                balance -= wAmount;
                cout<<"Collect your cash !!"<<endl<<"Available balance: "<<balance<<endl;
                _getch();
            }
            else{
                cout<<"Insufficient balance or Invalid amount!"<<endl;
                _getch();
            }
        }

};

int main(){
    int choice = 0;
    long int accNo = 1234567890;
    double bal = 48000.0;
    string mobNo = "9834000111";
    int pin = 1111;

    system("cls");  //used to clear the screen
    atm user1(accNo,"Siddhant",pin,bal,mobNo);

    do{
        system("cls");

        cout<<"Welcome to SBI ATM"<<endl;
        cout<<"Enter account no: ";
        cin>>accNo;
        cout<<"Enter Pin: ";
        cin>>pin;

        if(accNo == user1.getAccountNo() && pin == user1.getPin()){
            do{
                int wAmount = 0;
                string newMobNo;
                system("cls");
                cout<<"Select option: "<<endl;
                cout<<"1. Check Balance"<<endl;
                cout<<"2. Cash Withdraw"<<endl;
                cout<<"3. Show Account details"<<endl;
                cout<<"4. Update Mobile No."<<endl;
                cout<<"5. Exit"<<endl;
                cin>>choice;

                switch(choice)
                {
                    case 1:
                        cout<<"Your account balance: "<<user1.showBalance()<<endl;
                        _getch();
                        break;

                    case 2:
                        cout<<"Enter amount: ";
                        cin>>wAmount;
                        user1.cashWithdrawl(wAmount);
                        _getch();
                        break;

                    case 3:
                        cout<<"User account details"<<endl;
                        cout<<"Account number: "<<user1.getAccountNo()<<endl;
                        cout<<"User Name: "<<user1.getName()<<endl;
                        cout<<"Balance: "<<user1.showBalance()<<endl;
                        cout<<"Mobile number: "<<user1.showMobileNo()<<endl;
                        _getch();
                        break;

                    case 4:
                        cout<<"Enter Old mobile number: ";
                        cin>>mobNo;
                        cout<<"Enter New mobile number: ";
                        cin>>newMobNo;

                        user1.updateMobileNo(mobNo,newMobNo);
                        _getch();
                        break;

                    case 5:
                        exit(0);
                        break;

                    default:
                        cout<<"Enter valid choice"<<endl;
                }
            }while(true);
        }
        else{
            cout<<"Enter correct details"<<endl;
            _getch();
        }
    }while(true);
}