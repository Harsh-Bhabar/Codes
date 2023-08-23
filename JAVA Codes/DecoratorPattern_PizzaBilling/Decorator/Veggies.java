package DecoratorPattern_PizzaBilling.Decorator;

import DecoratorPattern_PizzaBilling.BasePizza;

public class Veggies extends Toppings {
	BasePizza basePizza;

	public Veggies(BasePizza basePizza){
		this.basePizza = basePizza;
	}

	@Override
	public int cost(){
		return this.basePizza.cost() + 40;
	}
}
