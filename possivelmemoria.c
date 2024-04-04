#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>

// Função para converter um caractere hexadecimal em um inteiro 
int hexToDec(char hex) { 
    if(hex >= '0' && hex <= '9') { 
        return hex - '0'; 
        
    } else if(hex >= 'A' && hex <= 'F') { 
        return hex - 'A' + 10;
    } else if(hex >= 'a' && hex <= 'f') { 
        return hex - 'a' + 10;
    } 
    return -1;
}

// Função para converter um número hexadecimal de 4 bits em binário 
void hexToBinary(char hex, char* binary) { 
    int decimal = hexToDec(hex); 
    for(int i = 3; i >= 0; i--) { 
        binary[i] = (decimal % 2) + '0'; 
        decimal /= 2;
    }
}

// Função para converter um conjunto de 4 bits em opcode, rs, rt e imm 
void decodeBinary(char binary[16]) { 
    char opcode[4], rs[3], rt[3], imm[7];
// Separando os bits
for(int i = 0; i < 4; i++) {
    opcode[i] = binary[i];
}
for(int i = 4; i < 7; i++) {
    rs[i-4] = binary[i];
}
for(int i = 7; i < 9; i++) {
    rt[i-7] = binary[i];
}
for(int i = 9; i < 16; i++) {
    imm[i-9] = binary[i];
}
// Comparando os parâmetros
if(strcmp(opcode, "0000") == 0) {
    if(strcmp(rt, "000") == 0) {
        if(strcmp(imm, "000000") == 0) {
            // ADD
            printf("opcode: ADD, rs: $%d, rt: $%d, imm: %d",binToDec(rs), binToDec(rt), binToDec(imm)); 
            
        } else { 
            // ADDi 
            printf("opcode: ADDi, rs: $%d, rt: $%d, imm: %d ",binToDec(rs), binToDec(rt), binToDec(imm)); 
        }
    } else if(strcmp(rt, "010") == 0) { 
        // SUB 
        printf("opcode: SUB, rs: $%d, rt: $%d, imm: %d ",binToDec(rs), binToDec(rt), binToDec(imm)); 
    } else if(strcmp(rt, "100") == 0) { 
        // AND 
        printf("opcode: AND, rs: $%d, rt: $%d, imm: %d ",binToDec(rs), binToDec(rt), binToDec(imm)); 
    } else if(strcmp(rt, "101") == 0) { 
        // OR 
        printf("opcode: OR, rs: $%d, rt: $%d, imm: %d ",binToDec(rs), binToDec(rt), binToDec(imm));
    }
} else if (strcmp(opcode, "1011") == 0) { 
    // LW 
    printf("opcode: LW, rs: $%d, rt: $%d, imm: %d ", binToDec(rs), binToDec(rt), binToDec(imm)); 
    } else if (strcmp(opcode, "1000") == 0) { 
        // BEQ 
        printf("opcode: BEQ, rs: $%d, rt: $%d, imm: %d ",binToDec(rs), binToDec(rt), binToDec(imm));
    } else if (strcmp(opcode, "0010") == 0) { 
        // J 
        printf("opcode: J, rs: $%d, rt: $%d, imm: %d ", binToDec(rs), binToDec(rt), binToDec(imm));
    }
}

int main() { FILE *file; char filename[] = "file.mem"; char line[5]; char binary[16];

 
file = fopen("arquivo.mem", "r");
if (file == NULL) {
    printf("Erro na abertura do arquivo.");
    return 1;
}

while (fgets(line, sizeof(line), file)) {
    for(int i = 0; i < 4; i++) {
        hexToBinary(line[i], &binary[i*4]);
    }
    decodeBinary(binary);
}

fclose(file);

return 0;
}
