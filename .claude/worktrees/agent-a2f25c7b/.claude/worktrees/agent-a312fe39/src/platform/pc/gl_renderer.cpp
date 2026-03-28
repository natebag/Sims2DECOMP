// gl_renderer.cpp — OpenGL rendering context and texture management for Sims 2 PC port
// Uses Win32 WGL for OpenGL context creation (no GLEW/GLAD needed for GL 1.x)

#include "gl_renderer.h"

#if defined(_WIN32) || defined(__CYGWIN__)

#include <stdio.h>

static HWND  g_hwnd = NULL;
static HDC   g_hdc  = NULL;
static HGLRC g_hrc  = NULL;

int gl_init(void* hwnd) {
    g_hwnd = (HWND)hwnd;
    g_hdc = GetDC(g_hwnd);
    if (!g_hdc) {
        printf("[GL] Failed to get device context\n");
        return 0;
    }

    // Set pixel format
    PIXELFORMATDESCRIPTOR pfd = {};
    pfd.nSize = sizeof(pfd);
    pfd.nVersion = 1;
    pfd.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
    pfd.iPixelType = PFD_TYPE_RGBA;
    pfd.cColorBits = 32;
    pfd.cDepthBits = 24;
    pfd.cStencilBits = 8;
    pfd.iLayerType = PFD_MAIN_PLANE;

    int pixelFormat = ChoosePixelFormat(g_hdc, &pfd);
    if (!pixelFormat) {
        printf("[GL] ChoosePixelFormat failed\n");
        return 0;
    }
    if (!SetPixelFormat(g_hdc, pixelFormat, &pfd)) {
        printf("[GL] SetPixelFormat failed\n");
        return 0;
    }

    // Create OpenGL context
    g_hrc = wglCreateContext(g_hdc);
    if (!g_hrc) {
        printf("[GL] wglCreateContext failed\n");
        return 0;
    }
    if (!wglMakeCurrent(g_hdc, g_hrc)) {
        printf("[GL] wglMakeCurrent failed\n");
        return 0;
    }

    // Report GL info
    printf("[GL] Vendor:   %s\n", glGetString(GL_VENDOR));
    printf("[GL] Renderer: %s\n", glGetString(GL_RENDERER));
    printf("[GL] Version:  %s\n", glGetString(GL_VERSION));

    // Basic GL setup
    glClearColor(0.0f, 0.0f, 0.2f, 1.0f);  // dark blue (proof of life)
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_TEXTURE_2D);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    // Set up a simple orthographic projection for 2D (640x480 GC framebuffer)
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, 640, 480, 0, -1, 1);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    printf("[GL] OpenGL context initialized successfully\n");
    return 1;
}

void gl_shutdown(void) {
    if (g_hrc) {
        wglMakeCurrent(NULL, NULL);
        wglDeleteContext(g_hrc);
        g_hrc = NULL;
    }
    if (g_hdc && g_hwnd) {
        ReleaseDC(g_hwnd, g_hdc);
        g_hdc = NULL;
    }
    g_hwnd = NULL;
}

void gl_begin_frame(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void gl_end_frame(void) {
    if (g_hdc) {
        SwapBuffers(g_hdc);
    }
}

unsigned int gl_create_texture(const unsigned char* rgba, int width, int height) {
    GLuint texId;
    glGenTextures(1, &texId);
    glBindTexture(GL_TEXTURE_2D, texId);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0,
                 GL_RGBA, GL_UNSIGNED_BYTE, rgba);

    return (unsigned int)texId;
}

void gl_delete_texture(unsigned int texId) {
    GLuint id = (GLuint)texId;
    glDeleteTextures(1, &id);
}

void gl_bind_texture(unsigned int texId) {
    glBindTexture(GL_TEXTURE_2D, (GLuint)texId);
}

#endif // _WIN32
