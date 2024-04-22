#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define Alunos_Max 100
#define Nome_Max 50
#define Curso_Max 25

// informações do arquivo DadosEntrada em struct
typedef struct
{
    char nome[Nome_Max];
    char telefone[20];
    char curso[Curso_Max];
    float notas[2];
} Inscrito;

float calculaMedia(float notas[], float num_notas)
{
    float media = 0;
    for (int i = 0; i < num_notas; i++)
    {
        // Aqui o array vai se somando até prencher
        media += notas[i];
    }
    return media / num_notas;
}

// Utilizado essa função para retirar a necessidade de criar uma copia a cada loop
char *resultadoMedia(float media)
{
    return media >= 7.0 ? "APROVADO" : "REPROVADO";
}

int main()
{
    int alunos_qtd = 0;
    Inscrito incritos[Alunos_Max];
    FILE *planilhaEntrada, *planilhaSaida;

    planilhaEntrada = fopen("DadosEntrada.csv", "r");
    planilhaSaida = fopen ("SituaçãoFinal.csv", "w");

    if (planilhaEntrada == NULL || planilhaSaida == NULL)
    {
        printf("Erro ao encontrar o arquivo! Codigo 13");
        return 13;
    }

    char cabecalho[100];
    fgets (cabecalho, sizeof(cabecalho), planilhaEntrada);

    //While para o arquivo entrada ser lido e armazenado.
    while (alunos_qtd < Alunos_Max && fscanf (planilhaEntrada, "%[^,],%[^,],%[^,],%f,%f\n", inscrito[Alunos_Max].nome, inscrito[Alunos_Max].telefone, inscrito[Alunos_Max].curso, &inscrito[Alunos_Max].notas[0], &inscrito[Alunos_Max].notas[1] == 5))
    {
        alunos_qtd++;
    }

    fprintf("PlanilhaSaida", "Nome,Media_nominal,Resultado\n");
    
    //for para ir preenchendo a cada loop a situação do aluno
    for (int i = 0; i < Alunos_Max; i++)
    {
        float media = calculaMedia(inscrito[i], 2);
        char* resultado = resultadoMedia(media);
        fprintf("%s,%.2f,%s\n", inscrito.nome, media, resultado);
    }

    printf("Criado arquivo de saida chamado situacaoFinal.csv!");

    fclose("planilhaEntrada");
    fclose("planilhaSaida");    

    return 0;
}