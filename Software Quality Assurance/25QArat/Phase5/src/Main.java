import java.util.ArrayList;
import java.util.List;

public class Main {

	public static void main(String[] args) {
        if (args.length < 3) {
            System.out.println("Improper use of code!");
            System.out.println("Run it as \"java Main daily_transaction.txt items.txt users.txt");
        } else {
            System.out.println("UPDATING WITH DAILY TRANSACTIONS...");

            //local variables to hold the data from the three files
            List<String> actions = new ArrayList<String>();
            List<String> users = new ArrayList<String>();
            List<String> items = new ArrayList<String>();

            String action = "";        //holds the inputed action from the transaction file
            String argument = "";    //holds the following arguments of said action

            //read through each line and store it in an array of strings
            actions = FileController.readFromFile(args[0]);

            //read through each line in the items file and store it in
            items = FileController.readFromFile(args[1]);

            //read through each line in the users file and store it in
            users = FileController.readFromFile(args[2]);

            //try-catch starts here
            try {
                //begin running through command array
                for (int lineCounter = 0; lineCounter < actions.size(); lineCounter++) {
                    //separate number from rest of string
                    action = actions.get(lineCounter).substring(0, 2);
                    argument = actions.get(lineCounter).substring(3);

                    //decide which action is being executed
                    if (action.equals("00")) {
                        //END OF FILE
                        System.out.println("EOF reached");
                        break;
                    } else if (action.equals("01")) {
                        //create - 01
                        users = Actions.create(users, argument);
                    } else if (action.equals("02")) {
                        //delete - 02
                        Actions.delete(users, argument);
                    } else if (action.equals("03")) {
                        //advertise - 03
                        Actions.advertise(items, argument);
                    } else if (action.equals("04")) {
                        //bid - 04
                        Actions.bid(items, argument);
                    } else if (action.equals("05")) {
                        //refund - 05
                        Actions.refund(users, argument);
                    } else if (action.equals("06")) {
                        //addcredit - 06
                        Actions.addCredit(users, argument);
                    } else if (action.equals("10")){
                        //Login
                        //System.out.println("ERROR: Bad Input, action type could not be identified");
                    } else if (action.equals("00")) {
                        //logout
                    } else {
                        System.out.println("ERROR: Bad Input, action type could not be identified");
                    }
                }
            } catch (Exception EX) {
                //catch runtime errors
                System.out.println("ERROR: " + EX.getMessage());
            }

            //write new content line by line to the "new" versions of the files
            FileController.writeToFile(args[2], users);
            FileController.writeToFile(args[1], items);

            System.out.println("UPDATE COMPLETE");
        }
    }
}
