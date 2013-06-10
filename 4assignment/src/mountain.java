/*
 * Max Marchuk
 * CS 202
 * Karla Fant
 * Program 4
 * file for class definition of the mountain class
 */

public class mountain extends vacation{

	//data members of this class
	private int snowfall;
	private float liftPrice;
	
	//constructor
	mountain(int rating, boolean goodWeather, int snowfall, float liftPrice){
		
		this.setRating(rating);
		this.setGoodWeather(goodWeather);
		this.setSnowfall(snowfall);
		this.setPrice(liftPrice);
		
	}
	public void setPrice(float newPrice){this.liftPrice = newPrice;}
	public void setSnowfall(int newSnowfall){this.snowfall = newSnowfall;}
	public int  getSnowfall(){return this.snowfall;}
	public float getPrice(){return this.liftPrice;}
	void display(){System.out.println("Snowfall: "+ this.snowfall + "\nLift Price: "+ this.liftPrice); super.display();}

		
}
