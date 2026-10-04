#define BUDGET_H

struct of budget {
    char budgetDept[20][30];
    double budgetAllowed[20];
    double budgetSpent[20];
    int deptCount;
};
    void budgetMenu ();
    void addDepartmentBudget();
    void recordExpenditure();
    void displayDepartment();
    void displayExceededDepartment();
    double remaining();
}
