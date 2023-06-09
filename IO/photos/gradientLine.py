#-----------------------------------------------------------------------------
#
# Creates gradient 1x22 pixels line with OpenCV in Python3
#
#-----------------------------------------------------------------------------

import cv2
import numpy

# Create array for numbers (0, 12, 24, ..., 252)
randomByteArray = bytearray(range(0, 255, 12))

# Write array
cv2.imwrite('GradientLine.jpg', numpy.array(randomByteArray).reshape(22, 1))
