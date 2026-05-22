// 0x80165990 CasScene::DrawRoom(ERC*, CasScene::RoomId, EMat4&) (68B)

class ERC;
class EMat4;

class CasSceneBase {
public:
    int m_0_pad;
};

class CasScene : public CasSceneBase {
public:
    enum RoomId { kRoom0 = 0 };
    virtual ~CasScene() = 0;
    virtual void v04() = 0;
    virtual void v08() = 0;
    virtual void v0C() = 0;
    virtual void v10() = 0;
    virtual void v14() = 0;
    virtual void v18() = 0;
    virtual void v1C() = 0;
    virtual void v20() = 0;
    virtual void v24() = 0;
    virtual void v28() = 0;
    virtual void v2C() = 0;
    virtual void v30() = 0;
    virtual void v34() = 0;
    virtual void DrawSomething(ERC* erc, EMat4& mat) = 0;
    void DrawRoom(ERC* erc, RoomId room, EMat4& mat);
};

void CasScene::DrawRoom(ERC* erc, RoomId room, EMat4& mat) {
    if (room != 0) return;
    DrawSomething(erc, mat);
}
