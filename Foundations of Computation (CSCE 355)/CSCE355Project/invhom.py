import sys


def getStringsDFA(file_path): 
    file = open(file_path,"r")
    lines = file.readlines()
    file.close()
    wantLines = []
    #print(lines)
    for a in lines:    
        if(a == "\n"): 
           wantLines.append(a)
        else:
                wantLines.append(a[:-1])        

    numberStates = wantLines.pop(0)[18:]
    #print(numberStates)
    wantedStates = wantLines.pop(0)[18:].split()
    alphabet = wantLines.pop(0)[10:].split()
    return (numberStates,wantedStates,alphabet)

def getStringsHOM(file_path): 
    file = open(file_path,"r")
    lines = file.readlines()
    file.close()
    wantLines = []
    #print(lines)
    for a in lines:    
        if(a == "\n"): 
           wantLines.append(a)
        else:
            wantLines.append(a[:-1])   
     
    
    input_alphabet = wantLines.pop(0)[16:]
    output_alphabet = wantLines.pop(0)[17:]

    #print(input_alphabet)
    #print(output_alphabet)
    return (input_alphabet,output_alphabet, wantLines)


def makeDFA(path):
        file = open(path,"r")
        lines = file.readlines()
        file.close
        lines.pop(0)

        wanted = [int(i) for i in lines.pop(0)[18:].split()]
        alphabet = lines.pop(0)[10:-1]
        states = [[int(i) for i in line[:-1].split()]for line in lines]

        trans = {} 
        for i, state in enumerate(states):
                tran = {}
                for j, x in enumerate(state):
                    tran[alphabet[j]] = x
                #print(tran)
                trans[i] = tran
                
        return (wanted,trans)

def printDFA(transitions, wanted, alphabet):
        print("Number of states:", len(transitions))
        print("Accepting states:", *wanted)
        print("Alphabet:", alphabet)
        for i, x in enumerate(transitions):
                print(transitions[i])

def newDFA(dfa, numStates, stringz, alphabet):
        dfaList = []
        for loopNum in range(numStates):
                currState = loopNum
                dfaString = ""
        
                for c in stringz:
                        for d in c:
                                if(c == "\n"):
                                        currState = loopNum
                                else:
                                        currState = dfa[currState][d]
                                
                        dfaString += (str(currState)+ " ")
                        currState = loopNum
                dfaList.append(dfaString)
        #print(dfaList)
        states = [[int(i) for i in line[:-1].split()]for line in dfaList]
        #print(states)
        trans = {} 

        for i, state in enumerate(states):
                tran = {}
                for j, x in enumerate(state):
                        tran[alphabet[j]] = x
                trans[i] = tran
        return dfaList
        

(totalStates, wanted, alphabet) = getStringsDFA(sys.argv[1])                    #want -DFA.txt
(input_alphabet, output_alphabet, wantLines) = getStringsHOM(sys.argv[2])       #want -DFA-hom.txt

(wanted,dfa) = makeDFA(sys.argv[1])                                           
newDFA = newDFA(dfa, int(totalStates), wantLines, input_alphabet)                       

#print(newDFAList)
printDFA(newDFA, wanted, input_alphabet)
