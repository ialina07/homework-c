.section .note.GNU-stack,"",@progbits
.section .text
.global bubbleSortAsm

bubbleSortAsm:
    pushq %rbp
    movq %rsp, %rbp
    pushq %rbx
    pushq %r12
    pushq %r13

    movq %rdi, %rbx        # rbx = указатель на массив
    movl %esi, %r12d       # r12d = количество элементов

    cmpl $1, %r12d
    jle .end_sort

    movl $0, %r13d         # i = 0

.outer_loop:
    movl %r12d, %eax
    decl %eax
    cmpl %r13d, %eax
    jle .end_sort

    movl $0, %ecx          # j = 0

.inner_loop:
    movl %r12d, %eax
    subl %r13d, %eax
    decl %eax
    cmpl %ecx, %eax
    jle .end_inner_loop

    movl (%rbx, %rcx, 4), %edx
    movl 4(%rbx, %rcx, 4), %eax
    cmpl %eax, %edx
    jle .no_swap

    # Обмен элементов
    movl %eax, (%rbx, %rcx, 4)
    movl %edx, 4(%rbx, %rcx, 4)

.no_swap:
    incl %ecx
    jmp .inner_loop

.end_inner_loop:
    incl %r13d
    jmp .outer_loop

.end_sort:
    popq %r13
    popq %r12
    popq %rbx
    popq %rbp
    ret
