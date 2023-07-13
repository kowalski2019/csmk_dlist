This folder contains mainly data structures that are intended to handle chained lists, double chained lists and another special type of list called "csmk dataList or dlist" that works a bit like a polymorph data structure for lists

# What is DataList ?
DataList as the name says a data structure that works more or less like an ArrayList in java. DataList is generic but a bit limited. It can be used as a Stack, Queue and a normal List.

# How to use the dlist Library ? 

- You must first choose the type of data by replacing the value of "dl_type" in the "DataListType.h" header file
- And finally use the "APPLY_DATATYPE(dataType)" macro with the previously chosen type at the very beginning of your code before you can use the data list


