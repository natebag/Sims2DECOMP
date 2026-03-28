class ERModel { char pad[308]; unsigned char m_val; public: unsigned char GetAttachmentColor(); };
unsigned char ERModel::GetAttachmentColor() { return m_val; }
