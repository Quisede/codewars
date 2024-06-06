// ATM machines allow 4 or 6 digit PIN codes and PIN codes cannot contain anything but exactly 4 digits or exactly 6 digits.

// If the function is passed a valid PIN string, return true, else return false.

// Examples (Input --> Output)

// "1234"   -->  true
// "12345"  -->  false
// "a234"   -->  false
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

bool validate_pin(const char *pin) {
    int len = strlen(pin);
    if (len != 4 && len != 6) {
        return false;
    }

    for (int i = 0; i < len; i++) {
        if (pin[i] < '0' || pin[i] > '9') {
            return false;
        }
    }

    return true;
}