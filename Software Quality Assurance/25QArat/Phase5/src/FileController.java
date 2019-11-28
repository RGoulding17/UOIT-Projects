import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

/**
* The FileController class implements a method for reading 
* and writing to files by using lists
* 
* @author  25QARAT
* @version 1.0
* @since   2018-03-15
*/
public class FileController {

	/**
	 * writeToFile - Takes a file name of the file to be read and a list
	 * 				 that contains the new info to be written. Iterates 
	 * 				 through each item and writes it to the file
	 *			 	
	 * @param  fileName the file to be opened and read from
	 * @param  fileContents list of new content to be written
	 * @return nothing
	 */
	public static void writeToFile(String fileName, List<String> contents) {
		BufferedWriter fileWriter = null;
		
		try{
			File logFile = new File(fileName);
			fileWriter = new BufferedWriter(new FileWriter(logFile));
			
			for(int i = 0; i < contents.size(); i++){
				fileWriter.write(contents.get(i) + "\n");
			}
		}catch(IOException EX){
			System.out.println("ERROR: " + EX.getMessage());
		}finally{
			try{
				fileWriter.close();
			}catch(IOException EX){
				System.out.println("ERROR: " + EX.getMessage());
			}
		}
	}

	/**
	 * readFromFile - Takes a file name of the file to be read, then reads
	 * 				  and stores information line by line to a list
	 *			 	
	 * @param  fileName the file to be opened and read from
	 * @return the data read from the file, stored in an list of strings
	 */
	public static List<String> readFromFile(String fileName) {
		List<String> tempList = new ArrayList<String>();
		
		try {
			File file = new File(fileName);
			Scanner fileScanner = new Scanner(file);
	
	        while (fileScanner.hasNextLine()) {
	        	String line = fileScanner.nextLine();
	        	tempList.add(line);
	        }
	        fileScanner.close();
	    } catch (IOException EX) {
			//could not read file, display error
			System.out.println("ERROR: Cannot Open " + EX.getMessage());
		}
		
		return tempList;
	}
}
