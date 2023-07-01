#-----------------------------------------------------------------------------
#
# Example for creating 10x10 pixels gray image
#
#-----------------------------------------------------------------------------

import cv2
import numpy

# Create size 100 bytearray
byteArray = bytearray(100)

# Create from it numpy array and fill it gray pixels
numpyArray = numpy.array(byteArray)
numpyArray[:] = 127

# Write it via imwrite
cv2.imwrite('GrayImage.jpg', numpyArray.reshape(10, 10))
