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
static const char *ng0 = "C:/Users/u0837708/Desktop/Documents/CPU SimTesting/XMenCPU/memoryController.v";
static int ng1[] = {20003, 0};
static int ng2[] = {20004, 0};
static int ng3[] = {20005, 0};
static int ng4[] = {20007, 0};
static unsigned int ng5[] = {1U, 0U};
static unsigned int ng6[] = {25U, 0U};
static unsigned int ng7[] = {0U, 0U};
static int ng8[] = {6, 0};
static unsigned int ng9[] = {20006U, 0U};
static int ng10[] = {0, 0};
static unsigned int ng11[] = {2U, 0U};
static int ng12[] = {1, 0};
static unsigned int ng13[] = {4U, 0U};
static int ng14[] = {2, 0};
static unsigned int ng15[] = {8U, 0U};
static int ng16[] = {3, 0};
static unsigned int ng17[] = {16U, 0U};
static int ng18[] = {4, 0};
static unsigned int ng19[] = {32U, 0U};
static int ng20[] = {5, 0};
static unsigned int ng21[] = {126U, 0U};
static unsigned int ng22[] = {125U, 0U};
static unsigned int ng23[] = {123U, 0U};
static unsigned int ng24[] = {119U, 0U};
static unsigned int ng25[] = {111U, 0U};
static unsigned int ng26[] = {95U, 0U};



static void Always_35_0(char *t0)
{
    char t9[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    int t6;
    char *t7;
    char *t8;

LAB0:    t1 = (t0 + 3808U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(35, ng0);
    t2 = (t0 + 4376);
    *((int *)t2) = 1;
    t3 = (t0 + 3840);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(36, ng0);

LAB5:    xsi_set_current_line(37, ng0);
    t4 = (t0 + 1528U);
    t5 = *((char **)t4);

LAB6:    t4 = ((char*)((ng1)));
    t6 = xsi_vlog_unsigned_case_compare(t5, 15, t4, 32);
    if (t6 == 1)
        goto LAB7;

LAB8:    t2 = ((char*)((ng2)));
    t6 = xsi_vlog_unsigned_case_compare(t5, 15, t2, 32);
    if (t6 == 1)
        goto LAB9;

LAB10:    t2 = ((char*)((ng3)));
    t6 = xsi_vlog_unsigned_case_compare(t5, 15, t2, 32);
    if (t6 == 1)
        goto LAB11;

LAB12:    t2 = ((char*)((ng4)));
    t6 = xsi_vlog_unsigned_case_compare(t5, 15, t2, 32);
    if (t6 == 1)
        goto LAB13;

LAB14:
LAB16:
LAB15:    xsi_set_current_line(42, ng0);
    t2 = (t0 + 1848U);
    t3 = *((char **)t2);
    t2 = (t0 + 2728);
    xsi_vlogvar_assign_value(t2, t3, 0, 0, 16);

LAB17:    goto LAB2;

LAB7:    xsi_set_current_line(38, ng0);
    t7 = (t0 + 2008U);
    t8 = *((char **)t7);
    t7 = (t0 + 2728);
    xsi_vlogvar_assign_value(t7, t8, 0, 0, 16);
    goto LAB17;

LAB9:    xsi_set_current_line(39, ng0);
    t3 = (t0 + 2168U);
    t4 = *((char **)t3);
    t3 = (t0 + 2728);
    xsi_vlogvar_assign_value(t3, t4, 0, 0, 16);
    goto LAB17;

LAB11:    xsi_set_current_line(40, ng0);
    t3 = (t0 + 2328U);
    t4 = *((char **)t3);
    t3 = (t0 + 2728);
    xsi_vlogvar_assign_value(t3, t4, 0, 0, 16);
    goto LAB17;

LAB13:    xsi_set_current_line(41, ng0);
    t3 = (t0 + 2888);
    t4 = (t3 + 56U);
    t7 = *((char **)t4);
    memcpy(t9, t7, 8);
    t8 = (t0 + 2728);
    xsi_vlogvar_assign_value(t8, t9, 0, 0, 16);
    goto LAB17;

}

static void Always_45_1(char *t0)
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
    int t30;
    int t31;

LAB0:    t1 = (t0 + 4056U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(45, ng0);
    t2 = (t0 + 4392);
    *((int *)t2) = 1;
    t3 = (t0 + 4088);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(46, ng0);

LAB5:    xsi_set_current_line(47, ng0);
    t4 = (t0 + 1208U);
    t5 = *((char **)t4);
    t4 = ((char*)((ng5)));
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

LAB11:    xsi_set_current_line(51, ng0);
    t2 = (t0 + 1368U);
    t3 = *((char **)t2);
    t2 = ((char*)((ng7)));
    memset(t6, 0, 8);
    t4 = (t3 + 4);
    t5 = (t2 + 4);
    t9 = *((unsigned int *)t3);
    t10 = *((unsigned int *)t2);
    t11 = (t9 ^ t10);
    t12 = *((unsigned int *)t4);
    t13 = *((unsigned int *)t5);
    t14 = (t12 ^ t13);
    t15 = (t11 | t14);
    t16 = *((unsigned int *)t4);
    t17 = *((unsigned int *)t5);
    t18 = (t16 | t17);
    t19 = (~(t18));
    t20 = (t15 & t19);
    if (t20 != 0)
        goto LAB17;

LAB14:    if (t18 != 0)
        goto LAB16;

LAB15:    *((unsigned int *)t6) = 1;

LAB17:    t8 = (t6 + 4);
    t23 = *((unsigned int *)t8);
    t24 = (~(t23));
    t25 = *((unsigned int *)t6);
    t26 = (t25 & t24);
    t27 = (t26 != 0);
    if (t27 > 0)
        goto LAB18;

LAB19:    xsi_set_current_line(56, ng0);
    t2 = (t0 + 1528U);
    t3 = *((char **)t2);
    t2 = ((char*)((ng9)));
    memset(t6, 0, 8);
    t4 = (t3 + 4);
    t5 = (t2 + 4);
    t9 = *((unsigned int *)t3);
    t10 = *((unsigned int *)t2);
    t11 = (t9 ^ t10);
    t12 = *((unsigned int *)t4);
    t13 = *((unsigned int *)t5);
    t14 = (t12 ^ t13);
    t15 = (t11 | t14);
    t16 = *((unsigned int *)t4);
    t17 = *((unsigned int *)t5);
    t18 = (t16 | t17);
    t19 = (~(t18));
    t20 = (t15 & t19);
    if (t20 != 0)
        goto LAB27;

LAB24:    if (t18 != 0)
        goto LAB26;

LAB25:    *((unsigned int *)t6) = 1;

LAB27:    t8 = (t6 + 4);
    t23 = *((unsigned int *)t8);
    t24 = (~(t23));
    t25 = *((unsigned int *)t6);
    t26 = (t25 & t24);
    t27 = (t26 != 0);
    if (t27 > 0)
        goto LAB28;

LAB29:    xsi_set_current_line(79, ng0);

LAB84:    xsi_set_current_line(80, ng0);
    t2 = (t0 + 2888);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    t7 = (t0 + 2888);
    xsi_vlogvar_wait_assign_value(t7, t5, 0, 0, 7, 0LL);

LAB30:
LAB20:
LAB12:    goto LAB2;

LAB8:    t21 = (t6 + 4);
    *((unsigned int *)t6) = 1;
    *((unsigned int *)t21) = 1;
    goto LAB9;

LAB10:    xsi_set_current_line(48, ng0);

LAB13:    xsi_set_current_line(49, ng0);
    t28 = ((char*)((ng6)));
    t29 = (t0 + 2888);
    xsi_vlogvar_wait_assign_value(t29, t28, 0, 0, 7, 0LL);
    goto LAB12;

LAB16:    t7 = (t6 + 4);
    *((unsigned int *)t6) = 1;
    *((unsigned int *)t7) = 1;
    goto LAB17;

LAB18:    xsi_set_current_line(52, ng0);

LAB21:    xsi_set_current_line(53, ng0);
    t21 = (t0 + 2888);
    t22 = (t21 + 56U);
    t28 = *((char **)t22);
    t29 = (t0 + 2888);
    xsi_vlogvar_wait_assign_value(t29, t28, 0, 0, 7, 0LL);
    xsi_set_current_line(54, ng0);
    t2 = ((char*)((ng5)));
    t3 = (t0 + 2888);
    t4 = (t0 + 2888);
    t5 = (t4 + 72U);
    t7 = *((char **)t5);
    t8 = ((char*)((ng8)));
    xsi_vlog_generic_convert_bit_index(t6, t7, 2, t8, 32, 1);
    t21 = (t6 + 4);
    t9 = *((unsigned int *)t21);
    t30 = (!(t9));
    if (t30 == 1)
        goto LAB22;

LAB23:    goto LAB20;

LAB22:    xsi_vlogvar_wait_assign_value(t3, t2, 0, *((unsigned int *)t6), 1, 0LL);
    goto LAB23;

LAB26:    t7 = (t6 + 4);
    *((unsigned int *)t6) = 1;
    *((unsigned int *)t7) = 1;
    goto LAB27;

LAB28:    xsi_set_current_line(57, ng0);

LAB31:    xsi_set_current_line(58, ng0);
    t21 = (t0 + 2888);
    t22 = (t21 + 56U);
    t28 = *((char **)t22);
    t29 = (t0 + 2888);
    xsi_vlogvar_wait_assign_value(t29, t28, 0, 0, 7, 0LL);
    xsi_set_current_line(59, ng0);
    t2 = (t0 + 1688U);
    t3 = *((char **)t2);

LAB32:    t2 = ((char*)((ng5)));
    t30 = xsi_vlog_unsigned_case_compare(t3, 16, t2, 16);
    if (t30 == 1)
        goto LAB33;

LAB34:    t2 = ((char*)((ng11)));
    t30 = xsi_vlog_unsigned_case_compare(t3, 16, t2, 16);
    if (t30 == 1)
        goto LAB35;

LAB36:    t2 = ((char*)((ng13)));
    t30 = xsi_vlog_unsigned_case_compare(t3, 16, t2, 16);
    if (t30 == 1)
        goto LAB37;

LAB38:    t2 = ((char*)((ng15)));
    t30 = xsi_vlog_unsigned_case_compare(t3, 16, t2, 16);
    if (t30 == 1)
        goto LAB39;

LAB40:    t2 = ((char*)((ng17)));
    t30 = xsi_vlog_unsigned_case_compare(t3, 16, t2, 16);
    if (t30 == 1)
        goto LAB41;

LAB42:    t2 = ((char*)((ng19)));
    t30 = xsi_vlog_unsigned_case_compare(t3, 16, t2, 16);
    if (t30 == 1)
        goto LAB43;

LAB44:    t2 = ((char*)((ng21)));
    t30 = xsi_vlog_unsigned_case_compare(t3, 16, t2, 16);
    if (t30 == 1)
        goto LAB45;

LAB46:    t2 = ((char*)((ng22)));
    t30 = xsi_vlog_unsigned_case_compare(t3, 16, t2, 16);
    if (t30 == 1)
        goto LAB47;

LAB48:    t2 = ((char*)((ng23)));
    t30 = xsi_vlog_unsigned_case_compare(t3, 16, t2, 16);
    if (t30 == 1)
        goto LAB49;

LAB50:    t2 = ((char*)((ng24)));
    t30 = xsi_vlog_unsigned_case_compare(t3, 16, t2, 16);
    if (t30 == 1)
        goto LAB51;

LAB52:    t2 = ((char*)((ng25)));
    t30 = xsi_vlog_unsigned_case_compare(t3, 16, t2, 16);
    if (t30 == 1)
        goto LAB53;

LAB54:    t2 = ((char*)((ng26)));
    t30 = xsi_vlog_unsigned_case_compare(t3, 16, t2, 16);
    if (t30 == 1)
        goto LAB55;

LAB56:
LAB58:
LAB57:    xsi_set_current_line(75, ng0);
    t2 = (t0 + 2888);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    t7 = (t0 + 2888);
    xsi_vlogvar_wait_assign_value(t7, t5, 0, 0, 7, 0LL);

LAB59:    goto LAB30;

LAB33:    xsi_set_current_line(61, ng0);
    t4 = ((char*)((ng5)));
    t5 = (t0 + 2888);
    t7 = (t0 + 2888);
    t8 = (t7 + 72U);
    t21 = *((char **)t8);
    t22 = ((char*)((ng10)));
    xsi_vlog_generic_convert_bit_index(t6, t21, 2, t22, 32, 1);
    t28 = (t6 + 4);
    t9 = *((unsigned int *)t28);
    t31 = (!(t9));
    if (t31 == 1)
        goto LAB60;

LAB61:    goto LAB59;

LAB35:    xsi_set_current_line(62, ng0);
    t4 = ((char*)((ng5)));
    t5 = (t0 + 2888);
    t7 = (t0 + 2888);
    t8 = (t7 + 72U);
    t21 = *((char **)t8);
    t22 = ((char*)((ng12)));
    xsi_vlog_generic_convert_bit_index(t6, t21, 2, t22, 32, 1);
    t28 = (t6 + 4);
    t9 = *((unsigned int *)t28);
    t31 = (!(t9));
    if (t31 == 1)
        goto LAB62;

LAB63:    goto LAB59;

LAB37:    xsi_set_current_line(63, ng0);
    t4 = ((char*)((ng5)));
    t5 = (t0 + 2888);
    t7 = (t0 + 2888);
    t8 = (t7 + 72U);
    t21 = *((char **)t8);
    t22 = ((char*)((ng14)));
    xsi_vlog_generic_convert_bit_index(t6, t21, 2, t22, 32, 1);
    t28 = (t6 + 4);
    t9 = *((unsigned int *)t28);
    t31 = (!(t9));
    if (t31 == 1)
        goto LAB64;

LAB65:    goto LAB59;

LAB39:    xsi_set_current_line(64, ng0);
    t4 = ((char*)((ng5)));
    t5 = (t0 + 2888);
    t7 = (t0 + 2888);
    t8 = (t7 + 72U);
    t21 = *((char **)t8);
    t22 = ((char*)((ng16)));
    xsi_vlog_generic_convert_bit_index(t6, t21, 2, t22, 32, 1);
    t28 = (t6 + 4);
    t9 = *((unsigned int *)t28);
    t31 = (!(t9));
    if (t31 == 1)
        goto LAB66;

LAB67:    goto LAB59;

LAB41:    xsi_set_current_line(65, ng0);
    t4 = ((char*)((ng5)));
    t5 = (t0 + 2888);
    t7 = (t0 + 2888);
    t8 = (t7 + 72U);
    t21 = *((char **)t8);
    t22 = ((char*)((ng18)));
    xsi_vlog_generic_convert_bit_index(t6, t21, 2, t22, 32, 1);
    t28 = (t6 + 4);
    t9 = *((unsigned int *)t28);
    t31 = (!(t9));
    if (t31 == 1)
        goto LAB68;

LAB69:    goto LAB59;

LAB43:    xsi_set_current_line(66, ng0);
    t4 = ((char*)((ng5)));
    t5 = (t0 + 2888);
    t7 = (t0 + 2888);
    t8 = (t7 + 72U);
    t21 = *((char **)t8);
    t22 = ((char*)((ng20)));
    xsi_vlog_generic_convert_bit_index(t6, t21, 2, t22, 32, 1);
    t28 = (t6 + 4);
    t9 = *((unsigned int *)t28);
    t31 = (!(t9));
    if (t31 == 1)
        goto LAB70;

LAB71:    goto LAB59;

LAB45:    xsi_set_current_line(69, ng0);
    t4 = ((char*)((ng7)));
    t5 = (t0 + 2888);
    t7 = (t0 + 2888);
    t8 = (t7 + 72U);
    t21 = *((char **)t8);
    t22 = ((char*)((ng10)));
    xsi_vlog_generic_convert_bit_index(t6, t21, 2, t22, 32, 1);
    t28 = (t6 + 4);
    t9 = *((unsigned int *)t28);
    t31 = (!(t9));
    if (t31 == 1)
        goto LAB72;

LAB73:    goto LAB59;

LAB47:    xsi_set_current_line(70, ng0);
    t4 = ((char*)((ng7)));
    t5 = (t0 + 2888);
    t7 = (t0 + 2888);
    t8 = (t7 + 72U);
    t21 = *((char **)t8);
    t22 = ((char*)((ng12)));
    xsi_vlog_generic_convert_bit_index(t6, t21, 2, t22, 32, 1);
    t28 = (t6 + 4);
    t9 = *((unsigned int *)t28);
    t31 = (!(t9));
    if (t31 == 1)
        goto LAB74;

LAB75:    goto LAB59;

LAB49:    xsi_set_current_line(71, ng0);
    t4 = ((char*)((ng7)));
    t5 = (t0 + 2888);
    t7 = (t0 + 2888);
    t8 = (t7 + 72U);
    t21 = *((char **)t8);
    t22 = ((char*)((ng14)));
    xsi_vlog_generic_convert_bit_index(t6, t21, 2, t22, 32, 1);
    t28 = (t6 + 4);
    t9 = *((unsigned int *)t28);
    t31 = (!(t9));
    if (t31 == 1)
        goto LAB76;

LAB77:    goto LAB59;

LAB51:    xsi_set_current_line(72, ng0);
    t4 = ((char*)((ng7)));
    t5 = (t0 + 2888);
    t7 = (t0 + 2888);
    t8 = (t7 + 72U);
    t21 = *((char **)t8);
    t22 = ((char*)((ng16)));
    xsi_vlog_generic_convert_bit_index(t6, t21, 2, t22, 32, 1);
    t28 = (t6 + 4);
    t9 = *((unsigned int *)t28);
    t31 = (!(t9));
    if (t31 == 1)
        goto LAB78;

LAB79:    goto LAB59;

LAB53:    xsi_set_current_line(73, ng0);
    t4 = ((char*)((ng7)));
    t5 = (t0 + 2888);
    t7 = (t0 + 2888);
    t8 = (t7 + 72U);
    t21 = *((char **)t8);
    t22 = ((char*)((ng18)));
    xsi_vlog_generic_convert_bit_index(t6, t21, 2, t22, 32, 1);
    t28 = (t6 + 4);
    t9 = *((unsigned int *)t28);
    t31 = (!(t9));
    if (t31 == 1)
        goto LAB80;

LAB81:    goto LAB59;

LAB55:    xsi_set_current_line(74, ng0);
    t4 = ((char*)((ng7)));
    t5 = (t0 + 2888);
    t7 = (t0 + 2888);
    t8 = (t7 + 72U);
    t21 = *((char **)t8);
    t22 = ((char*)((ng20)));
    xsi_vlog_generic_convert_bit_index(t6, t21, 2, t22, 32, 1);
    t28 = (t6 + 4);
    t9 = *((unsigned int *)t28);
    t31 = (!(t9));
    if (t31 == 1)
        goto LAB82;

LAB83:    goto LAB59;

LAB60:    xsi_vlogvar_wait_assign_value(t5, t4, 0, *((unsigned int *)t6), 1, 0LL);
    goto LAB61;

LAB62:    xsi_vlogvar_wait_assign_value(t5, t4, 0, *((unsigned int *)t6), 1, 0LL);
    goto LAB63;

LAB64:    xsi_vlogvar_wait_assign_value(t5, t4, 0, *((unsigned int *)t6), 1, 0LL);
    goto LAB65;

LAB66:    xsi_vlogvar_wait_assign_value(t5, t4, 0, *((unsigned int *)t6), 1, 0LL);
    goto LAB67;

LAB68:    xsi_vlogvar_wait_assign_value(t5, t4, 0, *((unsigned int *)t6), 1, 0LL);
    goto LAB69;

LAB70:    xsi_vlogvar_wait_assign_value(t5, t4, 0, *((unsigned int *)t6), 1, 0LL);
    goto LAB71;

LAB72:    xsi_vlogvar_wait_assign_value(t5, t4, 0, *((unsigned int *)t6), 1, 0LL);
    goto LAB73;

LAB74:    xsi_vlogvar_wait_assign_value(t5, t4, 0, *((unsigned int *)t6), 1, 0LL);
    goto LAB75;

LAB76:    xsi_vlogvar_wait_assign_value(t5, t4, 0, *((unsigned int *)t6), 1, 0LL);
    goto LAB77;

LAB78:    xsi_vlogvar_wait_assign_value(t5, t4, 0, *((unsigned int *)t6), 1, 0LL);
    goto LAB79;

LAB80:    xsi_vlogvar_wait_assign_value(t5, t4, 0, *((unsigned int *)t6), 1, 0LL);
    goto LAB81;

LAB82:    xsi_vlogvar_wait_assign_value(t5, t4, 0, *((unsigned int *)t6), 1, 0LL);
    goto LAB83;

}


extern void work_m_00000000001194395733_0403342352_init()
{
	static char *pe[] = {(void *)Always_35_0,(void *)Always_45_1};
	xsi_register_didat("work_m_00000000001194395733_0403342352", "isim/Test_CPU_isim_beh.exe.sim/work/m_00000000001194395733_0403342352.didat");
	xsi_register_executes(pe);
}
