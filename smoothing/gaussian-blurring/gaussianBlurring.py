# -----------------------------------------------------------------------------
#
# Example for Gaussian bluring with OpenCV.
#
# -----------------------------------------------------------------------------

import cv2

img = cv2.imread("../../img.jpg", 0)

# Gaussian bluring
blured_3 = cv2.GaussianBlur(img, (3, 3), 0);
blured_5 = cv2.GaussianBlur(img, (5, 5), 0);
blured_7 = cv2.GaussianBlur(img, (7, 7), 0);

cv2.imshow("blured_3", blured_3)
cv2.imshow("blured_5", blured_5)
cv2.imshow("blured_7", blured_7)

cv2.waitKey()
cv2.destroyAllWindows()
