#include <Adafruit_NeoPixel.h>

#define PIN 9           // 네오픽셀 LED의 데이터 핀
#define NUMPIXELS 8     // 네오픽셀 LED의 개수

// 네오픽셀 객체 생성
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  // 네오픽셀 초기화
  pixels.begin();
  
  // 초기 LED 상태 설정 (LED 끄기)
  for (int i = 0; i < NUMPIXELS; i++) {
    pixels.setPixelColor(i, pixels.Color(0, 0, 0));  // LED 끄기
  }
  pixels.show();
}

void loop() {
  // 밝기 값 (예시: 255)
  int brightness = 255;

  // 모든 LED의 밝기 설정
  for (int i = 0; i < NUMPIXELS; i++) {
    pixels.setPixelColor(i, pixels.Color(brightness, brightness, brightness)); // 밝기에 따라 LED 설정
  }
  pixels.show();

  // 짧은 딜레이
  delay(50);
}
