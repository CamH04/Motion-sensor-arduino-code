int led = 13;                // pin LED 
int sensor = 2;              // pin sensor 
int state = LOW;             // no motion defualt
int val = 0;                 // current sensor status

void setup() {
  pinMode(led, OUTPUT);      
  pinMode(sensor, INPUT);    
  Serial.begin(9600);        
}

void loop(){
  val = digitalRead(sensor);  
  if (val == HIGH) {           
    digitalWrite(led, HIGH);   
    delay(100);                
    
    if (state == LOW) {
      Serial.println("Motion detected!"); 
      state = HIGH;       // update variable state to HIGH
    }
  } 
  else {
      digitalWrite(led, LOW); // turn LED OFF
      delay(200);            
      
      if (state == HIGH){
        Serial.println("Motion stopped!");
        state = LOW;       //state to low
    }
  }
}
