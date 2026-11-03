#include <iostream>
#include <cstdlib>
#include <string>
#include <stdexcept>
#include <cmath>

using namespace std;

int susceptible = 80;
int infected = 10;
int recovered = 10;
int day = 0;
bool loop = 1;

double infectionRate = .20;
double recoveryRate = .10;

void ShowPopulation(int day, int susceptible, int infected, int recovered);
void Clear();
void Menu();
void TryParseInt(string a, int &b);
void TryParseDouble(string c, double& d);
void SimulateDay();

int main()
{
    while (loop == true) {
        ShowPopulation(day, susceptible, infected, recovered);
        Menu();
    }
   
}

void ShowPopulation(int day, int susceptible, int infected, int recovered) {
    cout << "Day: " << day << endl;
    cout << "Susceptible: " << susceptible << endl;
    cout << "Infected: " << infected << endl;
    cout << "Recovered: " << recovered << endl;
    cout << "Total: " << susceptible + infected + recovered << endl;
}

void Clear() {
    system("cls");
}

void TryParseInt(string a, int &b) {
    try {
        b = stoi(a);
    }
    catch (const invalid_argument& e) {
        cout << "Invalid input\n";
    }
    catch (const out_of_range& e) {
        cout << "The number is too large or too small for an int.\n";
    }
}

void TryParseDouble(string c, double& d) {
    try {
        d = stod(c);
    }
    catch (const invalid_argument& e) {
        cout << "Invalid input\n";
    }
    catch (const out_of_range& e) {
        cout << "The number is too large or too small for an int.\n";
    }
}

void Menu() {
    string input;
    int choice = 0;

    cout << "\n=== Epidemic simulator ===" << endl;
    cout << "1. Simulate next day" << endl;
    cout << "2. Change model parameters" << endl;
    cout << "3. Exit" << endl;
    cout << "Your choice: ", cin >> input;
    
    TryParseInt(input, choice);

    switch (choice) {
    case 1: 
        Clear();
        SimulateDay();
        break;
    case 2:
        
        break;
    case 3:
        Clear();
        loop = 0;
        break;
    default:
        cout << "Option couldn't be found! \n";
        Menu();
        break;
    }
}

void SimulateDay() {
    int temp = infected;
    int newInfections = floor(temp * infectionRate);
    if (newInfections > susceptible) {
        newInfections = susceptible;
    }

    int newRecoveries = floor(temp * recoveryRate);
    if (newRecoveries > infected) {
        newRecoveries = infected;
    }

    day++;
    susceptible -= newInfections;
    infected = infected + newInfections - newRecoveries;
    recovered += newRecoveries;
}