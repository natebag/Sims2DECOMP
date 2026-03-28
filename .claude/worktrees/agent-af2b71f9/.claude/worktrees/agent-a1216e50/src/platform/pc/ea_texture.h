#ifndef EA_TEXTURE_H
#define EA_TEXTURE_H

#include <stdint.h>

// EA Internal Texture Format (TXFL)
// Used by ERTexture::LoadFromMemory in the Sims 2 engine.
// Files in .arc archives begin with this 32-byte header.

// File signature: "TXFL" at the start of an IFF resource block
#define EA_TEX_SIGNATURE 0x5458464C  // "TXFL" big-endian

// 32-byte texture header (all fields big-endian)
struct EATexHeader {
    uint32_t flags;         // 0x00: texture flags
    uint32_t reserved1;     // 0x04
    uint32_t reserved2;     // 0x08
    uint32_t reserved3;     // 0x0C
    uint16_t width;         // 0x10
    uint16_t height;        // 0x12
    uint16_t clutWidth;     // 0x14: palette width (0 if no palette)
    uint16_t clutHeight;    // 0x16: palette height (0 if no palette)
    uint8_t  format;        // 0x18: EA image format code
    uint8_t  mipCount;      // 0x19: number of mipmap levels
    uint8_t  bpp;           // 0x1A: bits per pixel
    uint8_t  clutBpp;       // 0x1B: palette entry bits per pixel
    uint16_t unused;        // 0x1C
    uint16_t mipLevels;     // 0x1E: mip level count (may differ from mipCount)
};

// EA format codes → GCTexFormat mapping
// From the decomp (render_classes.cpp Create() switch)
#define EA_FMT_INDEXED_C8_32  0x00  // subformat check: 2080 = C8_32, 1056 = C4_32
#define EA_FMT_RGBA8          0x01  // or 0x85
#define EA_FMT_CMPR           0x81
#define EA_FMT_RGB5A3         0x82
#define EA_FMT_C4             0x83
#define EA_FMT_C8             0x84
#define EA_FMT_RGBA8_ALT      0x85
#define EA_FMT_C4_32          0x89
#define EA_FMT_C8_32          0x8A

// Parse an EA texture header from big-endian data.
// data: pointer to 32 bytes of header data
// out: parsed header (host-endian)
// Returns 0 on success, -1 on error.
int ea_tex_parse_header(const uint8_t* data, EATexHeader* out);

// Map EA format code to GCTexFormat for the texture decoder.
// ea_format: the format byte from the EA header
// Returns GCTexFormat enum value, or -1 if unsupported.
int ea_format_to_gc(uint8_t ea_format);

// Calculate total image data size (all mip levels) for an EA texture.
// header: parsed EA texture header
// Returns size in bytes.
uint32_t ea_tex_data_size(const EATexHeader* header);

#endif // EA_TEXTURE_H
