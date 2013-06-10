/*
 * Max Marchuk
 * CS 202
 * Karla Fant
 * Program 4
 * definitions for the beach class and its functions
 */

public class beach extends vacation{
	
	//data members of this class
	private int resortRating;
	
	//constructor
	beach(int rating, boolean goodWeather, int newResortRating){
		
		this.setRating(rating);
		this.setGoodWeather(goodWeather);
		this.setResortRating(newResortRating);
		
	}
	public void setResortRating(int newResortRating){this.resortRating = newResortRating;}
	public void display(){System.out.println("Resort Rating: "+ this.resortRating); super.display();}

		
}

