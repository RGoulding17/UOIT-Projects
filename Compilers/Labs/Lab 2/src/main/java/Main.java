import java.util.regex.*;

public class Main {
    public static Pattern importPattern = Pattern.compile("\\s?import ?(static)?\\sjava\\.\\w+\\.(\\*)?(\\w+)?(\\.)?(\\w+)?;\\s?"); // TODO
    public static Pattern classDeclPattern = Pattern.compile("class"); // TODO
    public static Pattern invokePattern = null; // TODO

    public static boolean isValidString(Pattern p, String line) {
        Matcher matcher = p.matcher(line);
        boolean isValid = matcher.matches();
        return isValid;
    }

    public static boolean contains(Pattern p, String line) {
        return p.matcher(line).find();
    }

    public static String[][] findMatches(Pattern p, String line) {
        return null;
    }
    
    public static void main(String... args) {
        System.out.println("Compiled fine");
    }
}
