// 0x802274FC EIDirLight::GetDir(void) const (8B)
struct EVec3I { int x; int y; int z; };
struct EIDirLight { char _pad[0xAC]; EVec3I m_dir; EVec3I* GetDir() const; };
EVec3I* EIDirLight::GetDir() const { return const_cast<EVec3I*>(&m_dir); }
