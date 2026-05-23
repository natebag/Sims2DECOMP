// 0x8003531C ESim::GetModelPart(int) (20 B)
// FLAGS: -fno-schedule-insns
struct ESimModel { char _pad[104]; unsigned m_parts[1]; };
struct ESim { char _pad[0x63c]; ESimModel* m_simModel; unsigned GetModelPart(int); };
unsigned ESim::GetModelPart(int index) { return m_simModel->m_parts[index]; }
