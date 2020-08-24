#include "graph.h"

// USER INTERFACE

Graph* g_newGraph() {
	Graph* graph = (Graph*)malloc(sizeof(Graph));
	graph->vertices_ = g_newVertexNode(NULL);
	graph->num_vertices_= 0;
	graph->edges_ = g_newEdgeNode(NULL);
	graph->num_edges_= 0;
	return graph;
}
// create new empty graph and return it


GVertex* g_newVertex(const char* data) {
	GVertex* vertex = (GVertex*)malloc(sizeof(GVertex));
	vertex->data_ = data;
	vertex->degree_ = 0;
	vertex->edges_ = g_newEdgeNode(NULL);
	vertex->label_ = L_FRESH;
	return vertex;
}
// create new vertex and return it


GEdge* g_newEdge(GVertex* vertex1, GVertex* vertex2) {
	GEdge* edge = (GEdge*)malloc(sizeof(GEdge));
	edge->vertices_[0] = vertex1;
	edge->vertices_[1] = vertex2;
	edge->label_ = L_FRESH;
	return edge;
}
// create new edge whose vertices are vertex 1 & 2 and return it


GVertex* g_insertVertex(Graph* graph, const char* data) {
	GVertex* vertex = g_newVertex(data);
	g_insertVertexNode(graph->vertices_,vertex);
	graph->num_vertices_++;
	return vertex;
}
// create new vertex with data and insert the vertex node into the vertex list of the graph and return the vertex


void g_removeVertex(Graph* graph, GVertex* vertex) {
	if(!g_existVertex(graph,vertex))	return;	// check validity
	while(vertex->edges_->next_ != NULL)
		g_removeEdge(graph,vertex->edges_->next_->edge_);	// remove the edges of the vertex
	free(vertex->edges_);
	g_removeVertexNode(graph->vertices_,vertex);	// remove the vertex node from vertex list of the graph
	free(vertex);	// free the vertex
}
// remove the edges of the vertex and remove the vertex node from vertex list of graph and free the vertex


GEdge* g_insertEdge(Graph* graph, GVertex* vertex1, GVertex* vertex2) {
	GEdge* edge = g_newEdge(vertex1,vertex2);
	g_insertEdgeNode(graph->edges_,edge);
	g_insertEdgeNode(vertex1->edges_,edge);
	g_insertEdgeNode(vertex2->edges_,edge);
	graph->num_edges_++;
	vertex1->degree_++;
	vertex2->degree_++;
	return edge;
}
// create new edge whose vertices are vertex1,2 and insert edge node into the edge list of the graph, vertex1,2 and return the edge


void g_removeEdge(Graph* graph, GEdge* edge) {
	if(!g_existEdge(graph,edge))	return;	// check validity
	g_removeEdgeNode(graph->edges_,edge);	// remove the edge node from edge list of the graph
	g_removeEdgeNode(edge->vertices_[0]->edges_,edge);	// remove the edge node from edge list of the vertex1
	g_removeEdgeNode(edge->vertices_[1]->edges_,edge);	// remove the edge node from edge list of the vertex2
	edge->vertices_[0]->degree_--;
	edge->vertices_[1]->degree_--;
	free(edge);	// free the edge
}
// remove the edge nodes from edge list of the graph, vertex1, vertext2 and free the edge


int g_existVertex(Graph* graph, GVertex* vertex) {
	GVertexNode* list = graph->vertices_->next_;
	while(list != NULL && list->vertex_ != vertex)	list = list->next_;
	return list->vertex_ == vertex;
}
// check whether there exists the vertex inside the graph


int g_existEdge(Graph* graph, GEdge* edge) {
	GEdgeNode* list = graph->edges_->next_;
	while(list != NULL && list->edge_ != edge)	list = list->next_;
	return list->edge_ == edge;
}
// check whether there exists the edge inside the graph


GEdge* g_getEdge(GEdgeNode* list, GVertex* vertex1, GVertex* vertex2) {
	GEdgeNode* pVisited = list->next_;
	while(pVisited != NULL) {
		for(int i=0;i<2;i++)
			if(pVisited->edge_->vertices_[i]==vertex1 && pVisited->edge_->vertices_[(i-1)*(-1)]==vertex2)
				return pVisited->edge_;
		pVisited = pVisited->next_;
	}
	return NULL;
}
// get the edge whose vertices are vertex1,2


GVertex* g_oppositeVertex(GEdge* edge, GVertex* vertex) {
	return (edge->vertices_[0]==vertex) ? edge->vertices_[1] : edge->vertices_[0];
}
// return vertex in the opposite side of the edge of the vertex 



// INNER METHODS

GVertexNode* g_newVertexNode(GVertex* vertex) {
	GVertexNode* node = (GVertexNode*)malloc(sizeof(GVertexNode));
	node->vertex_ = vertex;
	node->next_ = NULL;
	return node;
}
// create new vertex node and return it


void g_insertVertexNode(GVertexNode* list, GVertex* vertex) {
	while(list->next_ != NULL) list = list->next_;
	list->next_ = g_newVertexNode(vertex);
}
// create new vertex node and insert it into back of the list


void g_removeVertexNode(GVertexNode* list, GVertex* vertex) {
	while(list->next_->vertex_ != vertex)	list = list->next_;	// not check validity
	GVertexNode* node = list->next_;
	list->next_ = list->next_->next_;
	free(node);
}
// find vertex node which is supposed to be removed and remove it from the list
// assume that there exists the vertex node inside the list


GEdgeNode* g_newEdgeNode(GEdge* edge) {
	GEdgeNode* node = (GEdgeNode*)malloc(sizeof(GEdgeNode));
	node->edge_ = edge;
	node->next_ = NULL;
	return node;
}
// create new edge node and return it


void g_insertEdgeNode(GEdgeNode* list, GEdge* edge) {
	while(list->next_ != NULL) list = list->next_;
	list->next_ = g_newEdgeNode(edge);
}
// create new edge node and insert it into back of the list


void g_removeEdgeNode(GEdgeNode* list, GEdge* edge) {
	while(list->next_->edge_ != edge)	list = list->next_;	// not check validity
	GEdgeNode* node = list->next_;
	list->next_ = list->next_->next_;
	free(node);
}
// find edge node which is supposed to be removed and remove it from the list
// assume that there exists the edge node inside the list



// GRAPH TRAVERSAL

void g_initGraphLabel(Graph* graph) {
	GVertexNode* vertex_list = graph->vertices_->next_;
	while(vertex_list != NULL) {
		vertex_list->vertex_->label_ = L_FRESH;
		vertex_list = vertex_list->next_;
	}
	GEdgeNode* edge_list = graph->edges_->next_;
	while(edge_list != NULL) {
		edge_list->edge_->label_ = L_FRESH;
		edge_list = edge_list->next_;
	}
}


void g_rDFS(GVertex* vertex) {
	GEdgeNode* edge_list = vertex->edges_->next_;	// 해당 정점의 간선리스트 참조
	vertex->label_ = L_VISITED;	// 정점 방문 라벨

	while(edge_list != NULL) {	// 순회할 간선 남음
		if(edge_list->edge_->label_ == L_FRESH) {	// 간선 라벨 FRESH 경우
			GVertex* opposite = g_oppositeVertex(edge_list->edge_,vertex);	// 해당 간선 반대편 정점 참조
			printf("%s -> %s ",vertex->data_,opposite->data_);
			if(opposite->label_ == L_FRESH) {	// 반대편 정점 라벨 FRESH 경우
				// TREE
				edge_list->edge_->label_ = L_TREE;
				printf("(tree)\n");
				g_rDFS(opposite);		// FRESH인 반대편 정점부터 DFS 재귀 호출
			}
			else {		// 반대편 정점 라벨 VISITED 경우
				// BACK
				edge_list->edge_->label_ = L_BACK;
				printf("(back)\n");
			}
		}
		edge_list = edge_list->next_;
	}
}


void g_DFS(Graph* graph) {
	printf("===================================\n");
	printf("DFS\n");
	g_initGraphLabel(graph);	// label initialize
	GVertexNode* node = graph->vertices_->next_;
	while(node != NULL && node->vertex_->label_ == L_FRESH)	// graph 내의 fresh인 정점에 대하여
		g_rDFS(node->vertex_);	// 한 정점으로부터 dfs 수행
}


void g_fBFS(Graph* graph, GVertex* start_vertex) {
	GVertexNode* next_vertex_list = g_newVertexNode(NULL);
	g_insertVertexNode(next_vertex_list,start_vertex);		// BFS start node
	start_vertex->label_ = L_VISITED;
	
	while(next_vertex_list->next_ != NULL) {	// not any node left next level -> exit loop 
		GVertexNode* vertex_list = next_vertex_list;	// next level -> current level
		next_vertex_list = g_newVertexNode(NULL);		// reset next level
		
		while(vertex_list->next_ != NULL) {		// not any node left current level -> exit loop
			GVertex* vertex = vertex_list->next_->vertex_;	// get vertex
			g_removeVertexNode(vertex_list,vertex);			// remove vertex node

			GEdgeNode* edge_list = vertex->edges_->next_;	// get edge list of current vertex
			while(edge_list != NULL) {	
				if(edge_list->edge_->label_ == L_FRESH) {	// fresh edge
					GVertex* opposite = g_oppositeVertex(edge_list->edge_,vertex);	// get opposite vertex
					printf("%s -> %s ",vertex->data_,opposite->data_);
					if(opposite->label_ == L_FRESH) {	// opposite vertex fresh
						// TREE
						printf("(tree)\n");
						edge_list->edge_->label_ = L_TREE;
						opposite->label_ = L_VISITED;
						g_insertVertexNode(next_vertex_list,opposite);	// add vertex into next level
					}
					else {	// opposite vertex visited
						// CROSS	
						printf("(cross)\n");
						edge_list->edge_->label_ = L_CROSS;
					}
				}
				edge_list = edge_list->next_;
			}
		}
		free(vertex_list);	// free first node of current vertex list
	}
}


void g_BFS(Graph* graph) {
	printf("===================================\n");
	printf("BFS\n");
	g_initGraphLabel(graph);
	GVertexNode* node = graph->vertices_->next_;
	while(node != NULL && node->vertex_->label_ == L_FRESH)
		g_fBFS(graph,node->vertex_);
}



// TEST

void g_test_show(Graph* graph) {
	printf("===================================\n");
	printf("TEST SHOW\n");
	GVertexNode* vertex_list = graph->vertices_->next_;
	while(vertex_list != NULL) {
		printf("vertex %s[%d] : ",vertex_list->vertex_->data_,vertex_list->vertex_->degree_);
		GVertexNode* opponent = graph->vertices_->next_;
		while(opponent != NULL) {
			if(g_getEdge(vertex_list->vertex_->edges_,vertex_list->vertex_,opponent->vertex_)!=NULL) {
				printf("%s ",opponent->vertex_->data_);
			}
			opponent = opponent->next_;
		}
		printf("\n");
		vertex_list = vertex_list->next_;
	}
}