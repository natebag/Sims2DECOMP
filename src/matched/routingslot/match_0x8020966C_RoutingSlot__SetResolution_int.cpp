// 0x8020966C RoutingSlot::SetResolution(int) (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="addi 3,9,-12616"

struct RoutingSlot {
    void SetResolution();
};

void RoutingSlot::SetResolution() {
}
