import cv2
import os
import sys
import numpy

img = cv2.imread(sys.argv[1])

randomByteArray = bytearray(range(0, 100, 10))
cv2.imwrite(sys.argv[2], numpy.array(randomByteArray).reshape(10, 1))
