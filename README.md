## HW 2

 - Name: Quoc Nguyen
 - Email: qlnguyen@usc.edu

### Programming Problem Notes

 For each programming problem, let us know:

 - How we should compile your code (`g++` command or `make` target)
    type: make amazon to compile
    ./amazon databaseFileName.txt to use the program.


 - Design decisions you made or other non-trivial choices for your implementation
    Each word longer than 3 letters in Author name, Brand name can be searched.
    Program will either not do anything, or print "Invalid Request" when the user does something wrong.


 - Known errors/anything to help us grade (though we will run automated tests,
knowing what features may be broken/missing may help us provide some partial credit)
    Please make sure to quit AND output to a file to ensure no memory leaks. I added a dumpOut.txt file for this purpose.
    Thank you!
### Description of Program
Takes in a database of items (with quantity and price) and users (with name and budget). Allows users to search for items based on keywords (performing and/or searches) add items to cart, and purchase items too. Program updates quantity and user's budget after each BUYCART.
