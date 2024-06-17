#!/bin/bash

# Ensure .gitignore file contains the rule to ignore .exe files
echo "*.exe" >> .gitignore

# Remove all .exe files from the Git index (staging area)
git rm --cached *.exe

# Add all changes to the staging area
git add .gitignore

# Commit the changes
git commit -m "Ignored .exe files and removed"

# Push the changes to the remote repository
git push origin main

# To delete the rmexe.sh file present in this directory
rm rmexe.sh
