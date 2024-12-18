#include <stdio.h>
#include <time.h>

// Function to check if a year is a leap year
int isLeapYear(int year) {
    // A year is a leap year if it's divisible by 4 but not 100, unless it's also divisible by 400.
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        return 1;
    }
    return 0;
}

// Function to get the number of days in a month
int daysInMonth(int month, int year) {
    int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    // Check for February in a leap year
    if (month == 2 && isLeapYear(year)) {
        return 29;
    }

    return days[month - 1]; // month is 1-indexed, so we subtract 1
}

int main() {
    int day, month, year;
    time_t t = time(NULL);
    struct tm currentTime = *localtime(&t);

    // Prompt for date of birth
    printf("Enter your date of birth (DD/MM/YYYY): ");
    scanf("%d/%d/%d", &day, &month, &year);

    // Validate the input date
    if (month < 1 || month > 12 || day < 1 || day > daysInMonth(month, year)) {
        printf("Invalid date entered.\n");
        return 1;
    }

    // Print current date
    printf("Current Date: %d/%d/%d\n", currentTime.tm_mday, currentTime.tm_mon + 1, currentTime.tm_year + 1900);

    // Calculate age
    int ageYears = currentTime.tm_year + 1900 - year;
    int ageMonths = currentTime.tm_mon + 1 - month;
    int ageDays = currentTime.tm_mday - day;

    // Adjust for negative months or days
    if (ageDays < 0) {
        ageMonths--;
        ageDays += daysInMonth(currentTime.tm_mon + 1, currentTime.tm_year + 1900);
    }

    if (ageMonths < 0) {
        ageYears--;
        ageMonths += 12;
    }

    // Print the calculated age
    printf("\nYou are %d years, %d months, and %d days old.\n", ageYears, ageMonths, ageDays);

    return 0;
}
