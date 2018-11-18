struct DataPack{
  int order;
  float gyro;
  float acc;
};
void setup() {
  Serial.begin(9600);
}
void loop() {
  
  DataPack x;
  x.order = 2;
  x.gyro  = 2.33333;
  x.acc   = 6.66666;
  
  char s[10];
  memcpy(s, &x, sizeof(x) );
  for(int i=0;i<10;i++){
    Serial.print(s[i]);
  }
  delay(500);      
}