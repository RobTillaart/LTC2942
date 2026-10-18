//
//    FILE: LTC2942_test.ino
//  AUTHOR: Rob Tillaart
// PURPOSE: simple register test
//     URL: https://github.com/RobTillaart/LTC2942
//
//  TODO voltage and temperature

#include "LTC2942.h"

LTC2942 LTC;


void setup()
{
  Serial.begin(115200);
  Serial.println();
  Serial.println(__FILE__);
  Serial.print("LTC2942_LIB_VERSION: ");
  Serial.println(LTC2942_LIB_VERSION);
  Serial.println();

  Wire.begin();

  bool b = LTC.begin(2000, 0.050);
  Serial.print("BEGIN:\t");
  Serial.println(b);
  Serial.print("ADDR:\t");
  Serial.println(LTC.getAddress());

  Serial.print("STAT \tCONTROL\n");
  uint8_t status;
  LTC.getStatus(status);
  uint8_t alcc = 0;
  uint8_t prescaler = 0;
  uint8_t shutdown = 0;
  uint8_t ADCMode = 0;
  LTC.getControl(alcc, prescaler, shutdown, ADCMode);
  Serial.print(status, HEX);
  Serial.print("\t");
  Serial.print(alcc);
  Serial.print("\t");
  Serial.print(prescaler);
  Serial.print("\t");
  Serial.print(shutdown);
  Serial.print("\t");
  Serial.println(ADCMode);


  Serial.print("getCharge: \t");
  //  save old value to restore
  uint16_t val;
  uint16_t nval;
  LTC.getRawCharge(val);
  val ^= 0xFFFF;
  LTC.setRawCharge(val);
  LTC.getRawCharge(nval);
  if (nval != (val))
  {
    Serial.println("Error");
  }
  else
  {
    Serial.println("OK");
  }
  //  restore
  LTC.setRawCharge(val ^ 0xFFFF);


  Serial.print("getChargeThresholdHigh: \t");
  //  save old value to restore
  LTC.getRawChargeThresholdHigh(val);
  val ^= 0xFFFF;
  LTC.setRawChargeThresholdHigh(val);
  LTC.getRawChargeThresholdHigh(nval);
  if (nval != val)
  {
    Serial.println("Error");
  }
  else
  {
    Serial.println("OK");
  }
  //  restore
  LTC.setRawChargeThresholdHigh(val ^ 0xFFFF);


  Serial.print("getChargeThresholdLow: \t");
  //  save old value to restore
  LTC.getRawChargeThresholdLow(val);
  val ^= 0xFFFF;
  LTC.setRawChargeThresholdLow(val);
  LTC.getRawChargeThresholdLow(nval);
  if (nval != val)
  {
    Serial.println("Error");
  }
  else
  {
    Serial.println("OK");
  }
  //  restore
  LTC.setRawChargeThresholdLow(val ^ 0xFFFF);


  Serial.println("\ndone");
}


void loop()
{

}


//  -- END OF FILE --
