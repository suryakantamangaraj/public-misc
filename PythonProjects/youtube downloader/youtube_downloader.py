from __future__ import unicode_literals
import youtube_dl
import os

path = os.path.join(os.path.expanduser('~'), 'Downloads')

class download(object):
    def __init__(self, url):
        self.url = url

    def song(self):
        opts = { 
            'verbose': True,
            'fixup': 'detect_on_warn',
            'format': 'bestaudio/best',
            'postprocessors': [{
                'key': 'FFmpegExtractAudio',
                'preferredcodec': 'mp3',
                'preferredquality': '1411',
            }],
            'extractaudio': True,
            'outtmpl': '%(title)s.%(ext)s',
            'save': (f'{path}'),
            'noplaylist': True
        }
        ydl = youtube_dl.YoutubeDL(opts)
        return ydl.download([self.url])


if __name__ == '__main__':
    url = input("Enter the URL of youtube Video: ")
    download(url).song()