// 0x801892FC HUDTarget::ManageHUD(short, short, short) (100B)

class HUDTarget {
public:
    void ShowHUD();
    void HideHUD();
    void RequestHUD(short a, short b, short c);
    int ManageHUD(short a, short kind, short c);
};

int HUDTarget::ManageHUD(short a, short kind, short c) {
    switch (kind) {
        case 0:
            ShowHUD();
            break;
        case 1:
            HideHUD();
            break;
        case 2:
            RequestHUD(0, 0, a);
            break;
    }
    return 1;
}
