#include <iostream>
#include <iomanip>
#include <conio.h>

using namespace std;

float value;
string unit;
string result_unit;
void convert();
void checkValueErrors();
void checkUnitErrors();
bool welcome = false;
bool valueError;
bool unitError;
bool good;

int main()
{
	valueError = false;
	unitError = false;

	if (welcome == false)
	{
		cout << "Witaj w kalkulatorze jednostek.\n";
		cout << "Masz mozliwosc zamiany...\n";
		welcome = true;
	}

	do 
	{
		valueError = false;
		cout << "Podaj wartosc, ktora chcesz przekonwertowac: ";
		cin >> value;
		checkValueErrors();
	} while (valueError == true);
	
	do
	{
		unitError = false;
		cout << "Wybierz jedna z ponizszych jednostek:\n";
		cout << "- 1. kB\n";
		cout << "- 2. MB\n";
		cout << "- 3. GB\n";
		cout << "- 4. TB\n\n";
		cout << "Wybrana jednostka (podaj numer 1-4): ";
		cin >> unit;
		//checkUnitErrors();
	} while (unitError == true);

	if (valueError == false && unitError == false)
	{
		cout << "Chcesz zamienic na ";
		cout << "(Wybierz jedna z ponizszych jednostek):\n";
		cout << "- 1. kB\n";
		cout << "- 2. MB\n";
		cout << "- 3. GB\n";
		cout << "- 4. TB\n\n";
		cout << "Wybrana jednostka (podaj numer 1-4): ";
		cin >> result_unit;
		convert();
	}
	else main();
}

void convert()
{
	if (unit == "1") unit = "kB";
	if (unit == "2") unit = "MB";
	if (unit == "3") unit = "GB";
	if (unit == "4") unit = "TB";

	if (result_unit == "1") result_unit = "kB";
	if (result_unit == "2") result_unit = "MB";
	if (result_unit == "3") result_unit = "GB";
	if (result_unit == "4") result_unit = "TB";

	cout << value << " " << unit << " = ";
	if (unit == "kB") value /= 1024;
	else if (unit == "MB") value = value;
	else if (unit == "GB") value *= 1024;
	else if (unit == "TB") value *= 1024 * 1024;

	if (result_unit == "kB") value *= 1024;
	else if (result_unit == "MB") value = value;
	else if (result_unit == "GB") value /= 1024;
	else if (result_unit == "TB") value /= 1024 * 1024;
	cout << setprecision(25) << value << " " << result_unit;
}

void checkValueErrors()
{

	if (value < 0)
	{
		cout << "\n-- PODALES WARTOSC UJEMNA --\n\n";
		valueError = true;
	}

	while (!(cin >> value))
	{
		cout << "\n-- PODALES ZLA WARTOSC --\n\n";
		cin.clear();
		cin.sync();
	}
}

void checkUnitErrors()
{
	if (unit != "1" || unit != "2")
	{
	cout << "\n-- WYBRALES ZLA JEDNOSTKE --\n\n";
	unitError = true;
	}
}