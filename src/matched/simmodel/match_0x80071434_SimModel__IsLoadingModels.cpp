// 0x80071434 (44B) SimModel::IsLoadingModels(void) const
// Scan 26 consecutive words, return true if any has bit 5 (0x20) set.

class SimModel {
public:
    bool IsLoadingModels() const;
};

bool SimModel::IsLoadingModels() const {
    const unsigned int* p = (const unsigned int*)this;
    for (int i = 26; i != 0; i--) {
        unsigned int v = *p;
        p++;
        if (v & 0x20) return true;
    }
    return false;
}
