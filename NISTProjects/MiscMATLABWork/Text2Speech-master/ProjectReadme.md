# Matlab code for Text to Speech Converter

The purpose of this article is to introduce the use of Microsoft's Speech API (SAPI) 5.1 as an effective tool in game development and new projects based on text to speech converter . It is necessary to have the SAPI 5.1 SDK installed.andmatlab release 12 .

Note: This article will be using Matlab, on the Win32 platform. The source code and how to video for this article is available at the bottom of this page.


Getting started with text2speech Converter

* Make sure SAPI is installed on your computer

a) ![Get the Speech SDK 5.1 (86MB) for free from Microsoft:](http://www.microsoft.com/downloads/details.aspx?FamilyId=5E86EC97-40A7-453F-B0EE-6583171B4530&displaylang=en)

b) Test your default computer voice

   Start -> Control Panel -> Sounds,Speech...-> Speech -> Text To Speech -> Preview Voice
   
* Add the text2speech folder to your Matlabpath

* Matlab code for Text to Speech Converter
------------------------------------------

tts.m - This function converts text into speech (latest .Net version).

speak.m - This function converts text into speech (old).

initSpeech.m - loads the speech library (a privat function)

text2speech.m - This function converts text into speech (old, but allows voice attributes).

unloadSpeechLibrary.m - unloads the speech library

------------------------------------------
