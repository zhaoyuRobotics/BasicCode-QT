## 本代码用于记录以下情况用法： ##  

### 当有两个或多个界面控件布局大体相同， 但仅仅是一些成员变量，界面显示，信号槽传递不同的话，就可以将界面封装成一个类，将其可变得抽取出来，在主界面实例化两个对象，通过set ,get 来进行不同的操作，这样可以大大利用重复代码，提高开发效率 ###  

### 环境：Qt：5.5.1 linux ###  
### 说明：Tabwidget中有两页都是一样的控件界面，只不过界面显示的不同，图片也不同 主要看Form类的头文件中几个set,get函数 ###  
  
  
<div align=center>
<img src="https://github.com/zhaoyuRobotics/QT/blob/master/ModuleSameGui/image/Modular_same_interface.gif" width="862" height="584" align=center/>
</div>




