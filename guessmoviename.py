import random

def create_question(movie):
    letters=list(movie)
    length=len(letters)
    temp=[]
    for i in range(length):
        if(letters[i]==" "):
            temp.append(" ")
        else:
            temp.append("*")
    qn="".join(str(x) for x in temp )
    return qn

def is_present(letter, movie):
    c=movie.count(letter)
    if(c==0):
        return False
    else:
        return True
    
def unlock(movie, qn, letter):
    ref=list(movie)
    ques=list(qn)
    n=len(ref)
    temp=[]
    for i in range(n):
        if(ref[i]==" " or ref[i]==letter):
            temp.append(ref[i])
        else:
            if(ques[i]=="*"):
                temp.append("*")
            else:
                temp.append(ref[i])
    qn="".join(str(x) for x in temp)
    return qn
            

def play():
        movies=["gol maal","anand","hero","don no.1","spiderman","harry potter","big bull","harshad mehta","mr x","total dhamaal","golmaal again","dhol","brahmastra","taare zameen par","tanhaji","saunkan saunkane","uri" ,"chal mera putt"]
        picked_movie=random.choice(movies)
        player1=input("ENTER YOUR NAME, PLAYER1")
        player2=input("ENTER YOUR NAME, PLAYER2")
        pp1=0
        pp2=0
        turn=0
        willing=True
        while (willing):
            if(turn%2==0):
                # player1 turn
                print(player1, ", your turn")
                qn=create_question(picked_movie)
                print(qn)
                modified_qn=qn
                not_said=True
                while(not_said):
                    ans=input("Guess the name of the movie, Enter a character: ")
                    if(is_present(ans, picked_movie)):
                        print("Your answer is correct!...")
                        modified_qn=unlock(picked_movie,modified_qn,ans)
                        print(modified_qn)
                        choice=int(input("Enter 1 to guess the full name of movie or 2 to unlock another character"))
                        if(choice==1):
                            full_answer=input("Enter the characters: ")
                            if(full_answer==picked_movie):
                                print("Right answer, cheers!..")
                                pp1=pp1+1
                                not_said=False
                            else:
                                print("Wrong answer, Try again")
                    else:
                        print("Wrong answer, :(")
                n=int(input("Press 0 to continue and 1 to exit"))
                if(n==1):
                    print("Thanks for playing the game, Scores are as: ")
                    print(player1,":", pp1, player2, ":", pp2)
                    willing=False
                turn=turn+1
            else:
                print(player2, ", your turn")
                qn=create_question(picked_movie)
                print(qn)
                modified_qn=qn
                not_said=True
                while(not_said):
                    ans=input("Guess the name of the movie, Enter a character: ")
                    if(is_present(ans, picked_movie)):
                        print("Your answer is correct!...")
                        modified_qn=unlock(picked_movie,modified_qn,ans)
                        print(modified_qn)
                        choice=int(input("Enter 1 to guess the full name of movie or 2 to unlock another character"))
                        if(choice==1):
                            full_answer=input("Enter the characters: ")
                            if(full_answer==picked_movie):
                                print("Right answer, cheers!..")
                                pp2=pp2+1
                                not_said=False
                            else:
                                print("Wrong answer, Try again")
                    else:
                        print("Wrong answer, :(")
                n=int(input("Press 0 to continue and 1 to exit"))
                if(n==1):
                    print("Thanks for playing the game, Scores are as: ")
                    print(player1,":", pp1, player2, ":", pp2)
                    willing=False
                turn=turn+1
                # player2 turn
        
play() 
    
    