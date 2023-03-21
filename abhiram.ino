#include "Ubidots.h"
#include<PubSubClient.h>
/****************************************
 * Define Constants
 ****************************************/
#define TOKEN "********" // BBFF-xC02d3i0ikshgVhXERxacspctEfszB
#define WIFINAME "******" //abhiram 4184
#define WIFIPASS "******" // 12345678

Ubidots client(TOKEN);

/****************************************
 * Auxiliar Functions
 ****************************************/

void callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] ");
  for (int i=0;i<length;i++) {
    Serial.print((char)payload[i]);
  }
  Serial.println();
}

/****************************************
 * Main Functions
 ****************************************/

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  client.setDebug(true); // Pass a true or false bool value to activate debug messages
  client.wifiConnection(WIFINAME, WIFIPASS);
  client.begin(callback);
  }

void loop() {
  // put your main code here, to run repeatedly:
  if(!client.connected()){
      client.reconnect();
      }

  // Publish values to 2 different data sources
 for(int i=0;i<50;i++)
 {
      client.add("testvalues",i); //Insert your variable Labels and the value to be sent
      client.ubidotsPublish("tutorial");
 
 
  client.loop();
  delay(20000);
  }
}
6. Output
After successful uploading of the code, output will display on the ubidots Devices.


int fsrPin = A0;
int fsrReading;
int fsrVoltage;
unsigned long fsrResistance;
unsigned long fsrConductance;
long fsrForce;
void setup(void) {
  Serial.begin(9600);
}
void loop(void) {
  fsrReading = analogRead(fsrPin);
  Serial.print("Analog reading = ");
  Serial.println(fsrReading);

  fsrVoltage = map(fsrReading, 0, 1023, 0, 3000);
  Serial.print("Voltage reading in mv= ");
  Serial.println(fsrVoltage);

  if(fsrVoltage == 0){
    Serial.println("no pressure");
    } else {
      fsrResistance = 3000 - fsrVoltage;
      fsrResistance *= 4700;
      fsrResistance /= fsrVoltage;
      Serial.print("FSR resistance in ohms = ");
      Serial.println(fsrResistance);

      fsrConductance = 470000;
      fsrConductance /= fsrResistance;
      Serial.print("conductance in microMhos: ");
      Serial.println(fsrConductance);

      if(fsrConductance <= 1000){
        fsrForce = fsrConductance/80;
        Serial.print("Force in Newtons: ");
        Serial.println(fsrForce);
      } else {
        fsrForce = fsrConductance - 1000;
        fsrForce /= 30;
        Serial.print("Force in Newtons; ");
        Serial.println(fsrForce);
      }
   
       
       
   
}
    Serial.println("-------------");
    delay(1000);
   
}
