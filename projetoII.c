#include <stdio.h>
#include <stdlib.h>

int main() { 
	int opcao;

 
	do {
	    printf("\nMenu principal:\n");
	    printf("1. Carregar memória;\n"); 
	    printf("2. Imprimir memória;\n"); 
	    printf("3. Imprimir registradores;\n"); 
	    printf("4. Imprimir todo o simulador;\n"); 
	    printf("5. Salvar .asm;\n"); 
	    printf("6. Salvar .mem;\n"); 
	    printf("7. Executa Programa (run)\n"); 
	    printf("8. Executa uma instrução (Step)\n"); 
	    printf("9. Volta uma instrução (Back)\n"); 
	    printf("0. Sair ");
	 
	    printf("\nEscolha uma opção: ");
	    scanf("%d", &opcao);

	    switch(opcao) {
		case 1:
		    printf("Carregando memória...\n");
		    FILE *arquivo; arquivo = fopen("programaTestaInstrucoes.mem", "r");		 
		    if (arquivo == NULL) {
		         printf("Erro ao abrir o arquivo.");
		         return 1;
		     }
		    int matriz[256][7];
		    int linha = 0;

		    while (!feof(arquivo)) {
		          fscanf(arquivo, "%d %d %d %d %d %d %d", &matriz[linha][0], &matriz[linha][1],&matriz[linha][2],&matriz[linha][3], &matriz[linha][4], &matriz[linha][5], &matriz[linha][6]);
		    linha++;
		    }

		    fclose(arquivo);

		    //printf("Matriz armazenada:\n");
		    for (int i = 0; i < linha; i++) {
		         printf("Linha %d: %d %d %d %d %d %d %d"i+1, matriz[i][0], matriz[i][1], matriz[i][2], matriz[i][3], matriz[i][4], matriz[i][5], matriz[i][6]); 
		    }
		    printf("Memória Carregada...\n");
		    break;
		case 2:
		    printf("Imprimindo memória...\n");
		    break;
		case 3:
		    printf("Imprimindo registradores...\n");
		    break;
		case 4:
		    printf("Imprimindo todo o simulador...\n");
		    break;
		case 5:
		    printf("Salvando .asm...\n");
		    break;
		case 6:
		    printf("Salvando .mem...\n");
		    break;
		case 7:
		    printf("Executando Programa (run)...\n");
		    break;
		case 8:
		    printf("Executando uma instrução (Step)...\n");
		    break;
		case 9:
		    printf("Voltando uma instrução (Back)...\n");
		    break;
		case 0:
		    printf("Saindo do programa. Até mais!\n");
		    break;
		default:
		    printf("Opção inválida. Escolha outra opção.\n");
		    break;
	    }
	} while(opcao != 0);

	return 0;
}
