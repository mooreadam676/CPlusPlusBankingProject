#ifndef AIRGEAD_INVESTMENTACCOUNT_H_
#define AIRGEAD_INVESTMENTACCOUNT_H_

class InvestmentAccount {
public:
    // Constructors
    InvestmentAccount();
    InvestmentAccount(double t_initialInvestment,
        double t_monthlyDeposit,
        double t_annualInterest,
        int t_numberOfYears);

    // Setters
    void setInitialInvestment(double t_initialInvestment);
    void setMonthlyDeposit(double t_monthlyDeposit);
    void setAnnualInterest(double t_annualInterest);
    void setNumberOfYears(int t_numberOfYears);

    // Display both reports
    void printReportWithoutMonthlyDeposits() const;
    void printReportWithMonthlyDeposits() const;

private:
    double m_initialInvestment;
    double m_monthlyDeposit;
    double m_annualInterest;
    int m_numberOfYears;

    // Helper that performs the core compound interest calculation
    // and prints a table row per year.
    void printReport(bool t_useMonthlyDeposit) const;
};

#endif // AIRGEAD_INVESTMENTACCOUNT_H_
