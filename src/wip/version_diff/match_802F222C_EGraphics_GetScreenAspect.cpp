/* EGraphics::GetScreenAspect(void) - 0x802F222C (12 bytes) */
// TU: e_graphics

extern float EGraphics_s_screenAspect;

struct EGraphics {
    static float GetScreenAspect();
};

float EGraphics::GetScreenAspect() {
    return EGraphics_s_screenAspect;
}
