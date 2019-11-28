import java.text.DecimalFormat;
import java.util.List;

/**
* The ActionRefund class implements a method that
* add's credit from the sellers account to the buyers
* account and removes the credit from the seller
*
* @author  25QARAT
* @version 1.0
* @since   2018-03-15
*/
public class ActionRefund {
	
	/**
	 * refund - Takes a list of users and the info for refunding
	 * 			like buyers name, sellers name, and how much to refund.
	 * 			returns the updated users list
	 *			 	
	 * @param  users a list of strings containing user names & info
	 * @param  argument a string containing refund info
	 * @return updated users list with buyer refunded
	 */
	  public static List<String> refund(List<String> users, String argument) {
		  DecimalFormat decimalFormat = new DecimalFormat("000000");	
		  
		  String buyer = argument.substring(0,15).trim();
		  String seller = argument.substring(16,31).trim();
		  String user;
		
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
		
		  return users;
	  }
}
