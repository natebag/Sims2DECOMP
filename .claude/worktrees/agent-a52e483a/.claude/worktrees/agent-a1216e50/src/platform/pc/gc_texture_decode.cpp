#include "gc_texture_decode.h"
#include <string.h>

// ============================================================================
// Helpers
// ============================================================================

static inline uint16_t read_be16(const uint8_t* p) {
    return (uint16_t)(p[0] << 8 | p[1]);
}

static inline uint32_t read_be32(const uint8_t* p) {
    return (uint32_t)(p[0] << 24 | p[1] << 16 | p[2] << 8 | p[3]);
}

static inline void set_pixel(uint8_t* dst, int width, int x, int y, RGBA8 c) {
    int idx = (y * width + x) * 4;
    dst[idx + 0] = c.r;
    dst[idx + 1] = c.g;
    dst[idx + 2] = c.b;
    dst[idx + 3] = c.a;
}

// ============================================================================
// Pixel format decoders
// ============================================================================

RGBA8 gc_decode_rgb5a3(uint16_t pixel) {
    RGBA8 c;
    if (pixel & 0x8000) {
        // RGB555 (no alpha) — top bit set
        c.r = (uint8_t)(((pixel >> 10) & 0x1F) * 255 / 31);
        c.g = (uint8_t)(((pixel >> 5) & 0x1F) * 255 / 31);
        c.b = (uint8_t)((pixel & 0x1F) * 255 / 31);
        c.a = 255;
    } else {
        // RGB4A3 — top bit clear
        c.a = (uint8_t)(((pixel >> 12) & 0x07) * 255 / 7);
        c.r = (uint8_t)(((pixel >> 8) & 0x0F) * 255 / 15);
        c.g = (uint8_t)(((pixel >> 4) & 0x0F) * 255 / 15);
        c.b = (uint8_t)((pixel & 0x0F) * 255 / 15);
    }
    return c;
}

RGBA8 gc_decode_rgb565(uint16_t pixel) {
    RGBA8 c;
    c.r = (uint8_t)(((pixel >> 11) & 0x1F) * 255 / 31);
    c.g = (uint8_t)(((pixel >> 5) & 0x3F) * 255 / 63);
    c.b = (uint8_t)((pixel & 0x1F) * 255 / 31);
    c.a = 255;
    return c;
}

RGBA8 gc_decode_palette_entry(uint16_t entry, int palFmt) {
    switch (palFmt) {
        case GC_TL_IA8: {
            RGBA8 c;
            c.r = c.g = c.b = (uint8_t)(entry & 0xFF);
            c.a = (uint8_t)(entry >> 8);
            return c;
        }
        case GC_TL_RGB565:
            return gc_decode_rgb565(entry);
        case GC_TL_RGB5A3:
            return gc_decode_rgb5a3(entry);
        default: {
            RGBA8 c = {0, 0, 0, 255};
            return c;
        }
    }
}

// ============================================================================
// I4: 4-bit intensity, 8x8 tiles
// ============================================================================

static void decode_i4(const uint8_t* src, uint8_t* dst, int w, int h) {
    int tilesX = (w + 7) / 8;
    int tilesY = (h + 7) / 8;
    const uint8_t* p = src;

    for (int ty = 0; ty < tilesY; ty++) {
        for (int tx = 0; tx < tilesX; tx++) {
            for (int row = 0; row < 8; row++) {
                for (int col = 0; col < 8; col += 2) {
                    uint8_t byte = *p++;
                    int x0 = tx * 8 + col;
                    int y0 = ty * 8 + row;

                    uint8_t i0 = (byte >> 4) * 17; // expand 4-bit to 8-bit
                    uint8_t i1 = (byte & 0xF) * 17;

                    if (x0 < w && y0 < h) {
                        RGBA8 c = {i0, i0, i0, 255};
                        set_pixel(dst, w, x0, y0, c);
                    }
                    if (x0 + 1 < w && y0 < h) {
                        RGBA8 c = {i1, i1, i1, 255};
                        set_pixel(dst, w, x0 + 1, y0, c);
                    }
                }
            }
        }
    }
}

// ============================================================================
// I8: 8-bit intensity, 8x4 tiles
// ============================================================================

static void decode_i8(const uint8_t* src, uint8_t* dst, int w, int h) {
    int tilesX = (w + 7) / 8;
    int tilesY = (h + 3) / 4;
    const uint8_t* p = src;

    for (int ty = 0; ty < tilesY; ty++) {
        for (int tx = 0; tx < tilesX; tx++) {
            for (int row = 0; row < 4; row++) {
                for (int col = 0; col < 8; col++) {
                    uint8_t i = *p++;
                    int x = tx * 8 + col;
                    int y = ty * 4 + row;
                    if (x < w && y < h) {
                        RGBA8 c = {i, i, i, 255};
                        set_pixel(dst, w, x, y, c);
                    }
                }
            }
        }
    }
}

// ============================================================================
// IA4: 4-bit intensity + 4-bit alpha, 8x4 tiles
// ============================================================================

static void decode_ia4(const uint8_t* src, uint8_t* dst, int w, int h) {
    int tilesX = (w + 7) / 8;
    int tilesY = (h + 3) / 4;
    const uint8_t* p = src;

    for (int ty = 0; ty < tilesY; ty++) {
        for (int tx = 0; tx < tilesX; tx++) {
            for (int row = 0; row < 4; row++) {
                for (int col = 0; col < 8; col++) {
                    uint8_t byte = *p++;
                    int x = tx * 8 + col;
                    int y = ty * 4 + row;
                    if (x < w && y < h) {
                        uint8_t i = (byte & 0xF) * 17;
                        uint8_t a = (byte >> 4) * 17;
                        RGBA8 c = {i, i, i, a};
                        set_pixel(dst, w, x, y, c);
                    }
                }
            }
        }
    }
}

// ============================================================================
// IA8: 8-bit intensity + 8-bit alpha, 4x4 tiles
// ============================================================================

static void decode_ia8(const uint8_t* src, uint8_t* dst, int w, int h) {
    int tilesX = (w + 3) / 4;
    int tilesY = (h + 3) / 4;
    const uint8_t* p = src;

    for (int ty = 0; ty < tilesY; ty++) {
        for (int tx = 0; tx < tilesX; tx++) {
            for (int row = 0; row < 4; row++) {
                for (int col = 0; col < 4; col++) {
                    uint8_t a = *p++;
                    uint8_t i = *p++;
                    int x = tx * 4 + col;
                    int y = ty * 4 + row;
                    if (x < w && y < h) {
                        RGBA8 c = {i, i, i, a};
                        set_pixel(dst, w, x, y, c);
                    }
                }
            }
        }
    }
}

// ============================================================================
// RGB565: 16-bit RGB, 4x4 tiles
// ============================================================================

static void decode_rgb565(const uint8_t* src, uint8_t* dst, int w, int h) {
    int tilesX = (w + 3) / 4;
    int tilesY = (h + 3) / 4;
    const uint8_t* p = src;

    for (int ty = 0; ty < tilesY; ty++) {
        for (int tx = 0; tx < tilesX; tx++) {
            for (int row = 0; row < 4; row++) {
                for (int col = 0; col < 4; col++) {
                    uint16_t pixel = read_be16(p); p += 2;
                    int x = tx * 4 + col;
                    int y = ty * 4 + row;
                    if (x < w && y < h) {
                        set_pixel(dst, w, x, y, gc_decode_rgb565(pixel));
                    }
                }
            }
        }
    }
}

// ============================================================================
// RGB5A3: 16-bit RGB + optional alpha, 4x4 tiles
// ============================================================================

static void decode_rgb5a3(const uint8_t* src, uint8_t* dst, int w, int h) {
    int tilesX = (w + 3) / 4;
    int tilesY = (h + 3) / 4;
    const uint8_t* p = src;

    for (int ty = 0; ty < tilesY; ty++) {
        for (int tx = 0; tx < tilesX; tx++) {
            for (int row = 0; row < 4; row++) {
                for (int col = 0; col < 4; col++) {
                    uint16_t pixel = read_be16(p); p += 2;
                    int x = tx * 4 + col;
                    int y = ty * 4 + row;
                    if (x < w && y < h) {
                        set_pixel(dst, w, x, y, gc_decode_rgb5a3(pixel));
                    }
                }
            }
        }
    }
}

// ============================================================================
// RGBA8: 32-bit RGBA, 4x4 tiles (AR and GB interleaved in 64-byte blocks)
// ============================================================================

static void decode_rgba8(const uint8_t* src, uint8_t* dst, int w, int h) {
    int tilesX = (w + 3) / 4;
    int tilesY = (h + 3) / 4;
    const uint8_t* p = src;

    for (int ty = 0; ty < tilesY; ty++) {
        for (int tx = 0; tx < tilesX; tx++) {
            // First 32 bytes: AR values for 4x4 block
            uint8_t ar[16][2];
            for (int i = 0; i < 16; i++) {
                ar[i][0] = *p++; // A
                ar[i][1] = *p++; // R
            }
            // Next 32 bytes: GB values for 4x4 block
            for (int i = 0; i < 16; i++) {
                uint8_t g = *p++;
                uint8_t b = *p++;
                int col = i % 4;
                int row = i / 4;
                int x = tx * 4 + col;
                int y = ty * 4 + row;
                if (x < w && y < h) {
                    RGBA8 c = {ar[i][1], g, b, ar[i][0]};
                    set_pixel(dst, w, x, y, c);
                }
            }
        }
    }
}

// ============================================================================
// C4: 4-bit palette indexed, 8x8 tiles
// ============================================================================

static void decode_c4(const uint8_t* src, uint8_t* dst, int w, int h,
                      const uint8_t* palette, int palFmt) {
    int tilesX = (w + 7) / 8;
    int tilesY = (h + 7) / 8;
    const uint8_t* p = src;

    for (int ty = 0; ty < tilesY; ty++) {
        for (int tx = 0; tx < tilesX; tx++) {
            for (int row = 0; row < 8; row++) {
                for (int col = 0; col < 8; col += 2) {
                    uint8_t byte = *p++;
                    int idx0 = (byte >> 4) & 0xF;
                    int idx1 = byte & 0xF;

                    uint16_t pal0 = read_be16(palette + idx0 * 2);
                    uint16_t pal1 = read_be16(palette + idx1 * 2);

                    int x0 = tx * 8 + col;
                    int y0 = ty * 8 + row;

                    if (x0 < w && y0 < h)
                        set_pixel(dst, w, x0, y0, gc_decode_palette_entry(pal0, palFmt));
                    if (x0 + 1 < w && y0 < h)
                        set_pixel(dst, w, x0 + 1, y0, gc_decode_palette_entry(pal1, palFmt));
                }
            }
        }
    }
}

// ============================================================================
// C8: 8-bit palette indexed, 8x4 tiles
// ============================================================================

static void decode_c8(const uint8_t* src, uint8_t* dst, int w, int h,
                      const uint8_t* palette, int palFmt) {
    int tilesX = (w + 7) / 8;
    int tilesY = (h + 3) / 4;
    const uint8_t* p = src;

    for (int ty = 0; ty < tilesY; ty++) {
        for (int tx = 0; tx < tilesX; tx++) {
            for (int row = 0; row < 4; row++) {
                for (int col = 0; col < 8; col++) {
                    uint8_t idx = *p++;
                    uint16_t entry = read_be16(palette + idx * 2);
                    int x = tx * 8 + col;
                    int y = ty * 4 + row;
                    if (x < w && y < h)
                        set_pixel(dst, w, x, y, gc_decode_palette_entry(entry, palFmt));
                }
            }
        }
    }
}

// ============================================================================
// CMPR: S3TC/DXT1 compressed, 8x8 super-tiles of 4x4 sub-blocks
// ============================================================================

static void decode_cmpr_block(const uint8_t* block, RGBA8 out[4][4]) {
    uint16_t c0 = read_be16(block);
    uint16_t c1 = read_be16(block + 2);

    RGBA8 color[4];
    color[0] = gc_decode_rgb565(c0);
    color[1] = gc_decode_rgb565(c1);

    if (c0 > c1) {
        color[2].r = (uint8_t)((2 * color[0].r + color[1].r + 1) / 3);
        color[2].g = (uint8_t)((2 * color[0].g + color[1].g + 1) / 3);
        color[2].b = (uint8_t)((2 * color[0].b + color[1].b + 1) / 3);
        color[2].a = 255;
        color[3].r = (uint8_t)((color[0].r + 2 * color[1].r + 1) / 3);
        color[3].g = (uint8_t)((color[0].g + 2 * color[1].g + 1) / 3);
        color[3].b = (uint8_t)((color[0].b + 2 * color[1].b + 1) / 3);
        color[3].a = 255;
    } else {
        color[2].r = (uint8_t)((color[0].r + color[1].r) / 2);
        color[2].g = (uint8_t)((color[0].g + color[1].g) / 2);
        color[2].b = (uint8_t)((color[0].b + color[1].b) / 2);
        color[2].a = 255;
        color[3] = (RGBA8){0, 0, 0, 0}; // transparent
    }

    uint32_t indices = read_be32(block + 4);
    for (int row = 0; row < 4; row++) {
        for (int col = 0; col < 4; col++) {
            int shift = 30 - ((row * 4 + col) * 2);
            int idx = (indices >> shift) & 3;
            out[row][col] = color[idx];
        }
    }
}

static void decode_cmpr(const uint8_t* src, uint8_t* dst, int w, int h) {
    // CMPR: 8x8 super-tiles, each containing four 4x4 DXT1 sub-blocks
    int tilesX = (w + 7) / 8;
    int tilesY = (h + 7) / 8;
    const uint8_t* p = src;

    for (int ty = 0; ty < tilesY; ty++) {
        for (int tx = 0; tx < tilesX; tx++) {
            // 4 sub-blocks per super-tile: TL, TR, BL, BR
            for (int sb = 0; sb < 4; sb++) {
                RGBA8 block[4][4];
                decode_cmpr_block(p, block);
                p += 8;

                int baseX = tx * 8 + (sb & 1) * 4;
                int baseY = ty * 8 + (sb >> 1) * 4;

                for (int row = 0; row < 4; row++) {
                    for (int col = 0; col < 4; col++) {
                        int x = baseX + col;
                        int y = baseY + row;
                        if (x < w && y < h)
                            set_pixel(dst, w, x, y, block[row][col]);
                    }
                }
            }
        }
    }
}

// ============================================================================
// Public API
// ============================================================================

size_t gc_texture_data_size(int width, int height, int format) {
    int w = width, h = height;
    switch (format) {
        case GC_TF_I4:     return (size_t)((w + 7) / 8) * ((h + 7) / 8) * 32;
        case GC_TF_I8:     return (size_t)((w + 7) / 8) * ((h + 3) / 4) * 32;
        case GC_TF_IA4:    return (size_t)((w + 7) / 8) * ((h + 3) / 4) * 32;
        case GC_TF_IA8:    return (size_t)((w + 3) / 4) * ((h + 3) / 4) * 32;
        case GC_TF_RGB565: return (size_t)((w + 3) / 4) * ((h + 3) / 4) * 32;
        case GC_TF_RGB5A3: return (size_t)((w + 3) / 4) * ((h + 3) / 4) * 32;
        case GC_TF_RGBA8:  return (size_t)((w + 3) / 4) * ((h + 3) / 4) * 64;
        case GC_TF_C4:     return (size_t)((w + 7) / 8) * ((h + 7) / 8) * 32;
        case GC_TF_C8:     return (size_t)((w + 7) / 8) * ((h + 3) / 4) * 32;
        case GC_TF_CMPR:   return (size_t)((w + 7) / 8) * ((h + 7) / 8) * 32;
        default: return 0;
    }
}

int gc_texture_decode(const uint8_t* src, uint8_t* dst,
                      int width, int height, int format,
                      const uint8_t* palette, int palFmt) {
    memset(dst, 0, (size_t)width * height * 4);

    switch (format) {
        case GC_TF_I4:     decode_i4(src, dst, width, height); break;
        case GC_TF_I8:     decode_i8(src, dst, width, height); break;
        case GC_TF_IA4:    decode_ia4(src, dst, width, height); break;
        case GC_TF_IA8:    decode_ia8(src, dst, width, height); break;
        case GC_TF_RGB565: decode_rgb565(src, dst, width, height); break;
        case GC_TF_RGB5A3: decode_rgb5a3(src, dst, width, height); break;
        case GC_TF_RGBA8:  decode_rgba8(src, dst, width, height); break;
        case GC_TF_C4:
            if (!palette) return -1;
            decode_c4(src, dst, width, height, palette, palFmt);
            break;
        case GC_TF_C8:
            if (!palette) return -1;
            decode_c8(src, dst, width, height, palette, palFmt);
            break;
        case GC_TF_CMPR:   decode_cmpr(src, dst, width, height); break;
        default: return -1;
    }
    return 0;
}
