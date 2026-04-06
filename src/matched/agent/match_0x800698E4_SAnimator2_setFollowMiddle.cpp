// FLAGS: -msdata=eabi -G 8
// 0x800698E4 SAnimator2::setFollowMiddle (60b)
extern void setMovementVelocityFromAnim(void*);

struct SAnimator2 {
    char pad[24];
    int field_18;
    char pad2[1536];
    int field_61C;
};

void setFollowMiddle(SAnimator2* self) {
    self->field_18 = 3;
    self->field_61C = self->field_61C & ~0x5E;
    setMovementVelocityFromAnim(self);
}
