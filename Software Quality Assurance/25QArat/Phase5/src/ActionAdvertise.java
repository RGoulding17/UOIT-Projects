import java.util.List;

/**
* The ActionAdvertise class implements a method that
* creates a new item in the items list
*
* @author  25QARAT
* @version 1.0
* @since   2018-03-15
*/
public class ActionAdvertise {
	
	/**
	 * advertise - Takes a list of the current items and a string of
	 * 		       item info to be advertised, returns the updated items list
	 *			 	
	 * @param  items a list of strings containing item names & info
	 * @param  argument the new item to advertise
	 * @return updated items list with new advertised item
	 */
	  public static List<String> advertise(List<String> items, String argument) {
			//add the new item to the list of current items, Add N/A for highest bidder
		  	items.add(argument.substring(0, 42) + String.format("%-16s", "N/A") + argument.substring(42, 52));
		  	
		  	return items;
	  }
}
