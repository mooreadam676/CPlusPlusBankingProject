#include "InvestmentAccount.h"
#include <iostream>
#include <iomanip>
#include <stdexcept>

using namespace std;

InvestmentAccount::InvestmentAccount()
    : m_initialInvestment(0.0),
    m_monthlyDeposit(0.0),
    m_annualInterest(0.0),
    m_numberOfYears(0) {
}

InvestmentAccount::InvestmentAccount(double t_initialInvestment,
    double t_monthlyDeposit,
    double t_annualInterest,
    int t_numberOfYears)
    : m_initialInvestment(0.0),
    m_monthlyDeposit(0.0),
    m_annualInterest(0.0),
    m_numberOfYears(0) {
    setInitialInvestment(t_initialInvestment);
    setMonthlyDeposit(t_monthlyDeposit);
    setAnnualInterest(t_annualInterest);
    setNumberOfYears(t_numberOfYears);
}

void InvestmentAccount::setInitialInvestment(double t_initialInvestment) {
    if (t_initialInvestment < 0.0) {
        throw invalid_argument("Initial investment must be a positive value.");
    }
    m_initialInvestment = t_initialInvestment;
}

void InvestmentAccount::setMonthlyDeposit(double t_monthlyDeposit) {
    if (t_monthlyDeposit < 0.0) {
        throw invalid_argument("Monthly deposit must be a positive value or zero.");
    }
    m_monthlyDeposit = t_monthlyDeposit;
}

void InvestmentAccount::setAnnualInterest(double t_annualInterest) {
    if (t_annualInterest < 0.0) {
        throw invalid_argument("Annual interest rate must be a positive value or zero.");
    }
    m_annualInterest = t_annualInterest;
}

void InvestmentAccount::setNumberOfYears(int t_numberOfYears) {
    if (t_numberOfYears <= 0) {
        throw invalid_argument("Number of years must be greater than zero.");
    }
    m_numberOfYears = t_numberOfYears;
}

void InvestmentAccount::printReportWithoutMonthlyDeposits() const {
    cout << "Balance and Interest Without Additional Monthly Deposits" << endl;
    cout << "=======================================================" << endl;
    cout << left << setw(10) << "Year"
        << setw(20) << "Year End Balance"
        << setw(25) << "Year End Earned Interest" << endl;
    cout << "-------------------------------------------------------" << endl;

    printReport(false);
    cout << endl;
}

void InvestmentAccount::printReportWithMonthlyDeposits() const {
    cout << "Balance and Interest With Additional Monthly Deposits" << endl;
    cout << "====================================================" << endl;
    cout << left << setw(10) << "Year"
        << setw(20) << "Year End Balance"
        << setw(25) << "Year End Earned Interest" << endl;
    cout << "-------------------------------------------------------" << endl;

    printReport(true);
    cout << endl;
}

void InvestmentAccount::printReport(bool t_useMonthlyDeposit) const {
    // Starting balance is the initial investment
    double currentBalance = m_initialInvestment;
    double monthlyInterestRate = (m_annualInterest / 100.0) / 12.0;

    cout << fixed << setprecision(2);

    // Loop over each year
    for (int year = 1; year <= m_numberOfYears; ++year) {
        double totalInterestForYear = 0.0;

        // Loop over each month in the year
        for (int month = 1; month <= 12; ++month) {
            double openingAmount = currentBalance;

            // Use monthly deposit or not depending on the report
            double depositedAmount = 0.0;
            if (t_useMonthlyDeposit) {
                depositedAmount = m_monthlyDeposit;
            }

            // Total before interest
            double totalAmount = openingAmount + depositedAmount;

            // Interest for this month using the required formula:
            // (Opening Amount + Deposited Amount) * ((Interest Rate/100)/12)
            double interestForMonth = totalAmount * monthlyInterestRate;

            totalInterestForYear += interestForMonth;

            // Closing balance becomes opening for the next month
            currentBalance = totalAmount + interestForMonth;
        }

        // Print the year-end row
        cout << left << setw(10) << year
            << "$" << setw(19) << currentBalance
            << "$" << setw(24) << totalInterestForYear << endl;
    }
}