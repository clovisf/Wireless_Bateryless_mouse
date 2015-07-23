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

void setup()
{                
  Serial.begin(115200);
  
}

int Xaxis;
int Yaxis;

void loop()                     
{
  Xaxis = analogRead(0)-512;
  Yaxis = analogRead(1)-512; 
  /*
  if (Xaxis < 10 || Xaxis > -10) {
  Xaxis = 0;
    }
  if (Yaxis < 10 || Xaxis > -10) {
    Yaxis = 0;
    }
    */
 Mouse.move(Xaxis, Yaxis); 
  //Serial.print("X: ");
  //Serial.print(Xaxis);
  //Serial.print(" Y: ");
  //Serial.println(Yaxis);
  delay(25);
}

