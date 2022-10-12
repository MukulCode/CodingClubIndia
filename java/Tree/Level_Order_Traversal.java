class Node {
	int data;
	Node left, right;
	public Node(int item)
	{
		data = item;
		left = right = null;
	}
}

class Main {
	Node root;

	public Main() { root = null; }

	void LevelOrder()
	{
        int h = height(root);
        int i;
        for (i=1; i<=h; i++)
            CurrentLevel(root, i);
	}
	int height(Node root) {
    	if (root == null)
        	  return 0; 
    	else {
       		int lheight = height(root.left);
       		int rheight = height(root.right);
       		if (lheight > rheight)
            	return(lheight+1);
       		else return(rheight+1);
    	}
	}
	void CurrentLevel (Node root ,int level) {
     	if (root == null){
        	    return;
		}
     	if (level == 1){
        	  System.out.print(root.data + " ");
		}
     	else if (level > 1) {
        	CurrentLevel(root.left, level-1);
        	CurrentLevel(root.right, level-1);
     	 }
	}
	public static void main(String args[])
	{
		Main tree = new Main();
		tree.root = new Node(1);
		tree.root.left = new Node(2);
		tree.root.right = new Node(3);
		tree.root.left.left = new Node(4);
		tree.root.left.right = new Node(5);

		tree.LevelOrder();

	}
}