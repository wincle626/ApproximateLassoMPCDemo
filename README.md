# Run-time Approximate Lasso MPC Control Demonstration

#### Yun Wu, Joao F. C. Mota, Andrew M. Wallace. Approximate LASSO Model Predictive Control forResource Constrained Systems. Sensor Signal Processing for Defence (SSPD) conference 2020. 

## Project structure:

### 1. BitFiles

#### There three bitstream files for configuring the FPGA. Refer to the paper, only the Proximal Gradient Descent (PGD) solver is implemented. The figure bellow shows the implemented PGD accelerator using AXI Streaming interface with DMA. 

![vivado project snapshot](https://github.com/wincle626/SSPD2020Demo/blob/main/pics/vivadoproj.png)

### 3. PCSW

#### The host PC is running Ubuntu 22.04. The MPCHost is a Matlab project that using the spacecraft MPC model to generate data. The control state update is implemented in Matlab, and the script will send data to the Zynq Ultrascale+ ZCU106 board over Ethernet, and read data back from the board. 

#### The communiation over Ethernet is implemented in C based on socket programming. By adding MEX interface, the compiled mpcclient.mexa64 has the function to send/receive 40 floating point values for this MPC case. 

#### The socket programming example can be found on [www.geeksforgeeks.org](https://www.geeksforgeeks.org/tcp-server-client-implementation-in-c/). 

#### The demo shows figures for both the orientation of a satellite model and the run-time control process. The plotting of satellite refers to the Matlab project of [Display 3D Color NASA Calipso Satellite Model](https://uk.mathworks.com/matlabcentral/fileexchange/71148-display-3d-color-nasa-calipso-satellite-model?requestedDomain=). The run-time control process plots all the states every time step. 
  
### 4. PwrCfg

#### As different approximate MPC schemes consume different power on FPGA, there is a Qt app running on the ARM processor to monitor the power soncumptions at the run-time. In order to run the Qt app, the Qt 6.4.0 library must be compiled for aarch64 architecture (it's included in the Qt folder.). 

#### The Qt app also can locate the bit file and configure the FPGA based on the solution of [Xilinx MPSoC PL programming](https://xilinx-wiki.atlassian.net/wiki/spaces/A/pages/18841847/Solution+ZynqMP+PL+Programming?f=print). In order to use the Qt app to configure the FPGA, the executable file 'fpgautil.elf' MUST be put in the folder '/home/udrc/fpgautil/' for this demo. 
  
### 5. Qt

#### As mentioned the Qt 6.4.0 must used to enable the power monitoring app. The folder contains the compiled library and the script to export the library to system path. The script should be changed to the location where the qt library is. 
  
### 6. ZynqSW
