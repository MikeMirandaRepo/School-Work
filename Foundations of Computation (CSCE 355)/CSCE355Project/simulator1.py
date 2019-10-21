import sys


def makeDFA(path):
        file = open(path,"r")
        lines = file.readlines()
        file.close
        lines.pop(0)
        wanted = [int(i) for i in lines.pop(0)[18:].split()]
        #print(wanted)
        alphabet = lines.pop(0)[10:-1]
        #print(alphabet)
        states = [[int(i) for i in line[:-1].split()]for line in lines]
        #print(states)
        trans = {} 

        for i, state in enumerate(states):
                tran = {}
                for j, x in enumerate(state):
                        tran[alphabet[j]] = x
                trans[i] = tran
                
        return (wanted,trans)

def getString(file_path): 
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
    #print(wantLines)
    return wantLines


def ifAccept(dfa, wanted, stringz):
        currState = 0
        for c in stringz:
                #print(currState, c)
                if(c == "\n"):
                        continue
                else:
                        currState = dfa[currState][c]
        return currState in wanted

def test(dfa, strings, wanted):
        for s in strings:
                if(ifAccept(dfa, wanted, s)):
                        print("accept")
                        #continue
                else:
                        print("reject")
                        #continue
        return None

(wanted, trans) = makeDFA(sys.argv[1])
#print((trans))
fileStrings = getString(sys.argv[2])
#print(fileStrings)
test(trans,fileStrings,wanted)

        


        

