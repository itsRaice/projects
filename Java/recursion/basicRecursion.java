
//         Name: Aryan Rai


//  Description: this program reads in a sequence of numbers from standard
//               input until 0 is read, stores the numbers in an array,
//               then finds the minimum number,
//               the sum of numbers at odd indexes,
//               the sum of positive numbers, and
//               the total count of negative numbers using recursion.

import java.io.*;
import java.text.DecimalFormat;

public class Assignment9
{
    public static void main(String[] args)
    {

        // instantiate the array
        double[] numbers = new double[100];
        // index used for the array of numbers to be read
        int i = -1;
        int y = 0;
        
        //formating for answers
        DecimalFormat f = new DecimalFormat("0.00");
        DecimalFormat g = new DecimalFormat("0.0##");
        DecimalFormat h = new DecimalFormat("0.#");
        
        
        // where to save one line of input
        String line;

        // Try-Catch block for input stream and buffered reader io exceptions
        try
        {
            // Create an input stream reader and buffered reader object
        	InputStreamReader isr = new InputStreamReader(System.in);
        	BufferedReader br = new BufferedReader(isr);

            // while or do-While loop to store all integers in the array until 0
            // read in the number as a string and parse to an integer and assign
            // it to array element
        	double x = Double.parseDouble(br.readLine());
        	
        	while(x != 0.0) {
        		numbers[y]=x;
        		x = Double.parseDouble(br.readLine());
        		y++;
        	}

            // Continue iterating until 0 is entered

        } // end of try block

        // Catch an IO Exception and print out that it occurs
        catch (IOException ex)
        {
            System.out.println("IO Exception");
        }

        // Call recursive functions findMin, findSumAtOdd, findPositiveSum,
        // findNegative
        
        System.out.println("The minimum number is " + f.format(findMin(numbers,0,y)));
        
        System.out.println("The sum of numbers at odd indexes is " + g.format(findSumAtOdd(numbers,1,y)));
        
        System.out.println("The sum of positive numbers is " + h.format(findPositiveSum(numbers,0,y)));
        
        System.out.println("The total count of negative numbers is " + findNegative(numbers,0,y));
        
        // Print out results in the required format

    } // End main method

    // Recursive static method to find the smallest number in the array
    public static double findMin(double[] numbers, int startIndex, int endIndex)
    {
    	if (startIndex>=endIndex) {
    		
			return numbers[endIndex];
		}
		
		else if (numbers[startIndex]< findMin(numbers,startIndex+1,endIndex)) {
			
			return numbers[startIndex];
		}
    	
		else return findMin(numbers,startIndex+1,endIndex);
    }
    
    public static double findSumAtOdd(double[] numbers, int startIndex, int endIndex)
    {
		
		
		if (startIndex>=endIndex) {
			
			return 0;
		}
		
		else return numbers[startIndex] + findSumAtOdd(numbers,startIndex+2,endIndex);
        
    }

    // Recursive static method to find the sum of positive numbers in the array
    // between the indexes startIndex and endIndex (parameter)
    public static double findPositiveSum(double[] numbers, int startIndex, int endIndex)
    {
    	if (startIndex>=endIndex) {
    		
    		if (numbers[startIndex]>0) {
    			
    			return numbers[startIndex];
    		}
    		
    		else return 0;
    	}
    	
    	else if (numbers[startIndex]>0) {
    		
    		return numbers[startIndex] + findPositiveSum(numbers,startIndex+1,endIndex);
    	}
    	
    	else return findPositiveSum(numbers,startIndex+1,endIndex);

    }

    // Recursive static method to find how many negative numbers are between the
    // indexes startIndex and endIndex
    public static int findNegative(double[] numbers, int startIndex, int endIndex)
    {
		if (startIndex>=endIndex) {
			
			if (numbers[startIndex]<0) {
				
				return 1;
			}
			
			else return 0;
		}
		
		else if (numbers[startIndex]<0) {
			
			return 1 + findNegative(numbers,startIndex+1,endIndex);
		}
		
		else return findNegative(numbers,startIndex+1,endIndex);

    }
}// End Assignment9 class
