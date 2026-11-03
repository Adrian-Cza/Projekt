#include <iostream>

using namespace std;

int susceptible = 80;
int infected = 10;
int recovered = 10;
int day = 0;

double infectionRate = .20;
double recoveryRate = .10;

void ShowPopulation(int day, int susceptible, int infected, int recovered);

int main()
{
    ShowPopulation(day, susceptible, infected, recovered);
}

void ShowPopulation(int day, int susceptible, int infected, int recovered) {
    cout << "Day: " << day << endl;
    cout << "Susceptible: " << susceptible << endl;
    cout << "Infected: " << infected << endl;
    cout << "Recovered: " << recovered << endl;
    cout << "Total: " << susceptible + infected + recovered << endl;
}
