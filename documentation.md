
# Documentation

This is the documentation for spe  
Basically this is where I put the theory stuff  

## CMake

I'm not really sure how it works  
I think it builds the project  
Then uses a compiler (gcc in my case) to compile  
Also it uses the copy of SDL in the project  

## Vectors

Vector3 has direction and magnitude in 3 dimensions  
Vector2 has direction and magnitude in 2 dimensions  
The classes are self-written by me(waddlous)  
Vector3 will be used mainly for positioning  
Vector2 will be used for surfaces and camera angle  
(I WILL NOT BE USING QUATERNION)  

### (Applies to all vectors)

I don't want to deal with pointers :/  
So vectors cannot be assigned through pointers  
Use the asterisk to assign through pointers / new  
(as of now, could change later)  

## FOV

The central angle that the view point and render screen make  
The wider it is, the view point and render screen get closer  
So at 180 FOV, the view point is inside the render screen  

## Object Points

object points will be saved as RELATIVE VECTORS
(point[0] = (0,0,0) != any-other-vector = (0,0,0))  
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
