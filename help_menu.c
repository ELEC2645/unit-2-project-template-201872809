#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include "tools.h"


void help_item_1(void);
void print_help_menu(void);
int select_help_item(int input);






int select_help_item(int input)
{
    switch (input) {
        case 1:
            help_item_1();
            go_back_to_main();
            return false;
        
        default:
            return true;
    }
}


void print_help_menu(void) {
    printf("\n----------- Help menu -----------\n");
    printf("\n"
           "\t\t\t\t\t\t\n"
           "\t1. Menu item 1\t\t\n"
           "\t5. Exit to main menu\t\t\t\t\n"
           "\t\t\t\t\t\t\n");
    printf("---------------------------------------------\n");

}

void help_item_1(void) {
    printf("heres your help");
}