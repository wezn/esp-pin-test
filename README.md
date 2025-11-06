How to Test Systematically:

Step 1: Upload this new code

Step 2: Open Serial Monitor via screen

Step 3: You'll see all pins listed like:

Pin  1: 🔵 HIGH (touch to GND)

Pin  2: 🔵 HIGH (touch to GND) 

Pin  3: 🔵 HIGH (touch to GND)

...

Step 4: Test Method:


    Look for pins showing 🔵 HIGH

    Take your wire from GND to that pin

    Wait for the display to refresh (5 seconds)

    If it changes to 🔴 LOW = WORKING PIN!

    If stays 🔵 HIGH = BROKEN PIN


Step 5: Keep track of working pins
