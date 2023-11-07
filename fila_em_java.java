//fila com vector, ent circular

public int size(){
    int count = 0
    int posi = ini;

    //Se a posicao inicial esta vazia, a fila esta vazia
    if(vet[ini]==null){
        return 0;
    }

    while(true){
        count++; //incrementa o contador
        posi = (posi+1)%MAX//Move para a próxima posição, considerando a fila circular

        /*Se a posiição for nula
        ou se tivermos alcançado a posiição inicial,interrompa o loop*/
        if(vet[posi]==null||posi==ini){
            break;
        }
    }
    return count;}

    public boolean enfilar(Carro c){
        int nextPosi = (ini + size()) % MAX;

        if(vet[nextPos] != null){
            return false;
        }

        vet[nextPosi] = c;
        return true; //Indica sucesso ao enfilar
    }

 public Carro desenfilar(){
     //Se a fila estiver vazia
     if(vet[ini] == null){
         return null;
     }

     Carro removed = vet[ini];
     vet[ini] = null; //Limpar a posição inicial
     ini = (ini+1) % MAX;

     return removed;
 }