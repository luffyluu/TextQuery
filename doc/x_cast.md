## static_cast
- 用途：用于相关类型之间的转换（如基本类型转换；类层次中的上行转换）
- 特点：
-- 编译时检查，无运行时开销
-- 不能去除const或vilatile属性
- 示例
```cpp
double d = 3.14;
int i = static_cast<int>(d);
Base* b = static_cast<Base*>(new Derived());
```
## dynamic_cast
- 用途：用于多态类型的向下转换
- 特点：
-- 运行时检查，失败返回nullptr（指针）或抛出异常（引用）
-- 需要基类有虚函数（RTTI支持）
- 示例
```cpp
Base* b = new Derived();
Derived* d = dynamic_cast<Derived*>(b);
if (d) { }
```
## const_cast
- 用途：添加或移除const/volatile属性
- 特点：
-- 不修改底层数据，仅改变类型限定符
-- 修改原为const的对象是未定义行为
- 示例：
```cpp
const int x = 10;
int* p = const_cast<int*>(&x); // 移除const（慎用）
```
## reinterpret_cast
- 用途：低级别位模式重新解释（如指针转整数）
- 特点：
-- 不安全，依赖平台和实现
-- 常用于硬件操作或序列化
- 示例：
```cpp
int i = 42;
char* c = reinterpret_cast<char*>(&i);
## 对比总结
|casting type	|safty	|check timing	|primary use cases			|
|---------------|-------|---------------|---------------------------------------|
|static_cast	|high+	|compile-time	|r.t.c., upcasting in class hierarcky	|
|dynamic_cast	|high	|runtime	|downcasting polymorphic classes	|
|const_cast	|low	|compile-time	|modifying const/volatile qualifiers	|
|reinterpret_	|low-	|compile-time	|forced conversions btw. unrelated types|

high+, relatively high	low-, very low	r.t.c., related type conversions
