/*
 * A method to generate a random string in C++
 * Author: Danny Battison
 * Contact: gabehabe@googlemail.com
 */

#include <cstdlib> // rand()
#include <string>

std::string randomString(int length, bool letters, bool numbers, bool symbols) {
    // the shortest way to do this is to create a string, containing
    // all possible values. Then, simply add a random value from that string
    // to our return value
    std::string allPossible; // this will contain all necessary characters
    std::string str; // the random string
    if (letters == true) { // if you passed true for letters, we'll add letters to the possibilities
        for (int i = 65; i <= 90; i++) {
            allPossible += static_cast<char>(i);
        //    allPossible += static_cast<char>(i+32); // add a lower case letter, too!
        }
    } if (numbers == true) { // if you wanted numbers, we'll add numbers
        for (int i = 48; i <= 57; i++) {
            allPossible += static_cast<char>(i);
        }
    } if (symbols == true) { // if you want symbols, we'll add symbols (note, their ASCII values are scattered)
        for (int i = 33; i <= 47; i++) {
            allPossible += static_cast<char>(i);
        } for (int i = 58; i <= 64; i++) {
            allPossible += static_cast<char>(i);
        } for (int i = 91; i <= 96; i++) {
            allPossible += static_cast<char>(i);
        } for (int i = 123; i <= 126; i++) {
            allPossible += static_cast<char>(i);
        }
    }
    // get the number of characters to use (used for rand())
    int numberOfPossibilities = allPossible.length();
    for (int i = 0; i < length; i++) {
        str += allPossible[rand() % numberOfPossibilities];
    }

    return str;
}

/** EXAMPLE USAGE **
#include <iostream>
#include <ctime>
using namespace std;

int main ()
{
    srand(time(NULL)); // only seed the random generator once!
    cout //<< //"A string made up of symbols: " << randomString(10, false, false, true) << endl
         << "A string made up of characters: " << randomString(1000, true, false, false) << endl;
      //   << "A string made up of numbers: " << randomString(10, false, true, false) << endl
       //  << "A totally random string: " << randomString(10, true, true, true);

    cin.get(); // pause
    return EXIT_SUCCESS; // successful execution
}
*/
