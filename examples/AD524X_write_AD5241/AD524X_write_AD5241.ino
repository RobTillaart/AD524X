//
//    FILE: AD524X_write_AD5241ino.ino
//  AUTHOR: Rob Tillaart
// PURPOSE: AD524X demo program
//     URL: https://github.com/RobTillaart/AD524X
//


#include "AD524X.h"

AD5241 AD01(0x2C);  // AD0 & AD1 == GND


void setup()
{
  Serial.begin(115200);
  Serial.println();
  Serial.println(__FILE__);
  Serial.println();
  Serial.println(AD524X_LIB_VERSION);

  Wire.begin();
  Wire.setClock(400000);
  
  bool b = AD01.begin();
  Serial.println(b ? "true" : "false");
  Serial.println(AD01.isConnected());

  Serial.println(AD01.pmCount());
}


void loop()
{
  for (int val = 0; val < 255; val++)
  {
    AD01.write(0, val);
    if (val == 200)
    {
      AD01.write(1, val, HIGH, LOW);
    }
    if (val == 0)
    {
      AD01.write(0, val, LOW, LOW);
    }
    Serial.println(val);
    delay(20);
  }
}


//  -- END OF FILE --

