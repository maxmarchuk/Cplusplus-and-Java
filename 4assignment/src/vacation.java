
public class vacation {
			
	vacation(){
		this.goodWeather = true;
		this.rating = 0;
	}
	
	public void setRating(int newRating){this.rating = newRating;}
	public void setGoodWeather(boolean newGoodWeather){ this.goodWeather = newGoodWeather;}
	public int getRating(){return this.rating;}
	public boolean isGoodWeather(){return this.goodWeather;}
	void display(){System.out.println("\nRating: "+ this.rating + "\nGood Weather: ");
	  if(goodWeather == true) 
		  System.out.println("Yes\n");
      else 
    	  System.out.println("No\n");
	}
	
	private int rating;
	private boolean goodWeather;
}
