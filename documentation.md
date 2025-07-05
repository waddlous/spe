
# Documentation

This is the documentation for spe  
Basically this is where I put the theory stuff  

## Vectors

Vector3 has direction and magnitude in 3 dimensions  
Vector2 has direction and magnitude in 2 dimensions  
The classes are self-written by me(waddlous)  
Vector3 will be used mainly for positioning  
Vector2 will be used for surfaces and camera angle  
(I WILL NOT BE USING QUATERNION)  

## FOV

The central angle that the view point and render screen make  
The wider it is, the view point and render screen get closer  
So at 180 FOV, the view point is inside the render screen  

## Object Points

x   y   z  

Box:  
    0   left    bottom  back  
    1   right   bottom  back  
    2   right   bottom  front  
    3   left    bottom  front  
    4   left    top back  
    5   right   top back  
    6   right   top front  
    7   left    top front  

Octa:  
    0   left    center  back  
    1   right   center  back  
    2   right   center  front  
    3   left    center  front  
    4   N/A bottom  N/A  
    5   N/A top N/A  
