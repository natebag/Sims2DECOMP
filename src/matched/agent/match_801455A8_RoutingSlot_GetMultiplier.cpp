// 0x801455A8 (16 bytes) - RoutingSlot::GetMultiplier(RoutingSlot::VerticalPosition) const
// rlwinm r4,r4,2,0,29; addi r3,r3,16; lwzx r3,r3,r4; blr
// Array access: return m_multipliers[pos]

struct RoutingSlot_GM {
    char pad[0x10];
    int m_multipliers[1];

    int GetMultiplier(int pos) const;
};

int RoutingSlot_GM::GetMultiplier(int pos) const {
    return m_multipliers[pos];
}
