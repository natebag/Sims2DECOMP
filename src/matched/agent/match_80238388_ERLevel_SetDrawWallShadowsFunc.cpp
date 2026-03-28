// 0x80238388 (12 bytes) - ERLevel::SetDrawWallShadowsFunc(funcptr)
// addis r3, r3, 3; stw r4, -7464(r3); blr  =>  m_drawWallShadowsFunc = fn; (offset 0x2E2D8)

typedef void (*DrawWallShadowsFn)(void);

struct ERLevel_SDWSF {
    char pad[0x2E2D8];
    DrawWallShadowsFn m_drawWallShadowsFunc;
    void SetDrawWallShadowsFunc(DrawWallShadowsFn fn);
};
void ERLevel_SDWSF::SetDrawWallShadowsFunc(DrawWallShadowsFn fn) {
    m_drawWallShadowsFunc = fn;
}
