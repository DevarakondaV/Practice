//Linked LIst

//class decl
class Node;

//Main methond
int main() {
	
	return 0;
}

//Node Def
class Node {
	Node * next = nullptr;
	int data;
	
	Node(int d) {data = d;}
	void addtoend(int d) {
		Node * n_end = new Node(d);
		Node n = this;
		while(n.next != nullptr) {
			n = n.next;
		}
		n.next = n_end;
	}
}