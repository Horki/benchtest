	.text
	.file	"bench.cpp"
	.p2align	4, 0x90         # -- Begin function _ZL13bench_reserveRN9benchmark5StateE
	.type	_ZL13bench_reserveRN9benchmark5StateE,@function
_ZL13bench_reserveRN9benchmark5StateE:  # @_ZL13bench_reserveRN9benchmark5StateE
	.cfi_startproc
# %bb.0:
	pushq	%rbx
	.cfi_def_cfa_offset 16
	.cfi_offset %rbx, -16
	movq	%rdi, %rbx
	movq	(%rbx), %rax
	testq	%rax, %rax
	je	.LBB0_2
	.p2align	4, 0x90
.LBB0_5:                                # =>This Inner Loop Header: Depth=1
	addq	$-1, %rax
	movq	%rax, (%rbx)
	movl	$4, %edi
	callq	_Znwm@PLT
	movq	%rax, %rdi
	callq	_ZdlPv@PLT
	movq	(%rbx), %rax
	testq	%rax, %rax
	jne	.LBB0_5
.LBB0_2:
	cmpb	$0, 24(%rbx)
	jne	.LBB0_6
# %bb.3:
	movq	%rbx, %rdi
	callq	_ZN9benchmark5State16StartKeepRunningEv@PLT
	cmpb	$0, 26(%rbx)
	jne	.LBB0_6
# %bb.4:
	movq	(%rbx), %rax
	testq	%rax, %rax
	jne	.LBB0_5
.LBB0_6:
	movq	%rbx, %rdi
	popq	%rbx
	.cfi_def_cfa_offset 8
	jmp	_ZN9benchmark5State17FinishKeepRunningEv@PLT # TAILCALL
.Lfunc_end0:
	.size	_ZL13bench_reserveRN9benchmark5StateE, .Lfunc_end0-_ZL13bench_reserveRN9benchmark5StateE
	.cfi_endproc
                                        # -- End function
	.globl	main                    # -- Begin function main
	.p2align	4, 0x90
	.type	main,@function
main:                                   # @main
	.cfi_startproc
# %bb.0:
	pushq	%rbx
	.cfi_def_cfa_offset 16
	subq	$16, %rsp
	.cfi_def_cfa_offset 32
	.cfi_offset %rbx, -16
	movq	%rsi, %rbx
	movq	%fs:40, %rax
	movq	%rax, 8(%rsp)
	movl	%edi, 4(%rsp)
	leaq	4(%rsp), %rdi
	callq	_ZN9benchmark10InitializeEPiPPc@PLT
	movl	4(%rsp), %edi
	movq	%rbx, %rsi
	callq	_ZN9benchmark27ReportUnrecognizedArgumentsEiPPc@PLT
	movl	%eax, %ecx
	movl	$1, %eax
	testb	%cl, %cl
	jne	.LBB1_2
# %bb.1:
	callq	_ZN9benchmark22RunSpecifiedBenchmarksEv@PLT
	xorl	%eax, %eax
.LBB1_2:
	movq	%fs:40, %rcx
	cmpq	8(%rsp), %rcx
	jne	.LBB1_4
# %bb.3:
	addq	$16, %rsp
	.cfi_def_cfa_offset 16
	popq	%rbx
	.cfi_def_cfa_offset 8
	retq
.LBB1_4:
	.cfi_def_cfa_offset 32
	callq	__stack_chk_fail@PLT
.Lfunc_end1:
	.size	main, .Lfunc_end1-main
	.cfi_endproc
                                        # -- End function
	.section	.text.startup,"ax",@progbits
	.p2align	4, 0x90         # -- Begin function _GLOBAL__sub_I_bench.cpp
	.type	_GLOBAL__sub_I_bench.cpp,@function
_GLOBAL__sub_I_bench.cpp:               # @_GLOBAL__sub_I_bench.cpp
.Lfunc_begin0:
	.cfi_startproc
	.cfi_personality 155, DW.ref.__gxx_personality_v0
	.cfi_lsda 27, .Lexception0
# %bb.0:
	pushq	%r14
	.cfi_def_cfa_offset 16
	pushq	%rbx
	.cfi_def_cfa_offset 24
	pushq	%rax
	.cfi_def_cfa_offset 32
	.cfi_offset %rbx, -24
	.cfi_offset %r14, -16
	callq	_ZN9benchmark8internal17InitializeStreamsEv@PLT
	movl	$200, %edi
	callq	_Znwm@PLT
	movq	%rax, %rbx
.Ltmp0:
	leaq	.L.str(%rip), %rsi
	movq	%rax, %rdi
	callq	_ZN9benchmark8internal9BenchmarkC2EPKc@PLT
.Ltmp1:
# %bb.1:
	movq	_ZTVN9benchmark8internal17FunctionBenchmarkE@GOTPCREL(%rip), %rax
	addq	$16, %rax
	movq	%rax, (%rbx)
	leaq	_ZL13bench_reserveRN9benchmark5StateE(%rip), %rax
	movq	%rax, 192(%rbx)
	movq	%rbx, %rdi
	callq	_ZN9benchmark8internal25RegisterBenchmarkInternalEPNS0_9BenchmarkE@PLT
	movq	%rax, _ZL25_benchmark_2bench_reserve(%rip)
	addq	$8, %rsp
	.cfi_def_cfa_offset 24
	popq	%rbx
	.cfi_def_cfa_offset 16
	popq	%r14
	.cfi_def_cfa_offset 8
	retq
.LBB2_2:
	.cfi_def_cfa_offset 32
.Ltmp2:
	movq	%rax, %r14
	movq	%rbx, %rdi
	callq	_ZdlPv@PLT
	movq	%r14, %rdi
	callq	_Unwind_Resume@PLT
.Lfunc_end2:
	.size	_GLOBAL__sub_I_bench.cpp, .Lfunc_end2-_GLOBAL__sub_I_bench.cpp
	.cfi_endproc
	.section	.gcc_except_table,"a",@progbits
	.p2align	2
GCC_except_table2:
.Lexception0:
	.byte	255                     # @LPStart Encoding = omit
	.byte	255                     # @TType Encoding = omit
	.byte	1                       # Call site Encoding = uleb128
	.uleb128 .Lcst_end0-.Lcst_begin0
.Lcst_begin0:
	.uleb128 .Lfunc_begin0-.Lfunc_begin0 # >> Call Site 1 <<
	.uleb128 .Ltmp0-.Lfunc_begin0   #   Call between .Lfunc_begin0 and .Ltmp0
	.byte	0                       #     has no landing pad
	.byte	0                       #   On action: cleanup
	.uleb128 .Ltmp0-.Lfunc_begin0   # >> Call Site 2 <<
	.uleb128 .Ltmp1-.Ltmp0          #   Call between .Ltmp0 and .Ltmp1
	.uleb128 .Ltmp2-.Lfunc_begin0   #     jumps to .Ltmp2
	.byte	0                       #   On action: cleanup
	.uleb128 .Ltmp1-.Lfunc_begin0   # >> Call Site 3 <<
	.uleb128 .Lfunc_end2-.Ltmp1     #   Call between .Ltmp1 and .Lfunc_end2
	.byte	0                       #     has no landing pad
	.byte	0                       #   On action: cleanup
.Lcst_end0:
	.p2align	2
                                        # -- End function
	.type	_ZL25_benchmark_2bench_reserve,@object # @_ZL25_benchmark_2bench_reserve
	.local	_ZL25_benchmark_2bench_reserve
	.comm	_ZL25_benchmark_2bench_reserve,8,8
	.type	.L.str,@object          # @.str
	.section	.rodata.str1.1,"aMS",@progbits,1
.L.str:
	.asciz	"bench_reserve"
	.size	.L.str, 14

	.section	.init_array,"aw",@init_array
	.p2align	3
	.quad	_GLOBAL__sub_I_bench.cpp
	.hidden	DW.ref.__gxx_personality_v0
	.weak	DW.ref.__gxx_personality_v0
	.section	.data.DW.ref.__gxx_personality_v0,"aGw",@progbits,DW.ref.__gxx_personality_v0,comdat
	.p2align	3
	.type	DW.ref.__gxx_personality_v0,@object
	.size	DW.ref.__gxx_personality_v0, 8
DW.ref.__gxx_personality_v0:
	.quad	__gxx_personality_v0

	.ident	"clang version 8.0.0 (tags/RELEASE_800/final)"
	.section	".note.GNU-stack","",@progbits
	.addrsig
	.addrsig_sym _ZL13bench_reserveRN9benchmark5StateE
	.addrsig_sym __gxx_personality_v0
	.addrsig_sym _GLOBAL__sub_I_bench.cpp
	.addrsig_sym __stack_chk_fail
	.addrsig_sym _Unwind_Resume
