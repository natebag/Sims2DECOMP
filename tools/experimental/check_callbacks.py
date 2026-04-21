import os
import re

# Read the DVD map
callbacks = []
with open('extracted/files/u2_ngc_release_dvd.map') as f:
    for line in f:
        if any(cls in line for cls in ['FAMTarget::', 'HUDTarget::', 'E2ETarget::', 'H2DTarget::', 'R2LTarget::']):
            if 'Callback' in line:
                callbacks.append(line.strip())

for line in callbacks:
    print(line)
