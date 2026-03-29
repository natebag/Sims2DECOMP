/* Timer_SetFrameDelta(float) at 0x80076EF8 (68B) */

extern float g_frameDelta;
extern float g_time;
extern float g_prevTime;
extern int g_ticks;
extern int g_prevTicks;
extern void Timer_StartFrame();

static const float kFixedDelta = 0.033333335f;

void Timer_SetFrameDelta(float delta) {
    g_frameDelta = delta;
    if (delta == kFixedDelta) {
        g_prevTime = g_time;
        g_prevTicks = g_ticks;
    }
    Timer_StartFrame();
}
