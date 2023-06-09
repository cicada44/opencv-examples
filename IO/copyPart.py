import cv2
import sys

image1 = cv2.imread(sys.argv[1])
image2 = cv2.imread(sys.argv[2])

image2[400:600, 400:600] = image1[0:200, 0:200]

cv2.imwrite("withPart.png", image2)
