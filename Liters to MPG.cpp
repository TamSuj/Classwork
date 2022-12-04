/*Tammy Sujaritchai
CS 002 - Programming Project 6: Liters to MPG
Last edited: 10/27/22 
*/

#include <iostream>
using namespace std;

double input(string);//take string input
const float LITER_TO_GALLON = 0.264172; //1 liter = 0.264172 gallons.
void compareMPG(float, float); //compare MPG of two cars
float mile, liter; 
int i = 0;

class Car {
  public:
  float mile, liter, MPG;
  
  //Calculate number of miles per gallon by dividing miles by gallons (converted from liters)
  // x = liter, y = mile
  double mpgCalculator(float x, float y){
    MPG = y / (LITER_TO_GALLON * x); 
    
    return MPG;
  }
  
  void printMPG(){
      if(i == 2){
          i = 0; // Reser i to 0 when user repeat the calculation
      }
      
      i++;
      cout << "\nMPG " << i << ": " << MPG << endl;
  }
};

int main() {
  int user;
  
  do{
    Car car1, car2;
    car1.liter = input("\nEnter the information for Car 1\n\tLiters: ");
    car1.mile = input("\tMiles: ");

    car2.liter = input("\nEnter the information for Car 2\n\tLiters: ");
    car2.mile = input("\tMiles: ");

    compareMPG(car1.mpgCalculator(car1.liter, car1.mile), car2.mpgCalculator(car2.liter, car2.mile));
    /*Calculate the number of miles per gallon of each car using mpgCalculator() function 
    then compare the result using compareMPG() function*/
    car1.printMPG();
    car2.printMPG();

    cout << "\nEnter any number to repeat the calculation or enter 1 to exit" << endl;
    cin >> user;
    
  }while(user != 1);
}

double input(string x){
  float output;
  
  cout << x;
  cin >> output;

  return output;
}

//compare MPG and output the result
void compareMPG(float x, float y){
    
    string result = x > y ? "\nCar 1 has better mileage" : "\nCar 2 has better mileage";
    cout << result << endl;
}

//Credit: https://www.w3schools.com/cpp/cpp_classes.asphttps://www.w3schools.com/cpp/cpp_classes.asp
