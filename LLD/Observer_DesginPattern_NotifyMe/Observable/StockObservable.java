package Observer_DesginPattern_NotifyMe.Observable;

import Observer_DesginPattern_NotifyMe.Observer.NotificationAlertObserver;

public interface StockObservable {
	
	public void add(NotificationAlertObserver notificationAlertObserver);

	public void remove(NotificationAlertObserver notificationAlertObserver);
	
	public void notifyAllObservers();
	
	public void setStockCount(int newStockCount);
	
	public int getStockCount();
}
