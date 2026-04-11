/* EGraphics::GetNearZVal(void) - 0x802F2210 (12 bytes) */
// TU: e_graphics

extern float EGraphics_s_nearZ;

struct EGraphics {
    static float GetNearZVal();
};

float EGraphics::GetNearZVal() {
    return EGraphics_s_nearZ;
}
