/*
  Made by Sean Christian Lozana
*/

// Dependency Imports
#include <iostream>
#include "Lender.hpp"

/*
  Global Variables
  Do note that they're bad practice in general
  Read here why:
  https://www.tutorialspoint.com/why-are-global-variables-bad-in-c-cplusplus
*/
Lending Corporation;

// Starting function that is responsilbe for housing the main user interface of the program
void Start(){
  int Choice;
  bool mainSession = true;
  while(mainSession){
    std::cout<<"<=======================================>\n";
    std::cout<<"<      Loan Amortization Program        >\n";
    std::cout<<"<      Made by: Sean Christian Lozana   >\n";
    std::cout<<"<      <1> Client Options               >\n";
    std::cout<<"<      <2> Lender Options               >\n";
    std::cout<<"<      <3> Exit                         >\n";
    std::cout<<"<=======================================>\n";
    std::cout<<" < CHOICE > ";std::cin>>Choice;
    switch(Choice){
      case 1: {
        clear();
        int Choice;
        bool clientSession = true;
        while(clientSession){
          std::cout<<"<=======================================>\n";
          std::cout<<"<      Client Options                   >\n";
          std::cout<<"<      <1> Register                     >\n";
          std::cout<<"<      <2> Login                        >\n";
          std::cout<<"<      <3> Exit                         >\n";
          std::cout<<"<=======================================>\n";
          std::cout<<" < CHOICE > ";std::cin>>Choice;
          switch (Choice) {
            case 1: {
              clear();
              int Id, MonthsToPay, ChoiceMTP;
              double Amount;
              string Fullname, Username, LoanType, Password;
              std::cout<<"<=======================================>\n";
              std::cout<<"<         Client Registration           >\n";
              std::cout<<"<=======================================>\n";
              std::cout<<" < Id > ";std::cin>>Id;
              std::cout<<" < Fullname > ";std::cin>>Fullname;
              std::cout<<" < Username > ";std::cin>>Username;
              std::cout<<" < Password > ";std::cin>>Password;
              clear();
              std::cout<<"<=======================================>\n";
              std::cout<<"<        Loan Registration Form         >\n";
              std::cout<<"<=======================================>\n";
              std::cout<< "<Types of Loan> \n < Education > \n < House > \n < Salary >\n";
              std::cout<<" < Type > ";std::cin>>LoanType;
              clear();
              std::cout<<" < How much do you want to Loan > ";std::cin>>Amount;
              clear();
              std::cout<< "<Monthly Plan> \n 1 - < 18mos > \n 2 - < 12mos > \n 3 - < 6mos >\n";
              std::cout<<" < How long are you willing to pay off the loan in Months > ";std::cin>>ChoiceMTP;
              switch(ChoiceMTP){
                case 1: {
                  MonthsToPay = 18;
                  break;
                }
                case 2: {
                  MonthsToPay = 12;
                  break;
                }
                case 3: {
                  MonthsToPay = 6;
                  break;
                }
                default:
                  MonthsToPay = 18;
                  break;
              }
              Corporation.ClientRegistration(Id, MonthsToPay, Amount, LoanType, Fullname, Username, Password);
              break;
            }
            case 2: {
              string Username, Password;
              std::cout<<"<======================================>\n";
              std::cout<<"<              Client Login            >\n";
              std::cout<<"<======================================>\n";
              std::cout<<" < Username > ";std::cin>>Username;
              std::cout<<" < Password >";std::cin>>Password;
              Corporation.ClientLogin(Username, Password);
              clear();
              break;
            }
            case 3: {
              clientSession = false;
              break;
            }
            default:
              break;
          }

        }
        break;
      }
      case 2: {
        clear();
        int Choice;
        bool lenderSession = true;
        while(lenderSession){
          std::cout<<"<=======================================>\n";
          std::cout<<"<      Lender Options                   >\n";
          std::cout<<"<      <1> Register                     >\n";
          std::cout<<"<      <2> Login                        >\n";
          std::cout<<"<      <3> Check List                   >\n";
          std::cout<<"<      <4> Exit                         >\n";
          std::cout<<"<=======================================>\n";
          std::cout<<" < CHOICE > ";std::cin>>Choice;
          switch (Choice) {
            case 1: {
              clear();
              int Id;
              string Username, Password;
              std::cout<<"<=======================================>\n";
              std::cout<<"<         Lender Registration           >\n";
              std::cout<<"<=======================================>\n";
              std::cout<<" < Id > ";std::cin>>Id;
              std::cout<<" < Username > ";std::cin>>Username;
              std::cout<<" < Password > ";std::cin>>Password;
              Corporation.LenderRegistration(Id, Username, Password);
              break;
            }
            case 2: {
              clear();
              string Username, Password;
              std::cout<<"<======================================>\n";
              std::cout<<"<              Lender Login            >\n";
              std::cout<<"<======================================>\n";
              std::cout<<" < Username > ";std::cin>>Username;
              std::cout<<" < Password > ";std::cin>>Password;
              Corporation.Login(Username, Password);

              break;
            }
            case 3: {
              break;
            }
            case 4: {
              lenderSession = false;
              break;
            }
            default:
              break;
          }
        }
        break;
      }
      case 3: {
        mainSession = false;
        break;
      }
      default:
        break;
    }
  }
}

// Main driver utility function
int main(){
  Start();
  return 0;
}
