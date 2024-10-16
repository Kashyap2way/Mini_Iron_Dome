// C++ code
//
#include <Servo.h>

Servo servo_13;

void setup()
{
  servo_13.attach(13, 500, 2500);

}

void loop()
{
  servo_13.write(260);
}
