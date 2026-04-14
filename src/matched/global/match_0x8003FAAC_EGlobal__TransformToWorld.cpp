/* EGlobal::TransformToWorld(EVec2 &, EVec3 &) at 0x8003FAAC (80B) */

struct EVec2;
struct EVec3;

struct E3DWindow {
    void TransformToWorld(EVec2&, EVec3&);
};

struct EGlobal {
    E3DWindow* GetWin(void);
    void TransformToWorld(EVec2&, EVec3&);
};

void EGlobal::TransformToWorld(EVec2& v2, EVec3& v3) {
    if (GetWin() != 0) {
        GetWin()->TransformToWorld(v2, v3);
    }
}
