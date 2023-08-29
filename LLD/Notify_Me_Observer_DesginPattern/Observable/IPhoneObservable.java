package Notify_Me_Observer_DesginPattern.Observable;
import java.util.*;

import Notify_Me_Observer_DesginPattern.Observer.NotificationAlertObserver;

public class IPhoneObservable implements StockObservable{

	public static int stock = 0;
	List<NotificationAlertObserver> observers = new ArrayList<>();

	@Override
	public void add(NotificationAlertObserver notificationAlertObserver){
		observers.add(notificationAlertObserver);
	};

	@Override
	public void remove(NotificationAlertObserver notificationAlertObserver){
		observers.remove(notificationAlertObserver);
	};

	@Override
	public void notifyAllObservers(){
		for(NotificationAlertObserver observer : observers){
			observer.update();
		}
	};

	@Override
	public void setStockCount(int newStockCount){
		stock = newStockCount;
		if(this.getStockCount() != 0){
			notifyAllObservers();
		}
	};

	@Override
	public int getStockCount(){
		return stock;
	};
}
