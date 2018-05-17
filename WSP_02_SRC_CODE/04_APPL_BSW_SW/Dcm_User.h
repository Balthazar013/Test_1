#ifndef DCM_USER_H
#define DCM_USER_H

/*==================[inclusions]=============================================*/

#include <Std_Types.h>                             /* AUTOSAR standard types */

/*==================[macros]=================================================*/
#define Rte_IRead_DiagMeas_MainFunction_WspIoHwAbs_uP3V3_Voltage() (Rte_Inst_SCI_DiagMeas->DiagMeas_MainFunction_WspIoHwAbs_uP3V3_Voltage->value)

extern CONSTP2CONST(Rte_CDS_SCI_DiagMeas, RTE_CONST, RTE_CONST) Rte_Inst_SCI_DiagMeas;
extern FUNC(Std_ReturnType, RTE_APPL_CODE) NvmExt_DiagRead(uint16 Index, P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Data);


/*==================[type definitions]=======================================*/
/*==================[external constants]=====================================*/
/*==================[external data]==========================================*/


/*==================[end of file]============================================*/
#endif /* DCM_USER_H */
