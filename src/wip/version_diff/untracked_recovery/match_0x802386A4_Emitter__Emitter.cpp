// 0x802386A4 (136B) Emitter::Emitter(void)
// Calls EInstance base ctor, stores vtable, zero-initializes fields.

struct EInstance {
    EInstance();
};

extern float g_emitterDefaultFloat;
extern char g_EmitterVTable[];

struct Emitter : EInstance {
    void* vtable;
    char pad1[0x88];
    int field_8c;
    int field_90;
    int field_94;
    int field_98;
    int field_9c;
    int field_a0;
    int field_a4;
    int field_a8;
    int field_ac;
    int field_b0;
    float field_b4;
    float field_b8;
    int field_bc;
    int field_c0;
    char pad2[0x10];
    int field_d4;
    
    Emitter();
};

Emitter::Emitter() : EInstance() {
    vtable = g_EmitterVTable;
    field_8c = 0;
    field_90 = 0;
    field_94 = 0;
    field_98 = 0;
    field_9c = 0;
    field_a0 = 0;
    field_a4 = 0;
    field_a8 = 0;
    field_ac = 0;
    field_b0 = 0;
    field_b4 = g_emitterDefaultFloat;
    field_b8 = g_emitterDefaultFloat;
    field_bc = 0;
    field_c0 = 0;
    field_d4 = 0;
}
