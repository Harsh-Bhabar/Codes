package Pizza_Billing_DecoratorPattern;

import LLD.DecoratorPattern_PizzaBilling.Decorator.Cheese;
import LLD.DecoratorPattern_PizzaBilling.Decorator.Toppings;
import LLD.DecoratorPattern_PizzaBilling.Decorator.Veggies;

public class Driver {
	public static void main(String[] args){
		BasePizza basePizza = new Cheese(new MargaritaPizza());
		BasePizza basePizza2 = new Veggies(new Cheese(new MargaritaPizza()));

		System.out.println(basePizza.cost());
		System.out.println(basePizza2.cost());

	}
}
