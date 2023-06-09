import cv2 as cv

# Open the first available camera in device
cap = cv.VideoCapture(0)

# Check the state of camera
if not cap.isOpened():
    print("Cannot open camera")
    exit

# Input&output the frame red from camera
while True:
    # Read frame from camera (image)
    ret, frame = cap.read()

    # Check the state
    if not ret:
        print("Can't receive frame, exiting...")
        exit()

    gray = cv.cvtColor(frame, cv.COLOR_BGR2GRAY)

    # Show image
    cv.imshow('frame', gray)

    # quit button
    if cv.waitKey(1) == ord('q'):
        break

# Cleanup...
cap.release()
cv.destroyAllWindows()
