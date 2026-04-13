// 0x80142BC8 RoutingSlot::SetDistances (16b)
// FLAGS: -fno-schedule-insns
typedef unsigned int uint;

struct RoutingSlot {
    char _pad[36];
    uint m_dist1;
    uint m_dist2;
    uint m_dist3;
};

void RoutingSlot__SetDistances(RoutingSlot *self, int d1, int d2, int d3) {
    self->m_dist3 = d3;
    self->m_dist1 = d1;
    self->m_dist2 = d2;
}
