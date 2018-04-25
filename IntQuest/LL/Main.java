//Linked Lists


public class Main {
	public static void main(String[] args) {
		Node m_list = new Node(1);
		m_list.addtoend(2);
		m_list.addtoend(3);
		m_list.addtoend(4);
		m_list.addtoend(5);
		m_list.addtoend(6);
		m_list.addtoend(3);
		m_list.addtoend(3);
		m_list.addtoend(5);
		m_list.addtoend(3);
		print_list(m_list);
		System.out.println(" ");
		m_list = fun2_1(m_list);
		print_list(m_list);
		System.out.println(" ");
		System.out.println(fun2_2(6,m_list).data);
	}
	
	//Helper...Prints Linked list in order
	public static void print_list(Node n){
		while(n != null) {
			System.out.printf("%d ",n.data);
			n = n.next;
		}
	}
	
	//2.1 Remove duplicates from unsorted linked list.
	//Solve without using a temp buffer
	//Solved in O(n^2)
	public static Node fun2_1(Node head) {
		Node n = head;
		Node parent = n;
		//iterate from first element
		while(n.next != null ) {
			int d = n.data;
			Node nn = n;
			//iterate throuch all elements after n and delete copies
			while(nn.next != null) {
				if (nn.next.data == d) {
					nn.next = nn.next.next;
				} else {
					nn = nn.next;
				}
			}
			n = n.next;
		}
		return parent;
	}
				
	
	//2.2 nth to last element of single linked list
	//Find size of list, subtract size by n will give you idx for element
	public static Node fun2_2(int n, Node head) {
		if (head == null) {return head;}
		int count = 0; Node nn = head;
		while(nn != null) { count++; nn = nn.next;}
		System.out.println(count);
		int idx = count-n;
		
		//If n is greater than number of elements
		if (idx < 0) {
			return head;
		}
		
		int it_idx = 0;
		nn = head;
		while( it_idx != idx) {nn = nn.next; it_idx++;}
		return nn;
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