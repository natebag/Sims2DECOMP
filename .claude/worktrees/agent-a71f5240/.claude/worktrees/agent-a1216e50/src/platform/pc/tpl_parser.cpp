#include "tpl_parser.h"
#include "gc_texture_decode.h"
#include <string.h>

static inline uint16_t rbe16(const uint8_t* p) {
    return (uint16_t)(p[0] << 8 | p[1]);
}
static inline uint32_t rbe32(const uint8_t* p) {
    return (uint32_t)(p[0] << 24 | p[1] << 16 | p[2] << 8 | p[3]);
}

static float rbe_f32(const uint8_t* p) {
    uint32_t bits = rbe32(p);
    float f;
    memcpy(&f, &bits, 4);
    return f;
}

int tpl_parse(const uint8_t* data, int dataSize, TPLImage* outImages, int maxImages) {
    if (dataSize < 12) return -1;

    uint32_t magic = rbe32(data);
    if (magic != 0x0020AF30) return -1;

    uint32_t numImages = rbe32(data + 4);
    uint32_t tableOff = rbe32(data + 8);

    if (tableOff + numImages * 8 > (uint32_t)dataSize) return -1;

    int count = 0;
    for (uint32_t i = 0; i < numImages && count < maxImages; i++) {
        const uint8_t* entry = data + tableOff + i * 8;
        uint32_t imgOff = rbe32(entry);
        uint32_t palOff = rbe32(entry + 4);

        if (imgOff == 0 || imgOff + 36 > (uint32_t)dataSize) continue;

        const uint8_t* ih = data + imgOff;
        TPLImage* img = &outImages[count];

        img->height = rbe16(ih + 0);
        img->width  = rbe16(ih + 2);
        img->format = (int)rbe32(ih + 4);

        uint32_t dataOff = rbe32(ih + 8);
        if (dataOff >= (uint32_t)dataSize) continue;

        img->imageData = (uint8_t*)(data + dataOff);
        img->imageDataSize = (int)gc_texture_data_size(img->width, img->height, img->format);

        // Palette
        img->paletteData = NULL;
        img->paletteFormat = 0;
        img->paletteEntries = 0;

        if (palOff != 0 && palOff + 12 <= (uint32_t)dataSize) {
            const uint8_t* ph = data + palOff;
            img->paletteEntries = rbe16(ph + 0);
            img->paletteFormat = (int)rbe32(ph + 4);
            uint32_t palDataOff = rbe32(ph + 8);
            if (palDataOff < (uint32_t)dataSize) {
                img->paletteData = (uint8_t*)(data + palDataOff);
            }
        }

        count++;
    }
    return count;
}
