#!/bin/bash

# Check if the argument is provided
if [ -z "$1" ]; then
  echo "Usage: $0 <new_folder_name>"
  exit 1
fi

# Name of the new folder
new_folder="$1"

# Check if the template folder exists
if [ ! -d "template" ]; then
  echo "Error: template directory does not exist."
  exit 1
fi

# Check if the new folder already exists
if [ -d "$new_folder" ]; then
  echo "Error: The folder $new_folder already exists."
  exit 1
fi

# Create the new folder
mkdir "$new_folder"

# Copy all the files from template into the new folder
cp template/* "$new_folder/"

# Print a success message
echo "$new_folder Successfully."
