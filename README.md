# Project_Electronics_Two-wheel-robot-base-use-of-a-variable-resistance

Motor drive design and implementation for two-wheel robot base With the use of a variable resistance and pushbuttonto control the direction.

We'll be looking at how to power and drive a DC motor Or Hobby Geamotor with an L293D(H brageI298) and an Arduino,but you can use any Arduino that provides enough voltage for your motor, and has 2 digital output pins).

The L293D is a 16-pin Motor Driver IC which can control up to two DC motors Or Hobby Geamotor simultaneously.

# Component:
 Arduino Uno R3.
 
 Breadboard.
 
 Wires.
 
 H-bridge Motor Driver.
 
 250 kΩ Potentiometer.
 
 1 kΩ Resistor.
 
 Pushbutton.
 
 12v , 5 Power Supply.
 
 Voltage Multimeter.
 
 Motor R & L 2	Hobby Gearmotor.
 
 #  Connecting the components:
 
 First, let's hook up the components on the breadboard. Below you'll see a pin diagram of the L293D - note the location of each of the pins, relative to the notch at the top.
 
 https://www.ti.com/lit/ds/symlink/l293.pdf
 
 ![123439480-78ba6380-d5da-11eb-83e0-5c08f576a341](https://user-images.githubusercontent.com/56201060/123637340-924feb00-d826-11eb-852c-100334ccaf59.png)


#  Circuit connection steps:

Step_1, Connect ground and power Supply (12v) Breadboard then L293D.

Step_2, Connect the H-bridge pins Enable 1 & 2 to digtal(pwm) in arduino pin 8 .

Step_3, Connect the H-bridge pins Enable 3 & 4 to digtal(pwm) in arduino pin 9 .

Step_4, Connect the H-bridge pins input 1 & 2 to digtal(pwm) in arduino pin 6 & 7 .

Step_5, Connect the H-bridge pins input 3 & 4 to digtal(pwm) in arduino pin 2 & 3 .

Step_6, Connect the H-bridge pins Output 1 & 2 to Hobby Gearmotor Or DC Motor(Left) Terminal 1 & 2 .

Step_7, Connect the H-bridge pins Output 3 & 4 to Hobby Gearmotor Or DC Motor(Right) Terminal 1 & 2 .

Step_8, Connect the pontentiometer wiper in the middle to AnalogIn in arduino pin A0 .

Step_9, Connect the pontentiometer Terminal 1 to  Termina la in pushbutton .

Step_10, Connect the pontentiometer Terminal 2 to  (before the resistance) Termina 2a in pushbutton .

Step_11, Connect the pushbutton Terminal 2b to  digtal(pwm) in arduino pin 4 .

Step_12, Connect the pushbutton Terminal 2a to  resistance And the other side ground .

See the picture:

![Motor drive design With the use of a variable resistance](https://user-images.githubusercontent.com/56201060/123640484-e3151300-d829-11eb-858d-683b6be6bdda.png)


#  Code:

// Arduino DC Motor Or Hobby Gearmotor Control - PWM | H-Bridge | L298N
 //   by Dejan Eng.Odai Farhat .

#define enA 8     //EN 1 & 2 
#define in1 6     //input 1
#define in2 7     //input 2
#define enB 9     //EN 3 & 4 
#define in3 2     //input 3
#define in4 3     //input 4
#define button 4  //pushbutton  pin 4

int rotDirection = 0;
int pressed = false;

void setup() 

{
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(button, INPUT);
  
  // Set initial rotation direction.
  
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  
}
void loop()

{
  int potValue = analogRead(A0); // Read potentiometer value.
  int pwmOutput = map(potValue, 0, 1023, 0 , 255); // Map the potentiometer value from 0 to 255.
  analogWrite(enA, pwmOutput);  // Send PWM signal to L298N Enable pin 8.
  analogWrite(enB, pwmOutput);  // Send PWM signal to L298N Enable pin 9.
  // Read button - Debounce
  if (digitalRead(button) == true) {
    pressed = !pressed;
  }
  while (digitalRead(button) == true);
  delay(20);
  // If button is pressed - change rotation direction.
  if (pressed == true  & rotDirection == 0) {
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    rotDirection = 1;
    delay(20);
  }
  
   // If button is pressed - change rotation direction.
  
  if (pressed == false & rotDirection == 1) {
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    rotDirection = 0;
    delay(20);
  }
}
