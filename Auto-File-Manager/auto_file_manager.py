import os

directory = (input(r"Enter the path of the directory :"))

def makedirectory(folder):
    os.chdir(path=directory)
    if not os.path.exists(folder):
        os.makedirs(folder)

files = os.listdir(path=directory)
makedirectory("Images")
makedirectory("Docs")
makedirectory("Media")
makedirectory("Others")

imgext = ['.jpg','.png','.jpeg']
imgs = [file for file in files if os.path.splitext(file)[1].lower() in imgext]
# print(imgs)

docsext = ['.txt','.xml','.csv','.pdf','.docx','.doc','.xsl','.ppt']
docs = [file for file in files if os.path.splitext(file)[1].lower() in docsext]
# print(docs)

mediaext = ['.mp4','.mkv','.mp3','.flv','.avi','.wav']
medias = [file for file in files if os.path.splitext(file)[1].lower() in mediaext]
# print(medias)

others = []
for file in files:
    ext = os.path.splitext(file)[1].lower()
    if (ext not in imgext) and (ext not in docsext) and (ext not in mediaext) and os.path.isfile(file):
        others.append(file)

# print(others)


def move_to_folder(foldername,files):
    for file in files:
        os.replace(file,f"{foldername}/{file}")

move_to_folder("Media",medias)
move_to_folder("Images",imgs)
move_to_folder("Docs",docs)
move_to_folder("Others",others)



