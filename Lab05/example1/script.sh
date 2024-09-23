#!/bin/bash

# In case of no excution permission: chmod +x script.sh))
if [ $# -ne 1 ]; then
    echo "Wrong argument count!"
    exit 1
fi

message="$1"

for i in {1..10}; do
    echo "Run #$i:"
    ./main "$message" #important: Write the correct name of the executable file of your program!
    echo "-----------------------------"
done
