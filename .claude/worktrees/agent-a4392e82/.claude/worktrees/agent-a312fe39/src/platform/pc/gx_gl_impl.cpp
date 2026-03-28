// gx_gl_impl.cpp — OpenGL implementations for GX state/vertex/matrix functions
// These bridge the gap between the GX stub layer and real OpenGL calls.

#if defined(_WIN32) || defined(__CYGWIN__)
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <GL/gl.h>
#endif

#include <cstdio>

// ============================================================================
// GX State → OpenGL
// ============================================================================

void gx_state_set_viewport(float x, float y, float w, float h, float nearZ, float farZ) {
    glViewport((int)x, (int)y, (int)w, (int)h);
    glDepthRange(nearZ, farZ);
}

void gx_state_set_scissor(unsigned int x, unsigned int y, unsigned int w, unsigned int h) {
    glScissor(x, y, w, h);
}

void gx_state_set_cull_mode(int mode) {
    if (mode == 0) { // GX_CULL_NONE
        glDisable(GL_CULL_FACE);
    } else {
        glEnable(GL_CULL_FACE);
        glCullFace(mode == 1 ? GL_FRONT : GL_BACK);
    }
}

void gx_state_set_blend_mode(int type, int src, int dst, int op) {
    if (type == 0) { // GX_BM_NONE
        glDisable(GL_BLEND);
    } else {
        glEnable(GL_BLEND);
        // Map GX blend factors to GL (simplified)
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    }
}

void gx_state_set_z_mode(int enable, int func, int update) {
    if (enable) {
        glEnable(GL_DEPTH_TEST);
        // Map GX compare to GL (simplified — GX_LEQUAL most common)
        glDepthFunc(GL_LEQUAL);
    } else {
        glDisable(GL_DEPTH_TEST);
    }
    glDepthMask(update ? GL_TRUE : GL_FALSE);
}

void gx_state_set_alpha_compare(int comp0, unsigned char ref0, int op, int comp1, unsigned char ref1) {
    glEnable(GL_ALPHA_TEST);
    glAlphaFunc(GL_GREATER, ref0 / 255.0f);
}

void gx_state_set_color_update(int enable) {
    glColorMask(enable, enable, enable, enable);
}

void gx_state_set_alpha_update(int enable) {
    // Alpha mask is part of glColorMask's 4th parameter
    // Already handled by color update for now
}

void gx_state_copy_disp(void* dest, int clear) {
    // Frame copy — handled by SwapBuffers in gl_end_frame
}

void gx_state_draw_done() {
    glFinish();
}

// ============================================================================
// GX Vertex submission → OpenGL immediate mode
// ============================================================================

void gx_vertex_begin(int primitive, int vtxfmt, int nverts) {
    // Map GX primitives to GL
    GLenum mode;
    switch (primitive) {
        case 0x80: mode = GL_QUADS; break;          // GX_QUADS
        case 0x90: mode = GL_TRIANGLES; break;       // GX_TRIANGLES
        case 0x98: mode = GL_TRIANGLE_STRIP; break;  // GX_TRIANGLESTRIP
        case 0xA0: mode = GL_TRIANGLE_FAN; break;    // GX_TRIANGLEFAN
        case 0xA8: mode = GL_LINES; break;           // GX_LINES
        case 0xB0: mode = GL_LINE_STRIP; break;      // GX_LINESTRIP
        case 0xB8: mode = GL_POINTS; break;          // GX_POINTS
        default:   mode = GL_TRIANGLES; break;
    }
    glBegin(mode);
}

void gx_vertex_end() {
    glEnd();
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

// ============================================================================
// GX Matrix → OpenGL
// ============================================================================

void gx_load_pos_mtx(float mtx[3][4], unsigned int id) {
    // Convert 3x4 row-major to 4x4 column-major for OpenGL
    float gl_mtx[16] = {
        mtx[0][0], mtx[1][0], mtx[2][0], 0.0f,
        mtx[0][1], mtx[1][1], mtx[2][1], 0.0f,
        mtx[0][2], mtx[1][2], mtx[2][2], 0.0f,
        mtx[0][3], mtx[1][3], mtx[2][3], 1.0f,
    };
    if (id == 0) { // GX_PNMTX0 — primary model-view matrix
        glMatrixMode(GL_MODELVIEW);
        glLoadMatrixf(gl_mtx);
    }
}

void gx_set_current_mtx(unsigned int id) {
    // Matrix ID selection — OpenGL doesn't need this with immediate mode
}
