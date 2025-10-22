# Autoindex on : feature #

To have autoindex work, we need to create a listing of files, and folders from the requested directory, we could use a simple command to execute the following command to generate the listing.

```sh
tree -H '.' -L 1 --noreport --dirsfirst -T 'Downloads' -s -D --charset utf-8 -I "index.html" -o fold.html
```

* `-H '.'` : prints in HTML format
* `-L level` : is to precise how many level of directory to list
* `-T 'string'` : replace the title and h1 header with string
* `-s` : is to print the size in bytes of each file.
* `-D` : is to print the date of last modification or status change.
* `--dirsfirst` : is to list directories before files
* `--noreport` : is to turn off file/directory count at end of tree listing
* `-I pattern` : is to not include certain files/folders that match pattern
* `-o filename` : is to write output to a file, but in a cgi we should redirect all output to client
