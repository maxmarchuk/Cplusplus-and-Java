/*
 * Max Marchuk
 * CS 202
 * Karla Fant
 * Program 4
 * class file for the vacation class
 */

public class vacation {
			
	vacation(){
		this.goodWeather = true;
		this.rating = 0;
	}
	
	public void setRating(int newRating){this.rating = newRating;}
	public void setGoodWeather(boolean newGoodWeather){ this.goodWeather = newGoodWeather;}
	public int getRating(){return this.rating;}
	public boolean isGoodWeather(){return this.goodWeather;}
	void display(){System.out.print("Rating: "+ this.rating + "\nGood Weather: ");
	  if(goodWeather == true) 
		  System.out.println("Yes");
      else 
    	  System.out.println("No");
	}
	
	private int rating;
	private boolean goodWeather;
}
