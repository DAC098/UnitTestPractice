#include "Password.h"
#include <string>
#include <iostream>

using std::string;

/*
  The function receives a string counts how many times the same character 
  occurs at the beginning of the string, before any other characters (or the
  end of the string). The function is case-sensitive so 'Z' is different than
  'z' and any ASCII characters are allowed.
*/
int Password::count_leading_characters(string phrase){
    if (phrase.length() == 0) {
        return 0;
    }

    int repetition = 1;
    int index = 0;

    while(index < phrase.length() - 1 && phrase[index] == phrase[index + 1] ){
        repetition++;
        index++;
    }

    return repetition;
}


/*
  receives a string and returns whether it has both at least one upper-case
  letter and at least one lower-case letter
*/
bool Password::has_mixed_case(string pass){
    if (pass.length() < 2) {
        return false;
    }

    bool found_lower = false;
    bool found_upper = false;

    for (std::size_t index = 0; index < pass.length(); index += 1) {
        if (pass[index] >= 'a' && pass[index] <= 'z') {
            found_lower = true;
        } else if (pass[index] >= 'A' && pass[index] <= 'Z') {
            found_upper = true;
        }

        if (found_lower && found_upper) {
            break;
        }
    }

    return found_lower && found_upper;
}
