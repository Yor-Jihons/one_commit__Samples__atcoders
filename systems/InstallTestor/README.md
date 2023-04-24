# InstallTestor

This script helps to install Testor.exe (for C++) to your projects.

## Install

Just set this script IntallTestor.py into the directory which the Testor.exe exists.

## Usage

Call this script with command line arguments.

```
$ python InstallTestor.py list.txt
```

## Commandline Arguments

```
$ python InstallTestor.py <LISTFILEPATH>

<LISTFILEPATH>:
    The list file which was written the data.
```

See also the article "List file".

## List file

Write to a text file in CSV format as the header below.

```
project_name,number_of_tescases
```

```
project_name: The project name.
number_of_testcases: The number of testcases you want to check as test.
```

e.g.
```
project_name,number_of_tescases
A__test1,3
A__test2,5
```
