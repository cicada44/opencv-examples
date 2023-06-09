import cv2
import sys

camera = cv2.VideoCapture(0)

size = (int(camera.get(cv2.CAP_PROP_FRAME_WIDTH)), int(camera.get(cv2.CAP_PROP_FRAME_HEIGHT)))

fps = 10

videoWriter = cv2.VideoWriter('OutputVideo.avi', cv2.VideoWriter_fourcc('I', '4', '2', '0'), fps, size)

success, frame = camera.read()

numFramesRemaining = 10 * fps - 1

while success and numFramesRemaining > 0:
    print("Remains -", numFramesRemaining)
    videoWriter.write(frame)
    success, frame = camera.read()
    numFramesRemaining -= 1

camera.release()
