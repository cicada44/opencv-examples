#-----------------------------------------------------------------------------
#
# Convert image to black-white format with OpenCV in Python3
#
#-----------------------------------------------------------------------------

import cv2
import sys

# Read image in gray scale
image = cv2.imread('img.jpg', cv2.IMREAD_GRAYSCALE)

# Write that image
cv2.imwrite('ImageGray.jpg', image)
