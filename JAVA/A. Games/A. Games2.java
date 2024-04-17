import java.io.*;

class Pair<T, K>
{
    T first; K second;
    Pair(T a, K b)
    {
	first = a;
	second = b;
    }
}

class Main
{
    public static void main(String[] args) throws IOException
    {
	BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
	int n = Integer.parseInt(bf.readLine()), zahl = 0;
	Pair<Integer, Integer>[] teams = (Pair<Integer, Integer>[])new Object[n];
	for(int a = 0; a < n; a++)
	{
	    int x, y;
	    String j[] = bf.readLine().split(" ");
	    x = Integer.parseInt(j[0]);
	    y = Integer.parseInt(j[1]);
	    teams[a] = new Pair<Integer, Integer>(x, y);
	}
	for(int a = 0; a < n; a++)
	{
	    for(int b = 0; b < n; b++)
	    {

		if(teams[a].first == teams[b].second)
		    zahl++;
	    }
	}
	System.out.println(zahl);
    }
}
