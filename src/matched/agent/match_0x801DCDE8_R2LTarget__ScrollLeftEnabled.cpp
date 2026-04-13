// 0x801DCDE8 R2LTarget::ScrollLeftEnabled (24B)
struct R2LTarget { char pad[0xA4]; int m_scrollLeftPtr; };
int R2LTarget_ScrollLeftEnabled(R2LTarget* self) {
    int r = 1;
    if (self->m_scrollLeftPtr <= 0) r = 0;
    return r;
}
