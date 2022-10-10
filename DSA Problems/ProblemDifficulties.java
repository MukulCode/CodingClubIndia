import java.util.*;

public class ProblmeDifficulties {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		while(t-- > 0) {
			HashMap<Integer , Integer> hm = new HashMap<>();
			for(int i = 1 ; i <= 4 ; i++) {
				int x = sc.nextInt();
				hm.put(x , hm.getOrDefault(x, 0) + 1);
			}
			if(hm.size() == 4 || hm.size() == 3) {
				System.out.println("2");
			}else if(hm.size() == 1) {
				System.out.println("0");
			}else {
				for(Integer num : hm.values()) {
					if(num % 2 == 0) {
						System.out.println("2");
					}else {
						System.out.println("1");
					}
					break;
				}
			}
		}
		sc.close();
	}

}
