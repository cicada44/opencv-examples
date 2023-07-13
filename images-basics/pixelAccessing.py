#-----------------------------------------------------------------------------
#
# Example for pixel accessing in Python.
#
#-----------------------------------------------------------------------------

import cv2
import numpy as np

img = cv2.imread("../img.jpg", cv2.IMREAD_COLOR)

# Access to (0, 0) coordinates pixel.
intensity1 = img[0, 0]

print("(0, 0) -", intensity1)

# Another way.
intensity2 = {img.item(0), img.item(1), img.item(2)}

print("(100, 50) -", intensity2)

intensity3 = img[0, 0]

print("\nB -", intensity3[0])
print("G -", intensity3[1])
print("R -", intensity3[2])

# And pixel changing.
img[0, 0] = 128
