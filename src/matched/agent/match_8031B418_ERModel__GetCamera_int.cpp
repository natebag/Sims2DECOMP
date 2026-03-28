struct ENCameraPoint { char data[88]; };
class ERModel { char pad[296]; ENCameraPoint *m_camera; public: ENCameraPoint *GetCamera(int); };
ENCameraPoint *ERModel::GetCamera(int idx) { return &m_camera[idx]; }
