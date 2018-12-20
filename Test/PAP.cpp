
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

const int CREDIT_CARD_NUMBERS = 16;

int pap(unsigned long creditCardNumber) {
    cout << "Nr." << "  " << "Gew." << "  " << "Prod." << endl;
    
    //Holder for the products
    int products[CREDIT_CARD_NUMBERS];
    
    //While there is a rest of credit card number, take i as indicator for factoring
    for(int i = 0; i < CREDIT_CARD_NUMBERS; i++) {
        int digit = creditCardNumber % 10;
        
        int product = 0;
        
        // Take rest of module (0 or 1) + 1 for factor
        int factor = i % 2 + 1;
        
        // First digit is checked digit, so skip that
        if(i == 0) {
            cout << "P" << "    " << factor << "     " << "-" << endl;
        } else {
            // Multiply digit
            product = digit * factor;
            
            cout << digit << "    " << factor << "     " << product << endl;

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
        }
        
        //Store product in holder
        products[i] = product;
        
        //Go further with divided credit card number
        creditCardNumber /= 10;
    }
    
    // Build product digit sum
    int productSum = 0;
    for (int i= 0; i < CREDIT_CARD_NUMBERS; i++) {
        productSum += products[i];
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
        //5486965694025434
        cout << "Eingabe der Kreditkartennummer ('Quit' zum Beenden):" << endl;
        
        // Read in input from console
        cin >> input;
        
        cout << "Eingabe: " << input << endl;
        
        // Check input for breaking while loop
        if(input == "Quit") {
            break;
        }
        
        // Parse credit card number from input temp reference to proceed
        unsigned long creditCardNumber;
        stringstream(input) >> creditCardNumber;
        
        cout << "Pruefe: " << creditCardNumber / 10 << "x" << endl;
        
        // Get check digit for number
        int checkDigit = pap(creditCardNumber);
        
        // Check last digit of number for equality with check digit
        if(checkDigit == creditCardNumber % 10) {
            cout << "Die eingegebene Kreditkartennummer war korrekt." << endl;
        } else {
            cout << "Die eingegebene Kreditkartennummer war nicht korrekt." << endl;
        }
        
        cout << "--------------------------------------------------------" << endl;
    }
    
    return 0;
}

