// 0x801454C0 (16 bytes) - RoutingSlot::IsOnTopOfObject(void) const
// lbz r3,31(r3); subfic r0,r3,0; adde r3,r0,r3; blr
// Returns this->field_1F == 0 (boolean negate)

struct RoutingSlot_IOT {
    char pad[0x1F];
    unsigned char m_onTopFlag;

    int IsOnTopOfObject() const;
};

int RoutingSlot_IOT::IsOnTopOfObject() const {
    return m_onTopFlag == 0;
}
