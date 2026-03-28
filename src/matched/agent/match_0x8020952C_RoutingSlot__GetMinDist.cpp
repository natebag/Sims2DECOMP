struct RoutingSlot {
    char pad[0x20];
    float m_minDist;
};

float* RoutingSlot_GetMinDist(RoutingSlot* self) {
    return &self->m_minDist;
}
