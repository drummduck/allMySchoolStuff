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
static const char *ng0 = "//wannsee/users/u0687930/My Documents/ECE 3710/Processor with control/XMenCPU/signextend.v";
static unsigned int ng1[] = {128U, 1U};
static int ng2[] = {3, 0};
static int ng3[] = {0, 0};
static int ng4[] = {12, 0};
static int ng5[] = {15, 0};
static int ng6[] = {4, 0};
static unsigned int ng7[] = {130U, 1U};
static int ng8[] = {7, 0};
static int ng9[] = {8, 0};



static void Always_33_0(char *t0)
{
    char t7[8];
    char t18[8];
    char t19[8];
    char t20[8];
    char t43[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    int t6;
    char *t8;
    char *t9;
    char *t10;
    unsigned int t11;
    unsigned int t12;
    unsigned int t13;
    unsigned int t14;
    unsigned int t15;
    unsigned int t16;
    char *t17;
    char *t21;
    char *t22;
    char *t23;
    char *t24;
    char *t25;
    char *t26;
    unsigned int t27;
    int t28;
    char *t29;
    unsigned int t30;
    int t31;
    int t32;
    char *t33;
    unsigned int t34;
    int t35;
    int t36;
    unsigned int t37;
    int t38;
    unsigned int t39;
    unsigned int t40;
    int t41;
    int t42;

LAB0:    t1 = (t0 + 2800U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(33, ng0);
    t2 = (t0 + 3120);
    *((int *)t2) = 1;
    t3 = (t0 + 2832);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(34, ng0);

LAB5:    xsi_set_current_line(35, ng0);
    t4 = (t0 + 1320U);
    t5 = *((char **)t4);

LAB6:    t4 = ((char*)((ng1)));
    t6 = xsi_vlog_unsigned_case_zcompare(t5, 8, t4, 8);
    if (t6 == 1)
        goto LAB7;

LAB8:    t2 = ((char*)((ng7)));
    t6 = xsi_vlog_unsigned_case_zcompare(t5, 8, t2, 8);
    if (t6 == 1)
        goto LAB9;

LAB10:
LAB12:
LAB11:    xsi_set_current_line(47, ng0);

LAB24:    xsi_set_current_line(48, ng0);
    t2 = (t0 + 1480U);
    t3 = *((char **)t2);
    memset(t7, 0, 8);
    t2 = (t7 + 4);
    t4 = (t3 + 4);
    t11 = *((unsigned int *)t3);
    t12 = (t11 >> 0);
    *((unsigned int *)t7) = t12;
    t13 = *((unsigned int *)t4);
    t14 = (t13 >> 0);
    *((unsigned int *)t2) = t14;
    t15 = *((unsigned int *)t7);
    *((unsigned int *)t7) = (t15 & 15U);
    t16 = *((unsigned int *)t2);
    *((unsigned int *)t2) = (t16 & 15U);
    t8 = (t0 + 1880);
    t9 = (t0 + 1880);
    t10 = (t9 + 72U);
    t17 = *((char **)t10);
    t21 = ((char*)((ng2)));
    t22 = ((char*)((ng3)));
    xsi_vlog_convert_partindices(t18, t19, t20, ((int*)(t17)), 2, t21, 32, 1, t22, 32, 1);
    t23 = (t18 + 4);
    t27 = *((unsigned int *)t23);
    t6 = (!(t27));
    t24 = (t19 + 4);
    t30 = *((unsigned int *)t24);
    t28 = (!(t30));
    t31 = (t6 && t28);
    t25 = (t20 + 4);
    t34 = *((unsigned int *)t25);
    t32 = (!(t34));
    t35 = (t31 && t32);
    if (t35 == 1)
        goto LAB25;

LAB26:    xsi_set_current_line(49, ng0);
    t2 = (t0 + 1320U);
    t3 = *((char **)t2);
    memset(t7, 0, 8);
    t2 = (t7 + 4);
    t4 = (t3 + 4);
    t11 = *((unsigned int *)t3);
    t12 = (t11 >> 0);
    *((unsigned int *)t7) = t12;
    t13 = *((unsigned int *)t4);
    t14 = (t13 >> 0);
    *((unsigned int *)t2) = t14;
    t15 = *((unsigned int *)t7);
    *((unsigned int *)t7) = (t15 & 15U);
    t16 = *((unsigned int *)t2);
    *((unsigned int *)t2) = (t16 & 15U);
    t8 = (t0 + 1880);
    t9 = (t0 + 1880);
    t10 = (t9 + 72U);
    t17 = *((char **)t10);
    t21 = ((char*)((ng8)));
    t22 = ((char*)((ng6)));
    xsi_vlog_convert_partindices(t18, t19, t20, ((int*)(t17)), 2, t21, 32, 1, t22, 32, 1);
    t23 = (t18 + 4);
    t27 = *((unsigned int *)t23);
    t6 = (!(t27));
    t24 = (t19 + 4);
    t30 = *((unsigned int *)t24);
    t28 = (!(t30));
    t31 = (t6 && t28);
    t25 = (t20 + 4);
    t34 = *((unsigned int *)t25);
    t32 = (!(t34));
    t35 = (t31 && t32);
    if (t35 == 1)
        goto LAB27;

LAB28:    xsi_set_current_line(50, ng0);
    t2 = ((char*)((ng9)));
    t3 = (t0 + 1320U);
    t4 = *((char **)t3);
    memset(t18, 0, 8);
    t3 = (t18 + 4);
    t8 = (t4 + 4);
    t11 = *((unsigned int *)t4);
    t12 = (t11 >> 3);
    t13 = (t12 & 1);
    *((unsigned int *)t18) = t13;
    t14 = *((unsigned int *)t8);
    t15 = (t14 >> 3);
    t16 = (t15 & 1);
    *((unsigned int *)t3) = t16;
    xsi_vlog_mul_concat(t7, 8, 1, t2, 1U, t18, 1);
    t9 = (t0 + 1880);
    t10 = (t0 + 1880);
    t17 = (t10 + 72U);
    t21 = *((char **)t17);
    t22 = ((char*)((ng5)));
    t23 = ((char*)((ng9)));
    xsi_vlog_convert_partindices(t19, t20, t43, ((int*)(t21)), 2, t22, 32, 1, t23, 32, 1);
    t24 = (t19 + 4);
    t27 = *((unsigned int *)t24);
    t6 = (!(t27));
    t25 = (t20 + 4);
    t30 = *((unsigned int *)t25);
    t28 = (!(t30));
    t31 = (t6 && t28);
    t26 = (t43 + 4);
    t34 = *((unsigned int *)t26);
    t32 = (!(t34));
    t35 = (t31 && t32);
    if (t35 == 1)
        goto LAB29;

LAB30:
LAB13:    goto LAB2;

LAB7:    xsi_set_current_line(37, ng0);

LAB14:    xsi_set_current_line(38, ng0);
    t8 = (t0 + 1480U);
    t9 = *((char **)t8);
    memset(t7, 0, 8);
    t8 = (t7 + 4);
    t10 = (t9 + 4);
    t11 = *((unsigned int *)t9);
    t12 = (t11 >> 0);
    *((unsigned int *)t7) = t12;
    t13 = *((unsigned int *)t10);
    t14 = (t13 >> 0);
    *((unsigned int *)t8) = t14;
    t15 = *((unsigned int *)t7);
    *((unsigned int *)t7) = (t15 & 15U);
    t16 = *((unsigned int *)t8);
    *((unsigned int *)t8) = (t16 & 15U);
    t17 = (t0 + 1880);
    t21 = (t0 + 1880);
    t22 = (t21 + 72U);
    t23 = *((char **)t22);
    t24 = ((char*)((ng2)));
    t25 = ((char*)((ng3)));
    xsi_vlog_convert_partindices(t18, t19, t20, ((int*)(t23)), 2, t24, 32, 1, t25, 32, 1);
    t26 = (t18 + 4);
    t27 = *((unsigned int *)t26);
    t28 = (!(t27));
    t29 = (t19 + 4);
    t30 = *((unsigned int *)t29);
    t31 = (!(t30));
    t32 = (t28 && t31);
    t33 = (t20 + 4);
    t34 = *((unsigned int *)t33);
    t35 = (!(t34));
    t36 = (t32 && t35);
    if (t36 == 1)
        goto LAB15;

LAB16:    xsi_set_current_line(39, ng0);
    t2 = ((char*)((ng4)));
    t3 = (t0 + 1320U);
    t4 = *((char **)t3);
    memset(t18, 0, 8);
    t3 = (t18 + 4);
    t8 = (t4 + 4);
    t11 = *((unsigned int *)t4);
    t12 = (t11 >> 0);
    t13 = (t12 & 1);
    *((unsigned int *)t18) = t13;
    t14 = *((unsigned int *)t8);
    t15 = (t14 >> 0);
    t16 = (t15 & 1);
    *((unsigned int *)t3) = t16;
    xsi_vlog_mul_concat(t7, 12, 1, t2, 1U, t18, 1);
    t9 = (t0 + 1880);
    t10 = (t0 + 1880);
    t17 = (t10 + 72U);
    t21 = *((char **)t17);
    t22 = ((char*)((ng5)));
    t23 = ((char*)((ng6)));
    xsi_vlog_convert_partindices(t19, t20, t43, ((int*)(t21)), 2, t22, 32, 1, t23, 32, 1);
    t24 = (t19 + 4);
    t27 = *((unsigned int *)t24);
    t6 = (!(t27));
    t25 = (t20 + 4);
    t30 = *((unsigned int *)t25);
    t28 = (!(t30));
    t31 = (t6 && t28);
    t26 = (t43 + 4);
    t34 = *((unsigned int *)t26);
    t32 = (!(t34));
    t35 = (t31 && t32);
    if (t35 == 1)
        goto LAB17;

LAB18:    goto LAB13;

LAB9:    xsi_set_current_line(42, ng0);

LAB19:    xsi_set_current_line(43, ng0);
    t3 = (t0 + 1480U);
    t4 = *((char **)t3);
    memset(t7, 0, 8);
    t3 = (t7 + 4);
    t8 = (t4 + 4);
    t11 = *((unsigned int *)t4);
    t12 = (t11 >> 0);
    *((unsigned int *)t7) = t12;
    t13 = *((unsigned int *)t8);
    t14 = (t13 >> 0);
    *((unsigned int *)t3) = t14;
    t15 = *((unsigned int *)t7);
    *((unsigned int *)t7) = (t15 & 15U);
    t16 = *((unsigned int *)t3);
    *((unsigned int *)t3) = (t16 & 15U);
    t9 = (t0 + 1880);
    t10 = (t0 + 1880);
    t17 = (t10 + 72U);
    t21 = *((char **)t17);
    t22 = ((char*)((ng2)));
    t23 = ((char*)((ng3)));
    xsi_vlog_convert_partindices(t18, t19, t20, ((int*)(t21)), 2, t22, 32, 1, t23, 32, 1);
    t24 = (t18 + 4);
    t27 = *((unsigned int *)t24);
    t28 = (!(t27));
    t25 = (t19 + 4);
    t30 = *((unsigned int *)t25);
    t31 = (!(t30));
    t32 = (t28 && t31);
    t26 = (t20 + 4);
    t34 = *((unsigned int *)t26);
    t35 = (!(t34));
    t36 = (t32 && t35);
    if (t36 == 1)
        goto LAB20;

LAB21:    xsi_set_current_line(44, ng0);
    t2 = ((char*)((ng4)));
    t3 = (t0 + 1320U);
    t4 = *((char **)t3);
    memset(t18, 0, 8);
    t3 = (t18 + 4);
    t8 = (t4 + 4);
    t11 = *((unsigned int *)t4);
    t12 = (t11 >> 0);
    t13 = (t12 & 1);
    *((unsigned int *)t18) = t13;
    t14 = *((unsigned int *)t8);
    t15 = (t14 >> 0);
    t16 = (t15 & 1);
    *((unsigned int *)t3) = t16;
    xsi_vlog_mul_concat(t7, 12, 1, t2, 1U, t18, 1);
    t9 = (t0 + 1880);
    t10 = (t0 + 1880);
    t17 = (t10 + 72U);
    t21 = *((char **)t17);
    t22 = ((char*)((ng5)));
    t23 = ((char*)((ng6)));
    xsi_vlog_convert_partindices(t19, t20, t43, ((int*)(t21)), 2, t22, 32, 1, t23, 32, 1);
    t24 = (t19 + 4);
    t27 = *((unsigned int *)t24);
    t6 = (!(t27));
    t25 = (t20 + 4);
    t30 = *((unsigned int *)t25);
    t28 = (!(t30));
    t31 = (t6 && t28);
    t26 = (t43 + 4);
    t34 = *((unsigned int *)t26);
    t32 = (!(t34));
    t35 = (t31 && t32);
    if (t35 == 1)
        goto LAB22;

LAB23:    goto LAB13;

LAB15:    t37 = *((unsigned int *)t20);
    t38 = (t37 + 0);
    t39 = *((unsigned int *)t18);
    t40 = *((unsigned int *)t19);
    t41 = (t39 - t40);
    t42 = (t41 + 1);
    xsi_vlogvar_assign_value(t17, t7, t38, *((unsigned int *)t19), t42);
    goto LAB16;

LAB17:    t37 = *((unsigned int *)t43);
    t36 = (t37 + 0);
    t39 = *((unsigned int *)t19);
    t40 = *((unsigned int *)t20);
    t38 = (t39 - t40);
    t41 = (t38 + 1);
    xsi_vlogvar_assign_value(t9, t7, t36, *((unsigned int *)t20), t41);
    goto LAB18;

LAB20:    t37 = *((unsigned int *)t20);
    t38 = (t37 + 0);
    t39 = *((unsigned int *)t18);
    t40 = *((unsigned int *)t19);
    t41 = (t39 - t40);
    t42 = (t41 + 1);
    xsi_vlogvar_assign_value(t9, t7, t38, *((unsigned int *)t19), t42);
    goto LAB21;

LAB22:    t37 = *((unsigned int *)t43);
    t36 = (t37 + 0);
    t39 = *((unsigned int *)t19);
    t40 = *((unsigned int *)t20);
    t38 = (t39 - t40);
    t41 = (t38 + 1);
    xsi_vlogvar_assign_value(t9, t7, t36, *((unsigned int *)t20), t41);
    goto LAB23;

LAB25:    t37 = *((unsigned int *)t20);
    t36 = (t37 + 0);
    t39 = *((unsigned int *)t18);
    t40 = *((unsigned int *)t19);
    t38 = (t39 - t40);
    t41 = (t38 + 1);
    xsi_vlogvar_assign_value(t8, t7, t36, *((unsigned int *)t19), t41);
    goto LAB26;

LAB27:    t37 = *((unsigned int *)t20);
    t36 = (t37 + 0);
    t39 = *((unsigned int *)t18);
    t40 = *((unsigned int *)t19);
    t38 = (t39 - t40);
    t41 = (t38 + 1);
    xsi_vlogvar_assign_value(t8, t7, t36, *((unsigned int *)t19), t41);
    goto LAB28;

LAB29:    t37 = *((unsigned int *)t43);
    t36 = (t37 + 0);
    t39 = *((unsigned int *)t19);
    t40 = *((unsigned int *)t20);
    t38 = (t39 - t40);
    t41 = (t38 + 1);
    xsi_vlogvar_assign_value(t9, t7, t36, *((unsigned int *)t20), t41);
    goto LAB30;

}


extern void work_m_00000000002691770471_1900080952_init()
{
	static char *pe[] = {(void *)Always_33_0};
	xsi_register_didat("work_m_00000000002691770471_1900080952", "isim/Test_CPU_isim_beh.exe.sim/work/m_00000000002691770471_1900080952.didat");
	xsi_register_executes(pe);
}
