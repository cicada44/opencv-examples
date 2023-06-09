#-----------------------------------------------------------------------------
#
# Converts image to png with OpenCV in Python3
#
#-----------------------------------------------------------------------------

import cv2
import sys

# Read image
image = cv2.imread('img.jpg')

# Write image with png format
cv2.imwrite(sys.argv[1][:-3] + 'png', image)
