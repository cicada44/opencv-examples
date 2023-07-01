#-----------------------------------------------------------------------------
#
# Example for copying part of photo to another
#
#-----------------------------------------------------------------------------

import cv2

# Read image to copy from
image1 = cv2.imread('FromCopy.jpg')

# Read image to past to
image2 = cv2.imread('DestCopy.jpg')

image2[400:600, 400:600] = image1[0:200, 0:200]

cv2.imwrite("withPart.png", image2)
