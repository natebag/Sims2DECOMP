/* ENgcRC::Init(RCMode) at 0x803383A0 (32B) */
// 0x803383A0 (32 bytes)
typedef int RCMode;
class ERC {
public:
    void Init(RCMode mode);
};
class ENgcRC : public ERC {
public:
    void Init(RCMode mode);
};
void ENgcRC::Init(RCMode mode) {
    ERC::Init(mode);
}
