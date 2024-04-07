# Stop Watch System 
1. Used ATmega32 Microcontroller with frequency 8Mhz.
2. Configure Timer1 in ATmega32 with CTC mode to count the Stop Watch time.
3. Used six Common Anode 7-segments.
4. Connect the six 7-segments in the project using the multiplexed technique.
5. Connect 7447 decoder 4-pins to the first 4-pins in PORTC.
6. Used first 6-pins in PORTA as the enable/disable pins for the six 7-segments.
7. Stop Watch counting should start once the power is connected to the MCU.
8. Configure External Interrupt INT0 with falling edge. Connect a push button with the
   internal pull-up resistor. If a falling edge detected the Stop Watch time should be
   reset.
9. Configure External Interrupt INT1 with rising edge. Connect a push button with the
   external pull-down resistor. If a raising edge detected the Stop Watch time should be
   paused.
10. Configure External Interrupt INT2 with falling edge. Connect a push button with the
    internal pull-up resistor. If a falling edge detected the Stop Watch time should be
    resumed.
