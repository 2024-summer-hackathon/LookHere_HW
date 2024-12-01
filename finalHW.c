  #include <Adafruit_NeoPixel.h>

  // 네오픽셀 LED의 데이터 핀
  #define PIN 9

  // 네오픽셀 LED의 개수
  #define NUMPIXELS 8 

  // 조도 센서 핀
  #define LIGHT_SENSOR_PIN A0 

  // 네오픽셀 객체 생성sf
  Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800); 

  void setup() {
    // 시리얼 통신 초기화
    Serial.begin(9600);

    // 네오픽셀 초기화
    pixels.begin();
    
    // 초기 LED 상태 설정 (LED 끄기)
    for (int i = 0; i < NUMPIXELS; i++) {
      pixels.setPixelColor(i, pixels.Color(0, 0, 0));
    }
    pixels.show();
  }
  
  void loop() {
    // 조도 센서 값 읽기 (0~1023)
    int lightLevel = analogRead(LIGHT_SENSOR_PIN);

    // 시리얼 모니터에 조도 센서 값 출력
    Serial.print("Light Level: ");
    Serial.println(lightLevel);

    // 조도 센서 값에 따라 LED의 밝기 설정
    int brightness;
    if (lightLevel >= 700) {
      brightness = 255; // 최고 밝기
    } else if (lightLevel >= 600) {
      brightness = map(lightLevel, 600, 699, 80, 255); // 중간 정도 밝기에서 최고 밝기까지 선형적으로 변화
    } else {
      brightness = map(lightLevel, 0, 599, 0, 80); // 어두운 밝기에서 중간 정도 밝기까지 선형적으로 변화
    }
  
    // 모든 LED의 밝기 설정
    for (int i = 0; i < NUMPIXELS; i++) {
      pixels.setPixelColor(i, pixels.Color(brightness, brightness, brightness)); // 밝기에 따라 LED 설정
    }
    pixels.show();

    // 짧은 딜레이
    delay(50);
  }
