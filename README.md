# author_fix

authorsLog.txt was created via:

    cd mne-cpp
    find . -path ./include -prune -o -type f \( -iname \*.h -o -iname \*.cpp -o -iname \*.pro \) -exec echo {} \; -exec sh -c "git log --pretty=format:'%an%x09' {} | sort | uniq " \; > authorsLog.txt
    
The commane above:

- Finds all files with ending .h .cpp and .pro in . folder, excluding the ./include folder
- For all found files executes git blame and extracts unique authors from the output. Also, adds file name after each git blame result.
- Writes result to file
