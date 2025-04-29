#This an empty readme file.

## relation among the four files

		textquery.h	queryresult.h	textquery.cpp	queryresult.cpp
location	include/	include/	src/		src/
ref.		->QR		(none)		->QR		(none)
fwd_dcl		class QR;	(none)		(none)		(none)
cpl_def		(none)		(none)		textquery.h	queryresult.h
						queryresult.h
### notes
QR = QueryResult
fwd_dcl: forward declaration
cpl_def: complete defination - such as #include queryresult.h or put ahead the code 

### why
- fwd_dcl vs cpl_def
-- Forward declaration is only used for defination of pointer or reference of the class.
-- It takes full defination of the very class to constructing an object or visiting members.
- All cpp files must be compiled(build) before link.
g++ -std=c++20 src/main.cpp src/textquery.cpp src/queryresult.cpp -Iinclude -o main
- A declaration of #pragma once should be included on the very top of every head file. 
