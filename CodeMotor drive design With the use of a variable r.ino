// Arduino DC Motor Or Hobby Gearmotor Control - PWM | H-Bridge | L298N
 //   by Dejan Eng.Odai Farhat>

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
