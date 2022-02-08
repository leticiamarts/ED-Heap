#include <stdio.h>
#include <stdlib.h>

void subir(int *heap, int i){
    int j = i/2, temp;
    if(j >= 1){
        if(heap[i] > heap[j]){
            temp = heap[i];
            heap[i] = heap[j];
            heap[j] = temp;
            subir(heap, j);
        }
    }
}

void inserir(int *heap, int atual, int tamanhoheap){
    int elemento;
    printf("Insira o elemento a ser inserido:\n");
    scanf("%d", &elemento);
    if(atual < tamanhoheap){
        heap[atual+1] = elemento;
        atual = atual+1;
        subir(heap, atual);
    }
    else{
        printf("Não foi possível inserir um novo elemento!\n");
    }
}


void descer(int *heap, int i, int atual){
    int j = 2 * i, temp;
    if(j <= atual){
        if(j < atual){
            if(heap[j+1] > heap[j]){
                j++;
            }
        }
        if(heap[j] > heap[i]){
            temp = heap[i];
            heap[i] = heap[j];
            heap[j] = temp;
            descer(heap, j, atual);
        }
    }
}

void remover(int *heap, int atual){
    if(atual >= 0){
        if(atual != 0){
        heap[1] = heap[atual];
        atual = atual-1;
        if(atual <= 0){
            atual = 0;
        }
        descer(heap, 1, atual);
    }
        else{
            printf("Vazio!\n");
        }
    }
}

void arranjar(int *heap, int atual){
    for(int i = atual/2; i >= 1; i--){
        descer(heap, i, atual);
    }
}

void imprimir(int *heap, int atual){
    int i;
    if(atual == 0){
        printf("Não há elementos inseridos!\n");
    }
    else{
        printf("Heap: ");
        for(i = 1; i<=atual; i++){
            if(i == 1){
                printf("{");
            }
            if(i != atual){
                printf("%d,", heap[i]);
            }
            else{
            printf("%d}\n", heap[i]); 
            }
        }
    }
}

void menu(int *acao){
    printf("Escolha a ação\n");
    printf("1 - Inserir novo elemento.\n");
    printf("2 - Remover elemento.\n");
    printf("3 - Imprimir Heap.\n");
    printf("4 - Arranjar heap - Transformá-lo em HEAP.\n");
    printf("0 - Sair.\n");
    scanf("%d", acao);
}

int main(){
    int *heap; 
    int n, i, acao = -1, atual = 0, operacao = -1;

    printf("Digite a quantidade máxima de valores a serem inseridos:\n");
    scanf("%d", &n);

    heap = (int*)malloc((n+1) * sizeof(int));
    
    printf("Caso desejes incluir um heap já pronto, digite 0.\n");
    printf("Caso desejes incluir os valores a cada etapa, digite 1.\n");
    scanf("%d", &operacao);

    if(operacao == 0){
        printf("Insira a quantidades de elementos a serem inseridos agora\n");
        scanf("%d", &atual);
        for(int j = 1; j <= atual; j++){
            printf("Insira o valor de índice %d:\n", j);
            scanf("%d", &heap[j]);
        }
        printf("É RECOMENDÁVEL CHAMAR LOGO EM SEGUIDA A FUNÇÃO ARRANJAR(4), PARA EFETIVAMENTE TRANSFORMAR A LISTA EM HEAP\n");
    }

    while(acao != 0){
        menu(&acao);
        switch(acao){
            case 1:
                inserir(heap, atual, n);
                arranjar(heap, atual);
                if(atual < n){
                    atual++;
                }
                break;

            case 2:
                printf("Elemento de maior prioridade será removido\n");
                remover(heap, atual);
                atual--;
                if(atual <= 0){
                    atual = 0;
                }
                break;

            case 3:
                imprimir(heap, atual);
                break;
            
            case 4:
                arranjar(heap, atual);
                break;

        }
    }
    return 0;
}