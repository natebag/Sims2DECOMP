// FLAGS: -fno-schedule-insns
// 0x80221B54 InteractorModule::WallManipulator::GetTexGenMode(void) (40B)
struct WallManipulator {
    char pad[196];
    int m_flags;
};

int WallManipulator__GetTexGenMode(WallManipulator* self) {
    int flags = self->m_flags;
    if ((flags & 128) == 0) return 0;
    if ((flags & 4) == 0) return 0;
    return 2;
}
