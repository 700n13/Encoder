/* Encoder Library - Basic Example
 * http://www.pjrc.com/teensy/td_libs_Encoder.html
 *
 * This example code is in the public domain.
 */

#include <Encoder.h>

// Change these two numbers to the pins connected to your encoder.
//   Best Performance: both pins have interrupt capability
//   Good Performance: only the first pin has interrupt capability
//   Low Performance:  neither pin has interrupt capability
Encoder myEnc(2, 3);
//   avoid using pins with LEDs attached
int totalpulse = 6120; //total pulse in 360 degrees rotation
float t = 0;
float t0 = 0;

void setup() {
  Serial.begin(9600);
  Serial.println("Basic Encoder Test:");
}

long d0  = 0;


void loop() {
  t = millis();
  long d = myEnc.read();
// Compute using constant delta(t) method
// Read position testing
  if (d != d0) {
    //Serial.println(d);
  }
  else{
    //Serial.println(d0);
  }
  if ((t-t0) > 1){
    omega(d0,d,t-t0);
    //Serial.print(d0);
    //Serial.print(" ");
    //Serial.print(d);
    //Serial.print(" ");
    //Serial.println(t-t0);
    t0 = t;
  }
  d0 = d;
}

void omega (long d,long d0,float t){
  float rad = ((d-d0)*2*3.14)/totalpulse ;
  float ang_velocity = rad/(t*0.001);
  Serial.print("Angular Velocity(rad/s)");
  Serial.println(ang_velocity); 
}
