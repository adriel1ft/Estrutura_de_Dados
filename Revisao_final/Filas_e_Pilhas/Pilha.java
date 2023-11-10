public class PilhaSeq {
    int dados[];
    int topo;
    int tamMax;

    //construtor
    public PilhaSeq(){
        tamMax = 100;
        dados = new int[tamMax];
        topo = -1;
    }
}

//verificar se vazia

public boolean vazia() {

    if (topo == -1){
        return "pilha vazia";
    } else {
        return "pilha contém coisas"
    }

}