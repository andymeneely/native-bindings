#pragma once

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

#ifdef _WIN32
#    define MODULE_API __declspec(dllexport)
#else
#  define MODULE_API
#endif

MODULE_API char* say_hello();
MODULE_API int32_t multiply(int32_t x, int32_t y);
MODULE_API int32_t min(int32_t *array, int32_t len);

#ifdef __cplusplus
}
#endif
