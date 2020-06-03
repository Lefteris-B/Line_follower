int ENA = 11; //Δεξιοί κινητήρες
int IN1 = 10; 
int IN2 = 9;

int ENB = 6; //Αριστεροί κινητήρες
int IN3 = 5;
int IN4 = 3;

int RSensor = A4;  //mple    IR Sensors
int LSensor = A5;  //prasino

//Ταχύτητα Κινητήρων
#define ENASpeed 150   
#define ENBSpeed 180

//Αρχικοποίηση μεταβλητών
int l_sens = 0;
int r_sens = 0;


void setup() {
//Αρχικοποίηση εισόδων και εξόδων

  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);

  pinMode(ENB, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  pinMode(RSensor, INPUT);
  pinMode(LSensor, INPUT);
  
  
}

void loop(){

  //Ξεκινάει το όχημα στην ταχύτητα που θέσαμε
  analogWrite(ENA, ENASpeed);
  analogWrite(ENB, ENBSpeed);

  //Ανάνωση αισθητήρων
  r_sens = digitalRead(RSensor);
  l_sens = digitalRead(LSensor);
  

  //Θέτουμε προυποθέσεις για κίνηση ΜΠΡΟΣΤΑ,ΔΕΞΙΑ,ΑΡΙΣΤΕΡΑ,ΣΤΑΜΑΤΑ

  if(r_sens == HIGH && l_sens == LOW){
    turn_left();
  }
  
  else if (r_sens == LOW && l_sens == HIGH){
    turn_right();
  }
  
  else if(r_sens == LOW && l_sens == LOW){
    move_f();
  }
  
  else if (r_sens == HIGH && l_sens == HIGH){
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
    
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
}

void turn_right() {    //Turn ΔΕΞΙΑ
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);

    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
}

void turn_left(){    //ΑΡΙΣΤΕΡΑ
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);

    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
}
