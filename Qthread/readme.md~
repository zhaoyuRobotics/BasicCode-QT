## 本次笔记得益于熠飞大哥的讲解，醍醐灌顶，感谢！##

## 本笔记主要记录了如何将一个对象的槽函数放在子线程中执行 ## 



以下代码有详细注释，这里强调下核心：  
  

1.定时器对象移到子线程 m_timer->moveToThread(m_thread);  
2.定时器的开启和停止函数依托 connect 的 队列连接 Qt::QueuedConnection 达到开始和停止函数在子线程中执行，不然会报错（定时器的开启和停止需要和对象依附的线程在同一个线程  
3.自定义类对象的槽函数执行时间片断在子线程依托  connect 的 直接连接 Qt::Dirconnection 来达到和定时器发来的信号处于（已处于子线程的Qtimer对象）同一线程  
4.connect 的第五个参数默认是Qt::AutoConnection，表示当槽与触发信号处于同一线程时选用Qt::Dirconnection，否则选用Qt::QueuedConnection .  
  判断的依据是 该对象创建时所依附的线程（包括后面可能将该对象移动到其它线程的情况）
