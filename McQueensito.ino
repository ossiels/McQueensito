#include <AFMotor.h>

int detectorPin = 14;
AF_DCMotor motor1(1); //pin 11
AF_DCMotor motor2(2); //pin 3
AF_DCMotor motor3(3); //pin 5
AF_DCMotor motor4(4); //pin6

void setup() {
  Serial.begin(9600);
  pinMode(detectorPin, INPUT);
  cambiarVelocidad(100);
}

void loop() {
  int val = digitalRead(detectorPin);
  if(val == HIGH) {
    avanzar();
  }
  else {
    esquivar();
  }
  Serial.println();
}

void esquivar() {
  long duracion = 1000;
  long startTime = millis();

  while (millis() - startTime <= duracion) {
    retroceder();
  }

  duracion = random(200, 1000);
  startTime = millis();

  cambiarVelocidad(60);
  while (millis() - startTime <= duracion) {
    irDer();
  }
  cambiarVelocidad(40);
}

void parar() {
	Serial.print(" All motor stopped");
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
  
}

void avanzar() {
  Serial.print("fwd");
	motor1.run(FORWARD);
	motor2.run(FORWARD);
  motor3.run(FORWARD);
	motor4.run(FORWARD);
}

void retroceder() {
  Serial.print("back");
	motor1.run(BACKWARD);
	motor2.run(BACKWARD);
  motor3.run(BACKWARD);
	motor4.run(BACKWARD);
}

void irIzq() {
  Serial.print("left");
	motor1.run(FORWARD);
	motor2.run(BACKWARD);
	motor3.run(BACKWARD);
  motor4.run(FORWARD);
}

void irDer() {
  Serial.print("right");
	motor1.run(BACKWARD);
	motor2.run(FORWARD);
	motor3.run(FORWARD);
  motor4.run(BACKWARD);
}

void cambiarVelocidad(int velocidad){
  motor1.setSpeed(velocidad);
  motor2.setSpeed(velocidad);
  motor3.setSpeed(velocidad);
  motor4.setSpeed(velocidad);
}