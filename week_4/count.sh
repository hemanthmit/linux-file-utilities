#!/bin/bash
for file in "$*"; do
  if [ ! -f $file ]; then
    echo "File $file does not exist."
    continue
  fi
  echo "Word count for $file:"
  cat "$file" | tr '[:upper:]' '[:lower:]' | tr -cs '[:alpha:]' '\n' | sort | uniq -c | sort -nr
done

