//Problem statement -
//Program including all Operations on Graph and illustrate the traversals using DFS and BFS
//Coded By Aarush Arora

//Graph implemented as Adjacency List using vector;
#include<bits/stdc++.h>
using namespace std;

void insert_graph(vector<int> *v,int start,int end) {
	v[start].push_back(end);
	return;
}

void BFS(vector<int> *v,int n) {
	int start=0,vertex=0;
	cout<<"BFS Traversal\n";
	cout<<"Enter vertex from which to start the traversal with or 0 to start from the first vertex\n";
	cin>>start;
	int discovered[n] = {0};
	queue<int> q;
	q.push(start);
	discovered[start] = 1;
	while(!q.empty()) {
		vertex = q.front();
		cout<<vertex<<" ";
		q.pop();
		for(int i : v[vertex]) {
			if(!discovered[i]) {
				q.push(i);
				discovered[i]=1;
			}
		}
	}
}

void DFS(vector<int> *v,int n) {
	int vertex=0;
	int discovered[n]={0};
	int start=0;
	cout<<"DFS Traversal\n";
	cout<<"Enter start position or 0 to start from first vertex\n";
	cin>>start;
	stack<int> s;
	s.push(start);
	discovered[start]=1;
	while(!s.empty()) {
		cout<<s.top()<<" ";
		vertex = s.top();
		s.pop();
		for(auto i: v[vertex]) {
			if(!discovered[i]) {
				s.push(i);
				discovered[i]=1;
			}
		}
	}
}

int main() {
	int v=0,n=0,i=0,a=0,b=0;
	cout<<"Enter number of vertices\n";
	cin>>v;
	vector<int> adj[v];
	//created a graph with vertices=v
	//Enter edges
	cout<<"Enter number of edges\n";
	cin>>n;
	for(i=0;i<n;i++) {
		cin>>a>>b;
		insert_graph(adj,a,b);
	}
	//BFS Traversal of Graph -
	BFS(adj,v);
	//DFS Traversal of Graph - 
	DFS(adj,v);
}