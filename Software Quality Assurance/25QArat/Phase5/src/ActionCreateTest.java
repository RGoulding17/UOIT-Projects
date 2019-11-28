import org.junit.Before;
import org.junit.Test;

import java.util.ArrayList;
import java.util.List;

import static org.junit.Assert.*;

public class ActionCreateTest {

    List<String> users = new ArrayList<>();
    String argument;

    @Before
    public void setUp() throws Exception {
        users.add("User01          FS 000100");
        users.add("User02          FS 000100");
        argument = "User04          FS 000100";
    }


    @Test
    public void userNotExist() {
        //get info from argument string
        String username = argument.substring(0, 15);

        //search for existing name
        boolean alreadyExists = Actions.searchArray(users, username);
        assertFalse(alreadyExists);

        //add to users list if new name
        if(alreadyExists == false){
            //append new user data
            //User01          AA 000000
            users.add(argument);
        }
    }

    @Test
    public void userSuccessAdded() {
        //get info from argument string
        String username = argument.substring(0, 15);

        String userLast = users.get(users.size() - 1);
        //search for existing name
        boolean alreadyExists = Actions.searchArray(users, username);

        //add to users list if new name
        if(alreadyExists == false){
            //append new user data
            //User01          AA 000000
            users.add(argument);
        }
        String userLastNew = users.get(users.size() - 1);

        assertNotSame("Different Users", userLast, userLastNew);
    }

}