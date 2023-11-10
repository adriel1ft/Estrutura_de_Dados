public class ListaEncadeada {
    No cabeca;

    public ListaEncadeada(){
        this.cabeca = null;
    }

    public void addNo(int valor) {
        No novoNo = new No(valor);
        if (cabeca == null){
            cabeca = novoNo;
        } else {
            No atual = cabeca;
            //vai visitando os outros nos ate achar um apontando pra null
            while (atual.prox != null){
                atual = atual.prox;
            }
            atual.prox = novoNo;
            // nao precisa fazer novoNo.prox = null; pq no construtor .prox ja eh null 
        }

    }

    public void ListarNo(){
        if (cabeca == null){
            System.out.println("nao ha valores aqui");
        } else {
            No atual = cabeca;
            System.out.print(atual.valor + "-> ");
            //vai visitando os outros nos ate achar um apontando pra null
            while (atual.prox != null){
                atual = atual.prox;
                System.out.print(atual.valor + "-> ");
            }
            
            
        }

    }


    public static void main(String[] args) {
        ListaEncadeada lista = new ListaEncadeada();
        lista.addNo(5);
        lista.addNo(7);
        lista.ListarNo();
}
}