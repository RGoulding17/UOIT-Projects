import static org.junit.Assert.*;

import java.text.DecimalFormat;
import java.util.ArrayList;
import java.util.List;

import org.junit.Before;
import org.junit.Test;

public class ActionAddCreditTest {
    List<String> users = new ArrayList<>();
    String argument;

    @Before
    public void setUp() throws Exception {
        users.add("User01          FS 000100");
        users.add("User02          FS 000100");
        argument = "User01          AA 000100";
    }

    @Test
    public void addCreditUserExists() {
        DecimalFormat decimalFormat = new DecimalFormat("000000");

        String username = argument.substring(0,15).trim();
        String user= "";
        int creditToAdd = Integer.parseInt(argument.substring(19,25));
        int userCredit = 0;

        for(int i = 0; i<users.size(); i++){
            if(users.get(i).toLowerCase().contains(username.toLowerCase())) {
                assertTrue("User Found!", users.get(i).toLowerCase().contains(username.toLowerCase()));
            }
        }
    }

    @Test
    public void addCreditUserDoesNotExists() {
        argument = "User03          AA 000100";
        DecimalFormat decimalFormat = new DecimalFormat("000000");

        String username = argument.substring(0,15).trim();
        String user= "";
        int creditToAdd = Integer.parseInt(argument.substring(19,25));
        int userCredit = 0;

        for(int i = 0; i<users.size(); i++) {
            if (users.get(i).toLowerCase().contains(username.toLowerCase())) {

            } else {
                assertFalse("User Doesn't exist", users.get(i).toLowerCase().contains(username.toLowerCase()));
            }
        }
    }

    @Test
    public void addCreditSuccess() {
        DecimalFormat decimalFormat = new DecimalFormat("000000");

        String username = argument.substring(0,15).trim();
        String user= "";
        int creditToAdd = Integer.parseInt(argument.substring(19,25));
        int userCredit = 0;
        int index = 0;

        String userOld = "", userNew = "";

        for(int i = 0; i<users.size(); i++){
            if(users.get(i).toLowerCase().contains(username.toLowerCase())){
                index =  i;
                userOld = users.get(i);
                user = users.get(i);
                userCredit = Integer.parseInt(user.substring(19,25));

                userCredit += creditToAdd;

                users.set(i, user.substring(0,19) + decimalFormat.format(userCredit));
                userNew = users.get(i);
            }
        }
        assertNotSame("Changed Values", userNew, userOld);
    }
}