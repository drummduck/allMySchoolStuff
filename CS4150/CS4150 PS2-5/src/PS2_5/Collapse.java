package PS2_5;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.Set;

public class Collapse {

	public static void main(String[] args) throws IOException {
		//Member variables
				int numOfPrototypes;
				int numOfLayers;
				int uniqueShapes = 0;
				ArrayList<Node> trees = new ArrayList<Node>();
				BufferedReader buff = new BufferedReader(new InputStreamReader(System.in));
				String line = buff.readLine();
				numOfPrototypes = Integer.parseInt(line.split("\\s")[0]);
				numOfLayers = Integer.parseInt(line.split("\\s")[1]);
				while ((line = buff.readLine()) != null && line != "")
				{
					for(int i = 0; i < numOfLayers; i++)
					{	
						int resistance = Integer.parseInt(line.split("\\s")[i]);
						if(i == 0)
						{
							Node inNode = new Node(resistance);
							trees.add(inNode);
							if(trees.size() == 1) uniqueShapes++;
						}
						else insert(resistance, trees.get(trees.size()-1));
					}
					
					boolean unique = false;
					for(int i = 0; i <= trees.size()-2; i++)
					{
						
						if(isUnique(trees.get(trees.size()-1), trees.get(i)) == true) unique = true;
						
						else
							{
									unique = false;
									break;
							}
						
					}
					
					if(unique) uniqueShapes++;
					
				}
				buff.close();
				
				System.out.println(uniqueShapes);

	}
	
	public static void insert(int resistance, Node currentNode)
	{
		if(resistance > currentNode.data && currentNode.right != null)
		{
			insert(resistance, currentNode.right);
		}
		
		else if(resistance > currentNode.data & currentNode.right == null)
		{
			Node newRight = new Node(resistance);
			currentNode.right = newRight;
		}
		
		else if(resistance < currentNode.data && currentNode.left != null)
		{
			insert(resistance, currentNode.left);
		}
		
		else if (resistance < currentNode.data && currentNode.left == null)
		{
			Node newLeft = new Node(resistance);
			currentNode.left = newLeft;
		}
		
		else if(resistance == currentNode.data)
		{
			return;		//Might be using
		}
			
	}
	
	public static boolean isUnique(Node newRoot, Node oldRoot)
	{
		if(newRoot == null && oldRoot == null) return false;
		
		if((newRoot.left != null && oldRoot.left == null) || (newRoot.left == null && oldRoot.left != null)) return true;
		
		else if((newRoot.right != null && oldRoot.right == null) || (newRoot.right == null && oldRoot.right != null)) return true;
		
		else
		{
			boolean left = false;
			boolean right = false;
			
			left = isUnique(newRoot.left, oldRoot.left);
			right = isUnique(newRoot.right, oldRoot.right);
			
			if(left || right)
			{
				return true;
			}
			
			else
				return false;
		}
	}

}
