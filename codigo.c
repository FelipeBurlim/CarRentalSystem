#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct{
    int dia,mes,ano;
}data;

typedef struct{
    char cpf[15];
    char nome[20];
    char endereco[25];
    char telFixo[15];
    char telCel[15];
    data nasci;
}cliente;

typedef struct{
    char codigo[10];
    char desc[50];
    char categoria[15];
    int capacidade;
    int ano;
    char modelo[15];    
}veiculo;

typedef struct{
    char cpfCliente[15];
    char codigoVeiculo[10];
    data entrada;
    data saida;
}aluguel;

void limpaBuffer(){
    int c;
    while((c = getchar())!= '\n');
}

//relatorios

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

//aluguel

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

//veiculo

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

//clientes

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
                listarCliente(cpf);
            case 3:
                if(incluirCliente()) puts("Cliente incluído com sucesso.");
                else puts("Erro ao incluir cliente");
            case 4:
                puts("Digite o cpf do cliente desejado:");
                fgets(cpf,13,stdin);
                cpf[strcspn(cpf,"\n")]='\0';   
                listarCliente(cpf);
                puts("Digite 1 se for o cliente desejado");
                scanf("%d",&bool);
                if(bool==1) {
                    if(alterarCliente(cpf)) puts("Dados do cliente alterado");
                }
                else puts("Tente novamente");
            case 5:
                puts("Digite o cpf do cliente desejado:");
                fgets(cpf,13,stdin);
                cpf[strcspn(cpf,"\n")]='\0';   
                listarCliente(cpf);
                puts("Digite 1 se for o cliente desejado");
                scanf("%d",&bool);
                if(bool==1) {
                    if(removerCliente(cpf)) puts("Cliente removido");
                }
                else puts("Tente novamente");
            default: puts("Opção inválida.");     
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
    FILE *f = fopen("clientes.bin","rb");
    if(!f) puts("Nenhum cliente cadastrado.");
    else{
        cliente c;
        puts("Lista de Clientes: ");
        while(fread(&c,sizeof(cliente),1,f)){
            printf("\n\tCpf: %s",c.cpf);
            printf("\n\tNome: %s",c.nome);
            printf("\n\tEndereço: %s",c.endereco);
            printf("\n\tTelefone fixo: %s",c.telFixo);
            printf("\n\tTelefone celular: %s",c.telCel);
            printf("\n\tData de nascimento: %d/%d/%d",c.nasci.dia,c.nasci.mes,c.nasci.ano);
            puts("----------------------------------//-------------------------------------");
            puts("");
        }
    }
    fclose(f);
}

void listarCliente(char cpf[]){
    FILE *f = fopen("clientes.bin","rb");
    if(!f) puts("Erro ao listar cliente");
    else{
        int bool=0;
        cliente c;
        while(fread(&c,sizeof(cliente),1,f)&& !bool){
            if(strcmp(c.cpf,cpf)==0){
                printf("\n\tNome: %s",c.nome);
                printf("\n\tEndereço: %s",c.endereco);
                printf("\n\tTelefone fixo: %s",c.telFixo);
                printf("\n\tTelefone celular: %s",c.telCel);
                printf("\n\tData de nascimento: %d/%d/%d",c.nasci.dia,c.nasci.mes,c.nasci.ano);
                bool++;
            }
        }
        if(!bool) puts("Cliente não encontrado");
        fclose(f);
    }
}

int incluirCliente(){
    FILE *f = fopen("clientes.bin","ab");
    if(!f) puts("Erro ao abrir arquivo");
    else{
        cliente c;
        puts("Incluindo cliente: ");
        puts("Cpf do cliente:");
        fgets(c.cpf,15,stdin);
        c.cpf[strcspn(c.cpf,"\n")]='\0';
        if(!existeCliente(c.cpf)){
            puts("Cliente ja existente.");
            fclose(f);
            return 0;
        }
        puts("Nome: ");
        fgets(c.nome,20,stdin);
        c.nome[strcspn(c.nome,"\n")]='\0';
        puts("Endereço: ");
        fgets(c.endereco,25,stdin);
        c.endereco[strcspn(c.endereco,"\n")]='\0';
        puts("Telefone Fixo: ");
        fgets(c.telFixo,15,stdin);
        c.telFixo[strcspn(c.telFixo,"\n")]='\0';
        puts("Telefone Celular: ");
        fgets(c.telCel,15,stdin);
        c.telCel[strcspn(c.telCel,"\n")]='\0';
        puts("Data de nascimento(DD MM AAAA): ");
        scanf("%d %d %d",&c.nasci.dia,&c.nasci.mes,&c.nasci.ano);
        limpaBuffer();
        fwrite(&c,sizeof(cliente),1,f);
        fclose(f);
        return 1;
    }

}

int alterarCliente(char cpf[]){
    FILE *f = fopen("clientes.bin","rb");
    if(!f){
        puts("Erro ao abrir arquivo");
        return 0;
    }
    int qnt,ic=-1,i;
    fseek(f,0,SEEK_END);
    qnt = ftell(f)/sizeof(cliente);
    rewind(f);
    cliente *vetor = (cliente*) malloc(qnt*sizeof(cliente));
    fread(vetor,sizeof(cliente),qnt,f);
    fclose(f);
    for(i=0;i<qnt;i++){
        if(strcmp(vetor[i].cpf,cpf)==0){
            ic=i;
        }
    }
    puts("Nome: ");
    fgets(vetor[ic].nome,20,stdin);
    vetor[ic].nome[strcspn(vetor[ic].nome,"\n")]='\0';
    puts("Endereço: ");
    fgets(vetor[ic].endereco,25,stdin);
    vetor[ic].endereco[strcspn(vetor[ic].endereco,"\n")]='\0';
    puts("Telefone Fixo: ");
    fgets(vetor[ic].telFixo,15,stdin);
    vetor[ic].telFixo[strcspn(vetor[ic].telFixo,"\n")]='\0';
    puts("Telefone Celular: ");
    fgets(vetor[ic].telCel,15,stdin);
    vetor[ic].telCel[strcspn(vetor[ic].telCel,"\n")]='\0';
    puts("Data de nascimento(DD MM AAAA): ");
    scanf("%d %d %d",&vetor[ic].nasci.dia,&vetor[ic].nasci.mes,&vetor[ic].nasci.ano);
    limpaBuffer();
    f = fopen("clientes.bin","wb");
    fwrite(vetor,sizeof(cliente),qnt,f);
    fclose(f);
    free(vetor);
    return 1;
}

int removerCliente(char cpf[]){
    FILE *f = fopen("clientes.bin","rb");
    if(!f){
        puts("Erro ao abrir arquivo");
        return 0;
    }
    int tam,i,bool=0;
    fseek(f,0,SEEK_END);
    tam = ftell(f)/sizeof(cliente);
    rewind(f);
    cliente *vetor = (cliente*) malloc(tam*sizeof(cliente));
    fread(vetor,sizeof(cliente),tam,f);
    fclose(f);
    for(i=0;i<tam;i++){
        if(strcmp(vetor[i].cpf,cpf)==0) bool++;
        else fwrite(&vetor[i],sizeof(cliente),1,f);
    }
    fclose(f);
    free(vetor);
    return bool;
}

int existeCliente(char cpf[]){
    FILE *f = fopen("clientes.bin","rb");
    if(!f){
        puts("Erro ao abrir arquivo.");
        return 0;
    }
    cliente c;
    while(fread(&c,sizeof(cliente),1,f)){
        if(strcmp(c.cpf,cpf)==0) {
            fclose(f);
            return 1;
        }
    }
    fclose(f);
    return 0;
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