#define LIGHT_SENSOR_PIN A0  // 조도 센서 핀

void setup() {
  // 시리얼 통신 초기화
  Serial.begin(9600);
}

void loop() {
  // 조도 센서 값 읽기 (0~1023)
  int lightLevel = analogRead(LIGHT_SENSOR_PIN);

  // 시리얼 모니터에 조도 센서 값 출력
  Serial.print("Light Level: ");
  Serial.println(lightLevel);

  // 짧은 딜레이
  delay(500);  // 500ms 대기
}
