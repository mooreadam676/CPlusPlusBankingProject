#include <iostream>
#include <iomanip>
#include <cctype>
#include "InvestmentAccount.h"

using namespace std;

int main() {
    try {
        char keepRunning = 'Y';

        while (toupper(keepRunning) == 'Y') {

            double initialInvestment = 0.0;
            double monthlyDeposit = 0.0;
            double annualInterest = 0.0;
            int numberOfYears = 0;

            // Input screen
            cout << "**********************************" << endl;
            cout << "********** Airgead Banking *******" << endl;
            cout << "**********************************" << endl;
            cout << "Initial Investment Amount: ";
            cin >> initialInvestment;

            cout << "Monthly Deposit: ";
            cin >> monthlyDeposit;

            cout << "Annual Interest (Compounded %): ";
            cin >> annualInterest;

            cout << "Number of Years: ";
            cin >> numberOfYears;

            cout << "Press any key and ENTER to continue...";
            char pauseInput;
            cin >> pauseInput;

            // Create account object using the input values
            InvestmentAccount account(initialInvestment,
                monthlyDeposit,
                annualInterest,
                numberOfYears);

            cout << endl << endl;

            // Display both reports
            account.printReportWithoutMonthlyDeposits();
            cout << endl;
            account.printReportWithMonthlyDeposits();

            cout << "Would you like to test another investment scenario? (Y/N): ";
            cin >> keepRunning;
            cout << endl;
        }

        cout << "Thank you for using the Airgead Banking Investment Calculator." << endl;

    }
    catch (const exception& ex) {
        // Graceful exit with message, per standards doc
        cerr << "An error occurred: " << ex.what() << endl;
    }

    return 0;
}