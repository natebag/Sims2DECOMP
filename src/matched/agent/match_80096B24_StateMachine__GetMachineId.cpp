struct SM { char p[0x1C]; int m_id; int GetMachineId() const; };
int SM::GetMachineId() const { return m_id; }
