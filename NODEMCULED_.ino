#include <ESP8266HTTPClient.h>
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <SimpleTimer.h>
#define PIN_LED D1
#define PIN_LDR A0
int nilai;


char auth[] = "YiDcQ3iljCP3DNSV3XGXPLrVYlEkr9YK";
char ssid[] = "Mutia";                                   
char pass[] = "dfkb5150";

SimpleTimer timer;

void ldrsensor () {
  nilai = analogRead(PIN_LDR);
 Serial.print("Nilai LDR: ");
 Serial.println(nilai);
 Blynk.virtualWrite(V1, nilai);
 
 //Jika nilai < dari 400 diasumsikan sudah mulai gelap maka nyalakan lampu
 if (nilai < 50) {
 digitalWrite(PIN_LED, HIGH);
 pinMode(D1, HIGH);
WidgetLED LED(V2);
    LED.on();
 }
 else {
 digitalWrite(PIN_LED, LOW);
 pinMode(D1, LOW);
 WidgetLED LED(V2);
    LED.off();
 }

}
void setup() {
 pinMode(PIN_LED, OUTPUT);
 pinMode(D1, OUTPUT);
 Serial.begin(9600);
 Blynk.begin(auth, ssid, pass);
 timer.setInterval(500L, ldrsensor);
}
void loop() {
 Blynk.run();
timer.run();
delay(100);
}