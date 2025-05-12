#include <Wire.h>                // I2C 통신을 위한 Wire 라이브러리 포함
#include <LiquidCrystal_I2C.h>   // I2C LCD를 제어하기 위한 LiquidCrystal_I2C 라이브러리 포함

LiquidCrystal_I2C lcd(0x27, 16, 2);  // I2C LCD 객체 생성 (주소 0x27, 16x2 크기)

#define TRIG 13    // 초음파 센서의 TRIG 핀을 13번으로 설정
#define ECHO 12    // 초음파 센서의 ECHO 핀을 12번으로 설정

void setup() {
  Serial.begin(9600);        // 시리얼 통신 초기화 (9600 보드레이트)
  lcd.init();                // LCD 초기화
  lcd.backlight();           // LCD 백라이트 켜기
  lcd.print("LCD init");     // LCD에 "LCD init" 텍스트 출력
  delay(2000);               // 2초 대기 (초기화 메시지 확인 시간)
  lcd.clear();               // LCD 화면 지우기
  pinMode(TRIG, OUTPUT);     // TRIG 핀을 출력 모드로 설정
  pinMode(ECHO, INPUT);      // ECHO 핀을 입력 모드로 설정
}

void loop() {
    long duration, distance;

    // 초음파 거리 측정을 위한 트리거 신호 발생
    digitalWrite(TRIG, LOW);          
    delayMicroseconds(2);             
    digitalWrite(TRIG, HIGH);         
    delayMicroseconds(10);            
    digitalWrite(TRIG, LOW);          
  
    duration = pulseIn(ECHO, HIGH);   // ECHO 핀에서 HIGH 상태의 지속 시간 측정

    distance = duration / 58.2;       // 거리 계산 (duration을 58.2로 나누어 CM 단위로 변환)

    // 계산된 거리 값을 LCD에 출력
    lcd.print(distance);              // 거리 출력
    lcd.print("CM");                  // "CM" 텍스트 추가
    delay(1000);                      // 1초 대기 (출력 간 간격)
    lcd.clear();                      // 출력 후 LCD 화면을 비움
}

