#ifndef GX_STATE_BRIDGE_H
#define GX_STATE_BRIDGE_H

// Translates GX render state calls to OpenGL.

void gx_state_set_viewport(float x, float y, float w, float h, float nearZ, float farZ);
void gx_state_set_scissor(unsigned int x, unsigned int y, unsigned int w, unsigned int h);
void gx_state_set_cull_mode(int mode);
void gx_state_set_blend_mode(int type, int srcFactor, int dstFactor, int logicOp);
void gx_state_set_z_mode(int enable, int func, int updateEnable);
void gx_state_set_alpha_compare(int comp0, unsigned char ref0, int op, int comp1, unsigned char ref1);
void gx_state_set_color_update(int enable);
void gx_state_set_alpha_update(int enable);
void gx_state_set_fog(int type, float startz, float endz, float nearz, float farz,
                       unsigned char r, unsigned char g, unsigned char b, unsigned char a);
void gx_state_copy_disp(void* dest, int clear);
void gx_state_draw_done(void);

#endif // GX_STATE_BRIDGE_H
