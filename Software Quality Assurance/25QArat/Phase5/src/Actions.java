import java.util.List;

/**
* The Actions class implements a method for each action in the system
* and redirects the action to its own action class.Also contains misc 
* methods that are used in the action classes
* 
* @author  25QARAT
* @version 1.0
* @since   2018-03-15
*/
public class Actions {

	/**
	 * create - Takes the list of current users and the info of the user to create,
	 *		    passes parameters to the ActionCreate class to process the new user
	 *			 	
	 * @param  users a list of strings containing user names & info
	 * @param  argument the new user to create
	 * @return the new list of users
	 */
	protected static List<String> create(List<String> users, String argument) {
		return ActionCreate.create(users, argument);
	}
	
	/**
	 * advertise - Takes the list of current items and the info of the item to advertise,
	 *		  	   passes parameters to the ActionAdvertise class to process the new item
	 *			 	
	 * @param  items a list of strings containing item names & info
	 * @param  argument the new item to advertise
	 * @return the new list of items
	 */
	protected static List<String> advertise(List<String> items, String argument) {
		return ActionAdvertise.advertise(items, argument);
	}

	/**
	 * bid - Takes the list of current items and the info of the item to bid on,
	 *		 passes parameters to the ActionBid class to process the new bid
	 *			 	
	 * @param  items a list of strings containing item names & info
	 * @param  argument the new bid on an item
	 * @return updated items list with new bid
	 */
	protected static List<String> bid(List<String> items, String argument) {
		return ActionBid.bid(items, argument);
	}

	/**
	 * refund - Takes the list of current users and the info of the buyer to be refunded,
	 *		  	as well as the seller refunding. Passes parameters to the ActionRefund
	 *			to process the refund
	 *			 	
	 * @param  items a list of strings containing item names & info
	 * @param  argument the new item to advertise
	 * @return the new list of items
	 */
	protected static List<String> refund(List<String> users, String argument) {
		return ActionRefund.refund(users, argument);
	}
	
	/**
	 * addCredit - Takes the list of current users and the info of the users to add credit to,
	 *		  	   passes parameters to the ActionAddCredit class to process update of the users credit
	 *			 	
	 * @param  users a list of strings containing user names & info
	 * @param  argument credit to be added and to who
	 * @return updated users list with credit added to user specified
	 */
	protected static List<String> addCredit(List<String> users, String argument) {
		return ActionAddCredit.addCredit(users, argument);
	}
	
	/**
	 * delete - Takes the list of current users and the info of the user to delete,
	 *		  	passes parameters to the ActionDelete class to process the deletion of the user
	 *			 	
	 * @param  users a list of strings containing user names & info
	 * @param  argument the user to be deleted
	 * @return the new list of users
	 */
	protected static List<String> delete(List<String> users, String argument) {
		return ActionDelete.delete(users, argument);
	}
	
	/**
	 * searchArray - Takes a list of strings to search through and the string to search for.
	 * 				 if found return a boolean as true
	 *			 	
	 * @param  array list of strings that we are searching through
	 * @param  searchTerm string we are looking for
	 * @return a boolean, true means found, false means not found
	 */
	public static boolean searchArray(List<String> list, String searchTerm){
		 for(int i = 0; i<list.size(); i++){
			 if(list.get(i).toLowerCase().contains(searchTerm.toLowerCase())){
				 //found a match
				 return true;
			 }
		 }
		return false;
	}
}
