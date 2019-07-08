int const trigPin1 = 6;
int const echoPin1 = 7;
int const trigPin2 = 8;
int const echoPin2 = 9;
int const redled1 = 4;
int const greenled1 = 5;
int const redled2 = 12;
int const greenled2 = 11;
//int const buzzPin = 2;

void setup()
{
  Serial.begin(9600);
  pinMode(trigPin1, OUTPUT); // trig pin will have pulses output
  pinMode(echoPin1, INPUT); // echo pin should be input to get pulse width
  pinMode(trigPin2, OUTPUT); // trig pin will have pulses output
  pinMode(echoPin2, INPUT); // echo pin should be input to get pulse width
  pinMode(redled1,OUTPUT);
  pinMode(greenled1,OUTPUT);
 // pinMode(buzzPin, OUTPUT); // buzz pin is output to control buzzering
  //pinMode(LED_BUILTIN, OUTPUT);
}

void loop()
{
  // Duration will be the input pulse width and distance will be the distance to the obstacle in centimeters
  int duration1, distance1,duration2, distance2;
  // Output pulse with 1ms width on trigPin
  digitalWrite(trigPin1, HIGH); 
  delay(1);
  digitalWrite(trigPin1, LOW);
  // Measure the pulse input in echo pin
  duration1 = pulseIn(echoPin1, HIGH);
  // Distance is half the duration devided by 29.1 (from datasheet)
  distance1 = (duration1/2) / 29.1;
  Serial.println(distance1);
  // if distance less than 0.5 meter and more than 0 (0 or less means over range) 
    if (distance1 <= 50 && distance1 >= 0  ) {
      // Buzz
      digitalWrite(redled1, HIGH);
      digitalWrite(greenled1, LOW);
    } else {
      // Don't buzz
      digitalWrite(greenled1, HIGH);
      digitalWrite(redled1, LOW);
      
    }
    // Waiting 60 ms won't hurt any one
    delay(60);

    
  digitalWrite(trigPin2, HIGH);
  delay(1);
  digitalWrite(trigPin2, LOW);
  // Measure the pulse input in echo pin
  duration2 = pulseIn(echoPin2, HIGH);
  // Distance is half the duration devided by 29.1 (from datasheet)
  distance2 = (duration2/2) / 29.1;
  Serial.println(distance2);
  // if distance less than 0.5 meter and more than 0 (0 or less means over range) 
    if (distance2 <= 50 && distance2 >= 0  ) {
      // Buzz
      digitalWrite(redled2, HIGH);
      digitalWrite(greenled2, LOW);
    } else {
      // Don't buzz
      digitalWrite(greenled2, HIGH);
      digitalWrite(redled2, LOW);
      
    }
    // Waiting 60 ms won't hurt any one
    delay(60);

}
    
