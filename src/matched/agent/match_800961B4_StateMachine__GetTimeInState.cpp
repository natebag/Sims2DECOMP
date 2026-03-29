struct SM { char p[0x50]; float m_time; float GetTimeInState() const; };
float SM::GetTimeInState() const { return m_time; }
