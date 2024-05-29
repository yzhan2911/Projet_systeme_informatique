import re

opToBinOP = {
    "ADD": "01",
    "MUL": "02",
    "SUB": "03",
    "DIV": "04",
    "COP": "05",
    "AFC": "06",
    "LOAD": "07",
    "STORE": "08",
    "NOP": "FF"
}
 

def convertToBinary(ASMLines):
    ASMLinesBin = []
    for ASMLine in ASMLines:
        arr = ASMLine.split()
        opBin = opToBinOP.get(arr[0], "FF") ## "FF" par defaut

        registreBin = []
        for op in arr[1:]: ## en hexadecimal
            registreBin.append(f"{int(op):02X}")
        
        while len(registreBin) < 3:
            registreBin.append("00")
        
        ASMLinesBin.append(f"(x\"{opBin}{registreBin[0]}{registreBin[1]}{registreBin[2]}\")")## (x"06030600")
    return ASMLinesBin


fileInput = open("asm1", "r")
ASMLines = fileInput.readlines()
fileInput.close()
ASMLines.append("NOP")   

ASMLinesBin = convertToBinary(ASMLines)

vhdl_format = "("
for line in ASMLinesBin:
    vhdl_format += line + ","
vhdl_format += "others => (x\"FF000000\"))"

ASMLinesBin = "(" + ",".join(ASMLinesBin) + ",others => (x\"FF000000\"))"
print(" VHDL format: " + vhdl_format)

 
