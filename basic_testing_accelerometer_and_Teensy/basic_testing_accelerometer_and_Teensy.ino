/* Analog Input Example, Teensyduino Tutorial #4
   http://www.pjrc.com/teensy/tutorial4.html

   After uploading this to your board, use Serial Monitor
   to view the message.  When Serial is selected from the
   Tools > USB Type menu, the correct serial port must be
   selected from the Tools > Serial Port AFTER Teensy is
   running this code.  Teensy only becomes a serial device
   while this code is running!  For non-Serial types,
   the Serial port is emulated, so no port needs to be
   selected.

   This example code is in the public domain.
*/

int Xaxis;
int Yaxis;
int analog0 = A1;
int analog1 = A0;
int CalibrationX;
int CalibrationY;
int MinusMinMovement = 2;
int MinMovement = 2;
int Yantigo;
int Xantigo;

void setup()
{                
  Serial.begin(115200);
  delay(500);
  CalibrationX= analogRead(analog0);
  CalibrationY= analogRead(analog1);
  delay(500);  
}



void loop()                     
{
  Xaxis = analogRead(analog0)-CalibrationX;
  Yaxis = analogRead(analog1)-CalibrationY;
  
  
  if ((Xaxis + Xantigo < 3) || (Xaxis + Xantigo < -3)) {
  Xaxis = 0;
    }
  if ((Yaxis + Yantigo < 3) || (Yaxis + Yantigo < -3)) {
    Yaxis = 0;
    }
   
 Mouse.move(Xaxis, Yaxis);
  Xantigo = Xaxis;
  Yantigo = Yaxis;
  
  Serial.print("X: ");
  Serial.print(Xaxis);
  Serial.print(" Y: ");
  Serial.println(Yaxis);
  delay(25);
}
  
