# stl
STL (Stereolithography) – A 3D file format used for 3D printing and CAD.



### 🔹 Binary STL File Format

* **80 bytes**: Header (ignored, usually contains no critical info)
* **4 bytes**: Unsigned int - number of triangles
* Then for **each triangle (50 bytes)**:

  * **12 bytes**: Normal vector (3 floats)
  * **36 bytes**: 3 vertices (3 floats each = 9 floats)
  * **2 bytes**: Attribute byte count (usually unused)



### 💡 Notes

* Only supports **binary STL**, not ASCII.
* Replace `"your_model.stl"` with your STL file.
* Use `g++ file.cpp -lGL -lGLU -lglut -o viewer` to compile.








C

```
https://www.mattkeeter.com/projects/erizo/
https://github.com/mkeeter/erizo

```
