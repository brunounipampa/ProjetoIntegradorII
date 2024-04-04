#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Função para converter um caractere hexadecimal em seu valor decimal equivalente
int hexCharToDecimal(char c) {
    if (c >= '0' && c <= '9') {
        return c - '0';
    } else if (c >= 'A' && c <= 'F') {
        return c - 'A' + 10;
    } else {
        return -1; // Caractere inválido
    }
}

// Função para converter um caracter hexadecimal para binário em forma de string
void hexToBinary(char hex, char *binary) {
    int decimal = hexCharToDecimal(hex);
    // Conversão de decimal para binário (valor de 0 a 15)
    for (int i = 3; i >= 0; i--) {
        binary[i] = (decimal % 2) + '0';
        decimal = decimal / 2;
    }
    binary[4] = '\0';
}

// Struct para armazenar os parâmetros de instrução
typedef struct {
    char opcode[4];
    char rs[3];
    char rt[2];
    char imm[7];
} Instrucao;

int main() {
    FILE *arquivoEntrada = fopen("arquivo.mem", "r");
    FILE *arquivoSaida = fopen("instrucoes.mem", "w");

    if (arquivoEntrada == NULL) {
        printf("Erro ao abrir o arquivo de entrada.\n");
        return 1;
    }

    if (arquivoSaida == NULL) {
        printf("Erro ao criar o arquivo de saída.\n");
        return 1;
    }

    char linha[255];
    while (fgets(linha, 255, arquivoEntrada) != NULL) {
        char opcode[4], rs[3], rt[2], imm[7];
        Instrucao instrucao;

        for (int i = 0, j = 0; linha[i] != '\0'; i++, j++) {
            char hexadecimal = linha[i];
            char binario[5];
            hexToBinary(hexadecimal, binario);

            if (j >= 0 && j < 4) {
                strcat(opcode, binario);
            } else if (j >= 4 && j < 7) {
                strcat(rs, binario);
            } else if (j >= 7 && j < 9) {
                strcat(rt, binario);
            } else {
                strcat(imm, binario);
            }

            if (j == 15) {
                strcpy(instrucao.opcode, opcode);
                strcpy(instrucao.rs, rs);
                strcpy(instrucao.rt, rt);
                strcpy(instrucao.imm, imm);

                // Verificar as instruções e salvar no arquivo de saída
                if (strcmp(instrucao.opcode, "0000") == 0 && strcmp(instrucao.rt, "000") == 0) {
                    fprintf(arquivoSaida, "ADD");
                } else if (strcmp(instrucao.opcode, "0000") == 0 && strcmp(instrucao.rt, "010") == 0) {
                    fprintf(arquivoSaida, "SUB");
                } else if (strcmp(instrucao.opcode, "0000") == 0 && strcmp(instrucao.rt, "100") == 0) {
                    fprintf(arquivoSaida, "AND");
                } else if (strcmp(instrucao.opcode, "0000") == 0 && strcmp(instrucao.rt, "101") == 0) {
                    fprintf(arquivoSaida, "OR");
                } else if (strcmp(instrucao.opcode, "0100") == 0) {
                    fprintf(arquivoSaida, "ADDi");
                } else if (strcmp(instrucao.opcode, "1011") == 0) {
                    fprintf(arquivoSaida, "LW");
                } else if (strcmp(instrucao.opcode, "1000") == 0) {
                    fprintf(arquivoSaida, "BEQ");
                } else if (strcmp(instrucao.opcode, "0010") == 0) {
                    fprintf(arquivoSaida, "J");
                }

                strcpy(opcode, "");
                strcpy(rs, "");
                strcpy(rt, "");
                strcpy(imm, "");
                j = -1;
            }
        }
    }

    fclose(arquivoEntrada);
    fclose(arquivoSaida);

    return 0;
}
