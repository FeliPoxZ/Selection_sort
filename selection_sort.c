void selection_sort(List *list){
    //criação de um node auxiliar para armzenar o current e o data minimos
    Node* node_min = (Node*)malloc(sizeof(Node));
    node_min->prev = NULL;
    
    //variaveis necessarias
    int saved_number;
    Node* current = list->head;
    Node* first = list->head; //é o ponto de partida das verificações

    //percorre até o ultimo node da lista (porque por tabela o ultimo node é sempre maior nao precisa de verificação)
    while (current != list->tail) {
        //define o data do node minimo igual ao data do current 
        node_min->data = current->data;
        //percorre toda a lista
        while (current != NULL) {
            if (current->data < node_min->data){ //verifica se há algum data menor que o data minimo do node auxiliar
                //em caso positivo
                node_min->data = current->data; //atribui o valor minimo para o data minimo do node_auxiliar
                node_min->next = current; //atribui o enderço de memoria do node de menor data para o ponteiro next do node auxiliar
            }
            current = current->next; //current avança um node
        }

        saved_number = first->data; //salva o data do ponto de partida em uma variavel
        first->data = node_min->data; //atribui o valor do data minimo do node_aux para o ponto de partida (ou o node que tem que possuir o menor data)
        node_min->next->data = saved_number; //atribui no current que antes tinha o menor data o valor do data que havia no ponto de partida (first)
        first = first->next; //o firt agora é o proximo node
        current = first; //current recebe o valor do first
    }

    free(node_min); //libera o node aux
}
