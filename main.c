#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <conio.h>

/*git repositorio 20092016 0628*/

/*definindo variavel para registro de estudantes*/
typedef struct {
int cpf;
char nome[50];
char sexo;
float notas[4];
float media;
} TESTUDANTE;

/* definindo variaveis globais */
int nroMaxAlunos=50;
int codCadastro;
TESTUDANTE aluno[50];
TESTUDANTE est;

/* funcoes auxiliares */
void menu();
int buscaEstudante();
void lerAluno();
void gravarAluno();
void addMenu();
void verMatAluno();
void veRegistro();

/* funcao principal */
int main(){
    setlocale(LC_ALL, "portuguese");
    addMenu();
    return 0;
}


/* grava o registro do estudante */
void gravarAluno(TESTUDANTE registrar, int a){
    aluno[a] = registrar;
    codCadastro++;
}

/* confere se a matricula ja foi registrada */
int buscaEstudante(TESTUDANTE mat){
    int i;
    for (i=0; i<nroMaxAlunos ; i++)
    if (aluno[i].cpf == mat.cpf)
        return i;
    return -1;
}

/* leitura dos dados do aluno*/
void lerAluno(){
    printf("Digite o CPF:\n");
    scanf("%d", &est.cpf);
    int i = buscaEstudante(est);
    if ( i != -1 )
        printf("\nMatrícula já cadastrada\n");
    else if (codCadastro == nroMaxAlunos)
        printf("\nNúmero máximo de estudantes ultrapassado\n");
        else {
            printf("\nDigite o nome do aluno:\n");
            scanf("%s", est.nome);
            printf("\nDigite o sexo: H ou M\n");
            est.sexo = getche();
            printf("\nDigite as notas:\n");
            int i;
            float soma=0;
            for (i=0; i<4; i++){
                scanf("%f", &est.notas[i]);
<<<<<<< HEAD
                soma += est.notas[i];
            }
            est.media = soma/4;
=======
>>>>>>> origin/miniprojeto
            gravarAluno(est, codCadastro);
            printf("\nCadastrado realizado com sucesso\n");
    }
}

void veRegistro(){
    int i;
    for (i=0; i<codCadastro; i++){
        printf("CPF: %d  ", aluno[i].cpf);
        printf("NOME: %s  ", aluno[i].nome);
        printf("SEXO: %c  ", aluno[i].sexo);
        printf("NOTA 1: %f  ", aluno[i].notas[0]);
        printf("NOTA 2: %f  ", aluno[i].notas[1]);
        printf("NOTA 3: %f  ", aluno[i].notas[2]);
        printf("NOTA 4: %f  ", aluno[i].notas[3]);
        printf("MEDIA: %f\n", aluno[i].media);
    }
}

void apagaRegistro(){
    printf("\nQual registro deseja apagar:\n\n");
    scanf("%d", &est.cpf);
    int i = buscaEstudante(est);
    if ( i != -1 )
        {
        int j;
        for (j=0; j<codCadastro; j++){
            if (aluno[j].cpf == est.cpf) {
                for(i=j ; i<codCadastro-1 ; i++) aluno[i]=aluno[i+1];
                codCadastro--;
            }
        }
    printf("\n Registro apagado \n");
    }
    else printf("\n Registro nao existe\n");
}

void altRegistro(){
    printf("\n Qual matricula deseja alterar?\n\n");
    scanf("%d", &est.cpf);
    int i;
    for (i=0; i<codCadastro; i++){
<<<<<<< HEAD
        if (aluno[i].cpf == est.cpf) {
=======
        if (aluno[i].cpf == a.cpf) {
                for( ; i<codCadastro-1 ; i++) aluno[i]=aluno[i+1];
                codCadastro--;
            }
    }
    printf("\n Registro apagado \n");
}

void altRegistro(){
    printf("\n Qual matricula deseja alterar?\n\n");
    scanf("%d", &est.cpf);
    int i;
    for (i=0; i<codCadastro; i++){
        if (aluno[i].cpf == est.cpf) {
>>>>>>> origin/miniprojeto
            printf("\nDigite o nome do aluno:\n");
            scanf("%s", est.nome);
            printf("\nDigite o sexo: H ou M\n");
            est.sexo=getche();
            printf("\nDigite as Notas:\n");
            int j;
<<<<<<< HEAD
            float soma=0;
            for (j=0; j<4; j++){
                scanf("%f", &est.notas[j]);
                soma += est.notas[j];
            }
            est.media = soma/4;
            gravarAluno(est, i);
            codCadastro--;
            printf("\nCadastrado alterado com sucesso\n");
        }
    }
}

/* exibe menu de opcoes */
void menu (){
printf("============================================\n");
printf("\t\tMenu\t\t\n");
printf("============================================\n");
printf ("1. Adicione registro de estudante\n");
printf ("2. Apague registro de estudante\n");
printf ("3. Atualize registro de estudante\n");
printf ("4. Ver todos os registros\n");
printf ("5. Calcular a média de um estudante\n");
printf ("6. Mostrar o estudante que conseguiu a maior média\n");
printf ("7. Mostrar o estudante com a menor média\n");
printf ("8. Encontrar estudante pela matrícula\n");
printf ("9. Encontrar estudante pelo nome\n");
printf ("10. Mostrar os registros ordenados pela média\n");
printf ("0. Sair do programa\n");
=======
            for (j=0; j<4; j++) scanf("%f", &est.notas[j]);
            gravarAluno(est, i);
            codCadastro--;
            printf("\nCadastrado alterado com sucesso\n");
        }
    }
>>>>>>> origin/miniprojeto
}

/* Menu de seleção */
void addMenu(){
    menu();
    int opcao;
    printf("\nDigite a opção desejada do MENU\n\n");
    scanf("%d", &opcao);
    while (opcao != 0){
            switch (opcao){
                case 0: return 0;
                case 1: lerAluno(); break;
                case 2: apagaRegistro(); break;
                case 3: altRegistro(); break;
                case 4: veRegistro(); break;
                case 5: printf("\n opcao 5 em construcao\n\n"); break;
                case 6: printf("\n opcao 6 em construcao\n\n"); break;
                case 7: printf("\n opcao em construcao\n\n"); break;
                case 8: verMatAluno(); break;
                case 9: printf("\n opcao em construcao\n\n"); break;
                case 10: verMedia(); break;
                default: printf("\n DIGITE UMA OPCAO VALIDA!\n\n"); break;
                }
            menu();
            printf("\n Digite a opção desejada do MENU\n\n");
            scanf("%d", &opcao);
            }
}

void verMatAluno(){
    printf("\n Qual matricula deseja visualisar?\n");
    scanf("%d", &est.cpf);
    int i = buscaEstudante(est);
    if ( i != -1 ){
        for (i=0; i<codCadastro; i++){
        if (aluno[i].cpf == est.cpf) {
            printf("CPF: %d  ", aluno[i].cpf);
            printf("NOME: %s  ", aluno[i].nome);
            printf("SEXO: %c  ", aluno[i].sexo);
            printf("NOTA 1: %f  ", aluno[i].notas[0]);
            printf("NOTA 2: %f  ", aluno[i].notas[1]);
            printf("NOTA 3: %f  ", aluno[i].notas[2]);
            printf("NOTA 4: %f\n", aluno[i].notas[3]);
            }
        }
    }
    else printf("\n Registro nao existe\n");
}

void verMedia(){
    int i,h;
    for (i=0; i<codCadastro; i++){
            est.media=0;
            for (h=0; h<codCadastro ; h++){
            if ( aluno[h].media>=est.media) est.media=aluno[h].media;
            printf("MEDIA: %f\n", est.media);
            }
        }
}
