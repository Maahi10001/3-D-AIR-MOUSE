#include<RCSwitch.h>
#include"Mouse.h"
RCSwitchmySwitch=RCSwitch();
intrvalue,a,b,c,d;
floatxReading,yReading;
voidsetup(){
//Serial.begin(115200);
mySwitch.enableReceive(1);//Receiveroninterrupt0=>thatispin#2
Mouse.begin();
pinMode(5,INPUT);
}
voidloop(){
if(mySwitch.available()){
rvalue=mySwitch.getReceivedValue();
a=(rvalue)%10;
b=(rvalue/10)%10;
c=(rvalue/100)%10;
d=(rvalue/1000)%10;
if(d==1){xReading=3;}
if(d==2){xReading=2;}
if(d==3){xReading=0;}
if(d==4){xReading=0;}
if(d==5){xReading=0;}
if(d==6){xReading=0;}
if(d==7){xReading=-2;}
if(d==8){xReading=-3;}
if(c==1){yReading=3;}
if(c==2){yReading=2;}
if(c==3){yReading=0;}
if(c==4){yReading=0;}
if(c==5){yReading=0;}
if(c==6){yReading=0;}
if(c==7){yReading=-2;}
if(c==8){yReading=-3;}
mySwitch.resetAvailable();
}
if(digitalRead(5)==LOW){
Mouse.Move(xReading,yReading,0);
}
if(a==1){
if(!Mouse.isPressed(MOUSE_LEFT)){
Mouse.press(MOUSE_LEFT);
}
}
else{
if(Mouse.isPressed(MOUSE_LEFT)){
Mouse.release(MOUSE_LEFT);
}
}
if(b==1){
if(!Mouse.isPressed(MOUSE_RIGHT)){
Mouse.press(MOUSE_RIGHT);
}
}
else{
if(Mouse.isPressed(MOUSE_RIGHT)){
Mouse.release(MOUSE_RIGHT);
}
}
}
