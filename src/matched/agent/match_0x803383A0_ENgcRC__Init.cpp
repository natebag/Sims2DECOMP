// 0x803383A0 (32B) ENgcRC::Init(RCMode)
// Thin forwarder to ERC::Init(RCMode) base class.

enum RCMode {};

class ERC {
public:
    void Init(RCMode m);
};

class ENgcRC : public ERC {
public:
    void Init(RCMode m);
};

void ENgcRC::Init(RCMode m) {
    ERC::Init(m);
}
