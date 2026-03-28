#ifndef ZLIB_STUB_H
#define ZLIB_STUB_H
#include <string.h>
typedef unsigned char Byte;
typedef unsigned long uLong;
#define Z_OK 0
#define Z_STREAM_END 1
#define Z_DEFAULT_STRATEGY 0
#define Z_DEFLATED 8
#define Z_FINISH 4
typedef struct { Byte *next_in; unsigned avail_in; unsigned long total_in; Byte *next_out; unsigned avail_out; unsigned long total_out; char *msg; void *state; } z_stream;
static inline int inflateInit_(z_stream *s, const char *v, int sz) { (void)s;(void)v;(void)sz; return -1; }
static inline int inflate(z_stream *s, int f) { (void)s;(void)f; return -1; }
static inline int inflateEnd(z_stream *s) { (void)s; return 0; }
#define inflateInit(s) inflateInit_(s, "1.0", sizeof(z_stream))
static inline int uncompress(Byte *d, uLong *dl, const Byte *s, uLong sl) { memcpy(d,s,sl<*dl?sl:*dl); *dl=sl; return 0; }
#endif
