import java.io.*;
import java.lang.*;
class spoj{
	public static int reverse(int p)
	{
		int q=0;
		while(p!=0)
		{
			q=q*10+p%10;
			p=p/10;
		}
		return q;
	}
	public static void main(String args[])
	{
		try{
		BufferedReader buffer = new BufferedReader(new InputStreamReader(System.in));
		// input
		String s = buffer.readLine();
		int T=Integer.parseInt(s);
//		System.out.println(T);
		while(T-->0)
		{
			s = buffer.readLine();
			String[] arr=s.split(" ");
			int p=Integer.parseInt(arr[0]);
			int q=Integer.parseInt(arr[1]);
//			int revp,revq;
			System.out.println(reverse(reverse(q)+reverse(p)));			
		}
		}
		catch (Exception e)
		{
			e.getMessage();
		}
	}
}
