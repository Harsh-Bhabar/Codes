package DecoratorPattern_PizzaBilling.Decorator;

import DecoratorPattern_PizzaBilling.BasePizza;

public class Cheese extends Toppings{
	BasePizza basePizza;

	public Cheese(BasePizza basePizza){
		this.basePizza = basePizza;
	}

	@Override
	public int cost(){
		return this.basePizza.cost() + 70;
	}
}
