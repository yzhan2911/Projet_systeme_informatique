
file = open("asm", "r")
ASMLines = file.readlines()
file.close()

ASMLines.append("NOP")
ASM = {}
ip = 0
while ip < len(ASMLines):
    incr = 1
    Line = ASMLines[ip].split()

    match Line[0]:
        case "ADD":
            ASM[Line[1]] = ASM[Line[2]] + ASM[Line[3]]
        case "MUL":
            ASM[Line[1]] = ASM[Line[2]] * ASM[Line[3]]
        case "SUB":
            ASM[Line[1]] = ASM[Line[2]] - ASM[Line[3]]
        case "DIV":
            ASM[Line[1]] = ASM[Line[2]] / ASM[Line[3]]
        case "COP":
            ASM[Line[1]] = ASM[Line[2]]
        case "AFC":
            ASM[Line[1]] = int(Line[2])
        case "SUP":
            ASM[Line[1]] = ASM[Line[2]] > ASM[Line[3]]
        case "EQ":
            ASM[Line[1]] = ASM[Line[2]] == ASM[Line[3]]
        case "NOT":
            ASM[Line[1]] = not ASM[Line[2]]
        case "INF":
            ASM[Line[1]] = ASM[Line[2]] < ASM[Line[3]]
        case "AND":
            ASM[Line[1]] = ASM[Line[2]] and ASM[Line[3]]
        case "OR":
            ASM[Line[1]] = ASM[Line[2]] or ASM[Line[3]]
        case "JMP":
            ip = int(Line[1])
            incr = 0
        case "JMF":
            if not ASM[Line[1]]:
                ip = int(Line[2])
                incr = 0
        case default:
            pass
    print("--------------")
    print(ASMLines[ip])
    for i in ASM:
        print(f"{i}: {ASM[i]}")

    ip += incr