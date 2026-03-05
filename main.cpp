#include <iostream>
#include <vector>

using namespace std;

// ==========================================
// IMPLEMENTAÇÃO DO SHELLSORT
// ==========================================
void shellSort(vector<int>& arr) {
    int n = arr.size();
    // Inicia com um gap grande e vai reduzindo pela metade
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i += 1) {
            int temp = arr[i];
            int j;
            // Realiza o insertion sort para os elementos no gap atual
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

// ==========================================
// IMPLEMENTAÇÃO DO HEAPSORT
// ==========================================

// Função para manter a propriedade do Max-Heap (Heapify)
void heapify(vector<int>& arr, int n, int i) {
    int largest = i;       // Inicializa o maior como raiz
    int left = 2 * i + 1;  // Filho da esquerda
    int right = 2 * i + 2; // Filho da direita

    // Se o filho da esquerda for maior que a raiz
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // Se o filho da direita for maior que o maior até agora
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // Se o maior não for a raiz, faz a troca e continua o heapify
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(vector<int>& arr) {
    int n = arr.size();

    // 1. Constrói o Max-Heap (rearranja o array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // 2. Extrai os elementos do heap um por um
    for (int i = n - 1; i > 0; i--) {
        // Move a raiz atual (maior elemento) para o fim
        swap(arr[0], arr[i]);
        // Chama o heapify na árvore reduzida
        heapify(arr, i, 0);
    }
}

// Função auxiliar para imprimir o vetor
void printArray(const vector<int>& arr) {
    cout << "[";
    for (size_t i = 0; i < arr.size(); i++) {
        cout << arr[i] << (i == arr.size() - 1 ? "" : ", ");
    }
    cout << "]\n";
}

int main() {
    cout << "=== Analise Comparativa: ShellSort e HeapSort ===\n\n";

    // Teste baseado na Questão 2
    vector<int> arr = {30, 12, 45, 6, 18, 3};
    
    cout << "Vetor Original: ";
    printArray(arr);

    // Demonstração da construção do Max-Heap da Questão 2
    vector<int> heapArr = arr;
    int n = heapArr.size();
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(heapArr, n, i);
    }
    cout << "Max-Heap Construido (Q2-a): ";
    printArray(heapArr);

    // Demonstração da primeira extração da Questão 2
    swap(heapArr[0], heapArr[n - 1]); // Troca raiz com último
    heapify(heapArr, n - 1, 0);       // Heapify no resto
    cout << "Apos primeira extracao da raiz (Q2-b): ";
    printArray(heapArr);

    cout << "\n-------------------------------------------------\n";
    
    // Teste dos algoritmos de ordenação completos
    vector<int> arrShell = arr;
    shellSort(arrShell);
    cout << "Vetor ordenado com ShellSort: ";
    printArray(arrShell);

    vector<int> arrHeap = arr;
    heapSort(arrHeap);
    cout << "Vetor ordenado com HeapSort:  ";
    printArray(arrHeap);

    return 0;
}