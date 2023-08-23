package ObserverDesginPattern_NotifyMe.Observer;

import ObserverDesginPattern_NotifyMe.Observable.StockObservable;

public class PhoneObserver implements NotificationAlertObserver{

	String phone;
	StockObservable stockObservable;

	public PhoneObserver(String phone, StockObservable stockObservable){
		this.phone = phone;
		this.stockObservable = stockObservable; 
	}

	@Override
	public void update() {
		this.sendMsg(phone, "Back in Stock Phone!");
	}

	public void sendMsg(String phone, String mail){
		System.out.println(phone + " " + mail);
	}
}
