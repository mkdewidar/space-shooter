# Space-Shooter

This project was made for the term 2 (year 1) C++ programming module at Nottingham Trent University. It is a vector graphics based space shooter similar to Asteroids. The game engine was created using the cross platform library [SDL 2.0.4](libsdl.org). The game engine was made to be as separate as possible from the actual game objects. This has been achieved to some extent.

The game controls similar to Asteroids with the `W` and `S` changing the speed of the ship and the `A` and `D` rotating it about it's centre. The ship shoots with the `space`. You can quit the game at any time using the `ESC` key.

### Main Features:

* **Entity-Component-System design:**  
The game engine makes use of the popular Entity-Component-System design concept that is popular in game engines such as [Unity](unity3d.com). The engine has 4 main systems (Object Manager, Physics, Renderer, Logic Manager) with a message bus to allow communication between the systems and each other.  
All game objects inherit from a single unified class which provides the basic functionality that is needed by the systems. The object manager is the one that controls when and which game objects are deleted.

* **Separating Axis Theorem collision detection:**  
The game makes use of a specific collision detection algorithm that allows for pixel perfect collision with vector shapes. The algorithm is based on projecting the shapes onto different axis and finding whether there is an overlap between both objects or not. This effectivly simulates the idea of being able to find a line separating two objects. The engine makes use of basic circle collision as a proximity check to ensure the objects are even within a sensible range before the more expensive collision algorithm is ran on the objects.

* **Slot Map implementation:**  
Instead of using the standard C++ `vector` data structure an improved one was built for this project. The data stucture behaves from the outside as a standard dynamic array however on the inside it has a pool of memory locations which are available and assigns objects a place. Whenever the pool of memory locations is full it attempts to allocate another block of memory locations and adds it to the existing pool.

For more information about the implementation details for the specific features check the report and/or the code for the project.

### Build

The project requires [Microsoft Visual Studio](www.visualstudio.com/) to build. The `.sln` file provided is set up to link to the SDL2 library provided in the Space Shooter folder. However the link is not relative and therefore needs to be changed for the project to build correctly.

From the bar at the top navigate to `project > Space Shooter properties > Configuration Properties`. To change the include path go to `C/C++ > General > Additional Include Directories` then click on the option and change the directory such that it points to new path of the files in the SDL2 folder. To change the paths for the linker navigate to `Linker > Input > Additional Dependencies` then select the option and change the directory to the new path.

You can debug (and consequently run) the program by hitting `F5` then confirming the build.
