#!/bin/bash

# GitHub file size limit in bytes (50MB = 54857600 bytes)
LIMIT=50857600

# Find files over 100 MB and append them to .gitignore
find "$UNIVERSITY_DIR" -type f -size +100M -print >> .gitignore

