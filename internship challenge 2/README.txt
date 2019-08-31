# OVERVIEW
this program gives 2 longest strings in a text file [with 1 lowercase string in each new line without spaces], which can be formed by concatenating other smaller strings in the file.


# HOW TO RUN
compile, run and just enter the name (without spaces) of the text file when it asks for input


# COMPILER USED
GCC 8.1.0


# DATA STRUCTURES USED 
as i have to manipulate the dat in the file as a whole, i cant do that directly from a file.
so, i have to store it somewhere. now, performing operations on such big data will be very 
expensive and time consuming. 
i want to perform insertion and searching on this data. i know that only maps in c++ can provide such a low time complexity for this because arrays and vectors will be very expensive in searching. now, i have 2 choices - ordered map and unordered map.

						map 						unordered_map
insertion			O(log n) + rebalancing				O(1) in average case
	
searching 			O(log n) + rebalancing				O(1) in average case

so, i go with "unordered_map"	as they provide direct access of any string in the map
----------
i also use vector to store the input first and sort them because i cant sort an unordered map
and using ordered map will increase my search complexity, which i gave more importance to.



# # # APPROACH USED 
i take input from the file and store it in vector. then sort it in decreasing order of length because i want to get the 2 LONGEST strings, so i'll start from the biggest string first.

then i store the strings into a map, for easy processing. it also removes the duplicates.
i start operating on strings from the vector one by one use a recursive function to check if a string can be made by concatenation of other strings.
it divides the string into 2 parts in every possible way untill it gets exhausted or finds a combination. so, it checks for the left part if it exists in the map and is valid and then checks for the right part also.
the base case is when a string found in the map and is not valid.

in this process, we also add the possible substrings we encounter, to the map, which fail to be made, so that we can use it for subsequent strings and escape reprocessing of the same string. and this is why we also check for validity of string by doing statusMap[s]==0 because we have failed strings also.

the value field in map stores the validity of the string. initially all words are assumed to be valid. 



