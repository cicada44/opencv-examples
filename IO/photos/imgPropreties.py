#-----------------------------------------------------------------------------
#
# Prints information about image with OpenCV in Python3
#
#-----------------------------------------------------------------------------

import cv2

# Read image
image = cv2.imread('img.jpg')

# Print size of image in pixels
print("Size -", image.size)

# Print width and height
print("Shape -", image.shape)

# Print datatype of image pixels
print("Datatype -", image.dtype)
