// 0x801657E0 CasScene::Update (68b)

struct CasScene {
    char pad[0xA80];
    void* model;
    char pad2[0x3C];
    void* anim;
};

extern void CasScene_UpdateInternal(CasScene*);
extern void UpdateAnim(void*);
extern void UpdateModel(void*);

void CasScene_Update(CasScene* self, float dt) {
    CasScene_UpdateInternal(self);
    UpdateAnim(self->anim);
    if (self->model != 0) {
        UpdateModel(self->model);
    }
}
