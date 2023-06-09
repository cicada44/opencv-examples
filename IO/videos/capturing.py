import cv2
import sys

videoCapture = cv2.VideoCapture(sys.argv[1])

fps = videoCapture.get(cv2.CAP_PROP_FPS)
size = (int(videoCapture.get(cv2.CAP_PROP_FRAME_WIDTH)), int(videoCapture.get(cv2.CAP_PROP_FRAME_HEIGHT)))

print("FPS -", fps)
print("size -", size)

videoWriter = cv2.VideoWriter(sys.argv[2], cv2.VideoWriter_fourcc('I','4','2','0'), fps, size)

success, frame = videoCapture.read()

while success: # Loop until there are no more frames.
    videoWriter.write(frame)
    success, frame = videoCapture.read()
