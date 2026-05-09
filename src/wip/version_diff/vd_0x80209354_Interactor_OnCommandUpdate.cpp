struct Interactor {
    char pad[52];
    int field_34;
    int field_38;
    int field_3C;
    int field_40;
    
    void OnCommandUpdate(int cmd, float val);
};

void Interactor::OnCommandUpdate(int cmd, float val) {
    if (cmd == 7) {
        float temp1 = val;
        float temp2 = val;
        field_34 = *(int*)&temp1;
        field_38 = *(int*)&temp2;
    } else if (cmd == 8) {
        float temp1 = val;
        float temp2 = val;
        field_3C = *(int*)&temp1;
        field_40 = *(int*)&temp2;
    }
}
