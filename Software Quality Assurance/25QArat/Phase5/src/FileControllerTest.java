import org.junit.Before;
import org.junit.Test;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

import static org.junit.Assert.*;

public class FileControllerTest {

    private String fileName;
    private String fileContents;
    private List<String> contents;

    @Before
    public void setUp() throws Exception {
        fileName = "./files/test/file_zerolines.txt";
        fileContents = "";
        contents.add("");
    }


    @Test
    public void writeToFileZero() {
        BufferedWriter fileWriter = null;
        boolean success = false;

        try{
            File logFile = new File(fileName);
            fileWriter = new BufferedWriter(new FileWriter(logFile));

            for(int i = 0; i < contents.size(); i++){
                fileWriter.write(contents.get(i) + "\n");
            }
            success = true;
        }catch(IOException EX){
            System.out.println("ERROR: " + EX.getMessage());
        } finally {
            try{
                fileWriter.close();
            }catch(IOException EX){
                System.out.println("ERROR: " + EX.getMessage());
            }
        }
        assertTrue(success);
    }

    @Test
    public void writeToFileOne() {
        fileName = "./files/test/file_onelines.txt";
        contents.add("One Line");

        BufferedWriter fileWriter = null;
        boolean success = false;

        try{
            File logFile = new File(fileName);
            fileWriter = new BufferedWriter(new FileWriter(logFile));

            for(int i = 0; i < contents.size(); i++){
                fileWriter.write(contents.get(i) + "\n");
            }
            success = true;
        }catch(IOException EX){
            System.out.println("ERROR: " + EX.getMessage());
        } finally {
            try{
                fileWriter.close();
            }catch(IOException EX){
                System.out.println("ERROR: " + EX.getMessage());
            }
        }
        assertTrue(success);
    }

    @Test
    public void writeToFileMany() {
        fileName = "./files/test/file_manylines.txt";
        contents.add("One Line");
        contents.add("Two Lines");
        contents.add("Three Lines");

        BufferedWriter fileWriter = null;
        boolean success = false;

        try{
            File logFile = new File(fileName);
            fileWriter = new BufferedWriter(new FileWriter(logFile));

            for(int i = 0; i < contents.size(); i++){
                fileWriter.write(contents.get(i) + "\n");
            }
            success = true;
        }catch(IOException EX){
            System.out.println("ERROR: " + EX.getMessage());
        } finally {
            try{
                fileWriter.close();
            }catch(IOException EX){
                System.out.println("ERROR: " + EX.getMessage());
            }
        }
        assertTrue(success);
    }

    @Test
    public void readFromFileZero() {
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

        assertNotSame(tempList.size(), 0);
    }

    public void readFromFileOne() {
        fileName = "./files/test/file_onelines.txt";
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

        assertNotSame(tempList.size(), 1);
    }

    public void readFromFileMany() {
        List<String> tempList = new ArrayList<String>();
        fileName = "./files/test/file_manylines.txt";

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

        assertNotSame(tempList.size(), 3);
    }
}