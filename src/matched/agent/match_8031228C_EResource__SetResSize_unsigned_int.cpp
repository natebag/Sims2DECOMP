struct SizeField { unsigned int size : 24; unsigned int flags : 8; };
class EResource { char pad[16]; SizeField m_sizeField; public: void SetResSize(unsigned int); };
void EResource::SetResSize(unsigned int size) { m_sizeField.size = size; }
