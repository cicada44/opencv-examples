import cv2
import sys

video1 = cv2.VideoCapture(sys.argv[1])
videoWriter = cv2.VideoWriter(sys.argv[2], cv2.VideoWriter_fourcc('F','L','V','1'), 30, (1280, 720))

success, frame = video1.read()

frameToReplace = cv2.imread("deepFakeEgor.jpg")

while success:
    frame[250:500, 350:700] = frameToReplace[250:500, 350:700]
    videoWriter.write(frame)
    success, frame = video1.read()
