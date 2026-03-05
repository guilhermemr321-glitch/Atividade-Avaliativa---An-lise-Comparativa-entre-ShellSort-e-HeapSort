Questão 1
O HeapSort possui complexidade $O(n \log n)$ garantida em todos os casos (pior, médio e melhor) porque sua estrutura é estritamente baseada em uma árvore binária completa (o Heap). A construção inicial do Heap consome tempo $O(n)$, e cada uma das $n$ extrações do maior elemento exige o rebaixamento (heapify) na árvore, o que custa no máximo a altura da árvore, ou seja, $O(\log n)$. Multiplicando a extração pelo número de elementos, temos o tempo garantido de $O(n \log n)$.
Já o ShellSort não possui uma complexidade matematicamente previsível para todos os casos porque seu desempenho depende inteiramente da "sequência de gaps" (intervalos) escolhida (ex: sequência de Shell, Hibbard, Sedgewick). Dependendo dessa sequência e da disposição inicial dos dados, a complexidade no pior caso pode variar de $O(n^2)$ até $O(n^{1.25})$, tornando-o instável em termos de previsibilidade.

Questão 2
Vetor original: [30, 12, 45, 6, 18, 3]
a) Construção do Max-Heap:

Avaliando o nó 45 (filho 3): Está correto (45 > 3).

Avaliando o nó 12 (filhos 6 e 18): O maior é 18. Troca 12 com 18. Vetor fica [30, 18, 45, 6, 12, 3].

Avaliando a raiz 30 (filhos 18 e 45): O maior é 45. Troca 30 com 45.
Vetor Max-Heap final: [45, 18, 30, 6, 12, 3]

b) Vetor após a primeira extração da raiz:

Extrai-se a raiz (45) e troca com o último elemento (3). Vetor fica [3, 18, 30, 6, 12 | 45].

Aplica-se o heapify na nova raiz (3). Seus filhos são 18 e 30. O maior é 30. Troca 3 com 30.
Vetor resultante: [30, 18, 3, 6, 12, 45]

Questão 3 
Resposta: A) Apenas II e IV
Justificativa: A afirmativa I é falsa (ShellSort é instável). A III é falsa (quem depende de gaps é o ShellSort). A II é verdadeira e a IV é verdadeira (ShellSort otimiza o Insertion Sort permitindo saltos maiores).

Questão 4
Para um sistema que processa milhões de registros, o HeapSort é o mais indicado.
Justificativa: Ao lidar com volumes massivos de dados, a previsibilidade é crucial para evitar gargalos no servidor. O HeapSort garante matematicamente uma complexidade de tempo de $O(n \log n)$ mesmo no pior cenário possível. O ShellSort, por sua vez, pode degradar sua performance para $O(n^2)$ dependendo da sequência de gaps e de como os milhões de registros estão inicialmente ordenados, o que seria catastrófico para o sistema.

Questão 5
A estrutura Heap é amplamente utilizada para implementar Filas de Prioridade de forma altamente eficiente. Em algoritmos de grafos, como o Algoritmo de Dijkstra (usado para encontrar o caminho mais curto), é necessário extrair repetidamente o vértice com a menor distância atual. Usando um Min-Heap, essa extração da distância mínima e a atualização das prioridades ocorrem em tempo $O(\log n)$, o que torna a execução do Dijkstra muito mais rápida em grafos grandes se comparada a uma busca linear em um array comum $O(n)$.



















