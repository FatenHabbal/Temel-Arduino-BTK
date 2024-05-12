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
NewPing ultrasonikSensor (6,7,200); //(trigger_pin,echo_pin,max_mesafe)
Servo myServo;
void setup(){
  Serial.begin(9600);
  myServo.attach(3);
}

void loop(){
  mesafe = ultrasonikSensor.ping_cm();

  if (mesafe<15 && mesafe>0) // && işareti ve anlamına gelir.
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

######################### 

#include <NewPing.h>
#include <LiquidCrystal_I2C.h>

NewPing uSensor(3,2,300);
LiquidCrystal_I2C lcd(0x27,16,2);

int mesafe;
void setup() {
  lcd.init();
  lcd.backlight();

}

void loop() {
  mesafe = uSensor.ping_cm();
  lcd.setCursor(0,0);
  lcd.print("Mesafe= ");
  lcd.setCursor(9,0);
  lcd.print(mesafe);
  delay(500);
  lcd.clear();

}




############

#include <NewPing.h>
#include <LiquidCrystal_I2C.h>

NewPing uSensor(3,2,300);
LiquidCrystal_I2C lcd(0x27,16,2);

int mesafe;
void setup() {
  lcd.init();
  lcd.backlight();

}

void loop() {
  mesafe = uSensor.ping_cm();
  lcd.setCursor(0,0);
  lcd.print("Mesafe= ");
  lcd.setCursor(8,0);
  lcd.print(mesafe);
  if(mesafe>40 && mesafe<50)
  {
    lcd.setCursor(0,1);
    lcd.print("Yaklaştınız!");
  }
  else if (30<mesafe && mesafe<=40)
  {
    lcd.setCursor(0,1);
    lcd.print("Çok Yaklaştınız!");
  }
  else if (0<mesafe && mesafe<=30)
  {
    lcd.setCursor(0,1);
    lcd.print("Dikkat Et!");
  }
  else
  {
    lcd.setCursor(0,1);
    lcd.print("Güvenli");
  }
  delay(500);
  lcd.clear();

}




##########


#include <NewPing.h>
#include <LiquidCrystal_I2C.h>

NewPing uSensor(3,2,300);
LiquidCrystal_I2C lcd(0x27,16,2);

int mesafe;
void setup() {
  lcd.init();
  lcd.backlight();
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
}

void loop() {
  mesafe = uSensor.ping_cm();
  lcd.setCursor(0,0);
  lcd.print("Mesafe= ");
  lcd.setCursor(8,0);
  lcd.print(mesafe);
  if(mesafe>40 && mesafe<50)
  {
    lcd.setCursor(0,1);
    lcd.print("Yaklastiniz");
    digitalWrite(5,1);
    delay(1000);
    digitalWrite(5,0);
  }
  else if (30<mesafe && mesafe<=40)
  {
    lcd.setCursor(0,1);
    lcd.print("Cok Yaklastin");
    digitalWrite(6,1);
    delay(1000);
    digitalWrite(6,0);
  }
  else if (0<mesafe && mesafe<=30)
  {
    lcd.setCursor(0,1);
    lcd.print("Dikkat Et!");
    digitalWrite(7,1);
    delay(1000);
    digitalWrite(7,0);
  }
  else
  {
    lcd.setCursor(0,1);
    lcd.print("Guvenli");
  }
  
  delay(500);
  lcd.clear();

}
