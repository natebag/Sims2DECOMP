#ifndef GX_VERTEX_BRIDGE_H
#define GX_VERTEX_BRIDGE_H

// Translates GX vertex submission calls to OpenGL.
// The GC game submits vertices in immediate mode:
//   GXBegin(primitive, vtxfmt, numVerts)
//   for each vertex:
//     GXPosition3f32(x, y, z)
//     GXNormal3f32(nx, ny, nz)
//     GXColor4u8(r, g, b, a)
//     GXTexCoord2f32(s, t)
//   GXEnd()
//
// We translate this to GL immediate mode (glBegin/glEnd).

void gx_vertex_begin(int primitive, int vtxfmt, int numVerts);
void gx_vertex_end(void);
void gx_vertex_position(float x, float y, float z);
void gx_vertex_normal(float nx, float ny, float nz);
void gx_vertex_color(unsigned char r, unsigned char g, unsigned char b, unsigned char a);
void gx_vertex_texcoord(float s, float t);

// GX matrix operations → GL
void gx_load_pos_mtx(float mtx[3][4], unsigned int id);
void gx_set_current_mtx(unsigned int id);

#endif // GX_VERTEX_BRIDGE_H
