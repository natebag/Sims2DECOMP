// 0x800CB5F4 Neighbor::CalculateBookmarkAd(WantFear::Bookmark &) (80B)

namespace WantFear {
    struct AdData {};
    struct Bookmark {
        short GetTarget() const;
        AdData& GetAdData() const;
    };
}

class Neighbor {
    void CalculateWantFearAd(WantFear::AdData&, short);
public:
    void CalculateBookmarkAd(WantFear::Bookmark& bookmark);
};

void Neighbor::CalculateBookmarkAd(WantFear::Bookmark& bookmark) {
    short target = bookmark.GetTarget();
    WantFear::AdData& adData = bookmark.GetAdData();
    CalculateWantFearAd(adData, target);
}
