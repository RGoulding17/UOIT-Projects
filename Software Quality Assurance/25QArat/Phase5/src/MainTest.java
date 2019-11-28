import org.junit.Test;

import java.util.List;

import static org.junit.Assert.*;

public class MainTest {

    @Test
    public void CreateUser() {
        List<String> actions = FileController.readFromFile("./files/test/create_user.txt");
        // Test for checking if create user is read
        for(int lineCounter = 0; lineCounter < actions.size(); lineCounter++) {
            String action = actions.get(lineCounter).substring(0, 2);
            assertEquals("User Creation" ,"01", action);
        }
    }

    @Test
    public void DeleteUser() {
        List<String> actions = FileController.readFromFile("./files/test/delete_user.txt");
        // Test for checking if create user is read
        for(int lineCounter = 0; lineCounter < actions.size(); lineCounter++) {
            String action = actions.get(lineCounter).substring(0, 2);
            assertEquals("User Deletion" ,"02", action);
        }
    }

    @Test
    public void Advertise() {
        List<String> actions = FileController.readFromFile("./files/test/advertise.txt");
        // Test for checking if create user is read
        for(int lineCounter = 0; lineCounter < actions.size(); lineCounter++) {
            String action = actions.get(lineCounter).substring(0, 2);
            assertEquals("Advertising" ,"03", action);
        }
    }

    @Test
    public void Bid() {
        List<String> actions = FileController.readFromFile("./files/test/bid.txt");
        // Test for checking if create user is read
        for(int lineCounter = 0; lineCounter < actions.size(); lineCounter++) {
            String action = actions.get(lineCounter).substring(0, 2);
            assertEquals("Bid" ,"04", action);
        }
    }

    @Test
    public void Refund() {
        List<String> actions = FileController.readFromFile("./files/test/refund.txt");
        // Test for checking if create user is read
        for(int lineCounter = 0; lineCounter < actions.size(); lineCounter++) {
            String action = actions.get(lineCounter).substring(0, 2);
            assertEquals("Refund" ,"05", action);
        }
    }
    @Test
    public void AddCredit() {
        List<String> actions = FileController.readFromFile("./files/test/addcredit.txt");
        // Test for checking if create user is read
        for(int lineCounter = 0; lineCounter < actions.size(); lineCounter++) {
            String action = actions.get(lineCounter).substring(0, 2);
            assertEquals("AddCredit" ,"06", action);
        }
    }

    @Test
    public void EOF() {
        List<String> actions = FileController.readFromFile("./files/test/eof.txt");
        // Test for checking if create user is read
        for(int lineCounter = 0; lineCounter < actions.size(); lineCounter++) {
            String action = actions.get(lineCounter).substring(0, 2);
            assertEquals("End of File" ,"00", action);
        }
    }


    @Test
    public void LoopCoverageZero() {
        List<String> actions = FileController.readFromFile("./files/test/loop0.txt");
        int count = 0;
        boolean check = false;
        boolean loop = false;
        
        while(check == true) {
        	if (count == 0) {
        		String action = actions.get(count).substring(0,2);
        		assertTrue(loop);
        		assertEquals("Loops 0 times",action);
        	} else {
        		break;
        	}
        }
        
    }

    @Test
    public void LoopCoverageOne() {
        List<String> actions = FileController.readFromFile("./files/test/loop1.txt");
        int count = 1;
        boolean check = false;
        boolean loop = false;
        
        while(check == true) {
        	if (count == 1) {
        		String action = actions.get(count).substring(0,2);
        		assertTrue("Entered the loop once",loop);
        		assertEquals("Loops 1 times",action);
        	} else {
        		break;
        	}
        }
        
    }

    @Test
    public void LoopCoverageTwo() {
        List<String> actions = FileController.readFromFile("./files/test/loop2.txt");
        boolean check = false;
        boolean loop = false;
        
        while(check == true) {
        	for(int count = 0; count < 2; count++) {
        		String action = actions.get(count).substring(0,2);
        		assertTrue("Entered the loop once",loop);
        		assertEquals("Loops 2 times",action);
        	} 
        }
    }

    @Test
    public void LoopCoverageMany() {
        List<String> actions = FileController.readFromFile("./files/test/loop10.txt");
        boolean check = false;
        boolean loop = false;
        
        while(check == true) {
        	for(int count = 0; count < 10; count++) {
        		String action = actions.get(count).substring(0,2);
        		assertTrue("Entered the loop once",loop);
        		assertEquals("Loops 10 times",action);
        	} 
        }
    }
}