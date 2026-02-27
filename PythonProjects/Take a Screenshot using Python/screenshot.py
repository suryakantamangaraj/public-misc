import os
import pyautogui

path = os.path.join(os.path.expanduser('~'), 'Pictures')

def screenshot():
    my_screenshot = pyautogui.screenshot()
    my_screenshot.save(f"{path}\\screenshot_new.png")
    print("Screenshot saved!")

if __name__ == "__main__":
    screenshot()