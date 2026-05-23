// 0x801892A8 HUDTarget::AddHUDControl(short, short, short&) (44B)

extern char* GetJobHUDControlName(short id);

class HUDTarget {
public:
    bool AddHUDControl(short id, short val, short& outRef);
};

bool HUDTarget::AddHUDControl(short id, short val, short& outRef) {
    outRef = id;
    GetJobHUDControlName(id);
    return true;
}
