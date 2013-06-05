
public class mountain extends vacation{

	//data members of this class
	private int snowfall;
	private float liftPrice;
	
	mountain(){}
	public void setPrice(float newPrice){this.liftPrice = newPrice;}
	public void setSnowfall(int newSnowfall){this.snowfall = newSnowfall;}
	public int  getSnowfall(){return this.snowfall;}
	public float getPrice(){return this.liftPrice;}
	void display(){System.out.println("\nSnowfall: "+ this.snowfall + "\nLift Price: "+ this.liftPrice);}

		
}
