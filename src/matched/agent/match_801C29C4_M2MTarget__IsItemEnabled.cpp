/* M2MTarget::IsItemEnabled(int) at 0x801C29C4 (96B) */

struct M2MTarget {
    char pad_000[0x10C];
    int m_field10C;
    int m_field110;
    char pad_114[0x168 - 0x114];
    int m_field168;

    int IsItemEnabled(int item);
    int IsItemEnabledMemCardSelect(int item);
    int IsItemEnabledSaveGameSelect(int item);
};

int M2MTarget::IsItemEnabled(int item) {
    int result = 1;
    if (m_field168 == 0) {
        result = 0;
    } else if (m_field10C == 0xFF) {
        result = IsItemEnabledMemCardSelect(item);
    } else if (m_field110 == 0xFF) {
        result = IsItemEnabledSaveGameSelect(item);
    }
    return result;
}
