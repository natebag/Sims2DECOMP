typedef unsigned char u8;

void awarenessMove(u8*);
void moveAnimation(u8*);
void updateFreeMoveState(u8*);

void SAnimator2_updateMovementState(u8* self) {
    if (*(int*)(self + 0x18) > 5) {
        awarenessMove(self);
        return;
    }
    if (*(int*)(self + 0x10) == 1) {
        moveAnimation(self);
        return;
    }
    if (*(int*)(self + 0x61C) & 1) {
        updateFreeMoveState(self);
    }
}
