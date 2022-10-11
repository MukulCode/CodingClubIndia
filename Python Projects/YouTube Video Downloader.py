
from pytube import YouTube

print("Enter the link of Video to be downloaded: ",end="")
inpt = str(input())

ytv = YouTube(inpt)

print("You have selected: ",end = "")
print(ytv.title)

#Path = str(input("Enter the download path : "))        # If you want to a specific folder for storage

vid = ytv.streams.filter(progressive=True)              #progressive=True   means    Audio+Video
for content in list(enumerate(vid)):
    print(content)



user_input = int(input("Enter the serial number from list to be downloaded : "))

vid[user_input].download( "D:")     #Path of downloads

print("Download Successful")


    
 
