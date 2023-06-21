# Run-time Approximate Lasso MPC Demonstration

#### Yun Wu, Joao F. C. Mota, Andrew M. Wallace. Approximate LASSO Model Predictive Control forResource Constrained Systems. Sensor Signal Processing for Defence (SSPD) conference 2020. 

## System setup:

### Host PC: Ubuntu 22.04

### ZCU106: Ubuntu 22.04 on SD card (Instructions about how to prepare SD card can be found [here](https://github.com/wincle626/ZCU106_SD_Card_Setup)).

## Project structure:

### 1. BitFiles

#### There three bitstream files for configuring the FPGA. Refer to the paper, only the Proximal Gradient Descent (PGD) solver is implemented. The figure bellow shows the implemented PGD accelerator using AXI Streaming interface with DMA. 

![vivado project snapshot](https://github.com/wincle626/SSPD2020Demo/blob/main/pics/vivadoproj.png)

### 3. PCSW

#### The MPCHost is a Matlab project that using the spacecraft MPC model to generate data. The control state update is implemented in Matlab, and the script will send data to the Zynq Ultrascale+ ZCU106 board over Ethernet, and read data back from the board. 

#### The communiation over Ethernet is implemented in C based on socket programming. By adding MEX interface, the compiled mpcclient.mexa64 has the function to send/receive 40 floating point values for this MPC case. 

#### The socket programming example can be found on [www.geeksforgeeks.org](https://www.geeksforgeeks.org/tcp-server-client-implementation-in-c/). In this demo, the host PC IP is set to 192.168.137.1, while the ZCU106 IP is set to 192.168.137.106. 

#### The demo shows figures for both the orientation of a satellite model and the run-time control process. The plotting of satellite refers to the Matlab project of [Display 3D Color NASA Calipso Satellite Model](https://uk.mathworks.com/matlabcentral/fileexchange/71148-display-3d-color-nasa-calipso-satellite-model?requestedDomain=). The run-time control process plots all the states every time step. 
  
### 4. PwrCfg

#### As different approximate MPC schemes consume different power on FPGA, there is a Qt app 'PowerMonitor' running on the ARM processor to monitor the power soncumptions at the run-time. In order to run the Qt app, the Qt 6.4.0 library must be compiled for aarch64 architecture (it's included in the Qt folder.). 

#### The Qt app also can locate the bit file and configure the FPGA based on the solution of [Xilinx MPSoC PL programming](https://xilinx-wiki.atlassian.net/wiki/spaces/A/pages/18841847/Solution+ZynqMP+PL+Programming?f=print). In order to use the Qt app to configure the FPGA, the executable file 'fpgautil.elf' MUST be put in the folder '/home/udrc/fpgautil/' for this demo. 

#### To run the Qt app, [Putty](https://www.putty.org/) is used to ssh the ZCU106. In order to measure the power and scale the voltage, the ssh must use root identity to remotely connect ZCU106. Or it can also use command line on Ubuntu: ssh -X root@192.168.137.106, with root password. 
  
### 5. Qt

#### As mentioned the Qt 6.4.0 must used to enable the power monitoring app. The folder contains the compiled library and the script to export the library to system path. The script should be changed according to the location where the qt library is. 
  
### 6. ZynqSW

#### On the ZCU106 board, a simple socket server is running for receive data from host PC, streaming data to/from the PGD accelerator on FPGA, send data back to the host PC. So on the PC side, the Matlab could communicate to the FPGA accelerator over Ethernet. This is a similar solution to [MathWork Simulink](https://uk.mathworks.com/help/hdlcoder/ug/getting-started-with-hardware-software-codesign-workflow-for-zynq-ultrascale-mpsoc-devices.html#d124e132669). 

#### The executable 'mpc_n10_host' can streaming 40 floating point values to and read back from ZCU106 board as well as the Ethernet receive/send communications, while the executable 'mpcn10' is a wrapper that running infinite time of 'mpc_n10_host'. Hence a mini TCP server is running on ARM to connecting FPGA accelerator and the Matlab on PC. 

#### 

## Demo Draft on YouTube

### Spacecraft MPC horizon N=10 Floating point 64 bits

[![Spacecraft MPC horizon N=10 Floating point 64 bits](https://i9.ytimg.com/vi_webp/Q4_9WLV2qkc/mq2.webp?sqp=CPyfy6QG-oaymwEmCMACELQB8quKqQMa8AEB-AH-CIAC0AWKAgwIABABGFYgXyhlMA8=&rs=AOn4CLAkn1tr2Sg-txdKoso0rV6GyzpGow)](https://youtu.be/Q4_9WLV2qkc)

### Spacecraft MPC horizon N=10 fixed point 28 bits

[![Spacecraft MPC horizon N=10 fixed point 28 bits](https://i9.ytimg.com/vi_webp/GR8h1Lunoiw/mq2.webp?sqp=CPyfy6QG-oaymwEmCMACELQB8quKqQMa8AEB-AH-CIAC0AWKAgwIABABGFYgXyhlMA8=&rs=AOn4CLB3rw22HIuYc6_LVnZJznA4x4fkXw)](https://youtu.be/GR8h1Lunoiw)

