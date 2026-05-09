// PRAGMA_STUB: HUDTarget::AddHUDControl(short, short, short &)
// 0x801892A8 HUDTarget::AddHUDControl(short, short, short&) (44B)
struct HUDTarget;

extern const char* GetJobHUDControlName(short ctl);

int HUDTarget__AddHUDControl(HUDTarget* self, short c1, short c2, short& out) {
    out = c1;
    GetJobHUDControlName(c1);
    return 1;
}
