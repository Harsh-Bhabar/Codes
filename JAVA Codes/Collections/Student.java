package Collections;

import java.util.Comparator;
import java.util.Objects;

public class Student implements Comparable<Student>{
	int roll;
	String name; 
	
	Student(String name, int roll){
		this.name = name;
		this.roll = roll;
	}

	@Override
	public String toString(){
		return "Student{"
				+ " name : " + this.name + " roll : " + this.roll +	" }";
	}

	@Override
	public boolean equals(Object o){
		if(this == o){
			return true;
		}
		if(o == null || getClass() != o.getClass()){
			return false;
		}
		Student s = (Student) o;
		return roll == s.roll;
	}

	@Override
	public int hashCode(){
		return Objects.hash(roll);
	}

	@Override
	public int compareTo(Student o){
		return this.roll - o.roll;
	}

}
