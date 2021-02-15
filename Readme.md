# Compilation times for the kernel  

> __kernel void Addition(__global float* input1, __global float* input2, __global float* output)  
> {  
> 	int index = get_global_id(0);  
> 	output[index] = input1[index] + input2[index];  
> }  

## Compiling kernel for device AMD Radeon RX 5700 XT (OpenCL 2.0 AMD-APP (3188.4)):
Run 1: 2729.53ms  
Run 2: 1254.58ms  
Run 3: 1242.51ms  
Run 4: 1278.31ms  
Run 5: 1202.36ms  
Run 6: 1269.07ms  
Run 7: 1237.95ms  
Run 8: 1267.08ms  
Run 9: 1252ms  
Run 10: 1268.22ms  
Average: 1400.16ms  

## Compiling kernel for device AMD Radeon (TM) R9 390 Series (OpenCL 2.0 AMD-APP (3110.7)):  
Run 1: 282.61ms  
Run 2: 26.6979ms  
Run 3: 27.009ms  
Run 4: 27.0421ms  
Run 5: 26.917ms  
Run 6: 28.2667ms  
Run 7: 29.3081ms  
Run 8: 27.0859ms  
Run 9: 25.7717ms  
Run 10: 29.2355ms  
Average: 52.9943ms  

## Compiling kernel for device Intel(R) Core(TM) i9-7940X CPU @ 3.10GHz (OpenCL 2.1 (Build 0)):
Run 1: 47.1116ms  
Run 2: 19.7415ms  
Run 3: 18.9358ms  
Run 4: 19.5806ms  
Run 5: 19.0173ms  
Run 6: 19.5361ms  
Run 7: 19.1919ms  
Run 8: 19.4186ms  
Run 9: 19.511ms  
Run 10: 19.8893ms  
Average: 22.1934ms  

## Compiling kernel for device GeForce GTX 1650 (OpenCL 1.2 CUDA):
Run 1: 470.605ms  
Run 2: 0.3794ms  
Run 3: 0.3591ms  
Run 4: 0.2699ms  
Run 5: 0.2626ms  
Run 6: 0.2632ms  
Run 7: 0.2584ms  
Run 8: 0.2573ms  
Run 9: 0.2595ms  
Run 10: 0.2619ms  
Average: 47.3176ms  

## Compiling kernel for device Intel(R) UHD Graphics 630 (OpenCL 2.1 NEO ):
Run 1: 647.542ms  
Run 2: 319.691ms  
Run 3: 315.673ms  
Run 4: 322.019ms  
Run 5: 317.625ms  
Run 6: 319.044ms  
Run 7: 319.101ms  
Run 8: 364.771ms  
Run 9: 347.076ms  
Run 10: 382.742ms  
Average: 365.528ms  
