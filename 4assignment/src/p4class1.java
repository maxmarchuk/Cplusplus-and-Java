/*
 * Max Marchuk
 * CS 202
 * Karla Fant
 * Program 4
 * Main Class file / application file
 */

import java.io.*;
import java.util.Scanner;


//main class 
public class p4class1{
	
	//menu function. Will be called in main
	public static void menu(BST newTree){
		
		int menuChoice = 0;
		//main menu loop
		while(menuChoice != 3){
			
			//output all of the menu options
			System.out.println("Please choose an option from the menu:");
			System.out.println("1) Add a new review");
			System.out.println("2) Display all reviews");
			System.out.println("3) Quit Program");
			
			//scan for the user's choice
			Scanner input = null;
			input = new Scanner(System.in);
			menuChoice = input.nextInt();
			
			//pass the user's choice into a switch statements
			switch(menuChoice){
			
			case 1:
				//execute the addNewReview() function 
				addNewReview(newTree);
				break;
			case 2:
				//displays the tree
				newTree.displayAll();
				break;
			case 3:
				return;
			default:
				System.out.println("Invalid input. Aborting");
				
			}
		}
	}
	
	//add new review temporary function in main
	public static void addNewReview(BST newTree){
		
		Scanner input = null;
		input = new Scanner(System.in);
				
		System.out.println("What is the rating (1-10) of the vacation you went on?");
		int vacRating = input.nextInt();
		System.out.println("Was there nice weather on the vacation? (input \"true\" for yes, and \"false\" for no)");
		boolean vacGoodWeather = input.nextBoolean();
		
		System.out.println("What location would you like to add this review for?\n1) Mountain \n2) Beach");
		int reviewType = input.nextInt();
		
		switch (reviewType){
		case 1:
		{
			//collect all of the mountain data needed
			System.out.println("How much snowfall was there at the mountain?");
			int snowfall = input.nextInt();
			System.out.println("What was the price of the lift tickets?");
			float liftPrice = input.nextFloat();
			
			//create a new mountain object with the collected data
			//using dynamic binding
			vacation vacPtr = new mountain(vacRating, vacGoodWeather, snowfall, liftPrice);
			
			//pass the vacation object into a node object
			
			//pass that node object into the tree's insertion function
			newTree.addReview(vacPtr);
			break;
			
		}
		case 2:
		{
			//collect the beach data required
			System.out.println("What would you rate the resort you stayed at? (1-10)");
			int resortRating = input.nextInt();
			
			//create a new beach object with a vacation using dynamic binding 
			//and the beach constructor
			vacation vacPtr = new beach(vacRating, vacGoodWeather, resortRating);
		
			//pass the vacation object into a node object
			
			//pass that node object into the tree's insertion function
			newTree.addReview(vacPtr);
			break;
			
		}
		
	}
		
		
	}
	
	//main function
	public static void main(String[] args) {
		
		//create a new tree object 
		BST newTree = new BST();
		//pass that object 
		menu(newTree);
		
	}

}
