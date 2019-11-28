# Client Requirements
## Description
This file contains a list of requirements that have been specified/clarified via Slack.

## Requirements
### Credit
- A user may have credit of: 0 < x <= 999,999.99 (however, SS can have 0)
- Funds are deducted from an account when the number of days left for an auction item is 0 and they have the highest bid

### Transactions
- Only successful transactions are recorded
- Conatin the most up-to-date balance
- All bids should be added to the daily transaction file
- At the end-of-day, items should be listed with the highest bid for each item

### Accounts
- DELETE: Admins cannot delete admin accounts
- CREATE: If the username is longer than the max (15 chars), simply truncate the extra characters
- SELL-STANDARD: Only SS will have no credit upon creation

- BUY-STANDARD can: login; bid; logout
- SELL-STANDARD can: login; advertise; logout
- FULL-STANDARD can: login; bid; advertise; logout
- ADMIN can: perform all transactions

### Files
- Files can be overwritten (as opposed to generating additional ones) as long as it meets the requirements

### Interface
- Since the interface matters, the program can display text to prompt the user for a username
- No password for login
- For now, a login is only unsuccessful if and only if the username does not exist

