// 0x80118F0C cSamplePatch::SetLooped(int) (8 B)
struct cSamplePatch { char _pad[0x10]; unsigned m_looped; void SetLooped(int); };
void cSamplePatch::SetLooped(int val) { m_looped = val; }
