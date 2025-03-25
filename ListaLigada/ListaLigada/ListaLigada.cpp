#include <iostream>
using namespace std;

struct NO {
    int valor;
    NO* prox;
};

NO* primeiro = NULL;

void menu();
void inicializar();
void exibirQuantidadeElementos();
void exibirElementos();
void inserirElemento();
void excluirElemento();
void buscarElemento();
NO* posicaoElemento(int numero);

int main() {
    menu();
}

void menu() {
    int op = 0;
    while (op != 7) {
        system("cls");
        cout << "Menu Lista Ligada" << endl << endl;
        cout << "1 - Inicializar Lista \n";
        cout << "2 - Exibir quantidade de elementos \n";
        cout << "3 - Exibir elementos \n";
        cout << "4 - Buscar elemento \n";
        cout << "5 - Inserir elemento \n";
        cout << "6 - Excluir elemento \n";
        cout << "7 - Sair \n\n";

        cout << "Opcao: ";
        cin >> op;

        switch (op) {
        case 1: inicializar(); break;
        case 2: exibirQuantidadeElementos(); break;
        case 3: exibirElementos(); break;
        case 4: buscarElemento(); break;
        case 5: inserirElemento(); break;
        case 6: excluirElemento(); break;
        case 7: return;
        default: break;
        }
        system("pause");
    }
}

void inicializar() {
    NO* aux = primeiro;
    while (aux != NULL) {
        NO* paraExcluir = aux;
        aux = aux->prox;
        free(paraExcluir);
    }
    primeiro = NULL;
    cout << "Lista inicializada \n";
}

void exibirQuantidadeElementos() {
    int nElementos = 0;
    NO* aux = primeiro;
    while (aux != NULL) {
        nElementos++;
        aux = aux->prox;
    }
    cout << "Quantidade de elementos: " << nElementos << endl;
}

void exibirElementos() {
    if (primeiro == NULL) {
        cout << "Lista vazia \n";
        return;
    }
    cout << "Elementos: \n";
    NO* aux = primeiro;
    while (aux != NULL) {
        cout << aux->valor << endl;
        aux = aux->prox;
    }
}

void inserirElemento() {
    int valor;
    cout << "Digite o elemento: ";
    cin >> valor;

    if (posicaoElemento(valor) != NULL) {
        cout << "ELEMENTO JA EXISTE" << endl;
        return;
    }

    NO* novo = (NO*)malloc(sizeof(NO));
    if (novo == NULL) return;

    novo->valor = valor;
    novo->prox = NULL;

    if (primeiro == NULL) {
        primeiro = novo;
    }
    else {
        NO* aux = primeiro;
        while (aux->prox != NULL) {
            aux = aux->prox;
        }
        aux->prox = novo;
    }
}

void excluirElemento() {
    int valor;
    cout << "Digite um numero para excluir: ";
    cin >> valor;

    NO* atual = primeiro;
    NO* anterior = NULL;

    while (atual != NULL && atual->valor != valor) {
        anterior = atual;
        atual = atual->prox;
    }

    if (atual == NULL) {
        cout << "ELEMENTO NAO ENCONTRADO" << endl;
        return;
    }

    if (anterior == NULL) {
        primeiro = atual->prox;
    }
    else {
        anterior->prox = atual->prox;
    }

    free(atual);
    cout << "ELEMENTO EXCLUIDO" << endl;
}

void buscarElemento() {
    int valor;
    cout << "Digite um numero para buscar: ";
    cin >> valor;

    if (posicaoElemento(valor) != NULL) {
        cout << "ENCONTRADO" << endl;
    }
    else {
        cout << "ELEMENTO NAO ENCONTRADO" << endl;
    }
}

NO* posicaoElemento(int numero) {
    NO* aux = primeiro;
    while (aux != NULL) {
        if (aux->valor == numero) {
            return aux;
        }
        aux = aux->prox;
    }
    return NULL;
}
