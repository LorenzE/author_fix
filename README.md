# author_fix

authorsLog.txt was created via:

    cd mne-cpp
    find . -path ./include -prune -o -type f \( -iname \*.h -o -iname \*.cpp -o -iname \*.pro \) -exec echo {} \; -exec sh -c "git log --follow --pretty=format:'%an%x09' {} | sort | uniq " \; > authorsLog.txt
    
The commane above:

- Finds all files with ending .h .cpp and .pro in . folder, excluding the ./include folder
- For all found files executes git log and extracts unique authors from the output. Please note that the complete history of the file will be processed, including renamings etc. If this is not wanted just remove the --follow flag in the above command. Also, adds file name after each git log result.
- Writes result to file
