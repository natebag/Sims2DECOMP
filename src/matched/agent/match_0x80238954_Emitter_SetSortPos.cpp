struct EVec3 {
    float x, y, z;
};
struct Emitter {
    char _pad[0x80];
    EVec3 m_SetSortPos;
    void SetSortPos(EVec3 *v);
};
void Emitter::SetSortPos(EVec3 *v) {
    m_SetSortPos = *v;
}
