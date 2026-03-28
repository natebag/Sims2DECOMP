/* c_linkage_stubs.c — C-linkage stubs for functions some decomp files declare as extern "C" */

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

int Sprintf(char* buf, const char* fmt, ...) {
    va_list a;
    va_start(a, fmt);
    int r = vsprintf(buf, fmt, a);
    va_end(a);
    return r;
}

int AtoI(const char* str) {
    return atoi(str);
}

void localConvertToWide(unsigned short* dst, const char* src) {
    while (*src) { *dst++ = (unsigned short)(unsigned char)*src++; }
    *dst = 0;
}

void* small_alloc(unsigned int n) { return malloc(n); }
void small_free(void* p) { free(p); }
void* EAHeap_Alloc(int n) { return malloc(n); }
void* EAHeap_MallocAligned(int n, int align) { return malloc(n); }
void EGraphics_SetCameraBloom() {}
void EGraphics_SetMotionBlur() {}
void EMat4_Identity() {}
void ProfileHook() {}

int stricmp(const char* a, const char* b) {
    while (*a && *b) {
        int ca = (*a >= 'A' && *a <= 'Z') ? *a + 32 : *a;
        int cb = (*b >= 'A' && *b <= 'Z') ? *b + 32 : *b;
        if (ca != cb) return ca - cb;
        a++; b++;
    }
    return (unsigned char)*a - (unsigned char)*b;
}
