public class PracticeQuestion {
		
	
	public void oddNumbers(){
		
		for(int itemp = 0; itemp <=1000; itemp++) {
			if(itemp %2 != 0)
				System.out.println("Number is odd:"+itemp);
		}
		
	}
	
	
	public void evenNumbers() {
		
		for(int itemp = 1; itemp <=500; itemp++) {
			if(itemp %2==0) {
				System.out.println("Even number is : "+itemp);
			}
		}
		
	}
	
	public void seventhNo() {
		
		for (int itemp = 7; itemp <= 200 ; itemp = itemp + 7) {
			System.out.println(itemp);
		}
		
	}
	
	public void patternRightAngleTriangle() {
		
		for(int itemp = 1; itemp <= 5; itemp++) {
			for(int jtemp = 1; jtemp<=itemp;jtemp++) {
				System.out.print("*");
			}
			System.out.println(" ");
		}
		
	}
	public void patternReverseRightAngleTriangle() {
		
		for(int itemp = 5; itemp >= 1; itemp--) {
			for(int jtemp = 1; jtemp<=itemp;jtemp++) {
				System.out.print("*");
			}
			System.out.println(" ");
		}
		
	}
	
	
	public void printNosTriangle() {
		int num = 1;
		for(int temp = 1; temp<=4;temp++) {
			
			for(int jtemp= 1;jtemp <=temp;jtemp++) {
				System.out.print(num+" ");
				num++;
			}
			System.out.println();
		}
	}
	
	public void printSameNosTriangle() {
		
		for(int temp = 1; temp<=6;temp++) {
			
			for(int jtemp= 1;jtemp <=temp;jtemp++) {
				System.out.print(jtemp+" ");
				
			}
			System.out.println();
		}
	}
	
	public void printReverseSameNosTriangle() {

	    for(int temp = 6; temp >= 1; temp--) {

	        for(int jtemp = 1; jtemp <= temp; jtemp++) {
	            System.out.print(jtemp + " ");
	        }

	        System.out.println();
	    }
	}
	
	
	
	
	
	
	
}
