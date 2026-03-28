#include "ea_texture.h"
#include "gc_texture_decode.h"
#include <string.h>

static inline uint16_t rbe16(const uint8_t* p) {
    return (uint16_t)(p[0] << 8 | p[1]);
}
static inline uint32_t rbe32(const uint8_t* p) {
    return (uint32_t)(p[0] << 24 | p[1] << 16 | p[2] << 8 | p[3]);
}

int ea_tex_parse_header(const uint8_t* data, EATexHeader* out) {
    if (!data || !out) return -1;

    out->flags      = rbe32(data + 0x00);
    out->reserved1  = rbe32(data + 0x04);
    out->reserved2  = rbe32(data + 0x08);
    out->reserved3  = rbe32(data + 0x0C);
    out->width      = rbe16(data + 0x10);
    out->height     = rbe16(data + 0x12);
    out->clutWidth  = rbe16(data + 0x14);
    out->clutHeight = rbe16(data + 0x16);
    out->format     = data[0x18];
    out->mipCount   = data[0x19];
    out->bpp        = data[0x1A];
    out->clutBpp    = data[0x1B];
    out->unused     = rbe16(data + 0x1C);
    out->mipLevels  = rbe16(data + 0x1E);

    // Sanity checks
    if (out->width == 0 || out->height == 0) return -1;
    if (out->width > 4096 || out->height > 4096) return -1;

    return 0;
}

int ea_format_to_gc(uint8_t ea_format) {
    switch (ea_format) {
        case EA_FMT_RGBA8:
        case EA_FMT_RGBA8_ALT:
            return GC_TF_RGBA8;
        case EA_FMT_CMPR:
            return GC_TF_CMPR;
        case EA_FMT_RGB5A3:
            return GC_TF_RGB5A3;
        case EA_FMT_C4:
            return GC_TF_C4;
        case EA_FMT_C8:
            return GC_TF_C8;
        case EA_FMT_C4_32:
            return GC_TF_C4;  // same decode, just 32-bit CLUT entries
        case EA_FMT_C8_32:
            return GC_TF_C8;  // same decode, just 32-bit CLUT entries
        default:
            return -1;
    }
}

uint32_t ea_tex_data_size(const EATexHeader* header) {
    int gc_fmt = ea_format_to_gc(header->format);
    if (gc_fmt < 0) return 0;

    uint32_t total = 0;
    int mips = header->mipLevels > 0 ? header->mipLevels : 1;

    for (int m = 0; m < mips; m++) {
        int mw = header->width >> m;
        int mh = header->height >> m;
        if (mw < 1) mw = 1;
        if (mh < 1) mh = 1;
        total += (uint32_t)gc_texture_data_size(mw, mh, gc_fmt);
    }

    // Add palette data if present
    if (header->clutWidth > 0 && header->clutHeight > 0) {
        total += (uint32_t)(header->clutWidth * header->clutHeight * header->clutBpp / 8);
    }

    return total;
}
