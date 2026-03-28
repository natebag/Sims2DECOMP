struct EVec3 {
    float x, y, z;
};
struct EIStaticModel {
    char _pad[0xF0];
    EVec3 m_GetPos;
    void GetPos(EVec3 *out);
};
void EIStaticModel::GetPos(EVec3 *out) {
    *out = m_GetPos;
}
