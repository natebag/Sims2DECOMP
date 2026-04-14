/* ISimsObjectModel::StartBurp(int) at 0x8004ED24 (24B) */

extern float g_burpValues[4];

struct ISimsObjectModel {
    char pad[0x3F8];
    float m_burpArray[1];

    void StartBurp(int index);
};

void ISimsObjectModel::StartBurp(int index) {
    m_burpArray[index] = g_burpValues[0];
}
