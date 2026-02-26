// Date Created: Feb 26, 2026 - 2:11pm
// Date Updated: Feb 26, 20206 - 10:58pm
// hw3: intro_c++.financial processing program

#include <iostream>
#include <string>
// #include <iomanip> //	cout << fixed << setprecision(2);

using namespace std;

// initialize a math function. the deposit variable will be used for the calculation. currency_type is used to ensure proper conversion.
float converter(float deposited, string currency_type) {
    float const PHP_USD = 56.50, PHP_EUR = 61.20, PHP_JPY = 0.38; // fixed exchange rate
    if (currency_type == "USD") {
        return deposited / PHP_USD;
    } 
    else if (currency_type == "EUR") {
        return deposited / PHP_EUR;
    } 
    else if (currency_type == "JPY") {
        return deposited / PHP_JPY;
    } 
    else {
        return 0;
    }
}

int main(){
    float deposited = 0;
    string currency_type;
    string CONFIRM_MESSAGE_1 = " is selected. Continue? (Y/N) ";
    char confirm_1;


    // confirmation process
    cout << "Currency Converter for Philippine Peso (PHP) to United States Dollar (USD), European Dollar (EUR), and Japanese Yen (JPY).\n" << endl; 
    cout << "What currency would you like your money to be converted to?\nAvailable Currencies: USD, EUR, JPY.\nEnter: "; cin >> currency_type;

        if (currency_type == "USD") {
                cout << currency_type; cout << CONFIRM_MESSAGE_1; 
                cin >> confirm_1;
            } else if (currency_type == "JPY") {
                cout << currency_type; cout << CONFIRM_MESSAGE_1; 
                cin >> confirm_1;
            } else if (currency_type == "EUR") {
                cout << currency_type; cout << CONFIRM_MESSAGE_1; 
                cin >> confirm_1;
            } else {
                cout << "Please try again.";
                return 1;
            }//confirm end


    // after confirmation, we will have the currency_type and confirm_1 variables.
    if(confirm_1 == 'Y'){cout << "Converting PHP to "; cout << currency_type; cout << "\nEnter amount: "; cin >> deposited;} else {cout << "Please try again.";} // terminates the program if unconfirmed.
    
    // calls the math function above main(). moved the math function outside for simplicity and easier syntax.
    float converted_amount = converter(deposited, currency_type);
    cout << "Converted amount: " << converted_amount << endl;


    return 0;
}