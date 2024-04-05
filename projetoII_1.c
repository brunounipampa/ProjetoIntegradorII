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
	FILE *arquivo; arquivo = fopen("programaTestaInstrucoes.mem", "r");
	 
	if (arquivo == NULL) {
	    printf("Erro ao abrir o arquivo.");
	    return 1;
	}else{printf("Carregando na memória.");}	

	int matriz[256][7];
	int linha = 0;

	while (!feof(arquivo)) {
	    fscanf(arquivo, "%d %d %d %d %d %d %d", &matriz[linha][0], &matriz[linha][1], &matriz[linha][2],
		                                    &matriz[linha][3], &matriz[linha][4], &matriz[linha][5], &matriz[linha][6]);
	    linha++;
	}

	fclose(arquivo); 

}

// Função para imprimir a memória 
void imprimir_memoria() { 
	// Código para imprimir a memória 
	/*enum classe_inst{
		tipo_I, 
		tipo_J, 
		tipo_R, 
		tipo_OUTROS
	};
	struct instrucao{
		enum classe_inst tipo_inst;
		char inst_char[17];
		int opcode;
		int rs;
		int rt;
		int rd;
		int funct;
		int imm;
		int addr;
	};
	struct memoria_instrucao{
		struct instrucao *mem_inst;
		int tamanho;
	};
	struct dado{
		char dado_char[8];
		int dado;
	};
	struct memoria_dados{
		struct instrucao *mem_dados;
		int tamanho;
	};*/
	/*void identifyInstruction(int opcode, int funct) {
    switch (opcode) {
        case 0:
            switch (funct) {
                case 0:
                    printf("ADD => 0/0");
                    break;
                case 2:
                    printf("SUB => 0/2");
                    break;
                case 4:
                    printf("AND => 0/4");
                    break;
                case 5:
                    printf("OR => 0/5");
                    break;
            }
            break;
        case 4:
            printf("AADi => 4");
            break;
        case 11:
            printf("LW => 11");
            break;
        case 15:
            printf("SW => 15");
            break;
        case 8:
            printf("BEQ => 8");
            break;
        case 2:
            printf("J => 2");
            break;
	    }
	}
	FILE *file = fopen("programaTestaInstrucoes.mem.mem", "r");
        int matrix[256][7];
        int row = 0;

        while (fscanf(file, "%d %d %d %d %d %d %d", &matrix[row][0], &matrix[row][1], &matrix[row][2], &matrix[row][3], &matrix[row][4], &matrix[row][5], &matrix[row][6]) == 7) {
              int opcode = matrix[row][0] / 16;
              int funct = matrix[row][0] % 16;

              printf("Linha %d: Opcode: %d rs: %d rt: %d rd: %d funct: %d Imm/Addr: %d ", row, opcode, matrix[row][1], matrix[row][2], matrix[row][3], funct, matrix[row][4]);

              identifyInstruction(opcode, funct);

              row++;
              }
        fclose(file);
}*/
	/*int matriz[256][7] = {{0,0,0,0,0,0,0}, {0,2,4,3,0,0,0}, {0,4,1,2,1,0,0}, {0,5,2,3,1,0,0}, {4,1,3,4,0,0,1}, {11,2,5,6,0,0,2},{15,3,6,7,0,0,2}, {8,4,7,8,0,0,2}, {2,1,8,9,0,0,3}};

 
	int i, j;
	printf("Posicao  Opcode  Rs  Rt  Rd  Funct  Imm/Addr  Tipo de Instrucao\n"); 
	for(i = 0; i < 256; i++) { 
		int opcode = matriz[i][0]; 
		int rs = matriz[i][1]; 
		int rt = matriz[i][2]; 
		int rd = matriz[i][3]; 
		int funct = matriz[i][4]; 
		int imm_addr = matriz[i][5]; 
		int tipo_instrucao;
 
	    	if(opcode == 0 && (funct == 0 || funct == 2 || funct == 4 || funct == 5)) {
			tipo_instrucao = 0; // Tipo R
	    	} else if(opcode == 4 || opcode == 11 || opcode == 15 || opcode == 8) {
			tipo_instrucao = 1; // Tipo I
	    	} else if(opcode == 2) {
			tipo_instrucao = 2; // Tipo J
	    	}

	    	if(tipo_instrucao == 0) {
			printf("%d       %d       %d    %d    %d    %d        %d             R", i, opcode, rs, rt, rd, funct, imm_addr); 
		} else if(tipo_instrucao == 1) { 
			printf("%d %d %d %d %d %d %d I ", i, opcode, rs, rt, rd, funct, imm_addr); 
		} else { 
			printf("%d %d %d %d %d %d %d J ", i, opcode, rs, rt, rd, funct, imm_addr); 
		} 
	    }*/
// esses codigos aqui em cima para fazer o teste.


// Função para imprimir os registradores 
void imprimir_registradores() { 
// Código para imprimir os registradores 
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
