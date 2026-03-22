class Expense{
public:
    string date;
    string category;
    double amount;
    string description;
    Expense(string d,string c,double a,string desc){
        date=d;
        category=c;
        amount=a;
        description=desc;
    }
};
void addExpense(vector<Expense>& expenses){
    string date, category, desc;
    double amount;
    cout<<"Enter date: ";
    cin>>date;
    cout<<"Enter category: ";
    cin>>category;
    cout<<"Enter amount: ";
    cin>>amount;
    cout<<"Enter description: ";
    cin>>desc;    
    expenses.push_back(Expense(date, category, amount, desc));
    cout<<"Expense added successfully\n";
}
void viewExpenses(vector<Expense>& expenses) {

    for(auto &e : expenses) {
        cout<<e.date<<" "<<e.category<<" "<< e.amount << " "<<e.description<<endl;
    }
}
void totalSpending(vector<Expense>& expenses){
    double total=0;
    for(auto &e:expenses)
        total+=e.amount;
    cout<<"Total spending: "<<total<<endl;
}
void saveExpenses(vector<Expense>& expenses){
    ofstream file("expenses.txt");
    for(auto &e:expenses){
        file<<e.date<<" "<< e.category<<" "<<e.amount<< " "<<e.description<<endl;
    }
    file.close();
}
int main(){
    vector<Expense> expenses;
    int choice;
    do{
        cout<<\n"Expense Tracker\n";
        cout<<"1. Add Expense\n";
        cout<<"2. View Expenses\n";
        cout<<"3. Total Spending\n";
        cout<<"4. Save & Exit\n";
        cout<<"Enter choice: ";
        cin>>choice;
        switch(choice){
            case 1: 
              addExpense(expenses);
              break;
            case 2: 
              viewExpenses(expenses);
              break;
            case 3: 
              totalSpending(expenses);
              break;
            case 4: 
              saveExpenses(expenses); 
              out<<"Data saved.Exiting...\n"; 
              break;
            default:
              cout<<"Invalid choice\n";
        }
    }while(choice!=4);
    return 0;
}
