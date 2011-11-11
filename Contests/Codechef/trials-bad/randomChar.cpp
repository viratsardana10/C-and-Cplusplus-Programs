#include <cstdlib> // rand()
#include <cstring>

char* randomString(int length, bool letters, bool numbers, bool symbols) 
{
    // the shortest way to do this is to create a string, containing
    // all possible values. Then, simply add a random value from that string
    // to our return value
    char allPossible[26]=""; // this will contain all necessary characters
    char str[length+1]=""; // the random string
    if (letters == true) { // if you passed true for letters, we'll add letters to the possibilities
        for (int i = 65; i <= 90; i++) {
            strcat(allPossible,static_cast<char>(i));
        //    allPossible += static_cast<char>(i+32); // add a lower case letter, too!
        } /*
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
    }*/
    // get the number of characters to use (used for rand())
    int numberOfPossibilities = strlen(allPossible);
    for (int i = 0; i < length; i++) {
          strcat(str,allPossible[rand() % numberOfPossibilities]);
    }
    str[length]='\0';

    return str;
}

