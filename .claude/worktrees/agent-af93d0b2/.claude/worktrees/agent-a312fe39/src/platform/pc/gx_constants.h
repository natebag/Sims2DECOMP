#ifndef GX_CONSTANTS_H
#define GX_CONSTANTS_H

// GX primitive types (GXPrimitive)
#define GX_QUADS          0x80
#define GX_TRIANGLES      0x90
#define GX_TRIANGLESTRIP  0x98
#define GX_TRIANGLEFAN    0xA0
#define GX_LINES          0xA8
#define GX_LINESTRIP      0xB0
#define GX_POINTS         0xB8

// GX cull mode (GXCullMode)
#define GX_CULL_NONE   0
#define GX_CULL_FRONT  1
#define GX_CULL_BACK   2
#define GX_CULL_ALL    3

// GX blend mode (GXBlendMode)
#define GX_BM_NONE     0
#define GX_BM_BLEND    1
#define GX_BM_LOGIC    2
#define GX_BM_SUBTRACT 3

// GX blend factor (GXBlendFactor)
#define GX_BL_ZERO        0
#define GX_BL_ONE         1
#define GX_BL_SRCCLR      2
#define GX_BL_INVSRCCLR   3
#define GX_BL_SRCALPHA    4
#define GX_BL_INVSRCALPHA 5
#define GX_BL_DSTALPHA    6
#define GX_BL_INVDSTALPHA 7
#define GX_BL_DSTCLR      GX_BL_SRCCLR
#define GX_BL_INVDSTCLR   GX_BL_INVSRCCLR

// GX compare function (GXCompare)
#define GX_NEVER   0
#define GX_LESS    1
#define GX_EQUAL   2
#define GX_LEQUAL  3
#define GX_GREATER 4
#define GX_NEQUAL  5
#define GX_GEQUAL  6
#define GX_ALWAYS  7

// GX TEV mode (GXTevMode) for SetTevOp convenience function
#define GX_MODULATE  0
#define GX_DECAL     1
#define GX_BLEND     2
#define GX_REPLACE   3
#define GX_PASSCLR   4

// GX fog type (GXFogType)
#define GX_FOG_NONE    0
#define GX_FOG_LIN     2
#define GX_FOG_EXP     4
#define GX_FOG_EXP2    5
#define GX_FOG_REXP    6
#define GX_FOG_REXP2   7

// GX texture format (GXTexFmt) — matches GCTexFormat in gc_texture_decode.h
#define GX_TF_I4      0
#define GX_TF_I8      1
#define GX_TF_IA4     2
#define GX_TF_IA8     3
#define GX_TF_RGB565  4
#define GX_TF_RGB5A3  5
#define GX_TF_RGBA8   6
#define GX_TF_C4      8
#define GX_TF_C8      9
#define GX_TF_C14X2   10
#define GX_TF_CMPR    14

// GX texture wrap mode (GXTexWrapMode)
#define GX_CLAMP   0
#define GX_REPEAT  1
#define GX_MIRROR  2

#endif // GX_CONSTANTS_H
