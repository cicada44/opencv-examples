# -----------------------------------------------------------------------------
#
# Example for info of cv.Mat type in Python3 with OpenCV.
#
# -----------------------------------------------------------------------------

import cv2

image = cv2.imread("image.png")

if image is None:
    exit(-1)

print("Size:", image.size)
print("Shape:", image.shape)
print("Data type:", image.dtype)
print("Item size:", image.itemsize)
print("Number of dimensions:", image.ndim)
print("Number of channels:", image.shape[2])
print("Number of rows:", image.shape[0])
print("Number of columns:", image.shape[1])
print("Total number of elements:", image.size)
print("Size of each element:", image.itemsize)
print("Size of each element without channels:", image.itemsize // image.shape[2] if len(image.shape) == 3 else image.itemsize)

