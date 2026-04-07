// 0x802F222C EGraphics::GetScreenAspect (12b)

struct EGraphicsGlobals {
    float farZ;
    float nearZ;
    float aspect;
};
extern EGraphicsGlobals g_graphicsGlobals;

class EGraphics {
public:
    float GetScreenAspect(void);
};

float EGraphics::GetScreenAspect(void) {
    return g_graphicsGlobals.aspect;
}
