/*
UNIVERSIDADE CATÓLICA DE BRASÍLIA
CURSO: ANÁLISE E DESENVOLVIMENTO DE SISTEMAS
DISCIPLINA: PROGRAMAÇÃO ESTRUTURADA
DOCENTE: JOYCE SIQUEIRA
DISCENTE: RAFAEL RIKI OGAWA OSIRO (UC21100716)

Exercício: 1. Desenvolva um programa em C utilizando registro que permita a entrada de nome, endereço e 
telefone de 3 pessoas e os imprima ao final.
*/

// !LIBRARIES _________________________________________________________________________________________________
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>
#include<stdbool.h>
#include<ctype.h>

//! STRUCTS ___________________________________________________________________________________________________
struct DadosAluno
{
    char fullName[50];
    int age;
};

//! MESSAGES OF THE SYSTEM ____________________________________________________________________________________
void messageTitle();
void messageMenu();
void messageNameInput(int index, int option);
void messageConfirmExit();
void messageExit();
void messageName(struct DadosAluno *alunos, int size);


//! ERROR MESSAGES OF THE SYSTEM ______________________________________________________________________________
void errorMessageInput(int quantityOfError, int option);
void errorExit();

//! VALIDATION INPUT __________________________________________________________________________________________
bool validationString(char *string);
bool validationAge(int age);

//! FUNCTION OF THE SYSTEM ____________________________________________________________________________________
int functionOptionInput();
void functionInputString(struct DadosAluno *alunos, int size);


int main()
{
    int option, quantityOfError = 0, size;
    struct DadosAluno alunos[1];
    bool validation = false, exitValidation = false;

    size = sizeof(alunos)/sizeof(alunos[0]);

    do
    {
        messageTitle();
        messageMenu();
        option = functionOptionInput();

        switch (option)
        {
        case 1:
            system("cls");
            quantityOfError = 0;
            
            functionInputString(alunos, size);
            messageName(alunos, size);
            break;
        
        case 2:
            system("cls");
            quantityOfError = 0;
            
            do
            {
                messageConfirmExit();
                option = functionOptionInput();

                if (option == 1)
                {
                    exitValidation = true;
                    validation = true; 
                }
                else if(option == 2)
                {
                    exitValidation = true;
                    validation = false;
                }
                else
                {
                    exitValidation = false;
                    system("cls");
                    quantityOfError++;
                    errorMessageInput(quantityOfError, 1);

                    if (quantityOfError == 3)
                    {
                        errorExit();
                        exit(EXIT_FAILURE);
                    }    
                }

            } while (exitValidation == false);


            system("cls");
            quantityOfError = 0;
            
            break;

        default:
            system("cls");
            quantityOfError++;
            errorMessageInput(quantityOfError, 1);

            if (quantityOfError == 3)
            {
                errorExit();
                exit(EXIT_FAILURE);
            }
            break;
        }
    
    } while (validation == false);
    
    messageExit();
    exit(EXIT_SUCCESS);
}

//! MESSAGES OF THE SYSTEM ____________________________________________________________________________________

//  MESSAGE TITLE OF THE SYSTEM
void messageTitle()
{
    printf("SISTEMA PARA FORMATAR OS NOMES\n\n\n");
}

//  MESSAGE MENU
void messageMenu()
{
    printf("---------------------------------\n");
    printf("[1] ENTRADA DOS DADOS DE UM ALUNO\n");
    printf("[2] SAIR DO PROGRAMA\n");
    printf("---------------------------------\n\n");
    printf("DIGITE A OP\200\307O DESEJADA: ");
}

//  MESSAGE ASK NAME INPUT
void messageNameInput(int index, int option)
{
    switch (option)
    {
    case 1:
        printf("DIGITE O NOME DO ALUNO %d: ", index);
        break;
    
    case 2:
        printf("DIGITE A IDADE ALUNO %d: ", index);
        break;

    default:
        break;
    }
}

//  MESSAGE ASK CONFIRM EXIT OF THE SYSTEM
void messageConfirmExit()
{
    printf("DESEJA CONFIRMAR A SA\326DA DO SISTEMA?\n\n");
    printf("-------\n");
    printf("[1] SIM\n");
    printf("[2] N\307O\n");
    printf("-------\n\n");
    printf("DIGITE A OP\200\307O DESEJADA: ");
}

//  MESSAGE TO EXIT SYSTEM
void messageExit()
{
    printf("O SISTEMA IR\265 FINALIZAR\n");
}

//  MESSAGE TO PRINT THE NAMES
void messageName(struct DadosAluno *alunos, int size)
{
    printf("Nome do aluno: %s\n", alunos->fullName);
    printf("Idade: %d\n\n\n\n", alunos->age);
}

//! ERROR MESSAGES OF THE SYSTEM ______________________________________________________________________________

//  ERROR MESSAGE INPUT
void errorMessageInput(int quantityOfError, int option)
{
    switch (option)
    {
    case 1:
        printf("ERRO %d de 3!\n", quantityOfError);
        printf("DIGITE UMA OP\200\307O V\265LIDA\n\n\n");
        break;
    
    case 2:
        printf("ERRO %d de 3!\n", quantityOfError);
        printf("DIGITE UMA IDADE V\265LIDO ENTRE 0 E 120 ANOS\n\n\n");
        break;

    default:
        break;
    }
}

//  ERROR EXIT SYSTEM
void errorExit()
{
    printf("QUANTIDADE DE ERROS ATINGIDO!\n");
    printf("O SISTEMA IR\265 FINALIZAR!\n\n\n");
}

//! VALIDATION INPUT __________________________________________________________________________________________

//  FUNCTION TO VALIDATE A STRING
bool validationString(char *string)
{
    int index = 0;

    if (strlen(string) == 1)
    {
        if (string[index] == "\n" || string[index] == " " || string[index] == '\0' || string[index] == '\r' || 
        string[index] == '\r\n' || !isalpha(string[index] || !isdigit(string[index])))
        {
            return false;
        }
    }
    else
    {
        while (index < strlen(string))
        {
            if (string[index] != "\n" && string[index] != " " && string[index] != '\0' && string[index] != '\r' && 
            string[index] != '\r\n' && !isspace(string[index]) && (isalpha(string[index]) || isdigit(string[index])))
            {
                return true;
            }
            index++;
        }

        return false;
    }

    return false;
}

//  FUNCTION TO VALIDATE A NUMBER
bool validationAge(int age)
{
    if (age < 0)
    {
        return false;
    }
    else if (age >= 0 && age <= 120)
    {
        return true;
    }
    else
    {
        return false;
    }
}

//! FUNCTION OF THE SYSTEM ____________________________________________________________________________________

//  FUNCTION OPTION INPUT
int functionOptionInput()
{
    int number;

    fflush(stdin);
    scanf("%d", &number);

    return number;
}

//  FUNCTION INPUT STRING
void functionInputString(struct DadosAluno *alunos, int size)
{
    int quantityOfError = 0, count = 0;
    bool validation = false;

    for (int i = 0; i < size; i++)
    {
        while (validation == false)
        {
            messageTitle();
            messageNameInput(i+1, 1);
            fflush(stdin);
            fgets(alunos[i].fullName, sizeof(alunos[i].fullName), stdin);
            validation = validationString(alunos[i].fullName);

            if (strlen(alunos[i].fullName) == sizeof(alunos[i].fullName))
            {
                char charactere;
                while ((charactere = getchar()) != '\n' && charactere != EOF);
            }
            else
            {
                int j = strlen(alunos[i].fullName);
                alunos[i].fullName[j-1] = '\0';
            }

            if (validation == false)
            {
                system("cls");
                quantityOfError++;
                errorMessageInput(quantityOfError, 2);

                if (quantityOfError == 3)
                {
                    errorExit();
                    exit(EXIT_FAILURE);
                }
            }
        }

        system("cls");
        count = 0;
        validation = false;

        
        while (validation == false)
        {
            messageTitle();
            messageNameInput(i+1, 2);
            fflush(stdin);
            scanf("%d", &alunos[i].age);

            validation = validationAge(alunos[i].age);
            if (validation == false)
            {
                system("cls");
                quantityOfError++;
                errorMessageInput(quantityOfError, 3);

                if (quantityOfError == 3)
                {
                    errorExit();
                    exit(EXIT_FAILURE);
                }
            }
        }

        system("cls");
        count = 0;
        validation = false;
    }
}