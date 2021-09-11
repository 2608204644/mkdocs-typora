## WriteUp1

### BUU BRUTE 1

由题目猜测可能是暴力破解

尝试用户名

1 

user 

admin

用户名为admin时提示

![image-20210512192450938](WriteUp.assets/image-20210512192450938.png)

随后使用burpsuit暴力破解

![image-20210512192644717](WriteUp.assets/image-20210512192644717.png)



![image-20210512192629539](WriteUp.assets/image-20210512192629539.png)

线程过多访问失效，修改线程数与访问间隔

![image-20210512193513990](WriteUp.assets/image-20210512193513990.png)

![image-20210512193733007](WriteUp.assets/image-20210512193733007.png)



### BUU SQL COURSE 1

![image-20210512195854748](WriteUp.assets/image-20210512195854748.png)

登录界面寻找sql注入点

![image-20210512195955285](WriteUp.assets/image-20210512195955285.png)

多次尝试，均无法注入

找题解

最终发现sql注入点在网络栏

![image-20210512200220842](WriteUp.assets/image-20210512200220842.png)



进入该页，调用sqlmap

![image-20210512205931686](WriteUp.assets/image-20210512205931686.png)

破解得到密码，填入登录页面，得到flag

![image-20210512210009647](WriteUp.assets/image-20210512210009647.png)



### BUU UPLOAD COURSE 1

![image-20210512210301786](WriteUp.assets/image-20210512210301786.png)

文件上传漏洞，试着上传一句话木马

![image-20210512210354873](WriteUp.assets/image-20210512210354873.png)

上传后得到

![image-20210512210426424](WriteUp.assets/image-20210512210426424.png)

查看源码，推测为php代码

试着采用phar破解

file=phar://uploads/609bd2afe14b9.jpg

![image-20210512210654835](WriteUp.assets/image-20210512210654835.png)

试着获取页面源码

file=index.php

![image-20210512210923100](WriteUp.assets/image-20210512210923100.png)

可能php存在白名单，无法访问其他目录

目录打错了，直接访问post.php就行。。

使用蚁剑连接

![image-20210512212333883](WriteUp.assets/image-20210512212333883.png)

##  writeup2

### BUU CODE REVIEW 1

![image-20210512220800118](WriteUp.assets/image-20210512220800118.png)

题目要求post满足MD5相同值不同的要求，可采用数组绕过，或者采用搜索的方式找到对应值

反序列，自己写一个

![image-20210512221026108](WriteUp.assets/image-20210512221026108.png)

最后填上参数

![image-20210512221112383](WriteUp.assets/image-20210512221112383.png)

取得flag



### BUU XSS COURSE 1

![image-20210513091005172](WriteUp.assets/image-20210513091005172.png)



打开后

![image-20210513091050425](WriteUp.assets/image-20210513091050425.png)

内容被屏蔽，试着查看网络连接内容

![image-20210513091130698](WriteUp.assets/image-20210513091130698.png)

![image-20210513091149460](WriteUp.assets/image-20210513091149460.png)

存在xss注入点，编写绕过规则，

查看源码，构造成功，却没有弹窗

看书，试着构造图片xss注入

![image-20210513194306102](WriteUp.assets/image-20210513194306102.png)

![image-20210513194250360](WriteUp.assets/image-20210513194250360.png)



### [HCTF 2018]WarmUp

![image-20210513221001515](WriteUp.assets/image-20210513221001515.png)

查看源码，



![image-20210513221025481](WriteUp.assets/image-20210513221025481.png)

提示source.php,查看文件

![image-20210513221152141](WriteUp.assets/image-20210513221152141.png)

复制代码查看



![image-20210513220921730](WriteUp.assets/image-20210513220921730.png)

![image-20210513221220107](WriteUp.assets/image-20210513221220107.png)

条件为 非空且是字符串，且经过函数check检查

check存在几个判定

1：需要是非空字符串

2：在白名单内，则通过

mb_strpos($page . '?', '?')第二个？判定不明，

![image-20210513221642719](WriteUp.assets/image-20210513221642719.png)

![image-20210513221716904](C:\Users\Cha\AppData\Roaming\Typora\typora-user-images\image-20210513221716904.png)

显然，？使用错误，第三个参数为默认值0

3：如果？号前存在白名单文件，通过

4：如果经过url解码后？前存在白名单文件通过。

白名单文件为

![image-20210513221920354](WriteUp.assets/image-20210513221920354.png)

存在hint。php访问后得到

![image-20210513221955125](WriteUp.assets/image-20210513221955125.png)

最终构造

![image-20210513222247408](WriteUp.assets/image-20210513222247408-1622876087661.png)

or

![image-20210513222319077](WriteUp.assets/image-20210513222319077.png)

or

![image-20210513222343717](WriteUp.assets/image-20210513222343717.png)

or

![image-20210513222359360](WriteUp.assets/image-20210513222359360.png)

获取flag

?/代表访问hint。php文件下内容

../表示访问上一层目录，四层../代表访问 /var/www/html/hint.php

## WriteUp3

### [极客大挑战 2019]Secret File

![image-20210514195611558](WriteUp.assets/image-20210514195611558.png)

查看源码，不断推进

![image-20210514195723730](WriteUp.assets/image-20210514195723730.png)

存在action.php重定向到end.php,用burpsuit抓包，得到

![image-20210514195820555](WriteUp.assets/image-20210514195820555.png)

进入该页面

http://121d2783-3ec1-48be-83f9-cca36f6a2c9f.node3.buuoj.cn/secr3t.php

![image-20210514195851078](WriteUp.assets/image-20210514195851078.png)

可以看到审计规则，

构造phar://filter/convert.base64-encode/resource=flag.php 读取

得到

![image-20210514200130326](WriteUp.assets/image-20210514200130326.png)

解码得到flag

### [ACTF2020 新生赛]Exec



![image-20210514201212731](WriteUp.assets/image-20210514201212731.png)

输入baidu.com尝试

![image-20210514201313312](WriteUp.assets/image-20210514201313312.png)

尝试使用多条指令

www.baidu.com;echo hello

![image-20210514201413847](WriteUp.assets/image-20210514201413847.png)

![image-20210514201736832](C:\Users\Cha\AppData\Roaming\Typora\typora-user-images\image-20210514201736832.png)

查看各个目录，寻找flag

```
flag{a941a556-54af-40dc-be73-98e66ca5ce47}
```

完

### [GXYCTF2019]Ping Ping Ping

![image-20210514212445252](WriteUp.assets/image-20210514212445252.png)

推测使用ping命令

![image-20210514212518619](WriteUp.assets/image-20210514212518619.png)

返回命令结果，使用管道或者；

[9f907086-8cc8-4dee-a309-9b14b3765fd0.node3.buuoj.cn/?ip=www.baidu.com;ls](http://9f907086-8cc8-4dee-a309-9b14b3765fd0.node3.buuoj.cn/?ip=www.baidu.com;ls)

![image-20210514212559594](WriteUp.assets/image-20210514212559594.png)

[9f907086-8cc8-4dee-a309-9b14b3765fd0.node3.buuoj.cn/?ip=www.baidu.com;echo "xx"](http://9f907086-8cc8-4dee-a309-9b14b3765fd0.node3.buuoj.cn/?ip=www.baidu.com;echo "xx")

![image-20210514212753669](WriteUp.assets/image-20210514212753669.png)

[9f907086-8cc8-4dee-a309-9b14b3765fd0.node3.buuoj.cn/?ip=www.baidu.com;echo xx](http://9f907086-8cc8-4dee-a309-9b14b3765fd0.node3.buuoj.cn/?ip=www.baidu.com;echo xx)

![image-20210514212830809](WriteUp.assets/image-20210514212830809.png)

无法使用空格，尝试使用管道

[9f907086-8cc8-4dee-a309-9b14b3765fd0.node3.buuoj.cn/?ip=www.baidu.com;ls](http://9f907086-8cc8-4dee-a309-9b14b3765fd0.node3.buuoj.cn/?ip=www.baidu.com;ls)

![image-20210514212928234](WriteUp.assets/image-20210514212928234.png)

可知flag在本目录下，使用ls|cat

http://9f907086-8cc8-4dee-a309-9b14b3765fd0.node3.buuoj.cn/?ip=www.baidu.com;ls|cat

![image-20210514213138315](WriteUp.assets/image-20210514213138315.png)

。。。。

经过测试，这个命令只在Windows下可执行，Linux下只会输出目录

查看题解

使用

1. ${IFS}替换
2. $IFS$1替换
3. ${IFS替换
4. %20替换
5. <和<>重定向符替换
6. %09替换

reference

[有关[GXYCTF2019\]Ping Ping Ping 做题总结_孙得劲的博客-CSDN博客](https://blog.csdn.net/qq_46184013/article/details/107061110)

### [HCTF 2018]admin

![image-20210521194247517](WriteUp.assets/image-20210521194247517.png)

在登录页面与注册页面尝试使用SQL注入，未找到注入点

![image-20210521194735626](WriteUp.assets/image-20210521194735626.png)

![image-20210521194746848](WriteUp.assets/image-20210521194746848.png)

尝试注册一个账号并登录。

观察各个页面，发现在修改密码页面存在github项目，



![image-20210521193950828](WriteUp.assets/image-20210521193950828.png)

打开GitHub页面

![image-20210521194124041](WriteUp.assets/image-20210521194124041.png)

存在一个user.sql

![image-20210521194149546](WriteUp.assets/image-20210521194149546.png)

存在账号密码，尝试破解sha1密码。

![image-20210521212623725](WriteUp.assets/image-20210521212623725.png)

python环境配置一直出错，这个GitHub项目太老了

放弃，寻找题解yo

[HCTF2018-admin_迷风小白-CSDN博客](https://blog.csdn.net/weixin_44677409/article/details/100733581)

存在三种解法



1. flask session 伪造

2. unicode欺骗

3. 条件竞争

   总结：应了解flask的搭建机制，加强python代码能力

   注册ᴬᴰᴹᴵᴺ账号，实现admin修改

   

![image-20210521214446240](WriteUp.assets/image-20210521214446240.png)



### [ACTF2020 新生赛]BackupFile

![image-20210521220052815](WriteUp.assets/image-20210521220052815.png)

备份文件，使用burpsuit爆破、

![image-20210521220037146](WriteUp.assets/image-20210521220037146.png)

![image-20210521220302353](WriteUp.assets/image-20210521220302353.png)

得到

![image-20210521220627083](WriteUp.assets/image-20210521220627083.png)

构造key=“123”即可

[3a4ae4e2-e051-4f38-86ed-45aeeeaab93c.node3.buuoj.cn/index.php?key=123](http://3a4ae4e2-e051-4f38-86ed-45aeeeaab93c.node3.buuoj.cn/index.php?key=123)

得到

![image-20210521220737693](WriteUp.assets/image-20210521220737693.png)

## WriteUp4

### RSA1

![image-20210522213238562](WriteUp.assets/image-20210522213238562.png)

尝试使用python写个程序解码

以我浅薄的数学知识只能想到dp+k1*(p-1)==dq+k2*(q-1)

不会，看密码学writeup

https://blog.csdn.net/qq_32350719/article/details/102719279

![image-20210522231444787](WriteUp.assets/image-20210522231444787.png)





### [极客大挑战 2019]LoveSQL

### 有手就行的sql注入

![image-20210522231306262](WriteUp.assets/image-20210522231306262.png)

![image-20210522231231141](WriteUp.assets/image-20210522231231141.png)

## 

### [ACTF2020 新生赛]Upload

文件上传：

![image-20210523201416247](WriteUp.assets/image-20210523201416247.png)

只允许上传部分格式的图片，尝试burpsuit绕过

![image-20210523201325894](WriteUp.assets/image-20210523201325894.png)

通过修改content—type可以绕过部分，然而服务端似乎会过滤php后缀。如果修改为其他后缀可以正常上传，尝试php3，php4等后缀都不行。

![image-20210523210234326](WriteUp.assets/image-20210523210234326.png)



后缀修改为phtml后成功上传，利用蚁剑访问后台获取flag

![image-20210523211556091](WriteUp.assets/image-20210523211556091.png)

![image-20210523211609575](WriteUp.assets/image-20210523211609575.png)

### [MRCTF2020]你传你🐎呢

![image-20210523220331943](WriteUp.assets/image-20210523220331943.png)

文件上传，尝试使用burpsuit上传文件。限制content_type，为图片，限制php类型后缀，不限制.htaccess。

尝试上传木马，后缀修改为jpg，再通过.htaccess进行配置

![image-20210523220826752](WriteUp.assets/image-20210523220826752.png)

![image-20210523221241305](WriteUp.assets/image-20210523221241305.png)

使用蚁剑连接

![image-20210523221353229](WriteUp.assets/image-20210523221353229.png)

## 尝试写一个Upload-labs的WriteUp

![image-20210524193713593](WriteUp.assets/image-20210524193713593.png)

### Pass01

![image-20210524193822502](WriteUp.assets/image-20210524193822502.png)

使用Javascript，进行校验，尝试修改

![image-20210524193856718](WriteUp.assets/image-20210524193856718.png)

上传webshell

![image-20210524194114970](WriteUp.assets/image-20210524194114970.png)

修改不起作用，尝试禁用js脚本

再次上传webshell，上传成功，查看文件路径，用蚁剑连接

![image-20210524194714455](WriteUp.assets/image-20210524194714455.png)

![image-20210524194656312](WriteUp.assets/image-20210524194656312.png)

### Pass02



![image-20210524195736558](WriteUp.assets/image-20210524195736558.png)

使用burpsuit抓包，并修改MIME类型

附

[常见 MIME 类型列表 - HTTP | MDN (mozilla.org)](https://developer.mozilla.org/zh-CN/docs/Web/HTTP/Basics_of_HTTP/MIME_types/Common_types)

![image-20210524195930263](WriteUp.assets/image-20210524195930263.png)



![image-20210524195939466](C:\Users\Cha\AppData\Roaming\Typora\typora-user-images\image-20210524195939466.png)

### Pass03

![image-20210524200053894](WriteUp.assets/image-20210524200053894.png)

修改php后缀为php3，尝试上传

![image-20210524200157072](WriteUp.assets/image-20210524200157072.png)

### Pass04

![image-20210524200256973](WriteUp.assets/image-20210524200256973.png)

00截断尝试

![image-20210524200645670](WriteUp.assets/image-20210524200645670.png)





### Pass05

与04的差异在于.htaccess

.htaccess文件(或者"分布式配置文件"）,全称是Hypertext Access(超文本入口)。提供了针对目录改变配置的方法， 即，在一个特定的文档目录中放置一个包含一个或多个指令的文件， 以作用于此目录及其所有子目录。作为用户，所能使用的命令受到限制。管理员可以通过Apache的[AllowOverride](https://baike.baidu.com/item/AllowOverride)指令来设置。

概述来说，htaccess文件是[Apache](https://baike.baidu.com/item/Apache)服务器中的一个配置文件，它负责相关目录下的网页配置。通过htaccess文件，可以帮我们实现：网页[301重定向](https://baike.baidu.com/item/301重定向)、自定义404错误页面、改变文件扩展名、允许/阻止特定的用户或者目录的访问、禁止目录列表、配置默认文档等功能。

Unix、Linux系统或者是任何版本的Apache Web服务器都是支持.htaccess的，但是有的[主机](https://baike.baidu.com/item/主机)服务商可能不允许你自定义自己的.htaccess文件。

[[CTF\].htaccess的使用技巧总结_Y4tacker的博客-CSDN博客](https://blog.csdn.net/solitudi/article/details/116666720)

![image-20210524200746600](WriteUp.assets/image-20210524200746600.png)

00截断再次尝试

经过多次尝试，将php大小写进行修改，绕过规则，成功上传

![image-20210524203441081](WriteUp.assets/image-20210524203441081.png)

### Pass06

![image-20210524203818147](WriteUp.assets/image-20210524203818147.png)

禁止目录，尝试大小写绕过。无法绕过

观察到.htaccess不在目录中

![image-20210524204426325](WriteUp.assets/image-20210524204426325.png)

随机命名，.htaccess不起作用

尝试末尾加上空格

![image-20210524204557292](WriteUp.assets/image-20210524204557292.png)





### Pass07

![image-20210524204627002](WriteUp.assets/image-20210524204627002.png)



![image-20210524205017873](WriteUp.assets/image-20210524205017873.png)

看题解

但是没有对后缀名进行去”.”处理，利用windows特性，会自动去掉后缀名中最后的”.”，可在后缀名中加”.”绕过：

尝试

![image-20210524210406485](WriteUp.assets/image-20210524210406485.png)

上传成功，也能解析，但是为什么带.的php文件仍然能被解析？

![image-20210524210514261](WriteUp.assets/image-20210524210514261.png)

我看了一下，这个目录运行在Debian系统下，所以文件命名后缀的.没有消除，但是php能够解析

待解答



查证得，apache解析漏洞

[Apache-解析漏洞 - 知乎 (zhihu.com)](https://zhuanlan.zhihu.com/p/94604252)

### Pass08

![image-20210524214700298](WriteUp.assets/image-20210524214700298.png)

查看源码

![image-20210524214732787](WriteUp.assets/image-20210524214732787.png)

与上一个相差一个::$DATA

注入灵魂

![image-20210524220958310](WriteUp.assets/image-20210524220958310.png)



### Pass09

![image-20210524221121678](WriteUp.assets/image-20210524221121678.png)

![image-20210524222646212](WriteUp.assets/image-20210524222646212.png)

![image-20210524222711808](WriteUp.assets/image-20210524222711808.png)

根据deldot函数和trim函数

构造.（空格）.

实现绕过

![image-20210524222755896](WriteUp.assets/image-20210524222755896.png)

### Pass10

![image-20210524222743028](WriteUp.assets/image-20210524222743028.png)

![image-20210525180417606](WriteUp.assets/image-20210525180417606.png)

黑名单替换，构造

.pphp3hp3规避

![image-20210525180538865](WriteUp.assets/image-20210525180538865.png)

### Pass11

![image-20210525181611972](WriteUp.assets/image-20210525181611972.png)

![image-20210525181644407](WriteUp.assets/image-20210525181644407.png)

尝试使用00截断，修改保存路径

无法上传，寻找题解，发现是oj平台配置问题，这题有bug

### Pass12

![image-20210525184714206](WriteUp.assets/image-20210525184714206.png)

![image-20210525184727224](WriteUp.assets/image-20210525184727224.png)

与上一题差不多，但是保存路径换成post上传

抓包，使用00截断

![](WriteUp.assets/image-20210525185115860.png)

与上题一样，无法上传



### Pass13

![image-20210525185220744](WriteUp.assets/image-20210525185220744.png)

上传简单的webshell木马

![image-20210525194649407](WriteUp.assets/image-20210525194649407.png)

缺少文件包含漏洞，所以无法使用

### Pass14

![image-20210525194819338](WriteUp.assets/image-20210525194819338.png)

提示使用getimagesize

上传图片马正常绕过

![image-20210525194908860](WriteUp.assets/image-20210525194908860.png)

### Pass15

![image-20210525194934104](WriteUp.assets/image-20210525194934104.png)

图片马还是能过

### Pass16

![image-20210525200632256](WriteUp.assets/image-20210525200632256.png)

三种校验，拓展名，content_type，imagecreatefromjpeg。

burpsuit修改

imagecreatefrom

![image-20210525201217664](WriteUp.assets/image-20210525201217664.png)

![image-20210525212136975](WriteUp.assets/image-20210525212136975.png)



### Pass17

![image-20210525202655674](WriteUp.assets/image-20210525202655674.png)

先上传文件，如果不符合条件再删除，使用条件竞争

![image-20210525203600775](WriteUp.assets/image-20210525203600775.png)

![image-20210525203610809](WriteUp.assets/image-20210525203610809.png)



![image-20210525202613536](C:\Users\Cha\AppData\Roaming\Typora\typora-user-images\image-20210525202613536.png)



### Pass18

![image-20210525205234603](WriteUp.assets/image-20210525205234603.png)

条件竞争，重复上一步过程



### Pass19

![image-20210525210234939](WriteUp.assets/image-20210525210234939.png)

post %00 截断



### Pass20

![image-20210525213226305](WriteUp.assets/image-20210525213226305.png)

修改mime

使用数组绕过explode

令save_name[1]等于不存在，



![image-20210525213217095](WriteUp.assets/image-20210525213217095.png)

![image-20210525214100486](C:\Users\Cha\Desktop\image-20210525214100486.png)

利用apache解析漏洞解析

## WriteUp5

### [强网杯 2019]随便注

![image-20210527222655757](WriteUp.assets/image-20210527222655757.png)

存在注入点

![image-20210527222727935](WriteUp.assets/image-20210527222727935.png)

存在关键词屏蔽

![image-20210527222749718](WriteUp.assets/image-20210527222749718.png)

使用堆叠注入可用

![image-20210527222837629](WriteUp.assets/image-20210527222837629.png)

考虑使用concat绕过屏蔽词

![image-20210527223942055](WriteUp.assets/image-20210527223942055.png)

```
flag{286532b6-a2f4-4f5c-84de-77f44e11c592}
```

### [极客大挑战 2019]Upload

![image-20210527225127347](WriteUp.assets/image-20210527225127347.png)

修改content—type

![image-20210527225242961](WriteUp.assets/image-20210527225242961.png)

![image-20210527225305988](WriteUp.assets/image-20210527225305988.png)

修改为phtml后缀

![image-20210527225340543](WriteUp.assets/image-20210527225340543.png)

使用js language=php绕过

![image-20210527225605994](WriteUp.assets/image-20210527225605994.png)

蚁剑连接

![image-20210527225839079](WriteUp.assets/image-20210527225839079.png)

writeup

### [极客大挑战 2019]BabySQL

### 1

![image-20210601205551011](WriteUp.assets/image-20210601205551011.png)

![image-20210601205608000](C:\Users\Cha\AppData\Roaming\Typora\typora-user-images\image-20210601205608000.png)

or语句被过滤，替换成||

绕过

![image-20210601205335242](WriteUp.assets/image-20210601205335242.png)

经过尝试，发现or语句被替换为空，于是进行双写

![image-20210601223726773](WriteUp.assets/image-20210601223726773.png)

构造语句

xxx' uniounionn seleselectct 1,2,3  -- +

试出屏蔽词

![image-20210601225939846](WriteUp.assets/image-20210601225939846.png)

![image-20210601224854289](WriteUp.assets/image-20210601224854289.png)

构造1 ’ uniunionon SELECSELECTT extractvalue(1, concat(0x5c,(SELECSELECTT table_name Frfromom infoorrmation_schema.tables whwhereere table_schema=database() limit 1,1))) -- +

爆出表名

![image-20210601231130669](WriteUp.assets/image-20210601231130669.png)

同理

uniunionon SELECSELECTT extractvalue(1, concat(0x5c,(SELECSELECTT GROUP_CONCAT(column_name) Frfromom infoorrmation_schema.columns whwhereere table_name='b4bsql'))) -- +

![image-20210601232219630](WriteUp.assets/image-20210601232219630.png)

1' uniunionon SELECSELECTT extractvalue(1, concat(0x5c,(seselectlect GROUP_CONCAT(passwoorrd) frfromom b4bsql))) -- +

![image-20210601233002404](WriteUp.assets/image-20210601233002404.png)

超过限制

构造

uniunionon selselectect 1,2,group_concat(passwoorrd) frfromom b4bsql -- +

![image-20210601233406244](WriteUp.assets/image-20210601233406244.png)

## Writeup6

### 变异凯撒

![image-20210601233653135](WriteUp.assets/image-20210601233653135.png)

尝试使用凯撒解密方式解密，无法破解

发现存在非字母类型的字符 ，如_ ^等，猜测进行了倒置与ASCII转置 

查看相应ASCII码表

在大小写字母之间存在_ ^

猜测c对应f。

![image-20210601233935337](WriteUp.assets/image-20210601233935337.png)

没找到规律，查看writeup

![image-20210601234156329](C:\Users\Cha\AppData\Roaming\Typora\typora-user-images\image-20210601234156329.png)

存在递进移位

![image-20210601234817700](WriteUp.assets/image-20210601234817700.png)

![image-20210601234728676](WriteUp.assets/image-20210601234728676.png)

### [SUCTF 2019]CheckIn

![image-20210603223055634](WriteUp.assets/image-20210603223055634.png)

![image-20210603223834225](WriteUp.assets/image-20210603223834225.png)

尝试上传jpg，存在图片校验和文件名校验

![image-20210603223342217](WriteUp.assets/image-20210603223342217.png)

尝试上传 图片马，提示<?包含

尝试改为JavaScript 

```
<script language="php">echo "test";</script>
```

![image-20210603223435521](WriteUp.assets/image-20210603223435521.png)

将内容插入图片中

[[SUCTF 2019\]CheckIn_沐目的博客-CSDN博客](https://blog.csdn.net/weixin_44077544/article/details/102688564)

通过给上传脚本加上相应的幻数头字节，可以绕过图片校验函数

[.user.ini文件构成的PHP后门 - phith0n (wooyun.js.org)](https://wooyun.js.org/drops/user.ini文件构成的PHP后门.html)

上传.user.ini

![image-20210603225221118](WriteUp.assets/image-20210603225221118.png)





### [CISCN2019 华北赛区 Day2 Web1]Hack World

![image-20210604231736444](WriteUp.assets/image-20210604231736444.png)

注入存在三种返回值

sql检测

![image-20210604231759470](WriteUp.assets/image-20210604231759470.png)

正常回显

![image-20210604231826139](WriteUp.assets/image-20210604231826139.png)

bool值

![image-20210604231858577](WriteUp.assets/image-20210604231858577.png)

屏蔽词如下

![image-20210604232259311](WriteUp.assets/image-20210604232259311.png)

无法进行联合注入

堆叠注入

进行bool注入用0|ascii(substr((select(flag)from(flag)),1,1))>1

没时间了，今天先睡觉

明天研究python url传输方式

### [BJDCTF2020]Easy MD5

主页

![image-20210602221829619](WriteUp.assets/image-20210602221829619.png)

随机输入内容

![image-20210602222010015](WriteUp.assets/image-20210602222010015.png)

上传password

查看源码，没有收获，

使用扫描器扫描，没有发现，查看题解后发现

![image-20210602221928211](WriteUp.assets/image-20210602221928211.png)

响应头存在提示，绕过md5，联想到之前看过的sql注入的md5 false注入的文章内容如下

![image-20210602222222967](WriteUp.assets/image-20210602222222967.png)

reference ： [【技术分享】MySQL False注入及技巧总结 - 安全客，安全资讯平台 (anquanke.com)](https://www.anquanke.com/post/id/86021)

输入字符串

跳转到该页

![image-20210602222306512](WriteUp.assets/image-20210602222306512.png)

查看源码，发现

![image-20210602222332703](WriteUp.assets/image-20210602222332703.png)

构造http://fe13f452-39f8-43d3-9446-db87abc84281.node3.buuoj.cn/levels91.php?a[]=0&b[]=1

进入到

其实首页跟第二页url都带有levell，可以遍历爆破

![image-20210602222423369](WriteUp.assets/image-20210602222423369.png)

同理，构造数组绕过

![image-20210602223521353](WriteUp.assets/image-20210602223521353.png)

### [极客大挑战 2019]BuyFlag

![image-20210602225321920](WriteUp.assets/image-20210602225321920.png)

![image-20210602225334513](WriteUp.assets/image-20210602225334513.png)

![image-20210602225343062](WriteUp.assets/image-20210602225343062.png)

猜测用户验证，，密码

![image-20210602225416803](WriteUp.assets/image-20210602225416803.png)

![image-20210602225436612](WriteUp.assets/image-20210602225436612.png)

查看源码，

使用burpsuit

使用00截断绕过is_numeric函数

![image-20210602225532797](WriteUp.assets/image-20210602225532797.png)

数字过长采用科学计数法绕过

![image-20210602225731776](WriteUp.assets/image-20210602225731776.png)







flag{cc08177c-5570-4cb4-9df0-8077d40518c2}