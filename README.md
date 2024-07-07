# LRU Page Replacement Algorithm Visualization using OpenGL

This project showcases a graphical visualization of the Least Recently Used (LRU) page replacement algorithm using OpenGL. The LRU algorithm is an essential memory management technique in operating systems that replaces the least recently used page when new pages need to be loaded into full memory. This project aims to provide an educational tool that visually demonstrates how the LRU algorithm works in a step-by-step manner.

## Features

Graphical Visualization: Observe the LRU algorithm in action with real-time graphics.
Interactive Interface: Manually step through the algorithm or run the sequence automatically.
Page Reference Input: Input a sequence of page references for simulation.
Performance Metrics: Display statistics such as the number of page faults and hit/miss ratio.
Customization: Change background and tile colors through a context menu.

## How It Works

Initialization: Set up the OpenGL environment and define memory frames.
Page References: Input a sequence of page references to simulate memory access.
Algorithm Execution: Visualize each step as pages are referenced and replaced using the LRU algorithm.
Rendering: Continuously update the display to show the current state of memory, highlighting page faults and replacements.
User Interaction: Step through each reference or run the entire sequence automatically.

## Visualization

Memory Frames: Represent memory frames and their contents graphically.
Page Faults: Highlight and animate page faults and replacements for better understanding.
Real-Time Updates: Observe changes in memory and track the least recently used pages.
This project is an excellent educational tool for students and enthusiasts to understand the workings of the LRU page replacement algorithm through an engaging and interactive graphical interface.

## Getting Started

**Prerequisites**
Code::Blocks IDE
OpenGL and GLUT libraries installed on your system

**Installation and Setup**
Clone the Repository:

> git clone https://github.com/yourusername/LRU-Page-Replacement-OpenGL.git
> <br />

Open the Project in Code::Blocks:
Launch Code::Blocks.
Go to File > Open... and navigate to the cloned repository directory.
Open the main.cpp project file.

**Configure OpenGL and GLUT:\***

Ensure that OpenGL and GLUT libraries are installed on your system. If not, follow these steps:

**For Windows:**

Download and install FreeGLUT.
Configure Code::Blocks to link against the GLUT and OpenGL libraries:
Go to Settings > Compiler... > Linker settings.
Add the following libraries:

> libopengl32.a
> <br />

> libglut32.a

**For Linux:**

> sudo apt-get install freeglut3 freeglut3-dev
> <br />

> sudo apt-get install binutils-gold

**For macOS:**

> brew install freeglut
> <br />

Build and Run the Project:

In Code::Blocks, click on the Build menu and select Build or press F9 to compile the project.
After a successful build, click on Build > Run to execute the program.
Now, you should see the graphical interface demonstrating the LRU page replacement algorithm.
