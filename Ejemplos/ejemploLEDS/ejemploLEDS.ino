void setup() {
  // put your setup code here, to run once:
  pinMode(22,OUTPUT);//1
  digitalWrite(22,LOW);
  
  pinMode(23,OUTPUT);//A
  digitalWrite(23,HIGH);
  
  pinMode(24,OUTPUT);//2
  digitalWrite(24,LOW);
  
  pinMode(25,OUTPUT);//B
  digitalWrite(25,HIGH);
  
  pinMode(26,OUTPUT);//3
  digitalWrite(26,HIGH);
  
  pinMode(27,OUTPUT);//C
  digitalWrite(27,LOW);
  
  pinMode(28,OUTPUT);//4
  digitalWrite(28,HIGH);
  
  pinMode(29,OUTPUT);//D
  digitalWrite(29,HIGH);
  
  pinMode(30,OUTPUT);//5
  digitalWrite(30,LOW);
  
  pinMode(31,OUTPUT);//E
  digitalWrite(31,LOW);
  
  pinMode(32,OUTPUT);//6
  digitalWrite(32,HIGH);
  
  pinMode(33,OUTPUT);//F
  digitalWrite(33,HIGH);
  
  pinMode(34,OUTPUT);//7
  digitalWrite(34,LOW);
  
  pinMode(35,OUTPUT);//G
  digitalWrite(35,HIGH);
  
  pinMode(36,OUTPUT);//8
  digitalWrite(36,LOW);
  
  pinMode(37,OUTPUT);//H
  digitalWrite(37,LOW);


  
}

void loop() {
  digitalWrite(30,HIGH);
  digitalWrite(29,LOW);
  delay(5);
  digitalWrite(30,LOW);
  digitalWrite(29,HIGH);
  delay(5);
  digitalWrite(34,HIGH);
  digitalWrite(23,LOW);
  delay(5);
  digitalWrite(34,LOW);
  digitalWrite(23,HIGH);
  delay(5);
}
