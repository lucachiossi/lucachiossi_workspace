#ifndef GRAPH_UTILS
#define GRAPH_UTILS

#include <string>
#define BAD_ARGUMENTS -1

#include <clocale>
#include <map>
#include <vector>
#include <iostream>

class AdjVertex;
class AdjEdge;

class AdjVertex {
    private:
        int id;
        int val;
        std::vector<AdjEdge*>* incidenceEdges;
    public:
        AdjVertex(int id, int val=0);
        ~AdjVertex();
        int getId();
        int getVal();
        std::vector<AdjEdge*>* getIncidenceEdges();
        void addEdge(AdjEdge* edge);
        void removeEdge(int idEdge);
        /* std::vector<AdjEdge*> incidentEdges(); //TODO */
        /* bool isIncidentTo(AdjVertex* v); //TODO */
        std::string printVertex();
};

class AdjEdge {
    private:
        int id;
        int weight;
        AdjVertex* left;
        AdjVertex* right;
    public:
        AdjEdge(int id, AdjVertex* left, AdjVertex* right, int weight=1);
        ~AdjEdge();
        int getId();
        int getWeight();
        /* std::vector<AdjVertex*> endVerteces(); //TODO */
        /* AdjVertex* opposite(AdjVertex* v); //TODO */
        /* bool incidentOn(AdjVertex* v); //TODO */
        std::string printEdge();
};

/*
 * directed/undirected
 * weighted/unweighted */
class AdjacencyList {
    private:
        /* vertecesList and edgesList contain all the objects representing
         * the verteces and edges of the graph -> they have been implemented
         * as maps in order to be more efficient during lookup operations */
        std::map<int, AdjVertex*>* vertecesList;
        std::map<int, AdjEdge*>* edgesList;
        int idVertex;
        int idEdge;
    public:
        /*
         * construct the Adjacency Linked List from a jsonFile containing
         * directed: d|nd
         * weighted edges: we|nwe
         * matrix: adjacency_matrix */
        AdjacencyList(char* jsonInputFile);
        ~AdjacencyList();

        std::string printGraph(std::string message="");
        std::string printVerteces();
        std::string printEdges();

        /* it is good practive to obtain the linked lists (maps) before
         * applying any algorithm to the graph in order to work with a
         * consistent version */
        std::map<int, AdjVertex*>* getVerteces();
        std::map<int, AdjEdge*>* getEdges();

        /* it is important to add new verteces to the adjacency list
         * to maintain the linked lists consistent */
        void insertVertex(int val=0);
        void insertEdge(int id_left, int id_right, int weight=1);

        /* erasing an element from the graph will make related pointers
         * inconsistent to the graph -> it is a good usage to erase element
         * from the graph always before applying an algorithm */
        void eraseVertex(int id);
        void eraseEdge(int idEdge);
};

/*
 * directed/undirected
 * weighted/unweighted */
/* class AdjacencyMatrix { */

/* }; */

#endif
