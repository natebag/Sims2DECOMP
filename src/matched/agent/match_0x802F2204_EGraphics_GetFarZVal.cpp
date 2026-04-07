// 0x802F2204 EGraphics::GetFarZVal (12b)

struct EGraphicsGlobals {
    float farZ;
    float nearZ;
    float aspect;
};
extern EGraphicsGlobals g_graphicsGlobals;

class EGraphics {
public:
    float GetFarZVal(void);
};

float EGraphics::GetFarZVal(void) {
    return g_graphicsGlobals.farZ;
}
