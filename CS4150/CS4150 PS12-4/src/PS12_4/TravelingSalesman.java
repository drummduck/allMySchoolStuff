package PS12_4;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.PriorityQueue;



/*
To solve this problem, you will need to compute the total weight of the lightest Hamiltonian cycle in a complete, directed graph.
 
The lightest Hamiltonian cycle goes from vertex 0 to vertex 1 to vertex 2 and then back to vertex 0, with a total weight of 9.

Input
The first line contains n, where 2 <= n <= 50.

Each of the next n lines contains n integers, each of which is between 1 and 500, inclusive. This n by n grid of integers is the adjacency matrix for an n-vertex 
complete, directed graph.

Output
Produce a single line of input that contains the total weight of the lightest Hamiltonian cycle contained in the graph described in the input.

Sample Input 1	Sample Output 1
2				5
1 3
2 1

Sample Input 2	Sample Output 2
3				9
1 2 7
6 5 4
3 8 9
 */

public class TravelingSalesman 
{
    private static int vertexVisits = 0;
    private static ArrayList<Vertex> graph;
    private static ArrayList<Vertex> visitedVertices;
    private static ArrayList<Vertex> haventBeenVisited;
    private static Vertex startVertex;
    private static int min;
    private static boolean first = true;
    
    public static void main(String[] args) throws NumberFormatException, IOException 
    {
        BufferedReader buff = new BufferedReader(new InputStreamReader(System.in));
        int numOfVertices = Integer.parseInt(buff.readLine());
        graph = new ArrayList<Vertex>();
        haventBeenVisited = new ArrayList<Vertex>();
        min = 0;
        String line = "";
        
        for(int i = 0; i < numOfVertices; i++)
    	{
        	graph.add(new Vertex(i));
        	haventBeenVisited.add(new Vertex(i));
    	}
        
        int tempNumOfVertices = 0;
        boolean newLine = true;
        int i = 0;
        int tempMin = 0;
        
        //Read in the data, keep track of total min of one path of edges for now.
        while(tempNumOfVertices != numOfVertices)
        {      	
        	if(newLine)
        	{
        		line = buff.readLine();
        		newLine = false;
        	}
        	
        	else if(!newLine)
        	{
        		if(i == numOfVertices)
        		{
        			newLine = true;
        			i = 0;
        			tempNumOfVertices++;
        			min += tempMin;
        			continue;
        		}
            	if(i == tempNumOfVertices)
        		{
            		i++;
            		continue;
        		}
            	
            	int weight = Integer.parseInt(line.split("\\s")[i]);
                graph.get(tempNumOfVertices).addEdge(new Edge(weight, graph.get(tempNumOfVertices), graph.get(i)));
                haventBeenVisited.get(tempNumOfVertices).addEdge(new Edge(weight, haventBeenVisited.get(tempNumOfVertices), haventBeenVisited.get(i)));
                if(weight > tempMin) tempMin = weight;
                i++;
        	}           
        }
                
        startVertex = graph.get(0);
        System.out.println(optimize(startVertex, 0));          
        buff.close();
    }
     
    //Go through the vertices that have not been visited yet and create a lowerbound for them.
    public static int lowerBound()
    {   
    	int lowerBound = 0;
    	for(Vertex v : haventBeenVisited) {lowerBound += v.getLightestEdge();}
    	return lowerBound;
    }
    
    //This method finds the cheapest hamiltonian path for the graph.
    public static int optimize(Vertex currentVertex, int total)
    {
    	//First case is the end case(reached the beginning again, second case is if lower bound has been surpassed(break early, not a solution).
        if(currentVertex.getVisited() && currentVertex.equals(startVertex) && vertexVisits == graph.size()) {return total;}
        else if(currentVertex.getVisited() || total + lowerBound() > min) {return Integer.MAX_VALUE;}
        
        else
        { 
            int tempTotal;
            int returnValue = Integer.MAX_VALUE;
            
            currentVertex.setVistited(true);
            haventBeenVisited.remove(currentVertex);
            vertexVisits++;
            PriorityQueue<Edge> edges = new PriorityQueue<Edge>(currentVertex.getEdges());
            
            //Use prioritized edges of current vertex and try every possible edge, take minimum of path.
            for(int i = 0; i <= edges.size(); i++)
            {	
            	Edge edge = edges.poll();
                tempTotal = optimize(edge.getToVertex(), edge.getWeight()+total);
                returnValue = Math.min(returnValue, tempTotal);
                if(returnValue < min) {min = returnValue;}
            }
            
            vertexVisits--;
            currentVertex.setVistited(false);
            haventBeenVisited.add(currentVertex);
            return min;
        }   
    }
}
