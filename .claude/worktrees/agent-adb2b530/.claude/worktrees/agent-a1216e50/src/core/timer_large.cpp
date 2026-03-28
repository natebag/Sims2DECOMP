// timer_large.cpp - Timer large functions (257-512 bytes)
// Object file: timer.obj
// Functions: Timer_StartFrame

#include "core/timer.h"

// External functions
extern "C" {
    // Timer query function (OS-level, returns ticks as float)
    // Uses vtable dispatch on input manager at r13-26532
}

// SDA globals - all timer state is in the small data area
extern "C" {
    extern float s_deltaTime;         // r13 - 0x6150 -> stored at r13-0x7DC8
    extern float s_totalTime;         // r13 - 0x614C
    extern float s_lastFrameTime;     // r13 - 0x614C (0x9EB8)
    extern float s_prevFrameTime;     // r13 - 0x6148 (0x9EB4)
    extern int   s_deltaTicks;        // r13 - 0x6144 (0x9EBC)
    extern int   s_totalTicks;        // r13 - 0x6140 (0x9EC0)
    extern int   s_prevTotalTicks;    // r13 - 0x613C (0x9EC4)
    extern float s_accumTime;         // r13 - 0x7DC8 (accumulator for dt)
    extern void* g_pInputMgr;        // r13 - 0x67A4 (r13-26532)
}

// Float constants from rodata
extern "C" {
    extern const float kTimerInitSentinel;   // 0x803d5cf4 - sentinel value for first frame
    extern const float kTimerTickScale;      // 0x803d5cf8 - tick to seconds conversion
    extern const float kTimerMaxFrame;       // 0x803d5cfc - max frame time (e.g., 1/15)
    extern const float kTimerHalfScale;      // 0x803d5d00 - 0.5x scale for averaging
    extern const float kTimerDoubleConv;     // 0x803d5d08 - double precision conversion constant
}

// ============================================================================
// Timer_StartFrame(void)
// Address: 0x80076f3c
// Size: 392 bytes (0x188)
// NON_MATCHING - SDA addressing, float-to-int conversion tricks, first-frame detection
//
// Called at the start of each frame to update all timer globals.
// Handles first-frame initialization, computes delta time, total time,
// and tick counts. Uses PPC float-to-int conversion via fctiwz+stfd trick.
//
// Flow:
// 1. Check if this is the first frame (sentinel value check)
// 2. If first frame: query OS timer, initialize all state
// 3. If not first frame: query OS timer, compute delta
// 4. Clamp delta time to maximum frame time
// 5. If delta is too large or negative, re-query timer
// 6. Update accumulated time, delta ticks, total ticks
// ============================================================================
void Timer_StartFrame(void) {
    // Load accumulated delta from SDA
    float accum = s_accumTime;
    float sentinel = kTimerInitSentinel;

    if (accum == sentinel) {
        // FIRST FRAME - initialize everything

        // Query OS timer via virtual dispatch on input manager
        // Input manager at r13-26532, vtable offset 0x28/0x2c
        void* inputMgr = g_pInputMgr;
        int prevTicks = s_prevTotalTicks;
        void** vtbl = *(void***)inputMgr;
        typedef float (*QueryTimeFn)(void*, int);
        short adj = *(short*)((char*)vtbl + 0x28);
        QueryTimeFn fn = (QueryTimeFn)*((void**)((char*)vtbl + 0x2c));

        // Store previous values
        s_prevFrameTime = s_lastFrameTime;
        s_prevTotalTicks = s_totalTicks;

        float curTime = fn((char*)inputMgr + adj, prevTicks);

        // Scale to ticks
        float scaled = curTime * kTimerTickScale;
        s_lastFrameTime = curTime;

        // Compute delta
        float delta = curTime - s_prevFrameTime;
        s_accumTime = delta;

        // Convert scaled time to int (ticks)
        // PPC: fctiwz f12, f0; stfd f12, 8(r1); lwz r11, 12(r1)
        int newTicks = (int)scaled;
        int tickDelta = newTicks - s_prevTotalTicks;
        s_totalTicks = newTicks;
        s_deltaTicks = tickDelta;

        // Check if delta is too large or negative
        if (delta > kTimerMaxFrame || delta < sentinel) {
            // Re-query timer to get a stable reading
            float curTime2 = fn((char*)inputMgr + adj, prevTicks);
            float scaled2 = curTime2 * kTimerTickScale;

            // Handle overflow in float-to-int conversion
            // Uses the double-precision trick for large values
            int newTicks2;
            float checkVal = scaled2;
            if (checkVal >= kTimerDoubleConv) {
                // Large value: use double subtraction + xoris trick
                newTicks2 = (int)(checkVal - kTimerDoubleConv);
                newTicks2 ^= (int)0x80000000;
            } else {
                newTicks2 = (int)checkVal;
            }

            // Reset all deltas
            s_lastFrameTime = curTime2;
            s_prevFrameTime = curTime2;
            s_prevTotalTicks = newTicks2;
            delta = curTime2 - curTime2; // = 0
            s_accumTime = delta;
            s_deltaTicks = 0;
            s_totalTicks = newTicks2;
        }
    } else {
        // SUBSEQUENT FRAME - use accumulated delta

        float prevAccum = s_lastFrameTime;
        float halfScale = kTimerHalfScale; // 0x803d5d08

        // Average the accumulated time
        float avgTime = (prevAccum + accum) * halfScale;

        // Convert to ticks
        int prevTotalTicks = s_totalTicks;
        s_accumTime = accum;
        int newTicks = (int)avgTime;
        int tickDelta = newTicks - prevTotalTicks;
        s_prevTotalTicks = prevTotalTicks;
        s_lastFrameTime = avgTime;
        s_totalTicks = newTicks;
        s_deltaTicks = tickDelta;
    }
}
