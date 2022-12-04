/*
Tammy Sujaritchai
CS 002 - Programming Project 5: Calculate Your Paycheck
Last edited: 10/16/22
*/

#include <iostream>
using namespace std;

string state;
int grossPay; 
double stateTax, incomeTax, socialSecurityTax, medicare, pensionPlan, healthIns = 0, dentalIns = 17.58, visionIns = 0, total, pensionPercentage;
char choice;

void basicDeduction(int); // calculate income tax, Social Security tax, and Medicare/Medicaid tax
double CaliforniaTaxDeduction(int); //calculate CA state tax according to user's input gross income
double AlabamaTaxDeduction(int); //calculate AL state tax according to user's input gross income
void itemizedDeduction(); //Print out the deduction values for every deduction
void pensionPlanDeduction(int, float); //calculate pension plan deduction according to user's input
void InsuranceCalculation(); //Calculate insurance (medical/dental/vision) fee according to user's needs (single/family coverage)
//void outputWithComma(double);

int main() {
  //Formatting the output to 2 decimal places
  cout.setf(ios::fixed);
  cout.setf(ios::showpoint);
  cout.precision(2);
  
  //Prompting for user's state and income to be used in calculation
  cout << "Enter your annual gross income\n";
  cin >> grossPay;
  cout << "Enter your current State (CA by default)\n";
  cin >> state;

  //Calculate Federal Income, SSN, and Medicare/Medicaid Tax
  basicDeduction(grossPay);
  if (state == "Alabama" || state == "AL"){
    AlabamaTaxDeduction(grossPay);
  }
  else{
    CaliforniaTaxDeduction(grossPay);
  }

  //Calculate pension plan deduction
  cout << "Enter your pension plan percentage from the scale 0-15% (ex: 15 for 15%)" << endl; 
  cin >> pensionPercentage;
  pensionPlanDeduction(grossPay, pensionPercentage);
  
  InsuranceCalculation();

  itemizedDeduction();
  cout << "\nTotal Deduction\t\t\t = $" << total << endl;

  //Print out break down of income (yearly, monthly, bi-monthly, and weekly)
  double netSalary = grossPay - total;
  double monthlySalary = netSalary / 12;
  double biMonthlySalary = netSalary / 6;
  double weeklySalary = monthlySalary / 4;

  cout << "\nYour net annual salary\t = $" << netSalary 
       << "\n\tBi-monthly salary\t = $" << biMonthlySalary
       << "\n\tMonthly salary\t\t = $" << monthlySalary
       << "\n\tWeekly salary\t\t = $" << weeklySalary << endl;    
}

void basicDeduction(int x){
  /*Federal Income Tax: 22%
  Social Security Tax: 6.2%
  Medicare/Medicaid Tax: 1.45%*/
  
  incomeTax = 0.22 * x;
  socialSecurityTax = 0.062 * x;
  medicare = 0.0145 * x;
}

double CaliforniaTaxDeduction(int x){
  if (x <= 8544) {
    stateTax = x * 0.01;
  } 
  else if (x <= 20255) {
    stateTax = x * 0.02;
  }
  else if (x <= 31969) {
    stateTax = x * 0.04;
  }
  else if (x <= 44377) {
    stateTax = x * 0.06;
  }
  else if (x <= 56085) {
    stateTax = x * 0.08;
  }
  else if (x <= 286492) {
    stateTax = x * 0.093;
  }
  else if (x <= 343788) {
    stateTax = x * 0.103;
  }
  else if (x <= 572980) {
    stateTax = x * 0.113;
  }
  else if (x <= 572980) {
    stateTax = x * 0.113;
  }
  else if (x <= 999999) {
    stateTax = x * 0.123;
  }
  else {
    stateTax = x * 0.133;
  }
  return stateTax;
}

double AlabamaTaxDeduction(int x){
  if (x >= 3000) {
    stateTax = x * 0.05;
  } 
  else if (x >= 500) {
    stateTax = x * 0.04;
  }
  else {
    stateTax = x * 0.02;
  }
  return stateTax;
}

void itemizedDeduction(){
  cout << "\nDeduction:\n" << endl;
  cout << "\tFederal Income Tax\t = $" << incomeTax << endl;
  cout << "\tSocial Security Tax\t = $" << socialSecurityTax << endl;
  cout << "\tMedicare/medicad\t = $" << medicare << endl;
  cout << "\tState tax\t\t\t = $" << stateTax << endl;
  cout << "\tPension Deduction\t = $" << pensionPlan << endl;
  cout << "\tHealth Insurance\t = $" << healthIns << endl;
  cout << "\tDental Insurance\t = $" << dentalIns << endl;
  cout << "\tVision Insurance\t = $" << visionIns << endl;
  
  total = incomeTax + socialSecurityTax + medicare + stateTax + pensionPlan + healthIns +  dentalIns + visionIns;
}

void pensionPlanDeduction (int x, float y) {
  pensionPlan = x * (y / 100);
}

void InsuranceCalculation(){
  //Asking user if they want to opt-in health insurance
  cout << "Do you want to opt-in health insurance? (Y/N)" << endl;
  cin >> choice;
  if (choice == 'Y' || choice == 'y') {
    cout << "Do you want health insurance just for yourself? (Y/N)" << endl;
    cin >> choice;
    if (choice == 'Y' || choice == 'y') {
      cout << "Health insurance will only cover you\n" << endl;
    }
    else {
    healthIns = 251.63 * 24;
    cout << "Health insurance will cover both you and your family\n" << endl;
    }
  }
  

  //Asking user if they want to opt-in dental insurance
  cout << "Do you want to opt-in dental insurance? (Y/N)" << endl;
  cin >> choice;
  if (choice == 'Y' || choice == 'y') {
    cout << "Do you want dental insurance just for yourself? (Y/N)" << endl;
    cin >> choice;
    if (choice == 'Y' || choice == 'y') {
      cout << "Dental insurance will only cover you\n" << endl;
    }
    else {
    dentalIns = 70.88 * 24;
    cout << "Dental insurance will cover both you and your family\n" << endl;
    }
  }

  //Asking user if they want to opt-in vision insurance
  cout << "Do you want to opt-in vision insurance? (Y/N)" << endl;
  cin >> choice;
  if (choice == 'Y' || choice == 'y') {
    cout << "Do you want vision insurance just for yourself? (Y/N)" << endl;
    cin >> choice;
    if (choice == 'Y' || choice == 'y') {
      cout << "Vision insurance will only cover you\n" << endl;
    }
    else {
    visionIns = 5.61 * 24;
    cout << "Vision insurance will cover both you and your family\n" << endl;
    }
  }
}

/*
//Print out final wage with proper commas
void outputWithComma(double x){
  #include<cstring>

  int num = x, i, len = to_string(num).length(); //Get the length of the number

  while(len > 0){
    to_string(x).insert(i, ",");
    len -= 3;
  }
}
*/

/*Credit: 
  State Individual Income Tax Rates and Brackets: https://www.docuclix.com/external/?_y=744e95342305279835204c1fcd657188*/
