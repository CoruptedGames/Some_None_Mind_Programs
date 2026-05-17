import random


print("Welcome to rock paper seciores")

loop = True
def getSelectionName(pi):
    match pi:
        case 0:
            return "Rock"
        case 1:
            return "Paper"
        case 2:
            return "Seciores"
        case _:
            return "Invalid selection!"
game_roasts = [
    "Your gameplay is the best advertisement for uninstalling I have ever seen.",
    "If throwing rounds was an Olympic sport, you would be a decorated gold medalist.",
    "Somewhere out there, a tree is working hard to replace the oxygen you just wasted making that move.",
    "The only thing lagging right now is your critical decision-making process.",
    "Your teammates aren't fighting the enemy; they are fighting the urge to report you.",
    "I have seen AI bots play better while lagging on 900 ping dial-up internet.",
    "That play was so catastrophically bad, your ancestors are blushing in the afterlife.",
    "You are the exact reason why this game needs a 'surrender' button in the main menu.",
    "Your strategy is a masterclass in what absolute failure looks like.",
    "Please do not reproduce. The world cannot handle another generation of this skill level."
]
# List of developer names
dev_names = ["shubh", "cg", "corruptedgamer", "amit"]

# The input statement that prompts the user
user_input = input("Please enter your username to log in: ")

# Checking the input (stripped of extra spaces and converted to lowercase)
if user_input.strip().lower() in dev_names:
    print("\n" + "="*60)
    print("Access Granted. I am sorry, you are the god of this game.")
    print("You don't need to prove anything.")
    print("Deepest respect to the creator.")
    print("="*60)
    loop = False
else:
    print(f"\nWelcome to the game, {user_input}! Enjoy your session.")
while (loop): # to restart game or select level

    print("Lets select which level of bot you want to fight")
    print("0 for noob \n1 for Starter")
    bot = int(input()) 
    match bot:
        case 0:
            print("You selected: Noob Bot. Get ready for an easy win!")
            bs = 0
            ps = 0
            while(bs < 2 and ps < 2):
                print("Enter \n0 for rock\n1 for paper\n2 for seciores")
                psel = int(input())
                bsel = random.choice([0,1,2])
                if psel > 2 or psel < 0:
                    print(getSelectionName(psel))
                    continue
                elif bsel == psel:
                    print("No one gain a point you both selected ",getSelectionName(bsel))
                elif (psel == 0 and  bsel == 2) or (psel == 1 and bsel == 0) or (psel == 2 and bsel == 1):
                    ps = ps + 1
                    print("You entered ",getSelectionName(psel)," Bot Selected ",getSelectionName(bsel))
                    print("You got a point \nScore \nBot Score = ",bs,"\nYour Score = ",ps)
                else:
                    bs = bs + 1
                    print("You entered ",getSelectionName(psel)," Bot Selected ",getSelectionName(bsel))
                    print("Bot got a point \nScore \nBot Score = ",bs,"\nYour Score = ",ps)
            if (bs > ps):
                print(random.choice(game_roasts))
            else:
                print("Some how you managed to win try out starter level then you will see how computer control itself")
            print("anyways let me know do you want to play again or not\nenter\n0 to exit game\nAnyNumber to play again")
            ch = int(input())
            if ch == 0:
                break
            else:
                continue
         
            
        case 1:
            print("You selected: Starter Bot. Let's see what you've got!")
            bs = 0
            ps = 0
            while(bs < 2 and ps < 2):
                print("Enter \n0 for rock\n1 for paper\n2 for seciores")
                psel = int(input())
                if psel > 2 or psel < 0:
                    print(getSelectionName(psel))
                    continue
                bsel = 0
                winornot = random.choice([0,1])
                if winornot == 1 or ps > bs:
                    if (psel == 0 ):
                        bsel = 1
                    elif (psel == 1):
                        bsel = 2
                    else:
                        bsel = 0
                else:
                    bsel = random.choice([0,1,2])


                
                
                if bsel == psel:
                    print("No one gain a point you both selected ",getSelectionName(bsel))
                elif (psel == 0 and  bsel == 2) or (psel == 1 and bsel == 0) or (psel == 2 and bsel == 1):
                    ps = ps + 1
                    print("You entered ",getSelectionName(psel)," Bot Selected ",getSelectionName(bsel))
                    print("You got a point \nScore \nBot Score = ",bs,"\nYour Score = ",ps)
                else:
                    bs = bs + 1
                    print("You entered ",getSelectionName(psel)," Bot Selected ",getSelectionName(bsel))
                    print("Bot got a point \nScore \nBot Score = ",bs,"\nYour Score = ",ps)
            if (bs > ps):
                print(random.choice(game_roasts))
            else:
                print("Some how you managed to win")
            print("anyways let me know do you want to play again or not\nenter\n0 to exit game\nAnyNumber to play again")
            ch = int(input())
            if ch == 0:
                break
            else:
                continue
            
        case _:
            print("Invalid selection! Please choose 0 or 1.")
    
a = int(input("Press any number to quit "))

