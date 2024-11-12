package padrao;

public class Main {

    public static void main(String[] args) {
        
        int tamanho = 8;
        PilhaCompartilhada pilha = new PilhaCompartilhada(tamanho);

        // Empilha elementos na Pilha A
        pilha.empilhaA(1);
        pilha.empilhaA(2);
        pilha.empilhaA(3);

        // Empilha elementos na Pilha B
        pilha.empilhaB(9);
        pilha.empilhaB(8);
        pilha.empilhaB(7);
        pilha.empilhaB(6);
        
        System.out.println("-------------Iniciando Sistema-------------\n");

        // Mostra os elementos das pilhas
        System.out.println("Estado inicial das pilhas:");
        pilha.mostrarPilhaA();
        pilha.mostrarPilhaB();
        
        System.out.println("__________________________");

        // Verifica e mostra os topos das pilhas
        System.out.println("\nTopo da Pilha A: " + pilha.topoA());
        System.out.println("Topo da Pilha B: " + pilha.topoB());
        
        System.out.println("__________________________");

        // Desempilha elementos de A e B
        System.out.println("\nDesempilhando da Pilha A: " + pilha.desempilhaA());
        System.out.println("Desempilhando da Pilha B: " + pilha.desempilhaB());
        
        System.out.println("__________________________");

        // Mostra o estado das pilhas após desempilhar
        System.out.println("\nPilhas após desempilhar:");
        pilha.mostrarPilhaA();
        pilha.mostrarPilhaB();
        
        System.out.println("__________________________");

        // Verifica se as pilhas estão vazias
        System.out.println("\nA Pilha A está vazia? " + pilha.vaziaA());
        System.out.println("A Pilha B está vazia? " + pilha.vaziaB());
        
        System.out.println("__________________________");

        // Verifica se as pilhas estão cheias
        System.out.println("\nA Pilha A está cheia? " + pilha.cheiaA());
        System.out.println("A Pilha B está cheia? " + pilha.cheiaB());
        
        System.out.println("__________________________");

        // Mostra os tamanhos das pilhas
        System.out.println("\nTamanho da Pilha A: " + pilha.tamanhoA());
        System.out.println("Tamanho da Pilha B: " + pilha.tamanhoB());
        System.out.println("\n-------------Finalizando Sistema-------------");
    }
}
