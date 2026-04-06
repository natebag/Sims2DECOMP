// 0x8032E0CC ENgcEngine::Init (40b)

struct ENgcEngine {
    char pad[8];
    int field08;
};

extern void EEngine_Init(void*);

void ENgcEngine_Init(ENgcEngine* self) {
    self->field08 = 0;
    EEngine_Init(self);
}
