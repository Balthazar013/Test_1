/* This file is generated automatically. DO NOT EDIT!!
 * 
 * EB tresos AutoCore OS 4.5.69 PA/MPC574XP
 * (Build 20140813)
 * 
 * (c) 1998-2018 Elektrobit Automotive GmbH
 * Am Wolfsmantel 46
 * 91058 Erlangen
 * GERMANY
 * 
 * http://www.automotive.elektrobit.com
 * 
 * Date         : 5/22/18 4:05 PM           !!!IGNORE-LINE!!!
 * 
 * The name of the optimized lib will be : OS_lib_02132fdba8
 */

#ifndef OS_LIBCFG_H
#define OS_LIBCFG_H
#ifdef __cplusplus
extern "C" {
#endif

#define OS_GENERATION_ID_OS_LIBCONF_H 0x893c8559UL

#define OS_AUTOSAROS_VER 4

#define OS_AUTOSAROS_REV 5

#define OS_AUTOSAROS_CORE_BUILD 20140813

#define OS_AUTOSAROS_ARCH_BUILD 20140813

#define OS_USE_OPTIMIZATION_OPTIONS 1
#if OS_USE_OPTIMIZATION_OPTIONS
#define OS_EXCLUDE_EXTRA_CHECK 1
#define OS_EXCLUDE_PROTECTION 1
#define OS_EXCLUDE_PRETASKHOOK 1
#define OS_EXCLUDE_POSTTASKHOOK 1
#define OS_EXCLUDE_STARTUPHOOK 1
#define OS_EXCLUDE_PREISRHOOK 1
#define OS_EXCLUDE_POSTISRHOOK 1
#define OS_EXCLUDE_TIMINGPROTECTION 1
#define OS_EXCLUDE_APPLICATIONS 1
#define OS_EXCLUDE_RATEMONITORS 1
#define OS_EXCLUDE_RESOURCEONISR 1
#define OS_EXCLUDE_PARAMETERACCESS 1
#define OS_EXCLUDE_ERRORHOOK_APP 1
#define OS_EXCLUDE_MULTIPLE_ACTIVATIONS 1
#define OS_EXCLUDE_HW_FP 1
#define OS_EXCLUDE_ERRORHANDLINGFORVOIDAPI 1
#define OS_EXCLUDE_INTSENABLEDCHECK 1
#define OS_EXCLUDE_KILLALARM 1
#define OS_LCFG_TASKQUEUE_CC1 1
#define OS_LCFG_TASKQUEUE_SMALL 0
#endif

#ifdef __cplusplus
}
#endif
#endif  /* OS_LIBCFG_H */
