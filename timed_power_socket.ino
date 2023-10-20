/*
 * Created by Adriano Parracciani
 Timed power socket 
 */
 
int relayState=0;
const int timer=240000; //set timer to 4 min in milisec (60sec*4min*1000)
const int BUTTON_PIN = 7; // Arduino pin connected to button's pin
const int RELAY_PIN  = 3; // Arduino pin connected to relay's pin
const int LED_PIN=13; //LED to pin 13

void setup() {
  Serial.begin(9600);                // initialize serial
  pinMode(BUTTON_PIN,INPUT); // set arduino pin to input mode
  pinMode(RELAY_PIN, OUTPUT);        // set arduino pin to output mode
  pinMode(LED_PIN, OUTPUT);        // set arduino pin to output mode
  digitalWrite(RELAY_PIN, HIGH); // set arduino pin to high
   digitalWrite(LED_PIN, LOW); // set arduino pin to low
  
}

void loop() {

  
  int buttonState = digitalRead(BUTTON_PIN); // read butto_pin state
//Serial.println(buttonState);

  if (buttonState == HIGH) {
    relayState=1;
  }
  if (relayState ==1) {
    //Serial.println("The button is being pressed");
     digitalWrite(RELAY_PIN, LOW); // relay Closed
     digitalWrite(LED_PIN, HIGH); // turn LED on
     
    delay(timer); //wait time set in timer then open the relay and turn the led off
    digitalWrite(RELAY_PIN, HIGH); // relay Opened
    digitalWrite(LED_PIN, LOW); // turn LED OFF
    relayState=0;
    delay(50);
  
  
  }

      }
    
