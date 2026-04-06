// FLAGS: -msdata=eabi -G 8
// 0x8004DF84 ISimsObjectModel::AnimStartBlendIn (80b)
extern void SetTrackAnim(void*, int, unsigned int, float, int, int);
extern char g_blendInValue[];

struct ISimsObjectModel {
    char pad[820];
    char animCtrl[180];
    int field_3E8;
};

void AnimStartBlendIn(ISimsObjectModel* self, unsigned int animId) {
    SetTrackAnim(&self->animCtrl, 1, animId, *(float*)g_blendInValue, 3, 0);
    self->field_3E8 = 2;
}
