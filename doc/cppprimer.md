## review

|chapter			|reviewed		|finished		|
|-------------------------------|-----------------------|-----------------------|
|	c01. Start		|			|			|
|Part I: The Basics								|
|PI	c02. Vars & Types	|			|                       |
|PI	c03. String Vector Array|			|			|
|PI	c04. Expressions	|			|			|
|PI	c05. Statements		|			|			|
|PI	c06. Functions		|			|			|
|PI	c07. Classes		|X			|			|
|Part II: The C++ Library							|
|PII	c08. The IO Library	|X			|			|
|PII	c09. Sequential Cont.	|X			|			|
|PII	c10. Generic Algo.	|X			|			|
|PII	c11. Associative Cont.	|			|			|
|PII	c12. Dynamic Memory	|X			|			|
|Part III: Tools for Class Authors						|
|PIII	c13. Copy Control	|X			|			|
|PIII	c14. Overloaded Oper.	|			|			|
|PIII	c15. Object-Oriented P.	|X			|			|
|PIII	c16. Templates and Gene.|X			|			|
|Part IV: Advanced Topics							|
|PIV	c17. Specialized Lib.	|			|			|
|PIV	c18. Tools for Large P.	|			|			|
|PIV	c19. Specialized Tools	|			|			|

## stack vs heap
- stack overflow 
-- infinite recursion(turn to recursion)
-- excessively large local variables(turn to heap for big data).
- heap risks
-- memory leak(call delete or turn to smart pointer)
-- dangling pointer(turn to smart pointer, turn to value or avoid ref./pointer to local var.)
-- double free(nullptr immediately after delete or turn to smart pointer)
-- uninitialized Pointer(initialize to nullptr or valid address)
-- memory fragmentation(turn to memory pool or std::vector)

### why using stack
- They don't know how many objects they'll need.
- They don't know the precise type of the objects they need.
- They want to share data between several objects.

## libraries to learn c++
- STL
- Folly, facebook, folly::fbvector, folly::Future
- libuv, Event Loop, I/O
- Intel TBB(Threading Building Blocks)
- Eigen
- boost.Math
- SFML (Simple and Fast Multimedia Library), 2D game
- bgfx, 3D Engin
- boost.Asio, asyn-newwork
- Abseil, google, absl::flat_hash_map
- fmt, printf alternative
- spdlog, high performance log
- nlohmann/json, modern c++
- Range-v3, modern c++
- LLVM, compiler


