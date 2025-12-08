# FPM

## DESCRIPTION
This API allows you to check file permissions. There can be 3 levels, USER, ADMIN, and OWNER. User has low-control, Admin has moderate control, and Owner has full control. There can only be 1 owner.

## HOW TO INSTALL (GCC/G++ && CMAKE)
### before starting, go to releases to get the .rar file and extract it to follow the steps, or copy the files from the repository.

# GCC/G++

1- Copy the files from include and src to one main folder. Name it whatever you want (the folder). 

2- Go to compiling folder. It will teach you to build tasks.json and launch.json, c_cpp_properties.json if needed.

3- Including it:

```cpp
#include "../<yourFolder>/FPM.hpp"
#include "../<yourFolder>/fpm_operators.hpp"

int main() {
// your code
}
```

# CMAKE

1- Copy the files from include/ and src/ into a folder inside your project (name the folder whatever you want), or download the .rar from Releases and extract it.

2- In your projects CMakeLists.txt, add FPM as a library:

```cmake
add_subdirectory(<path_to_FPM_folder>)

add_executable(app
    src/main.cpp
)

target_link_libraries(app PRIVATE fpm)
```

3- Build the project with commands:

```
cmake -S . -B build
cmake --build build
```

4- Include the necessary files:

```cpp
#include "FPM.hpp"
#include "fpm_operators.hpp"
```
