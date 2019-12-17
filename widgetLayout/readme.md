### 示例程序说明

<div align=center>
<img src="https://github.com/zhaoyuRobotics/QT/blob/Qss/widgetLayout/image/WidgetTest.jpg" width="800" height="500" align=center/>
</div>


**操作说明1**:在主界面WidgetTest，按键1，按键“核炸弹启动”，和GroupBox中设置了样式表
         （注："按键在增加样式表后点击会有橙色框，解决方法是设置padding参数，设置后案件的按下效果就没了，采用的解决办法是设置按键三态（常态，放上，按下）不同效果"）

**操作说明2**：将子界面添加到主界面中的一个TabWidget中（通过再创建一个ui+class），两个类用一个ui文件也可以，但是目标还是想把界面也模块化，之间的数据交互就用信号槽打算

**操作说明3**：在手动布局时，想要控件大小基本按照布局前大小基本不变时，可以调整 策略 和 最大，最小大小；

**操作说明4**：手动代码创建Widget的时候要设置窗体大小才会显示出来，否则默认是按照窗体里面存在的控件大小来决定窗体的大小。





界面盒子模式讲解（padding）：https://www.cnblogs.com/findumars/p/9231730.html

Qss参数整理大全 ：https://blog.csdn.net/u013968786/article/details/51295744

