### UDP Debug logger

#### Build

```
mkdir -p ~/catkin_ws/src
git clone https://github.com/tac-dog/udp_debug_logger.git
cd  ~/catkin_ws
catkin build
```

#### Run

```
roscore

rosrun udp_logger_pkg example

rosrun plotjuggler plotjuggler
```

plotjugger选择端口9870    json模式,即可看到数据波形
