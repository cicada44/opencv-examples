# -----------------------------------------------------------------------------
#
# Example for translation image from RGB to HSV color space on Python3 with OpenCV.
#
# -----------------------------------------------------------------------------

import cv2

imageRGB = cv2.imread("image.png");

if imageRGB is None:
    exit(-1)

imageHSV = cv2.cvtColor(imageRGB, cv2.COLOR_RGB2HSV);

cv2.imwrite("imageHSV.png", imageHSV);
