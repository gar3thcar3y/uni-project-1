#include <math.h>

const int resistance = 100000;
const int thermistor_val = 4275000;
#define PI 3.14159
const int pin = A0;
float voltage;
float temperature;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

float* DFT(float temps[]){
  float* temps_frequecy = (float*)malloc(20 * sizeof(float));
  float sum_R, sum_I;

  for(int k = 0; k < 10; k++){
    sum_R = 0; sum_I = 0;
    for(int n = 0; n < 10; n++){
      sum_R += (float) temps[n] * cos(-2*PI*k*n/10);
      sum_I += (float) temps[n] * sin(-2*PI*k*n/10);
    }
    temps_frequecy[k] = sum_R;
    temps_frequecy[10+k] = sum_I;
  }
  
  return temps_frequecy;
}


float temp_values_TD[10];
float* temp_values_FD;
int current_index = 0;

void loop() {
  // put your main code here, to run repeatedly:
  
  voltage = (float) (5 / 1024.0) * (analogRead(pin)-1);
  Serial.println(voltage);
  temperature = 1.0/(log(voltage/5.0)/thermistor_val+1/298.15)-273.15;
  Serial.println(temperature);
  delay(1000);
  temp_values_TD[current_index] = temperature;
  for(int i=0;i<10;i++){Serial.println(temp_values_TD[i]);}
  current_index += 1;
  if (current_index >= 10){
    current_index = 0;
    temp_values_FD = DFT(temp_values_TD);
    for(int i=0;i<20;i++){Serial.println((*temp_values_FD+i));}
  }
}
