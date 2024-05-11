void setup (){
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
}
void loop (){ 
  digitalWrite(3,1);
  delay(3000);
  digitalWrite(3,1);
  digitalWrite(4,1);
  delay(2000);
  digitalWrite(3,0);
  digitalWrite(4,0);
  digitalWrite(5,1);
  delay(3000);
  digitalWrite(5,1);
  digitalWrite(4,1);
  delay(2000);
  digitalWrite(5,0);
  digitalWrite(4,0);
}
0 comments on commit c607881
