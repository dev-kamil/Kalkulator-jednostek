#include <iostream>
#include <iomanip>
#include <conio.h>

using namespace std;

float value;				// Wartość jaką chcemy przekonwertować
string unit;				// Jednostka liczby do konwersji
string result_unit;			// Jednostka na którą ma być przekonwertowana podana wartość
void convert();				// Konwersja podanej jednostki
void checkValueErrors();	// Walidacja wartości
void checkUnitErrors();		// Walidacja jednostki początkowej
void checkResultUnit();		// Walidacja jednostki wynikowej
void firstConvert();		// Wstępna zamiana - string unit - z zakresu (1-4) na jednostki (kB/MB/GB/TB)
bool welcome = false;		// Wiadomość powitalna, przedstawienie możliwośc programu (false - nie było / true - było)
bool valueError;			// Błąd wartości
bool unitError;				// Błąd jednostki początkowej
bool resultUnitError;		// Błąd jednostki wynikowej

int main()
{
	do
	{
		// Powitanie, możliwości programu
		if (welcome == false)
		{
			cout << "Witaj w kalkulatorze jednostek.\n";
			cout << "Mozesz poruszac sie w nastepujacych jednostkach: kB, MB, GB, TB\n\n";
			welcome = true;
		}

		// Pobieramy wartość od gracza
		do
		{
			valueError = false; // Domyślnie brak błędu (wartość jeszcze jest niezdefiniowana)
			cout << "Podaj wartosc, ktora chcesz przekonwertowac: ";
			checkValueErrors(); // Sprawdzamy czy wartość jest prawidłowa
		} while (valueError == true); // Wykonujemy dopóki nie zostanie podana prawidłowa wartość

		// Użytkownik wybiera jednostkę
		do
		{
			unitError = false; // Domyślnie brak błędu (wartośc niezdefiniowana)
			cout << "Wybierz jednostke:\n";
			cout << "- 1. kB\n";
			cout << "- 2. MB\n";
			cout << "- 3. GB\n";
			cout << "- 4. TB\n";
			cout << "Wybrana jednostka (podaj numer 1-4): ";
			cin >> unit;
			checkUnitErrors(); // Sprawdzamy prawidłowość
		} while (unitError == true); // Wykonujemy dopóki nie zostanie wybrana prawidłowa opcja

		if (valueError == false && unitError == false) // Zabezpieczenie na wypadek, gdyby wystąpił jakiś błąd
		{
			do
			{
				resultUnitError = false;
				firstConvert();
				cout << "\n" << value << " " << unit << " ";
				cout << "chcesz zamienic na ";
				cout << "(Wybierz jedna z ponizszych jednostek):\n";
				cout << "- 1. kB\n";
				cout << "- 2. MB\n";
				cout << "- 3. GB\n";
				cout << "- 4. TB\n";
				cout << "Wybrana jednostka (podaj numer 1-4): ";
				cin >> result_unit;
				checkResultUnit();
			} while (resultUnitError == true);

			convert();
		}
		else main();

		cout << "\n\nWcisnij ESC aby zakonczyc program.\n";
		cout << "Aby kontynuowac kliknij dowolny inny klawisz.\n\n";
	} while (_getch() != 27);
}

void firstConvert()
{
	if (unit == "1") unit = "kB";
	else if (unit == "2") unit = "MB";
	else if (unit == "3") unit = "GB";
	else if (unit == "4") unit = "TB";
}

void convert()
{
	if (result_unit == "1") result_unit = "kB";
	else if (result_unit == "2") result_unit = "MB";
	else if (result_unit == "3") result_unit = "GB";
	else if (result_unit == "4") result_unit = "TB";

	// Zamieniamy z jakiejkolwiek jednostki na MB
	cout << value << " " << unit << " = ";
	if (unit == "kB") value /= 1024;
	else if (unit == "MB") value = value;
	else if (unit == "GB") value *= 1024;
	else if (unit == "TB") value *= 1024 * 1024;

	// Wychodząc z MB zmieniamy na jednostkę pożądaną przez użytkownika
	if (result_unit == "kB") value *= 1024;
	else if (result_unit == "MB") value = value;
	else if (result_unit == "GB") value /= 1024;
	else if (result_unit == "TB") value /= 1024 * 1024;
	cout << setprecision(25) << value << " " << result_unit;
}

void checkValueErrors()
{
	// Jeżeli użytkownik wpisze tekst
	if (!(cin >> value))
	{
		cerr << "\n-- PODALES ZLA WARTOSC --\n\n";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		valueError = true;
	}

	// Jeżeli użytkownik poda wartość ujemną
	else if (value < 0)
	{
		cerr << "\n-- PODALES WARTOSC UJEMNA --\n\n";
		valueError = true;
	}
}

void checkUnitErrors()
{
	if (unit != "1" && unit != "2" && unit != "3" && unit != "4")
	{
	cerr << "\n-- WYBRALES ZLA JEDNOSTKE --\n\n";
	unitError = true;
	}
}

void checkResultUnit()
{
	if (result_unit != "1" && result_unit != "2" && result_unit != "3" && result_unit != "4")
	{
		cerr << "\n-- WYBRALES ZLA JEDNOSTKE --\n\n";
		resultUnitError = true;
	}
}