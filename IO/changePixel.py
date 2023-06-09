import cv2
import os
import sys

image = cv2.imread(sys.argv[1])

print(image.item(0, 0, 0))

image.itemset((0, 0, 0), 127)

print(image.item(0, 0, 0))
