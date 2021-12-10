#ifndef AIRGEADBANKING_PROJECTS_AIRGEADBANKINGPROJECT2_H_
#define AIRGEADBANKING_PROJECTS_AIRGEADBANKINGPROJECT2_H_


#include <string>

using namespace std;

//The class is declared
class BankingInfo{
    //All public functions are declared
    public:
        BankingInfo();
        void setIntial(double f_initialVal);
        void setMonthly(double f_monthlyAdd);
        void setAnnual(double f_annualInterestAdd);
        void setYears(double f_years);
        double getIntial();
        double getMonthly();
        double getAnnual();
        double getYears();
        void userInMenu();
        void noMonthlyDeposits();
        void monthlyDeposits();
    private:
        //All private variables are declared
        double m_InitialDeposit;
        double m_MonthlyDeposit;
        double m_AnnualInterest;
        double m_NumberOfYrs;
};

#endif