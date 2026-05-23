// 0x8012C778 cXPersonImpl::GetPersonDataArray(void) (8 B)
struct cXPersonImpl { char _pad[8]; unsigned m_personDataArray[1]; unsigned* GetPersonDataArray(); };
unsigned* cXPersonImpl::GetPersonDataArray() { return m_personDataArray; }
