class BSplineVolume {
public:
    char m_pad[128];
    int m_id;
    int GetID();
};
int BSplineVolume::GetID() { return m_id; }
