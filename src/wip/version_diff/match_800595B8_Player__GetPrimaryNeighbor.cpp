/*
  Player::GetPrimaryNeighbor(void) - 0x800595B8 (164 bytes)

  Traverses the neighborhood object hierarchy to find the primary neighbor
  for this player, storing result in m_primaryNeighbor and returning it.
*/

struct INeighborhood {
    virtual void* vf00(int);
    virtual void* vf01(int);
    virtual void* vf02(int);
    virtual void* vf03(int);
    virtual void* vf04(int);
    virtual void* vf05(int);
    virtual void* vf06(int);
    virtual void* vf07(int);
    virtual void* vf08(int);
    virtual void* vf09(int);
    virtual void* vf10(int);
    virtual void* vf11(int);
    virtual void* vf12(int);
    virtual void* vf13(int);
    virtual void* vf14(int);
    virtual void* vf15(int);
    virtual void* vf16(int);
    virtual void* vf17(int);
    virtual void* vf18(int);
    virtual void* vf19(int);
    virtual void* vf20(int);
    virtual void* vf21(int);
    virtual void* vf22(int);
    virtual void* vf23(void*);
    virtual void* vf24(int);
    virtual void* vf25(int);
    virtual void* vf26(int);
    virtual void* vf27(int);
    virtual void* vf28(int);
    virtual void* vf29(int);
    virtual void* vf30(int);
    virtual void* vf31(int);
    virtual void* vf32(int);
    virtual void* vf33(int);
    virtual void* vf34(int);
    virtual void* GetPrimary(int);
};

struct IPersonObj {
    virtual void* vf00(int);
    virtual void* vf01(int);
    virtual void* vf02(int);
    virtual void* vf03(int);
    virtual void* vf04(int);
    virtual void* vf05(int);
    virtual void* vf06(int);
    virtual void* GetNeighbor(int);
};

extern INeighborhood* Globs_pNeighborhood;

struct GameDataGlobals {
    char _pad[0xD8];
    int m_field_0D8;
};
extern GameDataGlobals _gd;

class Player {
public:
    int m_field_000;
    int m_primaryNeighbor;
    void* m_field_008;
    void* m_field_00C;
    void* GetPrimaryNeighbor(void);
};

void* Player::GetPrimaryNeighbor(void) {
    INeighborhood* hood = Globs_pNeighborhood;
    void* result = 0;
    void* first = hood->GetPrimary(_gd.m_field_0D8);
    if (first) {
        IPersonObj* person = (IPersonObj*)first;
        void* second = person->vf06(m_field_000);
        if (second) {
            result = hood->vf23(*(void**)second);
        }
    }
    m_primaryNeighbor = (int)result;
    return result;
}
