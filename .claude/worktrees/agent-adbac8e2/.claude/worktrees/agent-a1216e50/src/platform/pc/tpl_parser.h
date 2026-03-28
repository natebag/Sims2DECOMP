#ifndef TPL_PARSER_H
#define TPL_PARSER_H

#include <stdint.h>

// TPL file header (GameCube Texture Palette Library)
// Magic: 0x0020AF30

struct TPLHeader {
    uint32_t magic;       // 0x0020AF30
    uint32_t numImages;
    uint32_t imageTableOffset;
};

struct TPLImageEntry {
    uint32_t imageHeaderOffset;
    uint32_t paletteHeaderOffset;
};

struct TPLImageHeader {
    uint16_t height;
    uint16_t width;
    uint32_t format;        // GCTexFormat
    uint32_t dataOffset;
    uint32_t wrapS;
    uint32_t wrapT;
    uint32_t minFilter;
    uint32_t magFilter;
    float    lodBias;
    uint8_t  edgeLODEnable;
    uint8_t  minLOD;
    uint8_t  maxLOD;
    uint8_t  unpacked;
};

struct TPLPaletteHeader {
    uint16_t entryCount;
    uint8_t  unpacked;
    uint8_t  pad;
    uint32_t format;       // GCPalFormat
    uint32_t dataOffset;
};

struct TPLImage {
    int      width;
    int      height;
    int      format;       // GCTexFormat
    uint8_t* imageData;    // raw GC tile data
    int      imageDataSize;
    uint8_t* paletteData;  // raw palette data (or NULL)
    int      paletteFormat; // GCPalFormat
    int      paletteEntries;
};

// Parse a TPL file from memory.
// data: pointer to TPL file contents
// dataSize: size of the TPL file
// outImages: caller-allocated array of TPLImage structs
// maxImages: size of outImages array
// Returns number of images parsed, or -1 on error.
// Note: imageData/paletteData point into the input buffer — do not free them separately.
int tpl_parse(const uint8_t* data, int dataSize, TPLImage* outImages, int maxImages);

#endif // TPL_PARSER_H
