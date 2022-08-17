#!/bin/bash


file_name=$(basename $1 .c)
if gcc $1 -o $file_name.exe
then

echo  $0 $@
shift 1
echo $@
./$file_name.exe $@
else echo "Error" >&2
fi
