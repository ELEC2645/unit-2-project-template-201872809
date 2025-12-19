#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdbool.h>

#include "help_menu.h"
#include "tools.h"

#define MAX_MAX_V 1000.0
#define MENU_OPTIONS 6


void adc_menu(void) {
    printf("\n>> Analogue to Digital converter\n");
    printf("\nPlease enter the maximum voltage");
    double maxVoltage = get_float_input(MAX_MAX_V);
    printf("\nPlease enter the reading");
    double reading = get_float_input(maxVoltage);

    printf("\nYour digital reading is: %d", adc(reading, maxVoltage));

}

void menu_item_2(void) {
    printf("\n>> Menu 2\n");
    printf("\nSome code here does something useful\n");
    /* you can call a function from here that handles menu 2 */
}

void menu_item_3(void) {
    printf("\n>> Menu 3\n");
    printf("\nSome code here does something useful\n");
    /* you can call a function from here that handles menu 3 */
}

void menu_item_4(void) {
    printf("\n>> Menu 4\n");
    printf("\nSome code here does something useful\n");
    /* you can call a function from here that handles menu 4 */
}



void help_menu(void)
{
    bool back = false;
    while (back == false) {
        print_help_menu();
        int input = get_menu_choice(MENU_OPTIONS);
        back = select_help_item(input);
    
    }
}