#include <stdio.h>

// Função para carregar memória a partir de um arquivo ".mem" 
void carregar_memoria();

// Função para imprimir a memória 
void imprimir_memoria();

// Função para imprimir os registradores 
void imprimir_registradores();

// Função para imprimir todo o simulador 
void imprimir_simulador();

// Função para salvar em um arquivo ".asm" 
void salvar_asm();

// Função para salvar em um arquivo ".mem" 
void salvar_mem();

// Função para executar o programa 
void executar_programa();

// Função para executar uma instrução 
void executar_instrucao();

// Função para voltar uma instrução 
void voltar_instrucao();

int main() { 
	int opcao;

 
	do {
	    printf("\nMenu Principal\n"); 
	    printf("1. Carregar memória\n"); 
	    printf("2. Imprimir memória \n"); 
	    printf("3. Imprimir registradores \n"); 
	    printf("4. Imprimir todo o simulador \n"); 
	    printf("5. Salvar .asm \n"); 
	    printf("6. Salvar .mem \n"); 
	    printf("7. Executa Programa (run)\n"); 
	    printf("8. Executa uma instrução (Step)\n"); 
	    printf("9. Volta uma instrução (Back)\n"); 
	    printf("0. Sair \n"); 
	    printf("Escolha uma opção: "); 
	    scanf("%d", &opcao);
	 
	    switch(opcao) {
		case 1:
		    carregar_memoria();
		    break;
		case 2:
		    imprimir_memoria();
		    break;
		case 3:
		    imprimir_registradores();
		    break;
		case 4:
		    imprimir_simulador();
		    break;
		case 5:
		    salvar_asm();
		    break;
		case 6:
		    salvar_mem();
		    break;
		case 7:
		    executar_programa();
		    break;
		case 8:
		    executar_instrucao();
		    break;
		case 9:
		    voltar_instrucao();
		    break;
		case 0:
		    printf("Saindo do programa...\n");
		    break;
		default:
		    printf("Opção inválida! Escolha uma opção válida.\n");
	    }
	} while(opcao != 0);

	return 0;
}
// Função para carregar memória a partir de um arquivo ".mem" 
void carregar_memoria() { 
	// Código para carregar a memória
	
	    FILE *arquivo_mem, *arquivo_txt;
	    int matriz[256][15];

	    arquivo_mem = fopen("programaTestaInstrucoes.mem", "rb");
	    
	    if (arquivo_mem == NULL) {
		printf("Erro ao abrir o arquivo");
		return 1;
	    }

	    arquivo_txt = fopen("matriz.txt", "w");
	    if (arquivo_txt == NULL) {
		printf("Erro ao abrir o arquivo.txt");
		return 1;
	    }

	    fread(dados, sizeof(int), 256 * 15, arquivo_mem);

	    for (int i = 0; i < 256; i++) {
		for (int j = 0; j < 15; j++) {
		    fprintf(arquivo_txt, "%d ", matriz[i][j]);
		}
		fprintf(arquivo_txt, "\n");
	    }

	    fclose(arquivo_mem);
	    fclose(arquivo_txt);   
}


// Função para imprimir a memória 
void imprimir_memoria() { 
	// Código para imprimir a memória 
/*	void processInstructions(char instruction[256][15], int rows) {
    FILE *outputFile;
    outputFile = fopen("instrução.txt", "w");

    for (int i = 0; i < rows; i++) {
        char type[10];
        char rs[10];
        char rt[10];
        char rd[10];
        char funct[10];
        char imm[10];

        // Extracting columns 0 to 3
        char opcode[5];
        strncpy(opcode, instruction[i], 4);

        // Extracting columns 13 to 15
        char op[4];
        strncpy(op, &instruction[i][12], 3);

        if (strcmp(opcode, "0000") == 0) {
            strcpy(type, "T");
            strcpy(rs, "RS");
            strcpy(rt, "RT");
            strcpy(rd, "RD");

            if (strcmp(op, "000") == 0) {
                strcpy(funct, "ADD");
            } else if (strcmp(op, "010") == 0) {
                strcpy(funct, "SUB");
            } else if (strcmp(op, "100") == 0) {
                strcpy(funct, "AND");
            } else if (strcmp(op, "101") == 0) {
                strcpy(funct, "OR");
            }

            fprintf(outputFile, "%s | %s | %s | %s | %s\n", type, rs, rt, rd, funct);
        } else {
            strcpy(type, "I");
            strcpy(rs, "RS");
            strcpy(rt, "RT");

            if (strcmp(opcode, "0100") == 0) {
                strcpy(imm, "ADDI");
            } else if (strcmp(op, "011") == 0) {
                strcpy(imm, "LW");
            } else if (strcmp(opcode, "1111") == 0) {
                strcpy(imm, "SW");
            } else if (strcmp(opcode, "1000") == 0) {
                strcpy(imm, "BEQ");
            } else if (strcmp(opcode, "0010") == 0) {
                strcpy(imm, "J");
            }

            fprintf(outputFile, "%s | %s | %s | %s\n", type, rs, rt, imm);
        }
    }

    fclose(outputFile);
}

    char instructions[256][15];
    int rows = 256; // Number of rows in the matrix

    // Read from input.txt file
    FILE *inputFile;
    inputFile = fopen("matriz.txt", "r");
    if (inputFile == NULL) {
        printf("Error opening input file\n");
        return 1;
    }

    for (int i = 0; i < rows; i++) {
        fscanf(inputFile, "%s", instructions[i]);
    }

    fclose(inputFile);

    processInstructions(instructions, rows);
}*/
		/*void processInstructions(char instruction[256][15], int rows) {
	    FILE *outputFile;
	    outputFile = fopen("instrtxt", "w");
	    for (int i = 0; i < rows; i++) {
		char type[10];
		char rs[10];
		char rt[10];
		char rd[10];
		char funct[15];
		char imm[15];
		// Convert columns 0 to 3 to decimal
		int opcode_decimal = 0;
		for (int j = 0; j < 4; j++) {
		    if (instruction[i][j] == '1') {
		        opcode_decimal += pow(2, 3 - j);
		    }
		}
		// Extract columns 13 to 15
		int op_decimal = 0;
		for (int j = 12; j < 15; j++) {
		    if (instruction[i][j] == '1') {
		        op_decimal += pow(2, 14 - j);
		    }
		}
		// Check opcode_decimal and op_decimal to determine instruction type and values
		if (opcode_decimal == 0) {
		    strcpy(type, "T");
		    strcpy(rs, "RS");
		    strcpy(rt, "RT");
		    strcpy(rd, "RD");
		    if (op_decimal == 0) {
		        strcpy(funct, "ADD");
		    } else if (op_decimal == 2) {
		        strcpy(funct, "SUB");
		    } else if (op_decimal == 4) {
		        strcpy(funct, "AND");
		    } else if (op_decimal == 5) {
		        strcpy(funct, "OR");
		    }
		    printf("%s | %s | %s | %s | %s\n", type, rs, rt, rd, funct);
		    fprintf(outputFile, "%s | %s | %s | %s | %s\n", type, rs, rt, rd, funct);
		} else {
		    strcpy(type, "I");
		    strcpy(rs, "RS");
		    strcpy(rt, "RT");
		    if (opcode_decimal == 4) {
		        strcpy(imm, "ADDI");
		    } else if (opcode_decimal == 7) {
		        strcpy(imm, "LW");
		    } else if (opcode_decimal == 15) {
		        strcpy(imm, "SW");
		    } else if (opcode_decimal == 8) {
		        strcpy(imm, "BEQ");
		    } else if (opcode_decimal == 2) {
		        strcpy(imm, "J");
		    }
		    printf("%s | %s | %s | %s\n", type, rs, rt, imm);
		    fprintf(outputFile, "%s | %s | %s | %s\n", type, rs, rt, imm);
		}
	    }
	    fclose(outputFile);
	}
	int main() {
	    char instructions[256][15];
	    int rows = 256; // Number of rows in the matrix
	    // Read from input.txt file
	    FILE *inputFile;
	    inputFile = fopen("matriz.txt", "r");
	    if (inputFile == NULL) {
		printf("Error opening input file\n");
		return 1;
	    }
	    for (int i = 0; i < rows; i++) {
		fscanf(inputFile, "%s", instructions[i]);
	    }
	    fclose(inputFile);
	    processInstructions(instructions, rows);
	    return 0;
}*/



// Função para imprimir os registradores 
void imprimir_registradores() { 
// Código para imprimir os registradores
/*	enum Registers {
    $0 = 0,
    $r1 = 1,
    $r2 = 2,
    $r3 = 3,
    $r4 = 4,
    $r5 = 5,
    $r6 = 6
};
// Function to process instructions from the input matrix
void processInstructions(char instruction[256][15], int rows) {
    FILE *outputFile;
    outputFile = fopen("output.txt", "w");
    for (int i = 0; i < rows; i++) {
        char rs[3];
        char rt[3];
        char rd[3];
        char imm[7];
        // Convert columns 4 to 6 to decimal and map to enum Registers
        int rs_dec = 0;
        for (int j = 4; j < 7; j++) {
            if (instruction[i][j] == '1') {
                rs_dec += 1 << (6 - j);
            }
        }
        // Convert columns 7 to 9 to decimal and map to enum Registers
        int rt_dec = 0;
        for (int j = 7; j < 10; j++) {
            if (instruction[i][j] == '1') {
                rt_dec += 1 << (9 - j);
            }
        }
        // Convert columns 10 to 12 to decimal and map to enum Registers
        int rd_dec = 0;
        for (int j = 10; j < 13; j++) {
            if (instruction[i][j] == '1') {
                rd_dec += 1 << (12 - j);
            }
        }
        // Check the opcode to determine instruction type and values
        if (instruction[i][0] == '0') {
            strcpy(rs, (rs_dec == 0) ? "$0" : (rs_dec == 1) ? "$r1" : (rs_dec == 2) ? "$r2" : (rs_dec == 3) ? "$r3" :
                (rs_dec == 4) ? "$r4" : (rs_dec == 5) ? "$r5" : "$r6");
            strcpy(rt, (rt_dec == 0) ? "$0" : (rt_dec == 1) ? "$r1" : (rt_dec == 2) ? "$r2" : (rt_dec == 3) ? "$r3" :
                (rt_dec == 4) ? "$r4" : (rt_dec == 5) ? "$r5" : "$r6");
            strcpy(rd, (rd_dec == 0) ? "$0" : (rd_dec == 1) ? "$r1" : (rd_dec == 2) ? "$r2" : (rd_dec == 3) ? "$r3" :
                (rd_dec == 4) ? "$r4" : (rd_dec == 5) ? "$r5" : "$r6");
            strcpy(imm, instruction[i]+10); // Extracting imm from columns 10 to 15
            fprintf(outputFile, "%s | %s | %s | %s\n", rs, rt, rd, imm);
        } else {
            // Handle instruction types of I and J
            strcpy(rs, (rs_dec == 0) ? "$0" : (rs_dec == 1) ? "$r1" : (rs_dec == 2) ? "$r2" : (rs_dec == 3) ? "$r3" :
                (rs_dec == 4) ? "$r4" : (rs_dec == 5) ? "$r5" : "$r6");
            strcpy(imm, instruction[i]+10); // Extracting imm from columns 10 to 15
            fprintf(outputFile, "%s | %s | %s\n", rs, rt, rd, imm);
        }
    }
    fclose(outputFile);
}
int main() {
    char instructions[256][15];
    int rows = 256; // Number of rows in the matrix
    // Read from input.txt file
    FILE *inputFile;
    inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Error opening input file\n");
        return 1;
    }
    for (int i = 0; i < rows; i++) {
        fscanf(inputFile, "%s", instructions[i]);
    }
    fclose(inputFile);
    processInstructions(instructions, rows);
    return 0;
}*/ 
}

// Função para imprimir todo o simulador 
void imprimir_simulador() { 
// Código para imprimir todo o simulador 
}

// Função para salvar em um arquivo ".asm" 
void salvar_asm() { 
// Código para salvar em um arquivo ".asm" 
}

// Função para salvar em um arquivo ".mem" 
void salvar_mem() { 
// Código para salvar em um arquivo ".mem" 
}

// Função para executar o programa 
void executar_programa() { 
// Código para executar o programa 
}

// Função para executar uma instrução 
void executar_instrucao() { 
// Código para executar uma instrução 
}

// Função para voltar uma instrução 
void voltar_instrucao() { 
// Código para voltar uma instrução 
}
