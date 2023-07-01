#-----------------------------------------------------------------------------
#
# Example for making image whole-black
#
#-----------------------------------------------------------------------------

import cv2

# Read image
image = cv2.imread('img.jpg')

# Fill image black pixels
image[:, :] = (0, 0, 0)

# Write new image
cv2.imwrite('BlackImage.png', image)
