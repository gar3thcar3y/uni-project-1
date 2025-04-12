
const int resistance = 100000;
const int thermistor_val = 4275000;
const int pin = A0;
float voltage;
float temperature;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  voltage = (float) (5 / 1024.0) * (analogRead(pin)-1);
  Serial.println(voltage);
  temperature = 1.0/(log(voltage/5.0)/thermistor_val+1/298.15)-273.15;
  Serial.println(temperature);
  delay(1000);
}
