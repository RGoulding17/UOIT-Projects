import java.util.List;

/**
* The ActionBid class implements a method that
* updates the bid amount on an item in the items list
*
* @author  25QARAT
* @version 1.0
* @since   2018-03-15
*/
public class ActionBid {
	
	/**
	 * bid - Takes a list of the current items and a string of
	 * 		 the new bid information, returns the updated items list
	 *			 	
	 * @param  items a list of strings containing item names & info
	 * @param  argument the new bid on an item
	 * @return updated items list with new bid
	 */
	  public static List<String> bid(List<String> items, String argument) {  
			String searchTerm = argument.substring(0, 32);	//item we are looking for
			String bidderName = argument.substring(42,58);	//the new bidder's name
			String newBid = argument.substring(58,64);		//the new bid
			
			for(int i = 0; i<items.size(); i++){
				if(items.get(i).toLowerCase().contains(searchTerm.toLowerCase())){		
					items.set(i, argument.substring(0,42) + bidderName + items.get(i).substring(58,62) + newBid);
				}
			}
		  
		 	return items;
	  }
}
