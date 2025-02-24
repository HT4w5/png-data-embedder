# png-data-embedder
Assignment project of embedding binary data in png images.
## Build
Install opencv 4.11.0 or above.
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
## License
This software uses opencv which is licensed under the Apache License, Version 2.0.

Copyright 2025 opencv

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.