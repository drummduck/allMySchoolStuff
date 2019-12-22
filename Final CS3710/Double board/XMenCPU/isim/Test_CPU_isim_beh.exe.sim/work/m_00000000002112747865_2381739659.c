/**********************************************************************/
/*   ____  ____                                                       */
/*  /   /\/   /                                                       */
/* /___/  \  /                                                        */
/* \   \   \/                                                       */
/*  \   \        Copyright (c) 2003-2009 Xilinx, Inc.                */
/*  /   /          All Right Reserved.                                 */
/* /---/   /\                                                         */
/* \   \  /  \                                                      */
/*  \___\/\___\                                                    */
/***********************************************************************/

/* This file is designed for use with ISim build 0x7708f090 */

#define XSI_HIDE_SYMBOL_SPEC true
#include "xsi.h"
#include <memory.h>
#ifdef __GNUC__
#include <stdlib.h>
#else
#include <malloc.h>
#define alloca _alloca
#endif
static const char *ng0 = "//wannsee/users/u0687930/My Documents/ECE 3710/Clock change with help/XMenCPU/memory.v";
static const char *ng1 = "hexprogram.txt";
static int ng2[] = {0, 0};
static int ng3[] = {32767, 0};
static unsigned int ng4[] = {1U, 0U};



static void Initial_56_0(char *t0)
{
    char *t1;
    char *t2;
    char *t3;

LAB0:    xsi_set_current_line(58, ng0);
    t1 = (t0 + 3320);
    t2 = ((char*)((ng2)));
    t3 = ((char*)((ng3)));
    xsi_vlogfile_readmemh(ng1, 0, t1, 1, *((unsigned int *)t2), 1, *((unsigned int *)t3));

LAB1:    return;
}

static void Always_62_1(char *t0)
{
    char t6[8];
    char t30[8];
    char t54[8];
    char t55[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t7;
    char *t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    unsigned int t12;
    unsigned int t13;
    unsigned int t14;
    unsigned int t15;
    unsigned int t16;
    unsigned int t17;
    unsigned int t18;
    unsigned int t19;
    unsigned int t20;
    char *t21;
    char *t22;
    unsigned int t23;
    unsigned int t24;
    unsigned int t25;
    unsigned int t26;
    unsigned int t27;
    char *t28;
    char *t29;
    char *t31;
    char *t32;
    unsigned int t33;
    unsigned int t34;
    unsigned int t35;
    unsigned int t36;
    unsigned int t37;
    unsigned int t38;
    unsigned int t39;
    unsigned int t40;
    unsigned int t41;
    unsigned int t42;
    unsigned int t43;
    unsigned int t44;
    char *t45;
    char *t46;
    unsigned int t47;
    unsigned int t48;
    unsigned int t49;
    unsigned int t50;
    unsigned int t51;
    char *t52;
    char *t53;
    char *t56;
    char *t57;
    char *t58;
    char *t59;
    char *t60;
    char *t61;
    char *t62;
    char *t63;
    unsigned int t64;
    int t65;
    char *t66;
    unsigned int t67;
    int t68;
    int t69;
    unsigned int t70;
    unsigned int t71;
    int t72;
    int t73;

LAB0:    t1 = (t0 + 4488U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(62, ng0);
    t2 = (t0 + 5056);
    *((int *)t2) = 1;
    t3 = (t0 + 4520);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(63, ng0);

LAB5:    xsi_set_current_line(64, ng0);
    t4 = (t0 + 1480U);
    t5 = *((char **)t4);
    t4 = ((char*)((ng4)));
    memset(t6, 0, 8);
    t7 = (t5 + 4);
    t8 = (t4 + 4);
    t9 = *((unsigned int *)t5);
    t10 = *((unsigned int *)t4);
    t11 = (t9 ^ t10);
    t12 = *((unsigned int *)t7);
    t13 = *((unsigned int *)t8);
    t14 = (t12 ^ t13);
    t15 = (t11 | t14);
    t16 = *((unsigned int *)t7);
    t17 = *((unsigned int *)t8);
    t18 = (t16 | t17);
    t19 = (~(t18));
    t20 = (t15 & t19);
    if (t20 != 0)
        goto LAB9;

LAB6:    if (t18 != 0)
        goto LAB8;

LAB7:    *((unsigned int *)t6) = 1;

LAB9:    t22 = (t6 + 4);
    t23 = *((unsigned int *)t22);
    t24 = (~(t23));
    t25 = *((unsigned int *)t6);
    t26 = (t25 & t24);
    t27 = (t26 != 0);
    if (t27 > 0)
        goto LAB10;

LAB11:
LAB12:    goto LAB2;

LAB8:    t21 = (t6 + 4);
    *((unsigned int *)t6) = 1;
    *((unsigned int *)t21) = 1;
    goto LAB9;

LAB10:    xsi_set_current_line(65, ng0);

LAB13:    xsi_set_current_line(66, ng0);
    t28 = (t0 + 1640U);
    t29 = *((char **)t28);
    t28 = ((char*)((ng4)));
    memset(t30, 0, 8);
    t31 = (t29 + 4);
    t32 = (t28 + 4);
    t33 = *((unsigned int *)t29);
    t34 = *((unsigned int *)t28);
    t35 = (t33 ^ t34);
    t36 = *((unsigned int *)t31);
    t37 = *((unsigned int *)t32);
    t38 = (t36 ^ t37);
    t39 = (t35 | t38);
    t40 = *((unsigned int *)t31);
    t41 = *((unsigned int *)t32);
    t42 = (t40 | t41);
    t43 = (~(t42));
    t44 = (t39 & t43);
    if (t44 != 0)
        goto LAB17;

LAB14:    if (t42 != 0)
        goto LAB16;

LAB15:    *((unsigned int *)t30) = 1;

LAB17:    t46 = (t30 + 4);
    t47 = *((unsigned int *)t46);
    t48 = (~(t47));
    t49 = *((unsigned int *)t30);
    t50 = (t49 & t48);
    t51 = (t50 != 0);
    if (t51 > 0)
        goto LAB18;

LAB19:    xsi_set_current_line(71, ng0);
    t2 = (t0 + 3320);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 3320);
    t7 = (t5 + 72U);
    t8 = *((char **)t7);
    t21 = (t0 + 3320);
    t22 = (t21 + 64U);
    t28 = *((char **)t22);
    t29 = (t0 + 1960U);
    t31 = *((char **)t29);
    xsi_vlog_generic_get_array_select_value(t6, 16, t4, t8, t28, 2, 1, t31, 15, 2);
    t29 = (t0 + 3000);
    xsi_vlogvar_wait_assign_value(t29, t6, 0, 0, 16, 0LL);

LAB20:    goto LAB12;

LAB16:    t45 = (t30 + 4);
    *((unsigned int *)t30) = 1;
    *((unsigned int *)t45) = 1;
    goto LAB17;

LAB18:    xsi_set_current_line(67, ng0);

LAB21:    xsi_set_current_line(68, ng0);
    t52 = (t0 + 1800U);
    t53 = *((char **)t52);
    t52 = (t0 + 3320);
    t56 = (t0 + 3320);
    t57 = (t56 + 72U);
    t58 = *((char **)t57);
    t59 = (t0 + 3320);
    t60 = (t59 + 64U);
    t61 = *((char **)t60);
    t62 = (t0 + 1960U);
    t63 = *((char **)t62);
    xsi_vlog_generic_convert_array_indices(t54, t55, t58, t61, 2, 1, t63, 15, 2);
    t62 = (t54 + 4);
    t64 = *((unsigned int *)t62);
    t65 = (!(t64));
    t66 = (t55 + 4);
    t67 = *((unsigned int *)t66);
    t68 = (!(t67));
    t69 = (t65 && t68);
    if (t69 == 1)
        goto LAB22;

LAB23:    xsi_set_current_line(69, ng0);
    t2 = (t0 + 1800U);
    t3 = *((char **)t2);
    t2 = (t0 + 3000);
    xsi_vlogvar_wait_assign_value(t2, t3, 0, 0, 16, 0LL);
    goto LAB20;

LAB22:    t70 = *((unsigned int *)t54);
    t71 = *((unsigned int *)t55);
    t72 = (t70 - t71);
    t73 = (t72 + 1);
    xsi_vlogvar_wait_assign_value(t52, t53, 0, *((unsigned int *)t55), t73, 0LL);
    goto LAB23;

}

static void Always_76_2(char *t0)
{
    char t6[8];
    char t30[8];
    char t54[8];
    char t55[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t7;
    char *t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    unsigned int t12;
    unsigned int t13;
    unsigned int t14;
    unsigned int t15;
    unsigned int t16;
    unsigned int t17;
    unsigned int t18;
    unsigned int t19;
    unsigned int t20;
    char *t21;
    char *t22;
    unsigned int t23;
    unsigned int t24;
    unsigned int t25;
    unsigned int t26;
    unsigned int t27;
    char *t28;
    char *t29;
    char *t31;
    char *t32;
    unsigned int t33;
    unsigned int t34;
    unsigned int t35;
    unsigned int t36;
    unsigned int t37;
    unsigned int t38;
    unsigned int t39;
    unsigned int t40;
    unsigned int t41;
    unsigned int t42;
    unsigned int t43;
    unsigned int t44;
    char *t45;
    char *t46;
    unsigned int t47;
    unsigned int t48;
    unsigned int t49;
    unsigned int t50;
    unsigned int t51;
    char *t52;
    char *t53;
    char *t56;
    char *t57;
    char *t58;
    char *t59;
    char *t60;
    char *t61;
    char *t62;
    char *t63;
    unsigned int t64;
    int t65;
    char *t66;
    unsigned int t67;
    int t68;
    int t69;
    unsigned int t70;
    unsigned int t71;
    int t72;
    int t73;

LAB0:    t1 = (t0 + 4736U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(76, ng0);
    t2 = (t0 + 5072);
    *((int *)t2) = 1;
    t3 = (t0 + 4768);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(77, ng0);

LAB5:    xsi_set_current_line(78, ng0);
    t4 = (t0 + 2120U);
    t5 = *((char **)t4);
    t4 = ((char*)((ng4)));
    memset(t6, 0, 8);
    t7 = (t5 + 4);
    t8 = (t4 + 4);
    t9 = *((unsigned int *)t5);
    t10 = *((unsigned int *)t4);
    t11 = (t9 ^ t10);
    t12 = *((unsigned int *)t7);
    t13 = *((unsigned int *)t8);
    t14 = (t12 ^ t13);
    t15 = (t11 | t14);
    t16 = *((unsigned int *)t7);
    t17 = *((unsigned int *)t8);
    t18 = (t16 | t17);
    t19 = (~(t18));
    t20 = (t15 & t19);
    if (t20 != 0)
        goto LAB9;

LAB6:    if (t18 != 0)
        goto LAB8;

LAB7:    *((unsigned int *)t6) = 1;

LAB9:    t22 = (t6 + 4);
    t23 = *((unsigned int *)t22);
    t24 = (~(t23));
    t25 = *((unsigned int *)t6);
    t26 = (t25 & t24);
    t27 = (t26 != 0);
    if (t27 > 0)
        goto LAB10;

LAB11:
LAB12:    goto LAB2;

LAB8:    t21 = (t6 + 4);
    *((unsigned int *)t6) = 1;
    *((unsigned int *)t21) = 1;
    goto LAB9;

LAB10:    xsi_set_current_line(79, ng0);

LAB13:    xsi_set_current_line(80, ng0);
    t28 = (t0 + 2280U);
    t29 = *((char **)t28);
    t28 = ((char*)((ng4)));
    memset(t30, 0, 8);
    t31 = (t29 + 4);
    t32 = (t28 + 4);
    t33 = *((unsigned int *)t29);
    t34 = *((unsigned int *)t28);
    t35 = (t33 ^ t34);
    t36 = *((unsigned int *)t31);
    t37 = *((unsigned int *)t32);
    t38 = (t36 ^ t37);
    t39 = (t35 | t38);
    t40 = *((unsigned int *)t31);
    t41 = *((unsigned int *)t32);
    t42 = (t40 | t41);
    t43 = (~(t42));
    t44 = (t39 & t43);
    if (t44 != 0)
        goto LAB17;

LAB14:    if (t42 != 0)
        goto LAB16;

LAB15:    *((unsigned int *)t30) = 1;

LAB17:    t46 = (t30 + 4);
    t47 = *((unsigned int *)t46);
    t48 = (~(t47));
    t49 = *((unsigned int *)t30);
    t50 = (t49 & t48);
    t51 = (t50 != 0);
    if (t51 > 0)
        goto LAB18;

LAB19:    xsi_set_current_line(85, ng0);
    t2 = (t0 + 3320);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 3320);
    t7 = (t5 + 72U);
    t8 = *((char **)t7);
    t21 = (t0 + 3320);
    t22 = (t21 + 64U);
    t28 = *((char **)t22);
    t29 = (t0 + 2600U);
    t31 = *((char **)t29);
    xsi_vlog_generic_get_array_select_value(t6, 16, t4, t8, t28, 2, 1, t31, 15, 2);
    t29 = (t0 + 3160);
    xsi_vlogvar_wait_assign_value(t29, t6, 0, 0, 16, 0LL);

LAB20:    goto LAB12;

LAB16:    t45 = (t30 + 4);
    *((unsigned int *)t30) = 1;
    *((unsigned int *)t45) = 1;
    goto LAB17;

LAB18:    xsi_set_current_line(81, ng0);

LAB21:    xsi_set_current_line(82, ng0);
    t52 = (t0 + 2440U);
    t53 = *((char **)t52);
    t52 = (t0 + 3320);
    t56 = (t0 + 3320);
    t57 = (t56 + 72U);
    t58 = *((char **)t57);
    t59 = (t0 + 3320);
    t60 = (t59 + 64U);
    t61 = *((char **)t60);
    t62 = (t0 + 2600U);
    t63 = *((char **)t62);
    xsi_vlog_generic_convert_array_indices(t54, t55, t58, t61, 2, 1, t63, 15, 2);
    t62 = (t54 + 4);
    t64 = *((unsigned int *)t62);
    t65 = (!(t64));
    t66 = (t55 + 4);
    t67 = *((unsigned int *)t66);
    t68 = (!(t67));
    t69 = (t65 && t68);
    if (t69 == 1)
        goto LAB22;

LAB23:    xsi_set_current_line(83, ng0);
    t2 = (t0 + 2440U);
    t3 = *((char **)t2);
    t2 = (t0 + 3160);
    xsi_vlogvar_wait_assign_value(t2, t3, 0, 0, 16, 0LL);
    goto LAB20;

LAB22:    t70 = *((unsigned int *)t54);
    t71 = *((unsigned int *)t55);
    t72 = (t70 - t71);
    t73 = (t72 + 1);
    xsi_vlogvar_wait_assign_value(t52, t53, 0, *((unsigned int *)t55), t73, 0LL);
    goto LAB23;

}


extern void work_m_00000000002112747865_2381739659_init()
{
	static char *pe[] = {(void *)Initial_56_0,(void *)Always_62_1,(void *)Always_76_2};
	xsi_register_didat("work_m_00000000002112747865_2381739659", "isim/Test_CPU_isim_beh.exe.sim/work/m_00000000002112747865_2381739659.didat");
	xsi_register_executes(pe);
}
