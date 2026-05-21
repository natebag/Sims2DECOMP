// 0x8022E28C EIStaticModel::GetOrient(void) const (8B)
struct EIStaticModel { char _pad[0xC0]; char m_orient[1]; const char* GetOrient() const; };
const char* EIStaticModel::GetOrient() const { return m_orient; }
