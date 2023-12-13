Basic cpp filesystem
=====


What is it?
-----------
It's a basic file system, implemented in c++. It imitates the Unix inode file
system with a fake disk (a flat file) and offers several commands.

How do I compile it?
--------------------
With Clang++ 3.3+, simply call "make". You can also use "make debug", in which 
case executing the program will allow it to test some simple test cases. If you
do so, you can pipe the output to another file and diff it with 
'CorrectOutput.txt':

    > make clean
    > make debug
    > ./main fsFile > output
    > diff output CorrectOutput
    
You'll find that the inode numbers are likely different on your system. This is
normal and expected.

How do I run it?
----------------
Although our filesystem is not persistent, you can choose the name of the
working file to ensure it does not clash with any other files in your working
directory.

    Run the program: ./main workingFileName

Since we read commands on stdin and output to stdout and stderr, you can 
redirect input and output as you would any other unix program:
    
    With redirection: ./main filename < inputfile > outputfile

Note that the shell shows a prompt of "sh> " when reading commands, and this
is output even with indirection. Since newlines would normally be entered by
the user, a newline is now appended to each command. Thus, when using 
indirection, expect some "sh> sh> sh> " to be peppered into the output.

What commands can I use?
------------------------
Our basicFS supports many commands:

    open filename mode:
        Open a file and return a file descriptor
            filename: the name of the file; if openning for reading, the 
                      file must exist
                mode: one of w, r, rw:
                      w: open for writing
                      r: open for reading
                      rw: open for reading and writing
        The file descriptor is an integer. If you open a file, close it, and
        reopen it, it is likely the file descriptor will change, so do not 
        rely on their reuse; only use a file descriptor that has been returned
        as the result of open to read, write, seek, and close files.
    
    close fd:
        Closes an open file descriptor fd

    read fd bytes
        Reads bytes from fd, starting from the current position. If bytes
        exceeds the number of bytes in fd, an error is reported. The file
        must be open for reading.

    write fd "some string"
        Writes "some string" to the file pointed to by fd, starting from the
        current location. The file must be open for writing.

    seek fd pos
        Seeks to pos in the file pointed to by fd.

    link src dest
        Creates a new file, dest, that points to the same inode as src. Src and
        dest must be in different directories.

    unlink file
        Removes the link to a given inode ("deletes" this file from a 
        directory). If the inode is no longer pointed to by any file, it is
        deleted, and it's memory is placed back in the free list.

    stat file1 [file2, file3, ...]
        Returns some information about a file or directory.

    cat file
        Prints the contents of a file.

    import src dest
        Imports a text file from the host operating system, giving it the name
        dest.

    export src dest
        Exports the text file src to the host operating system, giving it the
        name dest.

    cp src dest
        Create a new file dest with the same contents as src.

    mkdir dir1 [dir2, dir3, ...]
        Makes a directory by the name given, starting from the current location
        (unless an absolute location is given). Our file system supports "."
        for the current location and ".." for the parent directory.

    rmdir dir1 [dir2, ...]
        Removes the directory by the name given, provided that directory is
        empty.

    cd directory
        Changes the current working directory to the name given

    pwd
        Prints the current working directory path, starting from root.

    ls
        List the contents of the current working directory.

    tree
        List the contents of the current directory and every subdirectory of
        the current directory. File sizes are displayed next to ordinary files
        and links.
