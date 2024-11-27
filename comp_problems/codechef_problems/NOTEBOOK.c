import java.util.*;

public class test_program {
	public static void main(String args[]) {
		int num_cases, weight;
		Scanner scan = new Scanner(System.in);
		num_cases = scan.nextInt();
		
		for(int i = 0; i < num_cases; i++) {
			weight = scan.nextInt();
			System.out.println(weight * 10);
		}
		scan.close();
	}
}

