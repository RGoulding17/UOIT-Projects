# CSCI 3060U - Project - Genesis
## Group Members
- [Betty Kwong](https://github.com/bunnehbetz)
- [Devon McGrath](https://github.com/DevonMcGrath)
- [Martin Tuzim](https://github.com/Nomulous)

## Front-End
### Compile
1. Download/clone the repository
1. Navigate to `/csci3060u/src/frontend/` in a terminal
1. Run `make`

### Usage
The front-end can be used in various ways and the executable `./frontend` supports command line arguments. In addition, the standard input stream can be redirected and a file containing the equivalent user input can be used instead (i.e. for testing).

#### General Use
`./frontend <user_accounts_file_path> <items_file_path> <transaction_file_path>`
- Specifies the path to the user accounts file, available items file, and the daily transaction file path to append to
- To run with sample accounts/items files, run `make run-files`

#### Testing
`./frontend -test <user_accounts_file_path> <items_file_path> <transaction_file_path>`
- Specifies the path to the user accounts file, available items file, and the daily transaction file path to append to
- The `-test` flag indicates the the program should only output simple text
