/* Include files */

#include "SatDinModel_3_TES_RW_OL_sfun.h"
#include "c2_SatDinModel_3_TES_RW_OL.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
uint32_T _SatDinModel_3_TES_RW_OLMachineNumber_;
real_T _sfTime_;

/* Function Declarations */

/* Function Definitions */
void SatDinModel_3_TES_RW_OL_initializer(void)
{
}

void SatDinModel_3_TES_RW_OL_terminator(void)
{
}

/* SFunction Glue Code */
unsigned int sf_SatDinModel_3_TES_RW_OL_method_dispatcher(SimStruct
  *simstructPtr, unsigned int chartFileNumber, const char* specsCksum, int_T
  method, void *data)
{
  if (chartFileNumber==2) {
    c2_SatDinModel_3_TES_RW_OL_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  return 0;
}

unsigned int sf_SatDinModel_3_TES_RW_OL_process_check_sum_call( int nlhs,
  mxArray * plhs[], int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[20];
  if (nrhs<1 || !mxIsChar(prhs[0]) )
    return 0;

  /* Possible call to get the checksum */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"sf_get_check_sum"))
    return 0;
  plhs[0] = mxCreateDoubleMatrix( 1,4,mxREAL);
  if (nrhs>1 && mxIsChar(prhs[1])) {
    mxGetString(prhs[1], commandName,sizeof(commandName)/sizeof(char));
    commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
    if (!strcmp(commandName,"machine")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2074660033U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(333357548U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1915998728U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(784420440U);
    } else if (!strcmp(commandName,"exportedFcn")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0U);
    } else if (!strcmp(commandName,"makefile")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(4292796392U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(142747539U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(489986800U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1783922597U);
    } else if (nrhs==3 && !strcmp(commandName,"chart")) {
      unsigned int chartFileNumber;
      chartFileNumber = (unsigned int)mxGetScalar(prhs[2]);
      switch (chartFileNumber) {
       case 2:
        {
          extern void sf_c2_SatDinModel_3_TES_RW_OL_get_check_sum(mxArray *plhs[]);
          sf_c2_SatDinModel_3_TES_RW_OL_get_check_sum(plhs);
          break;
        }

       default:
        ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0.0);
      }
    } else if (!strcmp(commandName,"target")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3176360410U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1862911626U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(659157607U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1884031890U);
    } else {
      return 0;
    }
  } else {
    ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2447550303U);
    ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3727379923U);
    ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1849662006U);
    ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(4188205732U);
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_SatDinModel_3_TES_RW_OL_autoinheritance_info( int nlhs, mxArray *
  plhs[], int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[32];
  if (nrhs<2 || !mxIsChar(prhs[0]) )
    return 0;

  /* Possible call to get the autoinheritance_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_autoinheritance_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 2:
      {
        extern mxArray *sf_c2_SatDinModel_3_TES_RW_OL_get_autoinheritance_info
          (void);
        plhs[0] = sf_c2_SatDinModel_3_TES_RW_OL_get_autoinheritance_info();
        break;
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_SatDinModel_3_TES_RW_OL_get_eml_resolved_functions_info( int
  nlhs, mxArray * plhs[], int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[64];
  if (nrhs<2 || !mxIsChar(prhs[0]))
    return 0;

  /* Possible call to get the get_eml_resolved_functions_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_eml_resolved_functions_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 2:
      {
        extern const mxArray
          *sf_c2_SatDinModel_3_TES_RW_OL_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c2_SatDinModel_3_TES_RW_OL_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;

#else

  return 0;

#endif

}

void SatDinModel_3_TES_RW_OL_debug_initialize(void)
{
  _SatDinModel_3_TES_RW_OLMachineNumber_ = sf_debug_initialize_machine(
    "SatDinModel_3_TES_RW_OL","sfun",0,1,0,0,0);
  sf_debug_set_machine_event_thresholds(_SatDinModel_3_TES_RW_OLMachineNumber_,0,
    0);
  sf_debug_set_machine_data_thresholds(_SatDinModel_3_TES_RW_OLMachineNumber_,0);
}

void SatDinModel_3_TES_RW_OL_register_exported_symbols(SimStruct* S)
{
}
