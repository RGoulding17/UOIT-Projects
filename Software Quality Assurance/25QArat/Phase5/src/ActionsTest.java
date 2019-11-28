import org.junit.Test;

import static org.junit.Assert.*;

import java.util.ArrayList;
import java.util.List;


public class ActionsTest {

    //These just call functions
    @Test
    public void create() {
    	boolean fail = true;
    	try {
    		Class.forName("ActionAddCredit");
    	} catch (ClassNotFoundException e) {
    		assertFalse("Class create does not exists.", fail);
    	}
    }


	@Test
    public void advertise() {
		boolean fail = true;
    	try {
    		Class.forName("ActionAdvertise");
    	} catch (ClassNotFoundException e) {
    		assertFalse("Class advertise does not exists.", fail);
    	}
    }

    @Test
    public void bid() {
    	boolean fail = true;
    	try {
    		Class.forName("ActionBid");
    	} catch (ClassNotFoundException e) {
    		assertFalse("Class bid does not exists.", fail);
    	}
    }

    @Test
    public void refund() {
    	boolean fail = true;
    	try {
    		Class.forName("ActionCreate");
    	} catch (ClassNotFoundException e) {
    		assertFalse("Class refund does not exists.", fail);
    	}
    }

    @Test
    public void addCredit() {
    	boolean fail = true;
    	try {
    		Class.forName("ActionAddCredit");
    	} catch (ClassNotFoundException e) {
    		assertFalse("Class addCredit does not exists.", fail);
    	}
    }

    @Test
    public void delete() {
    	boolean fail = true;
    	try {
    		Class.forName("ActionDelete");
    	} catch (ClassNotFoundException e) {
    		assertFalse("Class delete does not exists.", fail);
    	}
    }
    
    @Test
    public void searchArray() {
    	Actions action = new Actions();
    	List<String> list = new ArrayList();
    	String searchTerm = null;
    	boolean search = action.searchArray(list, searchTerm);
    	//boolean search = true;
    	for(int searchArray = 0; searchArray < list.size(); searchArray++) {
            String lists = list.get(searchArray).substring(0, 2);
            assertTrue(search);
            assertEquals("Serach Array", lists);
        }
    	
    }
}