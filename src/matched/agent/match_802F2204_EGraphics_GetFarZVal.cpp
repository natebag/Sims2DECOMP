/* EGraphics::GetFarZVal(void) - 0x802F2204 (12 bytes) */
// TU: e_graphics

extern float EGraphics_s_farZ;

struct EGraphics {
    static float GetFarZVal();
};

float EGraphics::GetFarZVal() {
    return EGraphics_s_farZ;
}
