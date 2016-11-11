# Space-Shooter

This project was made for the term 2 (year 1) C++ programming module at Nottingham Trent University. It is a vector graphics based space shooter similar to Asteroids. The game engine was created using the cross platform library [SDL 2.0.4](libsdl.org). The game engine was made to be as separate as possible from the actual game objects. This has been achieved to some extent.

The game controls similar to Asteroids with the `W` and `S` changing the speed of the ship and the `A` and `D` rotating it about it's centre. The ship shoots with the `space`.

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

The project is built using CMake to generate the makefiles and make to actually build it. This version can't be built due to linker/compiler errors as a result of the way the project was originally setup to include each others files. They will be addressed in the next commit.