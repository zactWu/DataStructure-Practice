#include "graph.h"


int main() {
    graph course_graph;
    course_graph.build();
    course_graph.TopoSearch(1,0);
    cerr << endl << "�޷����ſγ̣� " <<endl;
    return 0;
}