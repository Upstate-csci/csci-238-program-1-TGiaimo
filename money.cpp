/********
 Author: Thomas Giaimo
 Program: Money class - program assignment #1
 Due Date: 2/3/2020
 Purpose:
 ********/
#include "money.h"
#include <string>

// convert current currency values to a string
string Money::toString() {
    stringstream output;
    output << hundreds << " hundreds " << tens << " tens " << fives << " fives " << ones << " ones " << quarters << " quarters " << dimes << " dimes " << nickels << " nickels " << cents << " pennies ";
    return output.str();
}

// format amount as a local currency and return
string Money::toCurrency(double amount) {

    stringstream ss;
    ss.imbue(locale(""));

    ss << showbase << put_money(amount*100);

    return ss.str();

}

// convert currency to float
// read currency values from stdin and compute value
// return results
string Money::processChange() {
    float total;
    cin >> hundreds >> tens >> fives >> ones >> quarters >> dimes >> nickels >> cents;
    total = (hundreds * 100) + (tens * 10) + (fives * 5) + (ones * 1) + (quarters * .25) + (dimes * .10) + (nickels * .05) + (cents * .01);
    stringstream output;
    output << toString() << "= " << toCurrency(total);
    return output.str();
}

// read from stdin and process float command
// convert float to change
// return results
string Money::processFloat() {
    float amount, placeholder;
    cin >> amount;
    placeholder = amount; //placeholder value for math
    placeholder*=100; //multiplying input by 100 so we don't have to deal with floating pt. rounding

    hundreds = (placeholder/10000); //getting value of each, then subtracting that from the total amount
    placeholder -= (hundreds*10000);
    tens = (placeholder/1000);
    placeholder -= (tens*1000);
    fives = (placeholder/500);
    placeholder -= (fives*500);
    ones = (placeholder/100);
    placeholder -= (ones*100);
    quarters = (placeholder/25);
    placeholder -= (quarters*25);
    dimes = (placeholder/10);
    placeholder -= (dimes*10);
    nickels = (placeholder/5);
    placeholder -= (nickels*5);
    cents = (placeholder/1);
    placeholder -= (cents*1);

    stringstream output;
    output << toCurrency(amount) << " = " << toString() << endl;
    return output.str();
}

// read from stdin and process check command
// convert float to dollar words & cents
// return results
string Money::processCheck() {
    float amount, changeAmount;
    cin >> amount;
    changeAmount = amount*100; //placeholder value for calculations

    ones = (changeAmount/100);
    changeAmount -= (ones*100);
    cents = (changeAmount/1);
    changeAmount -= (cents*1);

    stringstream output;
    output << "check for " << toCurrency(amount) << " = " << ones << " dollars and " << cents << " cents" << endl;

    return output.str();
}

// read from stdin and process change-float command
// read float of customer payment
// read float of transaction cost
// calculate difference and compute change values
// return the results
string Money::processChangeFloat() {
    float totalPaid, totalPurchased, totalChange, placeholder;

    cin >> totalPaid >> totalPurchased;
    totalChange = totalPaid - totalPurchased;
    placeholder = totalChange; //placeholder value for math
    placeholder*=100; //multiplying input by 100 so we don't have to deal with floating pt. rounding

    hundreds = (placeholder/10000); //getting value of each, then subtracting that from the total amount
    placeholder -= (hundreds*10000);
    tens = (placeholder/1000);
    placeholder -= (tens*1000);
    fives = (placeholder/500);
    placeholder -= (fives*500);
    ones = (placeholder/100);
    placeholder -= (ones*100);
    quarters = (placeholder/25);
    placeholder -= (quarters*25);
    dimes = (placeholder/10);
    placeholder -= (dimes*10);
    nickels = (placeholder/5);
    placeholder -= (nickels*5);
    cents = (placeholder/1);
    placeholder -= (cents*1);

    stringstream output;
    output << "change back on " << toCurrency(totalPaid) << " for purchase of " << toCurrency(totalPurchased) << " is " << toCurrency(totalChange) << " which is " << toString() << endl;
    return output.str();
}

// read from stdin and process change-change command
// read change of customer payment
// read float of transaction cost
// calculate difference and compute change values
// output the results
string Money::processChangeChange() {
    float totalPurchased, totalChange, placeholder;
    string totalOutput, changeOutput;
    cin >> hundreds >> tens >> fives >> ones >> quarters >> dimes >> nickels >> cents >> totalPurchased;
    totalOutput = toString();
    total = (hundreds * 100) + (tens * 10) + (fives * 5) + (ones * 1) + (quarters * .25) + (dimes * .10) + (nickels * .05) + (cents * .01);
    totalChange = total - totalPurchased;
    placeholder = totalChange*100;
    hundreds = 0;
    tens = 0;
    fives = 0;
    ones = 0;
    quarters = 0;
    dimes = 0;
    nickels = 0;
    cents = 0;
    hundreds = (placeholder/10000); //getting value of each, then subtracting that from the total amount
    placeholder -= (hundreds*10000);
    tens = (placeholder/1000);
    placeholder -= (tens*1000);
    fives = (placeholder/500);
    placeholder -= (fives*500);
    ones = (placeholder/100);
    placeholder -= (ones*100);
    quarters = (placeholder/25);
    placeholder -= (quarters*25);
    dimes = (placeholder/10);
    placeholder -= (dimes*10);
    nickels = (placeholder/5);
    placeholder -= (nickels*5);
    cents = (placeholder/1);
    placeholder -= (cents*1);

    stringstream output;
    output << "change back on " << totalOutput << "for purchase of " << toCurrency(totalPurchased) << " is " << toCurrency(totalChange) << " which is " << toString() << endl;
    return output.str();
}
