import time
import threading, _thread
from pynput.keyboard import Key, Controller, Listener, HotKey

# Complete path to the code
file_path = "/home/abhishek/Programs/OOP/lab7/bank.cpp"

# "\t" if indented using tab
indent_string = "    "

# Delay to start typing the code in seconds
initial_delay = 5

# Delay between each letter while typing in seconds
key_delay = 0.1

# Note: Kill the program from typing the code by pressing <alt>+c
# Kill Switch
switch = '<alt>+c'

def type_code():
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

def kill_switch():

    def on_activate():
        _thread.interrupt_main()
        exit()

    def for_canonical(f):
        return lambda k: f(l.canonical(k))

    hotkey = HotKey(HotKey.parse(switch), on_activate)
    with Listener(
            on_press=for_canonical(hotkey.press),
            on_release=for_canonical(hotkey.release)) as l:
        l.join()

if __name__ == "__main__":
    threading.Thread(target=kill_switch).start()
    time.sleep(initial_delay)
    type_code()