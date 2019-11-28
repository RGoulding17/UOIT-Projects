import java.util.List;

/**
* The ActionCreate class implements a method that
* creates a new user and add's it to the users list
*
* @author  25QARAT
* @version 1.0
* @since   2018-03-15
*/
public class ActionCreate {
	
	/**
	 * create - Takes the list of current users and the name of the user to create,
	 *		    checks if the user exists in the current users list and add's it. 
	 *			If it does exists return the list back.
	 *			 	
	 * @param  users a list of strings containing user names & info
	 * @param  argument the user to be created
	 * @return updated users list with deleted user removed
	 */
	public static List<String> create(List<String> users, String argument){			
		//get info from argument string
		String username = argument.substring(0, 15);
	
		//search for existing name
		boolean alreadyExists = Actions.searchArray(users, username);
		
		//add to users list if new name
		if(alreadyExists == false){
			//append new user data
			//User01          AA 000000
			users.add(argument);
		}
	
		//return the newUsers list
		return users;
	}
}
