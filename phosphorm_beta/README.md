# How to setup on RPI

RPI3
Debian Strech
ROS Kinetic

## 1.) Install Strech OS
Follow official Strech website

## 2.) Install OF

    sudo apt update
    sudo apt upgrade
    cd
    wget https://openframeworks.cc/versions/v0.11.0/of_v0.11.0_linuxarmv6l_release.tar.gz
    mkdir openFrameworks
    tar vxfz of_v0.11.0_linuxarmv6l_release.tar.gz -C openFrameworks --strip-components 1
    cd /home/pi/openFrameworks/scripts/linux/debian
    sudo ./install_dependencies.sh
    make Release -C /home/pi/openFrameworks/libs/openFrameworksCompiled/project
  
Compile and run example to check if it works 

    cd /home/pi/openFrameworks/examples/graphics/polygonExample
    make
    make run


## 3.) Install ROS


Source: 
https://neverbenever.wordpress.com/2017/12/20/install-ros-and-opencv-in-raspberry-piraspbian-stretch/


    sudo nano /sbin/dphys–swapfile


and change CONF_SWAPSIZE - we do that because rpi3 usually does not have enought RAM to compile ROS


    # set size to absolute value, leaving empty (default) then uses computed value
    # you most likely don't want this, unless you have an special disk situation
    # CONF_SWAPSIZE=100
    CONF_SWAPSIZE=1024


then


    sudo /etc/init.d/dphys-swapfile stop
    sudo /etc/init.d/dphys-swapfile start


**Note: After installing ROS, MUST change swap space from 1024 to 100.**


    sudo apt-get install dirmngr
    sudo sh -c 'echo "deb http://packages.ros.org/ros/ubuntu $(lsb_release -sc) main" > /etc/apt/sources.list.d/ros-latest.list'
    sudo apt-key adv --keyserver hkp://ha.pool.sks-keyservers.net:80 --recv-key 421C365BD9FF1F717815A3895523BAEEB01FA116
    sudo apt-get update
    sudo apt-get upgrade
    sudo apt-get install python-rosdep python-rosinstall-generator python-wstool python-rosinstall build-essential cmake
    sudo rosdep init
    rosdep update
    mkdir ~/ros_catkin_ws
    cd ~/ros_catkin_ws
    rosinstall_generator ros_comm --rosdistro kinetic --deps --wet-only --tar > kinetic-ros_comm-wet.rosinstall
    wstool init -j8 src kinetic-ros_comm-wet.rosinstall
    rosdep install --from-paths src --ignore-src --rosdistro kinetic -y
    sudo mkdir -p /opt/ros/kinetic
    sudo chown pi:pi /opt/ros/kinetic
    ./src/catkin/bin/catkin_make_isolated -j2 --install --install-space /opt/ros/kinetic -DCMAKE_BUILD_TYPE=Release
    source /opt/ros/kinetic/setup.bash



## Compile lidar midi

    mkidr -p ~/catkin_ws/src
    cd ~/catkin_ws/src
    git clone https://github.com/JanezCim/lidar_midi.git
    git clone https://github.com/YDLIDAR/ydlidar_ros.git
    cd ~/catkin_ws/
    rosdep install --from-paths src --ignore-src -r -y
    catkin_make

## Compile phosphorm

    cd ~/openFrameworks/apps
    git clone https://github.com/JanezCim/phosphorm.git
    cd phosphorm/phosphorm_beta
    make
    
##  Run
    roscore
    roslaunch lidar_midi lidar_midi.launch
    ./openFrameworks/apps/myApps/phosphorm_beta/bin/phosphorm_beta
