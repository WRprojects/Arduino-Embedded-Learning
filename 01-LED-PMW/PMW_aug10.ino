int potPin = A0;
int potVal;
float pwmConversion;
int pwmValue;
int pwmPin = 9;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(potPin,INPUT);
  pinMode(pwmPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  potVal = analogRead(potPin);
  pwmConversion = (potVal / 1023.0) * 255;
  pwmValue = round(pwmConversion);
  analogWrite(pwmPin, pwmValue);
  Serial.print("Pot Value: ");
  Serial.println(potVal);
  Serial.print("PWM Value: ");
  Serial.println(pwmConversion);
  Serial.println(pwmValue);
}
