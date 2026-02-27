#Create a freeze.py Script to freeze your Flask app
from app import app, freezer

if __name__ == '__main__':
    freezer.freeze()
