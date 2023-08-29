package Notify_Me_Observer_DesginPattern.Observer;

import Notify_Me_Observer_DesginPattern.Observable.StockObservable;

public class MailObserver implements NotificationAlertObserver {

	String email;
	StockObservable stockObservable;

	public MailObserver(String email, StockObservable stockObservable){
		this.email = email;
		this.stockObservable = stockObservable;
	}

	@Override
	public void update(){
		sendMail(email, "Back in Stock mail!");
	}

	public void sendMail(String email, String mail) {
		System.out.println(email + " " + mail);
	}
}
