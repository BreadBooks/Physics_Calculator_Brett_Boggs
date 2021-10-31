//Coding Assignment 1: Physics Calculator: Brett Boggs, Teacher: Dr_T
//Header
#include <iostream>
#include<string>
#include <iomanip>
#include "inputValidation.h" 
using namespace std;
// Prototypes
void handleChoice(string); 
void showMenu(); 
void findVelocity(double,double); 
void findAcceleration(double,double);  
void showMotionMenu();
void findMotionOne(double,double,double);
void findForce(double, double);
void findWeight (double);
void findMomentum(double, double);

// Definitions
void handleChoice(string userChoice)
{
    double distance = 0.0, time = 0.0, velocity = 0.0, acceleration = 0.0,
    mass = 0.0;
    
    if(userChoice == "A" || userChoice == "a")
    {
      cout << "\nFind Velocity" << endl;
      cout << "\nInput the known distance in km below. \n"; 
      distance = validateDouble(distance);
      cout << "\nInput the known time in hours below. \n"; 
      time = validateDouble(time); 
      findVelocity(distance, time);
    }
    else if(userChoice == "B" || userChoice == "b")
    {
      cout << "\nFind Acceleration" << endl;
      cout << "\nInput the known velocity below. \n"; 
      velocity = validateDouble(velocity); 
      cout << "\nInput the known time in seconds below. \n"; 
      time = validateDouble(time); 
      findAcceleration(velocity, time);
    }
    else if(userChoice == "C" || userChoice == "c")
    {
      // showMotionMenu();
      cout << "\nFind Motion" << endl;
      cout << "\nInput the known velocity below. \n";
      velocity = validateDouble(velocity); 
      cout << "\nInput the known acceleration below. \n";
      acceleration = validateDouble(acceleration);
      cout << "\nInput the known time in seconds below. \n"; 
      time = validateDouble(time); 
      findMotionOne(velocity, acceleration, time);

    }
    else if(userChoice == "D" || userChoice == "d")
    { 
      cout << "\nFind Force" << endl;
      cout << "\nInput the known mass below. \n";
      mass = validateDouble(mass); 
      cout << "\nInput the known acceleration below. \n";
      acceleration = validateDouble(acceleration); 
      findForce(mass, acceleration);
    }
    else if(userChoice == "E" || userChoice == "e")
    { 
      cout << "\nFind Weight" << endl;
      cout << "\nInput the known mass below. \n";
      mass = validateDouble(mass); 
      findWeight(mass);
    }
    else if(userChoice == "F" || userChoice == "f")
    { 
      cout << "\nFind Momentum" << endl;
      cout << "\nInput the known mass below. \n";
      mass = validateDouble(mass); 
      cout << "\nInput the known velocity below. \n";
      velocity = validateDouble(velocity); 
      findMomentum(mass,velocity);
    }
    // Taken from Dr. T Function Practice
  else if(userChoice == "X" || userChoice == "x")
    {
      string reset = "\x1b[0m";
      //Linux Umbunu
      cout << reset; 
      cout << "\033[2J\033[1;1H";  //for ubuntu Linux ChoiceuserChoice 1 of 2
      //Windows: system("cls"); 
      system("clear"); //for ubuntu Linux ChoiceuserChoice 2 of 2
    }
}

void showMenu()
{
  cout << "\nMENU" << endl; 
  cout << "A: Find Velocity" <<endl; 
  cout << "B: Find Acceleration" << endl; 
  cout << "C: Find Motion" << endl; 
  cout << "D: Find Force" << endl; 
  cout << "E: Find Weight" << endl; 
  cout << "F: Find Momentum" << endl; 
  cout << "T: Terminate Program" << endl; 
  cout << "X: Clear" << endl;
}

void findVelocity(double distance, double time)
{
  double Velocity;
  Velocity = distance/time;
  cout << "The velocity is: " << Velocity << " km/h" << endl;
 
}

void findAcceleration(double velocity, double time)
{
  double Acceleration;
  Acceleration = velocity/time;
  cout << "The acceleration is: " << Acceleration << " m/s" << endl;
 
}

// WHERE MOTION SUBMENU IS SUPPOSE TO BE 
// Can't figure out I was a procrastinator 

// void handleMotionMenu(string);

// void showMotionMenu()
// {
//   cout << "\nChoose which motion formula you'd like to use" << endl;
//   cout << "A: Ma = Solve for v" << endl;
//   cout << "B: Ms = Solve for s" << endl;
//   cout << "C: Mv2 = Solve for v^2" << endl;
//   cout << "D: Mv = Solve for v_bar" << endl;
  
// }

// void handleMotionMenu(string userOption)
// {
//     double distance = 0.0, time = 0.0, velocity = 0.0, acceleration = 0.0;
    
//     if(userOption == "A" || userOption == "a")
//     {
//       cout << "\nMa = Solve for v" << endl;
//       cout << "\nInput the known velocity in km/h below. \n"; 
//       velocity = validateDouble(velocity);
//       cout << "\nInput the known acceleration in km/h below. \n"; 
//       acceleration = validateDouble(acceleration); 
//       cout << "\nInput the known time in km/h below. \n"; 
//       findMotionOne(velocity,acceleration,time);
//     }
//     else if(userOption == "B" || userOption == "b")
//     {
//       cout << "\nFind the Acceleration" << endl;
//       cout << "\nInput the known velocity below. \n"; 
//       velocity = validateDouble(velocity); 
//       cout << "\nInput the known time below. \n"; 
//       time = validateDouble(time); 
//       findAcceleration(velocity, time);
//     }
   
// }

void findMotionOne(double velocity, double acceleration, double time)
{
  double MotionOne;
  MotionOne = velocity + acceleration*time;
  cout << "The motion is: " << MotionOne << " m/s" << endl;
 
}

void findForce(double mass, double acceleration)
{
  double Force;
  Force = mass*acceleration;
  cout << "The force is: " << Force << " kg m/s^2" << endl;
}

void findWeight(double mass) {
  float g = 9.81;
  double Weight;
  Weight = mass*g;
  cout << "The weight is: " << Weight << " lbs" << endl;
}

void findMomentum(double mass, double velocity) {
  double Momentum;
  Momentum = mass*velocity;
  cout << "The momentum is: " << Momentum << " kg m/s" << endl;
}
// main
// Taken from Dr. T functions practice but changed color to pink!
int main() 
{
  string choice = ""; //the choice local to int main()
  string color = "\x1b[" + to_string(35) + ";1m";
  string reset = "\x1b[0m";
  //loop until the user provides "e" or (&&) "E" as exit condition
  
  do
  {
    showMenu(); //call a menu void function here
    cout << "\nPlease enter a choice: ";
      cout << color; //change text to pink 
     //cin >> choice; //getline(cin,choice); //get the entire line
    choice = validateString(choice); 
    cout << reset; //reset back to standard
    handleChoice(choice); //call handlechoice and pass the user choice as an argument
    
  
  } while(choice != "t" && choice != "T"); //DeMorgan's Law!!! 
  cout << "\nGoodbye. Hasta luego." << endl;
  return 0; 
}