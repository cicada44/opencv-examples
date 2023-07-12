#-----------------------------------------------------------------------------
#
# Example for images input/output in Python3.
#
#-----------------------------------------------------------------------------

import cv2

# Read image with standard colors.
img = cv2.imread("../img.jpg")

# Read image with grayscale colors.
imgGrayscale = cv2.imread("../img.jpg", cv2.IMREAD_GRAYSCALE)

# Save image.
cv2.imwrite("img.jpg", img)

# For byte-IO:
#     cv2.imdecode()
#     cv2.imencode()
