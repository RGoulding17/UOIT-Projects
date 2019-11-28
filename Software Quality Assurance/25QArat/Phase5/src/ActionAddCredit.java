import java.text.DecimalFormat;
import java.util.List;

/**
* The ActionAddCredit class implements a method that
* updates the credit amount on an user in the users list
*
* @author  25QARAT
* @version 1.0
* @since   2018-03-15
*/
public class ActionAddCredit {
	
	/**
	 * addCredit - Takes a list of the current users and a string of
	 * 		       the information to add credit, returns the updated users list
	 *			 	
	 * @param  users a list of strings containing user names & info
	 * @param  argument credit to be added and to who
	 * @return updated users list with credit added to user specified
	 */
	  public static List<String> addCredit(List<String> users, String argument) {
		  DecimalFormat decimalFormat = new DecimalFormat("000000");
		  
		  String username = argument.substring(0,15).trim();
		  String user= "";
		  int creditToAdd = Integer.parseInt(argument.substring(19,25));
		  int userCredit = 0;
		  
		  for(int i = 0; i<users.size(); i++){
			  if(users.get(i).toLowerCase().contains(username.toLowerCase())){
				  user = users.get(i);
				  userCredit = Integer.parseInt(user.substring(19,25));
					
				  userCredit += creditToAdd;
					
				  users.set(i, user.substring(0,19) + decimalFormat.format(userCredit));
			  }
		  }
			
		  return users;
	  }
}
