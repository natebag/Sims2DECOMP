#ifndef TYPES_H
#define TYPES_H

#include <cstddef>
#include <cstdint>

// Standard integer types (portable across GC and PC)
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef signed long long s64;

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;

typedef float f32;
typedef double f64;

typedef int BOOL;

// Portable pointer-sized integer (32-bit on GC, 64-bit on PC)
typedef uintptr_t uptr;

#ifndef TRUE
#define TRUE  1
#endif
#ifndef FALSE
#define FALSE 0
#endif
#ifndef NULL
#define NULL  nullptr
#endif

// Placement new — use standard <new> header
#include <new>

#endif // TYPES_H
