"""
Star tracker image testing code.
Used to generate images that we can test our star tracker code on

Based off the method used in the paper "A Star Tracker Design for CubeSats" by Christopher McBryde at UT Austin
"""
import numpy as np
from skimage import io, util
import math as math

# Constants for image generation
N_POINTS = 500  # how many points the star photons will be divided
BLUR_FACTOR = 3 # Blur factor
T_EXP = 25      # Exposure time (s)
TAU = 1         # Transmittance constant
FOCAL_LEN = 66.8    # Camera focal length (mm)
APER_DIAMETER = 2.5 # Aperture diameter (cm)
FOV = 20            # Field of View (degrees)
LAMBDA = 0.6        # Spectral range (micro meters)
SAT_LIMIT = 135000  # Saturation limit (photons)
DYNAMIC_RANGE = 69  # Dynamic Range (dB)

def main():
    pass

# gets a random attitude
def get_random_attitude():
    theta1 = random.uniform(-180, 180)
    theta2 = random.uniform(-180, 180)
    theta3 = random.uniform(-180, 180)
    attitude = np.array([theta1, theta2, theta2])

# produces and returns the rotaiton matrix from the intertial
# to the camera frame.
def get_rot_matrix(attitude):
    theta1 = attitude[0]
    theta2 = attitude[1]
    theta2 = attitude[3]
    R1 = np.array([1, 0, 0],
                  [0, cos(theta1), sin(theta1)],
                  [0, -sin(theta1), cos(theta1)])
    R2 = np.array([cos(theta2), 0, -sin(theta2)],
                  [0, 1, 0],
                  [sin(theta2), 0, cos(theta2)])
    R3 = np.array([cos(theta3), sin(theta3), 0],
                  [-sin(theta3), cos(theta3), 0],
                  [0, 0, 1])
    rot = R3 * R2 * R1
    return rot

# 
def generate_image(attitude, rot, catalog, fov):
    # unit vector along the boresight direction, found
    # in the intertial coordinate frame
    ubore = rot.T * np.array([0, 0, 1]).T

    # check each star in the catalog to see if it lies in the
    # FOV of the camera
    for star in catalog:
        # see if it is in threshold
        if ubore.T * star > cos(fov / 2):
            # convert unit vector to camera frame
            ustarc = rot * star
            # coordinates of star on image plane
            u = -(FOCAL_LEN * star[0] / star[2])
            v = -(FOCAL_LEN * star[1] / star[2])

            # number of photons the star generations
            S = T_EXP * ((math.pi / 4) * APER_DIAMETER ** 2) * TAU * LAMBDA * (10 ** -0.4)

            



