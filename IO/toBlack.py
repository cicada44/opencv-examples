import cv2
import sys

image = cv2.imread(sys.argv[1])

image[:, :] = (0, 0, 0)

newimg = image

cv2.imwrite('wholeblack.png', newimg)
