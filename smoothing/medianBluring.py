# -----------------------------------------------------------------------------
#
# Example for median bluring
#
# -----------------------------------------------------------------------------

import cv2

img = cv2.imread("../../img.jpg", 0)

# Bluring apply only even numbers
blurred_7 = cv2.medianBlur(img, 7)
blurred_5 = cv2.medianBlur(img, 5)
blurred_3 = cv2.medianBlur(img, 3)

# Then show all of them
cv2.imshow("img", img)
cv2.imshow("blurred_7", blurred_7)
cv2.imshow("blurred_5", blurred_5)
cv2.imshow("blurred_3", blurred_3)

cv2.waitKey()
cv2.destroyAllWindows()
