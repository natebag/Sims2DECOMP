// 0x801492EC CalculateAttenuationValue(bool, (196 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="cmpwi 3,0; beq 6f; cmpwi 4,2; beq 2f; bgt 0f; cmpwi 4,0; beqlr; cmpwi 4,1; beq 1f; b 5f; 0:; cmpwi 4,3; beq 3f; cmpwi 4,4; beq 4f; b 5f; 1:; lis 9,-32706; lfs f1,-9288(9); blr; 2:; lfs f1,-31616(13); blr; 3:; lfs f1,-31612(13); blr; 4:; lfs f1,-31608(13); blr; 5:; lis 9,-32706; lfs f1,-9284(9); blr; 6:; cmpwi 4,2; beq 8f; bgt 7f; cmpwi 4,0; beqlr; cmpwi 4,1; beq 1b; b 11f; 7:; cmpwi 4,3; beq 9f; cmpwi 4,4; beq 10f; b 11f; 8:; lfs f1,-31628(13); blr; 9:; lfs f1,-31624(13); blr; 10:; lfs f1,-31620(13); blr; 11:; lis 9,-32706; lfs f1,-9284(9)"
extern "C" float f_801492EC() {}
