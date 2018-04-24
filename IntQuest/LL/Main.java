//Linked Lists


public class Main {
	public static void main(String[] args) {
		Node m_list = new Node(5);
		m_list.addtoend(3);
		print_list(m_list);
	}
	
	public static void print_list(Node n){
		while(n != null) {
			System.out.printf("%d ",n.data);
			n = n.next;
		}
	}
	
}


//Single linked list definition
class Node {
	Node next = null;
	int data;
	
	public Node(int d) {data = d;}
	public void addtoend(int d) {
		Node n_node = new Node(d);
		Node n = this;
		while(n.next != null) {
			n = n.next;
		}
		n.next = n_node;
	}
}