// 0x801F6094 INVTarget::InstallShoppingPanelShaders(void) (64B)

class INVTarget {
public:
    void InstallShoppingCategoryShaders();
    int GetSelectedShoppingCategoryListIdx();
    void InstallShoppingObjectShaders(int);
    void InstallShoppingPanelShaders();
};

void INVTarget::InstallShoppingPanelShaders() {
    InstallShoppingCategoryShaders();
    int idx = GetSelectedShoppingCategoryListIdx();
    InstallShoppingObjectShaders(idx);
}
