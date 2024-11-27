
import java.util.*;

public class test_program {
	public static void main(String args[]) {
		int num_cases, size_group, cost;
		Scanner scan = new Scanner(System.in);
		num_cases = scan.nextInt();
		
		for(int i = 0; i < num_cases; i++) {
			size_group = scan.nextInt();
			cost =  scan.nextInt();
			if(size_group % 6 == 0)
				System.out.println(cost * (size_group / 6));
			else
				System.out.println(cost * ((size_group / 6) + 1));
		}
		scan.close();
	}
}
