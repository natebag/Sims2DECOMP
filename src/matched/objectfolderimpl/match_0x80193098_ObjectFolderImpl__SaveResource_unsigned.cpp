// 0x80193098 ObjectFolderImpl::SaveResource(unsigned (68 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 11,0x1348(31); subf 0,0,27; li 9,1; slw 9,9,0; or 11,11,9; stw 11,0x1348(31); lwz 0,0x1348(31); stw 27,0x134c(31); ori 0,0,32; stw 0,0x1348(31); lwz 0,0x15c(1); lwz 12,0x138(1); mtspr 8,0; lmw 25,0x13c(1); mtcrf 8,12; addi 1,1,344"

struct ObjectFolderImpl {
    void SaveResource();
};

void ObjectFolderImpl::SaveResource() {
}
