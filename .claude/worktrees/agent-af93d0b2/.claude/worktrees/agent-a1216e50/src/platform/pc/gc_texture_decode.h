#ifndef GC_TEXTURE_DECODE_H
#define GC_TEXTURE_DECODE_H

#include <stdint.h>
#include <stddef.h>

// GameCube texture format IDs (GXTexFmt)
enum GCTexFormat {
    GC_TF_I4     = 0,  // 4-bit intensity
    GC_TF_I8     = 1,  // 8-bit intensity
    GC_TF_IA4    = 2,  // 4-bit intensity + 4-bit alpha
    GC_TF_IA8    = 3,  // 8-bit intensity + 8-bit alpha
    GC_TF_RGB565 = 4,  // 16-bit RGB
    GC_TF_RGB5A3 = 5,  // 16-bit RGB with 3-bit alpha or 15-bit RGB
    GC_TF_RGBA8  = 6,  // 32-bit RGBA (two 32-byte tiles interleaved)
    GC_TF_C4     = 8,  // 4-bit palette index
    GC_TF_C8     = 9,  // 8-bit palette index
    GC_TF_C14X2  = 10, // 14-bit palette index
    GC_TF_CMPR   = 14, // S3TC/DXT1 compressed (4x4 blocks)
};

// GC palette format IDs (GXTlutFmt)
enum GCPalFormat {
    GC_TL_IA8    = 0,
    GC_TL_RGB565 = 1,
    GC_TL_RGB5A3 = 2,
};

// Decoded RGBA pixel
struct RGBA8 {
    uint8_t r, g, b, a;
};

// Decode a GC texture to RGBA8 pixels.
// src: raw GC texture data (swizzled/tiled)
// dst: output RGBA8 buffer (width * height * 4 bytes, caller-allocated)
// width, height: texture dimensions
// format: GCTexFormat enum
// palette: palette data for indexed formats (C4/C8), NULL for direct-color
// palFmt: palette format (GCPalFormat), ignored if palette is NULL
// Returns 0 on success, -1 on unsupported format
int gc_texture_decode(const uint8_t* src, uint8_t* dst,
                      int width, int height, int format,
                      const uint8_t* palette, int palFmt);

// Decode a single palette entry to RGBA8
RGBA8 gc_decode_palette_entry(uint16_t entry, int palFmt);

// Decode a single RGB5A3 pixel to RGBA8
RGBA8 gc_decode_rgb5a3(uint16_t pixel);

// Decode a single RGB565 pixel to RGBA8
RGBA8 gc_decode_rgb565(uint16_t pixel);

// Calculate the data size in bytes for a GC texture
size_t gc_texture_data_size(int width, int height, int format);

#endif // GC_TEXTURE_DECODE_H
