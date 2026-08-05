#!/bin/bash
# Compile code.c into code.exe, run it, then push changes to GitHub

# Step 3: Git add, commit, and push
git add .
git commit -m "Auto-build and push update."
git push origin main
