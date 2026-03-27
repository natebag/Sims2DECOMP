// main_pc.cpp — PC port entry point for The Sims 2
// Uses Win32 API directly for the window (no SDL2 dependency needed).

#include "types.h"
#include "gl_renderer.h"
#include "input_bridge.h"
#include "platform/arc_reader.h"
#include <stdio.h>
#include <stdlib.h>

#ifdef _WIN32
#include <GL/gl.h>
#endif

#if defined(_WIN32) || defined(__CYGWIN__)
#define WIN32_LEAN_AND_MEAN
#include <windows.h>

static bool g_running = true;

LRESULT CALLBACK Sims2WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    switch (msg) {
        case WM_CLOSE:
        case WM_DESTROY:
            g_running = false;
            PostQuitMessage(0);
            return 0;
        case WM_KEYDOWN:
            if (wParam == VK_ESCAPE) {
                g_running = false;
                PostQuitMessage(0);
            }
            input_handle_key((unsigned int)wParam, 1);
            return 0;
        case WM_KEYUP:
            input_handle_key((unsigned int)wParam, 0);
            return 0;
        case WM_PAINT: {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hwnd, &ps);
            // Black background
            HBRUSH black = (HBRUSH)GetStockObject(BLACK_BRUSH);
            FillRect(hdc, &ps.rcPaint, black);
            // Draw title text
            SetBkMode(hdc, TRANSPARENT);
            SetTextColor(hdc, RGB(0, 255, 100));
            RECT rc;
            GetClientRect(hwnd, &rc);
            const char* title = "The Sims 2 - PC Port";
            const char* sub1 = "GameCube Decompilation (G4ZE69)";
            const char* sub2 = "Build F.09.12.0 - Gold Master";
            const char* sub3 = "Press ESC to exit";
            rc.top = rc.bottom / 2 - 60;
            DrawTextA(hdc, title, -1, &rc, DT_CENTER | DT_SINGLELINE);
            SetTextColor(hdc, RGB(0, 180, 80));
            rc.top += 30;
            DrawTextA(hdc, sub1, -1, &rc, DT_CENTER | DT_SINGLELINE);
            rc.top += 22;
            DrawTextA(hdc, sub2, -1, &rc, DT_CENTER | DT_SINGLELINE);
            SetTextColor(hdc, RGB(100, 100, 100));
            rc.top += 40;
            DrawTextA(hdc, sub3, -1, &rc, DT_CENTER | DT_SINGLELINE);
            EndPaint(hwnd, &ps);
            return 0;
        }
    }
    return DefWindowProcA(hwnd, msg, wParam, lParam);
}

int main(int argc, char* argv[]) {
    // Register window class
    WNDCLASSEXA wc = {};
    wc.cbSize = sizeof(wc);
    wc.style = CS_HREDRAW | CS_VREDRAW;
    wc.lpfnWndProc = Sims2WndProc;
    wc.hInstance = GetModuleHandle(NULL);
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
    wc.lpszClassName = "Sims2PCPort";
    RegisterClassExA(&wc);

    // Create window
    RECT wr = {0, 0, 1280, 720};
    AdjustWindowRect(&wr, WS_OVERLAPPEDWINDOW, FALSE);
    HWND hwnd = CreateWindowExA(
        0, "Sims2PCPort", "The Sims 2 (PC Port)",
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT,
        wr.right - wr.left, wr.bottom - wr.top,
        NULL, NULL, GetModuleHandle(NULL), NULL
    );

    if (!hwnd) {
        MessageBoxA(NULL, "Failed to create window!", "Sims 2 PC Port", MB_OK | MB_ICONERROR);
        return 1;
    }

    ShowWindow(hwnd, SW_SHOW);
    UpdateWindow(hwnd);

    // Initialize input
    input_init();

    // Initialize OpenGL
    if (!gl_init(hwnd)) {
        printf("[MAIN] OpenGL init failed — falling back to GDI\n");
    } else {
        printf("[MAIN] OpenGL rendering active\n");
    }

    // Load game archives — try multiple paths
    printf("[MAIN] Loading game archives...\n");
    const char* data_paths[] = {
        "extracted/files/DATA",
        "../extracted/files/DATA",
        "../../extracted/files/DATA",
        "../../../extracted/files/DATA",
        "/f/coding/Decompiles/Sims 2/extracted/files/DATA",
        "F:\\coding\\Decompiles\\Sims 2\\extracted\\files\\DATA",
        NULL
    };
    int arc_loaded = 0;
    for (int i = 0; data_paths[i] && arc_loaded == 0; i++) {
        arc_loaded = arc_open_all(data_paths[i]);
    }
    printf("[MAIN] Loaded %d archives\n", arc_loaded);

    // Generate a Sims 2 themed test texture (checkerboard with game colors)
    unsigned int test_texture_id = 0;
    {
        int w = 128, h = 128;
        u8* rgba = (u8*)malloc(w * h * 4);
        for (int y = 0; y < h; y++) {
            for (int x = 0; x < w; x++) {
                int idx = (y * w + x) * 4;
                bool check = ((x / 16) + (y / 16)) % 2 == 0;
                if (check) {
                    rgba[idx+0] = 0; rgba[idx+1] = 180; rgba[idx+2] = 80; rgba[idx+3] = 255; // Sims green
                } else {
                    rgba[idx+0] = 0; rgba[idx+1] = 40; rgba[idx+2] = 20; rgba[idx+3] = 255; // dark green
                }
            }
        }
        test_texture_id = gl_create_texture(rgba, w, h);
        free(rgba);
    }

    // Log asset stats
    {
        FILE* lf = fopen("sims2pc.log", "a");
        if (lf) {
            int total_entries = 0;
            for (int i = 0; i < arc_count(); i++) {
                ArcArchive* a = arc_get(i);
                if (a) {
                    // Count entries via arc_find hack — we know the entry count from the log
                    total_entries++; // Just count archives for now
                }
            }
            fprintf(lf, "[MAIN] %d archives loaded, GL texture created\n", arc_count());
            fclose(lf);
        }
    }

    // Message loop with OpenGL rendering
    MSG msg;
    while (g_running) {
        while (PeekMessageA(&msg, NULL, 0, 0, PM_REMOVE)) {
            if (msg.message == WM_QUIT) {
                g_running = false;
                break;
            }
            TranslateMessage(&msg);
            DispatchMessageA(&msg);
        }

        // Poll input
        input_poll_controllers();

        // Render frame
        gl_begin_frame();

        // TODO: When game init is working, replace this test scene with:
        // ESimsApp::Update() which calls UpdateDraw() etc.

        // Test scene: render a textured quad to prove the pipeline works
        // This will be replaced with the real game loop (Session C)
        {
            // Set up 2D orthographic projection (640x480 like GC framebuffer)
            glMatrixMode(GL_PROJECTION);
            glLoadIdentity();
            glOrtho(0, 640, 480, 0, -1, 1);
            glMatrixMode(GL_MODELVIEW);
            glLoadIdentity();

            // Draw "Sims 2 PC Port" text overlay with GL
            glDisable(GL_TEXTURE_2D);
            glDisable(GL_DEPTH_TEST);

            // Green diamond in the center (proof that vertex pipeline works)
            glColor4ub(0, 255, 100, 255);
            glBegin(GL_TRIANGLE_FAN);
                glVertex2f(320, 180);  // top
                glVertex2f(380, 240);  // right
                glVertex2f(320, 300);  // bottom
                glVertex2f(260, 240);  // left
            glEnd();

            // Plumbob shape (smaller green diamond above)
            glColor4ub(0, 200, 60, 200);
            glBegin(GL_TRIANGLE_FAN);
                glVertex2f(320, 150);
                glVertex2f(335, 170);
                glVertex2f(320, 190);
                glVertex2f(305, 170);
            glEnd();

            // White text area background
            glColor4ub(0, 0, 0, 180);
            glBegin(GL_QUADS);
                glVertex2f(140, 320);
                glVertex2f(500, 320);
                glVertex2f(500, 420);
                glVertex2f(140, 420);
            glEnd();

            // Render loaded game texture (raw data visualization)
            if (test_texture_id > 0) {
                glEnable(GL_TEXTURE_2D);
                gl_bind_texture(test_texture_id);
                glColor4ub(255, 255, 255, 255);
                float qx = 420, qy = 50;
                float qw = 200, qh = 200;
                glBegin(GL_QUADS);
                    glTexCoord2f(0, 0); glVertex2f(qx, qy);
                    glTexCoord2f(1, 0); glVertex2f(qx+qw, qy);
                    glTexCoord2f(1, 1); glVertex2f(qx+qw, qy+qh);
                    glTexCoord2f(0, 1); glVertex2f(qx, qy+qh);
                glEnd();
                glDisable(GL_TEXTURE_2D);
            }
        }

        gl_end_frame();

        Sleep(16); // ~60fps
    }

    gl_shutdown();
    DestroyWindow(hwnd);
    return 0;
}

#else
// Non-Windows fallback
int main(int argc, char* argv[]) {
    printf("=== The Sims 2 — PC Port ===\n");
    printf("Build: F.09.12.0 (Gold Master)\n");
    printf("Window requires Windows. This build confirmed x86 compilation.\n");
    return 0;
}
#endif
