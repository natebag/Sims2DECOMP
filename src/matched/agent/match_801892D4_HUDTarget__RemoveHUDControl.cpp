void GetJobHUDControlName(short id);

class HUDTarget {
public:
    int RemoveHUDControl(short a, short b);
};

int HUDTarget::RemoveHUDControl(short a, short b) {
    GetJobHUDControlName(b);
    return 1;
}
