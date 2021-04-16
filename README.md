# Chess in SFML
## Language and framework used
Developed entirely in **C++** using the **SFML** library and compiled in **Visual Studio Code**.
## Supported OS for Automatic Builds
**Windows**, since the provided SFML library in the repo is for Windows, that too targeting **32-bit** platform, but even if you have a **64-bit** platform you can use the automatic build.
## Manual Build
- For manually building the project, just download the latest stable version of the SFML library from [downloads](https://www.sfml-dev.org/download.php) for your OS and follow the steps from the [documentation](https://www.sfml-dev.org/learn.php),  it is quite easy to follow.
- Also don't forget to move the **"main"** application file after building to **"Builds"** folder for a successful run
> **Note: I highly suggest you to use Visual Studio for building this project since it is quite simple to set all the required properties in it**
## Automatic Build
- For building automatically, you should have any **Microsoft Windows** OS and a **32-bit** _mingw_
- In case you have a **64-bit compiler**, just download the 64-bit headers and linking files from [this site](https://www.sfml-dev.org/download.php) and replace the files in the directory for a successful build
- If you have some **other compiler (like Visual C++)** then you can replace the files in the directory by downloading the headers and linking files from [this site](https://www.sfml-dev.org/download.php) or you can simply install [mingw](https://sourceforge.net/projects/mingw/)
> **Note: The project would not build with 64-bit compilers if you don't replace the files**

- When everything is done, **compile the "build.cpp" file** by the following command:
> `g++ build.cpp -o build.exe`
- When everything is done, just open a **command prompt window** in the **working directory** and build using the following command:
> `build main`

The above command will build the **main.cpp** and automatically run it. It is quite important to know that it is not limited for just building **main.cpp**. For eg, if you want to build a file **scan.cpp** then you can issue the following command:
> `build scan`

Basically
> `build fileName` 
for any fileName.cpp

You can also build multiple files
> `build fileName1 fileName2 fileName3 ...`

Be sure to not build and use **build.cpp** for any other OS except **Windows** as it will be of no use.

## Behind the scenes
Why did you choose **chess**? Why use **SFML** when there are better alternatives like **ImGui**, **GuiLite** or **OpenGL**? I know all of this stuff, but this is my first public repo and I really didn't have any great ideas back in the day. Any feedbacks or suggestions would be open-handedly accepted.

## Motivation
In short, the chess game! I like it and I have played it a lot in my childhood days.

## 