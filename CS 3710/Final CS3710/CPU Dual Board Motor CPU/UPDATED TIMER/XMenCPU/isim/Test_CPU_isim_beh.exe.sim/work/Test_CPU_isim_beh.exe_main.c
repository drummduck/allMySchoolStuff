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

#include "xsi.h"

struct XSI_INFO xsi_info;



int main(int argc, char **argv)
{
    xsi_init_design(argc, argv);
    xsi_register_info(&xsi_info);

    xsi_register_min_prec_unit(-12);
    work_m_00000000002112747865_2381739659_init();
    work_m_00000000000349958838_0883194013_init();
    work_m_00000000000949543746_0273213086_init();
    work_m_00000000001525149922_3141217020_init();
    work_m_00000000000938396896_0254784918_init();
    work_m_00000000002589344328_1366144890_init();
    work_m_00000000004258065806_0753789445_init();
    work_m_00000000002691770471_1900080952_init();
    work_m_00000000000601804733_1957175458_init();
    work_m_00000000003247274001_2118084387_init();
    work_m_00000000001424220008_1395566128_init();
    work_m_00000000002319032761_3508565487_init();
    work_m_00000000003607842059_0451635433_init();
    work_m_00000000004134447467_2073120511_init();


    xsi_register_tops("work_m_00000000003607842059_0451635433");
    xsi_register_tops("work_m_00000000004134447467_2073120511");


    return xsi_run_simulation(argc, argv);

}