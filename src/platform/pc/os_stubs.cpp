// os_stubs.cpp — Stub implementations of DolphinSDK OS functions for PC
// Maps GameCube OS calls to standard C/C++ equivalents.

#include "platform/platform.h"

#ifdef SIMS2_PLATFORM_PC

#include <cstdio>
#include <cstdarg>
#include <cstring>
#include <cstdlib>
#include <chrono>
#include <thread>
#include <mutex>

extern "C" {

// ============================================================================
// Timing
// ============================================================================

static auto program_start = std::chrono::high_resolution_clock::now();

unsigned long long OSGetTime(void) {
    auto now = std::chrono::high_resolution_clock::now();
    auto us = std::chrono::duration_cast<std::chrono::microseconds>(now - program_start).count();
    // GC timebase is ~40.5 MHz, but for PC we just return microseconds
    return (unsigned long long)us;
}

unsigned int OSGetTick(void) {
    return (unsigned int)(OSGetTime() & 0xFFFFFFFF);
}

// ============================================================================
// Reporting
// ============================================================================

void OSReport(const char* fmt, ...) {
    va_list args;
    va_start(args, fmt);
    vprintf(fmt, args);
    va_end(args);
}

void OSPanic(const char* file, int line, const char* fmt, ...) {
    fprintf(stderr, "PANIC at %s:%d: ", file, line);
    va_list args;
    va_start(args, fmt);
    vfprintf(stderr, fmt, args);
    va_end(args);
    fprintf(stderr, "\n");
    abort();
}

// ============================================================================
// Threading (simple stubs — will be replaced with real threading)
// ============================================================================

int OSCreateThread(OSThread* thread, void* (*func)(void*), void* param,
                   void* stack, unsigned int stackSize, int priority, int detached) {
    // TODO: implement with std::thread
    return 1;
}

void OSResumeThread(OSThread* thread) { }
void OSSuspendThread(OSThread* thread) { }
int OSIsThreadTerminated(OSThread* thread) { return 0; }

static std::mutex global_mutex;

void OSInitMutex(OSMutex* mutex) { }
void OSLockMutex(OSMutex* mutex) { global_mutex.lock(); }
void OSUnlockMutex(OSMutex* mutex) { global_mutex.unlock(); }

void OSInitCond(OSCond* cond) { }
void OSWaitCond(OSCond* cond, OSMutex* mutex) { }
void OSSignalCond(OSCond* cond) { }

// ============================================================================
// Memory (pass-through to standard allocator)
// ============================================================================

void* OSAllocFromHeap(int heap, unsigned int size) {
    return malloc(size);
}

void OSFreeToHeap(int heap, void* ptr) {
    free(ptr);
}

// ============================================================================
// Interrupts (no-ops on PC)
// ============================================================================

int OSDisableInterrupts(void) { return 0; }
void OSRestoreInterrupts(int level) { (void)level; }

// ============================================================================
// DVD file I/O (maps GameCube disc paths to PC filesystem)
// ============================================================================

// Base path for extracted disc files (set at startup)
static char g_disc_base_path[512] = "extracted/files";

void DVD_SetBasePath(const char* path) {
    strncpy(g_disc_base_path, path, sizeof(g_disc_base_path) - 1);
    printf("[DVD] Base path set to: %s\n", g_disc_base_path);
}

static FILE* dvd_try_open(const char* fileName) {
    char full_path[1024];

    // Try exact path first
    FILE* f = fopen(fileName, "rb");
    if (f) return f;

    // Try under disc base path
    snprintf(full_path, sizeof(full_path), "%s/%s", g_disc_base_path, fileName);
    f = fopen(full_path, "rb");
    if (f) return f;

    // Try with DATA/ prefix
    snprintf(full_path, sizeof(full_path), "%s/DATA/%s", g_disc_base_path, fileName);
    f = fopen(full_path, "rb");
    if (f) return f;

    // Try just the filename (strip any path)
    const char* base = strrchr(fileName, '/');
    if (!base) base = strrchr(fileName, '\\');
    if (base) {
        base++;
        snprintf(full_path, sizeof(full_path), "%s/DATA/%s", g_disc_base_path, base);
        f = fopen(full_path, "rb");
        if (f) return f;
    }

    return nullptr;
}

int DVDOpen(const char* fileName, DVDFileInfo* fileInfo) {
    FILE* f = dvd_try_open(fileName);
    if (!f) {
        fprintf(stderr, "[DVD] Failed to open: %s\n", fileName);
        return 0;
    }
    fileInfo->internal = f;
    return 1;
}

void DVDClose(DVDFileInfo* fileInfo) {
    if (fileInfo->internal) {
        fclose((FILE*)fileInfo->internal);
        fileInfo->internal = NULL;
    }
}

int DVDReadPrio(DVDFileInfo* fileInfo, void* addr, int length, int offset, int prio) {
    (void)prio;
    FILE* f = (FILE*)fileInfo->internal;
    if (!f) return -1;
    fseek(f, offset, SEEK_SET);
    return (int)fread(addr, 1, length, f);
}

int DVDGetLength(DVDFileInfo* fileInfo) {
    FILE* f = (FILE*)fileInfo->internal;
    if (!f) return 0;
    long pos = ftell(f);
    fseek(f, 0, SEEK_END);
    long len = ftell(f);
    fseek(f, pos, SEEK_SET);
    return (int)len;
}

// ============================================================================
// CARD (maps to save files on PC)
// ============================================================================

int CARDInit(void) { return 0; }
int CARDOpen(int chan, const char* fileName, void* fileInfo) { return -1; } // TODO
int CARDClose(void* fileInfo) { return 0; }
int CARDRead(void* fileInfo, void* addr, int length, int offset) { return -1; }
int CARDWrite(void* fileInfo, const void* addr, int length, int offset) { return -1; }

// ============================================================================
// PAD (maps to SDL2 gamepad on PC)
// ============================================================================

int PADInit(void) { return 1; }

// Forward declare input bridge function (defined in input_bridge.cpp)
extern int input_get_pad_status(void* status);

int PADRead(PADStatus* status) {
    return input_get_pad_status(status);
}

void PADReset(unsigned int mask) { (void)mask; }
void PADSetAnalogMode(int mode) { (void)mode; }

// ============================================================================
// Audio
// ============================================================================

// Forward declare audio bridge (defined in audio_bridge.cpp)
extern int audio_init(void);
extern void audio_shutdown(void);

void AXInit(void) {
    audio_init();
}
void AXQuit(void) {
    audio_shutdown();
}
void AXSetMode(int mode) { (void)mode; }

} // extern "C"

#endif // SIMS2_PLATFORM_PC
