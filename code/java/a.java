import java.io.*;
import java.lang.*;
public class a{
	public static void main(String args[])
	{
		try{
		BufferedReader buffer = new BufferedReader(new InputStreamReader(System.in));
		int numbers[] = new int[] {32,34,3453,23,32,34,23};
		System.out.println("Hello World !!");
		int min=-1;
		for(int i=0;i<7;i++)
			if(numbers[i]>min)
				min=numbers[i];
		System.out.println(min);
		// input
		String s = buffer.readLine();
		int p=Integer.parseInt(s);
		System.out.println(p+1);
		}
		catch (Exception e)
		{
			e.getMessage();
		}
	}
}
