# Logtra

Logtra is a simple C++ Logging Library

## Purpose

Voltra is **not** meant to be the fastest, easiest to use or in general best logging library. It is only something i created in an afternoon for fun and experimentation reasons. Hence, some code parts are absolutely horrible.

## Installation
```
git clone https://github.com/Homuncoli/Logtra.git
```

## Usage
```CMake
target_link_libraries (${CMAKE_PROJECT_NAME} PUBLIC Logtra)
```

```c++
#include "Logtra.h"

int main() {
	Logtra::Logger logger("Debug 1");

	LGA_USE_LOGGER(logger);

	LGA_SUCCESS("Success");
	LGA_LOG("Log");
	LGA_WARNING("Warning");
	LGA_ERROR("Error");
	LGA_CRITICAL("Critical");
}
```

## Contributing
Pull requests and recommendations are welcome, but please note that this repo is something i did for fun and experimentation reasons and not for actual production.

## License
[MIT](https://choosealicense.com/licenses/mit/)