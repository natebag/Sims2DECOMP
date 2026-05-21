// 0x80239B04 EmitterSpr3dCameraXYZProcessCB(void*) (76B)
// ASMPROC_gpr_relabel: swap="10:11"
// ASMPROC_swap_adj: a="lis" b="mr" which=0
// ASMPROC_swap_adj: a="lfs" b="lfs" which=0

struct Camera {
    char pad[0x110];
    float m_110;
    float m_114;
    float m_118;
};

extern Camera* g_camera_SDA;
extern char g_emitter_z_scale[16];

struct Particle {
    char pad[0x30];
    float m_30;
    float m_34;
    float m_38;
};

extern void EmitterSpr3dProcessCB(void* p);

void EmitterSpr3dCameraXYZProcessCB(void* p) {
    Particle* part = (Particle*)p;
    Camera* cam = g_camera_SDA;
    float x = cam->m_110;
    float scale = *(float*)g_emitter_z_scale;
    part->m_30 = x;
    part->m_34 = cam->m_114;
    part->m_38 = cam->m_118 + scale;
    EmitterSpr3dProcessCB(p);
}
