import org.junit.Before;
import org.junit.Test;

import java.util.ArrayList;
import java.util.List;

import static org.junit.Assert.*;

public class ActionBidTest {
    List<String> items = new ArrayList<>();
    String argument;

    @Before
    public void setUp() throws Exception {
        items.add("Computer                  User01          N/A             001 000150");
        items.add("Monitor                   User01          N/A             030 000200");
        argument = "Computer                  User01          User01          000060";
    }

    @Test
    public void bidItemExists() {
        String searchTerm = argument.substring(0, 32);	//item we are looking for
        String bidderName = argument.substring(42,58);	//the new bidder's name
        String newBid = argument.substring(58,64);		//the new bid
        boolean found = false;

        for(int i = 0; i<items.size(); i++){
            if(items.get(i).toLowerCase().contains(searchTerm.toLowerCase())){
                found = true;
                assertTrue("Item Exists", items.get(i).toLowerCase().contains(searchTerm.toLowerCase()));
            }
        }
        assertTrue(found);
    }

    @Test
    public void bidItemUpdated() {
        String searchTerm = argument.substring(0, 32);	//item we are looking for
        String bidderName = argument.substring(42,58);	//the new bidder's name
        String newBid = argument.substring(58,64);		//the new bid

        String itemOld = "", itemNew = "";
        for(int i = 0; i<items.size(); i++){
            if(items.get(i).toLowerCase().contains(searchTerm.toLowerCase())){
                itemOld = items.get(i);
                items.set(i, argument.substring(0,42) + bidderName + items.get(i).substring(58,62) + newBid);
                itemNew = items.get(i);
            }
        }
        assertNotSame("Different Item Bids", itemOld, itemNew);
    }
}