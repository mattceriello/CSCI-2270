#include "Graph9.hpp"
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <unistd.h>
#include <stdio.h>
#include <cctype>
#include <string>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

void Graph::addVertex(string name){
  bool found = false;
  for(int i = 0; i < vertices.size(); i++){
      if(vertices[i]->name == name){
          found = true;
      }
  }
  if(found == false){
      vertex * v = new vertex;
      v->name = name;
      vertices.push_back(v);
  }
}

void Graph::addEdge(string v1, string v2, int num){
  for(unsigned int i = 0; i < vertices.size(); i++){
      if(vertices[i]->name == v1){
          for(unsigned int j = 0; j < vertices.size(); j++){
              if(vertices[j]->name == v2 && i != j){
                  adjVertex av;
                  av.v = vertices[j];
                  av.weight = num;
                  vertices[i]->adj.push_back(av);
                  //another vertex for edge in other direction
                  adjVertex av2;
                  av2.v = vertices[i];
                  av2.weight = num;
                  vertices[j]->adj.push_back(av2);
              }
          }
      }
  }
}

void Graph::displayEdges(){
  for(unsigned int i = 0; i < vertices.size(); i++){
      cout<<vertices[i]->name<<" --> ";
      for(unsigned int j = 0; j < vertices[i]->adj.size(); j++){
          cout << vertices[i]->adj[j].v->name << " ";
      }
      cout<<endl;
  }
}

void Graph::setAllVerticesUnvisited(){

  for(unsigned int i=0; i<vertices.size(); i++) {
      vertices[i]->visited = false;
  }
}

void Graph::breadthFirstTraverse(string sourceVertex){
  setAllVerticesUnvisited(vertices);
  vertex* start;
  for (unsigned int i = 0; i < vertices.size(); i++){
    if(vertices[i]->name == sourceVertex){
      start = vertices[i];
    }
  }
  start->visited = true;
  cout << "Starting vertex (root): " << start->name << "-> ";
  queue<vertex*> q;
  q.push(start);
  while(!q.empty()){
    vertex* n = q.front();
    q.pop();
    for(unsigned int x = 0;  x < n-> adj.size(); x++){
      if(n->adj[x].v->visited == false){
        n->adj[x].v->visited = true;
        n->adj[x].v->distance = n->distance + 1;
        cout << n->adj[x].v->name <<"("<< n->adj[x].v->distance <<")"<< " ";
        q.push(n->adj[x].v);
      }
    }
  }
}



int Graph::getConnectedComponents(){
  int count = 0;
  setAllVerticesUnvisited(vertices);
  for(unsigned int i=0; i<vertices.size(); i++) {
      if(vertices[i]->visited == false){
        dfsHelper(vertices[i]);
        count++;
      }
  }
  return count;
}



bool biHelper(vertex* n){
  n->visited = true;
  if(n->color == ""){
      n->color = "red";
  }
  for(unsigned int x = 0;  x < n-> adj.size(); x++){
    if(n->adj[x].v->visited == true){
      if((n->color == "red" && n->adj[x].v->color == "red") || (n->color == "blue" && n->adj[x].v->color == "blue") ){
        return false;
      }
    }
    else if(n->adj[x].v->visited == false){
      n->adj[x].v->visited = true;
      if(n->color == "red"){
        n->adj[x].v->color = "blue";
      }
      else if(n->color == "blue"){
        n->adj[x].v->color = "red";
      }
      biHelper(n->adj[x].v);
    }
  }
  return true;
}

bool Graph::checkBipartite(){
  setAllVerticesUnvisited(vertices);
  bool bipartite = true;
  vertices[0]->color = "red";
  for(unsigned int i=0; i<vertices.size(); i++) {
      if(vertices[i]->visited == false){
        bipartite = biHelper(vertices[i]);
        if(bipartite == false){
          return false;
        }
      }
  }
  return true;
}

void dfsHelper(vertex* n){
  n->visited = true;
  cout << n->name << " --> ";
  for(unsigned int x = 0; x < n->adj.size(); x++ ){
      if(n->adj[x].v->visited == false){
        dfsHelper(n->adj[x].v);

      }
  }
}

void Graph::depthFirstTraversal(string sourceVertex){
  vertex* start;
  for (unsigned int i = 0; i < vertices.size(); i++){
    if(vertices[i]->name == sourceVertex){
      start = vertices[i];
    }
  }
  dfsHelper(start);
  cout << "Done" << endl;
}

vertex* Graph::DijkstraAlgorithm(string start, string end){
  vertex* vStart;
  vertex* vEnd;
  vertex* vSolved;
  vertex* s;
  int dist= 0;

  int min;
  for (unsigned int i = 0; i < vertices.size(); i++){
    if(vertices[i]->name == start){
      vStart = vertices[i];
    }
  }
  for (unsigned int j = 0; j < vertices.size(); j++){
    if(vertices[j]->name == end){
      vEnd = vertices[j];
    }
  }

  vStart->visited = true;
  vector<vertex*> solvedList;
  solvedList.push_back(vStart);

  while(vEnd->visited == false){
    min = 100000000;
    vSolved = NULL;
    for(unsigned int x = 0; x < solvedList.size(); x++){
      s = solvedList[x];
      for(unsigned int k = 0; k < s->adj.size(); k++){
        //cout << solvedList.size() << endl;
        if(s->adj[k].v != NULL){


          if(s->adj[k].v->visited == false){//seg fault
            dist = s->distance + s->adj[k].weight;

            if(dist < min){
              vSolved = s->adj[k].v;
              min = dist;
              s->adj[k].v->pred = s;
              //cout << "hello" << endl;
            }
          }
        }
      }
    }

    vSolved->distance = min;
    vSolved->visited = true;
    solvedList.push_back(vSolved);

  }
  return vEnd;
}

void Graph::shortestpath(string start, string end){
  vertex* vStart;
  vertex* vEnd;

  vertex* s;



  for (unsigned int i = 0; i < vertices.size(); i++){
    if(vertices[i]->name == start){
      vStart = vertices[i];
    }
  }
  cout << vStart->name << " ";
  for (unsigned int j = 0; j < vertices.size(); j++){
    if(vertices[j]->name == end){
      vEnd = vertices[j];
    }
  }

  s = vEnd;
  vector<vertex*> path;
  while(s->pred != NULL){
      path.push_back(s);
      s= s->pred;
  }

  int idxstart = path.size()-1;

  for(int k = idxstart; k >=0; k--){
    cout << path[k]->name << " ";
  }


}
