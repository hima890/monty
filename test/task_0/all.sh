for file in *.sh; do
    chmod +x "$file"   # Ensure the script is executable
    ./"$file"          # Run the script
done
