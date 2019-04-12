	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 10, 14	sdk_version 10, 14
	.p2align	4, 0x90         ## -- Begin function _ZL13bench_reserveRN9benchmark5StateE
__ZL13bench_reserveRN9benchmark5StateE: ## @_ZL13bench_reserveRN9benchmark5StateE
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	pushq	%rbx
	pushq	%rax
	.cfi_offset %rbx, -24
	movq	%rdi, %rbx
	movq	(%rdi), %rax
	testq	%rax, %rax
	je	LBB0_2
	.p2align	4, 0x90
LBB0_5:                                 ## =>This Inner Loop Header: Depth=1
	decq	%rax
	movq	%rax, (%rbx)
	testq	%rax, %rax
	jne	LBB0_5
LBB0_2:
	cmpb	$0, 24(%rbx)
	jne	LBB0_6
## %bb.3:
	movq	%rbx, %rdi
	callq	__ZN9benchmark5State16StartKeepRunningEv
	cmpb	$0, 26(%rbx)
	jne	LBB0_6
## %bb.4:
	movq	(%rbx), %rax
	testq	%rax, %rax
	jne	LBB0_5
LBB0_6:
	movq	%rbx, %rdi
	addq	$8, %rsp
	popq	%rbx
	popq	%rbp
	jmp	__ZN9benchmark5State17FinishKeepRunningEv ## TAILCALL
	.cfi_endproc
                                        ## -- End function
	.globl	_main                   ## -- Begin function main
	.p2align	4, 0x90
_main:                                  ## @main
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	pushq	%rbx
	pushq	%rax
	.cfi_offset %rbx, -24
	movq	%rsi, %rbx
	movl	%edi, -12(%rbp)
	leaq	-12(%rbp), %rdi
	callq	__ZN9benchmark10InitializeEPiPPc
	movl	-12(%rbp), %edi
	movq	%rbx, %rsi
	callq	__ZN9benchmark27ReportUnrecognizedArgumentsEiPPc
	movl	%eax, %ecx
	movl	$1, %eax
	testb	%cl, %cl
	jne	LBB1_2
## %bb.1:
	callq	__ZN9benchmark22RunSpecifiedBenchmarksEv
	xorl	%eax, %eax
LBB1_2:
	addq	$8, %rsp
	popq	%rbx
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.section	__TEXT,__StaticInit,regular,pure_instructions
	.p2align	4, 0x90         ## -- Begin function _GLOBAL__sub_I_bench.cpp
__GLOBAL__sub_I_bench.cpp:              ## @_GLOBAL__sub_I_bench.cpp
Lfunc_begin0:
	.cfi_startproc
	.cfi_personality 155, ___gxx_personality_v0
	.cfi_lsda 16, Lexception0
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	pushq	%r14
	pushq	%rbx
	.cfi_offset %rbx, -32
	.cfi_offset %r14, -24
	callq	__ZN9benchmark8internal17InitializeStreamsEv
	movl	$192, %edi
	callq	__Znwm
	movq	%rax, %rbx
Ltmp0:
	leaq	L_.str(%rip), %rsi
	movq	%rax, %rdi
	callq	__ZN9benchmark8internal9BenchmarkC2EPKc
Ltmp1:
## %bb.1:
	movq	__ZTVN9benchmark8internal17FunctionBenchmarkE@GOTPCREL(%rip), %rax
	addq	$16, %rax
	movq	%rax, (%rbx)
	leaq	__ZL13bench_reserveRN9benchmark5StateE(%rip), %rax
	movq	%rax, 184(%rbx)
	movq	%rbx, %rdi
	callq	__ZN9benchmark8internal25RegisterBenchmarkInternalEPNS0_9BenchmarkE
	movq	%rax, __ZL25_benchmark_2bench_reserve(%rip)
	popq	%rbx
	popq	%r14
	popq	%rbp
	retq
LBB2_2:
Ltmp2:
	movq	%rax, %r14
	movq	%rbx, %rdi
	callq	__ZdlPv
	movq	%r14, %rdi
	callq	__Unwind_Resume
	ud2
Lfunc_end0:
	.cfi_endproc
	.section	__TEXT,__gcc_except_tab
	.p2align	2
GCC_except_table2:
Lexception0:
	.byte	255                     ## @LPStart Encoding = omit
	.byte	255                     ## @TType Encoding = omit
	.byte	1                       ## Call site Encoding = uleb128
	.uleb128 Lcst_end0-Lcst_begin0
Lcst_begin0:
	.uleb128 Lfunc_begin0-Lfunc_begin0 ## >> Call Site 1 <<
	.uleb128 Ltmp0-Lfunc_begin0     ##   Call between Lfunc_begin0 and Ltmp0
	.byte	0                       ##     has no landing pad
	.byte	0                       ##   On action: cleanup
	.uleb128 Ltmp0-Lfunc_begin0     ## >> Call Site 2 <<
	.uleb128 Ltmp1-Ltmp0            ##   Call between Ltmp0 and Ltmp1
	.uleb128 Ltmp2-Lfunc_begin0     ##     jumps to Ltmp2
	.byte	0                       ##   On action: cleanup
	.uleb128 Ltmp1-Lfunc_begin0     ## >> Call Site 3 <<
	.uleb128 Lfunc_end0-Ltmp1       ##   Call between Ltmp1 and Lfunc_end0
	.byte	0                       ##     has no landing pad
	.byte	0                       ##   On action: cleanup
Lcst_end0:
	.p2align	2
                                        ## -- End function
.zerofill __DATA,__bss,__ZL25_benchmark_2bench_reserve,8,3 ## @_ZL25_benchmark_2bench_reserve
	.section	__TEXT,__cstring,cstring_literals
L_.str:                                 ## @.str
	.asciz	"bench_reserve"

	.section	__DATA,__mod_init_func,mod_init_funcs
	.p2align	3
	.quad	__GLOBAL__sub_I_bench.cpp

.subsections_via_symbols
