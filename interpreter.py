
fileInput = open("asm", "r")
ASMLines = list(map(lambda e: e.rstrip("\n"), fileInput.readlines()))
fileInput.close()

ASMLines.append("NOP")
dataMem = {}
ip = 0
while ip < len(ASMLines):
    incr = 1
    currLine = ASMLines[ip].split()
    match currLine[0]:
        case "ADD":
            dataMem[currLine[1]] = dataMem[currLine[2]] + dataMem[currLine[3]]
        case "MUL":
            dataMem[currLine[1]] = dataMem[currLine[2]] * dataMem[currLine[3]]
        case "SUB":
            dataMem[currLine[1]] = dataMem[currLine[2]] - dataMem[currLine[3]]
        case "DIV":
            dataMem[currLine[1]] = dataMem[currLine[2]] / dataMem[currLine[3]]
        case "COP":
            dataMem[currLine[1]] = dataMem[currLine[2]]
        case "AFC":
            dataMem[currLine[1]] = int(currLine[2])
        case "SUP":
            dataMem[currLine[1]] = dataMem[currLine[2]] > dataMem[currLine[3]]
        case "EQ":
            dataMem[currLine[1]] = dataMem[currLine[2]] == dataMem[currLine[3]]
        case "NOT":
            dataMem[currLine[1]] = not dataMem[currLine[2]]
        case "INF":
            dataMem[currLine[1]] = dataMem[currLine[2]] < dataMem[currLine[3]]
        case "AND":
            dataMem[currLine[1]] = dataMem[currLine[2]] and dataMem[currLine[3]]
        case "OR":
            dataMem[currLine[1]] = dataMem[currLine[2]] and dataMem[currLine[3]]
        case "JMP":
            ip = int(currLine[1])
            incr = 0
        case "JMF":
            if not dataMem[currLine[1]]:
                incr = 0
                ip = int(currLine[2])
        case "CAL":
            pass
        case "RET":
            pass
        case "PRI":
            pass
        case default:
            pass
    print(ASMLines[ip], ", ".join([f"{i}:{dataMem.get(i)}" for i in dataMem]))
    ip += incr