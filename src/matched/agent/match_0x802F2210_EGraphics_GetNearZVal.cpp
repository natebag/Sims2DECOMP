// 0x802F2210 EGraphics::GetNearZVal (12b)

struct EGraphicsGlobals {
    float farZ;
    float nearZ;
    float aspect;
};
extern EGraphicsGlobals g_graphicsGlobals;

class EGraphics {
public:
    float GetNearZVal(void);
};

float EGraphics::GetNearZVal(void) {
    return g_graphicsGlobals.nearZ;
}
