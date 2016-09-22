#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <conio.h>

/*definindo variavel para registro de estudantes*/
typedef struct
{
int cpf;
char nome[50];
char sexo;
float notas[3];
float projeto;
float media;
} TESTUDANTE;

/* definindo variaveis globais */
const int nroMaxAlunos=50;
int codCadastro;
TESTUDANTE aluno[50];
TESTUDANTE est;

/* funcoes auxiliares */
void gravarAluno(TESTUDANTE registrar, int a);
int buscaEstudante(TESTUDANTE mat);
void lerAluno();
void verAluno(int i);
void verTodos();
void apagaRegistro();
void altRegistro();
void menu();
int addMenu();
void verMatAluno();
void verMedia();
void dadosAluno();
void calcMedia();
void ordemMedia();
void maiorMedia();
void menorMedia();
void encNome();
int tamNome(int i);
void verMediaOrdem();

/* funcao principal */
int main()
{
    setlocale(LC_ALL, "portuguese");
    addMenu();
    return 0;
}


/* grava o registro do estudante */
void gravarAluno(TESTUDANTE registrar, int a)
{
    aluno[a] = registrar;
    codCadastro++;
}

/* confere se a matricula ja foi registrada */
int buscaEstudante(TESTUDANTE mat)
{
    int i;
    for (i=0; i<nroMaxAlunos ; i++)
    if (aluno[i].cpf == mat.cpf)
        return i;
    return -1;
}

void dadosAluno()
{
    printf("\nDigite o nome do aluno:\n");
    /*scanf("%[^\n]", est.nome);*/
    fflush(stdin);
    gets(est.nome);
    printf("\nDigite o sexo: H ou M\n");
    est.sexo = getche();
    /*scanf("%c", est.sexo); apresenta erro na execucao*/
    printf("\nDigite as 3 notas:\n");
    int i;
    for (i=0; i<3; i++)
        scanf("%f", &est.notas[i]);
    calcMedia();
    printf("\nDigite a nota do Projeto:\n");
    scanf("%f", &est.projeto);
}

/* leitura dos dados do aluno*/
void lerAluno()
{
    printf("Digite o CPF:\n");
    scanf("%d", &est.cpf);
    int i = buscaEstudante(est);
    if ( i != -1 )
        printf("\nMatrícula já cadastrada\n");
    else if (codCadastro == nroMaxAlunos)
        printf("\nNúmero máximo de estudantes ultrapassado\n");
        else dadosAluno(); {
    gravarAluno(est, codCadastro);
    system("cls");
    printf("\nCadastrado realizado com sucesso\n\n\n"); }
}

void verAluno(int i)
{
        printf("\nNOME: %s  ", aluno[i].nome);
        printf("CPF: %d  ", aluno[i].cpf);
        printf("SEXO: %c\n", aluno[i].sexo);
        printf("NOTA 1: %.2f ", aluno[i].notas[0]);
        printf("NOTA 2: %.2f ", aluno[i].notas[1]);
        printf("NOTA 3: %.2f ", aluno[i].notas[2]);
        printf("MEDIA: %.2f\n", aluno[i].media);
        printf("Projeto: %.2f\n\n", aluno[i].projeto);
        printf("(pressione qualquer tecla)\n\n");
        getch();
}

void verTodos()
{
    int i;
    for (i=0 ; i<codCadastro ; i++)
        verAluno(i);
    system("cls");
    printf("\nTodos os registros foram mostrados.\n\n\n");
}

void apagaRegistro()
{
    printf("\nQual registro deseja apagar:\n\n");
    scanf("%d", &est.cpf);
    int i = buscaEstudante(est);
    if ( i != -1 )
    {
        int j;
        for (j=0; j<codCadastro; j++)
        {
            if (aluno[j].cpf == est.cpf)
            {
                aluno[i]=aluno[codCadastro];
                codCadastro--;
            }
        }
        system("cls");
        printf("\n Registro apagado \n\n\n");
    }
    else { system("cls");
         printf("\n Registro nao existe\n\n\n"); }
}


void altRegistro()
{
    printf("\n Qual matricula deseja alterar?\n\n");
    scanf("%d", &est.cpf);
    int i, checkalt=0;
    for (i=0; i<codCadastro; i++){
        if (aluno[i].cpf == est.cpf) {
            dadosAluno();
            checkalt++; }
        }
    if(checkalt==0){
        system("cls");
        printf("\nEssa matrícula não existe.\n\n\n");
    }
    else {
        system("cls");
        printf("\nRegistro alterado com sucesso.\n\n\n");
    }
}

/* exibe menu de opcoes */
void menu()
{
printf("============================================\n");
printf("\t\tMenu\t\t\n");
printf("============================================\n");
printf("(Obs: O Número de matricula é o cpf do aluno.)\n");
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
}

/* Menu de seleção */
int addMenu()
{
    menu();
    int opcao;
    printf("\nDigite a opção desejada do MENU\n\n");
    scanf("%d", &opcao);
    while (opcao != 0)
        {
            switch (opcao)
            {
                case 0: break;
                case 1: lerAluno(); break;
                case 2: apagaRegistro(); break;
                case 3: altRegistro(); break;
                case 4: verTodos(); break;
                case 5: verMedia(); break;
                case 6: maiorMedia(); break;
                case 7: menorMedia(); break;
                case 8: verMatAluno(); break;
                case 9: encNome(); break;
                case 10: verMediaOrdem(); break;
                default: { system("cls");
                         printf("\n DIGITE UMA OPCAO VALIDA!\n\n"); } break;
            }
            menu();
            printf("\n Digite a opção desejada do MENU\n\n");
            scanf("%d", &opcao);
        }
    return 0;
}

void verMatAluno()
{
    printf("\n Qual matricula deseja visualisar?\n");
    scanf("%d", &est.cpf);
    int i = buscaEstudante(est);
    if ( i != -1 )
        {
        for (i=0; i<codCadastro; i++)
            {
            if (aluno[i].cpf == est.cpf) {
                verAluno(i);
                system("cls");
                printf("\nRegistro visualizado.\n\n\n"); }
            }
        }
    else { system("cls");
        printf("\n Registro inexistente\n\n\n"); }
}



void calcMedia()
{
    float soma=0;
    int i;
    for (i=0; i<3; i++)
        soma += est.notas[i];
    est.media = soma/3;
}

void verMedia()
{
    printf("\n Digite a matrícula do aluno.\n");
    scanf("%d", &est.cpf);
    int i = buscaEstudante(est);
    if ( i != -1 )
        {
        for (i=0; i<codCadastro; i++)
            {
            if (aluno[i].cpf == est.cpf){
                system("cls");
                printf("\nMEDIA DO ALUNO %s: %.2f\n\n\n", aluno[i].nome, aluno[i].media); }
            }
        }
    else { system("cls");
        printf("\n Registro inexistente\n\n\n"); }
}

void ordemMedia()
{
    int i,h;
    for (i=0; i<codCadastro-1; i++)
    {
        for (h=0; h<codCadastro-1-i ; h++)
        {
            if (aluno[h].media>aluno[h+1].media)
            {
                est=aluno[h+1];
                aluno[h+1]=aluno[h];
                aluno[h]=est;
            }
        }
    }
}

void maiorMedia()
{
    ordemMedia();
    int i = codCadastro-1;
    system("cls");
    printf ("\nAluno %s tem a maior media: %.2f \n\n\n", aluno[i].nome, aluno[i].media);
}

void menorMedia()
{
    ordemMedia();
    system("cls");
    printf ("\nAluno %s tem a menor media: %.2f \n\n\n", aluno[0].nome, aluno[0].media);
}

void encNome()
{
    printf("\n Digite nome do aluno:\n");
    scanf("%s", est.nome);
    int i,h;
    for (i=0; i<codCadastro; i++)
    {
        h=tamNome(i);
        int j=0;
        while ( est.nome[j] == aluno[i].nome[j] &&
           est.nome[j] != '\0' &&
           aluno[i].nome[j] != '\0' )
           j++;
        if (j==h) verAluno(j);
        else printf("\n Registro inexistente\n");
    }
}

int tamNome(int i)
{
    int j=0;
    while (aluno[i].nome[j] != '\0')
        j++;
    return j;
}

void verMediaOrdem()
{
    ordemMedia();
    verTodos();
}
