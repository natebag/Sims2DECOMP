// UIReflow::Reflow_Id at 0x8017EA1C (148b)
// T1 reattempt — flipped condition (DOL: ble = ch<=1 skips inner block)
// Existing wip source had `<= 1` (wrong direction); DOL takes `ble` to SKIP true/false
// when ch is '0' or '1', so the inner block runs only when ch > '1' (alphanumeric ID).

extern char kReflowIdOpen[];
extern char kReflowIdTrue[];
extern char kReflowIdFalse[];
extern char kReflowIdClose[];

struct UIReflow {
    void AddToBlock(char* str);
    void Reflow_Id(char* name, int value);
};

void UIReflow::Reflow_Id(char* name, int value) {
    AddToBlock(kReflowIdOpen);
    unsigned char ch = (unsigned char)name[0];
    if ((unsigned int)(ch - 0x30) > 1) {
        if (value != 0) {
            AddToBlock(kReflowIdTrue);
        } else {
            AddToBlock(kReflowIdFalse);
        }
    }
    AddToBlock(name);
    AddToBlock(kReflowIdClose);
}
