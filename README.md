# **fract-ol - 42 Network**

## **Overview**  
**fract-ol** is a project from the **42 Network** designed to explore **fractals** using **MiniLibX (mlx)**, a simple graphics library. The goal of the project is to render and interact with fractals like the **Mandelbrot set**, **Julia set**, and optionally the **Burning Ship** fractal. This project introduces fundamental concepts in **graphical programming**, including the use of **complex numbers**, **interactive controls**, and **performance optimization**.

## **Project Scope**  
In this project, you will:

- Use **MiniLibX** to create a window and render fractals.
- Implement fractal algorithms for the **Mandelbrot set**, **Julia set**, and **Burning Ship**.
- Handle **keyboard** and **mouse inputs** for interactive controls (zoom, pan, iterations).
- Use **complex numbers** to generate fractals.
- Optimize the rendering for better performance, especially with higher iterations.

## **Learning Outcomes**  
- Understanding the use of **complex numbers** in graphics programming.
- Implementing fractal algorithms from scratch.
- Working with **MiniLibX** for **2D graphics rendering**.
- Handling **interactive user inputs** for zooming, panning, and changing iterations.
- Optimizing the rendering and performance of fractal visuals.

## **Usage**  
### How to Build and Run

## **Usage**  
### How to Build and Run

1. Clone the repository:

   ```bash
   git clone https://github.com/msabr/FRACTOL_1337
   cd FRACTOL_1337

2. Build the mandatory part:

   ```bash
   make

3. Run mandelbrot:

   ```bash
   ./fractol mandelbrot

3. Run julia:

   ```bash
   ./fractol julia -0.8 0.156

#### Additional commands

- `make clean`: remove object files.
- `make fclean`: remove the program and object files.
- `make re`: rebuild everything.
