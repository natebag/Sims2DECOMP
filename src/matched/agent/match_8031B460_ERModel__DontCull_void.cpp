class ERModel { char pad[44]; int m_val; public: int DontCull(); };
int ERModel::DontCull() { return m_val; }
