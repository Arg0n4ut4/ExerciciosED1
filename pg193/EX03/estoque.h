#ifndef ESTOQUE_H
#define ESTOQUE_H

#define TAM 10

void inicializarEstoque(int estoque[], int tamanho);
void processarPedidos(int estoque[], int tamanho);
void imprimirComparacaoEstoque(const int estoque[], const int estoqueAntigo[], int tamanho);

#endif // ESTOQUE_H
