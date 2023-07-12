#-----------------------------------------------------------------------------
#
# Example for cv2.Mat sharpening in Python3.
#
#-----------------------------------------------------------------------------
#
# Hand-written version of cv2.filter2D function.
#
#------------------------------------------------------------------------------

import cv2
import numpy as np

def is_grayscale(inputImg):
    return len(inputImg.shape) < 3

def saturated(sum_value):
    if sum_value > 255:
        sum_value = 255
    if sum_value < 0:
        sum_value = 0
    return sum_value

inputImg = cv2.imread("../img.jpg", cv2.IMREAD_COLOR)

height, width, n_channels = inputImg.shape

cv2.namedWindow("input")
cv2.namedWindow("output")

outputImg = np.zeros_like(inputImg)

# Sharpening part.
for j in range(1, height - 1):
    for i in range(1, width - 1):
        if is_grayscale(inputImg):
            sum_value = 5 * inputImg[j, i] - inputImg[j + 1, i] - inputImg[j - 1, i] - inputImg[j, i + 1] - inputImg[j, i - 1]
            outputImg[j, i] = saturated(sum_value)
        else:
            for k in range(0, n_channels):
                sum_value = 5 * inputImg[j, i, k] - inputImg[j + 1, i, k] \
                - inputImg[j - 1, i, k] - inputImg[j, i + 1, k]\
                - inputImg[j, i - 1, k]
                outputImg[j, i, k] = saturated(sum_value)

cv2.imshow("input", inputImg)
cv2.imshow("output", outputImg)

cv2.waitKey()
cv2.destroyAllWindows()
