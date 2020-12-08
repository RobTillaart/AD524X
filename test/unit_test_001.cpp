//
//    FILE: unit_test_001.cpp
//  AUTHOR: Rob Tillaart
// VERSION: 0.1.0
//    DATE: 2020-12-03
// PURPOSE: unit tests for I2C digital PotentioMeter AD5241 AD5242
//          https://github.com/RobTillaart/AD524X
//          https://github.com/Arduino-CI/arduino_ci/blob/master/REFERENCE.md
//

// supported assertions
// ----------------------------
// assertEqual(expected, actual)
// assertNotEqual(expected, actual)
// assertLess(expected, actual)
// assertMore(expected, actual)
// assertLessOrEqual(expected, actual)
// assertMoreOrEqual(expected, actual)
// assertTrue(actual)
// assertFalse(actual)
// assertNull(actual)

#include <ArduinoUnitTests.h>

#include "AD524X.h"


unittest_setup()
{
}

unittest_teardown()
{
}

unittest(test_begin)
{
  AD524X AD(0x2C);  // AD0 & AD1 == GND
  Wire.begin();

  assertEqual(127, AD.read(0));
  assertEqual(127, AD.read(1));

  AD.zeroAll();
  assertEqual(0, AD.read(0));
  assertEqual(0, AD.read(1));

  AD.reset();
  assertEqual(127, AD.read(0));
  assertEqual(127, AD.read(1));
}

unittest(test_write_read)
{
  AD524X AD(0x2C);  // AD0 & AD1 == GND
  Wire.begin();

  assertEqual(127, AD.read(0));
  assertEqual(127, AD.read(1));

  AD.write(0, 42);
  assertEqual(42, AD.read(0));
  assertEqual(127, AD.read(1));

  AD.write(1, 42);
  assertEqual(42, AD.read(0));
  assertEqual(42, AD.read(1));

}

unittest(test_O1_O2)
{
  AD524X AD(0x2C);  // AD0 & AD1 == GND
  Wire.begin();

  assertEqual(0, AD.getO1());
  assertEqual(0, AD.getO2());
  
  AD.setO1();
  assertEqual(1, AD.getO1());
  assertEqual(0, AD.getO2());

  AD.setO2();
  assertEqual(1, AD.getO1());
  assertEqual(1, AD.getO2());
  
  AD.setO1(0);
  assertEqual(0, AD.getO1());
  assertEqual(1, AD.getO2());

  AD.setO2(0);
  assertEqual(0, AD.getO1());
  assertEqual(0, AD.getO2());
  
  AD.write(0, 0, 1, 1);
  assertEqual(1, AD.getO1());
  assertEqual(1, AD.getO2());
}

unittest_main()

// --------
