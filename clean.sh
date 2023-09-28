#!/bin/bash

base_directory=$PWD
RED="\033[31m"
GREEN="\033[32m"
RESET="\033[0m"

echo "Base directory: $base_directory"

# iterate throught "/module" directory
for module_dir in "$base_directory"/module0*; do 
    if [ -d "$module_dir" ]; then
        echo "Executing module: $module_dir"

        # iterate throught "exo" directory
        for ex_dir in "$module_dir"/ex0*; do
            if [ -d "$ex_dir" ]; then
                cd "$ex_dir" || exit 1
                
                make fclean

                if [ $? -eq 0 ]; then
                    echo -e "${GREEN}$ex_dir successfully cleaned${RESET}"
                else
                    echo -e "${RED}$ex_dir error while cleaning${RESET}"
                fi

                cd "$base_directory" || exit 1

            fi
        done
    fi
done
