// 0x8020956C RoutingSlot::SnapsToDirection(void) (24 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,0x48(3); cmpwi 0,0; beq 0f; li 9,1; 0:; mr 3,9"

struct RoutingSlot {
    void SnapsToDirection();
};

void RoutingSlot::SnapsToDirection() {
}
