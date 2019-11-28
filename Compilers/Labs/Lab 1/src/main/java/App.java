import java.io.*;
import java.io.*;
import static java.lang.System.*;

public class App {
    public static void main(String[] args) throws Exception {
        if(args.length == 0) {
            out.println("Usage: <filename>");
            exit(0);
        }

        String filename = args[0];

        BufferedReader in = new BufferedReader(new FileReader(filename));

        String line = in.readLine();
        while(line != null) {
            out.println(reverse(line));
            line = in.readLine();
        }
        in.close();
    }

    public static String reverse(String s) {
		byte [] byteString = s.getBytes(); 
  
        byte [] reversedString = new byte [byteString.length]; 

        for (int i = 0; i<byteString.length; i++){
            reversedString[i] = byteString[byteString.length-i-1]; 
		}
  
        return new String(reversedString); 
    }
}