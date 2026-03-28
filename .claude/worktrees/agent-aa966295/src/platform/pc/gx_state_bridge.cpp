// gx_state_bridge.cpp — GX render state → OpenGL translation

#include "gx_state_bridge.h"
#include "gx_constants.h"
#include "gl_renderer.h"

#ifdef _WIN32
#include <GL/gl.h>

// ============================================================================
// GX → GL compare function mapping
// ============================================================================

static GLenum gx_to_gl_compare(int gxCmp) {
    switch (gxCmp) {
        case GX_NEVER:   return GL_NEVER;
        case GX_LESS:    return GL_LESS;
        case GX_EQUAL:   return GL_EQUAL;
        case GX_LEQUAL:  return GL_LEQUAL;
        case GX_GREATER: return GL_GREATER;
        case GX_NEQUAL:  return GL_NOTEQUAL;
        case GX_GEQUAL:  return GL_GEQUAL;
        case GX_ALWAYS:  return GL_ALWAYS;
        default:         return GL_LEQUAL;
    }
}

// ============================================================================
// GX → GL blend factor mapping
// ============================================================================

static GLenum gx_to_gl_blend_factor(int gxFactor) {
    switch (gxFactor) {
        case GX_BL_ZERO:        return GL_ZERO;
        case GX_BL_ONE:         return GL_ONE;
        case GX_BL_SRCCLR:      return GL_SRC_COLOR;
        case GX_BL_INVSRCCLR:   return GL_ONE_MINUS_SRC_COLOR;
        case GX_BL_SRCALPHA:    return GL_SRC_ALPHA;
        case GX_BL_INVSRCALPHA: return GL_ONE_MINUS_SRC_ALPHA;
        case GX_BL_DSTALPHA:    return GL_DST_ALPHA;
        case GX_BL_INVDSTALPHA: return GL_ONE_MINUS_DST_ALPHA;
        default:                return GL_ONE;
    }
}

// ============================================================================
// Viewport & Scissor
// ============================================================================

void gx_state_set_viewport(float x, float y, float w, float h, float nearZ, float farZ) {
    glViewport((int)x, (int)y, (int)w, (int)h);
    glDepthRange((double)nearZ, (double)farZ);
}

void gx_state_set_scissor(unsigned int x, unsigned int y, unsigned int w, unsigned int h) {
    glEnable(GL_SCISSOR_TEST);
    glScissor((int)x, (int)y, (int)w, (int)h);
}

// ============================================================================
// Cull mode
// ============================================================================

void gx_state_set_cull_mode(int mode) {
    switch (mode) {
        case GX_CULL_NONE:
            glDisable(GL_CULL_FACE);
            break;
        case GX_CULL_FRONT:
            glEnable(GL_CULL_FACE);
            glCullFace(GL_FRONT);
            break;
        case GX_CULL_BACK:
            glEnable(GL_CULL_FACE);
            glCullFace(GL_BACK);
            break;
        case GX_CULL_ALL:
            glEnable(GL_CULL_FACE);
            glCullFace(GL_FRONT_AND_BACK);
            break;
    }
}

// ============================================================================
// Blend mode
// ============================================================================

void gx_state_set_blend_mode(int type, int srcFactor, int dstFactor, int logicOp) {
    switch (type) {
        case GX_BM_NONE:
            glDisable(GL_BLEND);
            break;
        case GX_BM_BLEND:
            glEnable(GL_BLEND);
            glBlendFunc(gx_to_gl_blend_factor(srcFactor),
                        gx_to_gl_blend_factor(dstFactor));
            break;
        case GX_BM_SUBTRACT:
            glEnable(GL_BLEND);
            glBlendFunc(gx_to_gl_blend_factor(srcFactor),
                        gx_to_gl_blend_factor(dstFactor));
            // GL_FUNC_REVERSE_SUBTRACT would be ideal but needs GL 1.4+
            break;
        case GX_BM_LOGIC:
            // Logic ops not commonly used in Sims 2
            glDisable(GL_BLEND);
            break;
    }
}

// ============================================================================
// Depth test
// ============================================================================

void gx_state_set_z_mode(int enable, int func, int updateEnable) {
    if (enable) {
        glEnable(GL_DEPTH_TEST);
        glDepthFunc(gx_to_gl_compare(func));
    } else {
        glDisable(GL_DEPTH_TEST);
    }
    glDepthMask(updateEnable ? GL_TRUE : GL_FALSE);
}

// ============================================================================
// Alpha test
// ============================================================================

void gx_state_set_alpha_compare(int comp0, unsigned char ref0, int op,
                                 int comp1, unsigned char ref1) {
    // GL only supports one alpha test function (pre-shader era)
    // Use the first comparator as approximation
    if (comp0 == GX_ALWAYS && comp1 == GX_ALWAYS) {
        glDisable(GL_ALPHA_TEST);
    } else {
        glEnable(GL_ALPHA_TEST);
        glAlphaFunc(gx_to_gl_compare(comp0), (float)ref0 / 255.0f);
    }
}

// ============================================================================
// Color/alpha update masks
// ============================================================================

void gx_state_set_color_update(int enable) {
    // GL_COLOR_WRITEMASK covers RGB
    GLboolean b = enable ? GL_TRUE : GL_FALSE;
    glColorMask(b, b, b, GL_TRUE);
}

void gx_state_set_alpha_update(int enable) {
    // Just the alpha channel
    GLboolean r, g, b;
    glGetBooleanv(GL_COLOR_WRITEMASK, &r); // simplified — always enable RGB
    GLboolean a = enable ? GL_TRUE : GL_FALSE;
    glColorMask(GL_TRUE, GL_TRUE, GL_TRUE, a);
}

// ============================================================================
// Fog
// ============================================================================

void gx_state_set_fog(int type, float startz, float endz, float nearz, float farz,
                       unsigned char r, unsigned char g, unsigned char b, unsigned char a) {
    if (type == GX_FOG_NONE) {
        glDisable(GL_FOG);
        return;
    }

    glEnable(GL_FOG);
    GLfloat fogColor[4] = {r / 255.0f, g / 255.0f, b / 255.0f, a / 255.0f};
    glFogfv(GL_FOG_COLOR, fogColor);
    glFogf(GL_FOG_START, startz);
    glFogf(GL_FOG_END, endz);

    switch (type) {
        case GX_FOG_LIN:
            glFogi(GL_FOG_MODE, GL_LINEAR);
            break;
        case GX_FOG_EXP:
        case GX_FOG_REXP:
            glFogi(GL_FOG_MODE, GL_EXP);
            break;
        case GX_FOG_EXP2:
        case GX_FOG_REXP2:
            glFogi(GL_FOG_MODE, GL_EXP2);
            break;
    }
}

// ============================================================================
// Frame operations
// ============================================================================

void gx_state_copy_disp(void* dest, int clear) {
    // CopyDisp on GC copies EFB → XFB (triggers display)
    // On PC this is handled by SwapBuffers in gl_end_frame()
    (void)dest;
    (void)clear;
}

void gx_state_draw_done(void) {
    glFinish();
}

#endif // _WIN32
