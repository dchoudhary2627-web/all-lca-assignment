/* Assignment 10: Print month-by-month calendar for a given year */
#include <stdio.h>

/* returns 1 if year is leap year, otherwise 0 */
int isLeap(int year) {
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        return 1;
    return 0;
}

/* returns day of week of 1 January: 0 = Sunday, 1 = Monday ... 6 = Saturday */
int firstDayOfYear(int year) {
    int y = year - 1;
    int days = y * 365 + y / 4 - y / 100 + y / 400;
    return (days + 1) % 7;
}

int main() {
    int year, month, day, startDay, i;
    int daysInMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    char *monthName[12] = {"January", "February", "March", "April", "May", "June",
                           "July", "August", "September", "October", "November", "December"};

    printf("Enter the year: ");
    if (scanf("%d", &year) != 1 || year < 1) {
        printf("Invalid input! Enter a valid year.\n");
        return 1;
    }

    /* February has 29 days in a leap year */
    if (isLeap(year))
        daysInMonth[1] = 29;

    startDay = firstDayOfYear(year);

    printf("\n========== Calendar for %d ==========\n", year);

    for (month = 0; month < 12; month++) {
        printf("\n---------- %s ----------\n", monthName[month]);
        printf(" Su Mo Tu We Th Fr Sa\n");

        /* print blank spaces before the first day */
        for (i = 0; i < startDay; i++)
            printf("   ");

        /* print all days of the month */
        for (day = 1; day <= daysInMonth[month]; day++) {
            printf("%3d", day);
            startDay++;
            if (startDay == 7) {   /* Saturday finished, go to next line */
                printf("\n");
                startDay = 0;
            }
        }
        if (startDay != 0)
            printf("\n");
    }
    return 0;
}