#ifndef TOOLS_H
#define TOOLS_H

int adc(double reading, int maxVoltage);
int  is_integer(const char *s);
int is_float(const char *s);
int get_menu_choice(int menuItems);
void go_back_to_main(void);
float get_float_input(float max_value);


#endif