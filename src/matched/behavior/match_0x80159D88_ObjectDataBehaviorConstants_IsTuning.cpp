// 0x80159D88 ObjectDataBehaviorConstants::IsTuning (12B) — bit 15 of short@4
struct ObjectDataBehaviorConstants {
    char pad[4];
    short m_flags;
    int IsTuning() const;
};
int ObjectDataBehaviorConstants::IsTuning() const { return (m_flags & 0x8000) != 0; }
