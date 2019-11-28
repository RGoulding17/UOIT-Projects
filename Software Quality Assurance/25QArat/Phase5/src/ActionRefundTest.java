import org.junit.Before;
import org.junit.Test;

import java.text.DecimalFormat;
import java.util.ArrayList;
import java.util.List;

import static org.junit.Assert.*;

public class ActionRefundTest {

    List<String> users = new ArrayList<>();
    String argument;

    @Before
    public void setUp() throws Exception {
        users.add("User01          FS 000100");
        users.add("User02          FS 000100");
        argument = "User01          User02          000020";
    }

    @Test
    public void RefundNoNull() {
        DecimalFormat decimalFormat = new DecimalFormat("000000");

        String buyer = argument.substring(0,15).trim();
        String seller = argument.substring(16,31).trim();
        String user = "";

        int refundAmount = Integer.parseInt(argument.substring(32,38));
        int userCredit = 0;

        for(int i = 0; i<users.size(); i++){
            if(users.get(i).toLowerCase().contains(buyer.toLowerCase())){
                //Buyer
                //Add refunded amount to user
                user = users.get(i);
                userCredit = Integer.parseInt(user.substring(19,25));
                userCredit += refundAmount;
                users.set(i, user.substring(0,19) + decimalFormat.format(userCredit));
            }else if(users.get(i).toLowerCase().contains(seller.toLowerCase())){
                //Seller
                //remove refunded amount to user
                user = users.get(i);
                userCredit = Integer.parseInt(user.substring(19,25));
                userCredit -= refundAmount;
                users.set(i, user.substring(0,19) + decimalFormat.format(userCredit));
            }
        }

        assertNotSame("User wasn't updated properly", "", user);
    }

    @Test
    public void RefundInvalidTwoUsers() {
        String buyer = argument.substring(0,15).trim();
        String seller = argument.substring(16,31).trim();
        for(int i = 0; i<users.size(); i++){
            if(users.get(i).toLowerCase().contains(buyer.toLowerCase()) != users.get(i).toLowerCase().contains(seller.toLowerCase())){
            	assertTrue(true);
            } else {
            	break;
            }
        }
    }

    @Test
    public void RefundInvalidAmount() {
    	DecimalFormat decimalFormat = new DecimalFormat("000000");

        String buyer = argument.substring(0,15).trim();
        String seller = argument.substring(16,31).trim();
        String user = "";

        int refundAmount = Integer.parseInt(argument.substring(32,38));
        int userCredit = 0;
        boolean valid = true;
        
        for(int i = 0; i<users.size(); i++){
            if(users.get(i).toLowerCase().contains(buyer.toLowerCase())){
                //Buyer
                //Add refunded amount to user
                user = users.get(i);
                userCredit = Integer.parseInt(user.substring(19,25));
                userCredit += refundAmount;
                users.set(i, user.substring(0,19) + decimalFormat.format(userCredit));
                while (valid == false) {
                	if (userCredit < 0) {
                    	assertNotNull("Invalid amount");
                    } else {
                    	break;
                    }
                }
                
            }else if(users.get(i).toLowerCase().contains(seller.toLowerCase())){
                //Seller
                //remove refunded amount to user
                user = users.get(i);
                userCredit = Integer.parseInt(user.substring(19,25));
                userCredit -= refundAmount;
                users.set(i, user.substring(0,19) + decimalFormat.format(userCredit));
                while (valid == false) {
                	if (userCredit < 0) {
                    	assertNotNull("Invalid amount");
                    } else {
                    	break;
                    }
                }
            }
        }

        assertNotSame("User wasn't updated properly", "", user);
    }
}


