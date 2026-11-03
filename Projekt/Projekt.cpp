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
void TryParseRate(string c, double &d, bool &a);
void SimulateDay();
bool CheckPopulation(int susceptible, int infected, int recovered);
void ChangeRates(double &x, double &y);

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

void TryParseRate(string c, double &d, bool &a) {
    try {
        d = stod(c);
        a = true;
    }
    catch (const invalid_argument& e) {
        cout << "Invalid input\n";
    }
    catch (const out_of_range& e) {
        cout << "The number is too large or too small for a double.\n";
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
        Clear();
        ChangeRates(infectionRate, recoveryRate);
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
    bool verify = 1;
    int temp = infected;
    int newInfections = floor(temp * infectionRate);
    if (newInfections > susceptible) {
        newInfections = susceptible;
    }

    int newRecoveries = floor(temp * recoveryRate);
    if (newRecoveries > infected) {
        newRecoveries = infected;
    }

    if (verify) {
        day++;
        susceptible -= newInfections;
        infected = infected + newInfections - newRecoveries;
        recovered += newRecoveries;
    }
    else {
        cout << "Incorrect population state!";
    }
}

bool CheckPopulation(int susceptible, int infected, int recovered) {
    if (susceptible >= 0 && infected >= 0 && recovered >= 0) {
        if (susceptible + infected + recovered == 100) {
            return true;
        }
        else {
            return false;
        }
    }
    else {
        return false;
    }
}

void ChangeRates(double &x, double &y) {
    string input1, input2;
    double temp1, temp2;
    bool is1set = false, is2set = false;

    cout << "Enter infection rate (0-1): ", cin >> input1;
    TryParseRate(input1, temp1, is1set);
    if (is1set) {
        if (temp1 >= 0 && temp1 <= 1) {
            x = temp1;
        }
        else {
            cout << "Value out of range";
        }
    }

    cout << "\nEnter recovery rate (0-1)", cin >> input2;
    TryParseRate(input2, temp2, is2set);
    if (is2set) {
        if (temp2 >= 0 && temp2 <= 1) {
            y = temp2;
        }
        else {
            cout << "Value out of range";
        }
    }
}