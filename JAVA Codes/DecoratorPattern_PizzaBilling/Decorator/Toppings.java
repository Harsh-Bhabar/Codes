package DecoratorPattern_PizzaBilling.Decorator;

import DecoratorPattern_PizzaBilling.BasePizza;

public abstract class Toppings extends BasePizza {
	public abstract int cost();
}
