	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 11, 0	sdk_version 11, 3
	.globl	_swapld                         ; -- Begin function swapld
	.p2align	2
_swapld:                                ; @swapld
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #32                     ; =32
	.cfi_def_cfa_offset 32
	str	x0, [sp, #24]
	str	x1, [sp, #16]
	ldr	x8, [sp, #24]
	ldr	x8, [x8]
	str	x8, [sp, #8]
	ldr	x8, [sp, #16]
	ldr	x8, [x8]
	ldr	x9, [sp, #24]
	str	x8, [x9]
	ldr	x8, [sp, #8]
	ldr	x9, [sp, #16]
	str	x8, [x9]
	add	sp, sp, #32                     ; =32
	ret
	.cfi_endproc
                                        ; -- End function
	.globl	_swapu                          ; -- Begin function swapu
	.p2align	2
_swapu:                                 ; @swapu
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #32                     ; =32
	.cfi_def_cfa_offset 32
	str	x0, [sp, #24]
	str	x1, [sp, #16]
	ldr	x8, [sp, #24]
	ldr	w9, [x8]
	mov	x8, x9
	str	x8, [sp, #8]
	ldr	x8, [sp, #16]
	ldr	w9, [x8]
	ldr	x8, [sp, #24]
	str	w9, [x8]
	ldr	x8, [sp, #8]
                                        ; kill: def $w8 killed $w8 killed $x8
	ldr	x10, [sp, #16]
	str	w8, [x10]
	add	sp, sp, #32                     ; =32
	ret
	.cfi_endproc
                                        ; -- End function
	.globl	_maxld                          ; -- Begin function maxld
	.p2align	2
_maxld:                                 ; @maxld
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #48                     ; =48
	.cfi_def_cfa_offset 48
	str	x0, [sp, #40]
	str	w1, [sp, #36]
	ldr	x8, [sp, #40]
	ldr	x8, [x8]
	str	x8, [sp, #24]
	mov	w9, #1
	str	w9, [sp, #20]
LBB2_1:                                 ; =>This Inner Loop Header: Depth=1
	ldr	w8, [sp, #20]
	ldr	w9, [sp, #36]
	subs	w8, w8, w9
	b.hs	LBB2_7
; %bb.2:                                ;   in Loop: Header=BB2_1 Depth=1
	ldr	x8, [sp, #24]
	ldr	x9, [sp, #40]
	ldr	w10, [sp, #20]
	mov	x11, x10
	ldr	x9, [x9, x11, lsl #3]
	subs	x8, x8, x9
	b.le	LBB2_4
; %bb.3:                                ;   in Loop: Header=BB2_1 Depth=1
	ldr	x8, [sp, #24]
	str	x8, [sp, #8]                    ; 8-byte Folded Spill
	b	LBB2_5
LBB2_4:                                 ;   in Loop: Header=BB2_1 Depth=1
	ldr	x8, [sp, #40]
	ldr	w9, [sp, #20]
	mov	x10, x9
	ldr	x8, [x8, x10, lsl #3]
	str	x8, [sp, #8]                    ; 8-byte Folded Spill
LBB2_5:                                 ;   in Loop: Header=BB2_1 Depth=1
	ldr	x8, [sp, #8]                    ; 8-byte Folded Reload
	str	x8, [sp, #24]
; %bb.6:                                ;   in Loop: Header=BB2_1 Depth=1
	ldr	w8, [sp, #20]
	add	w8, w8, #1                      ; =1
	str	w8, [sp, #20]
	b	LBB2_1
LBB2_7:
	ldr	x0, [sp, #24]
	add	sp, sp, #48                     ; =48
	ret
	.cfi_endproc
                                        ; -- End function
	.globl	_minld                          ; -- Begin function minld
	.p2align	2
_minld:                                 ; @minld
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #48                     ; =48
	.cfi_def_cfa_offset 48
	str	x0, [sp, #40]
	str	w1, [sp, #36]
	ldr	x8, [sp, #40]
	ldr	x8, [x8]
	str	x8, [sp, #24]
	mov	w9, #1
	str	w9, [sp, #20]
LBB3_1:                                 ; =>This Inner Loop Header: Depth=1
	ldr	w8, [sp, #20]
	ldr	w9, [sp, #36]
	subs	w8, w8, w9
	b.hs	LBB3_7
; %bb.2:                                ;   in Loop: Header=BB3_1 Depth=1
	ldr	x8, [sp, #24]
	ldr	x9, [sp, #40]
	ldr	w10, [sp, #20]
	mov	x11, x10
	ldr	x9, [x9, x11, lsl #3]
	subs	x8, x8, x9
	b.ge	LBB3_4
; %bb.3:                                ;   in Loop: Header=BB3_1 Depth=1
	ldr	x8, [sp, #24]
	str	x8, [sp, #8]                    ; 8-byte Folded Spill
	b	LBB3_5
LBB3_4:                                 ;   in Loop: Header=BB3_1 Depth=1
	ldr	x8, [sp, #40]
	ldr	w9, [sp, #20]
	mov	x10, x9
	ldr	x8, [x8, x10, lsl #3]
	str	x8, [sp, #8]                    ; 8-byte Folded Spill
LBB3_5:                                 ;   in Loop: Header=BB3_1 Depth=1
	ldr	x8, [sp, #8]                    ; 8-byte Folded Reload
	str	x8, [sp, #24]
; %bb.6:                                ;   in Loop: Header=BB3_1 Depth=1
	ldr	w8, [sp, #20]
	add	w8, w8, #1                      ; =1
	str	w8, [sp, #20]
	b	LBB3_1
LBB3_7:
	ldr	x0, [sp, #24]
	add	sp, sp, #48                     ; =48
	ret
	.cfi_endproc
                                        ; -- End function
	.globl	_bes_max_heap                   ; -- Begin function bes_max_heap
	.p2align	2
_bes_max_heap:                          ; @bes_max_heap
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #48                     ; =48
	stp	x29, x30, [sp, #32]             ; 16-byte Folded Spill
	add	x29, sp, #32                    ; =32
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	stur	x0, [x29, #-8]
	stur	w1, [x29, #-12]
	str	w2, [sp, #16]
	str	x3, [sp, #8]
	ldr	w8, [sp, #16]
	lsl	w8, w8, #1
	add	w8, w8, #1                      ; =1
	str	w8, [sp, #4]
	ldr	w8, [sp, #16]
	lsl	w8, w8, #1
	add	w8, w8, #2                      ; =2
	str	w8, [sp]
	ldr	w8, [sp]
	ldur	w9, [x29, #-12]
	subs	w8, w8, w9
	b.hs	LBB4_12
; %bb.1:
	ldur	x8, [x29, #-8]
	ldr	w9, [sp, #16]
	mov	x10, x9
	ldr	x8, [x8, x10, lsl #3]
	ldur	x10, [x29, #-8]
	ldr	w9, [sp, #4]
	mov	x11, x9
	ldr	x10, [x10, x11, lsl #3]
	subs	x8, x8, x10
	b.le	LBB4_4
; %bb.2:
	ldur	x8, [x29, #-8]
	ldr	w9, [sp, #16]
	mov	x10, x9
	ldr	x8, [x8, x10, lsl #3]
	ldur	x10, [x29, #-8]
	ldr	w9, [sp]
	mov	x11, x9
	ldr	x10, [x10, x11, lsl #3]
	subs	x8, x8, x10
	b.le	LBB4_4
; %bb.3:
	b	LBB4_20
LBB4_4:
	ldur	x8, [x29, #-8]
	ldr	w9, [sp, #4]
	mov	x10, x9
	ldr	x8, [x8, x10, lsl #3]
	ldur	x10, [x29, #-8]
	ldr	w9, [sp]
	mov	x11, x9
	ldr	x10, [x10, x11, lsl #3]
	subs	x8, x8, x10
	b.le	LBB4_8
; %bb.5:
	ldur	x8, [x29, #-8]
	ldr	w9, [sp, #16]
	mov	x10, x9
	add	x0, x8, x10, lsl #3
	ldur	x8, [x29, #-8]
	ldr	w9, [sp, #4]
	mov	x10, x9
	add	x1, x8, x10, lsl #3
	bl	_swapld
	ldr	x8, [sp, #8]
	cbz	x8, LBB4_7
; %bb.6:
	ldr	x8, [sp, #8]
	ldr	w9, [sp, #4]
	mov	x10, x9
	add	x0, x8, x10, lsl #2
	ldr	x8, [sp, #8]
	ldr	w9, [sp, #16]
	mov	x10, x9
	add	x1, x8, x10, lsl #2
	bl	_swapu
LBB4_7:
	ldur	x0, [x29, #-8]
	ldur	w1, [x29, #-12]
	ldr	w2, [sp, #4]
	ldr	x3, [sp, #8]
	bl	_bes_max_heap
	b	LBB4_11
LBB4_8:
	ldur	x8, [x29, #-8]
	ldr	w9, [sp, #16]
	mov	x10, x9
	add	x0, x8, x10, lsl #3
	ldur	x8, [x29, #-8]
	ldr	w9, [sp]
	mov	x10, x9
	add	x1, x8, x10, lsl #3
	bl	_swapld
	ldr	x8, [sp, #8]
	cbz	x8, LBB4_10
; %bb.9:
	ldr	x8, [sp, #8]
	ldr	w9, [sp]
	mov	x10, x9
	add	x0, x8, x10, lsl #2
	ldr	x8, [sp, #8]
	ldr	w9, [sp, #16]
	mov	x10, x9
	add	x1, x8, x10, lsl #2
	bl	_swapu
LBB4_10:
	ldur	x0, [x29, #-8]
	ldur	w1, [x29, #-12]
	ldr	w2, [sp]
	ldr	x3, [sp, #8]
	bl	_bes_max_heap
LBB4_11:
	b	LBB4_19
LBB4_12:
	ldr	w8, [sp, #4]
	ldur	w9, [x29, #-12]
	subs	w8, w8, w9
	b.hs	LBB4_18
; %bb.13:
	ldur	x8, [x29, #-8]
	ldr	w9, [sp, #4]
	mov	x10, x9
	ldr	x8, [x8, x10, lsl #3]
	ldur	x10, [x29, #-8]
	ldr	w9, [sp, #16]
	mov	x11, x9
	ldr	x10, [x10, x11, lsl #3]
	subs	x8, x8, x10
	b.le	LBB4_17
; %bb.14:
	ldur	x8, [x29, #-8]
	ldr	w9, [sp, #16]
	mov	x10, x9
	add	x0, x8, x10, lsl #3
	ldur	x8, [x29, #-8]
	ldr	w9, [sp, #4]
	mov	x10, x9
	add	x1, x8, x10, lsl #3
	bl	_swapld
	ldr	x8, [sp, #8]
	cbz	x8, LBB4_16
; %bb.15:
	ldr	x8, [sp, #8]
	ldr	w9, [sp, #4]
	mov	x10, x9
	add	x0, x8, x10, lsl #2
	ldr	x8, [sp, #8]
	ldr	w9, [sp, #16]
	mov	x10, x9
	add	x1, x8, x10, lsl #2
	bl	_swapu
LBB4_16:
LBB4_17:
LBB4_18:
LBB4_19:
LBB4_20:
	ldp	x29, x30, [sp, #32]             ; 16-byte Folded Reload
	add	sp, sp, #48                     ; =48
	ret
	.cfi_endproc
                                        ; -- End function
	.globl	_bes_build_heap                 ; -- Begin function bes_build_heap
	.p2align	2
_bes_build_heap:                        ; @bes_build_heap
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #48                     ; =48
	stp	x29, x30, [sp, #32]             ; 16-byte Folded Spill
	add	x29, sp, #32                    ; =32
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	stur	x0, [x29, #-8]
	stur	w1, [x29, #-12]
	str	x2, [sp, #8]
	ldur	w8, [x29, #-12]
	lsr	w8, w8, #1
	str	w8, [sp, #4]
LBB5_1:                                 ; =>This Inner Loop Header: Depth=1
	ldr	w8, [sp, #4]
	mov	x9, x8
	mov	x10, #4294967295
	subs	x9, x9, x10
	b.eq	LBB5_4
; %bb.2:                                ;   in Loop: Header=BB5_1 Depth=1
	ldur	x0, [x29, #-8]
	ldur	w1, [x29, #-12]
	ldr	w2, [sp, #4]
	ldr	x3, [sp, #8]
	bl	_bes_max_heap
; %bb.3:                                ;   in Loop: Header=BB5_1 Depth=1
	ldr	w8, [sp, #4]
	subs	w8, w8, #1                      ; =1
	str	w8, [sp, #4]
	b	LBB5_1
LBB5_4:
	ldp	x29, x30, [sp, #32]             ; 16-byte Folded Reload
	add	sp, sp, #48                     ; =48
	ret
	.cfi_endproc
                                        ; -- End function
	.globl	_lambda__bes_quicksort0         ; -- Begin function lambda__bes_quicksort0
	.p2align	2
_lambda__bes_quicksort0:                ; @lambda__bes_quicksort0
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #48                     ; =48
	stp	x29, x30, [sp, #32]             ; 16-byte Folded Spill
	add	x29, sp, #32                    ; =32
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	stur	x0, [x29, #-8]
	stur	w1, [x29, #-12]
	str	x2, [sp, #8]
	ldur	w8, [x29, #-12]
	cmp	w8, #1                          ; =1
	b.hi	LBB6_2
; %bb.1:
	b	LBB6_11
LBB6_2:
	str	wzr, [sp, #4]
	str	wzr, [sp]
LBB6_3:                                 ; =>This Inner Loop Header: Depth=1
	ldr	w8, [sp]
	ldur	w9, [x29, #-12]
	subs	w9, w9, #1                      ; =1
	subs	w8, w8, w9
	b.hs	LBB6_10
; %bb.4:                                ;   in Loop: Header=BB6_3 Depth=1
	ldur	x8, [x29, #-8]
	ldr	w9, [sp]
	mov	x10, x9
	ldr	x8, [x8, x10, lsl #3]
	ldur	x10, [x29, #-8]
	ldur	w9, [x29, #-12]
	subs	w9, w9, #1                      ; =1
	ldr	x10, [x10, w9, uxtw #3]
	subs	x8, x8, x10
	b.ge	LBB6_8
; %bb.5:                                ;   in Loop: Header=BB6_3 Depth=1
	ldur	x8, [x29, #-8]
	ldr	w9, [sp]
	mov	x10, x9
	add	x0, x8, x10, lsl #3
	ldur	x8, [x29, #-8]
	ldr	w9, [sp, #4]
	mov	x10, x9
	add	x1, x8, x10, lsl #3
	bl	_swapld
	ldr	x8, [sp, #8]
	cbz	x8, LBB6_7
; %bb.6:                                ;   in Loop: Header=BB6_3 Depth=1
	ldr	x8, [sp, #8]
	ldr	w9, [sp]
	mov	x10, x9
	add	x0, x8, x10, lsl #2
	ldr	x8, [sp, #8]
	ldr	w9, [sp, #4]
	mov	x10, x9
	add	x1, x8, x10, lsl #2
	bl	_swapu
LBB6_7:                                 ;   in Loop: Header=BB6_3 Depth=1
	ldr	w8, [sp, #4]
	add	w8, w8, #1                      ; =1
	str	w8, [sp, #4]
LBB6_8:                                 ;   in Loop: Header=BB6_3 Depth=1
; %bb.9:                                ;   in Loop: Header=BB6_3 Depth=1
	ldr	w8, [sp]
	add	w8, w8, #1                      ; =1
	str	w8, [sp]
	b	LBB6_3
LBB6_10:
	ldur	x0, [x29, #-8]
	ldr	w1, [sp, #4]
	ldr	x2, [sp, #8]
	bl	_lambda__bes_quicksort0
	ldur	x8, [x29, #-8]
	ldr	w9, [sp, #4]
	mov	x10, x9
	add	x0, x8, x10, lsl #3
	ldur	w9, [x29, #-12]
	ldr	w11, [sp, #4]
	subs	w9, w9, w11
	subs	w1, w9, #1                      ; =1
	ldr	x8, [sp, #8]
	ldr	w9, [sp, #4]
	mov	x10, x9
	add	x2, x8, x10, lsl #2
	bl	_lambda__bes_quicksort0
LBB6_11:
	ldp	x29, x30, [sp, #32]             ; 16-byte Folded Reload
	add	sp, sp, #48                     ; =48
	ret
	.cfi_endproc
                                        ; -- End function
	.globl	_bes_quicksort                  ; -- Begin function bes_quicksort
	.p2align	2
_bes_quicksort:                         ; @bes_quicksort
	.cfi_startproc
; %bb.0:
	stp	x29, x30, [sp, #-16]!           ; 16-byte Folded Spill
	mov	x29, sp
	sub	sp, sp, #96                     ; =96
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	adrp	x8, ___stack_chk_guard@GOTPAGE
	ldr	x8, [x8, ___stack_chk_guard@GOTPAGEOFF]
	ldr	x8, [x8]
	stur	x8, [x29, #-8]
	stur	x0, [x29, #-16]
	stur	w1, [x29, #-20]
	ldur	w9, [x29, #-20]
	mov	x8, x9
	mov	x10, #4
	mul	x0, x10, x8
	bl	_malloc
	stur	x0, [x29, #-32]
	ldur	w9, [x29, #-20]
	mov	x8, x9
	mov	x10, sp
	stur	x10, [x29, #-40]
	lsl	x10, x8, #3
	add	x10, x10, #15                   ; =15
	and	x10, x10, #0xfffffffffffffff0
	mov	x9, x10
	stur	x8, [x29, #-64]                 ; 8-byte Folded Spill
	stur	x10, [x29, #-72]                ; 8-byte Folded Spill
	adrp	x16, ___chkstk_darwin@GOTPAGE
	ldr	x16, [x16, ___chkstk_darwin@GOTPAGEOFF]
	blr	x16
	mov	x8, sp
	ldur	x9, [x29, #-72]                 ; 8-byte Folded Reload
	subs	x8, x8, x9
	mov	sp, x8
	ldur	x10, [x29, #-64]                ; 8-byte Folded Reload
	stur	x10, [x29, #-48]
	stur	wzr, [x29, #-52]
	stur	x8, [x29, #-80]                 ; 8-byte Folded Spill
LBB7_1:                                 ; =>This Inner Loop Header: Depth=1
	ldur	w8, [x29, #-52]
	ldur	w9, [x29, #-20]
	subs	w8, w8, w9
	b.hs	LBB7_4
; %bb.2:                                ;   in Loop: Header=BB7_1 Depth=1
	ldur	x8, [x29, #-16]
	ldur	w9, [x29, #-52]
	mov	x10, x9
	ldr	x8, [x8, x10, lsl #3]
	ldur	w9, [x29, #-52]
	mov	x10, x9
	ldur	x11, [x29, #-80]                ; 8-byte Folded Reload
	str	x8, [x11, x10, lsl #3]
; %bb.3:                                ;   in Loop: Header=BB7_1 Depth=1
	ldur	w8, [x29, #-52]
	add	w8, w8, #1                      ; =1
	stur	w8, [x29, #-52]
	b	LBB7_1
LBB7_4:
	stur	wzr, [x29, #-56]
LBB7_5:                                 ; =>This Inner Loop Header: Depth=1
	ldur	w8, [x29, #-56]
	ldur	w9, [x29, #-20]
	subs	w8, w8, w9
	b.hs	LBB7_8
; %bb.6:                                ;   in Loop: Header=BB7_5 Depth=1
	ldur	w8, [x29, #-56]
	ldur	x9, [x29, #-32]
	ldur	w10, [x29, #-56]
	mov	x11, x10
	str	w8, [x9, x11, lsl #2]
; %bb.7:                                ;   in Loop: Header=BB7_5 Depth=1
	ldur	w8, [x29, #-56]
	add	w8, w8, #1                      ; =1
	stur	w8, [x29, #-56]
	b	LBB7_5
LBB7_8:
	ldur	w1, [x29, #-20]
	ldur	x2, [x29, #-32]
	ldur	x0, [x29, #-80]                 ; 8-byte Folded Reload
	bl	_lambda__bes_quicksort0
	ldur	x0, [x29, #-32]
	ldur	x8, [x29, #-40]
	mov	sp, x8
	adrp	x8, ___stack_chk_guard@GOTPAGE
	ldr	x8, [x8, ___stack_chk_guard@GOTPAGEOFF]
	ldr	x8, [x8]
	ldur	x9, [x29, #-8]
	subs	x8, x8, x9
	stur	x0, [x29, #-88]                 ; 8-byte Folded Spill
	b.ne	LBB7_10
; %bb.9:
	ldur	x0, [x29, #-88]                 ; 8-byte Folded Reload
	mov	sp, x29
	ldp	x29, x30, [sp], #16             ; 16-byte Folded Reload
	ret
LBB7_10:
	bl	___stack_chk_fail
	.cfi_endproc
                                        ; -- End function
	.globl	_lambda__bes_heap_sort0         ; -- Begin function lambda__bes_heap_sort0
	.p2align	2
_lambda__bes_heap_sort0:                ; @lambda__bes_heap_sort0
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #48                     ; =48
	stp	x29, x30, [sp, #32]             ; 16-byte Folded Spill
	add	x29, sp, #32                    ; =32
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	stur	x0, [x29, #-8]
	stur	w1, [x29, #-12]
	str	x2, [sp, #8]
	ldur	w8, [x29, #-12]
	subs	w8, w8, #1                      ; =1
	str	w8, [sp, #4]
LBB8_1:                                 ; =>This Inner Loop Header: Depth=1
	ldr	w8, [sp, #4]
	mov	x9, x8
	mov	x10, #4294967295
	subs	x9, x9, x10
	b.eq	LBB8_6
; %bb.2:                                ;   in Loop: Header=BB8_1 Depth=1
	ldur	x0, [x29, #-8]
	ldur	x8, [x29, #-8]
	ldr	w9, [sp, #4]
	mov	x10, x9
	add	x1, x8, x10, lsl #3
	bl	_swapld
	ldr	x8, [sp, #8]
	cbz	x8, LBB8_4
; %bb.3:                                ;   in Loop: Header=BB8_1 Depth=1
	ldr	x0, [sp, #8]
	ldr	x8, [sp, #8]
	ldr	w9, [sp, #4]
	mov	x10, x9
	add	x1, x8, x10, lsl #2
	bl	_swapu
LBB8_4:                                 ;   in Loop: Header=BB8_1 Depth=1
	ldur	x0, [x29, #-8]
	ldr	w1, [sp, #4]
	ldr	x3, [sp, #8]
	mov	w8, #0
	mov	x2, x8
	bl	_bes_max_heap
; %bb.5:                                ;   in Loop: Header=BB8_1 Depth=1
	ldr	w8, [sp, #4]
	subs	w8, w8, #1                      ; =1
	str	w8, [sp, #4]
	b	LBB8_1
LBB8_6:
	ldp	x29, x30, [sp, #32]             ; 16-byte Folded Reload
	add	sp, sp, #48                     ; =48
	ret
	.cfi_endproc
                                        ; -- End function
	.globl	_bes_heapsort                   ; -- Begin function bes_heapsort
	.p2align	2
_bes_heapsort:                          ; @bes_heapsort
	.cfi_startproc
; %bb.0:
	stp	x29, x30, [sp, #-16]!           ; 16-byte Folded Spill
	mov	x29, sp
	sub	sp, sp, #96                     ; =96
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	adrp	x8, ___stack_chk_guard@GOTPAGE
	ldr	x8, [x8, ___stack_chk_guard@GOTPAGEOFF]
	ldr	x8, [x8]
	stur	x8, [x29, #-8]
	stur	x0, [x29, #-16]
	stur	w1, [x29, #-20]
	ldur	w9, [x29, #-20]
	mov	x8, x9
	lsl	x0, x8, #2
	bl	_malloc
	stur	x0, [x29, #-32]
	ldur	w9, [x29, #-20]
	mov	x8, x9
	mov	x10, sp
	stur	x10, [x29, #-40]
	lsl	x10, x8, #3
	add	x10, x10, #15                   ; =15
	and	x10, x10, #0xfffffffffffffff0
	mov	x9, x10
	stur	x8, [x29, #-64]                 ; 8-byte Folded Spill
	stur	x10, [x29, #-72]                ; 8-byte Folded Spill
	adrp	x16, ___chkstk_darwin@GOTPAGE
	ldr	x16, [x16, ___chkstk_darwin@GOTPAGEOFF]
	blr	x16
	mov	x8, sp
	ldur	x9, [x29, #-72]                 ; 8-byte Folded Reload
	subs	x8, x8, x9
	mov	sp, x8
	ldur	x10, [x29, #-64]                ; 8-byte Folded Reload
	stur	x10, [x29, #-48]
	stur	wzr, [x29, #-52]
	stur	x8, [x29, #-80]                 ; 8-byte Folded Spill
LBB9_1:                                 ; =>This Inner Loop Header: Depth=1
	ldur	w8, [x29, #-52]
	ldur	w9, [x29, #-20]
	subs	w8, w8, w9
	b.hs	LBB9_4
; %bb.2:                                ;   in Loop: Header=BB9_1 Depth=1
	ldur	x8, [x29, #-16]
	ldur	w9, [x29, #-52]
	mov	x10, x9
	ldr	x8, [x8, x10, lsl #3]
	ldur	w9, [x29, #-52]
	mov	x10, x9
	ldur	x11, [x29, #-80]                ; 8-byte Folded Reload
	str	x8, [x11, x10, lsl #3]
; %bb.3:                                ;   in Loop: Header=BB9_1 Depth=1
	ldur	w8, [x29, #-52]
	add	w8, w8, #1                      ; =1
	stur	w8, [x29, #-52]
	b	LBB9_1
LBB9_4:
	stur	wzr, [x29, #-56]
LBB9_5:                                 ; =>This Inner Loop Header: Depth=1
	ldur	w8, [x29, #-56]
	ldur	w9, [x29, #-20]
	subs	w8, w8, w9
	b.hs	LBB9_8
; %bb.6:                                ;   in Loop: Header=BB9_5 Depth=1
	ldur	w8, [x29, #-56]
	ldur	x9, [x29, #-32]
	ldur	w10, [x29, #-56]
	mov	x11, x10
	str	w8, [x9, x11, lsl #2]
; %bb.7:                                ;   in Loop: Header=BB9_5 Depth=1
	ldur	w8, [x29, #-56]
	add	w8, w8, #1                      ; =1
	stur	w8, [x29, #-56]
	b	LBB9_5
LBB9_8:
	ldur	w1, [x29, #-20]
	ldur	x2, [x29, #-32]
	ldur	x0, [x29, #-80]                 ; 8-byte Folded Reload
	bl	_lambda__bes_heap_sort0
	ldur	x0, [x29, #-32]
	ldur	x8, [x29, #-40]
	mov	sp, x8
	adrp	x8, ___stack_chk_guard@GOTPAGE
	ldr	x8, [x8, ___stack_chk_guard@GOTPAGEOFF]
	ldr	x8, [x8]
	ldur	x9, [x29, #-8]
	subs	x8, x8, x9
	stur	x0, [x29, #-88]                 ; 8-byte Folded Spill
	b.ne	LBB9_10
; %bb.9:
	ldur	x0, [x29, #-88]                 ; 8-byte Folded Reload
	mov	sp, x29
	ldp	x29, x30, [sp], #16             ; 16-byte Folded Reload
	ret
LBB9_10:
	bl	___stack_chk_fail
	.cfi_endproc
                                        ; -- End function
	.globl	_lambda__bes_bits_sort          ; -- Begin function lambda__bes_bits_sort
	.p2align	2
_lambda__bes_bits_sort:                 ; @lambda__bes_bits_sort
	.cfi_startproc
; %bb.0:
	stp	x29, x30, [sp, #-16]!           ; 16-byte Folded Spill
	mov	x29, sp
	sub	sp, sp, #144                    ; =144
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	adrp	x8, ___stack_chk_guard@GOTPAGE
	ldr	x8, [x8, ___stack_chk_guard@GOTPAGEOFF]
	ldr	x8, [x8]
	stur	x8, [x29, #-8]
	stur	x0, [x29, #-16]
	stur	w1, [x29, #-20]
	stur	x2, [x29, #-32]
	ldur	w9, [x29, #-20]
	mov	x8, x9
	mov	x10, sp
	stur	x10, [x29, #-40]
	lsl	x10, x8, #2
	add	x10, x10, #15                   ; =15
	and	x10, x10, #0xfffffffffffffff0
	mov	x9, x10
	stur	x8, [x29, #-104]                ; 8-byte Folded Spill
	stur	x10, [x29, #-112]               ; 8-byte Folded Spill
	adrp	x16, ___chkstk_darwin@GOTPAGE
	ldr	x16, [x16, ___chkstk_darwin@GOTPAGEOFF]
	blr	x16
	mov	x8, sp
	ldur	x9, [x29, #-112]                ; 8-byte Folded Reload
	subs	x8, x8, x9
	mov	sp, x8
	ldur	x10, [x29, #-104]               ; 8-byte Folded Reload
	stur	x10, [x29, #-48]
	ldur	w11, [x29, #-20]
	mov	x12, x11
	lsl	x13, x12, #2
	add	x13, x13, #15                   ; =15
	and	x13, x13, #0xfffffffffffffff0
	mov	x9, x13
	stur	x8, [x29, #-120]                ; 8-byte Folded Spill
	stur	x12, [x29, #-128]               ; 8-byte Folded Spill
	stur	x13, [x29, #-136]               ; 8-byte Folded Spill
	adrp	x16, ___chkstk_darwin@GOTPAGE
	ldr	x16, [x16, ___chkstk_darwin@GOTPAGEOFF]
	blr	x16
	mov	x8, sp
	ldur	x9, [x29, #-136]                ; 8-byte Folded Reload
	subs	x8, x8, x9
	mov	sp, x8
	ldur	x10, [x29, #-128]               ; 8-byte Folded Reload
	stur	x10, [x29, #-56]
	stur	wzr, [x29, #-60]
	stur	wzr, [x29, #-64]
	mov	w11, #1
	stur	w11, [x29, #-68]
	stur	x8, [x29, #-144]                ; 8-byte Folded Spill
LBB10_1:                                ; =>This Loop Header: Depth=1
                                        ;     Child Loop BB10_3 Depth 2
                                        ;     Child Loop BB10_10 Depth 2
                                        ;     Child Loop BB10_14 Depth 2
	ldur	w8, [x29, #-68]
	mov	w9, #-2147483648
	subs	w8, w8, w9
	b.eq	LBB10_19
; %bb.2:                                ;   in Loop: Header=BB10_1 Depth=1
	stur	wzr, [x29, #-60]
	stur	wzr, [x29, #-64]
	stur	wzr, [x29, #-72]
LBB10_3:                                ;   Parent Loop BB10_1 Depth=1
                                        ; =>  This Inner Loop Header: Depth=2
	ldur	w8, [x29, #-72]
	ldur	w9, [x29, #-20]
	subs	w8, w8, w9
	b.hs	LBB10_9
; %bb.4:                                ;   in Loop: Header=BB10_3 Depth=2
	ldur	x8, [x29, #-16]
	ldur	x9, [x29, #-32]
	ldur	w10, [x29, #-72]
	mov	x11, x10
	ldr	w10, [x9, x11, lsl #2]
	mov	x9, x10
	ldr	x8, [x8, x9, lsl #3]
	ldur	w10, [x29, #-68]
	mov	x9, x10
	and	x8, x8, x9
	cbz	x8, LBB10_6
; %bb.5:                                ;   in Loop: Header=BB10_3 Depth=2
	ldur	x8, [x29, #-32]
	ldur	w9, [x29, #-72]
	mov	x10, x9
	ldr	w9, [x8, x10, lsl #2]
	ldur	w11, [x29, #-64]
	mov	x8, x11
	mov	x11, x8
	add	w11, w11, #1                    ; =1
	stur	w11, [x29, #-64]
	ldur	x10, [x29, #-144]               ; 8-byte Folded Reload
	str	w9, [x10, x8, lsl #2]
	b	LBB10_7
LBB10_6:                                ;   in Loop: Header=BB10_3 Depth=2
	ldur	x8, [x29, #-32]
	ldur	w9, [x29, #-72]
	mov	x10, x9
	ldr	w9, [x8, x10, lsl #2]
	ldur	w11, [x29, #-60]
	mov	x8, x11
	mov	x11, x8
	add	w11, w11, #1                    ; =1
	stur	w11, [x29, #-60]
	ldur	x10, [x29, #-120]               ; 8-byte Folded Reload
	str	w9, [x10, x8, lsl #2]
LBB10_7:                                ;   in Loop: Header=BB10_3 Depth=2
; %bb.8:                                ;   in Loop: Header=BB10_3 Depth=2
	ldur	w8, [x29, #-72]
	add	w8, w8, #1                      ; =1
	stur	w8, [x29, #-72]
	b	LBB10_3
LBB10_9:                                ;   in Loop: Header=BB10_1 Depth=1
	stur	wzr, [x29, #-76]
LBB10_10:                               ;   Parent Loop BB10_1 Depth=1
                                        ; =>  This Inner Loop Header: Depth=2
	ldur	w8, [x29, #-76]
	ldur	w9, [x29, #-60]
	subs	w8, w8, w9
	b.hs	LBB10_13
; %bb.11:                               ;   in Loop: Header=BB10_10 Depth=2
	ldur	w8, [x29, #-76]
	mov	x9, x8
	ldur	x10, [x29, #-120]               ; 8-byte Folded Reload
	ldr	w8, [x10, x9, lsl #2]
	ldur	x9, [x29, #-32]
	ldur	w11, [x29, #-76]
	mov	x12, x11
	str	w8, [x9, x12, lsl #2]
; %bb.12:                               ;   in Loop: Header=BB10_10 Depth=2
	ldur	w8, [x29, #-76]
	add	w8, w8, #1                      ; =1
	stur	w8, [x29, #-76]
	b	LBB10_10
LBB10_13:                               ;   in Loop: Header=BB10_1 Depth=1
	stur	wzr, [x29, #-80]
LBB10_14:                               ;   Parent Loop BB10_1 Depth=1
                                        ; =>  This Inner Loop Header: Depth=2
	ldur	w8, [x29, #-80]
	ldur	w9, [x29, #-64]
	subs	w8, w8, w9
	b.hs	LBB10_17
; %bb.15:                               ;   in Loop: Header=BB10_14 Depth=2
	ldur	w8, [x29, #-80]
	mov	x9, x8
	ldur	x10, [x29, #-144]               ; 8-byte Folded Reload
	ldr	w8, [x10, x9, lsl #2]
	ldur	x9, [x29, #-32]
	ldur	w11, [x29, #-60]
	ldur	w12, [x29, #-80]
	add	w11, w11, w12
	str	w8, [x9, w11, uxtw #2]
; %bb.16:                               ;   in Loop: Header=BB10_14 Depth=2
	ldur	w8, [x29, #-80]
	add	w8, w8, #1                      ; =1
	stur	w8, [x29, #-80]
	b	LBB10_14
LBB10_17:                               ;   in Loop: Header=BB10_1 Depth=1
; %bb.18:                               ;   in Loop: Header=BB10_1 Depth=1
	ldur	w8, [x29, #-68]
	lsl	w8, w8, #1
	stur	w8, [x29, #-68]
	b	LBB10_1
LBB10_19:
	stur	wzr, [x29, #-64]
	stur	wzr, [x29, #-60]
	stur	wzr, [x29, #-84]
LBB10_20:                               ; =>This Inner Loop Header: Depth=1
	ldur	w8, [x29, #-84]
	ldur	w9, [x29, #-20]
	subs	w8, w8, w9
	b.hs	LBB10_26
; %bb.21:                               ;   in Loop: Header=BB10_20 Depth=1
	ldur	x8, [x29, #-16]
	ldur	x9, [x29, #-32]
	ldur	w10, [x29, #-84]
	mov	x11, x10
	ldr	w10, [x9, x11, lsl #2]
	mov	x9, x10
	ldr	x8, [x8, x9, lsl #3]
	cmp	x8, #0                          ; =0
	cset	w10, le
	tbnz	w10, #0, LBB10_23
; %bb.22:                               ;   in Loop: Header=BB10_20 Depth=1
	ldur	x8, [x29, #-32]
	ldur	w9, [x29, #-84]
	mov	x10, x9
	ldr	w9, [x8, x10, lsl #2]
	ldur	w11, [x29, #-64]
	mov	x8, x11
	mov	x11, x8
	add	w11, w11, #1                    ; =1
	stur	w11, [x29, #-64]
	ldur	x10, [x29, #-144]               ; 8-byte Folded Reload
	str	w9, [x10, x8, lsl #2]
	b	LBB10_24
LBB10_23:                               ;   in Loop: Header=BB10_20 Depth=1
	ldur	x8, [x29, #-32]
	ldur	w9, [x29, #-84]
	mov	x10, x9
	ldr	w9, [x8, x10, lsl #2]
	ldur	w11, [x29, #-60]
	mov	x8, x11
	mov	x11, x8
	add	w11, w11, #1                    ; =1
	stur	w11, [x29, #-60]
	ldur	x10, [x29, #-120]               ; 8-byte Folded Reload
	str	w9, [x10, x8, lsl #2]
LBB10_24:                               ;   in Loop: Header=BB10_20 Depth=1
; %bb.25:                               ;   in Loop: Header=BB10_20 Depth=1
	ldur	w8, [x29, #-84]
	add	w8, w8, #1                      ; =1
	stur	w8, [x29, #-84]
	b	LBB10_20
LBB10_26:
	stur	wzr, [x29, #-88]
LBB10_27:                               ; =>This Inner Loop Header: Depth=1
	ldur	w8, [x29, #-88]
	ldur	w9, [x29, #-60]
	subs	w8, w8, w9
	b.hs	LBB10_30
; %bb.28:                               ;   in Loop: Header=BB10_27 Depth=1
	ldur	w8, [x29, #-88]
	mov	x9, x8
	ldur	x10, [x29, #-120]               ; 8-byte Folded Reload
	ldr	w8, [x10, x9, lsl #2]
	ldur	x9, [x29, #-32]
	ldur	w11, [x29, #-88]
	mov	x12, x11
	str	w8, [x9, x12, lsl #2]
; %bb.29:                               ;   in Loop: Header=BB10_27 Depth=1
	ldur	w8, [x29, #-88]
	add	w8, w8, #1                      ; =1
	stur	w8, [x29, #-88]
	b	LBB10_27
LBB10_30:
	stur	wzr, [x29, #-92]
LBB10_31:                               ; =>This Inner Loop Header: Depth=1
	ldur	w8, [x29, #-92]
	ldur	w9, [x29, #-64]
	subs	w8, w8, w9
	b.hs	LBB10_34
; %bb.32:                               ;   in Loop: Header=BB10_31 Depth=1
	ldur	w8, [x29, #-92]
	mov	x9, x8
	ldur	x10, [x29, #-144]               ; 8-byte Folded Reload
	ldr	w8, [x10, x9, lsl #2]
	ldur	x9, [x29, #-32]
	ldur	w11, [x29, #-60]
	ldur	w12, [x29, #-92]
	add	w11, w11, w12
	str	w8, [x9, w11, uxtw #2]
; %bb.33:                               ;   in Loop: Header=BB10_31 Depth=1
	ldur	w8, [x29, #-92]
	add	w8, w8, #1                      ; =1
	stur	w8, [x29, #-92]
	b	LBB10_31
LBB10_34:
	ldur	x8, [x29, #-40]
	mov	sp, x8
	adrp	x8, ___stack_chk_guard@GOTPAGE
	ldr	x8, [x8, ___stack_chk_guard@GOTPAGEOFF]
	ldr	x8, [x8]
	ldur	x9, [x29, #-8]
	subs	x8, x8, x9
	b.ne	LBB10_36
; %bb.35:
	mov	sp, x29
	ldp	x29, x30, [sp], #16             ; 16-byte Folded Reload
	ret
LBB10_36:
	bl	___stack_chk_fail
	.cfi_endproc
                                        ; -- End function
	.globl	_bes_bits_sort                  ; -- Begin function bes_bits_sort
	.p2align	2
_bes_bits_sort:                         ; @bes_bits_sort
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #48                     ; =48
	stp	x29, x30, [sp, #32]             ; 16-byte Folded Spill
	add	x29, sp, #32                    ; =32
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	stur	x0, [x29, #-8]
	stur	w1, [x29, #-12]
	ldur	w8, [x29, #-12]
	mov	x9, x8
	mov	x10, #4
	mul	x0, x10, x9
	bl	_malloc
	str	x0, [sp, #8]
	str	wzr, [sp, #4]
LBB11_1:                                ; =>This Inner Loop Header: Depth=1
	ldr	w8, [sp, #4]
	ldur	w9, [x29, #-12]
	subs	w8, w8, w9
	b.hs	LBB11_4
; %bb.2:                                ;   in Loop: Header=BB11_1 Depth=1
	ldr	w8, [sp, #4]
	ldr	x9, [sp, #8]
	ldr	w10, [sp, #4]
	mov	x11, x10
	str	w8, [x9, x11, lsl #2]
; %bb.3:                                ;   in Loop: Header=BB11_1 Depth=1
	ldr	w8, [sp, #4]
	add	w8, w8, #1                      ; =1
	str	w8, [sp, #4]
	b	LBB11_1
LBB11_4:
	ldur	x0, [x29, #-8]
	ldur	w1, [x29, #-12]
	ldr	x2, [sp, #8]
	bl	_lambda__bes_bits_sort
	ldr	x0, [sp, #8]
	ldp	x29, x30, [sp, #32]             ; 16-byte Folded Reload
	add	sp, sp, #48                     ; =48
	ret
	.cfi_endproc
                                        ; -- End function
	.globl	_lambda__bucket_sort0           ; -- Begin function lambda__bucket_sort0
	.p2align	2
_lambda__bucket_sort0:                  ; @lambda__bucket_sort0
	.cfi_startproc
; %bb.0:
	stp	x29, x30, [sp, #-16]!           ; 16-byte Folded Spill
	mov	x29, sp
	sub	sp, sp, #192                    ; =192
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	adrp	x8, ___stack_chk_guard@GOTPAGE
	ldr	x8, [x8, ___stack_chk_guard@GOTPAGEOFF]
	ldr	x8, [x8]
	stur	x8, [x29, #-8]
	stur	x0, [x29, #-16]
	stur	w1, [x29, #-20]
	stur	x2, [x29, #-32]
	ldur	x0, [x29, #-16]
	ldur	w1, [x29, #-20]
	bl	_maxld
	stur	x0, [x29, #-40]
	ldur	x0, [x29, #-16]
	ldur	w1, [x29, #-20]
	bl	_minld
	stur	x0, [x29, #-48]
	ldur	w9, [x29, #-20]
	mov	x8, x9
	mov	x10, sp
	stur	x10, [x29, #-56]
	lsl	x10, x8, #3
	add	x10, x10, #15                   ; =15
	and	x10, x10, #0xfffffffffffffff0
	mov	x9, x10
	stur	x8, [x29, #-120]                ; 8-byte Folded Spill
	stur	x10, [x29, #-128]               ; 8-byte Folded Spill
	adrp	x16, ___chkstk_darwin@GOTPAGE
	ldr	x16, [x16, ___chkstk_darwin@GOTPAGEOFF]
	blr	x16
	mov	x8, sp
	ldur	x9, [x29, #-128]                ; 8-byte Folded Reload
	subs	x8, x8, x9
	mov	sp, x8
	ldur	x10, [x29, #-120]               ; 8-byte Folded Reload
	stur	x10, [x29, #-64]
	ldur	w11, [x29, #-20]
	mov	x12, x11
	lsl	x13, x12, #3
	add	x13, x13, #15                   ; =15
	and	x13, x13, #0xfffffffffffffff0
	mov	x9, x13
	stur	x8, [x29, #-136]                ; 8-byte Folded Spill
	stur	x12, [x29, #-144]               ; 8-byte Folded Spill
	stur	x13, [x29, #-152]               ; 8-byte Folded Spill
	adrp	x16, ___chkstk_darwin@GOTPAGE
	ldr	x16, [x16, ___chkstk_darwin@GOTPAGEOFF]
	blr	x16
	mov	x8, sp
	ldur	x9, [x29, #-152]                ; 8-byte Folded Reload
	subs	x8, x8, x9
	mov	sp, x8
	ldur	x10, [x29, #-144]               ; 8-byte Folded Reload
	stur	x10, [x29, #-72]
	ldur	w11, [x29, #-20]
	mov	x12, x11
	lsl	x13, x12, #2
	add	x13, x13, #15                   ; =15
	and	x13, x13, #0xfffffffffffffff0
	mov	x9, x13
	stur	x8, [x29, #-160]                ; 8-byte Folded Spill
	stur	x12, [x29, #-168]               ; 8-byte Folded Spill
	stur	x13, [x29, #-176]               ; 8-byte Folded Spill
	adrp	x16, ___chkstk_darwin@GOTPAGE
	ldr	x16, [x16, ___chkstk_darwin@GOTPAGEOFF]
	blr	x16
	mov	x8, sp
	ldur	x9, [x29, #-176]                ; 8-byte Folded Reload
	subs	x8, x8, x9
	mov	sp, x8
	ldur	x10, [x29, #-168]               ; 8-byte Folded Reload
	stur	x10, [x29, #-80]
	stur	wzr, [x29, #-84]
	stur	x8, [x29, #-184]                ; 8-byte Folded Spill
LBB12_1:                                ; =>This Inner Loop Header: Depth=1
	ldur	w8, [x29, #-84]
	ldur	w9, [x29, #-20]
	subs	w8, w8, w9
	b.hs	LBB12_4
; %bb.2:                                ;   in Loop: Header=BB12_1 Depth=1
	ldur	w8, [x29, #-84]
	mov	x9, x8
	mov	x10, #0
	ldur	x11, [x29, #-160]               ; 8-byte Folded Reload
	str	x10, [x11, x9, lsl #3]
; %bb.3:                                ;   in Loop: Header=BB12_1 Depth=1
	ldur	w8, [x29, #-84]
	add	w8, w8, #1                      ; =1
	stur	w8, [x29, #-84]
	b	LBB12_1
LBB12_4:
	stur	wzr, [x29, #-88]
LBB12_5:                                ; =>This Inner Loop Header: Depth=1
	ldur	w8, [x29, #-88]
	ldur	w9, [x29, #-20]
	subs	w8, w8, w9
	b.hs	LBB12_8
; %bb.6:                                ;   in Loop: Header=BB12_5 Depth=1
	ldur	x8, [x29, #-16]
	ldur	w9, [x29, #-88]
	mov	x10, x9
	ldr	x8, [x8, x10, lsl #3]
	ldur	x10, [x29, #-48]
	subs	x8, x8, x10
	ldur	w9, [x29, #-20]
	mov	x10, x9
	mul	x8, x8, x10
	ldur	x10, [x29, #-40]
	ldur	x11, [x29, #-48]
	subs	x10, x10, x11
	add	x10, x10, #1                    ; =1
	sdiv	x8, x8, x10
	ldur	x10, [x29, #-160]               ; 8-byte Folded Reload
	add	x8, x10, x8, lsl #3
	ldr	x10, [x8]
	add	x10, x10, #1                    ; =1
	str	x10, [x8]
; %bb.7:                                ;   in Loop: Header=BB12_5 Depth=1
	ldur	w8, [x29, #-88]
	add	w8, w8, #1                      ; =1
	stur	w8, [x29, #-88]
	b	LBB12_5
LBB12_8:
	ldur	x8, [x29, #-136]                ; 8-byte Folded Reload
	str	xzr, [x8]
	mov	w9, #1
	stur	w9, [x29, #-92]
LBB12_9:                                ; =>This Inner Loop Header: Depth=1
	ldur	w8, [x29, #-92]
	ldur	w9, [x29, #-20]
	subs	w8, w8, w9
	b.hs	LBB12_12
; %bb.10:                               ;   in Loop: Header=BB12_9 Depth=1
	ldur	w8, [x29, #-92]
	subs	w8, w8, #1                      ; =1
	ldur	x9, [x29, #-160]                ; 8-byte Folded Reload
	ldr	x10, [x9, w8, uxtw #3]
	ldur	w8, [x29, #-92]
	subs	w8, w8, #1                      ; =1
	ldur	x11, [x29, #-136]               ; 8-byte Folded Reload
	ldr	x12, [x11, w8, uxtw #3]
	add	x10, x10, x12
	ldur	w8, [x29, #-92]
	mov	x12, x8
	str	x10, [x11, x12, lsl #3]
; %bb.11:                               ;   in Loop: Header=BB12_9 Depth=1
	ldur	w8, [x29, #-92]
	add	w8, w8, #1                      ; =1
	stur	w8, [x29, #-92]
	b	LBB12_9
LBB12_12:
	stur	wzr, [x29, #-96]
LBB12_13:                               ; =>This Inner Loop Header: Depth=1
	ldur	w8, [x29, #-96]
	ldur	w9, [x29, #-20]
	subs	w8, w8, w9
	b.hs	LBB12_18
; %bb.14:                               ;   in Loop: Header=BB12_13 Depth=1
	ldur	x8, [x29, #-32]
	cbz	x8, LBB12_16
; %bb.15:                               ;   in Loop: Header=BB12_13 Depth=1
	ldur	x8, [x29, #-32]
	ldur	w9, [x29, #-96]
	mov	x10, x9
	ldr	w9, [x8, x10, lsl #2]
	ldur	x8, [x29, #-16]
	ldur	w11, [x29, #-96]
	mov	x10, x11
	ldr	x8, [x8, x10, lsl #3]
	ldur	x10, [x29, #-48]
	subs	x8, x8, x10
	ldur	w11, [x29, #-20]
	mov	x10, x11
	mul	x8, x8, x10
	ldur	x10, [x29, #-40]
	ldur	x12, [x29, #-48]
	subs	x10, x10, x12
	add	x10, x10, #1                    ; =1
	sdiv	x8, x8, x10
	ldur	x10, [x29, #-136]               ; 8-byte Folded Reload
	ldr	x8, [x10, x8, lsl #3]
	ldur	x12, [x29, #-184]               ; 8-byte Folded Reload
	str	w9, [x12, x8, lsl #2]
LBB12_16:                               ;   in Loop: Header=BB12_13 Depth=1
	ldur	x8, [x29, #-16]
	ldur	w9, [x29, #-96]
	mov	x10, x9
	ldr	x8, [x8, x10, lsl #3]
	ldur	x10, [x29, #-16]
	ldur	w9, [x29, #-96]
	mov	x11, x9
	ldr	x10, [x10, x11, lsl #3]
	ldur	x11, [x29, #-48]
	subs	x10, x10, x11
	ldur	w9, [x29, #-20]
	mov	x11, x9
	mul	x10, x10, x11
	ldur	x11, [x29, #-40]
	ldur	x12, [x29, #-48]
	subs	x11, x11, x12
	add	x11, x11, #1                    ; =1
	sdiv	x10, x10, x11
	ldur	x11, [x29, #-136]               ; 8-byte Folded Reload
	add	x10, x11, x10, lsl #3
	ldr	x11, [x10]
	add	x12, x11, #1                    ; =1
	str	x12, [x10]
	ldur	x10, [x29, #-160]               ; 8-byte Folded Reload
	str	x8, [x10, x11, lsl #3]
; %bb.17:                               ;   in Loop: Header=BB12_13 Depth=1
	ldur	w8, [x29, #-96]
	add	w8, w8, #1                      ; =1
	stur	w8, [x29, #-96]
	b	LBB12_13
LBB12_18:
	ldur	x8, [x29, #-136]                ; 8-byte Folded Reload
	ldr	x9, [x8]
                                        ; kill: def $w9 killed $w9 killed $x9
	ldur	x0, [x29, #-160]                ; 8-byte Folded Reload
	mov	x1, x9
	ldur	x2, [x29, #-184]                ; 8-byte Folded Reload
	bl	_lambda__bes_quicksort0
	mov	w9, #1
	stur	w9, [x29, #-100]
LBB12_19:                               ; =>This Inner Loop Header: Depth=1
	ldur	w8, [x29, #-100]
	ldur	w9, [x29, #-20]
	subs	w8, w8, w9
	b.hs	LBB12_22
; %bb.20:                               ;   in Loop: Header=BB12_19 Depth=1
	ldur	w8, [x29, #-100]
	subs	w8, w8, #1                      ; =1
	ldur	x9, [x29, #-136]                ; 8-byte Folded Reload
	ldr	x10, [x9, w8, uxtw #3]
	ldur	x11, [x29, #-160]               ; 8-byte Folded Reload
	add	x0, x11, x10, lsl #3
	ldur	w8, [x29, #-100]
	mov	x10, x8
	ldr	x10, [x9, x10, lsl #3]
	ldur	w8, [x29, #-100]
	subs	w8, w8, #1                      ; =1
	ldr	x11, [x9, w8, uxtw #3]
	subs	x10, x10, x11
                                        ; kill: def $w10 killed $w10 killed $x10
	ldur	w8, [x29, #-100]
	subs	w8, w8, #1                      ; =1
	ldr	x11, [x9, w8, uxtw #3]
	ldur	x12, [x29, #-184]               ; 8-byte Folded Reload
	add	x2, x12, x11, lsl #2
	mov	x1, x10
	bl	_lambda__bes_quicksort0
; %bb.21:                               ;   in Loop: Header=BB12_19 Depth=1
	ldur	w8, [x29, #-100]
	add	w8, w8, #1                      ; =1
	stur	w8, [x29, #-100]
	b	LBB12_19
LBB12_22:
	stur	wzr, [x29, #-104]
LBB12_23:                               ; =>This Inner Loop Header: Depth=1
	ldur	w8, [x29, #-104]
	ldur	w9, [x29, #-20]
	subs	w8, w8, w9
	b.hs	LBB12_26
; %bb.24:                               ;   in Loop: Header=BB12_23 Depth=1
	ldur	w8, [x29, #-104]
	mov	x9, x8
	ldur	x10, [x29, #-184]               ; 8-byte Folded Reload
	ldr	w8, [x10, x9, lsl #2]
	ldur	x9, [x29, #-32]
	ldur	w11, [x29, #-104]
	mov	x12, x11
	str	w8, [x9, x12, lsl #2]
; %bb.25:                               ;   in Loop: Header=BB12_23 Depth=1
	ldur	w8, [x29, #-104]
	add	w8, w8, #1                      ; =1
	stur	w8, [x29, #-104]
	b	LBB12_23
LBB12_26:
	stur	wzr, [x29, #-108]
LBB12_27:                               ; =>This Inner Loop Header: Depth=1
	ldur	w8, [x29, #-108]
	ldur	w9, [x29, #-20]
	subs	w8, w8, w9
	b.hs	LBB12_30
; %bb.28:                               ;   in Loop: Header=BB12_27 Depth=1
	ldur	w8, [x29, #-108]
	mov	x9, x8
	ldur	x10, [x29, #-160]               ; 8-byte Folded Reload
	ldr	x9, [x10, x9, lsl #3]
	ldur	x11, [x29, #-16]
	ldur	w8, [x29, #-108]
	mov	x12, x8
	str	x9, [x11, x12, lsl #3]
; %bb.29:                               ;   in Loop: Header=BB12_27 Depth=1
	ldur	w8, [x29, #-108]
	add	w8, w8, #1                      ; =1
	stur	w8, [x29, #-108]
	b	LBB12_27
LBB12_30:
	ldur	x8, [x29, #-56]
	mov	sp, x8
	adrp	x8, ___stack_chk_guard@GOTPAGE
	ldr	x8, [x8, ___stack_chk_guard@GOTPAGEOFF]
	ldr	x8, [x8]
	ldur	x9, [x29, #-8]
	subs	x8, x8, x9
	b.ne	LBB12_32
; %bb.31:
	mov	sp, x29
	ldp	x29, x30, [sp], #16             ; 16-byte Folded Reload
	ret
LBB12_32:
	bl	___stack_chk_fail
	.cfi_endproc
                                        ; -- End function
	.globl	_bes_bucket_sort                ; -- Begin function bes_bucket_sort
	.p2align	2
_bes_bucket_sort:                       ; @bes_bucket_sort
	.cfi_startproc
; %bb.0:
	stp	x29, x30, [sp, #-16]!           ; 16-byte Folded Spill
	mov	x29, sp
	sub	sp, sp, #96                     ; =96
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	adrp	x8, ___stack_chk_guard@GOTPAGE
	ldr	x8, [x8, ___stack_chk_guard@GOTPAGEOFF]
	ldr	x8, [x8]
	stur	x8, [x29, #-8]
	stur	x0, [x29, #-16]
	stur	w1, [x29, #-20]
	ldur	w9, [x29, #-20]
	mov	x8, x9
	mov	x10, #4
	mul	x0, x10, x8
	bl	_malloc
	stur	x0, [x29, #-32]
	stur	wzr, [x29, #-36]
LBB13_1:                                ; =>This Inner Loop Header: Depth=1
	ldur	w8, [x29, #-36]
	ldur	w9, [x29, #-20]
	subs	w8, w8, w9
	b.hs	LBB13_4
; %bb.2:                                ;   in Loop: Header=BB13_1 Depth=1
	ldur	w8, [x29, #-36]
	ldur	x9, [x29, #-32]
	ldur	w10, [x29, #-36]
	mov	x11, x10
	str	w8, [x9, x11, lsl #2]
; %bb.3:                                ;   in Loop: Header=BB13_1 Depth=1
	ldur	w8, [x29, #-36]
	add	w8, w8, #1                      ; =1
	stur	w8, [x29, #-36]
	b	LBB13_1
LBB13_4:
	ldur	w8, [x29, #-20]
	mov	x9, x8
	mov	x10, sp
	stur	x10, [x29, #-48]
	lsl	x10, x9, #3
	add	x10, x10, #15                   ; =15
	and	x10, x10, #0xfffffffffffffff0
	stur	x9, [x29, #-72]                 ; 8-byte Folded Spill
	mov	x9, x10
	stur	x10, [x29, #-80]                ; 8-byte Folded Spill
	adrp	x16, ___chkstk_darwin@GOTPAGE
	ldr	x16, [x16, ___chkstk_darwin@GOTPAGEOFF]
	blr	x16
	mov	x9, sp
	ldur	x10, [x29, #-80]                ; 8-byte Folded Reload
	subs	x9, x9, x10
	mov	sp, x9
	ldur	x11, [x29, #-72]                ; 8-byte Folded Reload
	stur	x11, [x29, #-56]
	stur	wzr, [x29, #-60]
	stur	x9, [x29, #-88]                 ; 8-byte Folded Spill
LBB13_5:                                ; =>This Inner Loop Header: Depth=1
	ldur	w8, [x29, #-60]
	ldur	w9, [x29, #-20]
	subs	w8, w8, w9
	b.hs	LBB13_8
; %bb.6:                                ;   in Loop: Header=BB13_5 Depth=1
	ldur	x8, [x29, #-16]
	ldur	w9, [x29, #-60]
	mov	x10, x9
	ldr	x8, [x8, x10, lsl #3]
	ldur	w9, [x29, #-60]
	mov	x10, x9
	ldur	x11, [x29, #-88]                ; 8-byte Folded Reload
	str	x8, [x11, x10, lsl #3]
; %bb.7:                                ;   in Loop: Header=BB13_5 Depth=1
	ldur	w8, [x29, #-60]
	add	w8, w8, #1                      ; =1
	stur	w8, [x29, #-60]
	b	LBB13_5
LBB13_8:
	ldur	w1, [x29, #-20]
	ldur	x2, [x29, #-32]
	ldur	x0, [x29, #-88]                 ; 8-byte Folded Reload
	bl	_lambda__bucket_sort0
	ldur	x0, [x29, #-32]
	ldur	x8, [x29, #-48]
	mov	sp, x8
	adrp	x8, ___stack_chk_guard@GOTPAGE
	ldr	x8, [x8, ___stack_chk_guard@GOTPAGEOFF]
	ldr	x8, [x8]
	ldur	x9, [x29, #-8]
	subs	x8, x8, x9
	stur	x0, [x29, #-96]                 ; 8-byte Folded Spill
	b.ne	LBB13_10
; %bb.9:
	ldur	x0, [x29, #-96]                 ; 8-byte Folded Reload
	mov	sp, x29
	ldp	x29, x30, [sp], #16             ; 16-byte Folded Reload
	ret
LBB13_10:
	bl	___stack_chk_fail
	.cfi_endproc
                                        ; -- End function
	.globl	_lambda__quick_find_nth_smallest_number ; -- Begin function lambda__quick_find_nth_smallest_number
	.p2align	2
_lambda__quick_find_nth_smallest_number: ; @lambda__quick_find_nth_smallest_number
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #48                     ; =48
	stp	x29, x30, [sp, #32]             ; 16-byte Folded Spill
	add	x29, sp, #32                    ; =32
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	str	x0, [sp, #16]
	str	w1, [sp, #12]
	str	w2, [sp, #8]
	ldr	w8, [sp, #12]
	cbnz	w8, LBB14_2
; %bb.1:
	ldr	x8, [sp, #16]
	ldr	x8, [x8]
	stur	x8, [x29, #-8]
	b	LBB14_13
LBB14_2:
	str	wzr, [sp, #4]
	str	wzr, [sp]
LBB14_3:                                ; =>This Inner Loop Header: Depth=1
	ldr	w8, [sp]
	ldr	w9, [sp, #12]
	subs	w9, w9, #1                      ; =1
	subs	w8, w8, w9
	b.hs	LBB14_8
; %bb.4:                                ;   in Loop: Header=BB14_3 Depth=1
	ldr	x8, [sp, #16]
	ldr	w9, [sp]
	mov	x10, x9
	ldr	x8, [x8, x10, lsl #3]
	ldr	x10, [sp, #16]
	ldr	w9, [sp, #12]
	subs	w9, w9, #1                      ; =1
	ldr	x10, [x10, w9, uxtw #3]
	subs	x8, x8, x10
	b.ge	LBB14_6
; %bb.5:                                ;   in Loop: Header=BB14_3 Depth=1
	ldr	x8, [sp, #16]
	ldr	w9, [sp]
	mov	x10, x9
	add	x0, x8, x10, lsl #3
	ldr	x8, [sp, #16]
	ldr	w9, [sp, #4]
	mov	x10, x9
	mov	x9, x10
	add	w9, w9, #1                      ; =1
	str	w9, [sp, #4]
	add	x1, x8, x10, lsl #3
	bl	_swapld
LBB14_6:                                ;   in Loop: Header=BB14_3 Depth=1
; %bb.7:                                ;   in Loop: Header=BB14_3 Depth=1
	ldr	w8, [sp]
	add	w8, w8, #1                      ; =1
	str	w8, [sp]
	b	LBB14_3
LBB14_8:
	ldr	w8, [sp, #4]
	ldr	w9, [sp, #8]
	subs	w8, w8, w9
	b.ls	LBB14_10
; %bb.9:
	ldr	x8, [sp, #16]
	ldr	w9, [sp, #4]
	mov	x10, x9
	add	x0, x8, x10, lsl #3
	ldr	w9, [sp, #12]
	subs	w9, w9, #1                      ; =1
	ldr	w11, [sp, #4]
	subs	w1, w9, w11
	ldr	w9, [sp, #8]
	subs	w9, w9, #1                      ; =1
	ldr	w11, [sp, #4]
	subs	w2, w9, w11
	bl	_lambda__quick_find_nth_smallest_number
	stur	x0, [x29, #-8]
	b	LBB14_13
LBB14_10:
	ldr	w8, [sp, #4]
	ldr	w9, [sp, #8]
	subs	w8, w8, w9
	b.hs	LBB14_12
; %bb.11:
	ldr	x0, [sp, #16]
	ldr	w1, [sp, #4]
	ldr	w2, [sp, #8]
	bl	_lambda__quick_find_nth_smallest_number
	stur	x0, [x29, #-8]
	b	LBB14_13
LBB14_12:
	ldr	x8, [sp, #16]
	ldr	w9, [sp, #12]
	subs	w9, w9, #1                      ; =1
	ldr	x8, [x8, w9, uxtw #3]
	stur	x8, [x29, #-8]
LBB14_13:
	ldur	x0, [x29, #-8]
	ldp	x29, x30, [sp, #32]             ; 16-byte Folded Reload
	add	sp, sp, #48                     ; =48
	ret
	.cfi_endproc
                                        ; -- End function
	.globl	_bes_stack_push                 ; -- Begin function bes_stack_push
	.p2align	2
_bes_stack_push:                        ; @bes_stack_push
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #16                     ; =16
	.cfi_def_cfa_offset 16
	str	x0, [sp, #8]
	str	x1, [sp]
	ldr	x8, [sp, #8]
	ldr	w9, [x8, #16]
	ldr	x8, [sp, #8]
	ldr	w10, [x8]
	subs	w9, w9, w10
	b.hi	LBB15_2
; %bb.1:
	adrp	x8, _bes_algorithms_err@PAGE
	adrp	x9, _bes_algorithms_err@PAGE
	add	x9, x9, _bes_algorithms_err@PAGEOFF
	ldrsb	w10, [x8, _bes_algorithms_err@PAGEOFF]
	add	w10, w10, #1                    ; =1
	strb	w10, [x9]
	b	LBB15_3
LBB15_2:
	ldr	x8, [sp]
	ldr	x9, [sp, #8]
	ldr	x9, [x9, #8]
	ldr	x10, [sp, #8]
	ldr	w11, [x10]
	mov	x12, x11
	mov	x11, x12
	add	w11, w11, #1                    ; =1
	str	w11, [x10]
	str	x8, [x9, x12, lsl #3]
LBB15_3:
	add	sp, sp, #16                     ; =16
	ret
	.cfi_endproc
                                        ; -- End function
	.globl	_bes_stack_pop                  ; -- Begin function bes_stack_pop
	.p2align	2
_bes_stack_pop:                         ; @bes_stack_pop
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #16                     ; =16
	.cfi_def_cfa_offset 16
	str	x0, [sp]
	ldr	x8, [sp]
	ldr	w9, [x8]
	cmp	w9, #0                          ; =0
	cset	w9, hi
	tbnz	w9, #0, LBB16_2
; %bb.1:
	adrp	x8, _bes_algorithms_err@PAGE
	adrp	x9, _bes_algorithms_err@PAGE
	add	x9, x9, _bes_algorithms_err@PAGEOFF
	ldrsb	w10, [x8, _bes_algorithms_err@PAGEOFF]
	add	w10, w10, #1                    ; =1
	strb	w10, [x9]
	str	xzr, [sp, #8]
	b	LBB16_3
LBB16_2:
	ldr	x8, [sp]
	ldr	w9, [x8]
	subs	w9, w9, #1                      ; =1
	str	w9, [x8]
	ldr	x8, [sp]
	ldr	x8, [x8, #8]
	ldr	x10, [sp]
	ldr	w9, [x10]
	mov	x10, x9
	ldr	x8, [x8, x10, lsl #3]
	str	x8, [sp, #8]
LBB16_3:
	ldr	x0, [sp, #8]
	add	sp, sp, #16                     ; =16
	ret
	.cfi_endproc
                                        ; -- End function
	.globl	_new__bes_d_stack               ; -- Begin function new__bes_d_stack
	.p2align	2
_new__bes_d_stack:                      ; @new__bes_d_stack
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #32                     ; =32
	stp	x29, x30, [sp, #16]             ; 16-byte Folded Spill
	add	x29, sp, #16                    ; =16
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	stur	w0, [x29, #-4]
	str	wzr, [x8]
	ldur	w9, [x29, #-4]
	mov	x10, x9
	mov	x11, #8
	mul	x0, x11, x10
	str	x8, [sp]                        ; 8-byte Folded Spill
	bl	_malloc
	ldr	x8, [sp]                        ; 8-byte Folded Reload
	str	x0, [x8, #8]
	ldur	w9, [x29, #-4]
	str	w9, [x8, #16]
	ldp	x29, x30, [sp, #16]             ; 16-byte Folded Reload
	add	sp, sp, #32                     ; =32
	ret
	.cfi_endproc
                                        ; -- End function
	.globl	_delete__bes_d_stack            ; -- Begin function delete__bes_d_stack
	.p2align	2
_delete__bes_d_stack:                   ; @delete__bes_d_stack
	.cfi_startproc
; %bb.0:
	stp	x29, x30, [sp, #-16]!           ; 16-byte Folded Spill
	mov	x29, sp
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	ldr	x0, [x0, #8]
	bl	_free
	ldp	x29, x30, [sp], #16             ; 16-byte Folded Reload
	ret
	.cfi_endproc
                                        ; -- End function
	.globl	_bes_queue_en                   ; -- Begin function bes_queue_en
	.p2align	2
_bes_queue_en:                          ; @bes_queue_en
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #16                     ; =16
	.cfi_def_cfa_offset 16
	str	x0, [sp, #8]
	str	x1, [sp]
	ldr	x8, [sp, #8]
	ldr	w9, [x8]
	ldr	x8, [sp, #8]
	ldr	w10, [x8, #4]
	subs	w9, w9, w10
	b.ne	LBB19_2
; %bb.1:
	adrp	x8, _bes_algorithms_err@PAGE
	adrp	x9, _bes_algorithms_err@PAGE
	add	x9, x9, _bes_algorithms_err@PAGEOFF
	ldrsb	w10, [x8, _bes_algorithms_err@PAGEOFF]
	add	w10, w10, #1                    ; =1
	strb	w10, [x9]
	b	LBB19_3
LBB19_2:
	ldr	x8, [sp]
	ldr	x9, [sp, #8]
	ldr	x9, [x9, #8]
	ldr	x10, [sp, #8]
	ldr	w11, [x10, #4]
	mov	x10, x11
	str	x8, [x9, x10, lsl #3]
	ldr	x8, [sp, #8]
	ldr	w11, [x8, #4]
	add	w11, w11, #1                    ; =1
	str	w11, [x8, #4]
	ldr	x8, [sp, #8]
	ldr	w11, [x8, #16]
	ldr	x8, [sp, #8]
	ldr	w12, [x8, #4]
	udiv	w13, w12, w11
	mul	w11, w13, w11
	subs	w11, w12, w11
	str	w11, [x8, #4]
LBB19_3:
	add	sp, sp, #16                     ; =16
	ret
	.cfi_endproc
                                        ; -- End function
	.globl	_bes_queue_de                   ; -- Begin function bes_queue_de
	.p2align	2
_bes_queue_de:                          ; @bes_queue_de
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #16                     ; =16
	.cfi_def_cfa_offset 16
	str	x0, [sp]
	ldr	x8, [sp]
	ldr	w9, [x8]
	ldr	x8, [sp]
	ldr	w10, [x8, #4]
	subs	w10, w10, #1                    ; =1
	ldr	x8, [sp]
	ldr	w11, [x8, #16]
	udiv	w12, w10, w11
	mul	w11, w12, w11
	subs	w10, w10, w11
	subs	w9, w9, w10
	b.ne	LBB20_2
; %bb.1:
	adrp	x8, _bes_algorithms_err@PAGE
	adrp	x9, _bes_algorithms_err@PAGE
	add	x9, x9, _bes_algorithms_err@PAGEOFF
	ldrsb	w10, [x8, _bes_algorithms_err@PAGEOFF]
	add	w10, w10, #1                    ; =1
	strb	w10, [x9]
	str	xzr, [sp, #8]
	b	LBB20_3
LBB20_2:
	ldr	x8, [sp]
	ldr	w9, [x8]
	add	w9, w9, #1                      ; =1
	ldr	x8, [sp]
	ldr	w10, [x8, #16]
	udiv	w11, w9, w10
	mul	w10, w11, w10
	subs	w9, w9, w10
	ldr	x8, [sp]
	str	w9, [x8]
	ldr	x8, [sp]
	ldr	x8, [x8, #8]
	ldr	x12, [sp]
	ldr	w9, [x12]
	mov	x12, x9
	ldr	x8, [x8, x12, lsl #3]
	str	x8, [sp, #8]
LBB20_3:
	ldr	x0, [sp, #8]
	add	sp, sp, #16                     ; =16
	ret
	.cfi_endproc
                                        ; -- End function
	.globl	_new__bes_d_queue               ; -- Begin function new__bes_d_queue
	.p2align	2
_new__bes_d_queue:                      ; @new__bes_d_queue
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #32                     ; =32
	stp	x29, x30, [sp, #16]             ; 16-byte Folded Spill
	add	x29, sp, #16                    ; =16
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	stur	w0, [x29, #-4]
	str	wzr, [x8, #4]
	ldur	w9, [x29, #-4]
	subs	w9, w9, #1                      ; =1
	str	w9, [x8]
	ldur	w9, [x29, #-4]
	mov	x10, x9
	mov	x11, #8
	mul	x0, x11, x10
	str	x8, [sp]                        ; 8-byte Folded Spill
	bl	_malloc
	ldr	x8, [sp]                        ; 8-byte Folded Reload
	str	x0, [x8, #8]
	ldur	w9, [x29, #-4]
	str	w9, [x8, #16]
	ldp	x29, x30, [sp, #16]             ; 16-byte Folded Reload
	add	sp, sp, #32                     ; =32
	ret
	.cfi_endproc
                                        ; -- End function
	.globl	_delete__bes_d_queue            ; -- Begin function delete__bes_d_queue
	.p2align	2
_delete__bes_d_queue:                   ; @delete__bes_d_queue
	.cfi_startproc
; %bb.0:
	stp	x29, x30, [sp, #-16]!           ; 16-byte Folded Spill
	mov	x29, sp
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	ldr	x0, [x0, #8]
	bl	_free
	ldp	x29, x30, [sp], #16             ; 16-byte Folded Reload
	ret
	.cfi_endproc
                                        ; -- End function
	.globl	_main                           ; -- Begin function main
	.p2align	2
_main:                                  ; @main
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #96                     ; =96
	stp	x29, x30, [sp, #80]             ; 16-byte Folded Spill
	add	x29, sp, #80                    ; =80
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	mov	w8, #0
	stur	wzr, [x29, #-4]
	sub	x9, x29, #32                    ; =32
	stur	w8, [x29, #-36]                 ; 4-byte Folded Spill
	mov	x8, x9
	mov	w0, #1024
	str	x9, [sp, #32]                   ; 8-byte Folded Spill
	bl	_new__bes_d_queue
	ldr	x0, [sp, #32]                   ; 8-byte Folded Reload
	mov	x1, #10
	bl	_bes_queue_en
	ldr	x0, [sp, #32]                   ; 8-byte Folded Reload
	mov	x1, #20
	bl	_bes_queue_en
	ldr	x0, [sp, #32]                   ; 8-byte Folded Reload
	mov	x1, #30
	bl	_bes_queue_en
	ldr	x0, [sp, #32]                   ; 8-byte Folded Reload
	bl	_bes_queue_de
	ldr	x8, [sp, #32]                   ; 8-byte Folded Reload
	str	x0, [sp, #24]                   ; 8-byte Folded Spill
	mov	x0, x8
	bl	_bes_queue_de
	adrp	x8, l_.str@PAGE
	add	x8, x8, l_.str@PAGEOFF
	str	x0, [sp, #16]                   ; 8-byte Folded Spill
	mov	x0, x8
	mov	x8, sp
	ldr	x9, [sp, #24]                   ; 8-byte Folded Reload
	str	x9, [x8]
	ldr	x10, [sp, #16]                  ; 8-byte Folded Reload
	str	x10, [x8, #8]
	bl	_printf
	ldur	w11, [x29, #-36]                ; 4-byte Folded Reload
	mov	x0, x11
	ldp	x29, x30, [sp, #80]             ; 16-byte Folded Reload
	add	sp, sp, #96                     ; =96
	ret
	.cfi_endproc
                                        ; -- End function
	.globl	_bes_algorithms_err             ; @bes_algorithms_err
.zerofill __DATA,__common,_bes_algorithms_err,1,0
	.section	__TEXT,__cstring,cstring_literals
l_.str:                                 ; @.str
	.asciz	"%ld %ld\n"

.subsections_via_symbols
