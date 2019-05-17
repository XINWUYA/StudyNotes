# StudyNotes
主要用于常用的算法、工具、方法的总结

### Algorithm
+ **LRU(Least Recently Used)**：简单模拟实现LRU（最近最久未使用）模式。*注：不保证线程安全*

### C++

+ **Inheritance**：测试继承系统中的构造和析构函数调用的顺序。
+ **unary_function**：一元函数，单输入对应单输出。注：可参考[unary_function和binary_function详解](https://www.cnblogs.com/blueoverflow/p/4738964.html)
+ **binary_function**：二元函数，两输入对应单输出。
+ **unordered_set**：容器unordered_set。

### System
+ **FindAppPathFromRegisterList**：在注册表中查找软件的安装路径，然后通过WinExec启动。*注：需要手动对应一些系统参数*

### Tools
+ **MemoryLeakDectector**：使用crtdbg方法检测c++程序中的内存泄漏，通过_crtBreakAlloc确定内存泄露的位置。*注：能检测大部分的常见内存泄漏*
