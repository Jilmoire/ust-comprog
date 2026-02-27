// Date Created: Feb 26, 2026 - 2:11pm
// Date Updated: Feb 27, 20206 - 10:09pm
// hw3: intro_c++.financial processing program

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

// initialize a math function. the deposit variable will be used for the calculation. currency_type is used to ensure proper conversion.
float converter(float deposited, string currency_type) {
    float const PHP_USD = 56.50, PHP_EUR = 61.20, PHP_JPY = 0.38; // fixed exchange rate
    float vat, remaining_bal; // for value added tax calculation
    float usd_eur, usd_jpy, eur_usd, eur_jpy, jpy_usd, jpy_eur;
    
    vat = deposited * 0.12;
    remaining_bal = deposited - vat;

    float usd = remaining_bal / PHP_USD;
    float eur = remaining_bal / PHP_EUR;
    float jpy = remaining_bal / PHP_JPY;
                                                // pre defined formulas for maths
    usd_eur = usd * (PHP_USD / PHP_EUR);
    usd_jpy = usd * (PHP_USD / PHP_JPY);
    jpy_eur = jpy * (PHP_JPY / PHP_EUR);

    // cross currency reference table
    cout << fixed << setprecision(2);
    cout << "\n----- Conversion Summary (After VAT) -----\n";
    cout << "PHP to USD: " << usd << endl;
    cout << "PHP to EUR: " << eur << endl;
    cout << "PHP to JPY: " << jpy << endl;

    cout << "\n----- Cross-Currency Conversions -----\n";
    cout << "USD to EUR: " << usd_eur << endl;
    cout << "USD to JPY: " << usd_jpy << endl;
    cout << "JPY to EUR: " << jpy_eur << endl << endl;
    // cross currency reference table

    // math for the intended currency converted.
    if (currency_type == "USD") {
        cout << "The VAT for this transaction is " << vat; cout << ". " << vat; cout << " pesos will be deducted to your balance.\n";
        cout  << fixed << setprecision(2) << "\nPrevious Balance: " << deposited; cout << ". \nCurrent Balance (Used in the computation): " << remaining_bal << endl;
        return remaining_bal / PHP_USD;
    } 
    else if (currency_type == "EUR") {
        cout << "The VAT for this transaction is " << vat; cout << ". " << vat; cout << " pesos will be deducted to your balance.\n";
        cout  << fixed << setprecision(2) << "\nPrevious Balance: " << deposited; cout << ". \nCurrent Balance (Used in the computation): " << remaining_bal << endl;
        return remaining_bal / PHP_EUR;
    } 
    else if (currency_type == "JPY") {
        cout << "The VAT for this transaction is " << vat; cout << ". " << vat; cout << " pesos be deducted to your balance.\n";
        cout  << fixed << setprecision(2) << "\nPrevious Balance: " << deposited; cout << ". \nCurrent Balance (Used in the computation): " << remaining_bal << endl;
        return remaining_bal / PHP_JPY;
    } 
    else {
        cout << "Somethiing went wrong. Please try again";
        return 1;
    } // this error shouldn't happen
    
} //deposited and currency_type are defined here and inside main because they are different functipns

int main(){
    float deposited = 0;
    string currency_type;
    string CONFIRM_MESSAGE_1 = " is selected. Continue? (Y/N): ";
    char confirm_1;

    // confirmation process
    cout << "Currency Converter for Philippine Peso (PHP) to United States Dollar (USD), European Dollar (EUR), and Japanese Yen (JPY).\n" << endl; 
    cout << "What currency would you like your money to be converted to?\nAvailable Currencies: USD, EUR, JPY. (Case Sensitive)\nEnter: "; cin >> currency_type;

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
    if(confirm_1 == 'Y'){cout << "\nConverting PHP to "; cout << currency_type; cout << ". A 12% Value Added Tax will be charged.\nEnter amount: "; cin >> deposited;} else {cout << "Please try again. Program terminated.\n"; return 0;} // terminates the program if unconfirmed.
    
    // calls the math function above main(). moved the math function outside for simplicity and easier syntax.
    float converted_amount = converter(deposited, currency_type);
        if (currency_type == "USD") {
            cout << "\nYou now have " << converted_amount; cout << " dollars. You can check the above table for other conversions for the same amount of money.\n";
        } else if (currency_type == "EUR") {
            cout << "\nYou now have " << converted_amount; cout << " euros. You can check the above table for other conversions for the same amount of money.\n";
        } else if (currency_type == "JPY") {
            cout << "\nYou now have " << converted_amount; cout << " yen. You can check the above table for other conversions for the same amount of money.\n";
        } 

    return 0;
}