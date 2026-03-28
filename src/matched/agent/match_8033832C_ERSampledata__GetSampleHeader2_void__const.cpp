class ERSampledata { char pad[24]; int m_val; public: int GetSampleHeader2() const; };
int ERSampledata::GetSampleHeader2() const { return m_val; }
