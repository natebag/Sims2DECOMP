// 0x80056738 ISimInstance::GetObCenter (36b)
// FLAGS: -fno-schedule-insns

struct EVec3 {
    float x, y, z;
};

struct ISimInstance {
    char _pad[0x100];
    EVec3 m_obCenter;
    
    EVec3 GetObCenter() const;
};

EVec3 ISimInstance::GetObCenter() const {
    return m_obCenter;
}
