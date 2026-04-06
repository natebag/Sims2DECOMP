// FLAGS: -msdata=eabi -G 8
// 0x8004DF34 ISimsObjectModel::AnimStartImmediate (80b)
extern void SetTrackAnim(void*, int, unsigned int, float, int, int);
extern char g_defaultBlend[];

struct ISimsObjectModel {
    char pad[820];
    char animCtrl[180];
    int field_3E8;
};

void AnimStartImmediate(ISimsObjectModel* self, unsigned int animId) {
    SetTrackAnim(&self->animCtrl, 1, animId, *(float*)g_defaultBlend, 0, 0);
    self->field_3E8 = 1;
}
