# -----------------------------------------------------------------------------
#
# Example for highlight blue shades from RGB on Python3 with OpenCV.
#
# -----------------------------------------------------------------------------

import numpy as np
import cv2

imageRGB = cv2.imread("image.png")

if imageRGB is None:
    exit(-1)

lowerBlue = np.array([15, 15, 0])
upperBlue = np.array([130, 170, 255])

mask = cv2.inRange(imageRGB, lowerBlue, upperBlue)

blueRegions = cv2.bitwise_and(imageRGB, imageRGB, mask=mask)

cv2.imwrite("imageBlue.png", blueRegions)
