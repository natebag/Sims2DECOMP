// 0x8012CA18 cXPersonImpl::SetIgnoringObject(cXObject (8 B)
struct cXPersonImpl { char _pad[0x53c]; unsigned m_ignoringObject; void SetIgnoringObject(unsigned); };
void cXPersonImpl::SetIgnoringObject(unsigned obj) { m_ignoringObject = obj; }
