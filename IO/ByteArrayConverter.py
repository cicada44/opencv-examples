import cv2
import os
import sys
import numpy

img = cv2.imread(sys.argv[1])

randomByteArray = bytearray(os.urandom(120000))
flatNumpyArray = numpy.array(randomByteArray)

grayImg = flatNumpyArray.reshape(300, 400)
cv2.imwrite(sys.argv[2], grayImg.reshape(100, 400, 3))
