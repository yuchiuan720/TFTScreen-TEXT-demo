#include <TFT.h>
#include <SPI.h>
#define cs A0
#define dc A1
#define rst A2
//1cm = 45.4545pixs
TFT TFTscreen = TFT(cs, dc, rst);
void DrwaRectangle(){
  TFTscreen.stroke(0, 255, 0);
  TFTscreen.line(0, 0, TFTscreen.width()-1, 0);
  TFTscreen.line(TFTscreen.width()-1, 0, TFTscreen.width()-1, TFTscreen.height()-1);
  TFTscreen.line(TFTscreen.width()-1, TFTscreen.height()-1, 0, TFTscreen.height()-1);
}
void DeawGrid(){
  int MaxWidth = TFTscreen.width();
  int MaxHeight = TFTscreen.height();
  TFTscreen.stroke(255, 0, 0);
  for (float x=5; x<MaxWidth; x+=6) {
    for (float y=7; y<MaxHeight; y+=8){
      TFTscreen.line(x, 0, x, TFTscreen.height()-1);//|
      TFTscreen.line(0, y, TFTscreen.width()-1, y);// _
    }
  }
}
void setup() {
  // put your setup code here, to run once:
  TFTscreen.begin();
  TFTscreen.background(0, 0, 0);
  TFTscreen.line(0, TFTscreen.height()-1, 0, 0);
  TFTscreen.stroke(255, 255, 255);
  TFTscreen.setTextSize(1);
  TFTscreen.text("ABCDEFGHIJKLMNOPQRSTUVWXYZ", 0, 0);
  //DrwaRectangle();
  DeawGrid();
  TFTscreen.stroke(255, 255, 255);
  TFTscreen.text("0123456789ABCDEFGHIJKLMNOP", 0, 8);
  TFTscreen.text("A", 36, 64);
}

void loop() {
  // put your main code here, to run repeatedly:
  TFTscreen.text("ANALOG READ:", 6, 16);
  TFTscreen.text("c", 114, 72);
}
