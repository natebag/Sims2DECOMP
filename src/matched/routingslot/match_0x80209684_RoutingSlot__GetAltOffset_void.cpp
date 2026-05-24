// 0x80209684 RoutingSlot::GetAltOffset(void) (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="addi 3,9,-12536"

struct RoutingSlot {
    void GetAltOffset();
};

void RoutingSlot::GetAltOffset() {
}
