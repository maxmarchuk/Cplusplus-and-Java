/*
 * Max Marchuk
 * CS 202
 * Karla Fant
 * Program 4
 * class file for the BST class
 * and the main data structure application and its functions
 */


public class BST {
	
	private node root;
	private node temp;
	
	//default constructor
	BST(){
	
	root = null;
	
	}
	
	//wrapper function for insertion
	public void addReview(vacation toAdd){
		temp = root;
		if(root == null)
			root = addReview(toAdd, root);
		else{
			while(temp != null){
				if(toAdd.getRating() <= temp.getKey())
					temp = temp.getLeft();
				else
					temp = temp.getRight();	
			}
			temp = addReview(toAdd, root);
		}		
	}
	
	//actual insertion function.
	//recursively inserts the toAdd node into the spot it needs to go into.
	private node addReview(vacation toAdd, node root){
		//if root doesn't exist, or you have reached the end of the tree where you wanted to get
		if(root == null)
			root = new node(toAdd);
		//if the new node's key is less than the current root's key,
		else{
			if(toAdd.getRating() <= root.getKey())
				root = addReview(toAdd, root.getLeft());
			else
				root = addReview(toAdd, root.getRight());
			}
		return root;

	}
	//wrapper function for the displayAll function
	public void displayAll(){
		displayAll(root);
	}
	//this function displays everything in the BST
	public void displayAll(node root){
		if(root == null)
			return;
		
		//in-order traversal
		displayAll(root.getLeft());
		root.display();
		displayAll(root.getRight());

	}
	

}
