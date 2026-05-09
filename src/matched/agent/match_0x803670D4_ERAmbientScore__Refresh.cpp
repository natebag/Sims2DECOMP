// 0x803670D4 ERAmbientScore::Refresh(EFile *) (44 B)
// PRAGMA_STUB: ERAmbientScore::Refresh(EFile *)
extern "C" void refreshScore(void*, void*, int);
void ERAmbientScore_Refresh(void* self, void* file) {
    if (file) {
        refreshScore(self, file, 0);
    }
}
