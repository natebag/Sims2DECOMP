struct Embedded { int x; };
class ERModel { char pad[324]; Embedded m_val; public: Embedded *GetLightPos(); };
Embedded *ERModel::GetLightPos() { return &m_val; }
