typedef unsigned char u8;

void awarenessSetPlayerControl(u8*, int);

void SAnimator2_SetPlayerControl(u8* self, int ctrl) {
    if (ctrl == 1) {
        *(int*)(self + 0x61C) |= 1;
    } else {
        *(int*)(self + 0x61C) &= ~1;
    }
    u8* data = *(u8**)(self + 8);
    if (ctrl != 0) {
        *(int*)(data + 0x334) |= 1;
    } else {
        *(int*)(data + 0x334) &= ~1;
    }
    awarenessSetPlayerControl(self + 0x620, ctrl);
}
