/*
 * Max Marchuk
 * CS 202
 * Karla Fant
 * Program 4
 * node definition and function definitions
 * for the node class
 */

public class node {
	
	//private data members in the node object
	private vacation review;
	private node left; 
	private node right;
	
	//constructor for passing in a vacation object
	node(vacation newReview){
		
		review = newReview;
		left = null;
		right = null;
	}
	
	//returns left pointer
	public node getLeft(){return this.left;}
	//returns right pointer
	public node getRight(){return this.right;}
	//set the new left node by passing in a node
	public void setLeft(node newLeft){this.left = newLeft;}
	//set the new right node by passing in a node
	public void setRight(node newRight){this.right = newRight;}
	//set the review object for this current node
	public void setReview(vacation newReview){this.review = newReview;}
	//return the review's rating. The tree will be sorted by rating
	public int getKey(){return review.getRating();}
	//simply calls the review's display function
	public void display(){review.display();}
	//returns the vacation
	public vacation getReview(){return review;}
	

}
