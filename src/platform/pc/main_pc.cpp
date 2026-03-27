// main_pc.cpp — PC port entry point for The Sims 2
// Uses Win32 API directly for the window (no SDL2 dependency needed).

#include "types.h"
#include "gl_renderer.h"
#include "input_bridge.h"
#include <stdio.h>
#include <stdlib.h>

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

        // Render frame
        gl_begin_frame();
        // TODO: call game update/render here once game loop is wired
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
