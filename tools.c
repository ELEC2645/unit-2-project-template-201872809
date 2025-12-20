#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include "tools.h"

#define MAX_ADC 1023

int adc(double reading, int maxVoltage);
int is_integer(const char *s);
int is_float(const char *s);
int get_menu_choice(int menuItems);
void go_back_to_main(void);
float get_float_input(float min_value, float max_value);



void go_back_to_main(void)
{
    char buf[64];
    do {
        printf("\nEnter 'b' or 'B' to go back: ");
        if (!fgets(buf, sizeof(buf), stdin)) {
            puts("\nInput error. Exiting.");
            exit(1);
        }
        buf[strcspn(buf, "\r\n")] = '\0'; /* strip newline */
    } while (!(buf[0] == 'b' || buf[0] == 'B') || buf[1] != '\0');

}



/* Return 1 if s is an optional [+/-] followed by one-or-more digits, else 0. */
int is_integer(const char *s)
{
    if (!s || !*s) return 0;

    /* optional sign */
    if (*s == '+' || *s == '-') s++;

    /* must have at least one digit */
    if (!isdigit((unsigned char)*s)) return 0;

    while (*s) {
        if (!isdigit((unsigned char)*s)) return 0;
        s++;
    }
    return 1;

}

/* Returns 1 if s represents a valid decimal and 0 if not */
int is_float(const char *s)
{
    if (!s || !*s) return 0; /*check pointer isnt null and string isnt empty*/

    char *endptr;
    strtod(s, &endptr);

    return (*endptr == '\0');// checking the end pointer is actually the end not another symblo or letter

}


int get_menu_choice(int menuItems) /**/
{
    char buf[128];
    int valid_input = 0;
    int value = 0;

    do {
        printf("\nSelect item: ");
        if (!fgets(buf, sizeof(buf), stdin)) {
            /* EOF or error; bail out gracefully */
            puts("\nInput error. Exiting.");
            exit(1);
        }

        // strip trailing newline
        buf[strcspn(buf, "\r\n")] = '\0';

        if (!is_integer(buf)) {
            printf("Enter an integer!\n");
            valid_input = 0;
        } else {
            value = (int)strtol(buf, NULL, 10);
            if (value >= 1 && value <= menuItems) {
                valid_input = 1;
            } else {
                printf("Invalid menu item!\n");
                valid_input = 0;
            }
        }
    } while (!valid_input);

    return value;

}


int adc(double reading, int maxVoltage) 
{
    double ratio = reading / maxVoltage;
    return ratio * MAX_ADC;
}


float get_float_input(float min_value, float max_value)
{
    char buf[128];
    int valid_input = 0;
    float value = 0.0f;

    while (!valid_input) {
        printf("\nEnter a value (%.2f - %.2f): ", min_value, max_value);
        if (!fgets(buf, sizeof(buf), stdin)) {
            puts("\nInput error. Exiting.");
            exit(1);
        }

        // strip trailing newline
        buf[strcspn(buf, "\r\n")] = '\0';

        if (!is_float(buf)) {
            printf("Enter a valid number!\n");
            valid_input = 0;
        } else {
            value = strtof(buf, NULL);
            if (value >= min_value && value <= max_value) {
                valid_input = 1;
            } else {
                printf("Value out of range! Must be between 0 and %.2f\n", max_value);
                valid_input = 0;
            }
        }
    }
    return value;

}

