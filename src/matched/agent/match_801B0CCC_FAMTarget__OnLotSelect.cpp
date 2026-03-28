class FAMTarget {
public:
    int IsSelectedLotOccupied();
    void UpdateMenuState(int state);
    void OnLotSelect();
};

void FAMTarget::OnLotSelect() {
    if (IsSelectedLotOccupied()) {
        UpdateMenuState(1);
    } else {
        UpdateMenuState(2);
    }
}
