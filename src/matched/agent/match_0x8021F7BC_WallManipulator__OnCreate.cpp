void *WM_GetVis(void);
void WM_CreateVis(void *, void *);

extern float gWM_Float1[];
extern float gWM_Float2[];

struct WM_OnCreateS {
    char _pad[0x50];
    float m_float50;
    float m_float54;
    void OnCreate(void);
};

void WM_OnCreateS::OnCreate(void) {
    void *vis = WM_GetVis();
    WM_CreateVis(vis, this);
    float a = gWM_Float1[0];
    float b = gWM_Float2[0];
    m_float50 = a;
    m_float54 = b;
}
