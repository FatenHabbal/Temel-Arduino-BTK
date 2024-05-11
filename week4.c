#include <Servo.h>
int pot;
int servoAci;
Servo myServo; //0-180 derece arasında döner.
void setup(){
  myServo.attach(3);
}
void loop(){
  pot= analogRead(A0);  //0-1023
  servoAci = map(pot,0,1023,0,180); //0-1023 arasındaki değer 0-180 arasında çevrildi.
  myServo.write(servoAci);
}


##############




#include <Servo.h>
#include <DHT.h> //dht11 için kütüphane eklendi

int sicaklik;

Servo myServo; //0-180 derece arasında döner
DHT myDht11(5,DHT11); //dht11sensörü ayarlanır

void setup() {
 myServo.attach(3);
 myDht11.begin(); // dht sensoru başlatır
}

void loop() {
 sicaklik = myDht11.readTemperature(); //sıcaklık sensöründen sıcaklık değerini okur ve ilgili değişkene atar
 if(sicaklik>25)
 {
   myServo.write(90);
 }
else
{
  myServo.write(0);
}
}

##############




#include <NewPing.h>

int mesafe;
NewPing ultrasonikSensor(6,7,200);
void setup() {
 Serial.begin(9600);

}

void loop() {
 mesafe = ultrasonikSensor.ping_cm(); // sensörden mesafe değerini cm cinsinden okur
 Serial.print("Mesafe = ");
 Serial.println(mesafe);
 delay(500);
}



##################

#include <NewPing.h>
#include <Servo.h>



int mesafe;
NewPing ultrasonikSensor (6,7,200);
Servo myServo;
void setup(){
  Serial.begin(9600);
  myServo.attach(3);
}

void loop(){
  mesafe = ultrasonikSensor.ping_cm();

  if (mesafe<15)
  {
    myServo.write(90);
  }
  else
  {
    myServo.write(0);
  }
  Serial.print("Mesafe= ");
  Serial.println(mesafe);
  delay(500);
}

