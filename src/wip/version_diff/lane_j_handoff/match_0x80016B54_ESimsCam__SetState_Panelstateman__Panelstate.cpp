// 0x80016B54 (128B) ESimsCam::SetState(Panelstateman::Panelstate)
// WALL: switch_branch_tree — needs `branch_tree_to_range` mutator authoring.
// Source-level descope FAILED (3 attempts). See docs/tracking/esimscam_setstate_descope_findings.md
// for full DOL anatomy + failed source attempts + recommended mutator spec.
//
// DOL has 0x10 bytes of compiler-emitted UNREACHABLE comparison (cmpwi r4,4; beq 0x3c
// after a `bge 0x3c` already routed states 3 and 4 to main path). Source-level C++
// constructs cannot naturally emit unreachable code — optimizer always eliminates it.
// This is mutator territory.

struct Panelstateman {
    enum Panelstate { /* 0, 3, 4, 8 known */ };
};

extern int IsUsingDirectControlInteractor(int);

struct ESimsCam {
    enum CameraMode { Mode0, Mode1 };

    char pad[4];
    int m_interactor;

    void SetMode(CameraMode mode);
    void SetState(Panelstateman::Panelstate state);
};

void ESimsCam::SetState(Panelstateman::Panelstate state) {
    // True logic per DOL flow analysis: state in {3, 4} → main path;
    // state == 8 → SetMode(Mode0); other states → no-op.
    if (state == 3 || state == 4) {
        int mode = IsUsingDirectControlInteractor(m_interactor);
        SetMode((CameraMode)mode);
    } else if (state == 8) {
        SetMode(Mode0);
    }
}
