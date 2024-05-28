
fileInput = open("asm", "r")
ASMLines = list(map(lambda e: e.rstrip("\n"), fileInput.readlines()))
fileInput.close()

ASMLines.append("NOP")
ASM = {}
ip = 0
while ip < len(ASMLines):
    incr = 1
    currLine = ASMLines[ip].split()

    match currLine[0]:
        case "ADD":
            ASM[currLine[1]] = ASM[currLine[2]] + ASM[currLine[3]]
        case "MUL":
            ASM[currLine[1]] = ASM[currLine[2]] * ASM[currLine[3]]
        case "SUB":
            ASM[currLine[1]] = ASM[currLine[2]] - ASM[currLine[3]]
        case "DIV":
            ASM[currLine[1]] = ASM[currLine[2]] / ASM[currLine[3]]
        case "COP":
            ASM[currLine[1]] = ASM[currLine[2]]
        case "AFC":
            ASM[currLine[1]] = int(currLine[2])
        case "SUP":
            ASM[currLine[1]] = ASM[currLine[2]] > ASM[currLine[3]]
        case "EQ":
            ASM[currLine[1]] = ASM[currLine[2]] == ASM[currLine[3]]
        case "NOT":
            ASM[currLine[1]] = not ASM[currLine[2]]
        case "INF":
            ASM[currLine[1]] = ASM[currLine[2]] < ASM[currLine[3]]
        case "AND":
            ASM[currLine[1]] = ASM[currLine[2]] and ASM[currLine[3]]
        case "OR":
            ASM[currLine[1]] = ASM[currLine[2]] and ASM[currLine[3]]
        case "JMP":
            ip = int(currLine[1])
            incr = 0
        case "JMF":
            if not ASM[currLine[1]]:
                incr = 0
                ip = int(currLine[2])
        case "PRI":
            pass
        case default:
            pass
    print(ASMLines[ip])
    for i in ASM:
        print(f"{i}: {ASM[i]}")

    ip += incr