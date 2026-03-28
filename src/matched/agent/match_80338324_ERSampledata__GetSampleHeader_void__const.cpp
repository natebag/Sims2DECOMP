class ERSampledata { char pad[20]; int m_val; public: int GetSampleHeader() const; };
int ERSampledata::GetSampleHeader() const { return m_val; }
