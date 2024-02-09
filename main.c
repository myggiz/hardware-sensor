#include <ESP8266WiFi.h>
#include <PubSubClient.h>

const char* ssid = "";
const char* password =  "";
//char ssid[] = "";            // your network SSID (name)
//char pass[] = "";        // your network password
//int status = WL_IDLE_STATUS;     // the Wifi radio's status

const char* mqttServer = "";
const int mqttPort = ;
const char* mqttUser = "";
const char* mqttPassword = "";

// SHT3X sht30(0x45);
WiFiClient espClient;
PubSubClient client(espClient);

void setup() {
 
  Serial.begin(115200);
 /*
  WiFi.begin(ssid, password);
 
   while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println("Connecting to WiFi..");
  }
  Serial.println("Connected to the WiFi network");

  client.setServer(mqttServer, mqttPort);
  client.setCallback(callback);
 
  while (!client.connected()) {
    Serial.println("Connecting to MQTT...");
 
    if (client.connect("ESP8266Client", mqttUser, mqttPassword )) {
 
      Serial.println("connected");  
 
    } else {
 
      Serial.print("failed with state ");
      Serial.print(client.state());
      delay(2000);
 
    }
}
 String mac = getMAC();
 Serial.println(mac);
  client.publish("esp/test",String(mac).c_str());
  client.subscribe("esp/test");*/ 
}


void callback(char* topic, byte* payload, unsigned int length) {
 
  Serial.print("Message arrived in topic: ");
  Serial.println(topic);
 
  Serial.print("Message:");
  for (int i = 0; i < length; i++) {
    Serial.print((char)payload[i]);
  }
 
  Serial.println();
  Serial.println("-----------------------");
 
}


void loop() {

  //String mac = getMAC();
  if(sht30.get()==0){
    Serial.print("Temperature in Celsius : ");
    Serial.println(sht30.cTemp);
    Serial.print("Temperature in Fahrenheit : ");
    Serial.println(sht30.fTemp);
    Serial.print("Relative Humidity : ");
    Serial.println(sht30.humidity);
    Serial.println();
  }
  else
  {
    Serial.println("Error!");
  }
  delay(1000);
  // Serial.println(mac);
 // client.loop();
}

String getMAC()
{
  uint8_t mac[6];
  char result[14];

 snprintf( result, sizeof( result ), "%02x%02x%02x%02x%02x%02x", mac[ 0 ], mac[ 1 ], mac[ 2 ], mac[ 3 ], mac[ 4 ], mac[ 5 ] );

  return String( result );
}
