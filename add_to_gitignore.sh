#!/bin/bash

# GitHub file size limit in bytes (50MB = 54857600 bytes)
LIMIT=50857600

# Name of the gitignore file
GITIGNORE_FILE=".gitignore"

# Create .gitignore if it doesn't exist
if [ ! -f "$GITIGNORE_FILE" ]; then
  touch "$GITIGNORE_FILE"
fi

# Find files larger than the specified limit
find . -type f -size +${LIMIT}c | while read -r file; do
  # Remove leading ./ for consistency
  filepath="${file#./}"
  
  # Check if the file is already in .gitignore
  if ! grep -Fxq "$filepath" "$GITIGNORE_FILE"; then
    echo "$filepath" >> "$GITIGNORE_FILE"
    echo "Added: $filepath"
  else
    echo "Already ignored: $filepath"
  fi
done

