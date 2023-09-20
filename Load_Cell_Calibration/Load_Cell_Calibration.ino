// Template ID, Device Name and Auth Token are provided by the Blynk.Cloud
// See the Device Info tab, or Template settings

#define BLYNK_TEMPLATE_ID "TMPLeqMU7c0X"
#define BLYNK_TEMPLATE_NAME "AR using ESP32"
#define BLYNK_AUTH_TOKEN "uVoQYaUvojsrBPta4c-GrS41eyaReQJX"

// Comment this out to disable prints and save space
#define BLYNK_PRINT Serial

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

char auth[] = BLYNK_AUTH_TOKEN;

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "Sam's Poco";
char pass[] = "gggggggh";






BlynkTimer timer;



int relay1_state = 0;
int relay2_state = 0;
int relay3_state = 0;

//Change the virtual pins according the rooms
#define button1_vpin    V1
#define button2_vpin    V2
#define button3_vpin    V3
#define button4_vpin    V4
#define temp_vpin    V5
#define power_vpin    V6

// This function is called every time the device is connected to the Blynk.Cloud
// Request the latest state from the server
BLYNK_CONNECTED() {
  Blynk.syncVirtual(button1_vpin);
  Blynk.syncVirtual(button2_vpin);
  Blynk.syncVirtual(button3_vpin);
  Blynk.syncVirtual(button4_vpin);
}

// This function is called every time the Virtual Pin state change
//i.e when web push switch from Blynk App or Web Dashboard
BLYNK_WRITE(button1_vpin) {
  relay1_state = param.asInt();
  int randomNumber = random(1, 90);  // Range is from 1 to 100
  Blynk.virtualWrite(power_vpin, randomNumber);
  delay(100);
}

BLYNK_WRITE(button2_vpin) {
  relay2_state = param.asInt();
  int randomNumber = random(90, 111);  // Range is from 1 to 100
  Blynk.virtualWrite(power_vpin, randomNumber);
  delay(100);
}

BLYNK_WRITE(button3_vpin) {
  relay3_state = param.asInt();
  int randomNumber = random(110, 200);  // Range is from 1 to 100
  Blynk.virtualWrite(power_vpin, randomNumber);
  delay(100);
}

BLYNK_WRITE(button4_vpin) {
  relay3_state = param.asInt();
  int randomNumber = 0;  // Range is from 1 to 100
  Blynk.virtualWrite(power_vpin, randomNumber);
  delay(100);
}

void setup()
{
   Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
  int P=0;
  Blynk.virtualWrite(power_vpin, P);
  delay(100);
}

void loop()
{
  Blynk.run();
  timer.run();
  

  int t = 1;
  Blynk.virtualWrite(temp_vpin, t);
}