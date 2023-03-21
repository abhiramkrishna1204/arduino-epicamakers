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
