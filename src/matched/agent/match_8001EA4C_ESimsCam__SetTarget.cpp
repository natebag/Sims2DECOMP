// FLAGS: -fno-elide-constructors
struct EVec3 { int x, y, z; };
struct ESimsCam { char pad[1084]; EVec3 m_target; void SetTarget(EVec3& t); };
void ESimsCam::SetTarget(EVec3& t) { m_target = t; }
