ASCII Shape Rendering Engine (v2.0)
A high-performance C++ console application that renders geometric shapes using ASCII characters. This version features a Dynamic Memory Buffer, allowing for custom resolutions and optimized memory management. 
🚀 Key Features Dynamic Resolution: 
.Unlike static versions, this engine uses Heap Allocation to generate a screen buffer of any size at runtime.Hollow/Solid .
Toggles: Logic for rendering both hollow shells and solid shapes. 
Linear Algebra Transformations: Includes a frame-rotation algorithm to ensure correct orientation in the terminal.
O(1) Memory Cleanup: Implements strict deallocation logic to prevent memory leaks on the host system. 
🛠 Technical Concepts UsedPointers & Double Pointers (char**): Used to create the 2D dynamic array structure (Array of Pointers). 
Dynamic Memory: Utilizes new and delete[] for efficient RAM usage.
Geometry Math: Implementation of the circle equation 
x^2+y^2=r2 for pixel mapping.
