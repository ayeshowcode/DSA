#include <iostream>
using namespace std;
class adjNode
{
public:
    int vertex;
    adjNode *next;
    adjNode(int v) : vertex(v), next(NULL) {}
};
class AdjList
{
private:
    int v;
    adjNode **graph;

public:
    AdjList(int vertices)
    {
        v = vertices;
        graph = new adjNode *[v];
        for (int i = 0; i < v; i++)
            graph[i] = NULL;
    }
    void addEdge(int source, int destination)
    {
        adjNode *newNode = new adjNode(0);
        newNode->vertex = destination;
        newNode->next = graph[source];
        graph[source] = newNode;
    }
    void deleteEdge(int source, int destination)
    {
        //remove edge from source to destination
        adjNode *temp = graph[source];
        adjNode *prev = NULL;

        while(temp!=NULL && temp->vertex!=destination)
        {
            prev=temp;
            temp = temp->next;
        }
        if(temp!=NULL)
        {
            if(prev==NULL)
                graph[source]=temp->next;
            else
                prev->next=temp->next;
            delete temp;
        }
        //remove edge from destination to source
        adjNode *temp = graph[destination];
        adjNode *prev = NULL;

        while(temp!=NULL && temp->vertex!=source)
        {
            prev=temp;
            temp = temp->next;
        }
        if(temp!=NULL)
        {
            if(prev==NULL)
                graph[destination]=temp->next;
            else
                prev->next=temp->next;
            delete temp;
        }


    }
    void addVertex(int vk, int source, int destination)
    {
        addEdge(source, vk);
        addEdge(vk, destination);
    }

    void printGraph()
    {
        for (int i = 0; i < v; i++)
        {
            cout << i << ": ";
            adjNode *temp = graph[i];
            while (temp != NULL)
            {
                cout << "--> " << temp->vertex;
                temp = temp->next;
            }
        }
    }
    void deleteVertex(int k)
    {
        // iterate through all the vertices of the graph
        for (int i = 0; i < v; i++)
        {
            adjNode *temp = graph[i];
            if (i == k)
            {
                graph[i] = temp->next;
                temp = graph[i];
            }
            while (temp != NULL)
            {
                if (temp->vertex == k)
                    break;

                adjNode *prev = temp;
                temp = temp->next;
                if (temp == NULL)
                    continue;
                
                prev->next=temp->next;
                temp=NULL;
            }
        }
    }
    
};
int main()
{
}