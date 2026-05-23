// 0x801892D4 HUDTarget::RemoveHUDControl(short, short) (40B)

extern char* GetJobHUDControlName(short id);

class HUDTarget {
public:
    bool RemoveHUDControl(short id, short val);
};

bool HUDTarget::RemoveHUDControl(short id, short val) {
    GetJobHUDControlName(val);
    return true;
}
