// 0x80142B64 RoutingSlot::AllowDirection(int) (32B)

struct RoutingSlot {
    char pad[28];
    int m_dirFlags;
    void AllowDirection(unsigned int dir);
};

void RoutingSlot::AllowDirection(unsigned int dir) {
    if (dir > 7) return;
    m_dirFlags |= (1 << dir);
}
