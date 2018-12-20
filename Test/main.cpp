#include <string>
#include <iostream>
#include <cstdlib>
#include <stdio.h>

using namespace std;

const int CREDIT_CARD_NUMBERS = 16;

int pap(unsigned long creditCardNumber) {
    printf("%-4s %-4s %-4s\n", "Nr.", "Gew.", "Prod.");
    
    //Holder for the products
    int products[CREDIT_CARD_NUMBERS - 1];
    
    //While there is a rest of credit card number, take i as indicator for factoring
    for(int i = 0; creditCardNumber; i++) {
        int digit = creditCardNumber % 10;
        
        int product = digit;
        
        // Take rest of module (0 or 1) + 1 for factor
        int factor = i % 2 + 1;
        
        // First digit is checked digit, so skip that
        if(i == 0) {
            printf("%-4s %-4d %-4s\n", "P", factor, "-");
        } else {
            // Multiply digit
            product *= factor;
            
            printf("%-4d %-4d %-4d\n", digit, factor, product);

            // Take care if there product is bigger than 9
            if (product > 9) {
                // Build product sum
                int productSum = 0;
                
                //While rest of product is more than 0
                while (product > 0) {
                    // Divide product with 10 to move one digit from right and add rest to productSum
                    productSum += product % 10;
                    
                    //Go further with divided product
                    product /= 10;
                }
                
                product = productSum;
            }
            
            //Store product in holder
            products[i - 1] = product;
        }
        
        //Go further with divided credit card number
        creditCardNumber /= 10;
    }
    
    // Build product digit sum
    int productSum = 0;
    for (int product : products) {
        productSum += product;
    }
    
    cout << "Quersumme: " << productSum << endl;
    
    // Modulo of sum
    int sumModulo = productSum % 10;
    cout << "Summe mod 10: " << sumModulo << endl;
    
    // Difference of modulo and 10
    int diff = 10 - sumModulo;
    cout << "Differenz: " << diff << endl;

    // If digit is limit (10), its zero
    int checkDigit = diff == 10 ? 0 : diff;
    cout << "Pruefziffer: " << checkDigit << endl;

    return checkDigit;
}

int main()
{
    string input;
    
    // while user does not provide "Quit" as input
    while(true)
    {
        //4509472140549006
        cout << "Eingabe der Kreditkartennummer ('Quit' zum Beenden):" << endl;
        
        // Read in input from console
        cin >> input;
        
        // Check input for breaking while loop
        if(input == "Quit") {
            break;
        }
        
        std::string const& str = input;
        char * endp;
        
        // Parse credit card number from input temp reference to proceed
        unsigned long creditCardNumber = strtoul(str.c_str(), &endp, 0);
        
        // If there is a valid number
        if(str.c_str() != endp) {
            cout << "Eingabe: " << input << endl;
            cout << "Pruefe: " << input.substr(0, input.length() - 1) << "x" << endl;
            
            // Get check digit for number
            int checkDigit = pap(creditCardNumber);
            
            // Check last digit of number for equality with check digit
            if(checkDigit == creditCardNumber % 10) {
                cout << "Die eingegebene Kreditkartennummer war korrekt." << endl;
            } else {
                cout << "Die eingegebene Kreditkartennummer war nicht korrekt." << endl;
            }
        } else {
            cout << "Eingabe war fehlerhaft!" << endl;
        }
        
        cout << "--------------------------------------------------------" << endl;
    }
    
    return 0;
}

