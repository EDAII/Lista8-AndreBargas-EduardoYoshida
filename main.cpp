#include<iostream>
#include <list>

using namespace std;

// A classe representa um grafo usando representação de lista de adjacência
class Grafo
{
    int V;    // Número de vértices
    list<int> *adj;
public:
    Grafo(int V);  // Construtor

    // Adiciona aresta ao grafo
    void addVertice(int v, int w);

    // imprime busca em largura
    void BFS(int s);
    void printGrafo();
    void printVisitados(bool *visitado);
    void printQueue(list<int>queue);
};

Grafo::Grafo(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

void Grafo::addVertice(int v, int w)
{
    adj[v].push_back(w); // Adiciona W na posição V
}

void Grafo::printGrafo(){
    cout << "Lista de Adjacência \n";
    list<int>::iterator j;

    for(int i = 0; i!= V; i++){
        cout << " " << i;
        for(j = adj[i].begin(); j!=adj[i].end();j++){
            cout << "-> " << *j;
        }
        cout << "\n";
    }
}
//
void Grafo::printVisitados(bool *visitado){
    cout << "\nVisitados: ";
    for(int i=0; i<V; i++){
      if(visitado[i] == true)
          cout << " " << i;
    }
    cout<<endl;
}

void Grafo::printQueue(list<int>queue){
  list<int>::iterator j;
  cout << "---------\n";
  cout<< "Queue: ";
  for(j = queue.begin(); j!=queue.end(); j++){
      cout << " " << *j;
  }
  cout<<endl;
}
void Grafo::BFS(int s)
{
    // Marca todos os vértices como não visitados
    bool *visitado = new bool[V];
    for(int i = 0; i < V; i++)
        visitado[i] = false;

    // Cria uma lista para a BFS
    list<int> queue;

    // Marca o nó atual como visitado e pula para o próximo
    visitado[s] = true;
    queue.push_back(s);

    list<int>::iterator i;

    while(!queue.empty())
    {
        // Remove o vértice da queue
        int iteracao = 1;
        s = queue.front();
        cout << s << " ";
        // printQueue(queue);
        queue.pop_front();

        // PEga todos os vértices adjacentes de S, caso o vértice não
        // tenha sido visitado marca como visitado e coloca na fila
        for (i = adj[s].begin(); i != adj[s].end(); ++i)
        {
            // printVisitados(visitado);
            if (!visitado[*i])
            {
                visitado[*i] = true;
                queue.push_back(*i);
            }
        }
    }
}

int main()
{
    int num;
    Grafo g(4);
    g.addVertice(0, 1);
    g.addVertice(0, 2);
    g.addVertice(1, 2);
    g.addVertice(2, 0);
    g.addVertice(2, 3);
    g.addVertice(3, 3);

    g.printGrafo();
    cout << "Insira algum vértice a partir do qual será realizada a travessia: ";
    cin >> num;
    cout << endl;
    cout << "Travessia em largura" << "(a partir do vértice " << num << "): ";
    g.BFS(num);
    cout << endl;
    return 0;
}
