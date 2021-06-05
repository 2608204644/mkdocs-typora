# 课设作业_基于socket的文件加密传输程序.md

### 公共内容

主要内容有实现的DH算法，RSA算法，这些都用C++类实现封装。仅注释接口，具体实现请看代码 

![image-20210605133958696](Other.assets/image-20210605133958696.png)

![image-20210605134006302](Other.assets/image-20210605134006302.png)

### 服务端

socket，用C++类实现封装

使main函数逻辑清晰

![image-20210605134019643](Other.assets/image-20210605134019643.png)

类mySocketServer.cpp,接口

![image-20210605134030986](Other.assets/image-20210605134030986.png)

Main函数

![image-20210605134040627](Other.assets/image-20210605134040627.png)

### 客户端

项目结构

![image-20210605134049202](Other.assets/image-20210605134049202.png)

Mysocket类

 ![image-20210605134102138](Other.assets/image-20210605134102138.png)

Main函数

![image-20210605134112317](Other.assets/image-20210605134112317.png)

### 附件：

[mkdocs-typora/Socket at main · 2608204644/mkdocs-typora (github.com)](https://github.com/2608204644/mkdocs-typora/tree/main/Socket)

### 运行

取D盘文件xx.txt

![image-20210605135153149](Other.assets/image-20210605135153149.png)

同时在本机上运行server跟client

Server：

![image-20210605135243784](Other.assets/image-20210605135243784.png)

Client：

![image-20210605135221792](Other.assets/image-20210605135221792.png)

服务端保存文件在项目目录下的file.txt

![image-20210605135249756](Other.assets/image-20210605135249756.png)