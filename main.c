
#include <stdio.h>
#include <stdlib.h>

struct myDados
{
    char usuario[16];
    char senha[16];
    char nome[16];
    char telefone[16];
    int clienteCadastrado;
    char nomePet[10][16];
    int numPet;
    int banhoETosa[10][2];
    int numBanho;
    int consulta[10][3];
    int numConsulta;
};

//[as 7 coisas guardadas, [0]usuario, [1]senha, [2]nome, [3]telefone, [4]pet, [5]banho, [6]consulta] [10 usuarios] [10 pets se precisar, o resto coloca tudo no 0] [ate 15 caracteres]

int main()
{
    struct myDados veetor[10];
    int numUsuarios = 0;
    inicio(veetor, numUsuarios);
    return 0;
}

void inicio(struct myDados veetor[10], int numUsuarios)
{
    system("cls");
    cadOrLogin(veetor, numUsuarios);
}

void cadOrLogin(struct myDados veetor[10], int numUsuarios)
{
    system("cls");
    int value;
    puts("1 | fazer cadastro");
    puts("2 | fazer login");
    puts("3 | sair");
    scanf("%d", &value);
    getchar();
    fflush(stdin);

    switch (value)
    {
    case 1:
        system("cls");
        cadastro(veetor, numUsuarios);
        break;
    case 2:
        system("cls");
        login(veetor, numUsuarios);
        break;
    case 3:
        system("cls");
        puts("Volte sempre ao Super PetShop Gustavo BCC");
        break;
    default:
        system("cls");
        puts("Comando nao reconhecido \n");
        cadOrLogin(veetor, numUsuarios);
        break;
    }
}

void cadastro(struct myDados veetor[10], int numUsuarios)
{
    system("cls");
    int i = 0;
    puts("digite seu usuario: ");
    fgets(veetor[numUsuarios].usuario, 15, stdin);
    fflush(stdin);
    puts("digite sua senha: ");
    fgets(veetor[numUsuarios].senha, 15, stdin);
    fflush(stdin);
    veetor[numUsuarios].usuario[strcspn(veetor[numUsuarios].usuario, "\n")] = '\0';
    veetor[numUsuarios].senha[strcspn(veetor[numUsuarios].senha, "\n")] = '\0';

    veetor[numUsuarios].numBanho = 0;
    veetor[numUsuarios].numPet = 0;
    veetor[numUsuarios].numConsulta = 0;
    numUsuarios++;
    system("cls");
    inicio(veetor, numUsuarios);
}

void login(struct myDados veetor[10], int numUsuarios)
{
    system("cls");
    int usuarioConectado;
    char usuarioLogin[16];
    char senhaLogin[16];
    puts("digite seu usuario: ");
    fgets(usuarioLogin, 9, stdin);
    fflush(stdin);
    puts("digite sua senha: ");
    fgets(senhaLogin, 9, stdin);
    fflush(stdin);
    
    if (numUsuarios > 0)
    {
        int usuarioVerificado;
        int senhaVerificada;
        usuarioLogin[strcspn(usuarioLogin, "\n")] = '\0';
        senhaLogin[strcspn(senhaLogin, "\n")] = '\0';
        for (int j = 0; j < 10; j++)
        {
            usuarioVerificado = strcmp(veetor[j].usuario, usuarioLogin);
            senhaVerificada = strcmp(veetor[j].senha, senhaLogin);
            if (senhaVerificada == 0 && usuarioVerificado == 0)
            {
                usuarioConectado = j;
                break;
            }
        }

        if (senhaVerificada == 0 && usuarioVerificado == 0)
        {
            system("cls");
            menu(veetor, usuarioConectado);
        }
        else
        {
            system("cls");
            puts("Login incorreta!\n");

            int value;
            puts("1 | Tentar novamente");
            puts("2 | voltar ao menu");
            scanf("%d", &value);
            getchar();
            fflush(stdin);

            switch (value)
            {
            case 1:
                system("cls");
                login(veetor, numUsuarios);
                break;
            case 2:
                system("cls");
                inicio(veetor, numUsuarios);
                break;
            default:
                puts("erro");
                login(veetor, numUsuarios);
                break;
            }
        }
    }
    else
    {
        system("cls");
        puts("Login incorreta!\n");

        int value;
        puts("1 | Tentar novamente");
        puts("2 | voltar ao menu");
        scanf("%d", &value);
        getchar();
        fflush(stdin);

        switch (value)
        {
        case 1:
            system("cls");
            login(veetor, numUsuarios);
            break;
        case 2:
            system("cls");
            inicio(veetor, numUsuarios);
            break;
        default:
            puts("erro");
            login(veetor, numUsuarios);
            break;
        }
    }
}

void nomePetShop()
{
    puts("Super PetShop Gustavo BCC");
}

void menu(struct myDados veetor[10], int usuarioConectado)
{
    nomePetShop();
    int value;
    puts("1 | Cadastrar cliente");
    puts("2 | Agendar banho e tosa");
    puts("3 | Agendar consulta");
    puts("4 | Imprimir relatorio geral");
    puts("5 | Sair");
    scanf("%d", &value);
    getchar();
    fflush(stdin);

    switch (value)
    {
    case 1:
        system("cls");
        cadastrarCliente(veetor, usuarioConectado);
        break;
    case 2:
        system("cls");
        banhoTosa(veetor, usuarioConectado);
        break;
    case 3:
        system("cls");
        consulta(veetor, usuarioConectado);
        break;
    case 4:
        system("cls");
        relatorioGeral(veetor, usuarioConectado);
        break;
    case 5:
        system("cls");
        puts("Volte sempre ao Super PetShop Gustavo BCC");
        inicio(veetor, 1);
        break;
    default:
        system("cls");
        puts("Opcao incorreta \n");
        menu(veetor, usuarioConectado);
        break;
    }
}

void cadastrarCliente(struct myDados veetor[10], int usuarioConectado)
{
    nomePetShop();
    char sOn = "n";

    if (veetor[usuarioConectado].numPet > 0)
    {
        puts("alterar dados do cadastro? [s] para sim [n] para nao");
        scanf("%c", &sOn);
        getchar();
    }

    if (veetor[usuarioConectado].numPet == 0 || sOn == 's')
    {
        printf("Cadastro de cliente\n");
        printf("Digite seu nome: \n");
        fgets(veetor[usuarioConectado].nome, 15, stdin);
        fflush(stdin);
        printf("Digite seu telefone: (so os numeros)\n");
        fgets(veetor[usuarioConectado].telefone, 15, stdin);
        fflush(stdin);
        system("cls");
    }
    char car;
    do
    {
        system("cls");
        nomePetShop();
        printf("Digite o nome do seu pet [max 10]\n");
        fgets(veetor[usuarioConectado].nomePet[veetor[usuarioConectado].numPet], 15, stdin);
        fflush(stdin);
        veetor[usuarioConectado].numPet++;
        veetor[usuarioConectado].nomePet[veetor[usuarioConectado].numPet][strcspn(veetor[usuarioConectado].nomePet[veetor[usuarioConectado].numPet], "\n")] = '\0';

        puts("continuar? \n[s] para sim\n[n] para nao\n");
        scanf("%c", &car);
        getchar();
    } while (car == 's' && veetor[usuarioConectado].numPet <= 10);
    if (veetor[usuarioConectado].numPet == 10)
    {
        puts("maximo de pets cadastrados");
    }
    system("cls");
    menu(veetor, usuarioConectado);
}

void banhoTosa(struct myDados veetor[10], int usuarioConectado)
{
    // system("cls");
    nomePetShop();

    char car;

    if (veetor[usuarioConectado].numPet > 0)
    {
        do
        {
            // system("cls");

            for (int j = 1; j <= veetor[usuarioConectado].numPet; j++)
            {
                printf("digite %d | para o(a) %s \n", j, veetor[usuarioConectado].nomePet[j - 1]);
            }
            int valuePet;
            scanf("%d", &valuePet);
            getchar();
            system("cls");
            system("cls");

            if (valuePet > 0 && valuePet <= veetor[usuarioConectado].numPet)
            {

                puts("digite :");
                puts("1 | Para agendar apenas banho");
                puts("2 | Para agendar apenas tosa");
                puts("3 | Para agendar banho e tosa");
                int valueOp;
                scanf("%d", &valueOp);
                getchar();
                system("cls");

                switch (valueOp)
                {
                case 1:
                    veetor[usuarioConectado].banhoETosa[veetor[usuarioConectado].numBanho][0] = valuePet;
                    veetor[usuarioConectado].banhoETosa[veetor[usuarioConectado].numBanho][1] = 1;
                    break;
                case 2:
                    veetor[usuarioConectado].banhoETosa[veetor[usuarioConectado].numBanho][0] = valuePet;
                    veetor[usuarioConectado].banhoETosa[veetor[usuarioConectado].numBanho][1] = 2;
                    break;
                case 3:
                    veetor[usuarioConectado].banhoETosa[veetor[usuarioConectado].numBanho][0] = valuePet;
                    veetor[usuarioConectado].banhoETosa[veetor[usuarioConectado].numBanho][1] = 3;

                    break;
                default:
                    puts("Erro");
                    banhoTosa(veetor, usuarioConectado);
                    break;
                }
                // system("cls");
                veetor[usuarioConectado].numBanho++;
            }
            else
            {
                system("cls");
                puts("erro");
                banhoTosa(veetor, usuarioConectado);
            }
            system("cls");

            puts("quer fazer outro agendamento? \n[s] para sim\n[n] para nao\n");
            scanf("%c", &car);
            getchar();
            veetor[usuarioConectado].numBanho++;
            veetor[usuarioConectado].numBanho = veetor[usuarioConectado].numBanho;
            system("cls");

            system("cls");
        } while (car == 's' && veetor[usuarioConectado].numBanho <= 10);
    }
    else
    {
        system("cls");
        puts("cadastro nao realizado");
    }
    if (veetor[usuarioConectado].numBanho == 10)
    {
        system("cls");
        puts("maximo de agendamentos feitos");
    }

    menu(veetor, usuarioConectado);
}

void consulta(struct myDados veetor[10], int usuarioConectado)
{
    system("cls");
    nomePetShop();

    char car;
    if (veetor[usuarioConectado].numPet > 0)
    {
        do
        {
            // system("cls");'

            for (int j = 1; j <= veetor[usuarioConectado].numPet; j++)
            {
                printf("digite %d | para o(a) %s \n", j, veetor[usuarioConectado].nomePet[j - 1]);
            }
            int valuePet;
            scanf("%d", &valuePet);
            getchar();
            system("cls");
            system("cls");
            if (valuePet > 0 && valuePet <= veetor[usuarioConectado].numPet)
            {

                puts("digite :");
                puts("1 | Para agendar uma consulta para a quarta");
                puts("2 | Para agendar uma consulta para o sabado");
                int valueOp;
                scanf("%d", &valueOp);
                getchar();
                system("cls");

                switch (valueOp)
                {
                case 1:
                    veetor[usuarioConectado].consulta[veetor[usuarioConectado].numConsulta][0] = valuePet;
                    veetor[usuarioConectado].consulta[veetor[usuarioConectado].numConsulta][1] = 1;
                    break;
                case 2:
                    veetor[usuarioConectado].consulta[veetor[usuarioConectado].numConsulta][0] = valuePet;
                    veetor[usuarioConectado].consulta[veetor[usuarioConectado].numConsulta][1] = 2;
                    break;
                default:
                    puts("Erro");
                    consulta(veetor, usuarioConectado);
                    break;
                }
                system("cls");

                puts("digite :");
                puts("1 | Para consultar com o Dr. Gustavo");
                puts("2 | Para consultar com o Dr. Fabiano");

                scanf("%d", &valueOp);
                getchar();
                system("cls");
                system("cls");

                switch (valueOp)
                {
                case 1:
                    veetor[usuarioConectado].consulta[veetor[usuarioConectado].numConsulta][2] = 1;
                    break;
                case 2:
                    veetor[usuarioConectado].consulta[veetor[usuarioConectado].numConsulta][2] = 2;
                    break;
                default:
                    puts("Erro");
                    consulta(veetor, usuarioConectado);
                    break;
                }
                veetor[usuarioConectado].numConsulta++;
            }
            else
            {
                system("cls");
                puts("erro");
                consulta(veetor, usuarioConectado);
            }

            system("cls");

            puts("quer fazer outro agendamento? \n[s] para sim\n[n] para nao\n");
            scanf("%c", &car);
            getchar();
            system("cls");
        } while (car == 's' && veetor[usuarioConectado].numConsulta <= 10);
    }
    else
    {
        system("cls");
        puts("cadastro nao realizado");
    }
    if (veetor[usuarioConectado].numConsulta == 10)
    {
        system("cls");
        puts("maximo de agendamentos feitos");
    }
    menu(veetor, usuarioConectado);
}

void relatorioGeral(struct myDados veetor[10], int usuarioConectado)
{
    system("cls");
    nomePetShop();
    if (veetor[usuarioConectado].numPet > 0)
    {
        printf("cliente: %s", veetor[usuarioConectado].nome);
        printf("telefone: %s \n", veetor[usuarioConectado].telefone);
        for (int j = 1; j <= veetor[usuarioConectado].numPet; j++)
        {
            printf("pet %d: %s", j, veetor[usuarioConectado].nomePet[j - 1]);
        }
        printf("\n");
        for (int j = 1; j <= veetor[usuarioConectado].numBanho; j++)
        {
            if (veetor[usuarioConectado].banhoETosa[j - 1][1] == 1)
            {
                printf("banho para o pet %s", veetor[usuarioConectado].nomePet[veetor[usuarioConectado].banhoETosa[j - 1][0] - 1]);
            }
            else if (veetor[usuarioConectado].banhoETosa[j - 1][1] == 2)
            {
                printf("tosa para o pet %s", veetor[usuarioConectado].nomePet[veetor[usuarioConectado].banhoETosa[j - 1][0] - 1]);
            }
            else if (veetor[usuarioConectado].banhoETosa[j - 1][1] == 3)
            {
                printf("banho e tosa para o pet %s", veetor[usuarioConectado].nomePet[veetor[usuarioConectado].banhoETosa[j - 1][0] - 1]);
            }
        }
        printf("\n");
        for (int j = 1; j <= veetor[usuarioConectado].numConsulta; j++)
        {
            if (veetor[usuarioConectado].consulta[j - 1][2] == 1)
            {
                diaConsulta(veetor, usuarioConectado, j, "Gustavo");
            }
            else if (veetor[usuarioConectado].consulta[j - 1][2] == 2)
            {
                diaConsulta(veetor, usuarioConectado, j, "Fabiano");
            }
        }
    }
    else
    {
        system("cls");
        puts("cadastro nao realizado");
        menu(veetor, usuarioConectado);
    }
    puts("precione qualquer tecla para voltar ao menu");
    char teste;
    scanf("%c", &teste);
    system("cls");
    menu(veetor, usuarioConectado);
}

void diaConsulta(struct myDados veetor[10], int usuarioConectado, int j, char *text)
{
    switch (veetor[usuarioConectado].consulta[j - 1][1])
    {
    case 1:
        printf(" consulta para o pet %s para a quarta com o dr. %s \n", veetor[usuarioConectado].nomePet[veetor[usuarioConectado].consulta[j - 1][0] - 1], text);
        break;
    case 2:
        printf(" consulta para o pet %s para o sabado com o dr. %s \n", veetor[usuarioConectado].nomePet[veetor[usuarioConectado].consulta[j - 1][0] - 1], text);
        break;
    default:
        puts("erro!");
        break;
    }
}