// gx_texture_bridge.cpp — Translates GX texture calls to OpenGL
// Decodes GameCube tile-swizzled textures to linear RGBA for GL

#include "gx_texture_bridge.h"
#include "gc_texture_decode.h"
#include "gl_renderer.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Simple texture cache — maps GC image pointers to GL texture IDs
// The game typically has <100 textures active at once
#define TEX_CACHE_SIZE 512

struct TexCacheEntry {
    void*        imgPtr;    // GC image data pointer (cache key)
    unsigned int glTexId;   // OpenGL texture ID
    int          width;
    int          height;
    int          format;
};

static TexCacheEntry g_texCache[TEX_CACHE_SIZE];
static int g_texCacheCount = 0;

// Currently bound textures per GX map slot
static unsigned int g_boundTex[GX_MAX_TEXMAP];

// ============================================================================
// Cache operations
// ============================================================================

static TexCacheEntry* cache_find(void* imgPtr) {
    for (int i = 0; i < g_texCacheCount; i++) {
        if (g_texCache[i].imgPtr == imgPtr)
            return &g_texCache[i];
    }
    return NULL;
}

static TexCacheEntry* cache_add(void* imgPtr, unsigned int glTexId,
                                 int w, int h, int fmt) {
    if (g_texCacheCount >= TEX_CACHE_SIZE) {
        // Evict oldest entry
        gl_delete_texture(g_texCache[0].glTexId);
        memmove(&g_texCache[0], &g_texCache[1],
                (TEX_CACHE_SIZE - 1) * sizeof(TexCacheEntry));
        g_texCacheCount = TEX_CACHE_SIZE - 1;
    }
    TexCacheEntry* e = &g_texCache[g_texCacheCount++];
    e->imgPtr = imgPtr;
    e->glTexId = glTexId;
    e->width = w;
    e->height = h;
    e->format = fmt;
    return e;
}

// ============================================================================
// GXTexObj layout
// We store our GL texture ID and metadata in the GXTexObj struct
// which the game allocates (8 uint32s = 32 bytes)
// ============================================================================

// Pack our data into the GXTexObj the game gives us
struct GXTexObjPC {
    unsigned int glTexId;   // [0]
    void*        imgPtr;    // [1]
    int          width;     // [2]
    int          height;    // [3]
    int          format;    // [4]
    int          wrapS;     // [5]
    int          wrapT;     // [6]
    int          mipmap;    // [7]
};

// ============================================================================
// Public API
// ============================================================================

void gx_tex_bridge_init(void) {
    memset(g_texCache, 0, sizeof(g_texCache));
    g_texCacheCount = 0;
    memset(g_boundTex, 0, sizeof(g_boundTex));
}

void gx_tex_bridge_init_obj(void* texObj, void* imgPtr,
                             int width, int height, int format) {
    GXTexObjPC* obj = (GXTexObjPC*)texObj;
    obj->imgPtr = imgPtr;
    obj->width = width;
    obj->height = height;
    obj->format = format;
    obj->glTexId = 0;

    if (!imgPtr || width <= 0 || height <= 0) return;

    // Check cache first
    TexCacheEntry* cached = cache_find(imgPtr);
    if (cached) {
        obj->glTexId = cached->glTexId;
        return;
    }

    // Decode GC texture to RGBA
    int pixelCount = width * height;
    unsigned char* rgba = (unsigned char*)calloc(pixelCount * 4, 1);
    if (!rgba) return;

    int ret = gc_texture_decode(
        (const unsigned char*)imgPtr, rgba,
        width, height, format,
        NULL, 0  // palette handled separately for indexed formats
    );

    if (ret != 0) {
        // Unsupported format — fill with magenta checkerboard for debugging
        for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++) {
                int idx = (y * width + x) * 4;
                int checker = ((x / 4) + (y / 4)) & 1;
                rgba[idx + 0] = checker ? 255 : 128;  // R
                rgba[idx + 1] = 0;                     // G
                rgba[idx + 2] = checker ? 255 : 128;   // B
                rgba[idx + 3] = 255;                    // A
            }
        }
    }

    // Create GL texture
    unsigned int glTex = gl_create_texture(rgba, width, height);
    free(rgba);

    obj->glTexId = glTex;

    // Add to cache
    if (glTex != 0) {
        cache_add(imgPtr, glTex, width, height, format);
    }
}

void gx_tex_bridge_load_obj(void* texObj, int mapId) {
    if (mapId < 0 || mapId >= GX_MAX_TEXMAP) return;

    GXTexObjPC* obj = (GXTexObjPC*)texObj;
    g_boundTex[mapId] = obj->glTexId;

    // Bind for immediate use (GL active texture 0)
    if (mapId == 0 && obj->glTexId != 0) {
        gl_bind_texture(obj->glTexId);
    }
}

void gx_tex_bridge_invalidate_all(void) {
    // Delete all cached GL textures
    for (int i = 0; i < g_texCacheCount; i++) {
        if (g_texCache[i].glTexId != 0) {
            gl_delete_texture(g_texCache[i].glTexId);
        }
    }
    g_texCacheCount = 0;
    memset(g_boundTex, 0, sizeof(g_boundTex));
}
