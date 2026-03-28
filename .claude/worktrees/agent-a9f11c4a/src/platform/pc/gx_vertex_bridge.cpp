// gx_vertex_bridge.cpp — GX vertex submission → OpenGL translation
// Maps GameCube immediate-mode vertex calls to GL immediate mode.

#include "gx_vertex_bridge.h"
#include "gx_constants.h"
#include "gl_renderer.h"

#ifdef _WIN32
#include <GL/gl.h>
#include <stdio.h>
#include <string.h>

// ============================================================================
// GX → GL primitive type mapping
// ============================================================================

static GLenum gx_to_gl_primitive(int gxPrim) {
    switch (gxPrim) {
        case GX_QUADS:         return GL_QUADS;
        case GX_TRIANGLES:     return GL_TRIANGLES;
        case GX_TRIANGLESTRIP: return GL_TRIANGLE_STRIP;
        case GX_TRIANGLEFAN:   return GL_TRIANGLE_FAN;
        case GX_LINES:         return GL_LINES;
        case GX_LINESTRIP:     return GL_LINE_STRIP;
        case GX_POINTS:        return GL_POINTS;
        default:               return GL_TRIANGLES;
    }
}

// ============================================================================
// Matrix storage
// GX supports 10 position/normal matrix slots (PNMTX0-9)
// ============================================================================

#define GX_MAX_PNMTX 10

// GX uses 3x4 row-major matrices; GL uses 4x4 column-major
static float g_posMtx[GX_MAX_PNMTX][16];  // stored as GL 4x4 column-major
static int g_currentMtx = 0;

// Convert GX 3x4 row-major → GL 4x4 column-major
static void gx_mtx_to_gl(float src[3][4], float* dst) {
    // GX:   | m00 m01 m02 m03 |    GL:  | m00 m10 m20 0 |
    //       | m10 m11 m12 m13 |         | m01 m11 m21 0 |
    //       | m20 m21 m22 m23 |         | m02 m12 m22 0 |
    //                                   | m03 m13 m23 1 |
    dst[0]  = src[0][0]; dst[1]  = src[1][0]; dst[2]  = src[2][0]; dst[3]  = 0;
    dst[4]  = src[0][1]; dst[5]  = src[1][1]; dst[6]  = src[2][1]; dst[7]  = 0;
    dst[8]  = src[0][2]; dst[9]  = src[1][2]; dst[10] = src[2][2]; dst[11] = 0;
    dst[12] = src[0][3]; dst[13] = src[1][3]; dst[14] = src[2][3]; dst[15] = 1;
}

// ============================================================================
// State tracking
// ============================================================================

static int g_inBeginEnd = 0;

// ============================================================================
// Public API
// ============================================================================

void gx_vertex_begin(int primitive, int vtxfmt, int numVerts) {
    (void)vtxfmt;
    (void)numVerts;
    GLenum glPrim = gx_to_gl_primitive(primitive);
    glBegin(glPrim);
    g_inBeginEnd = 1;
}

void gx_vertex_end(void) {
    if (g_inBeginEnd) {
        glEnd();
        g_inBeginEnd = 0;
    }
}

void gx_vertex_position(float x, float y, float z) {
    glVertex3f(x, y, z);
}

void gx_vertex_normal(float nx, float ny, float nz) {
    glNormal3f(nx, ny, nz);
}

void gx_vertex_color(unsigned char r, unsigned char g, unsigned char b, unsigned char a) {
    glColor4ub(r, g, b, a);
}

void gx_vertex_texcoord(float s, float t) {
    glTexCoord2f(s, t);
}

void gx_load_pos_mtx(float mtx[3][4], unsigned int id) {
    if (id >= GX_MAX_PNMTX) return;
    gx_mtx_to_gl(mtx, g_posMtx[id]);
}

void gx_set_current_mtx(unsigned int id) {
    if (id >= GX_MAX_PNMTX) return;
    g_currentMtx = (int)id;
    glMatrixMode(GL_MODELVIEW);
    glLoadMatrixf(g_posMtx[id]);
}

#endif // _WIN32
