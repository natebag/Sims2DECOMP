// 0x8030589C (12 bytes) - EController::IsStable(void)
// lwz r3,4(r3); rlwinm r3,r3,31,31,31; blr
// Returns bit 1 of this->field_4: (field_4 >> 1) & 1

struct EController_IS {
    int m_pad;
    unsigned int m_flags;

    int IsStable();
};

int EController_IS::IsStable() {
    return (m_flags >> 1) & 1;
}
