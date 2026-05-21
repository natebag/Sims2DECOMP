// 0x802274DC EIDirLight::SetDir(EVec3 &) (32B)
// FLAGS: -fno-schedule-insns
struct EVec3I { int x; int y; int z; };
struct EIDirLight { char _pad[0xAC]; EVec3I m_dir; void SetDir(EVec3I& v); };
void EIDirLight::SetDir(EVec3I& v) {
    int x = v.x;
    int z = v.z;
    int y = v.y;
    EVec3I* d = &m_dir;
    d->x = x;
    d->z = z;
    d->y = y;
}
