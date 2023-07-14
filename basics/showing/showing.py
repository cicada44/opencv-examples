#-----------------------------------------------------------------------------
#
# Example for showing image in Python with OpenCV.
#
#-----------------------------------------------------------------------------

import cv2

img = cv2.imread("../img.jpg", cv2.IMREAD_COLOR)

# Create window with name "image".
cv2.namedWindow("image")

# Show image into created window.
cv2.imshow("image", img)

# Press any key to quit.
cv2.waitKey(0)
cv2.destroyAllWindows()
