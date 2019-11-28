import java.util.*;

public class App {
  public static void main(String [] args) {
    List<String> arglist = Arrays.asList(args);
    int lastIndex = argslist.size() - 1;
    Collections.reverse(arglist);
    for(String s : arglist) {
        System.out.println(s);
    }
  }

  @Override
  public String toString() {
    return "Ding: this is the main app." + 3.1415;
  }
}