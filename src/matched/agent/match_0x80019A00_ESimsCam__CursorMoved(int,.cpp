// 0x80019A00 ESimsCam::CursorMoved(int) (4 B)
// FLAGS: -fno-schedule-insns
struct ESimsCam { void CursorMoved(int); };
void ESimsCam::CursorMoved(int) {}
