<!--
 * @Author: Yimning 1148967988@qq.com
 * @Date: 2022-07-03 09:58:21
-->
编译完成之后会生成库文件。

一般在运行可执行程序之前，需要注册动态库的路径名。否则会报错。
此时使用时会提示报错的原因是程序运行时候默认在/usr/lib/或者/lib/下寻找这个动态库。
其方法有几种：    
①修改/etc/ld.so.conf文件    
②修改LD_LIBRARY_PATH环境变量    
③将库文件直接拷贝到/lib或者/usr/lib目录下（这两个目录为系统的默认的库路径名）$ sudo cp libcalc.so /usr/lib/    
④创建软链接。软链接的作用是方便文件的快速访问，比如:给一个复杂路径下的文件创建一个软链接，以后就可以通过软链接完成快速访问操作。        
    创建软链接命令格式:ln  -s   源文件路径(使用绝对路径)    软链接
建议与推荐使用环境变量来指定查询的路径。export LD_LIBRARY_PATH=”*****”，引号内为动态库的路径，本质上是把这个环境变量和运行的程序合并在一起成为shell脚本同时运行。
  
run ./test即可  
