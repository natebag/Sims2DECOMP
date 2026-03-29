// 0x8015E5C8 (4 bytes)
// TreeTableAdQuickData::operator=(ITreeTableAd &)
class ITreeTableAd;
class TreeTableAdQuickData {
public:
    TreeTableAdQuickData& operator=(ITreeTableAd& other);
};

TreeTableAdQuickData& TreeTableAdQuickData::operator=(ITreeTableAd& other) {
    return *this;
}
