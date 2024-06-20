#include <Servo.h>

Servo myservo;

int val;
int SW[] = {2,3}; // 스위치에 연결할 핀 (left : 2, right : 3)

void setup() {
  Serial.begin(9600);
  // 서보 모터 데이터 핀을 아두이노의 9번 핀에 연결
  myservo.attach(9);
  // 핀을 입력으로 설정
  pinMode(SW[0], INPUT);
  pinMode(SW[1], INPUT);
  // 내부 풀업 저항을 활성화
  digitalWrite(SW[0], HIGH);
  digitalWrite(SW[1], HIGH);
}

void loop() {

  
  // 왼쪽 스위치의 값을 읽음
  val = digitalRead(SW[0]);
  // 스위치가 눌러진 경우 서보를 0도 위치로 이동
  if (val != 1) {    
    myservo.write(5);    
    // 서보가 위치에 도달할 때까지 지연
    delay(50);
  }

  // 오른쪽 스위치의 값을 읽음
  val = digitalRead(SW[1]);
  // 스위치가 눌러진 경우 서보를 180도 위치로 이동
  if (val != 1) {
    myservo.write(170);
    delay(50);
  }
}
