struct ENDummyPoint { char data[88]; };
class ERModel { char pad[284]; ENDummyPoint *m_dummy; public: ENDummyPoint *GetDummy(int); };
ENDummyPoint *ERModel::GetDummy(int idx) { return &m_dummy[idx]; }
