// 0x8012C9F8 cXPersonImpl::SetChangingOutfitMode(bool) (8 B)
struct cXPersonImpl { char _pad[0x530]; unsigned m_changingOutfitMode; void SetChangingOutfitMode(bool); };
void cXPersonImpl::SetChangingOutfitMode(bool val) { m_changingOutfitMode = val; }
