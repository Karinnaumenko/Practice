class Avto
{
	int kpass;
	int vfuel;
	double rash;
	String type;
	
	Avto(int kp, int vf, double r, String t)
	{
		kpass = kp;
		vfuel = vf;
		rash = r;
		type = t;
	}
	void range() 
	{
		System.out.println("Автомобиль проедет " + vfuel/rash*100 + "км. на полном баке");
	}
	double range2() 
	{
		return vfuel/rash*100;
	}
	double fuel(int range) 
	{
		return rash*(range/100);
	}	
}
class Obj1
{
	public static void main(String args[])
       	{
		Avto nissan = new Avto(7, 50, 12.5, "Минивэн");
		Avto ford = new Avto(5, 40, 10.2, "Седан");
		Avto bmw = new Avto(2, 20, 18.5, "Кабриолет");
		/*nissan.kpass = 7;
		ford.kpass = 5;
		bmw.kpass = 2;
		nissan.type = "Минивэн";
		ford.type = "Седан";
		bmw.type = "Кабриолет";
		nissan.vfuel = 50;
		ford.vfuel = 40;
		bmw.vfuel = 20;
		nissan.rash = 12.5;
		ford.rash = 10.2;
		bmw.rash = 18.5;
		*/
		System.out.println("Информация об автомобиле \"Ниссан\"");
		System.out.println("Количество пассажиров: " + nissan.kpass);
		System.out.println("Ёмкость топливного бака: " + nissan.vfuel);
		System.out.println("Тип кузова: " + nissan.type);
		nissan.range();
		System.out.println("Информация об автомобиле \"Форд\"");
                System.out.println("Количество пассажиров: " + ford.kpass);
                System.out.println("Ёмкость топливного бака: " + ford.vfuel);
                System.out.println("Тип кузова: " + ford.type);
                ford.range();
		System.out.println("Информация об автомобиле \"BMW\"");
                System.out.println("Количество пассажиров: " + bmw.kpass);
                System.out.println("Ёмкость топливного бака: " + bmw.vfuel);
                System.out.println("Тип кузова: " + bmw.type);
                bmw.range();
		System.out.println("BMW проедет на полном баке " + bmw.range2() + "км.");
		System.out.println("BMW проедет 100 км., истратив " + bmw.fuel(100) + "литров");



	}	
}
