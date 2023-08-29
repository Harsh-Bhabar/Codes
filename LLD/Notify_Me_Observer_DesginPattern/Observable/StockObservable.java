package Notify_Me_Observer_DesginPattern.Observable;

import Notify_Me_Observer_DesginPattern.Observer.NotificationAlertObserver;

public interface StockObservable {
	
	public void add(NotificationAlertObserver notificationAlertObserver);

	public void remove(NotificationAlertObserver notificationAlertObserver);
	
	public void notifyAllObservers();
	
	public void setStockCount(int newStockCount);
	
	public int getStockCount();
}
