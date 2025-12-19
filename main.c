// ELEC2645 Unit 2 Project Template
// Command Line Application Menu Handling Code

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdbool.h>

#include "tools.h"
#include "funcs.h"
#include "help_menu.h"

#define MENU_OPTIONS 6

/* Prototypes mirroring the C++ version */
int main(void);
static void main_menu(void);            /* runs in the main loop */
static void select_menu_item(int input);
void print_main_menu(void);


int main(void)
{
    /* this will run forever until we call exit(0) in select_menu_item() */
    for(;;) {
        main_menu();
    }
    /* not reached */
    return 0;
}

static void main_menu(void)
{
    print_main_menu();
    {
        int input = get_menu_choice(MENU_OPTIONS);
        select_menu_item(input);
    }
}


static void select_menu_item(int input)
{
    switch (input) {
        case 1:
            adc_menu();
            go_back_to_main();
            break;
        case 2:
            menu_item_2();
            go_back_to_main();
            break;
        case 3:
            menu_item_3();
            go_back_to_main();
            break;
        case 4:
            menu_item_4();
            go_back_to_main();
            break;
        case 5:
            help_menu();
            break;
        default:
            printf("Bye!\n");
            exit(0);
    }
}


void print_main_menu(void)
{
    printf("\n----------- Main menu -----------\n");
    printf("\n"
           "\t\t\t\t\t\t\n"
           "\t1. Analogue to Digital Converter\t\t\n"
           "\t2. Menu item 2\t\t\n"
           "\t3. Menu item 3\t\t\n"
           "\t4. Menu item 4\t\t\n"
           "\n5. Help Menu \t\t\n"
           "\t6. Exit\t\t\t\t\n"
           "\t\t\t\t\t\t\n");
    printf("---------------------------------------------\n");
}

