import cv2
import sys
import time

cap = cv2.VideoCapture(0)
cap.set(cv2.CAP_PROP_FRAME_WIDTH, 640)
cap.set(cv2.CAP_PROP_FRAME_HEIGHT, 480)
if not cap.isOpened():
  print("camera open error")
  exit()

while True:
  ret, image = cap.read() # ret에 이미지가 읽어졌는지 알려줌
  if not ret:
    print("frame read error")
    break
  cv2.imshow('CAMERA', image)
  if cv2.waitKey(1)&0xFF == ord('q'):
    break

  time.sleep(10)
