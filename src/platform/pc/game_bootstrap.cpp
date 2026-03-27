// game_bootstrap.cpp — PC port game initialization and state machine
//
// Implements a progressive boot sequence:
//   BOOT (2s) → LOGO (3s) → MAIN_MENU (interactive)
//
// Each state handles its own update + render. This replaces the GC-specific
// ESimsApp::Init/Update chain with PC-native equivalents that route through
// our OpenGL renderer and arc_reader.

#include "types.h"
#include "platform/arc_reader.h"
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cstdarg>
#include <cmath>
#include "gl_renderer.h"  // pulls in windows.h + GL/gl.h on Win32
#include "ea_texture.h"
#include "gc_texture_decode.h"

// ============================================================================
// Global singletons that the decomp code expects to exist
// ============================================================================

struct PCEAHeap {
    void* Malloc(unsigned int size, int flags) { return malloc(size); }
    void* MallocAligned(unsigned int size, unsigned int align, int flags) { return malloc(size); }
    void  Free(void* ptr) { free(ptr); }
};

static PCEAHeap g_mainHeap;
static PCEAHeap g_rootHeap;

extern "C" {
    void* MainHeap_PC(void) { return &g_mainHeap; }
    void* RootHeap_PC(void) { return &g_rootHeap; }
}

// Zeroed buffers for global singletons (decomp code accesses fields by offset)
static u8 g_eGlobal[8192] = {};
static void* g_pEGlobal = g_eGlobal;
static u8 g_eSimsApp[4096] = {};
static u8 g_eNgcEngine[2048] = {};
static u8 g_eControllerManager[512] = {};
static u8 g_stateMachineManager[256] = {};

// ============================================================================
// Logging
// ============================================================================

static FILE* g_logFile = nullptr;

static void log_boot(const char* fmt, ...) {
    if (!g_logFile) g_logFile = fopen("sims2pc.log", "w");
    if (g_logFile) {
        va_list args;
        va_start(args, fmt);
        vfprintf(g_logFile, fmt, args);
        va_end(args);
        fflush(g_logFile);
    }
}

// ============================================================================
// Texture loading from .arc archives
// ============================================================================

static unsigned int g_titleTexture = 0;   // GL texture ID for title background
static unsigned int g_maxisLogoTex = 0;   // GL texture ID for Maxis logo
static unsigned int g_teamPicTex = 0;     // GL texture ID for team picture

// Detect EA texture header offset in raw data.
// The .arc format stores a variable-length prefix (1-8 bytes) before the
// actual 32-byte EA texture header. We scan for valid dimensions + format.
static int find_ea_header_offset(const u8* data, unsigned int dataSize) {
    for (int off = 0; off <= 16 && off + 32 <= (int)dataSize; off++) {
        u16 w = (u16)(data[off + 0x10] << 8 | data[off + 0x11]);
        u16 h = (u16)(data[off + 0x12] << 8 | data[off + 0x13]);
        u8 fmt = data[off + 0x18];
        u8 bpp = data[off + 0x1A];

        // Width and height must be powers of 2, 4-1024
        if (w < 4 || w > 1024 || h < 4 || h > 1024) continue;
        if ((w & (w - 1)) != 0 || (h & (h - 1)) != 0) continue;

        // Format must be a valid EA texture format
        bool validFmt = (fmt == 0x81 || fmt == 0x82 || fmt == 0x83 ||
                         fmt == 0x84 || fmt == 0x85 || fmt == 0x89 ||
                         fmt == 0x8A || fmt == 0x00 || fmt == 0x01);
        if (!validFmt) continue;

        // BPP must be sensible
        if (bpp != 2 && bpp != 4 && bpp != 8 && bpp != 16 && bpp != 32) continue;

        return off;
    }
    return -1;
}

// Load an EA texture from an archive entry and upload to OpenGL.
// Returns GL texture ID, or 0 on failure.
static unsigned int load_arc_texture(const char* name) {
    // Search all archives for the named texture
    for (int i = 0; i < arc_count(); i++) {
        ArcArchive* arc = arc_get(i);
        if (!arc) continue;

        ArcEntry* entry = arc_find(arc, name);
        if (!entry) continue;

        unsigned int dataSize = 0;
        u8* rawData = (u8*)arc_read(arc, entry, &dataSize);
        if (!rawData || dataSize < 48) {
            free(rawData);
            continue;
        }

        // Find EA texture header within the data
        int headerOff = find_ea_header_offset(rawData, dataSize);
        if (headerOff < 0) {
            log_boot("[TEX] Can't find EA header for '%s' (first 8: %02X %02X %02X %02X %02X %02X %02X %02X)\n",
                     name, rawData[0], rawData[1], rawData[2], rawData[3],
                     rawData[4], rawData[5], rawData[6], rawData[7]);
            free(rawData);
            continue;
        }

        // Parse EA texture header
        EATexHeader header;
        if (ea_tex_parse_header(rawData + headerOff, &header) != 0) {
            log_boot("[TEX] Failed to parse header for '%s' at offset %d\n", name, headerOff);
            free(rawData);
            continue;
        }

        int gcFmt = ea_format_to_gc(header.format);
        if (gcFmt < 0) {
            log_boot("[TEX] Unsupported format 0x%02X for '%s'\n", header.format, name);
            free(rawData);
            continue;
        }

        log_boot("[TEX] '%s': %dx%d fmt=0x%02X gcFmt=%d bpp=%d (header at +%d)\n",
                 name, header.width, header.height, header.format, gcFmt, header.bpp, headerOff);

        // Pixel data starts after the prefix + 32-byte EA header
        const u8* pixelData = rawData + headerOff + 32;

        // For palette formats, palette comes after pixel data
        const u8* palette = NULL;
        if (gcFmt == GC_TF_C4 || gcFmt == GC_TF_C8) {
            size_t imgSize = gc_texture_data_size(header.width, header.height, gcFmt);
            palette = pixelData + imgSize;
        }

        // Decode to RGBA
        int w = header.width, h = header.height;
        u8* rgba = (u8*)malloc(w * h * 4);
        if (!rgba) {
            free(rawData);
            continue;
        }

        int result = gc_texture_decode(pixelData, rgba, w, h, gcFmt, palette, GC_TL_RGB5A3);
        if (result != 0) {
            log_boot("[TEX] Decode failed for '%s'\n", name);
            free(rgba);
            free(rawData);
            continue;
        }

        // Upload to OpenGL
        unsigned int texId = gl_create_texture(rgba, w, h);
        log_boot("[TEX] Uploaded '%s' as GL texture %u (%dx%d)\n", name, texId, w, h);

        free(rgba);
        free(rawData);
        return texId;
    }

    log_boot("[TEX] '%s' not found in any archive\n", name);
    return 0;
}

// Render a fullscreen textured quad
static void gl_draw_texture_fullscreen(unsigned int texId) {
    if (texId == 0) return;
    glEnable(GL_TEXTURE_2D);
    gl_bind_texture(texId);
    glColor4ub(255, 255, 255, 255);
    glBegin(GL_QUADS);
        glTexCoord2f(0, 0); glVertex2f(0, 0);
        glTexCoord2f(1, 0); glVertex2f(640, 0);
        glTexCoord2f(1, 1); glVertex2f(640, 480);
        glTexCoord2f(0, 1); glVertex2f(0, 480);
    glEnd();
    glDisable(GL_TEXTURE_2D);
}

// ============================================================================
// PC Game State Machine
// ============================================================================

enum PCGameState {
    PC_STATE_BOOT,        // Show boot info, load archives
    PC_STATE_LOGO,        // Maxis/EA logo
    PC_STATE_MAIN_MENU,   // Interactive main menu
    PC_STATE_LOADING,     // Loading a level
    PC_STATE_GAMEPLAY,    // In-game
};

static PCGameState g_pcState = PC_STATE_BOOT;
static float g_stateTimer = 0.0f;
static int g_frameCount = 0;
static int g_menuSelection = 0;
static int g_menuItemCount = 4;
static int g_prevButtons = 0;  // for edge detection

// Input helper: read PAD buttons this frame
extern int input_get_pad_status(void* status);

struct PADStatusLocal {
    unsigned short button;
    signed char stickX, stickY;
    signed char substickX, substickY;
    unsigned char triggerL, triggerR;
    unsigned char analogA, analogB;
    signed char err;
    char pad[3];
};

static unsigned short get_buttons(void) {
    PADStatusLocal pads[4];
    memset(pads, 0, sizeof(pads));
    input_get_pad_status(pads);
    return pads[0].button;
}

static int button_pressed(unsigned short buttons, unsigned short mask) {
    return (buttons & mask) && !(g_prevButtons & mask);
}

// ============================================================================
// OpenGL rendering helpers
// ============================================================================

static void gl_draw_rect(float x, float y, float w, float h,
                          u8 r, u8 g, u8 b, u8 a) {
    glColor4ub(r, g, b, a);
    glBegin(GL_QUADS);
        glVertex2f(x, y);
        glVertex2f(x + w, y);
        glVertex2f(x + w, y + h);
        glVertex2f(x, y + h);
    glEnd();
}

static void gl_draw_diamond(float cx, float cy, float rx, float ry,
                              u8 r, u8 g, u8 b, u8 a) {
    glColor4ub(r, g, b, a);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(cx, cy - ry);  // top
        glVertex2f(cx + rx, cy);  // right
        glVertex2f(cx, cy + ry);  // bottom
        glVertex2f(cx - rx, cy);  // left
    glEnd();
}

// Simple letter rendering using line segments (for boot screen text)
// Each letter is drawn as a set of GL_LINES in a 5x7 grid
static void gl_draw_char(float x, float y, float scale, char c,
                           u8 r, u8 g, u8 b) {
    glColor3ub(r, g, b);
    glLineWidth(2.0f);

    // Simplified block letters — just uppercase + digits
    float s = scale;
    #define L(x1,y1,x2,y2) glVertex2f(x+(x1)*s, y+(y1)*s); glVertex2f(x+(x2)*s, y+(y2)*s)

    glBegin(GL_LINES);
    switch (c) {
    case 'T': L(0,0,5,0); L(2.5f,0,2.5f,7); break;
    case 'H': L(0,0,0,7); L(5,0,5,7); L(0,3.5f,5,3.5f); break;
    case 'E': L(0,0,5,0); L(0,0,0,7); L(0,3.5f,4,3.5f); L(0,7,5,7); break;
    case 'S': L(5,0,0,0); L(0,0,0,3.5f); L(0,3.5f,5,3.5f); L(5,3.5f,5,7); L(5,7,0,7); break;
    case 'I': L(0,0,5,0); L(2.5f,0,2.5f,7); L(0,7,5,7); break;
    case 'M': L(0,7,0,0); L(0,0,2.5f,3.5f); L(2.5f,3.5f,5,0); L(5,0,5,7); break;
    case 'A': L(0,7,2.5f,0); L(2.5f,0,5,7); L(1,4.5f,4,4.5f); break;
    case 'X': L(0,0,5,7); L(5,0,0,7); break;
    case '2': L(0,0,5,0); L(5,0,5,3.5f); L(5,3.5f,0,3.5f); L(0,3.5f,0,7); L(0,7,5,7); break;
    case 'P': L(0,7,0,0); L(0,0,5,0); L(5,0,5,3.5f); L(5,3.5f,0,3.5f); break;
    case 'C': L(5,0,0,0); L(0,0,0,7); L(0,7,5,7); break;
    case 'O': L(0,0,5,0); L(5,0,5,7); L(5,7,0,7); L(0,7,0,0); break;
    case 'R': L(0,7,0,0); L(0,0,5,0); L(5,0,5,3.5f); L(5,3.5f,0,3.5f); L(2.5f,3.5f,5,7); break;
    case 'N': L(0,7,0,0); L(0,0,5,7); L(5,7,5,0); break;
    case 'G': L(5,0,0,0); L(0,0,0,7); L(0,7,5,7); L(5,7,5,3.5f); L(5,3.5f,3,3.5f); break;
    case 'D': L(0,0,4,0); L(4,0,5,1); L(5,1,5,6); L(5,6,4,7); L(4,7,0,7); L(0,7,0,0); break;
    case 'L': L(0,0,0,7); L(0,7,5,7); break;
    case 'W': L(0,0,1,7); L(1,7,2.5f,4); L(2.5f,4,4,7); L(4,7,5,0); break;
    case 'F': L(0,0,5,0); L(0,0,0,7); L(0,3.5f,4,3.5f); break;
    case 'B': L(0,0,0,7); L(0,0,4,0); L(4,0,5,1); L(5,1,4,3.5f); L(4,3.5f,0,3.5f); L(0,3.5f,4,3.5f); L(4,3.5f,5,5); L(5,5,4,7); L(4,7,0,7); break;
    case 'U': L(0,0,0,7); L(0,7,5,7); L(5,7,5,0); break;
    case 'Y': L(0,0,2.5f,3.5f); L(5,0,2.5f,3.5f); L(2.5f,3.5f,2.5f,7); break;
    case 'K': L(0,0,0,7); L(5,0,0,3.5f); L(0,3.5f,5,7); break;
    case 'V': L(0,0,2.5f,7); L(2.5f,7,5,0); break;
    case '0': L(0,0,5,0); L(5,0,5,7); L(5,7,0,7); L(0,7,0,0); L(0,0,5,7); break;
    case '1': L(2.5f,0,2.5f,7); L(0,7,5,7); break;
    case '3': L(0,0,5,0); L(5,0,5,7); L(5,7,0,7); L(1,3.5f,5,3.5f); break;
    case '4': L(0,0,0,3.5f); L(0,3.5f,5,3.5f); L(5,0,5,7); break;
    case '5': L(5,0,0,0); L(0,0,0,3.5f); L(0,3.5f,5,3.5f); L(5,3.5f,5,7); L(5,7,0,7); break;
    case '6': L(5,0,0,0); L(0,0,0,7); L(0,7,5,7); L(5,7,5,3.5f); L(5,3.5f,0,3.5f); break;
    case '7': L(0,0,5,0); L(5,0,5,7); break;
    case '8': L(0,0,5,0); L(5,0,5,7); L(5,7,0,7); L(0,7,0,0); L(0,3.5f,5,3.5f); break;
    case '9': L(5,7,5,0); L(5,0,0,0); L(0,0,0,3.5f); L(0,3.5f,5,3.5f); break;
    case '.': L(2,6,3,6); L(3,6,3,7); L(3,7,2,7); L(2,7,2,6); break;
    case ':': L(2,2,3,2); L(2,5,3,5); break;
    case '-': L(1,3.5f,4,3.5f); break;
    case '/': L(0,7,5,0); break;
    case ' ': break;
    default: L(0,0,5,0); L(5,0,5,7); L(5,7,0,7); L(0,7,0,0); break; // box for unknown
    }
    glEnd();
    #undef L
}

static void gl_draw_string(float x, float y, float scale, const char* str,
                             u8 r, u8 g, u8 b) {
    float cx = x;
    while (*str) {
        char c = *str;
        if (c >= 'a' && c <= 'z') c -= 32; // uppercase
        gl_draw_char(cx, y, scale, c, r, g, b);
        cx += 6.0f * scale;
        str++;
    }
}

// ============================================================================
// Boot Screen (STATE_BOOT)
// ============================================================================

static void render_boot_screen(void) {
    // Dark background
    gl_draw_rect(0, 0, 640, 480, 5, 10, 20, 255);

    // Title
    gl_draw_string(120, 30, 4.0f, "THE SIMS 2", 0, 220, 100);
    gl_draw_string(120, 70, 2.0f, "PC PORT", 0, 160, 80);

    // Build info
    gl_draw_string(20, 120, 1.5f, "BUILD F.09.12.0", 80, 120, 80);
    gl_draw_string(20, 140, 1.5f, "GAMECUBE DECOMPILATION", 80, 120, 80);

    // Archive loading bars
    gl_draw_string(20, 180, 1.5f, "ARCHIVES LOADED:", 120, 160, 120);
    int total = arc_count();
    for (int i = 0; i < total && i < 22; i++) {
        float bx = 20.0f + (i % 11) * 56.0f;
        float by = 200.0f + (i / 11) * 24.0f;
        float progress = (g_stateTimer > 0.1f * i) ? 1.0f : g_stateTimer / (0.1f * (i + 1));
        if (progress > 1.0f) progress = 1.0f;
        // Background
        gl_draw_rect(bx, by, 50, 16, 20, 40, 20, 255);
        // Fill
        gl_draw_rect(bx, by, 50.0f * progress, 16, 0, (u8)(160 + i * 4), 60, 255);
    }

    // Memory status
    gl_draw_string(20, 260, 1.5f, "MEMORY: SYSTEM MALLOC", 100, 140, 100);
    gl_draw_string(20, 280, 1.5f, "RENDERER: OPENGL", 100, 140, 100);

    // Progress bar
    float progress = g_stateTimer / 2.0f;
    if (progress > 1.0f) progress = 1.0f;
    gl_draw_rect(20, 440, 600, 20, 20, 40, 20, 255);
    gl_draw_rect(20, 440, 600.0f * progress, 20, 0, 200, 80, 255);
    gl_draw_string(250, 443, 1.5f, "BOOTING", 255, 255, 255);
}

// ============================================================================
// Logo Screen (STATE_LOGO)
// ============================================================================

static void render_logo_screen(void) {
    // Fade in/out
    float alpha = 1.0f;
    if (g_stateTimer < 0.5f) alpha = g_stateTimer / 0.5f;
    else if (g_stateTimer > 2.5f) alpha = (3.0f - g_stateTimer) / 0.5f;
    if (alpha < 0.0f) alpha = 0.0f;
    if (alpha > 1.0f) alpha = 1.0f;
    u8 a = (u8)(alpha * 255);

    // Black background
    gl_draw_rect(0, 0, 640, 480, 0, 0, 0, 255);

    // Render Maxis logo texture if available
    if (g_maxisLogoTex) {
        glEnable(GL_TEXTURE_2D);
        gl_bind_texture(g_maxisLogoTex);
        glColor4ub(255, 255, 255, a);
        float lw = 256, lh = 256;
        float lx = (640 - lw) / 2, ly = (480 - lh) / 2 - 30;
        glBegin(GL_QUADS);
            glTexCoord2f(0, 0); glVertex2f(lx, ly);
            glTexCoord2f(1, 0); glVertex2f(lx + lw, ly);
            glTexCoord2f(1, 1); glVertex2f(lx + lw, ly + lh);
            glTexCoord2f(0, 1); glVertex2f(lx, ly + lh);
        glEnd();
        glDisable(GL_TEXTURE_2D);
    } else {
        // Fallback: text-drawn MAXIS
        u8 lr = (u8)(200.0f * alpha);
        u8 lg = (u8)(220.0f * alpha);
        u8 lb = (u8)(255.0f * alpha);
        gl_draw_string(120, 160, 8.0f, "MAXIS", lr, lg, lb);
    }

    // Subtitle
    gl_draw_string(200, 340, 2.0f, "A DIVISION OF ELECTRONIC ARTS",
                   (u8)(100*alpha), (u8)(120*alpha), (u8)(160*alpha));

    // Small plumbob
    gl_draw_diamond(320, 400, 15 * alpha, 20 * alpha,
                    0, (u8)(200*alpha), (u8)(60*alpha), a);
}

// ============================================================================
// Main Menu (STATE_MAIN_MENU)
// ============================================================================

static const char* g_menuItems[] = {
    "NEW GAME",
    "LOAD GAME",
    "OPTIONS",
    "QUIT"
};

static void update_main_menu(float dt) {
    unsigned short buttons = get_buttons();

    // D-pad navigation
    if (button_pressed(buttons, 0x0008)) { // PAD_BUTTON_UP
        g_menuSelection--;
        if (g_menuSelection < 0) g_menuSelection = g_menuItemCount - 1;
    }
    if (button_pressed(buttons, 0x0004)) { // PAD_BUTTON_DOWN
        g_menuSelection++;
        if (g_menuSelection >= g_menuItemCount) g_menuSelection = 0;
    }

    // A button / Enter = select
    if (button_pressed(buttons, 0x0100)) { // PAD_BUTTON_A
        log_boot("[MENU] Selected: %s\n", g_menuItems[g_menuSelection]);
        if (g_menuSelection == 3) {
            // Quit
            log_boot("[MENU] Quit requested\n");
            // Signal exit (will be handled by checking a flag)
        }
    }

    g_prevButtons = buttons;
}

static void render_main_menu(void) {
    // Background: try team picture, then title tex, else solid
    unsigned int bgTex = g_teamPicTex ? g_teamPicTex : g_titleTexture;
    if (bgTex) {
        gl_draw_texture_fullscreen(bgTex);
        // Dark overlay for readability
        gl_draw_rect(0, 0, 640, 480, 0, 0, 0, 160);
    } else {
        gl_draw_rect(0, 0, 640, 480, 5, 8, 25, 255);
    }

    // Sims 2 logo texture in top-right if available
    if (g_titleTexture && g_titleTexture != bgTex) {
        glEnable(GL_TEXTURE_2D);
        gl_bind_texture(g_titleTexture);
        glColor4ub(255, 255, 255, 200);
        glBegin(GL_QUADS);
            glTexCoord2f(0, 0); glVertex2f(440, 10);
            glTexCoord2f(1, 0); glVertex2f(630, 10);
            glTexCoord2f(1, 1); glVertex2f(630, 130);
            glTexCoord2f(0, 1); glVertex2f(440, 130);
        glEnd();
        glDisable(GL_TEXTURE_2D);
    }

    // Animated plumbob
    float bobY = 80 + sinf(g_stateTimer * 2.0f) * 10.0f;
    gl_draw_diamond(320, bobY, 25, 35, 0, 220, 80, 255);
    gl_draw_diamond(320, bobY, 18, 28, 30, 255, 100, 200);

    // Title
    gl_draw_string(130, 140, 4.0f, "THE SIMS 2", 0, 220, 100);
    gl_draw_string(220, 180, 2.0f, "PC PORT", 80, 180, 80);

    // Menu items
    float menuY = 240;
    float menuSpacing = 45;
    for (int i = 0; i < g_menuItemCount; i++) {
        float itemY = menuY + i * menuSpacing;
        bool selected = (i == g_menuSelection);

        if (selected) {
            // Selection highlight
            gl_draw_rect(150, itemY - 4, 340, 32, 0, 80, 30, 200);
            // Selection indicator (small diamond)
            gl_draw_diamond(165, itemY + 8, 8, 10, 0, 255, 100, 255);
            // Text (bright)
            gl_draw_string(185, itemY, 2.5f, g_menuItems[i], 0, 255, 120);
        } else {
            // Text (dim)
            gl_draw_string(185, itemY, 2.5f, g_menuItems[i], 60, 120, 60);
        }
    }

    // Controls hint
    gl_draw_string(20, 450, 1.2f, "ARROWS:MOVE  Z:SELECT  ESC:QUIT",
                   60, 80, 60);

    // Archive count
    char buf[64];
    snprintf(buf, sizeof(buf), "%d ARCHIVES  FRAME %d",
             arc_count(), g_frameCount);
    gl_draw_string(400, 450, 1.2f, buf, 40, 60, 40);
}

// ============================================================================
// Bootstrap + Update + Shutdown
// ============================================================================

int game_bootstrap(const char* data_path) {
    log_boot("[BOOT] Starting game bootstrap...\n");
    log_boot("[BOOT] Memory: system malloc\n");

    // Initialize global state buffers
    memset(g_eGlobal, 0, sizeof(g_eGlobal));
    memset(g_eSimsApp, 0, sizeof(g_eSimsApp));
    memset(g_eNgcEngine, 0, sizeof(g_eNgcEngine));
    memset(g_eControllerManager, 0, sizeof(g_eControllerManager));
    memset(g_stateMachineManager, 0, sizeof(g_stateMachineManager));
    log_boot("[BOOT] Global singletons initialized\n");

    // Load game archives
    int arc_loaded = arc_open_all(data_path);
    log_boot("[BOOT] Archives loaded: %d\n", arc_loaded);

    if (arc_loaded == 0) {
        log_boot("[BOOT] ERROR: No archives found at %s\n", data_path);
        return 0;
    }

    // Verify key resources
    int has_textures = 0, has_models = 0, has_fonts = 0;
    for (int i = 0; i < arc_count(); i++) {
        ArcArchive* arc = arc_get(i);
        if (!arc) continue;
        if (arc_find(arc, "systemfont")) has_fonts = 1;
        if (arc_find(arc, "map")) has_models = 1;
        if (arc_find(arc, "title bg c")) has_textures = 1;
    }
    log_boot("[BOOT] Resources: fonts=%d models=%d textures=%d\n",
             has_fonts, has_models, has_textures);

    // Load game textures
    g_maxisLogoTex = load_arc_texture("maxis_logo_black_clean");
    g_teamPicTex = load_arc_texture("team_picture");
    g_titleTexture = load_arc_texture("ui_logo256_spa_light");  // Sims 2 logo
    if (!g_titleTexture) g_titleTexture = load_arc_texture("title bg c");
    log_boot("[BOOT] Textures: maxis=%u team=%u title=%u\n",
             g_maxisLogoTex, g_teamPicTex, g_titleTexture);

    // Set initial state
    g_pcState = PC_STATE_BOOT;
    g_stateTimer = 0.0f;
    g_frameCount = 0;
    g_menuSelection = 0;
    g_prevButtons = 0;

    log_boot("[BOOT] Game bootstrap complete — entering state machine\n");
    return 1;
}

void game_update(float dt) {
    g_frameCount++;
    g_stateTimer += dt;

    // Set up 2D orthographic projection (640x480 virtual resolution)
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, 640, 480, 0, -1, 1);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glDisable(GL_DEPTH_TEST);
    glDisable(GL_TEXTURE_2D);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    switch (g_pcState) {
    case PC_STATE_BOOT:
        render_boot_screen();
        if (g_stateTimer > 2.0f) {
            log_boot("[STATE] BOOT → LOGO\n");
            g_pcState = PC_STATE_LOGO;
            g_stateTimer = 0.0f;
        }
        break;

    case PC_STATE_LOGO:
        render_logo_screen();
        // Skip on button press, or auto-advance after 3s
        {
            unsigned short btns = get_buttons();
            if (g_stateTimer > 3.0f || button_pressed(btns, 0x0100)) {
                log_boot("[STATE] LOGO → MAIN_MENU\n");
                g_pcState = PC_STATE_MAIN_MENU;
                g_stateTimer = 0.0f;
                g_prevButtons = btns;
            }
        }
        break;

    case PC_STATE_MAIN_MENU:
        update_main_menu(dt);
        render_main_menu();
        break;

    default:
        break;
    }
}

int game_get_frame_count(void) { return g_frameCount; }
int game_get_archive_count(void) { return arc_count(); }

void game_shutdown(void) {
    log_boot("[BOOT] Game shutdown (frame %d)\n", g_frameCount);
    if (g_logFile) fclose(g_logFile);
    g_logFile = nullptr;
}
