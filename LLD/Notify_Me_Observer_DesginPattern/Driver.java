package Notify_Me_Observer_DesginPattern;

import Notify_Me_Observer_DesginPattern.Observable.IPhoneObservable;
import Notify_Me_Observer_DesginPattern.Observable.StockObservable;
import Notify_Me_Observer_DesginPattern.Observer.MailObserver;
import Notify_Me_Observer_DesginPattern.Observer.NotificationAlertObserver;
import Notify_Me_Observer_DesginPattern.Observer.PhoneObserver;

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
