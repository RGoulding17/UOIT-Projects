import java.util.List;

/**
* The ActionDelete class implements a method that
* deletes the user from the given users list
*
* @author  25QARAT
* @version 1.0
* @since   2018-03-15
*/
public class ActionDelete {
	
	/**
	 * delete - Takes the list of current users and the name of the user to remove,
	 *				  checks if the user exists in the current users list and removes it. 
	 *				  If it does not exists return the list back.
	 *			 	
	 * @param  users a list of strings containing user names & info
	 * @param  argument the user to be deleted
	 * @return updated users list with deleted user removed
	 */
	  protected static List<String> delete(List<String> users, String argument) {
		  	//get name from arguments
			String username = argument.substring(0, 15);
		
			for(int i = 0; i<users.size(); i++){
				if(users.get(i).substring(0, 15).trim().toLowerCase().contains(username.trim().toLowerCase())){
					users.remove(i);
				}
			}
		  
			return users;
	  }
}
