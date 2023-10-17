#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdio.h>
#include <string.h>
#include "millis.h"
#include "lcd.h"
#include "uart.h"
#include "ESP8266.h"

#define BIT_SET(a, b) ((a) |= (1ULL << (b)))
#define BIT_CLEAR(a,b) ((a) &= ~(1ULL<<(b)))
#define BIT_FLIP(a,b) ((a) ^= (1ULL<<(b)))
#define BIT_CHECK(a,b) (!!((a) & (1ULL<<(b)))) 

#define Set_Button_As_Input_Pullup(ddr,pdr,pin) BIT_CLEAR(ddr,pin);BIT_SET(pdr,pin);
#define Button_Is_Clicked(pinr,pin) !BIT_CHECK(pinr,pin)


// B (digital pin 8 to 13)
// C (analog input pins)
// D (digital pins 0 to 7)
// https://wokwi.com/projects/365067824797777921


#define BUTTON_PIN_1 0
#define BUTTON_PIN_2 1
#define BUTTON_PIN_3 2



void lcd_setup(){
    lcd_clear();
    lcd_set_cursor(0, 0);

    lcd_puts("<--Starting Up-->");
    _delay_ms(1000);
}

void lcd_question(){
    lcd_clear();
    lcd_set_cursor(0, 0);
    lcd_puts("How was Class");
    lcd_set_cursor(0, 1);
    lcd_puts("today?");
}

void HandleButtonClick(int status){
    _delay_ms(200);
    lcd_clear();
    lcd_set_cursor(0, 0);

    switch (status)
    {
    case 3:
        lcd_puts("GOOD!");
        addData("field1", 3);
        break;
    case 2:
        lcd_puts("OKAY!");
        addData("field1", 2);
        break;
    case 1:
        lcd_puts("BAD!");
        addData("field1", 1);
        break;
    default:
        lcd_puts("ERROR!");
        break;
    }

    pushData();
    lcd_question();
}



int main(void)
{
    millis_init();
    sei();

    lcd_init();
    lcd_enable_blinking();
    lcd_enable_cursor();
    _delay_ms(1000);

    init_serial();
    ESPinit();

    Set_Button_As_Input_Pullup(DDRB, PORTB, BUTTON_PIN_1);
    Set_Button_As_Input_Pullup(DDRB, PORTB, BUTTON_PIN_2);
    Set_Button_As_Input_Pullup(DDRB, PORTB, BUTTON_PIN_3);

    lcd_setup();
    lcd_question();

    while(1) {
        if(Button_Is_Clicked(PINB,BUTTON_PIN_1)) HandleButtonClick(1);
        if(Button_Is_Clicked(PINB,BUTTON_PIN_2)) HandleButtonClick(2);
        if(Button_Is_Clicked(PINB,BUTTON_PIN_3)) HandleButtonClick(3);
    }
    return 0;
}