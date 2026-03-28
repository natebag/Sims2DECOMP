// 0x80145348 (12 bytes)
// ObjectSlot::IsFreePos(void)
// lwz r3, 16(r3); rlwinm r3, r3, 31, 31, 31; blr
struct Slot;

class ObjectSlot {
public:
    char m_pad[16];
    int m_flags;
    int IsFreePos();
};

int ObjectSlot::IsFreePos() {
    return (m_flags >> 1) & 1;
}
