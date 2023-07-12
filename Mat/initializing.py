# -----------------------------------------------------------------------------
# 
#  Example for cv2.Mat initializing in Python3
# 
# -----------------------------------------------------------------------------

import cv2
import numpy as np

A = np.zeros((2, 2, 3), dtype=np.uint8)
A[:] = (0, 0, 255)

B = np.zeros((3, 3, 3), dtype=np.uint8)  # Cannot assign matrix values in this case
C = np.eye(4, 4, dtype=np.float64)  # MatLab style
D = np.zeros((2, 2), dtype=np.float32)  # MatLab style
E = np.ones((2, 2), dtype=np.uint8)  # MatLab style

F = np.array([[0, -1, 0], [-1, 5, -1], [0, -1, 0]], dtype=np.int32)  # For small matrices we have troubles...
G = np.array([0, -1, 0, -1, 5, -1, 0, -1, 0], dtype=np.float64).reshape(3, 3)  # For small matrices we have troubles...

R = np.zeros((400, 400, 3), dtype=np.uint8)  # Init Mat with random values
cv2.randu(R, 0, 255)  # Generate random values in R

print("\nA (common)\n", A)
print("\nB (NumPy)\n", B)
print("\nC (MatLab)\n", C)
print("\nD (CSV)\n", D)
print("\nE (C)\n", E)
print("\nF (Python)\n", F)
print("\nG (Default)\n", G)

cv2.imshow("R", R)  # Display image
cv2.waitKey()  # Wait for a key press
cv2.destroyAllWindows()  # Close all windows

