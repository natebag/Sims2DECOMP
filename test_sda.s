	.file	"test_sda.cpp"
gcc2_compiled.:
	.section	".text"
	.align 2
	.globl GetFarZVal__Fv
	.type	 GetFarZVal__Fv,@function
GetFarZVal__Fv:
.L_fGetFarZVal__Fv_s:
	lis 9,g_graphicsGlobals@ha
	lfs 1,g_graphicsGlobals@l(9)
	blr
.Lfe1:
	.size	 GetFarZVal__Fv,.Lfe1-GetFarZVal__Fv
	.align 2
	.globl GetNearZVal__Fv
	.type	 GetNearZVal__Fv,@function
GetNearZVal__Fv:
.L_fGetNearZVal__Fv_s:
	lis 9,g_graphicsGlobals+4@ha
	lfs 1,g_graphicsGlobals+4@l(9)
	blr
.Lfe2:
	.size	 GetNearZVal__Fv,.Lfe2-GetNearZVal__Fv
	.align 2
	.globl GetScreenAspect__Fv
	.type	 GetScreenAspect__Fv,@function
GetScreenAspect__Fv:
.L_fGetScreenAspect__Fv_s:
	lis 9,g_graphicsGlobals+8@ha
	lfs 1,g_graphicsGlobals+8@l(9)
	blr
.Lfe3:
	.size	 GetScreenAspect__Fv,.Lfe3-GetScreenAspect__Fv
	.ident	"GCC: (GNU) 2.95.3 SN BUILD v1.76 for Nintendo Gamecube"
