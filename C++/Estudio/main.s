	.file	"main.c"
	.intel_syntax noprefix
	.text
	.globl	_FooX
	.def	_FooX;	.scl	2;	.type	32;	.endef
_FooX:
	push	ebp
	mov	ebp, esp
	sub	esp, 16
	mov	DWORD PTR [ebp-4], 0
	mov	DWORD PTR [ebp-8], 0
	jmp	L2
L5:
	mov	DWORD PTR [ebp-12], 0
	jmp	L3
L4:
	mov	eax, DWORD PTR [ebp-8]
	mov	edx, eax
	sal	edx, 4
	mov	eax, DWORD PTR [ebp+8]
	add	edx, eax
	mov	eax, DWORD PTR [ebp-12]
	mov	eax, DWORD PTR [edx+eax*4]
	add	DWORD PTR [ebp-4], eax
	inc	DWORD PTR [ebp-12]
L3:
	cmp	DWORD PTR [ebp-12], 1
	jle	L4
	inc	DWORD PTR [ebp-8]
L2:
	cmp	DWORD PTR [ebp-8], 3
	jle	L5
	mov	eax, DWORD PTR [ebp+8]
	lea	edx, [eax+16]
	mov	eax, DWORD PTR [ebp-4]
	mov	DWORD PTR [edx], eax
	leave
	ret
	.def	___main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
LC1:
	.ascii "%d\0"
	.data
	.align 32
LC0:
	.long	1
	.long	5
	.long	2
	.long	7
	.long	2
	.long	3
	.long	9
	.long	12
	.long	4
	.long	7
	.long	5
	.long	2
	.long	2
	.long	2
	.long	9
	.long	32
	.text
	.globl	_main
	.def	_main;	.scl	2;	.type	32;	.endef
_main:
	push	ebp
	mov	ebp, esp
	push	edi
	push	esi
	push	ebx
	and	esp, -16
	sub	esp, 80
	call	___main
	lea	edx, [esp+16]
	mov	ebx, OFFSET FLAT:LC0
	mov	eax, 16
	mov	edi, edx
	mov	esi, ebx
	mov	ecx, eax
	rep movsd
	lea	eax, [esp+16]
	mov	DWORD PTR [esp], eax
	call	_FooX
	mov	eax, DWORD PTR [esp+16]
	mov	DWORD PTR [esp+4], eax
	mov	DWORD PTR [esp], OFFSET FLAT:LC1
	call	_printf
	mov	eax, 0
	lea	esp, [ebp-12]
	pop	ebx
	pop	esi
	pop	edi
	pop	ebp
	ret
	.def	_printf;	.scl	2;	.type	32;	.endef
