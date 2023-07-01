#-----------------------------------------------------------------------------
#
# Example for creating gradient 22x1 pixels white-black image
#
#-----------------------------------------------------------------------------

import cv2
import numpy

# Create array for numbers (0, 12, 24, ..., 252)
randomByteArray = bytearray(range(0, 255, 12))

# Write array
cv2.imwrite('GradientLine.jpg', numpy.array(randomByteArray).reshape(22, 1))
