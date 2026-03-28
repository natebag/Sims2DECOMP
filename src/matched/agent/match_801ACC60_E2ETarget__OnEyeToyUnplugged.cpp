class E2ETarget {
public:
    void SpawnNoEyeToyDialogBox(void);
    void OnEyeToyUnplugged(void);
};

void E2ETarget::OnEyeToyUnplugged(void) {
    SpawnNoEyeToyDialogBox();
}
