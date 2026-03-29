struct SM { char p[0x28]; float m_dt; float GetFrameDeltaTime() const; };
float SM::GetFrameDeltaTime() const { return m_dt; }
