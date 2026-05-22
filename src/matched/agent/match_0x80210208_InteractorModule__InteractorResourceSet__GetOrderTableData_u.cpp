// 0x80210208 InteractorModule::InteractorResourceSet::GetOrderTableData(unsigned (56 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 11,0x6c(3); lis 9,-18725; lwz 0,0x70(3); ori 9,9,28087; subf 0,11,0; mullw 0,0,9; srawi 0,0,3; cmplw 4,0; bge 0f; mulli 3,4,56; add 3,11,3; blr; 0:; li 3,0"
extern "C" int f_80210208() {}
