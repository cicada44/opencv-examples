#-----------------------------------------------------------------------------
#
# Example for images blending in Python with OpenCV.
#
#-----------------------------------------------------------------------------

import cv2

img1 = cv2.imread("../img.jpg", cv2.IMREAD_COLOR)
img2 = cv2.imread("../img.jpg", cv2.IMREAD_COLOR)

img2 = cv2.flip(img1, 0)

# Blend for 50%.
result = cv2.addWeighted(img1, 0.5, img2, 0.5, 0.0)

cv2.namedWindow("blending")
cv2.imshow("blending", result)

cv2.waitKey(0)
cv2.destroyAllWindows()
