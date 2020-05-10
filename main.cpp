#include <iostream>
using namespace std;

class Employee{
  private:
    string empName;
    double empPoints;
    string empGorup;
    double empAvg;
    int empId;
  public:
    Employee(){
      empId = 0;
      empName = "N/A";
      empPoints = 0;
      empGorup = "null";
      empAvg = 0.0;
    }
    Employee(int empId,string empName){
      this->empId = empId;
      this->empName = empName;
      empPoints = 0;
      empGorup = "null";
      empAvg = 0.0;
    }
    void addPoints(double newPoints){
      this->empPoints += newPoints;
    }
    void upgradePoints(double percentage){
      percentage /= 100;
      this->empPoints = this->empPoints * percentage + this->empPoints;
    }
    void removePoints(double deductPoints){
      this->empPoints -= deductPoints;
    }
    void computeGroup(){
      if(this->empPoints > 2000.0){
        this->empGorup = "Diamond";
      }else if(this->empPoints <= 2000 && this->empPoints > 500){
        this->empGorup = "Platinum";
      }else if(this->empPoints <= 500 && this->empPoints > 100){
        this->empGorup = "Gold";
      }else{
        this->empGorup = "Silver";
      }
    }
    void display(){
      cout << "Employee ID: " << this->empId << endl;
      cout << "Employee Name: " << this->empName << endl;
      cout << "Employee Points: " << this->empPoints << endl;
      cout << "Employee Group: " << this->empGorup << endl;
      cout << "Average: " << this->empAvg;
    }
    static int getBest(int numberOfEmployees){
      //TODO: complete this fucntion
      int bestCandidate = 0;
      return bestCandidate;
    }
};
int main(){
  Employee allEmployees[5];
  allEmployees[0] = Employee(1,"Haris");
  allEmployees[1] = Employee(2,"Faraz");
  allEmployees[2] = Employee(3,"Umer");
  allEmployees[3] = Employee(4,"Afaq");
  allEmployees[4] = Employee(5,"Abid");
  allEmployees[0].addPoints(129);
  allEmployees[1].addPoints(785);
  allEmployees[2].addPoints(3258);
  allEmployees[3].addPoints(59);
  allEmployees[4].addPoints(1652);
  allEmployees[2].addPoints(1000);
  allEmployees[1].upgradePoints(2);
  for(int i = 0 ; i < 5 ; i++){
    cout << endl << "---------------------"<<endl;
     allEmployees[i].display();
  }
  cout << endl << "---------------------";
  cout << endl << "After Calculating Groups";
  for(int i = 0 ; i < 5 ; i++){
    cout << endl << "---------------------" << endl;
    allEmployees[i].computeGroup();
     allEmployees[i].display();
  }
  //TODO: call the getBest
  Employee *emp = &allEmployees[4];
  emp->removePoints(2000);
  cout << endl << "--------------------------------";
  cout << endl << "After User of Reference Varialbe";
  cout << endl << "--------------------------------" << endl;
  emp->computeGroup();
  allEmployees[4].display();
  Employee defaultEmployee;
  *emp = defaultEmployee;
  Employee *emp1 = &defaultEmployee;
}