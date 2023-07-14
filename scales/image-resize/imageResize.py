# -----------------------------------------------------------------------------
#
# Example for image resizing in Python3 with OpenCV.
#
# -----------------------------------------------------------------------------

import cv2

image = cv2.imread("image.png");

image.resize(image.shape[0] // 2, image.shape[1], 3);

cv2.imwrite("imageResized.png", image);
