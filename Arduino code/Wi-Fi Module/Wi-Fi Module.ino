#include <ESP8266WiFi.h>

#include <FirebaseArduino.h>

#define WIFI_SSID "ESP8266"
#define WIFI_PASSWORD "password"
#define FIREBASE_HOST "https://agro-ease.firebaseio.com/"
#define FIREBASE_AUTH "27yupv3Tj6WOD9A5gj7jWzmdTTxlmp7lrI8snsQW"

int LED1 = 4;

void setup()
{
Serial.begin(115200);

pinMode(LED1, OUTPUT);

  delay(2000);
  Serial.println('\n');
  
  wifiConnect();

  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);

  delay(10);
}

void loop()
{  
  
Serial.print(Firebase.getString("LED1") + "\n");

analogWrite(LED1, Firebase.getString("LED1").toInt());
delay(10);

if(WiFi.status() != WL_CONNECTED)
{
  wifiConnect();
}
delay(10);

}

void wifiConnect()
{
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);             // Connect to the network
  Serial.print("Connecting to ");
  Serial.print(WIFI_SSID); Serial.println(" ...");

  int teller = 0;
  while (WiFi.status() != WL_CONNECTED)
  {                                       // Wait for the Wi-Fi to connect
    delay(1000);
    Serial.print(++teller); Serial.print(' ');
  }

  Serial.println('\n');
  Serial.println("Connection established!");  
  Serial.print("IP address:\t");
  Serial.println(WiFi.localIP());         // Send the IP address of the ESP8266 to the computer
}
