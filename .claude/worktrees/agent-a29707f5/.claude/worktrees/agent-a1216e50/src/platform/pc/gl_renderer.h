#ifndef GL_RENDERER_H
#define GL_RENDERER_H

#if defined(_WIN32) || defined(__CYGWIN__)
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <GL/gl.h>
#endif

// Initialize OpenGL context on an existing Win32 HWND.
// Call this after creating the window.
// Returns 1 on success, 0 on failure.
int gl_init(void* hwnd);

// Shutdown OpenGL context.
void gl_shutdown(void);

// Begin a new frame (clear buffers).
void gl_begin_frame(void);

// End frame (swap buffers).
void gl_end_frame(void);

// Create an OpenGL texture from decoded RGBA pixels.
// Returns OpenGL texture ID, or 0 on failure.
unsigned int gl_create_texture(const unsigned char* rgba, int width, int height);

// Delete an OpenGL texture.
void gl_delete_texture(unsigned int texId);

// Bind an OpenGL texture for rendering.
void gl_bind_texture(unsigned int texId);

#endif // GL_RENDERER_H
