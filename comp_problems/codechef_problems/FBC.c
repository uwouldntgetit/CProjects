import java.util.*;

public class test_program {
	public static void main(String args[]) {
		int num_cases, capacity, water_in;
		Scanner scan = new Scanner(System.in);
		num_cases = scan.nextInt();
		
		for(int i = 0; i < num_cases; i++) {
			capacity = scan.nextInt();
			water_in = scan.nextInt();
			System.out.println(capacity - water_in);
		}
		scan.close();
	}
}
