#!/bin/bash

# Path to the university folder
UNIVERSITY_DIR=~/UniversityNotes

# Find files over 100 MB and append them to .gitignore
find "$UNIVERSITY_DIR" -type f -size +100M -print >> .gitignore

