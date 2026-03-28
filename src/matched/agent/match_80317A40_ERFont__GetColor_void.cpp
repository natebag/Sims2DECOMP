struct Embedded { int x; };
class ERFont { char pad[88]; Embedded m_val; public: Embedded *GetColor(); };
Embedded *ERFont::GetColor() { return &m_val; }
