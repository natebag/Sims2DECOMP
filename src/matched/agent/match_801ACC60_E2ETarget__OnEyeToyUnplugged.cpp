class E2ETarget {
public:
    void SpawnNoEyeToyDialogBox();
    void OnEyeToyUnplugged();
};

void E2ETarget::OnEyeToyUnplugged() {
    SpawnNoEyeToyDialogBox();
}
