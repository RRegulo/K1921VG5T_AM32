/* Regulo, 2026: VG5T trap entry based on the project reference implementation.
 * Keep this entry integer-only; interrupt handlers must not use FP registers. */
    .section .text.irq_entry, "ax", @progbits
    .balign 16
    .globl vg5t_irq_entry
    .type vg5t_irq_entry, @function
vg5t_irq_entry:
    addi    sp, sp, -80
    sw      ra, 0(sp)
    sw      t0, 4(sp)
    sw      t1, 8(sp)
    sw      t2, 12(sp)
    sw      a0, 16(sp)
    sw      a1, 20(sp)
    sw      a2, 24(sp)
    sw      a3, 28(sp)
    sw      a4, 32(sp)
    sw      a5, 36(sp)
    sw      a6, 40(sp)
    sw      a7, 44(sp)
    sw      t3, 48(sp)
    sw      t4, 52(sp)
    sw      t5, 56(sp)
    sw      t6, 60(sp)
    csrr    t0, mcause
    bgez    t0, .Lvg5t_exception
    andi    t0, t0, 0xff
    slli    t0, t0, 2
    la      t1, riscv_handler_map
    add     t1, t1, t0
    lw      t1, 0(t1)
    beqz    t1, .Lvg5t_nohandler
    csrr    t2, mepc
    csrr    t3, mstatus
    sw      t2, 64(sp)
    sw      t3, 68(sp)
    jalr    t1
    csrci   mstatus, 8
    lw      t2, 64(sp)
    csrw    mepc, t2
    lw      t3, 68(sp)
    csrr    t4, mstatus
    li      t5, 0x1880
    not     t6, t5
    and     t4, t4, t6
    and     t3, t3, t5
    or      t4, t4, t3
    csrw    mstatus, t4
    lw      ra, 0(sp)
    lw      t0, 4(sp)
    lw      t1, 8(sp)
    lw      t2, 12(sp)
    lw      a0, 16(sp)
    lw      a1, 20(sp)
    lw      a2, 24(sp)
    lw      a3, 28(sp)
    lw      a4, 32(sp)
    lw      a5, 36(sp)
    lw      a6, 40(sp)
    lw      a7, 44(sp)
    lw      t3, 48(sp)
    lw      t4, 52(sp)
    lw      t5, 56(sp)
    lw      t6, 60(sp)
    addi    sp, sp, 80
    mret
.Lvg5t_exception:
    j       .Lvg5t_exception
.Lvg5t_nohandler:
    j       .Lvg5t_nohandler
    .size vg5t_irq_entry, . - vg5t_irq_entry
