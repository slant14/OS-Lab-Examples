echo > namelist
echo  "Timur" > namelist
echo "Anna" >> namelist # use >> to append to the file not to overwrite it
echo "Daniil" >> namelist
echo "Ruslan" >> namelist
echo "David" >> namelist

echo "namelist content:"
cat namelist

# sort -r namelist
# sort -r : Sort in reverse
# sort -n : Sort numerically


# sort -r -n namelist > namelist.sorted
sort -r -n < namelist > namelist.sorted

printf "\nnamelist.sorted content:\n"
cat namelist.sorted
