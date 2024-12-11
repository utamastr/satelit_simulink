#ifndef __SatDinModel_3_TES_RW_OL_2_sfun_h__
#define __SatDinModel_3_TES_RW_OL_2_sfun_h__

/* Include files */
#define S_FUNCTION_NAME                sf_sfun
#include "sfc_sf.h"
#include "sfc_mex.h"
#include "rtwtypes.h"
#include "sfcdebug.h"
#define rtInf                          (mxGetInf())
#define rtMinusInf                     (-(mxGetInf()))
#define rtNaN                          (mxGetNaN())
#define rtIsNaN(X)                     ((int)mxIsNaN(X))
#define rtIsInf(X)                     ((int)mxIsInf(X))

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */
extern uint32_T _SatDinModel_3_TES_RW_OL_2MachineNumber_;
extern real_T _sfTime_;

/* Variable Definitions */

/* Function Declarations */
extern void SatDinModel_3_TES_RW_OL_2_initializer(void);
extern void SatDinModel_3_TES_RW_OL_2_terminator(void);

/* Function Definitions */
#endif
