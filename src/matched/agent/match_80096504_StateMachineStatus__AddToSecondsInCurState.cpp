struct SMS { char p[0x14]; float m_sec; void AddToSecondsInCurState(float dt); };
void SMS::AddToSecondsInCurState(float dt) { m_sec += dt; }
