#!/bin/bash
awk '{
    # Count characters
    total_chars += length;
    print total_chars;
    
    # Count words
    total_words += NF;

    # Count lines
    total_lines++;
}
END {
    print "Total characters: " total_chars;
    print "Total words: " total_words;
    print "Total lines: " total_lines;
}' 1.txt

