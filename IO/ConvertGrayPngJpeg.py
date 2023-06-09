import cv2
import sys

image = cv2.imread(sys.argv[1], cv2.IMREAD_GRAYSCALE)
cv2.imwrite(sys.argv[1][:-3] + 'png', image)
