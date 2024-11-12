package padrao;

public class PilhaCompartilhada {
    
    private int[] vetor;
    private int topoA, topoB;
    
    // a) inicia os valores de frentee final.
    public PilhaCompartilhada(int tamanho){
        vetor = new int[tamanho];
        topoA = -1;               
        topoB = tamanho; 
    }
    
    // b) Método para empilhar um objeto na Pilha A
    public void empilhaA(Object obj) {
        if (cheiaA()) {
            System.out.println("Pilha A está cheia");
        } else {
            vetor[++topoA] = (int) obj;
        }
    }

    // c) Método para empilhar um objeto na Pilha B
    public void empilhaB(Object obj) {
        if (cheiaB()) {
            System.out.println("Pilha B está cheia");
        } else {
            vetor[--topoB] = (int) obj;
        }
    }

    // d) Verifica se a Pilha A está vazia
    public boolean vaziaA() {
        return topoA == -1;
    }

    // e) Verifica se a Pilha B está vazia
    public boolean vaziaB() {
        return topoB == vetor.length;
    }

    // f) Remove e retorna o objeto do topo da Pilha A
    public Object desempilhaA() {
        if (vaziaA()) {
            System.out.println("Pilha A está vazia");
            return null;
        } else {
            return vetor[topoA--];
        }
    }

    // g) Remove e retorna o objeto do topo da Pilha B
    public Object desempilhaB() {
        if (vaziaB()) {
            System.out.println("Pilha B está vazia");
            return null;
        } else {
            return vetor[topoB++];
        }
    }

    // h) Verifica se a Pilha A está cheia
    public boolean cheiaA() {
        return topoA + 1 == topoB;
    }

    // i) Verifica se a Pilha B está cheia
    public boolean cheiaB() {
        return topoB - 1 == topoA;
    }

    // j) Retorna o objeto no topo da Pilha A sem removê-lo
    public Object topoA() {
        if (vaziaA()) {
            System.out.println("Pilha A está vazia");
            return null;
        } else {
            return vetor[topoA];
        }
    }

    // k) Retorna o objeto no topo da Pilha B sem removê-lo
    public Object topoB() {
        if (vaziaB()) {
            System.out.println("Pilha B está vazia");
            return null;
        } else {
            return vetor[topoB];
        }
    }

    // l) Mostra todos os elementos da Pilha A
    public void mostrarPilhaA() {
        if (vaziaA()) {
            System.out.println("Pilha A está vazia");
        } else {
            System.out.print("Pilha A: ");
            for (int i = 0; i <= topoA; i++) {
                System.out.print(vetor[i] + " ");
            }
            System.out.println();
        }
    }

    // m) Mostra todos os elementos da Pilha B
    public void mostrarPilhaB() {
        if (vaziaB()) {
            System.out.println("Pilha B está vazia");
        } else {
            System.out.print("Pilha B: ");
            for (int i = vetor.length - 1; i >= topoB; i--) {
                System.out.print(vetor[i] + " ");
            }
            System.out.println();
        }
    }

    // n) Retorna o tamanho da Pilha A
    public int tamanhoA() {
        return topoA + 1;
    }

    // o) Retorna o tamanho da Pilha B
    public int tamanhoB() {
        return vetor.length - topoB;
    }
}
