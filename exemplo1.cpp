#include<iostream>
#include<vector>

using namespace std;

void adicionarAresta(int**matriz,int origem,int destino,int n){
    if(origem>=n||destino>=n){
        printf("\nOperacao invalida");
        return;
    }
    else
        matriz[origem][destino]=1;
}

void RemoverAresta(int**matriz,int origem,int destino,int n){
    if(origem>=n||destino>=n){
        printf("\nOperacao invalida");
        return;
    }
    else
        matriz[origem][destino]=0;
}

int** inicializaMatriz(int n){
    int**matriz=(int**)malloc(sizeof(int*)*n);
    for(int i=0;i<n;i++){
        matriz[i]=(int*) malloc(sizeof(int)*n);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            matriz[i][j]=0;
        }
    }
    return matriz;
}

vector<int> *getAdj(int**matriz,int n,int k){
    if(k>=n) return NULL;
    vector<int> *meuVetor = new vector<int>;
    for(int i=0;i<n;i++){
        if(matriz[k][i]==1){
            meuVetor->push_back(i);
        }
    }
    return meuVetor;
}

void printaVector(vector<int>*vetor){
    printf("Elementos do Vetor:");
    for(int i=0;i<vetor->size();i++){
        printf("%d,",vetor->at(i));
    }
}

void mostraArestas(int**matriz,int n){
    for(int i=0;i<n;i++){
        printf("\nElemento %d:",i);
        for(int j=0;j<n;j++){
            if(matriz[i][j]==1){
                printf("%d,",j);
            }
        }        
    }
    printf("\n");
}

int main(){
    vector<int>*v1;
    int n,opcao=1, origem,destino,elemento;
    printf("Tamanho?");
    scanf("%d",&n);
    int**matriz=inicializaMatriz(n); 
    while(opcao!=0){
        printf("\nO que quer fazer?");
        printf("\n0-Sair");
        printf("\n1-Adicionar aresta");
        printf("\n2-Mostrar arestas existentes");
        printf("\n3-Limpar a tela");
        printf("\n4-Remover Aresta");
        printf("\n5-Mostrar adjacencias");
        printf("\nSua opcao:");
        scanf("%d",&opcao);
        switch(opcao){
            case 1:
                printf("\nAresta de origem:");
                scanf("%d",&origem);
                printf("\nAresta de destino:");
                scanf("%d",&destino);
                adicionarAresta(matriz,origem,destino,n);
                break;
            case 2:
                mostraArestas(matriz,n);
                break;
            case 3:
                system("clear");
                break;
            case 0:
                break;
            case 4:
                printf("\nAresta de origem:");
                scanf("%d",&origem);
                printf("\nAresta de destino:");
                scanf("%d",&destino);
                RemoverAresta(matriz,origem,destino,n);
                break;
            case 5:
                printf("Elemento:");
                scanf("%d",&elemento);
                v1=getAdj(matriz,n,elemento);
                printaVector(v1);
                break;    
            default:
                break;
        }
    }
}