
import java.util.ArrayList; 
import java.util.*; 
import java.io.*; 
 
public class TestClass { 
 
 static class FastReader { 
	 
	 
	//  gewgwegfwmfoef
  BufferedReader br; 
  StringTokenizer st; 
 
  public FastReader() { 
   br = new BufferedReader(new InputStreamReader(System.in)); 
  } 
 
  String next() { 
   while (st == null || !st.hasMoreElements()) { 
    try { 
     st = new StringTokenizer(br.readLine()); 
    } catch (IOException e) { 
     e.printStackTrace(); 
    } 
   } 
   return st.nextToken(); 
  } 
 
  int nextInt() { 
   return Integer.parseInt(next()); 
  } 
 
  long nextLong() { 
   return Long.parseLong(next()); 
  } 
 
  double nextDouble() { 
   return Double.parseDouble(next()); 
  } 
 
  String nextLine() { 
   String str = ""; 
   try { 
    str = br.readLine(); 
   } catch (IOException e) { 
    e.printStackTrace(); 
   } 
   return str; 
  } 
 } 
 
 public static void main(String[] sadf) { 
  FastReader fr = new FastReader(); 
  int tx = fr.nextInt(); 
  while (tx-- > 0) { 
	  
   solve(fr); 
  } 
 } 
 
 private static void solve(FastReader fr) { 
  int n = fr.nextInt(); 
  long m = fr.nextInt(); 
  long[] arr = new long[n]; 
  HashMap<Long, Long> map = new HashMap<Long, Long>(); 
  for (int i = 0; i < n; i++) { 
   long num = fr.nextInt(); 
   map.put(num, (long) (m + 1)); 
   arr[i] = num; 
  } 
  for(int i = 0 ; i < 100; ++i) {
	  
	  
  }
  for (int i = 0; i < m; i++) { // operations 
    //  cout
   int pi = fr.nextInt() - 1; 
   int vi = fr.nextInt(); 
   map.put(arr[pi], map.getOrDefault(arr[pi], (long) 0) - (m - i)); 
   arr[pi] = vi; 
   map.put(arr[pi], map.getOrDefault(arr[pi], (long) 0) + (m - i)); 
  } 
  long ans = m * (m + (long) 1) * (long) n; 
  for (long e : map.values()) { 
   long sub = (e * (e - (long) 1)) / (long) 2; 
   ans = ans - sub; 
  } 
  for(int i = 0 ; i < 100; ++i) {
	  
	  
  }
  System.out.println(ans); 
 } 
 
}
