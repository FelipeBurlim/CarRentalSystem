#include<stdio.h>
#include<string.h>

struct clientes{
    char cpf[13];
    char nome[20];
    char endereco[25];
    int telFixo;
    int telCel;
    char nasc[10];
};

struct veiculos{
    char codigo[10];
    char desc[50];
    char categoria[15];
    int capacidade;
    int ano;
    char modelo[15];    
};

struct alugueis{
    char cpfCliente[13];
    char codigoVeiculo[10];
    char dataEnt[10];
    char dataSai[10];
};

void relatorios(){
    int op;
    do{
        op = submenuRelatorios();;
        switch(op){
            case 1:
            case 2:
            case 3:
        }
    } while(op>=1 && op<=3);
}

int submenuRelatorios(){
    int op;
    puts("Submenu Relatórios: ");
    puts("");
    puts("");
    puts("");
    puts("Digite a opção desejada: ");
    scanf("%d",&op);
    return op;
}

void alugueis(){
    int op;
    do{
        op = submenuAlugueis();;
        switch(op){
            case 1:
            case 2:
            case 3:
            case 4:
            case 5:
        }
    } while(op>=1 && op<=5);
}

int submenuAlugueis(){
    int op;
    puts("Submenu Alugueis: ");
    puts("1. Dados de todos os alugueis");
    puts("2. Dados de um aluguel");
    puts("3. Incluir aluguel");
    puts("4. Alterar dados de um aluguel");
    puts("5. Remover aluguel");
    puts("Digite a opção desejada: ");
    scanf("%d",&op);
    return op;
}

void listarTodosAlugueis(){

}

void listarAluguel(){

}

int incluirAluguel(){

}

int alterarAluguel(){

}

int removerAluguel(){
    
}

void veiculos(){
    int op;
    do{
        op = submenuVeiculos();;
        switch(op){
            case 1:
            case 2:
            case 3:
            case 4:
            case 5:
        }
    } while(op>=1 && op<=5);
}

int submenuVeiculos(){
    int op;
    puts("Submenu Veículos: ");
    puts("1. Dados de todos os veículos");
    puts("2. Dados de um veículo");
    puts("3. Incluir veículo");
    puts("4. Alterar dados de um veículo");
    puts("5. Remover veículo");
    puts("Digite a opção desejada: ");
    scanf("%d",&op);
    return op;
}

void listarTodosVeiculos(){

}

void listarVeiculo(){

}

int incluirVeiculo(){

}

int alterarVeiculo(){

}

int removerVeiculo(){
    
}

void clientes(){
    int op,bool;    
    char cpf[13];
    do{
        op = submenuClientes();;
        switch(op){
            case 1:
                listarTodosCliente();
            case 2:
                puts("Digite o cpf do cliente desejado:");
                fgets(cpf,13,stdin);
                cpf[strcspn(cpf,"\n")]='\0';                
                listarCliente();
            case 3:
                incluirCliente();
            case 4:
                puts("Digite o cpf do cliente desejado:");
                fgets(cpf,13,stdin);
                cpf[strcspn(cpf,"\n")]='\0';   
                listarCliente();
                puts("Digite 1 se for o cliente desejado ou 0 se não for");
                scanf("%d",&bool);
                if(bool==1) alterarCliente();
                else if(bool==0) puts("Desculpe, tente novamente.");
                else puts("Opção inválida");
            case 5:
                puts("Digite o cpf do cliente desejado:");
                fgets(cpf,13,stdin);
                cpf[strcspn(cpf,"\n")]='\0';   
                listarCliente();
                puts("Digite 1 se for o cliente desejado ou 0 se não for");
                scanf("%d",&bool);
                if(bool==1) removerCliente();
                else if(bool==0) puts("Desculpe, tente novamente.");
                else puts("Opção inválida");
        }
    } while(op>=1 && op<=5);
}

int submenuClientes(){
    int op;
    puts("Submenu Clientes: ");
    puts("1. Dados de todos os clientes");
    puts("2. Dados de um cliente");
    puts("3. Incluir cliente");
    puts("4. Alterar dados de um cliente");
    puts("5. Remover cliente");
    puts("Digite a opção desejada: ");
    scanf("%d",&op);
    return op;
}

void listarTodosCliente(){

}

void listarCliente(){

}

int incluirCliente(){

}

int alterarCliente(){

}

int removerCliente(){

}

int menu(){
    int opc;
    puts("Menu Principal: ");
    puts("1. Submenu de Clientes");
    puts("2. Submenu de Veículos");
    puts("3. Submenu de Alugueis");
    puts("4. Submenu Relatórios");
    puts("5. Sair");
    puts("Insira a opção desejada: ");
    scanf("%d",&opc);
    return opc;
}

int main(){
    int opc;
    do{
        opc = menu();
        switch(opc){
            case 1:
                clientes();
            case 2:
                veiculos();
            case 3:
                alugueis();
            case 4:
                relatorios();
            case 5:
            puts("Salvando e saindo do programa...");
        }
    } while(opc>=1 && opc<5);
}