// 0x80038CE8 (8 bytes) — li r3, 5; blr

struct Slot;

class EyeToyClient {
public:
    static int GetTargetSlotCount();
};

int EyeToyClient::GetTargetSlotCount() {
    return 5;
}
