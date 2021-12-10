#include <iostream>
#include <iomanip>
#include <vector>
#include <numeric>
#include <limits>
#include <conio.h>
using namespace std;

#include "airgeadBanking.h"

//Default constructor for private variables
BankingInfo::BankingInfo(){
    m_InitialDeposit = 0.0;
    m_MonthlyDeposit = 0.0;
    m_AnnualInterest = 0.0;
    m_NumberOfYrs = 0.0;
}

//Obtains the user input for intial deposit and passes it to m_InitialDeposit
void BankingInfo::setIntial(double f_initalVal){
    m_InitialDeposit = f_initalVal;
}

//Obtains input for monthly deposit and passes to m_MonthlyDeposit
void BankingInfo::setMonthly(double f_monthlyAdd){
    m_MonthlyDeposit = f_monthlyAdd;
}

//Obtains input for annual interest and passes to m_AnnualInterest
void BankingInfo::setAnnual(double f_annualInterestAdd){
    m_AnnualInterest = f_annualInterestAdd;
}

//Obtains input for number of years and passes to m_NumberOfYears
void BankingInfo::setYears(double f_years){
    m_NumberOfYrs = f_years;
}

//Will return value held by m_InitialDeposit
double BankingInfo::getIntial(){
    return m_InitialDeposit;
}

//Will return value held by m_MonthlyDeposit
double BankingInfo::getMonthly(){
    return m_MonthlyDeposit;
}

//Will return value held by m_AnnualInterest
double BankingInfo::getAnnual(){
    return m_AnnualInterest;
}

//Will return value held by m_NumberOfYrs
double BankingInfo::getYears(){
    return m_NumberOfYrs;
}


//This function calculates the annual balance and APY without monthly deposits into the account
void BankingInfo::noMonthlyDeposits(){
    double interest, balance, annualInterest;
    vector<double> interestContainer;

//Prints header for information
    cout << "    Balance and Interest Without Additional Monthly Deposits   \n";
    cout << setfill('=') << setw(65) << "=\n";
    cout << "Year" << "        Year End Balance        " << "Year End Earned Interest\n";
    cout << setfill('-') << setw(65) << "-\n";

//For loop will run once for every year defined by user
    for(int i = 0; i < getYears(); i++){
        
        //Will loop 12 times to account for a year
        //Will run 12 times for every year defined by the user
        for(int i = 0; i < 12; i++){
        
            //Calcs APY and annual balance without monthly deposits
            interest = getIntial() * ((getAnnual() / 100) / 12);
            balance = (getIntial() + interest);

            //Updates balance once for every month
            setIntial(balance);

            //Collects the monthly interest for 12 months
            interestContainer.push_back(interest);
            //All the interest collected over 12 months is added together and assigned to annualInterest
            annualInterest = accumulate(interestContainer.begin(), interestContainer.end(), 0.00);
        }

        //Prints information for user
        cout << fixed << setprecision(2) << setfill('0');
        //Will increment for number of years
        cout << setfill(' ') << setw(2) << i + 1;
        //prints closing balance for every year
        cout << setfill(' ') << setw(21) << "$" << balance;
        //prints the sum of monthly interest
        cout << setfill(' ') << setw(28) << "$" << annualInterest;
        cout << endl;

        //Clear the vector after each year for accurate annual interest info
        interestContainer.clear();
    }
}

//This function calcs user input with monthly deposits
void BankingInfo::monthlyDeposits(){
    double annualInterest, annualBalance, interest;
    vector<double> interestContainer;

    //Info header so the user knows what they are looking at
    cout << "\n    Balance and Interest With Additional Monthly Deposits   \n";
    cout << setfill('=') << setw(65) << "=\n";
    cout << "Year" << "        Year End Balance        " << "Year End Earned Interest\n";
    cout << setfill('-') << setw(65) << "-\n";

    //Will loop for number of years input by user
    for(int i = 0; i < getYears(); i++){

        //Loops 12 times for every year
        for(int i = 0; i < 12; i++){
        
            //Calcs interest of initial deposit plus a monthly deposit
            interest = (getIntial() + getMonthly()) * ((getAnnual() / 100) / 12);
            annualBalance = (getIntial() + getMonthly() + interest);

            //Update the initial balance for each month
            setIntial(annualBalance);

            //Collect the monthly interest on balance and monthly deposit
            interestContainer.push_back(interest);
            //Assign the sum of 12 months of interest to annualInterest
            annualInterest = accumulate(interestContainer.begin(), interestContainer.end(), 0.00);

        }
        
        //Will print the information for the user
        cout << fixed << setprecision(2) << setfill('0');
        cout << " " << i + 1;
        cout << setfill(' ') << setw(21) << "$" << annualBalance;
        cout << setfill(' ') << setw(23) << "$" << annualInterest;
        cout << endl;

        //Clear the annualInterest for accurate total interest over x years
        interestContainer.clear();
    }
}

//Display menu for user input
void BankingInfo::userInMenu(){
    double deposit, monthly, interest, years;
    bool keyPress = true;

    cout << setfill('*') << setw(34) << "*" << endl;
    cout << setfill('*') << setw(22) << " Data Input ";
    cout << setfill('*') << setw(12) << "*" << endl;

    //Will collect user input and assign it to setInitial for later call
    cout << "Initial Investment Amount: $";
    cin >> deposit;
    
    //Checks if user input is a character or a negative number
    //Will clear the character in and ask again
    //source: (A)
    while(cin.fail() || deposit < 0){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid entry. Please enter a number.\n";
        cout << "Initial Investment Amount: $";
        cin >> deposit;
    }

    //Passes user input to setInitial()
    setIntial(deposit);

    
    cout << "Monthly Deposit: $";
    cin >> monthly;

    //Checks if user input is a character or a negative number
    //Will clear the character in and ask again
    //source: (A)
    while(cin.fail() || monthly < 0){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid entry. Please enter a number.\n";
        cout << "Monthly Deposit: $";
        cin >> monthly;
    }

    //Input is passed to setMonthly()
    setMonthly(monthly);

    
    cout << "Annual Interest: %";
    cin >> interest;

    //Checks if user input is a character or a negative number
    //Will clear the character in and ask again
    //source: (A) 
    while(cin.fail() || interest < 0){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Please enter a number.\n";
        cout << "Annual Interest: %";
        cin >> interest;
    }

    //Input is passed to setAnnual()
    setAnnual(interest);

    
    cout << "Number of years: ";
    cin >> years;

    //Checks if user input is a character or a negative number
    //Will clear the character in and ask again
    //source: (A) 
    while(cin.fail() || years < 0){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Please enter a number.\n";
        cout << "Number of years: ";
        cin >> years;
    }

    //passes input to setYears
    setYears(years);

    //Waits for user keypress before displaying information
    cout << "Press any key to continue . . .\n\n";
    //source: (B) 
    keyPress = _getch();

    //Call to noMonthlyDeposits after a keypress is detected
    noMonthlyDeposits();

    //Resets the setters to user input after noMonthlyDeposits() runs
    setIntial(deposit);
    setMonthly(monthly);
    setAnnual(interest);
    setYears(years);
}


void userChoice(){

    BankingInfo user;
    bool Run = true;
    char userIn;

    while(Run){
        //Runs program whill Run is true
        user.userInMenu();
        user.monthlyDeposits();

        //After the program runs the user is asked if they want to input different values
        cout << "\nWould you like to try different values? (Y/y or N/n)\n";
        cin >> userIn;

        //Will run the program again if true
        if(userIn == 'y' || userIn == 'Y'){
            //runs again is above is true
            continue;
        }
        //Will end if true
        else if(userIn == 'n' || userIn == 'N'){
            cout << "Thank you.";
            //Run is set to false so the loop will not execute again
            Run = false;
            break;
        }
        
        //If the user input is not 'y''Y' or 'n''N' this loop starts
        while(userIn != 'y' || userIn != 'Y'){

            //Prompts user of bad input and asks for correct info
            cout << "Invalid input.\nPlease use Y/y or N/n\n";
            cin >> userIn;
            
            //When this condition is met the nested loop will break to run the parent loop
            if(userIn == 'Y' || userIn == 'y'){
                break;
            }

            //When this condition is true the program will end with a message
            if(userIn == 'n' || userIn == 'N'){
                cout << "Thank you.\n";
                Run = false;
                break;
            }
        }
    }
}

/* Sources of code looked up:
 *(A): How to catch invalid input in c++? (2013, October 31). Stack Overflow. Retrieved November 26, 2021, from https://stackoverflow.com/questions/19696442/how-to-catch-invalid-input-in-c
 *(B): Detecting pressed keys - C++ Forum. (2012, June 28). Cplusplus.Com. Retrieved November 26, 2021, from http://www.cplusplus.com/forum/general/74211/
*/