设计一个栈：符号栈，内含top属性，记录栈顶符号的下标，num属性，记录栈中符号总数，char数组，线性存储符号。

编写它的进出栈操作函数。

Main方法里面定义string类型的二维数组，用于存储LL（1）分析表，只存推导式右边的部分，并且逆序存储。

初始化：输入待检测的语句串，定义char类型指针指向语句串串首，用于记录验证的位置。将 E 入 栈 。

 开始分析：最外层*w**h**i**l**e*循环，以出错或者栈顶符号为，作为结束条件，中间循环先判断栈顶符号是否为终结符号，是的话与char类型指针所指的字符对比，相等的话把栈顶符号pop出去，并且char指针自增，判断栈有没有空，空了的话在、结束，没空的话continue。

如果栈顶符号不是终结符号，查LL（1）分析表，如果分析表的那一项不为空，则先pop栈顶符号，再push分析表里的符号。如果为空，报错。









### 图床配置：

github图床：

{
  "picBed": {
    "current": "github",
    "github": {
      "repo": "znsfox/PicGo",
      "branch": "master",
      "token": "5b625254da85b52e3279e9c82a95dfb7dee93c4a",
      "path": "img/",
      "customUrl": "https://github.com/znsfox/PicGo"
    },
    "uploader": "github",
    "transformer": "path"
  },
  "picgoPlugins": {
    "picgo-plugin-gitee-uploader": true,
    "picgo-plugin-smms-user": true
  }
}

SM.MS:

{
  "picBed": {
    "current": "smms-user",
    "uploader": "smms-user",
    "smms-user": {
      "Authorization": "YNENlBt88rC5l3EIaztUDcq91Jr9rooB"
    },
    "transformer": "path"
  },
  "picgoPlugins": {
    "picgo-plugin-smms-user": true
  }
}