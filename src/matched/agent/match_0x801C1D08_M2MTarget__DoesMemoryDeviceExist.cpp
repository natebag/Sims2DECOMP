// 0x801C1D08 M2MTarget::DoesMemoryDeviceExist() (104B)

class SimsMemCardWrap {
public:
    static bool IsCardInSlot(int slot, bool& out);
};

class M2MTarget {
public:
    int DoesMemoryDeviceExist();
};

int M2MTarget::DoesMemoryDeviceExist() {
    bool a = false;
    SimsMemCardWrap::IsCardInSlot(0, a);
    bool b = false;
    SimsMemCardWrap::IsCardInSlot(1, b);
    int result = 0;
    if (a) {
        result = 1;
    } else if (b) {
        result = 1;
    }
    return result;
}
