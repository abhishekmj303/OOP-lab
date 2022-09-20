import time
from pynput.keyboard import Key, Controller

# Complete path to the code
file_path = "/home/abhishek/Programs/OOP/lab6/clinklist.cpp"

# "\t" if indented using tab
indent_string = "    "

# Delay to start typing the code in seconds
initial_delay = 5

# Delay between each letter while typing in seconds
key_delay = 0.005

# TODO: Add kill switch (like ctrl+c)

time.sleep(initial_delay)
keyboard = Controller()
with open(file_path, "r") as f:
    code = f.read()

    code = code.replace(indent_string, "")
    count = code.count("{")
    for a in code:
        keyboard.type(a)
        time.sleep(key_delay)

    time.sleep(0.5)
    with keyboard.pressed(Key.shift):
        for i in range(count):
            keyboard.press(Key.down)
            keyboard.release(Key.down)
    keyboard.press(Key.backspace)
    keyboard.release(Key.backspace)
