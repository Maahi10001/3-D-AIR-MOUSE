#include<Wire.h>
#include<MPU6050.h>
#include<RCSwitch.h>
RCSwitchmySwitch=RCSwitch();
MPU6050mpu;
intLclick=11;
intRclick=13;
voidsetup()
{
Serial.begin(115200);
while(!mpu.begin(MPU6050_SCALE_2000DPS,MPU6050_RANGE_2G))
{
Serial.println("CouldnotfindavalidMPU6050sensor,checkwiring!");
delay(500);
}
checkSettings();
mySwitch.enableTransmit(4);
pinMode(Lclick,INPUT);
pinMode(Rclick,INPUT);
}
voidcheckSettings()
{
Serial.println();
Serial.print("*SleepMode: ");
Serial.println(mpu.getSleepEnabled()?"Enabled":"Disabled");
Serial.print("*ClockSource: ");
switch(mpu.getClockSource())
{
caseMPU6050_CLOCK_KEEP_RESET: Serial.println("Stopstheclockandkeepsthetiming
generatorinreset");break;
caseMPU6050_CLOCK_EXTERNAL_19MHZ:Serial.println("PLLwithexternal19.2MHzreference");
break;
caseMPU6050_CLOCK_EXTERNAL_32KHZ:Serial.println("PLLwithexternal32.768kHzreference");
break;
caseMPU6050_CLOCK_PLL_ZGYRO: Serial.println("PLLwithZaxisgyroscopereference");break;
caseMPU6050_CLOCK_PLL_YGYRO: Serial.println("PLLwithYaxisgyroscopereference");break;
caseMPU6050_CLOCK_PLL_XGYRO: Serial.println("PLLwithXaxisgyroscopereference");break;
caseMPU6050_CLOCK_INTERNAL_8MHZ:Serial.println("Internal8MHzoscillator");break;
}
Serial.print("*Accelerometer: ");
switch(mpu.getRange())
{
caseMPU6050_RANGE_16G: Serial.println("+/-16g");break;
caseMPU6050_RANGE_8G: Serial.println("+/-8g");break;
caseMPU6050_RANGE_4G: Serial.println("+/-4g");break;
caseMPU6050_RANGE_2G: Serial.println("+/-2g");break;
}
Serial.print("*Accelerometeroffsets:");
Serial.print(mpu.getAccelOffsetX());
Serial.print("/");
Serial.print(mpu.getAccelOffsetY());
Serial.print("/");
Serial.println(mpu.getAccelOffsetZ());
Serial.println();
}
voidloop()
{
//VectorrawAccel=mpu.readRawAccel();
VectornormAccel=mpu.readNormalizeAccel();
intxval=normAccel.XAxis/3+5;
intyval=normAccel.YAxis/3+5;
intRCval=digitalRead(Rclick);
intLCval=digitalRead(Lclick);
intT=1000*xval+100*yval+10*RCval+LCval;
mySwitch.send(T,24);
//delay(10);
}
