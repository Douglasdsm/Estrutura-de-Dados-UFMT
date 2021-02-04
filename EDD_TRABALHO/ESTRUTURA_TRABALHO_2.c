#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct Tipo_Dados
{
    int codigoPaciente;
    char nome[150];
    char data[10];
    char sexo[10];
    char queixaPrincipal[240];
    char historiaBreve[240];
    int registro;
    char hora[10];
    int idade;
    char observacaoObjetiva[240];
    char Dado_PA[5];
    float Dado_T;
    int Dado_FR;
    int Dado_Pulso;
    int Dado_Dor;
} DadosPaciente;
typedef struct Classificao_Risco
{
    int codigoPaciente;
    char classificao_Risco[8];
    char drogas[240];
    char alergia[240];
    char doencaPreexistentes[240];
    char condutaInicial[240];
    char horaReavaliacao[10];
    char reavaliacao[10];
    char nomeEmfermeiro[140];
} Classificao;
typedef struct Tipo_Leito
{
    DadosPaciente Dados;
    int leito;
    int prioridade;

} Leito;
typedef struct Cadastro_Medico
{
    int codigo_Medico;
    char nome[140];
    char CRM[15];
    char especialidade[55];
    struct Cadastro_Medico *proximo;
} Medico;
typedef struct Cadastro_Enfermeiro
{
    int codigo_Enfermeiro;
    char nome[140];
    char COREN[15];
    char especialidade[35];
    struct Cadastro_Enfermeiro *proximo;

} Enfermeiro;

typedef struct Tipo_Leitos
{
    DadosPaciente FichaPaciente;
    Medico MedicoResponsavel;
    int Leito;
    struct Tipo_Leito *proximo;

} Leitos;
typedef struct Tipo_triagem
{
    DadosPaciente Cadastro;
    Classificao ESTADOPACIENTE;

    int codigoPaciente;
    char DataEntrada[10];
    char HoraEntrada[10];
    int CodigoEmfermeiro;
    int prioridade;
} triagem;
typedef struct Tipo_No
{
    triagem Cadastro;
    struct Tipo_No *proximo;
    struct Tipo_No *anterior;
} No;
typedef struct No_funcionario
{
    Medico CadastroMedico;
    Enfermeiro CadastroEnfer;
} No_Fun;
typedef struct Lista_funcionario
{
    No_Fun *primeiro;
    No_Fun *fim;
    int tamanho;

} ListaFuncionario;
typedef struct ListaTriagem
{
    No *primeiro;
    No *fim;
    int tamanho;
} ListaTriagem;
void inicializarFuncionario(ListaFuncionario **funcionario)
{
    ListaFuncionario *AUX =(ListaFuncionario *)malloc(sizeof(ListaFuncionario));
    AUX->primeiro = NULL;
    AUX->fim =NULL;
    AUX->tamanho = 1;
    *funcionario = AUX;
}
void inicializar(ListaTriagem **Triagems)
{
    //printf("\n TRIAGEM INICIALIZADA COM SUCESSO\n");
    ListaTriagem *AUX = (ListaTriagem *)malloc(sizeof(ListaTriagem));
    AUX->primeiro = NULL;
    AUX->fim = NULL;
    AUX->tamanho = 0;
    *Triagems = AUX;
}
void CadastroDados(ListaTriagem **Triagems,int prioridade, ListaFuncionario *funcionarios)
{
    printf("\nESTOU  AQUI\n");
    No *aux = (No *)malloc(sizeof(No));
    if(aux != NULL)
    {
        fflush(stdin);
        printf("\n CODIGO: %d\n ",(*Triagems)->tamanho);
        aux->Cadastro.Cadastro.codigoPaciente = (*Triagems)->tamanho;
        fflush(stdin);
        printf("Digite o nome do Paciente\n");
        scanf("%[^\n]s",aux->Cadastro.Cadastro.nome);
        fflush(stdin);
        printf("Digite a Data no formato DIA/MES/ANO\n");
        scanf("%[^\n]s",aux->Cadastro.Cadastro.data);
        /* fflush(stdin);
         printf("Digite o Sexo FEMININO/MASCULINO \n");
         scanf("%[^\n]s",aux->Cadastro.Cadastro.sexo);
         fflush(stdin);
         printf("Digite a queixa principal do paciente no maximo 240 caracteries\n");
         scanf("%[^\n]s",aux->Cadastro.Cadastro.queixaPrincipal);
         fflush(stdin);
         printf("Digite a Historia Breve no Maximo 240 caracteries\n");
         scanf("%[^\n]s",aux->Cadastro.Cadastro.historiaBreve);
         fflush(stdin);
         aux->Cadastro.Cadastro.registro = (*Triagems)->tamanho;
         printf("Registro do Paciente %d \n",aux->Cadastro.Cadastro.registro);
         fflush(stdin);
         printf("Digite a HORA FORMATO Hora:Minutos:Segundos\n");
         scanf("%[^\n]s",aux->Cadastro.Cadastro.hora);
         fflush(stdin);
         printf("Digite a Idade\n");
         scanf("%d",&aux->Cadastro.Cadastro.idade);
         fflush(stdin);
         printf("Digite as Observacoes objetivas \n");
         scanf("%[^\n]s",aux->Cadastro.Cadastro.observacaoObjetiva);
         fflush(stdin);
         printf("Digite os DADOS da PA\n");
         scanf("%[^\n]s",aux->Cadastro.Cadastro.Dado_PA);
         fflush(stdin);
         printf("Digite os Dados da Temperatura\n");
         scanf("%f",&aux->Cadastro.Cadastro.Dado_T);
         fflush(stdin);
         printf("Digite os Dados FR\n");
         scanf("%d",&aux->Cadastro.Cadastro.Dado_FR);
         fflush(stdin);
         printf("Digite os Dados do Pulso\n");
         scanf("%d",&aux->Cadastro.Cadastro.Dado_Pulso);
         fflush(stdin);
         printf("Digite a intensidade da 0 a 10  Dor\n");
         scanf("%d",&aux->Cadastro.Cadastro.Dado_Dor);
         printf("\n DADO DOR : %d \n",aux->Cadastro.Cadastro.Dado_Dor);
         int dor = aux->Cadastro.Cadastro.Dado_Dor;
         if(1 <= dor && dor <= 3)

         {
             printf("\n Dor Leve \n");

         }
         if(3 < dor && dor <= 7)
         {
             printf("\n Dor moderada\n");
         }
         if(7< dor && dor <= 10)
         {
             printf("\n Dor Intensa\n");
         }
         printf("\nCADASTRO CONCLUIDO COM EXITO \n");
         system("pause");
         printf("CODIGO PACIENTE: %d \n",aux->Cadastro.Cadastro.codigoPaciente);
         printf("NOME: %s\n",aux->Cadastro.Cadastro.nome);
         printf("CODIGO: %d\n",(*Triagems)->tamanho);
         printf("DATA: %s\n",aux->Cadastro.Cadastro.data);
         printf("SEXO: %s\n",aux->Cadastro.Cadastro.sexo);
         printf("Queixa principal: %s\n",aux->Cadastro.Cadastro.queixaPrincipal);
         printf("HISTORIA BREVE: %s\n",aux->Cadastro.Cadastro.historiaBreve);
         printf("REGISTRO DO PACIENTE %d \n",aux->Cadastro.Cadastro.registro);
         printf("HORA\n",aux->Cadastro.Cadastro.hora);
         printf("IDADE: %d\n",aux->Cadastro.Cadastro.idade);
         printf("OBSERVACOES OBJETIVA: %s \n",aux->Cadastro.Cadastro.observacaoObjetiva);
         printf("DADOS PA: %s\n",aux->Cadastro.Cadastro.Dado_PA);
         printf("TEMPERATURA: %.2f\n",aux->Cadastro.Cadastro.Dado_T);
         printf("DADOS FR\n",aux->Cadastro.Cadastro.Dado_FR);
         printf("DADOS PULSO: %d\n",aux->Cadastro.Cadastro.Dado_Pulso);
         printf("INTENSIDADE DE DOR: %d\n",aux->Cadastro.Cadastro.Dado_Dor);*/

        if(prioridade != 0)
        {
            printf("\nCLASSIFICACAO DE RISCO\n");
            /*printf("\nDiga qual a classificao de risco Vermelha, Amarela, Verde e Azul\n");
            fflush(stdin);
            scanf("%[^\n]s",aux->Cadastro.ESTADOPACIENTE.classificao_Risco);
            printf("Drogas Utilizadas\n");
            scanf("%[^\n]s",aux->Cadastro.ESTADOPACIENTE.drogas);
            fflush(stdin);
            printf("Alergia:\n");
            scanf("%[^\n]s",aux->Cadastro.ESTADOPACIENTE.alergia);
            fflush(stdin);
            printf("Doenca Pre-Existentes\n");
            scanf("%[^\n]s",aux->Cadastro.ESTADOPACIENTE.doencaPreexistentes);
            fflush(stdin);
            printf("Conduta Inicial:\n");
            scanf("%[^\n]s",aux->Cadastro.ESTADOPACIENTE.condutaInicial);
            printf("Hora de Reavaliacao: FPRMATO Hora:Minutos:Segundos\n");
            scanf("%[^\n]s",aux->Cadastro.ESTADOPACIENTE.reavaliacao);
            */
            printf("Digite o Codigo do enfermeiro:\n");
            int codEnfermeiro;
            scanf("%d",&codEnfermeiro);
            No_Fun *Busca2 = funcionarios->primeiro;
            while(Busca2 != NULL)
            {
                if(codEnfermeiro == Busca2->CadastroEnfer.codigo_Enfermeiro)
                {
                    strcpy(aux->Cadastro.ESTADOPACIENTE.nomeEmfermeiro,Busca2->CadastroEnfer.nome);
                    codEnfermeiro = 1000;
                    printf("\n ENFERMEIRO ENCONTRADO \n");
                    printf("\nNOME: %s\n",aux->Cadastro.ESTADOPACIENTE.nomeEmfermeiro);
                }
                Busca2 = Busca2->CadastroEnfer.proximo;
            }
            if(codEnfermeiro !=1000)
            {
                printf("\n ENFERMEIRO NAO ENCONTRADO \n");
            }


        }
        aux->anterior = NULL;
        aux->proximo = NULL;
        if(aux->anterior == NULL)
        {
            printf("\nAUX ANTERIOR E NULL\n");
        }
        if(aux->proximo == NULL)
        {
            printf("\nAUX PROXIMO E NULL\n");
        }
        printf("\n PASSEI AQUI 1\n");
        if((*Triagems)->tamanho == 0)
        {printf("\n PASSEI AQUI 2\n");
            (*Triagems)->fim = aux;
            (*Triagems)->primeiro= aux;
            (*Triagems)->fim->proximo = NULL;
            (*Triagems)->fim->anterior = NULL;

        }
        else
        { printf("\n PASSEI AQUI 3\n");
            (*Triagems)->fim->anterior = (*Triagems)->fim;
            (*Triagems)->fim->proximo = aux;
            (*Triagems)->fim = aux;
            /*
            /*No *Busca = (*Triagems)->primeiro;
            printf("\n PASSEI AQUI 4\n");
            int cont = 0;
            while(Busca != NULL)
            { printf("\n %d",cont);
                if(Busca->proximo == NULL)
                {
                    (*Triagems)->fim->anterior = Busca;
                    Busca == NULL;
                }
                cont+=1;


            }*/


        }
        (*Triagems)->tamanho+=1;


    }
    else
    {
        printf("\n Memoria nao alocada \n");
    }
}

void CadastroEnfermeiro(ListaFuncionario **ListaFun)
{
    No_Fun *AUX =(No_Fun *)malloc(sizeof(No_Fun));
    if(AUX !=NULL)
    {
        AUX->CadastroEnfer.codigo_Enfermeiro = (*ListaFun)->tamanho;
        printf("DIGITE O NOME DO ENFERMEIRO:\n");
        fflush(stdin);
        scanf("%[^\n]s",AUX->CadastroEnfer.nome);
        fflush(stdin);
        printf("DIGITE O COREN DO ENFERMEIRO:\n");
        scanf("%[^\n]s",AUX->CadastroEnfer.COREN);
        printf("ESPECIALIDADE:\n");
        fflush(stdin);
        scanf("%[^\n]s",AUX->CadastroEnfer.especialidade);
        if((*ListaFun)->tamanho == 1)
        {
            AUX->CadastroEnfer.proximo = NULL;
            (*ListaFun)->primeiro = AUX;
            (*ListaFun)->fim = AUX;
            (*ListaFun)->tamanho +=1;
        }
        else
        {
            (*ListaFun)->fim->CadastroEnfer.proximo = AUX;
            (*ListaFun)->fim = AUX;
            (*ListaFun)->tamanho +=1;

        }
        printf("\n CADASTRO CONCLUIDO COM SUCESSO\n");
        system("pause");
        system("cls");
    }
    else
    {
        printf("\n MEMORIA NAO ALOCADA!!!\n");
        system("pause");
        system("cls");

    }
    printf("\nDADOS ENFERMEIRO\n");
    printf("CODIGO EMFERMEIRO: %d\n",AUX->CadastroEnfer.codigo_Enfermeiro);
    printf("ENFERMEIRO:%s\n",AUX->CadastroEnfer.nome);
    printf("COREN:%s\n",AUX->CadastroEnfer.COREN);
    printf("ESPECIALIDADE:%s\n",AUX->CadastroEnfer.especialidade);


}
void CadastroMedico(ListaFuncionario **ListaFun)
{
    No_Fun *AUX =(No_Fun *)malloc(sizeof(No_Fun));
    if(AUX !=NULL)
    {
        AUX->CadastroMedico.codigo_Medico = (*ListaFun)->tamanho;
        printf("DIGITE O NOME DO MEDICO:\n");
        fflush(stdin);
        scanf("%[^\n]s",AUX->CadastroMedico.nome);
        fflush(stdin);
        printf("DIGITE O CRM DO MEDICO:\n");
        scanf("%[^\n]s",AUX->CadastroMedico.CRM);
        printf("ESPECIALIDADE DO MEDICO:\n");
        fflush(stdin);
        scanf("%[^\n]s",AUX->CadastroMedico.especialidade);
        if((*ListaFun)->tamanho == 1)
        {
            AUX->CadastroMedico.proximo = NULL;
            (*ListaFun)->primeiro = AUX;
            (*ListaFun)->fim = AUX;
            (*ListaFun)->tamanho +=1;
        }
        else
        {
            (*ListaFun)->fim->CadastroMedico.proximo = AUX;
            (*ListaFun)->fim = AUX;
            (*ListaFun)->tamanho +=1;

        }
        system("cls");
        printf("\nCADASTRO CONCLUIDO COM SUCESSO\n");

    }
    else
    {
        printf("\n MEMORIA NAO ALOCADA!!!\n");
        system("pause");
        system("cls");

    }
    printf("\nDADOS DO MEDICO CADASTRADO\n");
    printf("CODIGO MEDICO: %d\n",AUX->CadastroMedico.codigo_Medico);
    printf("NOME DO MEDICO:%s\n",AUX->CadastroMedico.nome);
    printf("CRM:%s\n",AUX->CadastroMedico.CRM);
    printf("ESPECIALIDADE DO MEDICO:%s\n",AUX->CadastroMedico.especialidade);
    system("pause");
    system("cls");

}
void mostrarMedico(ListaFuncionario *funcionario)
{


    if(funcionario->tamanho !=1)
    {
        No_Fun *mostrar = funcionario->primeiro;
        while(mostrar != NULL)
        {
            printf("\nDADOS DO MEDICO CADASTRADO\n");
            printf("CODIGO MEDICO: %d\n",mostrar->CadastroMedico.codigo_Medico);
            printf("NOME DO MEDICO:%s\n",mostrar->CadastroMedico.nome);
            printf("CRM:%s\n",mostrar->CadastroMedico.CRM);
            printf("ESPECIALIDADE DO MEDICO:%s\n",mostrar->CadastroMedico.especialidade);
            mostrar = mostrar->CadastroMedico.proximo;
        }
    }
    else
    {
        printf("\n NAO HA FUNCIONARIOS CADASTRADOS \n");
    }
}
void mostrarEnfermeiro(ListaFuncionario *funcionario)
{


    if(funcionario->tamanho !=1)
    {
        No_Fun *mostrar = funcionario->primeiro;
        while(mostrar != NULL)
        {

            printf("\nDADOS ENFERMEIRO\n");
            printf("ENFERMEIRO:%s\n",mostrar->CadastroEnfer.nome);
            printf("CODIGO EMFERMEIRO: %d\n",mostrar->CadastroEnfer.codigo_Enfermeiro);
            printf("COREN:%s\n",mostrar->CadastroEnfer.COREN);
            printf("ESPECIALIDADE:%s\n",mostrar->CadastroEnfer.especialidade);
            mostrar = mostrar->CadastroMedico.proximo;
        }
    }
    else
    {
        printf("\n NAO HA FUNCIONARIOS CADASTRADOS \n");
    }
    system("pause");
    system("cls");
}
void mostrarTriagem(ListaTriagem *Triagem)
{


    if(Triagem->tamanho !=0)
    {
        No *aux = Triagem->primeiro;
        while(aux != NULL)
        {

        printf("\nCADASTRO CONCLUIDO COM EXITO \n");
        //system("pause");
        printf("CODIGO PACIENTE: %d \n",aux->Cadastro.Cadastro.codigoPaciente);
        printf("NOME: %s\n",aux->Cadastro.Cadastro.nome);
        printf("CODIGO: %d\n",aux->Cadastro.Cadastro.codigoPaciente);
        printf("DATA: %s\n",aux->Cadastro.Cadastro.data);
        printf("SEXO: %s\n",aux->Cadastro.Cadastro.sexo);
        printf("Queixa principal: %s\n",aux->Cadastro.Cadastro.queixaPrincipal);
        printf("HISTORIA BREVE: %s\n",aux->Cadastro.Cadastro.historiaBreve);
        printf("REGISTRO DO PACIENTE %d \n",aux->Cadastro.Cadastro.registro);
        printf("HORA\n",aux->Cadastro.Cadastro.hora);
        printf("IDADE: %d\n",aux->Cadastro.Cadastro.idade);
        printf("OBSERVACOES OBJETIVA: %s \n",aux->Cadastro.Cadastro.observacaoObjetiva);
        printf("DADOS PA: %s\n",aux->Cadastro.Cadastro.Dado_PA);
        printf("TEMPERATURA: %.2f\n",aux->Cadastro.Cadastro.Dado_T);
        printf("DADOS FR\n",aux->Cadastro.Cadastro.Dado_FR);
        printf("DADOS PULSO: %d\n",aux->Cadastro.Cadastro.Dado_Pulso);
        printf("INTENSIDADE DE DOR: %d\n",aux->Cadastro.Cadastro.Dado_Dor);
        aux = aux->proximo;
        }
    }
    else
    {
        printf("\n NAO HA FUNCIONARIOS CADASTRADOS \n");
    }
    system("pause");
    system("cls");
}
int main()
{
    int codPaciente = 0;
    ListaTriagem *Triagems;
    ListaFuncionario *funcionarios;
    Leitos Leitos[20];
    inicializar(&Triagems);
    inicializarFuncionario(&funcionarios);
    int prioridade;
    do
    {
        printf("\n DIGITE A PRIORIDADE DO PACIENTE \n");
//printf("0 - PRIORIDADE ZERO(VERMELHA) encaminhar diretamente  \n    para sala de ressuscitacao a avisar a equipe medica, acionamento de \n   sinal sonoro. nao perder tempo com classificacao. Atendimento em \n    15 minutos em morte eminente(Exemplo: Parada cardiorrespiratoria\n   infarto, politrauma, choque hipovolemico,etc \n");
        printf("\n 00 - PRIORIDADE ZERO(VERMELHA)");
        printf("\n 01 - PRIORIDADE UM(AMARELA)");
        printf("\n 02 - PRIORIDADE DOIS(VERDE)");
        printf("\n 03 - MENU PARA ADMINISTRACAO ");
        printf("\n 04 - PARA SAIR \n");
        printf(" OPCAO: ");
        scanf("%d",&prioridade);
        switch(prioridade)
        {
        case 0:
            system("cls");
            printf("\n ALTERNATIVA ESCOLHIDA FOI 0 \n");
            CadastroDados(&Triagems,prioridade,funcionarios);
            system("pause");
            break;
        case 1:
            system("cls");
            printf("\n ALTERNATIVA ESCOLHIDA FOI 1 \n");
            CadastroDados(&Triagems,prioridade,funcionarios);


            system("pause");
            break;
        case 2:
            system("cls");
            printf("\n ALTERNATIVA ESCOLHIDA FOI 2 \n");
            system("pause");
            break;
        case 3:
            printf("\n ALTERNATIVA ESCOLHIDA FOI 3 \n");
            system("cls");
            printf("01 - PARA CADASTRAR ENFERMEIRO:\n");
            printf("02 - PARA CADASTRAR MEDICO\n");
            printf("03 - PARA VER PACIENTES NA TRIAGEM\n");
            printf("04 - REMOVER PACIENTE DO LEITO\n");
            printf("05 - REMOVER PACIENTE DA TRIAGEM\n");
            printf("06 - REMOVER ENFERMEIRO\n");
            printf("07 - REMOVER MEDICO\n");
            printf("08 - VOLTAR AO MENU ANTERIOR\n");
            printf("09 - IMPRIMIR MEDICOS CADASTRADOS\n");
            printf("10 - IMPRIMIR ENFERMEIROS CADASTRADO\n");
            scanf("%d",&prioridade);
            switch(prioridade)
            {
            case 1:
                system("cls");
                printf("\nCADASTRAR ENFERMEIRO:\n");

                CadastroEnfermeiro(&funcionarios);
                break;
            case 2:
                printf("\nCADASTRAR MEDICO \n");
                CadastroMedico(&funcionarios);
                break;
            case 3:
                mostrarTriagem(Triagems);
                break;
            case 5:
                break;
            case 6:
                break;
            case 7:
                break;
            case 8:
                break;
            case 9:
                printf("\nESTOUA AQUI\n");
                mostrarMedico(funcionarios);
                break;
            case 10:
                mostrarEnfermeiro(funcionarios);
                break;


            }

            break;
        case 4:
            system("cls");
            printf("\n ALTERNATIVA ESCOLHIDA FOI 4 \n");
            system("pause");
            if(prioridade == 4)
            {
                prioridade = 10000;
            }
            break;
        default:
            system("cls");
            printf("\n ALTERNATIVA INVALIDA \n");
            break;
        }


    }
    while(prioridade != 10000);
}
