# OS Project
## Shell-project
  - [X] command parser
  - [x] copy
  
  To be continued...

  ---
## Command
  - quit
    - terminating shell and exit
  - copy #{param_1} #{param_2}
    - copy file param_1 and paste it into param_2
    - return 1, if success
    - return -2, if there is no file param_1
    - return -2, if there already exists param_2
  
  ---
  ## Compile
  ```
  gcc ./Source/copy.c ./Source/shell.c -o shell
  