// 0x80145330 ObjectSlot::IsSurface (24B)
struct ObjectSlot {
    char pad[0x10];
    int m_flags;
};
int ObjectSlot_IsSurface(ObjectSlot* self) {
    int result = 0;
    if (self->m_flags & 1) {
        result = 1;
    }
    return result;
}
