#include <mega32.h>
#include <delay.h>
#include <alcd.h>

interrupt [EXT_INT0] void ext_int0_isr(void)
{   
    #asm("sei")
    
    lcd_init(16);
    
    DDRB.3=1; 
    PORTA.0=1;
    PORTA.1=0;

    TCCR0=(1<<WGM00) | (1<<COM01) | (0<<COM00) | (1<<WGM01) | (1<<CS02) | (0<<CS01) | (1<<CS00); 
    
    OCR0=76;// almost 30% duty cycle (actual 0CR0=76.8)
    lcd_puts("OCR0=76  30%    Duty Cycle");
    lcd_gotoxy(0,0); 
    delay_ms (5000);
            
    OCR0=102;// almost 40% duty cycle (actual 0CR0=102.4)
    lcd_puts("OCR0=102 40%    Duty Cycle");
    lcd_gotoxy(0,0);
    delay_ms (5000);
    
    OCR0=128; // exact 50% duty cycle
    lcd_puts("OCR0=128 50%    Duty Cycle");
    lcd_gotoxy(0,0);
    delay_ms (5000); 
            
    OCR0=153;// almost 60% duty cycle (actual 0CR0=153.6)
    lcd_puts("OCR0=153 60%    Duty Cycle");
    lcd_gotoxy(0,0);
    delay_ms (5000); 
    
    OCR0=179;// almost 70% duty cycle (actual 0CR0=179.2)
    lcd_puts("OCR0=179 70%    Duty Cycle");
    lcd_gotoxy(0,0);
    delay_ms (5000);
    
    OCR0=204;// almost 80% duty cycle (actual 0CR0=204.8)
    lcd_puts("OCR0=204 80%    Duty Cycle");
    lcd_gotoxy(0,0);
    delay_ms (5000); 
    
    OCR0=230;// almost 90% duty cycle (actual 0CR0=230.4)
    lcd_puts("OCR0=230 90%    Duty Cycle");
    lcd_gotoxy(0,0);
    delay_ms (5000);
            
    OCR0=253;// almost 99% duty cycle (actual 0CR0=253.44)
    lcd_puts("OCR0=253 99%    Duty Cycle");
    lcd_gotoxy(0,0);
}


interrupt [EXT_INT1] void ext_int1_isr(void)
{
    #asm("sei")

    lcd_init(16); 
    
    DDRB.3=1; 
    PORTA.0=1;
    PORTA.1=0;

    TCCR0=(1<<WGM00) | (1<<COM01) | (0<<COM00) | (1<<WGM01) | (1<<CS02) | (0<<CS01) | (1<<CS00); 
            
    OCR0=230;// almost 90% duty cycle (actual 0CR0=230.4)
    lcd_puts("OCR0=230 90%    Duty Cycle");
    lcd_gotoxy(0,0);
    delay_ms (5000); 
            
    OCR0=204;// almost 80% duty cycle (actual 0CR0=204.8)
    lcd_puts("OCR0=204 80%    Duty Cycle");
    lcd_gotoxy(0,0);
    delay_ms (5000); 
            
    OCR0=179;// almost 70% duty cycle (actual 0CR0=179.2)
    lcd_puts("OCR0=179 70%    Duty Cycle");
    lcd_gotoxy(0,0);
    delay_ms (5000);
    
    OCR0=153;// almost 60% duty cycle (actual 0CR0=153.6)
    lcd_puts("OCR0=153 60%    Duty Cycle");
    lcd_gotoxy(0,0);
    delay_ms (5000); 
    
    OCR0=128; // exact 50% duty cycle
    lcd_puts("OCR0=128 50%    Duty Cycle");
    lcd_gotoxy(0,0);
    delay_ms (5000);
    
    OCR0=102;// almost 40% duty cycle (actual 0CR0=102.4)
    lcd_puts("OCR0=102 40%    Duty Cycle");
    lcd_gotoxy(0,0);
    delay_ms (5000); 
    
    OCR0=76;// almost 30% duty cycle (actual 0CR0=76.8)
    lcd_puts("OCR0=76  30%    Duty Cycle");
    lcd_gotoxy(0,0); 
    delay_ms (5000); 
    
    OCR0=51;// almost 20% duty cycle (actual 0CR0=51.2)
    lcd_puts("OCR0=51  20%    Duty Cycle");
    lcd_gotoxy(0,0);
}

void main(void)
{
    DDRA=0xFF;
    PORTA=0x00;

    GICR=(1<<INT1) | (1<<INT0) | (0<<INT2);
    MCUCR=(1<<ISC11) | (0<<ISC10) | (1<<ISC01) | (0<<ISC00);


    #asm("sei")

    while (1);
}