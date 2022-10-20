/* Encoder Library - Basic Example
 * http://www.pjrc.com/teensy/td_libs_Encoder.html
 *
 * This example code is in the public domain.
 */
#include <Encoder.h>
#define LA 2  //pin for Channel A, Left wheel's encoder
#define LB 3  //pin for Channel B, Left wheel's encoder
#define RA 4  //pin for Channel A, Right wheel's encoder
#define RB 5  //pin for Channel B, Right wheel's encoder
//replace these pin with interrupt supported pin, see https://www.pjrc.com/teensy/td_libs_Encoder.html
//avoid using pins with LEDs attached
//   Best Performance: both pins have interrupt capability
//   Good Performance: only the first pin has interrupt capability
//   Low Performance:  neither pin has interrupt capability

Encoder left(LA, LB); // Left Wheel Encoder
Encoder right(RA, RB); // Right Wheel Encoder

int totalpulse = 6120; //total pulse in 360 degrees rotation (not exact, value can be improved)
float t = 0;
float t0 = 0;
long d01 = 0;
long d02 = 0;

void setup() {
  Serial.begin(9600);
  Serial.println("Angular Velocity(rad/s)");
}


void loop() {
  // Compute using constant delta(t) method
  t = millis();
  long d1 = left.read();
  long d2 = right.read();
  if ((t-t0) > 1){
    Serial.print("L: ");
    Serial.print(omega(d1,d01,t));
    Serial.print("  R : ");
    Serial.println(omega(d2,d02,t));
    t0 = t;
  }
  d01 = d1;
  d02 = d2;
}

float omega (long d,long d0,float t){
  float rad = ((d-d0)*2*3.14)/totalpulse ;
  float ang_velocity = rad/(t*0.001);
  return(ang_velocity);
}

// Read position testing (for debug purpose)
  //if (d != d0) {
    //Serial.println(d);
  //}
  //else{
    //Serial.println(d0);
  //}
