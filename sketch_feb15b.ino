#include "rocciboard.h"
RocciBoard rb; // Rocciboard

RBLaser laser(0, TYPE_VL53L1X); // Laser  
RBColor color(4);

void setup()  // Base
{
Serial.begin(9600);
rb.init();
rb.initRBSensor(laser); 
rb.initRBSensor(color);
pinMode(A1, OUTPUT);
pinMode(A3, OUTPUT);
}







// Movement and Wall Sensory (Incomplete)
void loop()
{
  int Red = color.getRed(); 
  int Blue = color.getBlue();
  int Green = color.getGreen();
  int Lux = color.getLux();
  Serial.println("Distance: " + String(laser.getDistanceMillimeters()) + " mm");
  Serial.println(" Red: " + String(color.getRed()));
  Serial.println(" Green: " + String(color.getGreen()));
  Serial.println(" Blue: " + String(color.getBlue()));
  Serial.println(" Lux: " + String(color.getLux()));
  

    if(45 <= laser.getDistanceMillimeters() && 50 >= laser.getDistanceMillimeters())
       {
        rb.motor[0].rotate(100);
        rb.motor[1].rotate(-100);
        delay(2000);
       if(45 <= laser.getDistanceMillimeters() && 50 >= laser.getDistanceMillimeters())
       {
        rb.motor[0].rotate(-100);
        rb.motor[1].rotate(100);
        delay(4000);
        if(45 <= laser.getDistanceMillimeters() && 50 >= laser.getDistanceMillimeters())
       {
        rb.motor[0].rotate(-100);
        rb.motor[1].rotate(100);
        delay(2000);
       } 
     }
     else
     {
     rb.motor[0].rotate(-130);
     rb.motor[1].rotate(-130);
     }  
    } 
else
     {
     rb.motor[0].rotate(-130);
     rb.motor[1].rotate(-130);
     }
 } // Delete after done testing
    
     
    
     /**
     if(3 <= Red && 5 >= Blue && 5 >= Green && 0 == Lux) 
     {
      rb.motor[0].rotate(-150);
      rb.motor[1].rotate(-150);
      delay(1000);
      rb.motor[0].stop();
      rb.motor[1].stop();
      delay(100);
      digitalWrite(A1, HIGH);
      digitalWrite(A3, LOW);
      delay(500);
      digitalWrite(A3, HIGH);
      digitalWrite(A1, LOW);
      delay(500);
      digitalWrite(A1, HIGH);
      digitalWrite(A3, LOW);
      delay(500);
      digitalWrite(A3, HIGH);
      digitalWrite(A1, LOW);
      delay(500);
      digitalWrite(A1, HIGH);
      digitalWrite(A3, LOW);
      delay(500);
      digitalWrite(A3, HIGH);
      digitalWrite(A1, LOW);
      delay(500);
      digitalWrite(A1, HIGH);
      digitalWrite(A3, LOW); 
      delay(500);
      digitalWrite(A3, HIGH);
      digitalWrite(A1, LOW);
      delay(500);
      digitalWrite(A3, LOW);
      digitalWrite(A1, LOW);
      delay(500); 
      rb.motor[0].rotate(-150);
      rb.motor[1].rotate(-150);
      delay(2000);
     }
     if(3 >= Red && 3 >= Blue && 3 >= Green && 2 >= Lux)
     {
      rb.motor[0].stop();
      rb.motor[1].stop();
      delay(100);
      rb.motor[0].rotate(150);
      rb.motor[1].rotate(150);
      delay(500);
      rb.motor[0].rotate(150);
      rb.motor[1].rotate(-150);
      delay(1500);
      if(40 > laser.getDistanceMillimeters())
      {
       rb.motor[0].rotate(-150);
       rb.motor[1].rotate(150);
       delay(3000);
       if(40 > laser.getDistanceMillimeters())
       {
        rb.motor[0].rotate(-150 );
        rb.motor[1].rotate(150);
        delay(1500);
       }
      }
     }
  
 }
*/


// Black = Red: 4 Green: 4 Blue: 4 Clear: 4 Temperature: 8890 Lux: 2
// White =  Red: 11 Green: 12 Blue: 10 Clear: 10 Temperature: 5780 Lux: 8
// Red =  Red: 4 Green: 1 Blue: 1 Clear: 1 Temperature: 31585 Lux: 0
// Silver (probably not going to be used) =  Red: 4 Green: 4 Blue: 3 Clear: 3 Temperature: 4508 Lux: 2




  
