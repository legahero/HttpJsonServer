# HttpJsonServer
用QT实现HTTP JSON服务器( http json server by QT)，http 分析部分采用nodejs里面的http-parser（https://github.com/nodejs/http-parser）.

用QT实现HTTP JSON服务器，主要原因是：
1.使用java （servlet、com.sun.net.httpserver）容易反编译，虽然网上提供了一大把的java加密、混淆方案，但总感觉麻烦和不靠谱；
2.其次单点服务器下运行效率java比C++慢；
3.再有运维部署exe程序比web服务器简单（当然你要保证你的程序需要最够稳定）；
4.最后可以使你的json服务与web程序服务完全独立，web的维护不会影响到json服务，这点很重要能够保证你的系统不至于在web运维期间完全瘫痪。
5.选择QT来实现，编程速度比其他的C++快，windows、linux兼容性好。

这里边需要解决几个问题：
1.	框架的业务实现部分必须最够简单，业务部分容易实现和扩充；
2.	高效多线程并发处理必须最够强；
3.	体量小，CPU、内存占用小，能够长时间稳定运行；

write by QQ:502706647
开源不易，承接软件定制开发，有需求联系我QQ:502706647
