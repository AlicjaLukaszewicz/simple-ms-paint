# MS Paint Clone

## Table of Contents

- [Description](#description)
- [Features](#features)
- [Demo](#demo)
- [Installation](#installation)
- [Implementation Details](#implementation-details)
- [Dependencies](#dependencies)
- [Contributing](#contributing)

## Description

<img align="right" width="320" src="https://github.com/AlicjaLukaszewicz/simple-ms-paint/assets/134921001/3b12e48d-d5dd-45d4-8e44-7bb3edb339b8">

MS Paint Clone is a desktop application written in C++ using the SFML graphic library. The project aims to replicate basic paint features found in Microsoft Paint while providing a customizable and extensible environment for future development.

## Features

- **Pencil:** Draw freehand using the pencil tool.
- **Eraser:** Erase parts of your drawing with the eraser tool.
- **Fill:** Fill closed regions with a selected color.
- **Color Picker:** Select colors from your drawing.

## Demo

<div align="center">

![MS Paint Clone Demo](https://github.com/AlicjaLukaszewicz/simple-ms-paint/assets/134921001/8977303a-5ebd-40de-b1c5-87face0b4186)

</div>

## Installation

Before running the MS Paint Clone, make sure you have the SFML library installed on your system. Follow the [SFML Installation Tutorial](https://www.sfml-dev.org/tutorials/2.6/start-vc.php) for detailed instructions.

Once SFML is installed, you can build the project using a C++ compiler. Clone the repository and navigate to the project folder:

```bash
git clone https://github.com/AlicjaLukaszewicz/simple-ms-paint.git
cd ms-paint-clone

```

**Note:** If you encounter any issues related to missing `.dll` files when running the executable, make sure to copy the required SFML `.dll` files (such as sfml-graphics-2.dll, sfml-window-2.dll, sfml-system-2.dll, etc.) to the same directory as the `ms_paint_clone.sln` executable.

## Implementation Details
MS Paint Clone is implemented using Object-Oriented Programming (OOP) principles. Each drawing tool is implemented as a separate class, allowing for easy extension and modification. 

The bucket fill feature is implemented using the "flood fill algorithm" (Depth-First Search).

## Dependencies
```SFML``` - Simple and Fast Multimedia Library

## Credit
Icons made by [Freepik](https://www.freepik.com) from [Flaticon](https://www.flaticon.com/)

