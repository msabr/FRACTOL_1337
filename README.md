# 🧠FRACTOL_1337

**fract-ol** is a project from the 42 cursus that explores fractals using **MiniLibX**, a simple graphics library. The goal is to render and interact with fractals like the **Mandelbrot set**, the **Julia set**, and optionally the **Burning Ship**.

---

## 📚 Project Objectives

- Understand and use **complex numbers**.
- Implement fractal algorithms from scratch.
- Use the **MiniLibX** to draw pixels and handle user inputs.
- Allow interactive controls like zoom, move, and iteration changes.

---

## 🌀 Fractals Implemented

### ✔️ Mandelbrot Set
Classic fractal defined by the formula:  
`z = z² + c`, starting with `z = 0` and `c` from the complex plane.

### ✔️ Julia Set
Similar formula to Mandelbrot, but with a **fixed c** and variable `z`.

### ✔️ Burning Ship (Bonus)
A fractal similar to Mandelbrot but with a twist:  
`z = (|Re(z)| + i|Im(z)|)² + c`, giving a “ship-like” appearance.

---

## 🛠️ Compile & Launch

To compile the project:

```bash
make

Then, to launch different fractals:

```bash
./fractol mandelbrot

```bash
./fractol julia -0.8 0.156
