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

The project is built using CMake to generate the makefiles and make to actually build it. The `MakeFile` has been included for convenience. The binary has also been provided in the `bin` folder; it's called `Shooter`.

You will need basic knowledge of how to navigate a terminal to be able to keep up.

#### Running the bin

To run the provided binary you must make sure you have SDL2 installed, you can do this using apt (if you have it):

```sh
sudo apt-get install libsdl2-2.0-0
```

To then run the game run the following commands, provided you are at the root directory:

```sh
cd bin
./Shooter
```

#### Build using the MakeFile

To build it using make (if you really want to) make sure you have SDL2 dev installed, if you don't, it should be available through your favourite package manager. For distros with apt installed:

```sh
sudo apt-get install libsdl2-dev
```

Then move into the root directory for the project and run:

```sh
cd bin
make
```

Modifying the code doesn't require re-running CMake, only Make. If the file structure changes or you add/remove files then you will need to run CMake again.

#### Generating MakeFile using CMake

As mentioned above you will only need to do this if the file structure/directories change, otherwise the MakeFile is still valid.

First ensure you have CMake installed, if you don't you can install using apt:

```sh
sudo apt-get install cmake
```

Then from the root directory of the project enter the following:

```sh
cd bin
cmake ../
```

This will use the CMakeLists.txt file to generate the MakeFile in the bin directory, you can then follow the instructions above to build the project using Make.