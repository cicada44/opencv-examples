#-----------------------------------------------------------------------------
#
# Example for contrast and brightness changing in Python.
#
#-----------------------------------------------------------------------------
#
# Hand-written version of cv2.convertScaleAbs() function.
#
#------------------------------------------------------------------------------

import cv2
import numpy as np

def saturate_cast(value, dtype):
    return np.clip(value, np.iinfo(dtype).min, np.iinfo(dtype).max).astype(dtype)

alpha = 2
beta = -50
src = cv2.imread("../img.jpg")
img = cv2.imread("../img.jpg")

# Change all pixels using the formula `A*pixel + B`.
for i in range(img.shape[0]):
    for j in range(img.shape[1]):
        for c in range(img.shape[2]):
            img[i, j, c] = saturate_cast(
                alpha * img[i, j, c] + beta, dtype=img.dtype
            )

cv2.namedWindow("new")
cv2.imshow("new", img)
cv2.namedWindow("src")
cv2.imshow("src", src)

cv2.waitKey(0)
cv2.destroyAllWindows()
