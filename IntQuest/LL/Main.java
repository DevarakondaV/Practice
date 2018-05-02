//Linked Lists


public class Main {
	public static void main(String[] args) {
		Node m_list = new Node(1);
		m_list.addtoend(2);
		m_list.addtoend(3);
		m_list.addtoend(4);
		m_list.addtoend(5);
		m_list.addtoend(6);
		m_list.addtoend(7);
		m_list.addtoend(8);
		m_list.addtoend(9);
		m_list.addtoend(10);
		print_list(m_list);
		System.out.println("\n");
		fun2_3(m_list.next.next.next.next);
		print_list(m_list);
		System.out.println("\n");
		
		Node xx = new Node(4);
		xx.addtoend(8);
		xx.addtoend(9);
		xx.addtoend(6);
		Node yy = new Node(7);
		yy.addtoend(4);
		yy.addtoend(6);
		yy.addtoend(9);
		yy.addtoend(8);
		yy.addtoend(3);
		Node rtn = fun2_4(xx,yy);
		print_list(rtn);
		
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
	
	//2.3 Remove a node from middle of list given only access to that node
	//Easy. Just move next nodes data into current node and erase next node by skipping it
	public static void fun2_3(Node n) {
		Node cpy = n;
		if (cpy.next != null) {
			cpy.data = cpy.next.data;
			cpy.next = cpy.next.next;
		}
	}
	
	//2.4 Two number represented in reverse order by linked list. Return their sum
	//Easy just add them in order they are and carry values right
	//The best way to solve this is using recursive functions
	public static Node fun2_4(Node x, Node y) {
		Node cpy_x = x; Node cpy_y = y; Node rtn = new Node(); int ext = 0; int data_x; int data_y; int data_rtn;
		boolean first = true;
		while (cpy_x != null || cpy_y != null) {
			data_x = cpy_x == null ? 0:cpy_x.data;
			data_y = cpy_y == null ? 0:cpy_y.data;
			data_rtn = data_x+data_y+ext;
			data_rtn-=10;
			Node n_n;
			if (data_rtn < 0) {
				//n_n = new Node(data_rtn+10);
				if (first) {rtn = new Node(data_rtn+10); first = false;}
				else {rtn.addtoend(data_rtn+10);} 
				ext=0;
			}
			else {
				//n_n = new Node(data_rtn);
				if (first) {rtn = new Node(data_rtn);first = false;}
				else {rtn.addtoend(data_rtn);}
				ext=1;
			}
			if (cpy_y != null) {cpy_y = cpy_y.next;}
			if (cpy_x != null) {cpy_x = cpy_x.next;}
		}
		
		//fun2_3(rtn); //This is cheating :P There is an additional digit at the beginning of the LL because of decleration. You could also add a boolean to check		
		return rtn;
	}
}


//Single linked list definition
class Node {
	Node next = null;
	int data;
	
	public Node(int d) {data = d;}
	public Node(){};
	public void addtoend(int d) {
		Node n_node = new Node(d);
		Node n = this;
		while(n.next != null) {
			n = n.next;
		}
		n.next = n_node;
	}
}