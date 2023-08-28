package Observer_DesginPattern_NotifyMe;

import Observer_DesginPattern_NotifyMe.Observable.IPhoneObservable;
import Observer_DesginPattern_NotifyMe.Observable.StockObservable;
import Observer_DesginPattern_NotifyMe.Observer.MailObserver;
import Observer_DesginPattern_NotifyMe.Observer.NotificationAlertObserver;
import Observer_DesginPattern_NotifyMe.Observer.PhoneObserver;

public class Driver {
	public static void main(String[] args){
		StockObservable iphonStockObservable = new IPhoneObservable();

		NotificationAlertObserver obs1 = new PhoneObserver("12345", iphonStockObservable);
		NotificationAlertObserver obs2 = new MailObserver("harsh", iphonStockObservable);
		NotificationAlertObserver obs3 = new PhoneObserver("67890", iphonStockObservable);
		NotificationAlertObserver obs4 = new MailObserver("bhabar", iphonStockObservable);
		
		iphonStockObservable.add(obs1);
		iphonStockObservable.add(obs2);
		iphonStockObservable.add(obs3);
		iphonStockObservable.add(obs4);

		iphonStockObservable.setStockCount(10);
	}
}
