#ifndef WCHARUTIL_H
#define WCHARUTIL_H

#include "types.h"

// Wide character utility functions
// From: wcharutil.obj
// Note: wchar_t is 16-bit on GameCube (-fshort-wchar)

// Returns length of wide string (not counting null terminator)
int wcslen(const wchar_t* str);

// Compares two wide strings, returns difference of first mismatched chars
int wcscmp(const wchar_t* s1, const wchar_t* s2);

// Copies wide string src to dst, returns dst
wchar_t* wcscpy(wchar_t* dst, const wchar_t* src);

// Compares at most n chars of two wide strings
int wcsncmp(const wchar_t* s1, const wchar_t* s2, int n);

// Finds first occurrence of character c in wide string, or NULL if not found
wchar_t* wcschr(const wchar_t* str, wchar_t c);

#endif // WCHARUTIL_H
