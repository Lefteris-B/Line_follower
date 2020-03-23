int ENA = 3; //Δεξιοί κινητήρες
int IN1 = 1; 
int IN2 = 2;

int ENB = 6; //Αριστεροί κινητήρες
int IN3 = 4;
int IN4 = 5;

//Ταχύτητα Κινητήρων
#define ENASpeed 100 
#define ENBSpeed 100

//Αρχικοποίηση μεταβλητών
int Sensor1 = 0;
int Sensor2 = 0;
int Sensor3 = 0;
int Sensor4 = 0;

void setup() {
//Αρχικοποίηση εισόδων και εξόδων

  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);

  pinMode(ENB, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  pinMode(Sensor1, INPUT);
  pinMode(Sensor2, INPUT);
  pinMode(Sensor3, INPUT);
  pinMode(Sensor4, INPUT);
  
}

void loop(){

  //Ξεκινάει το όχημα στην ταχύτητα που θέσαμε
  analogWrite(ENA, ENASpeed);
  analogWrite(ENB, ENBSpeed);

  //Ανάνωση αισθητήρων
  Sensor1 = digitalRead(8);
  Sensor2 = digitalRead(9);
  Sensor3 = digitalRead(10);
  Sensor4 = digitalRead(11);

  //Θέτουμε προυποθέσεις για κίνηση ΜΠΡΟΣΤΑ,ΔΕΞΙΑ,ΑΡΙΣΤΕΡΑ,ΣΤΑΜΑΤΑ

  if(Sensor4 == HIGH && Sensor3 == HIGH && Sensor2 == LOW && Sensor1 == LOW){
    turn_left();
  }
  
  else if (Sensor4 == LOW && Sensor3 == LOW && Sensor2 == HIGH && Sensor1 == HIGH){
    turn_right();
  }
  
  else if(Sensor4 == LOW && Sensor3 == HIGH && Sensor2 == HIGH && Sensor1 == LOW){
    move_f();
  }
  
  else if (Sensor4 == HIGH && Sensor3 == HIGH && Sensor2 == HIGH && Sensor1 == HIGH){
     stop_m();
  }
}

void stop_m(){    //ΣΤΑΜΑΤΑ
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);

    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW); 
}

void move_f(){    //ΜΠΡΟΣΤΑ
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
}

void turn_right() {    //Turn ΔΕΞΙΑ
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);

    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
}

void turn_left(){    //ΑΡΙΣΤΕΡΑ
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);

    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
}

