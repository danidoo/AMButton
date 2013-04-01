About AMButton
==============

AMButton is derived from Analog Multi-Button, it's a library to detect
button press events on a setup where multiple buttons are connected
to a single Arduino analog pin.

I've developed this library to abstract the button handling on a 
personal project and decided to share. I'm not actively maintaining, 
enhancing or giving support to it, but it's open source, use at your
will. I'm not going to be liable for any damage you may cause.

Using AMButton
==============

To use AMButton you should:

* Connect the buttons following the diagram on:
   http://rayshobby.blogspot.com.br/2010/08/multiple-button-inputs-using-arduino.html

* Include the library on your software.

* Initialize the AMButton class with the apropriate parameters:
  AMButton(pin_number, number_of_buttons_connected, long_press_duration, callback_function)

* Place the button.Read() fuction on your loop to constantly scan the pin for pressed buttons.

* Develop your Callback function to deal with the button pressing events:
  button_callback(button_pressed, action_taken)
  Where action can be: PRESS, RELEASE or LONGPRESS

Getting AMButton
================

AMButton will be available at:

   https://github.com/danidoo/AMButton

