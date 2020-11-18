#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include <windows.h>
#include <locale.h>


int contadorMedicos = 0;
int contadorPacientes = 0, contC19_positivo = 0, contC19_negativo = 0;
int contadorClasserisco = 0;
char login_medico[15];

struct END{

	char logradouro[20];
	char complemento[20];
	char bairro[20];
	char cidade[20];
	char estado[10];
	char cep[10];
};
/*
typedef struct Paciente {
    char Nome[45];
	char Cpf[10];
	char telefone[15];
	END end;
	char nascimento[10];
	char Email[45];
	char data[15];
	char obs[50];
}paciente, pacientes[0];
*/


typedef struct Medico {
	char login[30];
	char senha[30];

	char Nome[45];
	char Cpf[10];
	char telefone[15];
	char nascimento[10];
	char email[45];
	char crm[20];
	char obs[50];
	END end;

} medico, medicos[0];


typedef struct Admin {
	
	char usuario[30];
	char senha[30];
	
}administrador; administrador adm[0];


void sair();
void menu_principal();

void autentica_medico();
void cadastrar_medico();
void listar_medico();
void menu_medico();

void cadastrar_paciente();
void filtrar_registros();
void filtrar_paciente_nome();
void filtrar_ordenar_cadastro();
void ordenar_nome();
void ordenar_cadastro();
void ordenar_pacientes_cadastro();

void autentica_adm();
void menu_administrador();


int main(){
	
	
	

    int i, j;
    setlocale(LC_ALL,"portuguese");

    printf("    SSSSSSSSSSSSSSS       CCCCCCCCCCCCCC PPPPPPPPPPPPPPPPP\n");
    printf(" SS:::::::::::::::S     CCC::::::::::::C P:::::::::::::::PPP\n");
    printf("S:::::SSSSSS::::::S   CC:::::::::::::::C P:::::::::::::::::PP\n");
    printf("S:::::S     SSSSSSS  C:::::CCCCCCCC::::C P:::::PPPPPPPP:::::P\n");
    printf("S:::::S             C:::::C       CCCCCC P:::::U     U:::::P\n");
    printf("S:::::S            C:::::C               P:::::D     D:::::P\n");
    printf(" S::::SSSS         C:::::C               P:::::PPPPPPP:::::P\n");
    printf("  SS::::::SSSSS    C:::::C               P:::::::::::::::::P\n");
    printf("    SSS::::::::SS  C:::::C               P::::::::::::::::PP\n");
    printf("       SSSSSS::::S C:::::C               P:::::PPPPPPPPPPP  \n");
    printf("            S:::::SC:::::C        CCCCCC P:::::P\n");
    printf("            S:::::S C:::::C       C::::C P:::::P\n");
    printf("SSSSSSS     S:::::S  CC:::::CCCCCCC::::C P:::::P\n");
    printf("S::::::SSSSSS:::::S   CC:::::::::::::::C P:::::P\n");
    printf("S:::::::::::::::SS      CCC::::::::::CC  P:::::P\n");
    printf(" SSSSSSSSSSSSSSS           CCCCCCCCCCCC  PPPPPPP\n");


    printf("\n\n\n             ..:: Sejam bem-vindos ao SCP! ::.. ");


   printf ("\n\nCarregando o sistema: \n\n");

   for (i = 1; i <= 50; i++){
      printf ("  %d%%\r", i*2);
      fflush (stdout);

      for (j = 0; j < i; j++){
         if (!j)
           printf("  ");

         printf ("%c", 2);
         Sleep(3);
      }
   }

    printf ("\n\nInicializando sistema...");
    Sleep(2);
    system("cls");
    menu_principal();

return 0;
}
void sair(){
        printf("    SSSSSSSSSSSSSSS       CCCCCCCCCCCCCC PPPPPPPPPPPPPPPPP\n");
    	printf(" SS:::::::::::::::S     CCC::::::::::::C P:::::::::::::::PP\n");
    	printf("S:::::SSSSSS::::::S   CC:::::::::::::::C P::::::::::::::::PP\n");
    	printf("S:::::S     SSSSSSS  C:::::CCCCCCCC::::C P:::::PPPPPPP:::::P\n");
    	printf("S:::::S             C:::::C       CCCCCC P:::::P     P:::::P\n");
    	printf("S:::::S            C:::::C               P:::::P     P:::::P\n");
    	printf(" S::::SSSS         C:::::C               P:::::PPPPPPP:::::P\n");
    	printf("  SS::::::SSSSS    C:::::C               P::::::::::::::::PP\n");
   	 	printf("    SSS::::::::SS  C:::::C               P:::::::::::::::PP\n");
    	printf("       SSSSSS::::S C:::::C               P:::::PPPPPPPPPPP  \n");
    	printf("            S:::::SC:::::C        CCCCCC P:::::P\n");
    	printf("            S:::::S C:::::C       C::::C P:::::P\n");
    	printf("SSSSSSS     S:::::S  CC:::::CCCCCCC::::C P:::::P\n");
    	printf("S::::::SSSSSS:::::S   CC:::::::::::::::C P:::::P\n");
    	printf("S:::::::::::::::SS      CCC::::::::::CC  P:::::P\n");
    	printf(" SSSSSSSSSSSSSSS           CCCCCCCCCCCC  PPPPPPP\n");


        printf("\n\n\n          ..:: A sessão acabou. Obrigado! ::..\n\n");
        exit(0);
    }


void menu_principal(){
    char opc_geral[2];


    do{
        printf("MENU PRINCIPAL\n");
        printf("--------------\n\n");
        printf("1 - Médico\n");
        printf("2 - Administrador\n");
        printf("3 - Sair\n\n");
        printf("Escolha sua opção: ");
        scanf("%s", opc_geral);
        system("cls");
        fflush(stdin);
    }while(strlen(opc_geral)>1 || (opc_geral[0]<49 || opc_geral[0]>52));


    switch (opc_geral[0]){
        case 49: autentica_medico(); break;
        case 50: autentica_adm(); break;
        case 51: sair(); break;
    }
}


void autentica_adm(){


    strcpy(adm[0].usuario, "admin");
    strcpy(adm[0].senha, "1234");

    char usuario[6];
    char senha[12] = {0};
    char c;
    int indice = 0;
    int i, op;

    printf("TELA DE AUTENTICAÇÃO\n");
    printf("--------------------\n\n");
    fflush(stdin);
    printf("Usuário: ");
    scanf("%[^\n]s", usuario);
    fflush(stdin);
    printf("\n");
    printf("%s", "Senha: ");
    do{
        c = getch();

        if(isprint(c)){
            senha[indice++] = c;
            printf("%c",'*');
        }else if(c == 10 && indice){
                senha[indice--] = '\0';
                printf("%s", "\b \b");
              }
    }while(c!=13);

    if(strcmp(adm[0].usuario, usuario) == 0 && strcmp(adm[0].senha, senha) == 0){
        printf("\n\nLogin efetuado com sucesso! Indo para o modo administrador ");
        for(i=1; i<=3; i++){
            if(i==1){
                Sleep(1);
            }
            printf(".");
            Sleep(1);
        }
        system("cls");
        menu_administrador();
    }else{
        printf("\n\n\nLogin mal-sucedido!\n\n1- Tentar novamente / 2- Voltar\n");
        scanf("%d", &op);
        if(op == 1){
            system("cls");
            autentica_adm();
        }else{
            system("cls");
            menu_principal();
        }
    }
}
void menu_administrador(){
    char opc_adm[2];

    do{
            printf("MENU ADMINISTRADOR\n");
            printf("------------------\n\n");
            printf("1 - Cadastrar paciente\n");
            printf("2 - Cadastrar Médico\n");
            printf("3 - Listar Médico\n");
            printf("4 - Voltar\n\n");
            printf("Escolha sua opção: ");
            scanf("%s", opc_adm);
            system("cls");
            fflush(stdin);\
        }while(strlen(opc_adm)>1 || (opc_adm[0]<49 || opc_adm[0]>55));


        switch (opc_adm[0]){
            case 49: cadastrar_paciente(); break;
            case 50: cadastrar_medico(); break;
            case 51: listar_medico(); break;
            case 52: menu_principal(); break;
        }
}

void cadastrar_medico(){
	
	int opc_cadastro;
        if (contadorMedicos < 1000){
            do{
                system("cls");
                printf("CADASTRO DE MÉDICOS\n");
                printf("-----------------------\n\n");
                printf("Médico %d:\n\n", contadorMedicos+1);
                printf("CRM do Médico: ");
                scanf("%d", medicos[contadorMedicos].id);
                fflush(stdin);
                printf("\nNome: ");
                scanf("%[^\n]s", medicos[contadorMedicos].nome_medico);
                fflush(stdin);
                printf("\nLogin: ");
                scanf("%[^\n]s", medicos[contadorMedicos].usuario);
                fflush(stdin);
                printf("\nSenha: ");
                scanf("%[^\n]s", medicos[contadorMedicos].senha);
                printf("\n\nProfessor %d cadastrado com sucesso!",contadorMedicos+1);
                contadorMedicos++;

                printf("\n\nDeseja cadastrar mais um médico? 1-Sim/2-Não\n");
                scanf("%d", &opc_cadastro);

                if(opc_cadastro==2){
                    system("cls");
                    menu_administrador();
                }

                if(contadorMedicos == 1000){
                    printf("\n\n A capacidade de registros de médicos esgotou.");
                    Sleep(2);
                    system("cls");
                    menu_administrador();
                }
            }while(opc_cadastro == 1 && contadorMedicos < 1000);
        }else{
            printf("\nA capacidade de registros de professores esgotou.");
            Sleep(2);
            system("cls");
            menu_administrador();
        }
    }    
void autentica_medico(){
	
    char usuario_med[15];
    char senha_med[15];
    char c;
    int i, j, indice = 0, op;

    printf("TELA DE AUTENTICAÇÃO\n");
    printf("--------------------\n\n");
    printf("Seja bem vindo %s\n", strupr(medicos[0].nome_medico));
    fflush(stdin);
    printf("Usuário: ");
    scanf("%[^\n]s", usuario_med);
    fflush(stdin);
    printf("\nSenha: ");
    scanf("%[^\n]s", senha_med);

    if(strcmp(medicos[0].usuario, usuario_med) == 0 && strcmp(medicos[0].senha, senha_med) == 0){
        printf("\n\nLogin efetuado com sucesso! Indo para o modo médico ");
        for(j = 1; j <= 3; j++){
            if(j == 1){
                Sleep(1);
            }
            printf(".");
            Sleep(1);
        }
        system("cls");
        menu_medico();
    }else{
        printf("\n\nLogin mal-sucedido!\n\n1- Tentar novamente / 2- Voltar\n");
        scanf("%d", &op);
        if(op == 1){
            system("cls");
            autentica_medico();
        }else{
            system("cls");
            menu_medico();
        }
    }
}
void menu_medico(){
   char opc_med[2];

    do{
        printf("MENU MÉDICO\n");
        printf("--------------\n\n");
        printf("1 - Listar todos os pacientes\n");
        printf("2 - Buscar/Filtrar registros de pacientes\n");
        printf("3 - Ordenar registros de pacientes\n");
        printf("4 - Buscar e ordenar de cadastro\n");
        printf("5 - Cadastrar Paciente\n");
        printf("7 - Voltar\n\n");
        printf("Escolha sua opção: ");
        scanf("%s", opc_med);
        system("cls");
        fflush(stdin);
    }while(strlen(opc_med)>1 || (opc_med[0]<49 || opc_med[0]>55));


    switch (opc_med[0]){
        case 49: listar_pacientes(); break;
        case 50: filtrar_registros(); break;
        case 51: ordenar_cadastro(); break;
        case 52: filtrar_ordenar_cadastro(); break;
        case 53: cadastrar_paciente(); break;
        case 55: menu_principal();
    }
}

void listar_medico(){
    printf("PROFESSOR MÉDICO\n");
    printf("----------------------\n\n");
    if(contadorMedicos==0){
        printf("Ainda não há registros de médicos no sistema.\n\n");
    }else{
        int i;
        for(i=0; i<contadorMedicos; i++){
            printf("\nMédicos %d\n\n", i+1);
            printf("CRM: %d\n", medicos[i].id);
            printf("Nome: %s\n", medicos[i].nome_medico);
            
            printf("--------------------------------------\n\n");
        }
    }

    printf("Pressione qualquer tecla para voltar...\n");
    if(getch()){
        system("cls");
        menu_administrador();
    }

}

void filtrar_registros(){

    int op;
    printf("BUSCAR PACIENTES\n");
    printf("-------------\n\n");

    printf("Buscar por:\n1. Nome\n2. CPF\n3. E-mail\n4. Voltar\n\n");
    scanf("%d", &op);
    if(op == 1){
        system("cls");
        filtrar_paciente_nome();
    }else{
        if(op == 2){
            system("cls");
            filtrar_paciente_cpf();
        }else{
            if(op == 3){
                system("cls");
                filtrar_paciente_email();
            }else{
                system("cls");
                menu_medico();
            }
        }
    }
}

void filtrar_paciente_nome(){
    int filtro_nome, nome_encontrado = 0, i, op;
    char nome_filtrado[30];

    printf("BUSCAR PACIENTE POR NOME\n");
    printf("---------------------\n\n");
    printf("Deseja buscar paciente por:\n");
    printf("1. Primeiro Nome\n2. Sobrenome\n\n");
    scanf("%d", &filtro_nome);

    if(filtro_nome == 1){
        fflush(stdin);
        printf("\n\nInforme o nome a ser buscado: ");
        scanf("%[^\n]s", nome_filtrado);
        for(i=0; i<contadorPacientes; i++){
            if(strcasecmp(nome_filtrado, pacientes[i].nome_paciente) == 0){
                printf("\nPaciente %d\n\n", i+1);
                printf("Cadastro: %d\n", pacientes[i].id);
                if(strcmp(pacientes[i].email_paciente, "0") == 0){
                    printf("Nome completo: %s %s\n", pacientes[i].nome_paciente);
                }else{
                    printf("Nome completo: %s %s %s\n", pacientes[i].nome_paciente, pacientes[i].email_paciente);
                }
                if(pacientes[i].cov_positivo == 1){
                    printf("COVID 19: POSITIVO\n\n");
                }else{
                    printf("COVID 19: NEGATIVO\n\n");
                }
                printf("-------------------------------------------------------------------------\n\n");
                nome_encontrado = 1;
            }
        }
    }


     if(nome_encontrado == 0){
        printf("\n\nNão há registro referente ao nome informado.\nTecle 1 p/ pra tentar novamente ou 2 p/ voltar ao menu:\n");
        scanf("%d", &op);
        if(op == 1){
            system("cls");
            filtrar_paciente_nome();
        }else{
            system("cls");
            filtrar_registros();
        }
    }

    printf("Pressione qualquer tecla para voltar...\n");
    if(getch()){
        system("cls");
        filtrar_registros();
    }

}



void ordenar_pacientes_cadastro(){


  int i, j, aux, op;

    printf("ORDENAÇÃO DE REGISTROS POR CADASTRO \n");
    printf("------------------------------------\n\n");
    printf("Deseja colocar os registros em:\n1. Ordem Crescente\n2. Ordem Decrescente\n\n");
    scanf("%d", &op);
    system("cls");

    if(op == 1){
        // Algoritmo de ordenação crescente: INSERTION SORT (ALGORITMO DE INSERÇÃO)
        for (j = 1; j < contadorPacientes; ++j) {
            aux = pacientes[j].id;
            for (i = j-1; i >= 0 && pacientes[i].id > aux; --i){
                pacientes[i+1].id = pacientes[i].id;
            }
            pacientes[i+1].id = aux;
        }

        printf("ORDENAÇÃO CRESCENTE DE REGISTROS POR CADASTRO\n");
        printf("----------------------------------------------\n\n");

       for(i=0; i < contadorPacientes; i++){
            printf("\nPaciente %d\n\n", i+1);
            printf("Cadastro: %d\n", pacientes[i].id);
            if(strcmp(pacientes[i].email_paciente, "0") == 0){
                printf("Nome completo: %s %s\n", pacientes[i].nome_paciente);
            }else{
                printf("Nome completo: %s %s %s\n", pacientes[i].nome_paciente, pacientes[i].email_paciente);
            }
            if(pacientes[i].cov_positivo == 1){
                printf("COVID 19: POSITIVO\n\n");
            }else{
                printf("COVID 19: NEGATIVO\n\n");
            }
            printf("----------------------------------------------------------------------\n\n");
       }
    }else{
        // Algoritmo de ordenação decrescente: INSERTION SORT (ALGORITMO DE INSERÇÃO)
        for (j = 1; j < contadorPacientes; ++j) {
            aux = pacientes[j].id;
            for (i = j-1; i >= 0 && pacientes[i].id < aux; --i){
                pacientes[i+1].id = pacientes[i].id;
            }
            pacientes[i+1].id = aux;
        }

        printf("ORDENAÇÃO DECRESCENTE DE REGISTROS POR CADASTRO\n");
        printf("------------------------------------------------\n\n");

       for(i = 0; i < contadorPacientes; i++){
            printf("\nPaciente %d\n\n", i+1);
            printf("Cadastro: %d\n", pacientes[i].id);
            if(strcmp(pacientes[i].email_paciente, "0") == 0){
                printf("Nome completo: %s %s\n", pacientes[i].nome_paciente);
            }else{
                printf("Nome completo: %s %s %s\n", pacientes[i].nome_paciente, pacientes[i].email_paciente);
            }
            if(pacientes[i].cov_positivo == 1){
                printf("COVID 19: POSITIVO\n\n");
            }else{
                printf("COVID 19: NEGATIVO\n\n");
            }
            printf("--------------------------------------------------------------------------\n\n");
       }
    }

     printf("Pressione qualquer tecla para voltar...\n");
     if(getch()){
        system("cls");
        ordenar_cadastro();
     }
}

void cadastrar_paciente(){
    int opc_cadastro, id_unico, i, k, letra = 0;
    char testeCadastro[3];
    char caminho[] = "arquivos_gerados/cadastro_pacientes.txt";

    if(contadorPacientes < 1000){
        do{
            FILE *cadastro_pacientes = fopen(caminho,"a");

            if(cadastro_pacientes == NULL){
                printf("\nErro: não foi possível abrir o arquivo.");
            }

            system("cls");
            printf("CADASTRO DE PACIENTES\n");
            printf("------------------\n\n");
            printf("Paciente %d:\n\n", contadorPacientes+1);
            fprintf(cadastrar_paciente, "Paciente %d:\n\n", contadorPacientes+1);
            do{
                letra = 0;
                fflush(stdin);
                printf("Cadastro: ");
                gets(testeCadastro);
                for(k=0; k<strlen(testeCadastro); k++){
                    if(isdigit(testeCadastro[k]) == 0){
                        letra = 1;
                    }
                }
                if(letra == 1){
                    printf("\nPor favor, digite somente números.\n\n");
                }
            }while(letra == 1);

            pacientes[contadorPacientes].id = atoi(testeCadastro);
            fprintf(cadastrar_paciente, "Cadastro: %d\n", pacientes[contadorPacientes].id);
            if(contadorPacientes != 0){
                id_unico = pacientes[contadorPacientes].id;
                for(i=0; i<contadorPacientes; i++){
                    if(pacientes[i].id == id_unico){
                        printf("\n\nO código de cadastro de paciente deve ser único. Tente novamente.");
                        Sleep(2);
                        system("cls");
                        cadastrar_paciente();
                    }
                }
            }
            fflush(stdin);
            printf("\nNome: ");
            scanf("%[^\n]s", pacientes[contadorPacientes].nome_paciente);
            fflush(stdin);
            printf("\nCPF: (se não possuir, tecle 0(zero)): ");
            scanf("%[^\n]s", pacientes[contadorPacientes].cpf_paciente);
            fflush(stdin);
            printf("\nE-mail (se não possuir, tecle 0(zero)): ");
            scanf("%[^\n]s", pacientes[contadorPacientes].email_paciente);
            
            printf("\nEndereço\n"); //Recebe as Strings da estrutura de Endereço
        	printf("\nRua:  ");
			scanf("%[^\n]s", pacientes[contadorPacientes].logradouro_paciente);
	        fflush(stdin);        	
			printf("\nComplemento: ");
			scanf("%[^\n]s", pacientes[contadorPacientes].complemento_paciente);
            fflush(stdin);        	
			printf("\nBairro: ");
			scanf("%[^\n]s", pacientes[contadorPacientes].bairro_paciente);
			fflush(stdin);        	
			printf("\nCidade: ");
			scanf("%[^\n]s", pacientes[contadorPacientes].cidade_paciente);
	        fflush(stdin);        	
			printf("\nEstado :");
			scanf("%[^\n]s", pacientes[contadorPacientes].estado_paciente);
            fflush(stdin);        	
			printf("\nCEP: ");
			scanf("%[^\n]s", pacientes[contadorPacientes].cep_paciente);
            fflush(stdin);
        	
			printf("\nComorbidades do Paciente: "); // Recebe a String das Comorbidades
			scanf("%[^\n]s", pacientes[contadorPacientes].comorbidade_paciente);
			fflush(stdin);
			
        	printf("\nData do Diagnóstico: "); //Recebe a String da Data
			scanf("%[^\n]s", pacientes[contadorPacientes].dataDiagnostico_paciente);
			
            fflush(stdin);            if(strcmp(pacientes[contadorPacientes].email_paciente, "0") == 0){
                fprintf(cadastro_pacientes,"Cadastro completo: %s %s\n",pacientes[contadorPacientes].nome_paciente, pacientes[contadorPacientes].cpf_paciente, pacientes[contadorPacientes].logradouro_paciente, pacientes[contadorPacientes].complemento_paciente, pacientes[contadorPacientes].bairro_paciente, pacientes[contadorPacientes].cidade_paciente, pacientes[contadorPacientes].estado_paciente, pacientes[contadorPacientes].cep_paciente, pacientes[contadorPacientes].comorbidade_paciente, pacientes[contadorPacientes].dataDiagnostico_paciente);
            }else{
                fprintf(cadastro_pacientes,"Cadastro completo: %s %s %s\n",pacientes[contadorPacientes].nome_paciente, pacientes[contadorPacientes].cpf_paciente, pacientes[contadorPacientes].email_paciente, pacientes[contadorPacientes].logradouro_paciente, pacientes[contadorPacientes].complemento_paciente, pacientes[contadorPacientes].bairro_paciente, pacientes[contadorPacientes].cidade_paciente, pacientes[contadorPacientes].estado_paciente, pacientes[contadorPacientes].cep_paciente, pacientes[contadorPacientes].comorbidade_paciente, pacientes[contadorPacientes].dataDiagnostico_paciente);
            }
            printf("\nPortador de COVID-19:\n");
            printf("1 - POSITIVO\n2 - NEGATIVO\n\n");
            scanf("%d", &pacientes[contadorPacientes].cov_positivo);
            if(pacientes[contadorPacientes].cov_positivo == 1){
                fprintf(cadastro_pacientes,"POSITIVO");
            }else{
                fprintf(cadastro_pacientes,"NEGATIVO");
            }
            fprintf(cadastro_pacientes,"\n------------------------------------------------------------\n\n");
            printf("\n\nPaciente %d cadastrado com sucesso!",contadorPacientes+1);

            fclose(cadastro_pacientes);

            if(pacientes[contadorPacientes].cov_positivo == 1){
                contC19_positivo++;
            }else{
            	
                contC19_negativo++;
            }

            contadorPacientes++;

            printf("\n\nDeseja cadastrar mais um paciente? 1-Sim/2-Não\n");
            scanf("%d", &opc_cadastro);

            if(opc_cadastro==2){
                system("cls");
                menu_administrador();
            }

            if(contadorPacientes == maxPacientes){
                printf("\n\n A capacidade de registros de pacientes esgotou.");
                Sleep(2);
                system("cls");
                menu_administrador();
            }

        }while(opc_cadastro == 1 && contadorPacientes < maxPacientes);
    }else{
        printf("\n\n A capacidade de registros de pacientes esgotou.");
        Sleep(2);
        system("cls");
        menu_administrador();
	}
}
void ordenar_nome(){
    int i, j;

    char **nomes_ordenados;
    char *aux;

    nomes_ordenados = (char **)malloc(contadorPacientes*sizeof(char*));
    aux = (char *)malloc(50*sizeof(char));

    printf("ORDENAR NOMES\n");
    printf("-------------\n\n");

    for(i=0; i<contadorPacientes; ++i){
        nomes_ordenados[i] = (char*) malloc(15*sizeof(char));
        strcpy(nomes_ordenados[i],pacientes[i].nome_paciente);
    }

    for(i=1; i<contadorPacientes; i++){
        for(j=0; j<contadorPacientes-1; j++){
            if(strcmp(nomes_ordenados[j], nomes_ordenados[j+1]) > 0){
                strcpy(aux, nomes_ordenados[j]);
                strcpy(nomes_ordenados[j], nomes_ordenados[j+1]);
                strcpy(nomes_ordenados[j+1], aux);
            }
        }
    }

    free(aux);

    //imprimindo os nomes ordenados
    for(i = 0; i < contadorPacientes; ++i){
        printf("\nPaciente %d\n\n", i+1);
        printf("Cadastro: %d\n", pacientes[i].id);
        if(strcmp(pacientes[i].email_paciente, "0") == 0){
            printf("Nome completo: %s %s\n", nomes_ordenados[i], pacientes[i].email_paciente);
        }else{
            printf("Nome completo: %s %s %s\n", nomes_ordenados[i], pacientes[i].email_paciente);
        }
        if(pacientes[i].cov_positivo == 1){
            printf("COVID 19: POSITIVO\n\n");
        }else{
            printf("COVID 19: NEGATIVO\n\n");
        }
        printf("------------------------------------------------\n\n");
    }

    //liberando a memória alocada dinamicamente
   for(i = 0; i < contadorPacientes;++i){
        free(nomes_ordenados[i]);
   }

     //liberando a memória alocada dinamicamente
    free(nomes_ordenados);

    printf("Pressione qualquer tecla para voltar...\n");
     if(getch()){
        system("cls");
        ordenar_cadastro();
     }

}
void ordenar_cadastro(){
    int op;
    printf("ORDENAR PACIENTES\n");
    printf("--------------\n\n");

    printf("Ordenar por:\n1. Código de Cadastro\n2. Nome\n3. Voltar\n\n");
    scanf("%d", &op);
    if(op == 1){
        system("cls");
        ordenar_cadastro();
    }else{
        if(op == 2){
           system("cls");
            ordenar_nome();
        }else{
            system("cls");
            menu_medico();
        }
    }
}

void listar_pacientes(){


    printf("RELAÇÃO DE PACIENTES\n");
    printf("-----------------\n\n");
    if(contadorPacientes==0){
        printf("Ainda não há registros de pacientes no sistema.\n\n");
    }else{
        int i;
        for(i=0; i<contadorPacientes; i++){
            printf("--------------------------------------------------------------------------\n");
            printf("\nPaciente %d\n\n", i+1);
            printf("Cadastro: %d\n", pacientes[i].id);
            if(strcmp(pacientes[i].email_paciente, "0") == 0){
                printf("Nome completo: %s %s\n", pacientes[i].nome_paciente;
            }else{
                printf("Nome completo: %s %s %s\n", pacientes[i].nome_paciente, pacientes[i].email_paciente);
            }
            if(pacientes[i].cov_positivo == 1){
                printf("COVID 19: POSITIVO\n\n");
            }else{
                printf("COVID 19: NEGATIVO\n\n");
            }
            printf("--------------------------------------------------------------------------\n\n");
        }
    }

    printf("Pressione qualquer tecla para voltar...\n");
    if(getch()){
        system("cls");
        menu_medico();
    }

}
