// 0x8014B440 (12 bytes)
// WantFear::Bookmark::GetOverlayShader(Neighbor *) const
// lis r3, 0x9F93; ori r3, r3, 0xFF74; blr
// Returns constant 0x9F93FF74 (blank shader ID)
class Neighbor;

namespace WantFear {

class Bookmark {
public:
    unsigned int GetOverlayShader(Neighbor* neighbor) const;
};

unsigned int Bookmark::GetOverlayShader(Neighbor* neighbor) const {
    return 0x9F93FF74;
}

}
