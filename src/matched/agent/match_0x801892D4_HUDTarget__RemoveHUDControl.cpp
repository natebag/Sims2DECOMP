// PRAGMA_STUB: HUDTarget::RemoveHUDControl(short, short)
// 0x801892D4 HUDTarget::RemoveHUDControl(short, short) (40B)
struct HUDTarget;

extern const char* GetJobHUDControlName(short ctl);

int HUDTarget__RemoveHUDControl(HUDTarget* self, short c1, short c2) {
    (void)c1;
    GetJobHUDControlName(c2);
    return 1;
}
