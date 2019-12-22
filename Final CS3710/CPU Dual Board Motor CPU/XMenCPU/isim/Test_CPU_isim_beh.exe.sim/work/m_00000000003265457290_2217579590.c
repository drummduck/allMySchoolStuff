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
static const char *ng0 = "C:/Users/u0837708/Desktop/Documents/CPU SimTesting/XMenCPU/nesController.v";
static unsigned int ng1[] = {1U, 0U};
static unsigned int ng2[] = {255U, 0U};
static unsigned int ng3[] = {0U, 0U};
static unsigned int ng4[] = {1000U, 0U};
static int ng5[] = {0, 0};
static int ng6[] = {1, 0};
static int ng7[] = {2, 0};
static int ng8[] = {3, 0};
static int ng9[] = {4, 0};
static int ng10[] = {5, 0};
static int ng11[] = {6, 0};
static int ng12[] = {7, 0};
static int ng13[] = {8, 0};
static int ng14[] = {9, 0};
static int ng15[] = {10, 0};
static int ng16[] = {11, 0};
static int ng17[] = {12, 0};



static void Cont_37_0(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    char *t8;
    char *t9;
    unsigned int t10;
    unsigned int t11;
    char *t12;
    unsigned int t13;
    unsigned int t14;
    char *t15;
    unsigned int t16;
    unsigned int t17;
    char *t18;

LAB0:    t1 = (t0 + 3944U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(37, ng0);
    t2 = (t0 + 2864);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 5136);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    memset(t9, 0, 8);
    t10 = 255U;
    t11 = t10;
    t12 = (t4 + 4);
    t13 = *((unsigned int *)t4);
    t10 = (t10 & t13);
    t14 = *((unsigned int *)t12);
    t11 = (t11 & t14);
    t15 = (t9 + 4);
    t16 = *((unsigned int *)t9);
    *((unsigned int *)t9) = (t16 | t10);
    t17 = *((unsigned int *)t15);
    *((unsigned int *)t15) = (t17 | t11);
    xsi_driver_vfirst_trans(t5, 0, 7);
    t18 = (t0 + 5008);
    *((int *)t18) = 1;

LAB1:    return;
}

static void Always_39_1(char *t0)
{
    char t6[8];
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

LAB0:    t1 = (t0 + 4192U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(39, ng0);
    t2 = (t0 + 5024);
    *((int *)t2) = 1;
    t3 = (t0 + 4224);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(40, ng0);

LAB5:    xsi_set_current_line(41, ng0);
    t4 = (t0 + 1344U);
    t5 = *((char **)t4);
    t4 = ((char*)((ng1)));
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

LAB11:    xsi_set_current_line(42, ng0);
    t2 = (t0 + 3024);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng1)));
    memset(t6, 0, 8);
    t7 = (t4 + 4);
    t8 = (t5 + 4);
    t9 = *((unsigned int *)t4);
    t10 = *((unsigned int *)t5);
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
        goto LAB16;

LAB13:    if (t18 != 0)
        goto LAB15;

LAB14:    *((unsigned int *)t6) = 1;

LAB16:    t22 = (t6 + 4);
    t23 = *((unsigned int *)t22);
    t24 = (~(t23));
    t25 = *((unsigned int *)t6);
    t26 = (t25 & t24);
    t27 = (t26 != 0);
    if (t27 > 0)
        goto LAB17;

LAB18:
LAB19:
LAB12:    goto LAB2;

LAB8:    t21 = (t6 + 4);
    *((unsigned int *)t6) = 1;
    *((unsigned int *)t21) = 1;
    goto LAB9;

LAB10:    xsi_set_current_line(41, ng0);
    t28 = ((char*)((ng2)));
    t29 = (t0 + 2064);
    xsi_vlogvar_wait_assign_value(t29, t28, 0, 0, 8, 0LL);
    goto LAB12;

LAB15:    t21 = (t6 + 4);
    *((unsigned int *)t6) = 1;
    *((unsigned int *)t21) = 1;
    goto LAB16;

LAB17:    xsi_set_current_line(42, ng0);
    t28 = (t0 + 1664U);
    t29 = *((char **)t28);
    t28 = (t0 + 2064);
    xsi_vlogvar_wait_assign_value(t28, t29, 0, 0, 8, 0LL);
    goto LAB19;

}

static void Always_47_2(char *t0)
{
    char t6[8];
    char t30[8];
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
    char *t38;
    char *t39;
    char *t40;
    unsigned int t41;
    unsigned int t42;
    unsigned int t43;
    unsigned int t44;
    unsigned int t45;
    unsigned int t46;
    unsigned int t47;
    unsigned int t48;
    char *t49;

LAB0:    t1 = (t0 + 4440U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(47, ng0);
    t2 = (t0 + 5040);
    *((int *)t2) = 1;
    t3 = (t0 + 4472);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(48, ng0);

LAB5:    xsi_set_current_line(49, ng0);
    t4 = (t0 + 1344U);
    t5 = *((char **)t4);
    t4 = ((char*)((ng1)));
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

LAB11:    xsi_set_current_line(54, ng0);
    t2 = (t0 + 2704);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng4)));
    memset(t6, 0, 8);
    t7 = (t4 + 4);
    t8 = (t5 + 4);
    t9 = *((unsigned int *)t4);
    t10 = *((unsigned int *)t5);
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
        goto LAB17;

LAB14:    if (t18 != 0)
        goto LAB16;

LAB15:    *((unsigned int *)t6) = 1;

LAB17:    t22 = (t6 + 4);
    t23 = *((unsigned int *)t22);
    t24 = (~(t23));
    t25 = *((unsigned int *)t6);
    t26 = (t25 & t24);
    t27 = (t26 != 0);
    if (t27 > 0)
        goto LAB18;

LAB19:    xsi_set_current_line(60, ng0);

LAB28:    xsi_set_current_line(61, ng0);
    t2 = (t0 + 2384);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 2384);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 1, 0LL);
    xsi_set_current_line(62, ng0);
    t2 = (t0 + 2704);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng1)));
    memset(t6, 0, 8);
    xsi_vlog_unsigned_add(t6, 10, t4, 10, t5, 10);
    t7 = (t0 + 2704);
    xsi_vlogvar_wait_assign_value(t7, t6, 0, 0, 10, 0LL);

LAB20:
LAB12:    goto LAB2;

LAB8:    t21 = (t6 + 4);
    *((unsigned int *)t6) = 1;
    *((unsigned int *)t21) = 1;
    goto LAB9;

LAB10:    xsi_set_current_line(50, ng0);

LAB13:    xsi_set_current_line(51, ng0);
    t28 = ((char*)((ng3)));
    t29 = (t0 + 2384);
    xsi_vlogvar_wait_assign_value(t29, t28, 0, 0, 1, 0LL);
    xsi_set_current_line(52, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 2704);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 10, 0LL);
    goto LAB12;

LAB16:    t21 = (t6 + 4);
    *((unsigned int *)t6) = 1;
    *((unsigned int *)t21) = 1;
    goto LAB17;

LAB18:    xsi_set_current_line(55, ng0);

LAB21:    xsi_set_current_line(56, ng0);
    t28 = (t0 + 2384);
    t29 = (t28 + 56U);
    t31 = *((char **)t29);
    memset(t30, 0, 8);
    t32 = (t31 + 4);
    t33 = *((unsigned int *)t32);
    t34 = (~(t33));
    t35 = *((unsigned int *)t31);
    t36 = (t35 & t34);
    t37 = (t36 & 1U);
    if (t37 != 0)
        goto LAB25;

LAB23:    if (*((unsigned int *)t32) == 0)
        goto LAB22;

LAB24:    t38 = (t30 + 4);
    *((unsigned int *)t30) = 1;
    *((unsigned int *)t38) = 1;

LAB25:    t39 = (t30 + 4);
    t40 = (t31 + 4);
    t41 = *((unsigned int *)t31);
    t42 = (~(t41));
    *((unsigned int *)t30) = t42;
    *((unsigned int *)t39) = 0;
    if (*((unsigned int *)t40) != 0)
        goto LAB27;

LAB26:    t47 = *((unsigned int *)t30);
    *((unsigned int *)t30) = (t47 & 1U);
    t48 = *((unsigned int *)t39);
    *((unsigned int *)t39) = (t48 & 1U);
    t49 = (t0 + 2384);
    xsi_vlogvar_wait_assign_value(t49, t30, 0, 0, 1, 0LL);
    xsi_set_current_line(57, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 2704);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 10, 0LL);
    goto LAB20;

LAB22:    *((unsigned int *)t30) = 1;
    goto LAB25;

LAB27:    t43 = *((unsigned int *)t30);
    t44 = *((unsigned int *)t40);
    *((unsigned int *)t30) = (t43 | t44);
    t45 = *((unsigned int *)t39);
    t46 = *((unsigned int *)t40);
    *((unsigned int *)t39) = (t45 | t46);
    goto LAB26;

}

static void Always_67_3(char *t0)
{
    char t6[8];
    char t35[8];
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
    char *t30;
    char *t31;
    int t32;
    char *t33;
    char *t34;

LAB0:    t1 = (t0 + 4688U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(67, ng0);
    t2 = (t0 + 5056);
    *((int *)t2) = 1;
    t3 = (t0 + 4720);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(68, ng0);

LAB5:    xsi_set_current_line(69, ng0);
    t4 = (t0 + 1344U);
    t5 = *((char **)t4);
    t4 = ((char*)((ng1)));
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

LAB11:    xsi_set_current_line(76, ng0);
    t2 = (t0 + 2544);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 472);
    t7 = *((char **)t5);
    memset(t6, 0, 8);
    t5 = (t4 + 4);
    if (*((unsigned int *)t5) != 0)
        goto LAB15;

LAB14:    t8 = (t7 + 4);
    if (*((unsigned int *)t8) != 0)
        goto LAB15;

LAB18:    if (*((unsigned int *)t4) > *((unsigned int *)t7))
        goto LAB17;

LAB16:    *((unsigned int *)t6) = 1;

LAB17:    t22 = (t6 + 4);
    t9 = *((unsigned int *)t22);
    t10 = (~(t9));
    t11 = *((unsigned int *)t6);
    t12 = (t11 & t10);
    t13 = (t12 != 0);
    if (t13 > 0)
        goto LAB19;

LAB20:
LAB21:
LAB12:    goto LAB2;

LAB8:    t21 = (t6 + 4);
    *((unsigned int *)t6) = 1;
    *((unsigned int *)t21) = 1;
    goto LAB9;

LAB10:    xsi_set_current_line(70, ng0);

LAB13:    xsi_set_current_line(71, ng0);
    t28 = ((char*)((ng2)));
    t29 = (t0 + 2864);
    xsi_vlogvar_wait_assign_value(t29, t28, 0, 0, 8, 0LL);
    xsi_set_current_line(72, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 2224);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 1, 0LL);
    xsi_set_current_line(73, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 2544);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 11, 0LL);
    xsi_set_current_line(74, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 3024);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 1, 0LL);
    goto LAB12;

LAB15:    t21 = (t6 + 4);
    *((unsigned int *)t6) = 1;
    *((unsigned int *)t21) = 1;
    goto LAB17;

LAB19:    xsi_set_current_line(77, ng0);

LAB22:    xsi_set_current_line(78, ng0);
    t28 = (t0 + 2544);
    t29 = (t28 + 56U);
    t30 = *((char **)t29);

LAB23:    t31 = ((char*)((ng5)));
    t32 = xsi_vlog_unsigned_case_compare(t30, 11, t31, 32);
    if (t32 == 1)
        goto LAB24;

LAB25:    t2 = ((char*)((ng6)));
    t32 = xsi_vlog_unsigned_case_compare(t30, 11, t2, 32);
    if (t32 == 1)
        goto LAB26;

LAB27:    t2 = ((char*)((ng7)));
    t32 = xsi_vlog_unsigned_case_compare(t30, 11, t2, 32);
    if (t32 == 1)
        goto LAB28;

LAB29:    t2 = ((char*)((ng8)));
    t32 = xsi_vlog_unsigned_case_compare(t30, 11, t2, 32);
    if (t32 == 1)
        goto LAB30;

LAB31:    t2 = ((char*)((ng9)));
    t32 = xsi_vlog_unsigned_case_compare(t30, 11, t2, 32);
    if (t32 == 1)
        goto LAB32;

LAB33:    t2 = ((char*)((ng10)));
    t32 = xsi_vlog_unsigned_case_compare(t30, 11, t2, 32);
    if (t32 == 1)
        goto LAB34;

LAB35:    t2 = ((char*)((ng11)));
    t32 = xsi_vlog_unsigned_case_compare(t30, 11, t2, 32);
    if (t32 == 1)
        goto LAB36;

LAB37:    t2 = ((char*)((ng12)));
    t32 = xsi_vlog_unsigned_case_compare(t30, 11, t2, 32);
    if (t32 == 1)
        goto LAB38;

LAB39:    t2 = ((char*)((ng13)));
    t32 = xsi_vlog_unsigned_case_compare(t30, 11, t2, 32);
    if (t32 == 1)
        goto LAB40;

LAB41:    t2 = ((char*)((ng14)));
    t32 = xsi_vlog_unsigned_case_compare(t30, 11, t2, 32);
    if (t32 == 1)
        goto LAB42;

LAB43:    t2 = ((char*)((ng15)));
    t32 = xsi_vlog_unsigned_case_compare(t30, 11, t2, 32);
    if (t32 == 1)
        goto LAB44;

LAB45:    t2 = ((char*)((ng16)));
    t32 = xsi_vlog_unsigned_case_compare(t30, 11, t2, 32);
    if (t32 == 1)
        goto LAB46;

LAB47:    t2 = ((char*)((ng17)));
    t32 = xsi_vlog_unsigned_case_compare(t30, 11, t2, 32);
    if (t32 == 1)
        goto LAB48;

LAB49:
LAB51:
LAB50:    xsi_set_current_line(175, ng0);

LAB66:    xsi_set_current_line(176, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 2224);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 1, 0LL);
    xsi_set_current_line(177, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 2544);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 11, 0LL);
    xsi_set_current_line(178, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 3024);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 1, 0LL);

LAB52:    goto LAB21;

LAB24:    xsi_set_current_line(80, ng0);

LAB53:    xsi_set_current_line(81, ng0);
    t33 = ((char*)((ng1)));
    t34 = (t0 + 2224);
    xsi_vlogvar_wait_assign_value(t34, t33, 0, 0, 1, 0LL);
    xsi_set_current_line(82, ng0);
    t2 = (t0 + 2544);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng1)));
    memset(t6, 0, 8);
    xsi_vlog_unsigned_add(t6, 11, t4, 11, t5, 11);
    t7 = (t0 + 2544);
    xsi_vlogvar_wait_assign_value(t7, t6, 0, 0, 11, 0LL);
    xsi_set_current_line(83, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 3024);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 1, 0LL);
    goto LAB52;

LAB26:    xsi_set_current_line(87, ng0);

LAB54:    xsi_set_current_line(88, ng0);
    t3 = ((char*)((ng3)));
    t4 = (t0 + 2224);
    xsi_vlogvar_wait_assign_value(t4, t3, 0, 0, 1, 0LL);
    xsi_set_current_line(89, ng0);
    t2 = (t0 + 2544);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng1)));
    memset(t6, 0, 8);
    xsi_vlog_unsigned_add(t6, 11, t4, 11, t5, 11);
    t7 = (t0 + 2544);
    xsi_vlogvar_wait_assign_value(t7, t6, 0, 0, 11, 0LL);
    xsi_set_current_line(90, ng0);
    t2 = (t0 + 1504U);
    t3 = *((char **)t2);
    t2 = (t0 + 2864);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    memset(t35, 0, 8);
    t7 = (t35 + 4);
    t8 = (t5 + 4);
    t9 = *((unsigned int *)t5);
    t10 = (t9 >> 0);
    *((unsigned int *)t35) = t10;
    t11 = *((unsigned int *)t8);
    t12 = (t11 >> 0);
    *((unsigned int *)t7) = t12;
    t13 = *((unsigned int *)t35);
    *((unsigned int *)t35) = (t13 & 127U);
    t14 = *((unsigned int *)t7);
    *((unsigned int *)t7) = (t14 & 127U);
    xsi_vlogtype_concat(t6, 8, 8, 2U, t35, 7, t3, 1);
    t21 = (t0 + 2864);
    xsi_vlogvar_wait_assign_value(t21, t6, 0, 0, 8, 0LL);
    xsi_set_current_line(91, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 3024);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 1, 0LL);
    goto LAB52;

LAB28:    xsi_set_current_line(95, ng0);

LAB55:    xsi_set_current_line(96, ng0);
    t3 = ((char*)((ng3)));
    t4 = (t0 + 2224);
    xsi_vlogvar_wait_assign_value(t4, t3, 0, 0, 1, 0LL);
    xsi_set_current_line(97, ng0);
    t2 = (t0 + 2544);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng1)));
    memset(t6, 0, 8);
    xsi_vlog_unsigned_add(t6, 11, t4, 11, t5, 11);
    t7 = (t0 + 2544);
    xsi_vlogvar_wait_assign_value(t7, t6, 0, 0, 11, 0LL);
    xsi_set_current_line(98, ng0);
    t2 = (t0 + 1504U);
    t3 = *((char **)t2);
    t2 = (t0 + 2864);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    memset(t35, 0, 8);
    t7 = (t35 + 4);
    t8 = (t5 + 4);
    t9 = *((unsigned int *)t5);
    t10 = (t9 >> 0);
    *((unsigned int *)t35) = t10;
    t11 = *((unsigned int *)t8);
    t12 = (t11 >> 0);
    *((unsigned int *)t7) = t12;
    t13 = *((unsigned int *)t35);
    *((unsigned int *)t35) = (t13 & 127U);
    t14 = *((unsigned int *)t7);
    *((unsigned int *)t7) = (t14 & 127U);
    xsi_vlogtype_concat(t6, 8, 8, 2U, t35, 7, t3, 1);
    t21 = (t0 + 2864);
    xsi_vlogvar_wait_assign_value(t21, t6, 0, 0, 8, 0LL);
    xsi_set_current_line(99, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 3024);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 1, 0LL);
    goto LAB52;

LAB30:    xsi_set_current_line(103, ng0);

LAB56:    xsi_set_current_line(104, ng0);
    t3 = ((char*)((ng3)));
    t4 = (t0 + 2224);
    xsi_vlogvar_wait_assign_value(t4, t3, 0, 0, 1, 0LL);
    xsi_set_current_line(105, ng0);
    t2 = (t0 + 2544);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng1)));
    memset(t6, 0, 8);
    xsi_vlog_unsigned_add(t6, 11, t4, 11, t5, 11);
    t7 = (t0 + 2544);
    xsi_vlogvar_wait_assign_value(t7, t6, 0, 0, 11, 0LL);
    xsi_set_current_line(106, ng0);
    t2 = (t0 + 1504U);
    t3 = *((char **)t2);
    t2 = (t0 + 2864);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    memset(t35, 0, 8);
    t7 = (t35 + 4);
    t8 = (t5 + 4);
    t9 = *((unsigned int *)t5);
    t10 = (t9 >> 0);
    *((unsigned int *)t35) = t10;
    t11 = *((unsigned int *)t8);
    t12 = (t11 >> 0);
    *((unsigned int *)t7) = t12;
    t13 = *((unsigned int *)t35);
    *((unsigned int *)t35) = (t13 & 127U);
    t14 = *((unsigned int *)t7);
    *((unsigned int *)t7) = (t14 & 127U);
    xsi_vlogtype_concat(t6, 8, 8, 2U, t35, 7, t3, 1);
    t21 = (t0 + 2864);
    xsi_vlogvar_wait_assign_value(t21, t6, 0, 0, 8, 0LL);
    xsi_set_current_line(107, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 3024);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 1, 0LL);
    goto LAB52;

LAB32:    xsi_set_current_line(110, ng0);

LAB57:    xsi_set_current_line(111, ng0);
    t3 = ((char*)((ng3)));
    t4 = (t0 + 2224);
    xsi_vlogvar_wait_assign_value(t4, t3, 0, 0, 1, 0LL);
    xsi_set_current_line(112, ng0);
    t2 = (t0 + 2544);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng1)));
    memset(t6, 0, 8);
    xsi_vlog_unsigned_add(t6, 11, t4, 11, t5, 11);
    t7 = (t0 + 2544);
    xsi_vlogvar_wait_assign_value(t7, t6, 0, 0, 11, 0LL);
    xsi_set_current_line(113, ng0);
    t2 = (t0 + 1504U);
    t3 = *((char **)t2);
    t2 = (t0 + 2864);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    memset(t35, 0, 8);
    t7 = (t35 + 4);
    t8 = (t5 + 4);
    t9 = *((unsigned int *)t5);
    t10 = (t9 >> 0);
    *((unsigned int *)t35) = t10;
    t11 = *((unsigned int *)t8);
    t12 = (t11 >> 0);
    *((unsigned int *)t7) = t12;
    t13 = *((unsigned int *)t35);
    *((unsigned int *)t35) = (t13 & 127U);
    t14 = *((unsigned int *)t7);
    *((unsigned int *)t7) = (t14 & 127U);
    xsi_vlogtype_concat(t6, 8, 8, 2U, t35, 7, t3, 1);
    t21 = (t0 + 2864);
    xsi_vlogvar_wait_assign_value(t21, t6, 0, 0, 8, 0LL);
    xsi_set_current_line(114, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 3024);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 1, 0LL);
    goto LAB52;

LAB34:    xsi_set_current_line(118, ng0);

LAB58:    xsi_set_current_line(119, ng0);
    t3 = ((char*)((ng3)));
    t4 = (t0 + 2224);
    xsi_vlogvar_wait_assign_value(t4, t3, 0, 0, 1, 0LL);
    xsi_set_current_line(120, ng0);
    t2 = (t0 + 2544);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng1)));
    memset(t6, 0, 8);
    xsi_vlog_unsigned_add(t6, 11, t4, 11, t5, 11);
    t7 = (t0 + 2544);
    xsi_vlogvar_wait_assign_value(t7, t6, 0, 0, 11, 0LL);
    xsi_set_current_line(121, ng0);
    t2 = (t0 + 1504U);
    t3 = *((char **)t2);
    t2 = (t0 + 2864);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    memset(t35, 0, 8);
    t7 = (t35 + 4);
    t8 = (t5 + 4);
    t9 = *((unsigned int *)t5);
    t10 = (t9 >> 0);
    *((unsigned int *)t35) = t10;
    t11 = *((unsigned int *)t8);
    t12 = (t11 >> 0);
    *((unsigned int *)t7) = t12;
    t13 = *((unsigned int *)t35);
    *((unsigned int *)t35) = (t13 & 127U);
    t14 = *((unsigned int *)t7);
    *((unsigned int *)t7) = (t14 & 127U);
    xsi_vlogtype_concat(t6, 8, 8, 2U, t35, 7, t3, 1);
    t21 = (t0 + 2864);
    xsi_vlogvar_wait_assign_value(t21, t6, 0, 0, 8, 0LL);
    xsi_set_current_line(122, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 3024);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 1, 0LL);
    goto LAB52;

LAB36:    xsi_set_current_line(125, ng0);

LAB59:    xsi_set_current_line(126, ng0);
    t3 = ((char*)((ng3)));
    t4 = (t0 + 2224);
    xsi_vlogvar_wait_assign_value(t4, t3, 0, 0, 1, 0LL);
    xsi_set_current_line(127, ng0);
    t2 = (t0 + 2544);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng1)));
    memset(t6, 0, 8);
    xsi_vlog_unsigned_add(t6, 11, t4, 11, t5, 11);
    t7 = (t0 + 2544);
    xsi_vlogvar_wait_assign_value(t7, t6, 0, 0, 11, 0LL);
    xsi_set_current_line(128, ng0);
    t2 = (t0 + 1504U);
    t3 = *((char **)t2);
    t2 = (t0 + 2864);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    memset(t35, 0, 8);
    t7 = (t35 + 4);
    t8 = (t5 + 4);
    t9 = *((unsigned int *)t5);
    t10 = (t9 >> 0);
    *((unsigned int *)t35) = t10;
    t11 = *((unsigned int *)t8);
    t12 = (t11 >> 0);
    *((unsigned int *)t7) = t12;
    t13 = *((unsigned int *)t35);
    *((unsigned int *)t35) = (t13 & 127U);
    t14 = *((unsigned int *)t7);
    *((unsigned int *)t7) = (t14 & 127U);
    xsi_vlogtype_concat(t6, 8, 8, 2U, t35, 7, t3, 1);
    t21 = (t0 + 2864);
    xsi_vlogvar_wait_assign_value(t21, t6, 0, 0, 8, 0LL);
    xsi_set_current_line(129, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 3024);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 1, 0LL);
    goto LAB52;

LAB38:    xsi_set_current_line(133, ng0);

LAB60:    xsi_set_current_line(134, ng0);
    t3 = ((char*)((ng3)));
    t4 = (t0 + 2224);
    xsi_vlogvar_wait_assign_value(t4, t3, 0, 0, 1, 0LL);
    xsi_set_current_line(135, ng0);
    t2 = (t0 + 2544);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng1)));
    memset(t6, 0, 8);
    xsi_vlog_unsigned_add(t6, 11, t4, 11, t5, 11);
    t7 = (t0 + 2544);
    xsi_vlogvar_wait_assign_value(t7, t6, 0, 0, 11, 0LL);
    xsi_set_current_line(136, ng0);
    t2 = (t0 + 1504U);
    t3 = *((char **)t2);
    t2 = (t0 + 2864);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    memset(t35, 0, 8);
    t7 = (t35 + 4);
    t8 = (t5 + 4);
    t9 = *((unsigned int *)t5);
    t10 = (t9 >> 0);
    *((unsigned int *)t35) = t10;
    t11 = *((unsigned int *)t8);
    t12 = (t11 >> 0);
    *((unsigned int *)t7) = t12;
    t13 = *((unsigned int *)t35);
    *((unsigned int *)t35) = (t13 & 127U);
    t14 = *((unsigned int *)t7);
    *((unsigned int *)t7) = (t14 & 127U);
    xsi_vlogtype_concat(t6, 8, 8, 2U, t35, 7, t3, 1);
    t21 = (t0 + 2864);
    xsi_vlogvar_wait_assign_value(t21, t6, 0, 0, 8, 0LL);
    xsi_set_current_line(137, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 3024);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 1, 0LL);
    goto LAB52;

LAB40:    xsi_set_current_line(140, ng0);

LAB61:    xsi_set_current_line(141, ng0);
    t3 = ((char*)((ng3)));
    t4 = (t0 + 2224);
    xsi_vlogvar_wait_assign_value(t4, t3, 0, 0, 1, 0LL);
    xsi_set_current_line(142, ng0);
    t2 = (t0 + 2544);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng1)));
    memset(t6, 0, 8);
    xsi_vlog_unsigned_add(t6, 11, t4, 11, t5, 11);
    t7 = (t0 + 2544);
    xsi_vlogvar_wait_assign_value(t7, t6, 0, 0, 11, 0LL);
    xsi_set_current_line(143, ng0);
    t2 = (t0 + 1504U);
    t3 = *((char **)t2);
    t2 = (t0 + 2864);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    memset(t35, 0, 8);
    t7 = (t35 + 4);
    t8 = (t5 + 4);
    t9 = *((unsigned int *)t5);
    t10 = (t9 >> 0);
    *((unsigned int *)t35) = t10;
    t11 = *((unsigned int *)t8);
    t12 = (t11 >> 0);
    *((unsigned int *)t7) = t12;
    t13 = *((unsigned int *)t35);
    *((unsigned int *)t35) = (t13 & 127U);
    t14 = *((unsigned int *)t7);
    *((unsigned int *)t7) = (t14 & 127U);
    xsi_vlogtype_concat(t6, 8, 8, 2U, t35, 7, t3, 1);
    t21 = (t0 + 2864);
    xsi_vlogvar_wait_assign_value(t21, t6, 0, 0, 8, 0LL);
    xsi_set_current_line(144, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 3024);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 1, 0LL);
    goto LAB52;

LAB42:    xsi_set_current_line(148, ng0);

LAB62:    xsi_set_current_line(149, ng0);
    t3 = ((char*)((ng3)));
    t4 = (t0 + 2224);
    xsi_vlogvar_wait_assign_value(t4, t3, 0, 0, 1, 0LL);
    xsi_set_current_line(150, ng0);
    t2 = (t0 + 2544);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng1)));
    memset(t6, 0, 8);
    xsi_vlog_unsigned_add(t6, 11, t4, 11, t5, 11);
    t7 = (t0 + 2544);
    xsi_vlogvar_wait_assign_value(t7, t6, 0, 0, 11, 0LL);
    xsi_set_current_line(151, ng0);
    t2 = (t0 + 1504U);
    t3 = *((char **)t2);
    t2 = (t0 + 2864);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    memset(t35, 0, 8);
    t7 = (t35 + 4);
    t8 = (t5 + 4);
    t9 = *((unsigned int *)t5);
    t10 = (t9 >> 0);
    *((unsigned int *)t35) = t10;
    t11 = *((unsigned int *)t8);
    t12 = (t11 >> 0);
    *((unsigned int *)t7) = t12;
    t13 = *((unsigned int *)t35);
    *((unsigned int *)t35) = (t13 & 127U);
    t14 = *((unsigned int *)t7);
    *((unsigned int *)t7) = (t14 & 127U);
    xsi_vlogtype_concat(t6, 8, 8, 2U, t35, 7, t3, 1);
    t21 = (t0 + 2864);
    xsi_vlogvar_wait_assign_value(t21, t6, 0, 0, 8, 0LL);
    xsi_set_current_line(152, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 3024);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 1, 0LL);
    goto LAB52;

LAB44:    xsi_set_current_line(156, ng0);

LAB63:    xsi_set_current_line(157, ng0);
    t3 = ((char*)((ng3)));
    t4 = (t0 + 2224);
    xsi_vlogvar_wait_assign_value(t4, t3, 0, 0, 1, 0LL);
    xsi_set_current_line(158, ng0);
    t2 = (t0 + 2544);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng1)));
    memset(t6, 0, 8);
    xsi_vlog_unsigned_add(t6, 11, t4, 11, t5, 11);
    t7 = (t0 + 2544);
    xsi_vlogvar_wait_assign_value(t7, t6, 0, 0, 11, 0LL);
    xsi_set_current_line(159, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 3024);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 1, 0LL);
    goto LAB52;

LAB46:    xsi_set_current_line(163, ng0);

LAB64:    xsi_set_current_line(164, ng0);
    t3 = ((char*)((ng3)));
    t4 = (t0 + 2224);
    xsi_vlogvar_wait_assign_value(t4, t3, 0, 0, 1, 0LL);
    xsi_set_current_line(165, ng0);
    t2 = (t0 + 2544);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng1)));
    memset(t6, 0, 8);
    xsi_vlog_unsigned_add(t6, 11, t4, 11, t5, 11);
    t7 = (t0 + 2544);
    xsi_vlogvar_wait_assign_value(t7, t6, 0, 0, 11, 0LL);
    xsi_set_current_line(166, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 3024);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 1, 0LL);
    goto LAB52;

LAB48:    xsi_set_current_line(169, ng0);

LAB65:    xsi_set_current_line(170, ng0);
    t3 = ((char*)((ng3)));
    t4 = (t0 + 2224);
    xsi_vlogvar_wait_assign_value(t4, t3, 0, 0, 1, 0LL);
    xsi_set_current_line(171, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 2544);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 11, 0LL);
    xsi_set_current_line(172, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 3024);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 1, 0LL);
    goto LAB52;

}


extern void work_m_00000000003265457290_2217579590_init()
{
	static char *pe[] = {(void *)Cont_37_0,(void *)Always_39_1,(void *)Always_47_2,(void *)Always_67_3};
	xsi_register_didat("work_m_00000000003265457290_2217579590", "isim/Test_CPU_isim_beh.exe.sim/work/m_00000000003265457290_2217579590.didat");
	xsi_register_executes(pe);
}
