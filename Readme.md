# Compilation times for the Addition kernel:  

```
__kernel void Addition(__global float* input1, __global float* input2, __global float* output)  
{  
	int index = get_global_id(0);  
	output[index] = input1[index] + input2[index];  
}
```  

## AMD Radeon PRO W6800 (OpenCL 2.0 AMD-APP (3354.13)):
| Run | Duration (ms) |
| -  | - |
| 1  | 467.382 |
| 2  | 106.683 |
| 3  | 106.861 |
| 4  | 107.879 |
| 5  | 107.799 |
| 6  | 104.983 |
| 7  | 107.775 |
| 8  | 105.926 |
| 9  | 107.524 |
| 10 | 107.95 |
| -  | - |
| Average| **143.076** |

## AMD Radeon RX 5700 XT (OpenCL 2.0 AMD-APP (3188.4)):
| Run | Duration (ms) |
| -  | - |
| 1  | 2729.53 |
| 2  | 1254.58 |
| 3  | 1242.51 |
| 4  | 1278.31 |
| 5  | 1202.36 |
| 6  | 1269.07 |
| 7  | 1237.95 |
| 8  | 1267.08 |
| 9  | 1252 |
| 10 | 1268.22 |
| -  | - |
| **Average** | **1400.16** |

## AMD Radeon (TM) R9 390 Series (OpenCL 2.0 AMD-APP (3110.7)):  
| Run | Duration (ms) |
| -  | - |
| 1  | 282.61 |
| 2  | 26.6979 |
| 3  | 27.009 |
| 4  | 27.0421 |
| 5  | 26.917 |
| 6  | 28.2667 |
| 7  | 29.3081 |
| 8  | 27.0859 |
| 9  | 25.7717 |
| 10 | 29.2355 |
| -  | - |
| **Average** | **52.9943** |

## Intel(R) Core(TM) i9-7940X CPU @ 3.10GHz (OpenCL 2.1 (Build 0)):  
| Run | Duration (ms) |
| -  | - |
| 1  | 47.1116 |
| 2  | 19.7415 |
| 3  | 18.9358 |
| 4  | 19.5806 |
| 5  | 19.0173 |
| 6  | 19.5361 |
| 7  | 19.1919 |
| 8  | 19.4186 |
| 9  | 19.511 |
| 10 | 19.8893 |
| -  | - |
| **Average** | **22.1934** |

## Nvidia GeForce GTX 1650 (OpenCL 1.2 CUDA):  
| Run | Duration (ms) |
| -  | - |
| 1  | 470.605 |
| 2  | 0.3794 |
| 3  | 0.3591 |
| 4  | 0.2699 |
| 5  | 0.2626 |
| 6  | 0.2632 |
| 7  | 0.2584 |
| 8  | 0.2573 |
| 9  | 0.2595 |
| 10 | 0.2619 |
| -  | - |
| **Average** | **47.3176** |

*Note: The Nvidia driver appears to cache compiled kernels, leading to a more impressive average.*

## Intel(R) UHD Graphics 630 (OpenCL 2.1 NEO ):  
| Run | Duration (ms) |
| -  | - |
| 1  | 647.542 |
| 2  | 319.691 |
| 3  | 315.673 |
| 4  | 322.019 |
| 5  | 317.625 |
| 6  | 319.044 |
| 7  | 319.101 |
| 8  | 364.771 |
| 9  | 347.076 |
| 10 | 382.742 |
| -  | - |
| **Average** | **365.528** |
