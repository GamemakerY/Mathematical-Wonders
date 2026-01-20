# 🏛️ A Library Of Algorithmic Wonders

A library of fun and interactive mathematical curisoities. Built with **C++** and rendered in the browser using **WebAssembly**.

[**Explore the Library Live**](https://gamemakery.github.io/Mathematical-Wonders)

---

## 🌌 Current Wonders

### 1. The Chaos Game

A method of creating fractals using a polygon and a random point inside it. 

* **The Logic:** In each iteration, a new point is placed a fraction of the distance between the previous point and a random vertex of the polygon.
  
* **The Result:** From pure randomness, the **Sierpiński triangle** emerges for n =3  and r = 1/2. Other patterns emerge for different n and r. Can you find them?* (Option to change r to be added soon.)

---

## 🛠️ Technical Architecture

-   **Language:** C++ (Standard 17+)
-   **Rendering:** WebGL (via Emscripten/SDL2)
-   **Philosophy:** Every "wonder" is designed to be mathematically accurate and performant at high iteration counts.

## 🚀 Future Additions
- [ ] Mandelbrot Set Visualizer
- [ ] Langton's Ant
- [ ] Boids Flocking Simulation
- [ ] Conway's Game of Life

---

## 📦 Building Locally
To compile the library to WASM:
1. Ensure `emsdk` is installed and activated.
2. Run:
   ```bash
   emcc main.cpp -s WASM=1 -o index.html
