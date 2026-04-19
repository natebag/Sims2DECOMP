// 0x801C1094 (52B) M2MTarget::OnSlotSelectItemSelected(int, ResultStruct&)
// Slot-fill: put the int into the first 255-sentinel slot. First slot sets
// companion slot to -1, second uses bitwise NOT of the slot value.

class M2MTarget {
public:
    struct ResultStruct {
        int a;
        int b;
    };
    void OnSlotSelectItemSelected(int slot, ResultStruct& r);
};

void M2MTarget::OnSlotSelectItemSelected(int slot, ResultStruct& r) {
    if (r.a == 255) {
        r.a = slot;
        r.b = -1;
        return;
    }
    if (r.b == 255) {
        r.b = ~slot;
    }
}
