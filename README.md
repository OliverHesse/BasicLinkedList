"# BasicLinkedList" 
Allows for danyamicly typed linked list
it can store multiple data types at the same time like
[1,2,4.5,"hello"]

to initialise a new linked list you do this
linked_list* new_list = new linked_list

to add data to the list you have to use the push method
new_list->push(data);
be carefull directly putting text in it like
new_list->push("Hello World!");
it treats the data as const char [13] which can cause some issues when retrieving said data
instead store it in either a regular char or string variable then pass the variable like:
std::string new_var = "Hello World!";
new_list->push(new_var);
This shouldnt cause any issues

to print the list just use
new_list->print();

if you want to retrive a piece of data you need two pieces of information. its index and type.
this linked list uses 0 indexing
int x = new_list->get_value<int>(2);
the brackets are the index of the value and int is the type i expect to find. this is why i warned about const char,
since it produces a bad alloc error when trying to cast to string and acts weird if i cast to char. it does work though if you cast it like this
new_list->get_value<char*>(1);
why? i dunno sill trying to work it out.

features im planning on adding. type checking(this wont be there for a while), deleting items, chaniging item value,turning it into a header file and more.

thankyou for reading this small project of mine
