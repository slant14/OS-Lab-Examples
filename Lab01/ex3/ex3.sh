nano notes &

jobs

fg

# Write some notes in GNU nano editor
# note 1
# note 2
# note 3

# Suspend the foreground process (Ctrl-T + Ctrl-Z)

jobs

gedit notes.txt &

# Write some notes in gedit
# note 4
# note 5
# note 6

jobs

cat notes > notes.txt


kill %1
kill -9 %2

jobs

# The signal (9) is used to immediately terminate the process without 
# allowing it to clean up or save any data. This signal cannot be ignored
# by the process. Use it if the process does not terminate with only kill
#  command.
