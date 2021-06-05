## 搭建开发环境

### VS Code + Clang

sudo apt-get install llvm 

sudo apt-get install clang 

sudo apt-get install libblocksruntime-dev

**VS code Remote-ssh**

```xml
{
    "version": "0.2.0",
    "configurations": [
        {
            "name": "C++ Launch",
            "cwd": "${workspaceFolder}",
            "type": "cppdbg",
            "request": "launch",
            "preLaunchTask": "Build with Clang",
            "program": "${fileDirname}/${fileBasenameNoExtension}.out",
            "stopAtEntry": false,
            "launchCompleteCommand": "exec-run",
            "linux": {
                "MIMode": "gdb",
                "miDebuggerPath": "/usr/bin/gdb"
            },
            "osx": {
                "MIMode": "lldb"
            },
            "windows": {
                "MIMode": "gdb",
                "miDebuggerPath": "C:\\MinGw\\bin\\gdb.exe"
            }
        }
    ],
}
```



```xml
{
    "tasks": [
        {
            "type": "cppbuild",
            "label": "Build with Clang",
            "command": "/usr/bin/clang++",
            "args": [
                "${workspaceFolder}/*.cpp",
                // "${workspaceFolder}/*.h",
                "-std=c++17",
                "-o",
                "${fileDirname}/${fileBasenameNoExtension}.out"
            ], 
            "options": {
                "cwd": "${workspaceFolder}"
            },
            "problemMatcher": [
                "$gcc"
            ],
            "group": {
                "kind": "build",
                "isDefault": true
            },
            "detail": "调试器生成的任务。"
        }
    ],
    "version": "2.0.0"
}
```



**修改Linux SSH端口号**

```
su
vim /etc/ssh/sshd_config
iptables -I INPUT  -p tcp --dport 1542 -j ACCEPT
/etc/init.d/ssh restart
```





## MYSQL  

```
apt install mysql-server
service mysql restart
cat /etc/mysql/debian.cnf
mysql -u debian-sys-maint -p

use mysql;
update mysql.user set authentication_string=password('root') where user='root' and Host ='localhost';
update user set plugin="mysql_native_password"; 
flush privileges;
quit;

service mysql restart
mysql -u root -p
# 新增用户并允许远程访问

GRANT ALL PRIVILEGES ON *.* TO '用户名'@'%'IDENTIFIED BY '密码' WITH GRANT OPTION;
# 刷新
flush privileges;

# 重启MySQL服务
service mysql restart
ifconfig


外部访问，输入IP，用户名密码。
重启时记得service mysql start

```



