# png-data-embedder
Assignment project of embedding binary data in png images.
## Build
```bash
g++ pde.cpp png_data_embedder.cpp -o pde -I/usr/local/include/opencv4 -L/usr/local/lib -lopencv_core -lopencv_imgcodecs -lopencv_imgproc
```
## Usage
```plaintext
Png Data Embedder: pde
Params:
pde --help    | -h
pde --embed   | -m  [path/to/file]
pde --extract | -x  [path/to/file]
```