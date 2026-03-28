// 0x80352214 (4 bytes)
struct EVec4 { float x, y, z, w; };

class ERC;
class EMat4;
class EVec4;
namespace Effects {
    void GetFaceCameraRotation(ERC*, EMat4&, EVec4&, bool);
}
void Effects::GetFaceCameraRotation(ERC*, EMat4&, EVec4&, bool) {}
