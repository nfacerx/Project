#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>

int MOTOR1 = D1;

int MOTOR2 = D2;

int MOTOR3 = D3;

int MOTOR4 = D4;

#define FIREBASE_HOST "lightsaber-f9e99.firebaseio.com"
#define FIREBASE_AUTH "o2RTrC9OskhvotJtIYtGXesCVWHX3M04hQZlviUT"

#define WIFI_SSID "A406"
#define WIFI_PASSWORD "maxzdrum1234"


void setup() {

  pinMode(MOTOR1, OUTPUT);

  pinMode(MOTOR2, OUTPUT);

  pinMode(MOTOR3, OUTPUT);

  pinMode(MOTOR4, OUTPUT);

  Serial.begin(115200);

  WiFi.mode(WIFI_STA);

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.println("CONNECTING Plz WAIT");

  while (WiFi.status() != WL_CONNECTED) {
    Serial.println(".");
    delay(500);
  }

  Serial.println("CONNECTED !!");
  Serial.println(WiFi.localIP());

  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  Firebase.set("LIGHTOPEN", 0
              );
  Firebase.set("MOTOROPEN", 4);

  // put your setup code here, to run once:
}

void loop() {

  int TestingFirebase2 = Firebase.getInt("MOTOROPEN");
  Serial.println(TestingFirebase2);
  if (TestingFirebase2 == 0) {
    digitalWrite(MOTOR1, HIGH);
    
    digitalWrite(MOTOR2, HIGH);

    digitalWrite(MOTOR3, LOW);

    digitalWrite(MOTOR4, LOW);


  }
  if (TestingFirebase2 == 1) {
    digitalWrite(MOTOR1, LOW);
    
    digitalWrite(MOTOR2, LOW);

    digitalWrite(MOTOR3, HIGH);

    digitalWrite(MOTOR4, HIGH);

  }
  if (TestingFirebase2 == 2) {
    digitalWrite(MOTOR1, HIGH);
    
    digitalWrite(MOTOR2, LOW);

    digitalWrite(MOTOR3, HIGH);

    digitalWrite(MOTOR4, LOW);

  }
  if (TestingFirebase2 == 3) {
    digitalWrite(MOTOR1, LOW);
    
    digitalWrite(MOTOR2, HIGH);

    digitalWrite(MOTOR3, LOW);

    digitalWrite(MOTOR4, HIGH);

  }
  if (TestingFirebase2 == 4) {
    digitalWrite(MOTOR1, LOW);
    
    digitalWrite(MOTOR2, LOW);

    digitalWrite(MOTOR3, LOW);

    digitalWrite(MOTOR4, LOW);

  }

  delay(200);
  // put your main code here, to run repeatedly:

}
