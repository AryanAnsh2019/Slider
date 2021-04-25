#define BLYNK_PRINT Serial
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
char ssid[]="Ktayal";
char pass[]="1357924680";
char auth[]="44004249418e42a9ba74b705343b1ccf"; 
int brightness;
BLYNK_WRITE(V1)
{
  brightness = param.asInt();
  analogWrite(15, brightness);
  Serial.print(brightness);
}
void setup() 
{
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
  pinMode(15,OUTPUT);
  WiFi.mode(WIFI_STA);
  if (WiFi.status() != WL_CONNECTED)
  {
    Serial.print("Attempting to connect to SSID: ");
    Serial.println(ssid);
    while (WiFi.status() != WL_CONNECTED)
    {
      WiFi.begin(ssid, pass);
      Serial.print(".");
      delay(5000);
    }
    Serial.println("\nConnected.");
  }
}
void loop() 
{ 
  Blynk.run();
}
