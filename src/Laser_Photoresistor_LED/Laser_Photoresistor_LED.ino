
#include <Servo.h>
#include <PololuLedStrip.h>
#include <LEDFader.h>


// Create an ledStrip object and specify the pin it will use.
PololuLedStrip<12> ledStrip;
PololuLedStrip<13> ledStrip2;

// Create a buffer for holding the colors (3 bytes per color).
#define LED_COUNT 300
rgb_color colors[LED_COUNT];

#define LED_COUNT2 100
rgb_color colors2[LED_COUNT2];


//Photoresistoren der Kontinente
int photoNorthAmericaA = 0;
int photoSouthAmericaA = 1;
int photoEuropeA       = 2;
int photoAfricaA       = 3;
int photoAsiaA         = 4;
int photoAustraliaA    = 5;

//Threshold der Photoresistoren
int thresholdNorthAmerica = 300;
int thresholdSouthAmerica = 250;
int thresholdEurope = 500;
int thresholdAfrica = 500;
int thresholdAsia = 420;
int thresholdAustralia = 490;

//Zeit stoppen
unsigned long timer;
long start;
long dauer;


void reset() {
  thresholdNorthAmerica = 250;
  thresholdSouthAmerica = 250;
  thresholdEurope = 500;
  thresholdAfrica = 500;
  thresholdAsia = 420;
  thresholdAustralia = 490;

  for (int i = 0; i < LED_COUNT; i++) {
    colors[i] = (rgb_color) {
      0, 0, 0
    };
  }

  ledStrip.write(colors, LED_COUNT);

}


/************************************************************************************************/
void setup() {

  Serial.begin(9600);

  timer = millis();


}

/************************************************************************************************/

void loop() {

//led.update();
  //Fade Schleife
 
  for (int j = 0; j < LED_COUNT2; j++) {
    colors2[j] = (rgb_color) {
      255, 255, 255
    };
  }
  ledStrip2.write(colors2, LED_COUNT2);




  if (millis() - timer > 50000) {
    reset();
  }

  //Serial.println(timer);

  //Photoresistor & LED
  //Serial.println(analogRead(photoSouthAmericaA));
  //Serial.println(analogRead(photoNorthAmericaA));
  //Serial.println(analogRead(photoAfricaA));
  //Serial.println(analogRead(photoEuropeA));
  //Serial.println(analogRead(photoAsiaA));
  //Serial.println(analogRead(photoAustraliaA));

  //  if (timer <= 2000) {
  Serial.println(millis() - timer);


  //Beleuchtung: Nordamerika
  if (analogRead(photoNorthAmericaA) > thresholdNorthAmerica) {
    timer = millis();

    for (uint16_t i = 29; i <= 96; i++) {
      colors[i] = (rgb_color) {
        0, 0, 255
      };
    }
    thresholdNorthAmerica = 900;
    ledStrip.write(colors, LED_COUNT);
  }

  //Beleuchtung: Südamerika
  if (analogRead(photoSouthAmericaA) > thresholdSouthAmerica) {
    timer = millis();
    for (uint16_t i = 0; i <= 28; i++) {
      colors[i] = (rgb_color) {
        210, 105, 30
      };
    }
    thresholdSouthAmerica = 900;
    ledStrip.write(colors, LED_COUNT);
  }

  //Beleuchtung: Afrika
  if (analogRead(photoAfricaA) > thresholdAfrica) {
    timer = millis();
    for (uint16_t i = 112; i <= 139; i++) {
      colors[i] = (rgb_color) {
        138, 43, 226
      };
    }
    thresholdAfrica = 900;
    ledStrip.write(colors, LED_COUNT);
  }

  //Beleuchtung: Europa
  if (analogRead(photoEuropeA) > thresholdEurope) {
    timer = millis();
    for (uint16_t i = 140; i <= 151; i++) {
      colors[i] = (rgb_color) {
        255, 215, 0
      };
    }
    thresholdEurope = 900;
    ledStrip.write(colors, LED_COUNT);

    for (uint16_t i = 210; i <= 215; i++) {
      colors[i] = (rgb_color) {
        255, 215, 0
      };
    }
    ledStrip.write(colors, LED_COUNT);
  }

  //Beleuchtung: Asien
  if (analogRead(photoAsiaA) > thresholdAsia) {
    timer = millis();
    for (uint16_t i = 152; i <= 172; i++) {
      colors[i] = (rgb_color) {
        0, 255, 0
      };
    }
    thresholdAsia = 900;
    ledStrip.write(colors, LED_COUNT);

    for (uint16_t i = 195; i <= 209; i++) {
      colors[i] = (rgb_color) {
        0, 255, 0
      };
    }
    ledStrip.write(colors, LED_COUNT);
  }

  //Beleuchtung: Australien
  if (analogRead(photoAustraliaA) > thresholdAustralia) {
    timer = millis();
    for (uint16_t i = 184; i <= 194; i++) {
      colors[i] = (rgb_color) {
        255, 0, 255
      };
    }
    thresholdAustralia = 999;
    ledStrip.write(colors, LED_COUNT);
  }

  /************************************************************************************************/

  //Verbindung Südamerika -> Afrika

  if (thresholdSouthAmerica == 900 && thresholdAfrica == 900) {
    //    interruptSouthAmericaAfrica();
    // conSouthAmericaAfrica();
    for (uint16_t i = 97; i <= 111; i++)
    {
      colors[i] = (rgb_color) {
        210, 105, 30
      };
      ledStrip.write(colors, LED_COUNT);
      delay(10);
    }

    for (uint16_t i = 97; i <= 111; i++)
    {

      colors[i] = (rgb_color) {
        0, 0, 0
      };
      ledStrip.write(colors, LED_COUNT);
      delay(10);
    }

    for (uint16_t i = 111; i >= 97; i--)
    {
      colors[i] = (rgb_color) {
        138, 43, 226
      };
      ledStrip.write(colors, LED_COUNT);
      delay(10);
    }

    for (uint16_t i = 111; i >= 97; i--)
    {
      colors[i] = (rgb_color) {
        0, 0, 0
      };
      ledStrip.write(colors, LED_COUNT);
      delay(10);
    }
  }


  //Verbindung Asia -> Australia
  if (thresholdAsia == 900 && thresholdAustralia == 999) {
    //  conAsiaAustralia();
    for (uint16_t i = 173; i <= 183; i++)
    {
      colors[i] = (rgb_color) {
        0, 255, 0
      };
      ledStrip.write(colors, LED_COUNT);
      delay(10);
    }

    for (uint16_t i = 173; i <= 183; i++)
    {

      colors[i] = (rgb_color) {
        0, 0, 0
      };
      ledStrip.write(colors, LED_COUNT);
      delay(10);
    }

    for (uint16_t i = 183; i >= 173; i--)
    {
      colors[i] = (rgb_color) {
        255, 0, 255
      };
      ledStrip.write(colors, LED_COUNT);
      delay(10);
    }

    for (uint16_t i = 183; i >= 173; i--)
    {
      colors[i] = (rgb_color) {
        0, 0, 0
      };
      ledStrip.write(colors, LED_COUNT);
      delay(10);
    }
  }

  //Verbindung Europe -> NorthAmerica
  if (thresholdEurope == 900 && thresholdNorthAmerica == 900) {
    //conEuropeNorthAmerica();
    for (uint16_t i = 215; i <= 230; i++)
    {
      colors[i] = (rgb_color) {
        255, 215, 0
      };
      ledStrip.write(colors, LED_COUNT);
      delay(10);
    }

    for (uint16_t i = 215; i <= 230; i++)
    {

      colors[i] = (rgb_color) {
        0, 0, 0
      };
      ledStrip.write(colors, LED_COUNT);
      delay(10);
    }

    for (uint16_t i = 230; i >= 215; i--)
    {
      colors[i] = (rgb_color) {
        0, 0, 255
      };
      ledStrip.write(colors, LED_COUNT);
      delay(10);
    }

    for (uint16_t i = 230; i >= 215; i--)
    {
      colors[i] = (rgb_color) {
        0, 0, 0
      };
      ledStrip.write(colors, LED_COUNT);
      delay(10);
    }
  }

  //Verbindung Africa -> Australia
  if (thresholdAfrica == 900 && thresholdAustralia == 999) {
    //conAfricaAustralia();
    for (uint16_t i = 231; i <= 245; i++)
    {
      colors[i] = (rgb_color) {
        138, 43, 226
      };
      ledStrip.write(colors, LED_COUNT);
      delay(10);
    }

    for (uint16_t i = 231; i <= 245; i++)
    {

      colors[i] = (rgb_color) {
        0, 0, 0
      };
      ledStrip.write(colors, LED_COUNT);
      delay(10);
    }

    for (uint16_t i = 245; i >= 231; i--)
    {
      colors[i] = (rgb_color) {
        255, 0, 255
      };
      ledStrip.write(colors, LED_COUNT);
      delay(10);
    }

    for (uint16_t i = 245; i >= 231; i--)
    {
      colors[i] = (rgb_color) {
        0, 0, 0
      };
      ledStrip.write(colors, LED_COUNT);
      delay(10);
    }
  }
  //  } else {

  //  Serial.println("sdhkjfhdjkfhkjdfkjd");
  // }
}












