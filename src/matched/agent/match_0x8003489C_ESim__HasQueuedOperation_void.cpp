// 0x8003489C ESim::HasQueuedOperation(void) (28 B)
// FLAGS: -fno-schedule-insns
struct ESim { char _pad[0x43c]; int m_opCount; char _pad2[0xE0]; int m_hasOp; int HasQueuedOperation(); };
int ESim::HasQueuedOperation() { if (m_opCount > 0) return 1; return m_hasOp; }
