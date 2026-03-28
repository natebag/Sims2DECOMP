// Standalone texture test harness
// Reads a .tpl file, decodes GC textures, dumps to .bmp
//
// Build:
//   g++ -std=c++17 -O2 -o texture_test tools/texture_test.cpp \
//       src/platform/pc/gc_texture_decode.cpp src/platform/pc/tpl_parser.cpp
//
// Usage:
//   ./texture_test extracted/files/ngcbanner.tpl
//   ./texture_test extracted/files/ngcicon.tpl

#include "../src/platform/pc/tpl_parser.h"
#include "../src/platform/pc/gc_texture_decode.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

// ============================================================================
// BMP writer
// ============================================================================

static int write_bmp(const char* filename, const uint8_t* rgba, int w, int h) {
    FILE* f = fopen(filename, "wb");
    if (!f) return -1;

    int rowBytes = w * 3;
    int padBytes = (4 - (rowBytes % 4)) % 4;
    int stride = rowBytes + padBytes;
    int imageSize = stride * h;
    int fileSize = 54 + imageSize;

    // BMP header
    uint8_t hdr[54] = {0};
    hdr[0] = 'B'; hdr[1] = 'M';
    hdr[2] = fileSize & 0xFF; hdr[3] = (fileSize >> 8) & 0xFF;
    hdr[4] = (fileSize >> 16) & 0xFF; hdr[5] = (fileSize >> 24) & 0xFF;
    hdr[10] = 54; // data offset
    hdr[14] = 40; // DIB header size
    hdr[18] = w & 0xFF; hdr[19] = (w >> 8) & 0xFF;
    hdr[22] = h & 0xFF; hdr[23] = (h >> 8) & 0xFF;
    hdr[26] = 1;  // planes
    hdr[28] = 24; // bits per pixel
    hdr[34] = imageSize & 0xFF; hdr[35] = (imageSize >> 8) & 0xFF;
    hdr[36] = (imageSize >> 16) & 0xFF; hdr[37] = (imageSize >> 24) & 0xFF;

    fwrite(hdr, 1, 54, f);

    // BMP stores bottom-to-top, BGR
    uint8_t pad[3] = {0, 0, 0};
    for (int y = h - 1; y >= 0; y--) {
        for (int x = 0; x < w; x++) {
            int idx = (y * w + x) * 4;
            uint8_t bgr[3] = {rgba[idx + 2], rgba[idx + 1], rgba[idx + 0]};
            fwrite(bgr, 1, 3, f);
        }
        if (padBytes > 0) fwrite(pad, 1, padBytes, f);
    }

    fclose(f);
    return 0;
}

// ============================================================================
// GC texture format name
// ============================================================================

static const char* format_name(int fmt) {
    switch (fmt) {
        case GC_TF_I4:     return "I4";
        case GC_TF_I8:     return "I8";
        case GC_TF_IA4:    return "IA4";
        case GC_TF_IA8:    return "IA8";
        case GC_TF_RGB565: return "RGB565";
        case GC_TF_RGB5A3: return "RGB5A3";
        case GC_TF_RGBA8:  return "RGBA8";
        case GC_TF_C4:     return "C4";
        case GC_TF_C8:     return "C8";
        case GC_TF_C14X2:  return "C14X2";
        case GC_TF_CMPR:   return "CMPR";
        default:           return "UNKNOWN";
    }
}

// ============================================================================
// Main
// ============================================================================

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s <file.tpl> [output.bmp]\n", argv[0]);
        printf("  Decodes a GameCube TPL texture and dumps to BMP.\n");
        return 1;
    }

    const char* inputPath = argv[1];

    // Read entire file
    FILE* f = fopen(inputPath, "rb");
    if (!f) {
        printf("ERROR: Cannot open %s\n", inputPath);
        return 1;
    }
    fseek(f, 0, SEEK_END);
    long fileSize = ftell(f);
    fseek(f, 0, SEEK_SET);

    uint8_t* data = (uint8_t*)malloc(fileSize);
    fread(data, 1, fileSize, f);
    fclose(f);

    printf("Loaded %s (%ld bytes)\n", inputPath, fileSize);

    // Parse TPL
    TPLImage images[64];
    int numImages = tpl_parse(data, (int)fileSize, images, 64);
    if (numImages <= 0) {
        printf("ERROR: Failed to parse TPL (got %d)\n", numImages);
        free(data);
        return 1;
    }

    printf("TPL contains %d image(s)\n\n", numImages);

    for (int i = 0; i < numImages; i++) {
        TPLImage* img = &images[i];
        printf("  Image %d: %dx%d, format=%s (%d)\n",
               i, img->width, img->height, format_name(img->format), img->format);

        if (img->paletteData) {
            printf("    Palette: %d entries, format=%d\n",
                   img->paletteEntries, img->paletteFormat);
        }

        size_t expectedSize = gc_texture_data_size(img->width, img->height, img->format);
        printf("    Data size: %d bytes (expected: %zu)\n", img->imageDataSize, expectedSize);

        // Decode to RGBA
        int pixelCount = img->width * img->height;
        uint8_t* rgba = (uint8_t*)calloc(pixelCount * 4, 1);

        int ret = gc_texture_decode(
            img->imageData, rgba,
            img->width, img->height, img->format,
            img->paletteData, img->paletteFormat
        );

        if (ret != 0) {
            printf("    ERROR: Decode failed (unsupported format?)\n");
            free(rgba);
            continue;
        }

        // Build output filename
        char outPath[512];
        if (argc > 2 && numImages == 1) {
            snprintf(outPath, sizeof(outPath), "%s", argv[2]);
        } else {
            // Strip extension from input, add _N.bmp
            char base[256];
            strncpy(base, inputPath, sizeof(base) - 1);
            base[sizeof(base) - 1] = '\0';
            char* dot = strrchr(base, '.');
            if (dot) *dot = '\0';
            snprintf(outPath, sizeof(outPath), "%s_%d.bmp", base, i);
        }

        if (write_bmp(outPath, rgba, img->width, img->height) == 0) {
            printf("    Wrote: %s\n", outPath);
        } else {
            printf("    ERROR: Failed to write %s\n", outPath);
        }

        free(rgba);
    }

    free(data);
    printf("\nDone!\n");
    return 0;
}
