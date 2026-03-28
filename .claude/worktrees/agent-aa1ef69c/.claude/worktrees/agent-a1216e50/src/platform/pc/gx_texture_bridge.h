#ifndef GX_TEXTURE_BRIDGE_H
#define GX_TEXTURE_BRIDGE_H

// Bridge between GX texture calls and OpenGL.
// When the game calls GXInitTexObj, we decode the GC texture data
// to RGBA and create an OpenGL texture. When GXLoadTexObj is called,
// we bind the corresponding GL texture.

// Maximum simultaneous textures (GX supports 8 texture map IDs)
#define GX_MAX_TEXMAP 8

// Internal texture slot
struct GXTexSlot {
    unsigned int glTexId;   // OpenGL texture ID (0 = empty)
    void*        imgPtr;    // original GC image data pointer (for cache key)
    int          width;
    int          height;
    int          format;    // GCTexFormat
};

// Initialize the texture bridge (call once at startup)
void gx_tex_bridge_init(void);

// Called from GXInitTexObj — decodes GC texture and creates GL texture
void gx_tex_bridge_init_obj(void* texObj, void* imgPtr,
                             int width, int height, int format);

// Called from GXLoadTexObj — binds the GL texture for rendering
void gx_tex_bridge_load_obj(void* texObj, int mapId);

// Called from GXInvalidateTexAll — clears texture cache
void gx_tex_bridge_invalidate_all(void);

#endif // GX_TEXTURE_BRIDGE_H
