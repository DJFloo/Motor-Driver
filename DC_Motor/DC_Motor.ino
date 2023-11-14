#include <Wire.h>
#include <Adafruit_MotorShield.h>

// Create the motor shield object with the default I2C address
Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 

// Connect motors to the appropriate channels
Adafruit_DCMotor *motor1 = AFMS.getMotor(1);
Adafruit_DCMotor *motor2 = AFMS.getMotor(2);
Adafruit_DCMotor *motor3 = AFMS.getMotor(3);
Adafruit_DCMotor *motor4 = AFMS.getMotor(4);

void setup() {
  Serial.begin(9600);           // set up Serial library at 9600 bps
  Serial.println("Adafruit Motorshield v2 - 4 motor test!");

  AFMS.begin();  // create with the default frequency 1.6KHz

  // Set the speed of the motors
  motor1->setSpeed(255);
  motor2->setSpeed(255);
  motor3->setSpeed(255);
  motor4->setSpeed(255);
}

void loop() {
  // Move forward
  moveForward();
  delay(2000);  // Move forward for 2 seconds

  // Move backward
  moveBackward();
  delay(2000);  // Move backward for 2 seconds

  // Turn left
  turnLeft();
  delay(2000);  // Turn left for 2 seconds

  // Turn right
  turnRight();
  delay(2000);  // Turn right for 2 seconds
}

void moveForward() {
  motor1->run(FORWARD);
  motor2->run(FORWARD);
  motor3->run(FORWARD);
  motor4->run(FORWARD);
}

void moveBackward() {
  motor1->run(BACKWARD);
  motor2->run(BACKWARD);
  motor3->run(BACKWARD);
  motor4->run(BACKWARD);
}

void turnLeft() {
  motor1->run(BACKWARD);
  motor2->run(FORWARD);
  motor3->run(BACKWARD);
  motor4->run(FORWARD);
}

void turnRight() {
  motor1->run(FORWARD);
  motor2->run(BACKWARD);
  motor3->run(FORWARD);
  motor4->run(BACKWARD);
}
