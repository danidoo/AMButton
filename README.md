About AMButton
==============

AMButton is derived from Analog Multi-Button, it's a library to detect
button press events on a setup where multiple buttons are connected
to a single Arduino analog pin.

I have tested this library with 3 buttons only, but it has the potential
of supporting up to 10 buttons (limit coded).

This library does debouncing by checking 3 times for the same value before
"committing" a button event. It includes 3 types of button events: press, 
long press and release.

I've developed this library to abstract the button handling on a 
personal project and decided to share. I'm not actively maintaining, 
enhancing or giving support to it, but it's open source, use at your
will. I'm not going to be liable for any damage you may cause.

Using AMButton
==============

To use AMButton you should follow this steps:

1.  Connect the buttons with equal value resistors following the diagram on:
    http://rayshobby.blogspot.com.br/2010/08/multiple-button-inputs-using-arduino.html

2.  Include the library on your software.

3.  Create a Callback function to deal with the button pressing events:
    ex.: button_callback(button_pressed, action_taken)
    Where action can be: PRESS, RELEASE or LONGPRESS

4.  Initialize the AMButton class with the appropriate parameters:
    AMButton(pin_number, number_of_buttons_connected, long_press_duration, callback_function)

5.  Place the instance.read() function on your loop to constantly scan the pin for pressed buttons.

Getting AMButton
================

AMButton will be available at:

   https://github.com/danidoo/AMButton

