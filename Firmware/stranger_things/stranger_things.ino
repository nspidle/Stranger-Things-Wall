#include <Adafruit_NeoPixel.h>
#include <avr/power.h>

#define PIN            2

#define NUMPIXELS      150

enum CHAR_LEDS {
  LR = 1, LS, LT, LU, LV, LW, LX, LY, LZ, NAN1, LQ,
  LP, LO, LN, LM, LL, LK, LJ, LI, NAN2, LA, LB, LC,
  LD, LE, LF, LG, LH
};

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN);

int delayVal = 500; // delay for half a second
uint32_t PixelG = pixels.Color(255,0,0);
uint32_t PixelR = pixels.Color(0,255,0);
uint32_t PixelB = pixels.Color(0,0,255);
uint32_t PixelY = pixels.Color(255,255,0);
uint32_t PixelW = pixels.Color(255,255,255);

uint32_t pixelTypes[]
{
PixelG = pixels.Color(255,0,0),
PixelR = pixels.Color(0,255,0),
PixelB = pixels.Color(0,0,255),
PixelY = pixels.Color(255,255,0),
PixelW = pixels.Color(255,255,255)
};
void setup() 
{
  Serial.begin(115200);
  pixels.begin();
  pixelScary();
}

void loop()
{
  if (Serial.available() > 0)
  {
    char inchar = Serial.read();
    switch(inchar)
    {
      case 'a':
      case 'A':
        lightUp(102, PixelG);
        break;
        
      case 'b':
      case 'B':
        lightUp(105, PixelR);
        break;
      case 'c':
      case 'C':
        lightUp(108, PixelB);
        break;
      case 'd':
      case 'D':
        lightUp(111, PixelY);
        break;
      case 'e':
      case 'E':
        lightUp(114, PixelW);
        break;
      case 'f':
      case 'F':
        lightUp(117, PixelG);
        break;
      case 'g':
      case 'G':
        lightUp(121, PixelR);
        break;
      case 'h':
      case 'H':
        lightUp(124, PixelB);
        break;
      case 'i':
      case 'I':
        lightUp(94, PixelY);
        break;
      case 'j':
      case 'J':
        lightUp(91, PixelW);
        break;
      case 'k':
      case 'K':
        lightUp(89, PixelG);
        break;
      case 'l':
      case 'L':
        lightUp(86, PixelR);
        break;
      case 'm':
      case 'M':
        lightUp(83, PixelB);
        break;
      case 'n':
      case 'N':
        lightUp(81, PixelY);
        break;
      case 'o':
      case 'O':
        lightUp(78, PixelW);
        break;
      case 'p':
      case 'P':
        lightUp(75, PixelR);
        break;
      case 'q':
      case 'Q':
        lightUp(72, PixelG);
        break;
      case 'r':
      case 'R':
        lightUp(44, PixelB);
        break;
      case 's':
      case 'S':
        lightUp(46, PixelY);
        break;
      case 't':
      case 'T':
        lightUp(49, PixelW);
        break;
      case 'u':
      case 'U':
        lightUp(50, PixelR);
        break;
      case 'v':
      case 'V':
        lightUp(53, PixelG);
        break;
      case 'w':
      case 'W':
        lightUp(56, PixelB);
        break;
      case 'x':
      case 'X':
        lightUp(60, PixelY);
        break;
      case 'y':
      case 'Y':
        lightUp(63, PixelW);
        break;
      case 'z':
      case 'Z':
        lightUp(65, PixelR);
        break;
      case '1':
        pixelScary();   
      default:
        break;
    }
  }
}
void pixelScary()
{
  int pulse = 200;
  for(int i=0;i<5;i++){
    pulse = rand() % 1000 + 1;
    pixelAllRandLight();
    delay(pulse);
    pixelClear();
    delay(pulse);
  }
}
void pixelAllRandLight()
{
  for(int i=0;i<NUMPIXELS;i++){
    pixels.setPixelColor(i, pixelTypes[i%4]);
  }
      pixels.show();     
}
void pixelClear()
{
  for(int i=0;i<NUMPIXELS;i++){
    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    pixels.setPixelColor(i, pixels.Color(0,0,0));
  }
  pixels.show();
}
void lightUp(int charIndex, uint32_t pixelColor )
{
  pixels.setPixelColor(charIndex, pixelColor);
  pixels.show();
  delay(delayVal);
  pixels.setPixelColor(charIndex, pixels.Color(0,0,0));
  pixels.show();
}

