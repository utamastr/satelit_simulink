/* Include files */

#include "blascompat32.h"
#include "SatDinModel_3_TES_RW_OL_2_sfun.h"
#include "c2_SatDinModel_3_TES_RW_OL_2.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "SatDinModel_3_TES_RW_OL_2_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
static const char * c2_debug_family_names[18] = { "temp", "tu", "year",
  "leapyrs", "days", "lmonth", "dayofyr", "i", "inttemp", "mon", "day", "hr",
  "min", "sec", "nargin", "nargout", "jd", "y" };

static const char * c2_b_debug_family_names[5] = { "nargin", "nargout", "x",
  "xv", "y" };

/* Function Declarations */
static void initialize_c2_SatDinModel_3_TES_RW_OL_2
  (SFc2_SatDinModel_3_TES_RW_OL_2InstanceStruct *chartInstance);
static void initialize_params_c2_SatDinModel_3_TES_RW_OL_2
  (SFc2_SatDinModel_3_TES_RW_OL_2InstanceStruct *chartInstance);
static void enable_c2_SatDinModel_3_TES_RW_OL_2
  (SFc2_SatDinModel_3_TES_RW_OL_2InstanceStruct *chartInstance);
static void disable_c2_SatDinModel_3_TES_RW_OL_2
  (SFc2_SatDinModel_3_TES_RW_OL_2InstanceStruct *chartInstance);
static void c2_update_debugger_state_c2_SatDinModel_3_TES_RW_OL_2
  (SFc2_SatDinModel_3_TES_RW_OL_2InstanceStruct *chartInstance);
static const mxArray *get_sim_state_c2_SatDinModel_3_TES_RW_OL_2
  (SFc2_SatDinModel_3_TES_RW_OL_2InstanceStruct *chartInstance);
static void set_sim_state_c2_SatDinModel_3_TES_RW_OL_2
  (SFc2_SatDinModel_3_TES_RW_OL_2InstanceStruct *chartInstance, const mxArray
   *c2_st);
static void finalize_c2_SatDinModel_3_TES_RW_OL_2
  (SFc2_SatDinModel_3_TES_RW_OL_2InstanceStruct *chartInstance);
static void sf_c2_SatDinModel_3_TES_RW_OL_2
  (SFc2_SatDinModel_3_TES_RW_OL_2InstanceStruct *chartInstance);
static void c2_chartstep_c2_SatDinModel_3_TES_RW_OL_2
  (SFc2_SatDinModel_3_TES_RW_OL_2InstanceStruct *chartInstance);
static void initSimStructsc2_SatDinModel_3_TES_RW_OL_2
  (SFc2_SatDinModel_3_TES_RW_OL_2InstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber);
static const mxArray *c2_sf_marshallOut(void *chartInstanceVoid, void *c2_inData);
static void c2_emlrt_marshallIn(SFc2_SatDinModel_3_TES_RW_OL_2InstanceStruct
  *chartInstance, const mxArray *c2_y, const char_T *c2_identifier, real_T
  c2_b_y[6]);
static void c2_b_emlrt_marshallIn(SFc2_SatDinModel_3_TES_RW_OL_2InstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_y[6]);
static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static real_T c2_c_emlrt_marshallIn(SFc2_SatDinModel_3_TES_RW_OL_2InstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_c_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static void c2_d_emlrt_marshallIn(SFc2_SatDinModel_3_TES_RW_OL_2InstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_y[12]);
static void c2_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_d_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static int32_T c2_e_emlrt_marshallIn
  (SFc2_SatDinModel_3_TES_RW_OL_2InstanceStruct *chartInstance, const mxArray
   *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static uint8_T c2_f_emlrt_marshallIn
  (SFc2_SatDinModel_3_TES_RW_OL_2InstanceStruct *chartInstance, const mxArray
   *c2_b_is_active_c2_SatDinModel_3_TES_RW_OL_2, const char_T *c2_identifier);
static uint8_T c2_g_emlrt_marshallIn
  (SFc2_SatDinModel_3_TES_RW_OL_2InstanceStruct *chartInstance, const mxArray
   *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void init_dsm_address_info(SFc2_SatDinModel_3_TES_RW_OL_2InstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c2_SatDinModel_3_TES_RW_OL_2
  (SFc2_SatDinModel_3_TES_RW_OL_2InstanceStruct *chartInstance)
{
  chartInstance->c2_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c2_is_active_c2_SatDinModel_3_TES_RW_OL_2 = 0U;
}

static void initialize_params_c2_SatDinModel_3_TES_RW_OL_2
  (SFc2_SatDinModel_3_TES_RW_OL_2InstanceStruct *chartInstance)
{
}

static void enable_c2_SatDinModel_3_TES_RW_OL_2
  (SFc2_SatDinModel_3_TES_RW_OL_2InstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c2_SatDinModel_3_TES_RW_OL_2
  (SFc2_SatDinModel_3_TES_RW_OL_2InstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c2_update_debugger_state_c2_SatDinModel_3_TES_RW_OL_2
  (SFc2_SatDinModel_3_TES_RW_OL_2InstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c2_SatDinModel_3_TES_RW_OL_2
  (SFc2_SatDinModel_3_TES_RW_OL_2InstanceStruct *chartInstance)
{
  const mxArray *c2_st;
  const mxArray *c2_y = NULL;
  int32_T c2_i0;
  real_T c2_u[6];
  const mxArray *c2_b_y = NULL;
  uint8_T c2_hoistedGlobal;
  uint8_T c2_b_u;
  const mxArray *c2_c_y = NULL;
  real_T (*c2_d_y)[6];
  c2_d_y = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S, 1);
  c2_st = NULL;
  c2_st = NULL;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_createcellarray(2));
  for (c2_i0 = 0; c2_i0 < 6; c2_i0++) {
    c2_u[c2_i0] = (*c2_d_y)[c2_i0];
  }

  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 1, 6));
  sf_mex_setcell(c2_y, 0, c2_b_y);
  c2_hoistedGlobal = chartInstance->c2_is_active_c2_SatDinModel_3_TES_RW_OL_2;
  c2_b_u = c2_hoistedGlobal;
  c2_c_y = NULL;
  sf_mex_assign(&c2_c_y, sf_mex_create("y", &c2_b_u, 3, 0U, 0U, 0U, 0));
  sf_mex_setcell(c2_y, 1, c2_c_y);
  sf_mex_assign(&c2_st, c2_y);
  return c2_st;
}

static void set_sim_state_c2_SatDinModel_3_TES_RW_OL_2
  (SFc2_SatDinModel_3_TES_RW_OL_2InstanceStruct *chartInstance, const mxArray
   *c2_st)
{
  const mxArray *c2_u;
  real_T c2_dv0[6];
  int32_T c2_i1;
  real_T (*c2_y)[6];
  c2_y = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c2_doneDoubleBufferReInit = TRUE;
  c2_u = sf_mex_dup(c2_st);
  c2_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 0)), "y",
                      c2_dv0);
  for (c2_i1 = 0; c2_i1 < 6; c2_i1++) {
    (*c2_y)[c2_i1] = c2_dv0[c2_i1];
  }

  chartInstance->c2_is_active_c2_SatDinModel_3_TES_RW_OL_2 =
    c2_f_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 1)),
    "is_active_c2_SatDinModel_3_TES_RW_OL_2");
  sf_mex_destroy(&c2_u);
  c2_update_debugger_state_c2_SatDinModel_3_TES_RW_OL_2(chartInstance);
  sf_mex_destroy(&c2_st);
}

static void finalize_c2_SatDinModel_3_TES_RW_OL_2
  (SFc2_SatDinModel_3_TES_RW_OL_2InstanceStruct *chartInstance)
{
}

static void sf_c2_SatDinModel_3_TES_RW_OL_2
  (SFc2_SatDinModel_3_TES_RW_OL_2InstanceStruct *chartInstance)
{
  int32_T c2_i2;
  real_T *c2_jd;
  real_T (*c2_y)[6];
  c2_y = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S, 1);
  c2_jd = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 0U, chartInstance->c2_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c2_jd, 0U);
  for (c2_i2 = 0; c2_i2 < 6; c2_i2++) {
    _SFD_DATA_RANGE_CHECK((*c2_y)[c2_i2], 1U);
  }

  chartInstance->c2_sfEvent = CALL_EVENT;
  c2_chartstep_c2_SatDinModel_3_TES_RW_OL_2(chartInstance);
  sf_debug_check_for_state_inconsistency
    (_SatDinModel_3_TES_RW_OL_2MachineNumber_, chartInstance->chartNumber,
     chartInstance->instanceNumber);
}

static void c2_chartstep_c2_SatDinModel_3_TES_RW_OL_2
  (SFc2_SatDinModel_3_TES_RW_OL_2InstanceStruct *chartInstance)
{
  real_T c2_hoistedGlobal;
  real_T c2_jd;
  uint32_T c2_debug_family_var_map[18];
  real_T c2_temp;
  real_T c2_tu;
  real_T c2_year;
  real_T c2_leapyrs;
  real_T c2_days;
  real_T c2_lmonth[12];
  real_T c2_dayofyr;
  real_T c2_i;
  real_T c2_inttemp;
  real_T c2_mon;
  real_T c2_day;
  real_T c2_hr;
  real_T c2_min;
  real_T c2_sec;
  real_T c2_nargin = 1.0;
  real_T c2_nargout = 1.0;
  real_T c2_y[6];
  real_T c2_A;
  real_T c2_x;
  real_T c2_b_x;
  real_T c2_c_x;
  real_T c2_d_x;
  real_T c2_e_x;
  real_T c2_a;
  real_T c2_b_y;
  real_T c2_f_x;
  real_T c2_g_x;
  real_T c2_b_a;
  real_T c2_c_y;
  real_T c2_c_a;
  real_T c2_d_y;
  real_T c2_h_x;
  real_T c2_i_x;
  real_T c2_d_a;
  real_T c2_e_y;
  int32_T c2_i3;
  static real_T c2_dv1[12] = { 31.0, 28.0, 31.0, 30.0, 31.0, 30.0, 31.0, 31.0,
    30.0, 31.0, 30.0, 31.0 };

  real_T c2_j_x;
  real_T c2_k_x;
  real_T c2_l_x;
  real_T c2_xv;
  uint32_T c2_b_debug_family_var_map[5];
  real_T c2_b_nargin = 2.0;
  real_T c2_b_nargout = 1.0;
  real_T c2_f_y;
  real_T c2_b_A;
  real_T c2_B;
  real_T c2_m_x;
  real_T c2_g_y;
  real_T c2_n_x;
  real_T c2_h_y;
  real_T c2_o_x;
  real_T c2_i_y;
  real_T c2_j_y;
  real_T c2_p_x;
  real_T c2_q_x;
  real_T c2_e_a;
  real_T c2_b;
  real_T c2_k_y;
  real_T c2_f_a;
  real_T c2_r_x;
  real_T c2_s_x;
  real_T c2_t_x;
  real_T c2_g_a;
  real_T c2_u_x;
  real_T c2_v_x;
  real_T c2_w_x;
  real_T c2_h_a;
  int32_T c2_i4;
  real_T *c2_b_jd;
  real_T (*c2_l_y)[6];
  boolean_T exitg1;
  c2_l_y = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S, 1);
  c2_b_jd = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c2_sfEvent);
  c2_hoistedGlobal = *c2_b_jd;
  c2_jd = c2_hoistedGlobal;
  sf_debug_symbol_scope_push_eml(0U, 18U, 18U, c2_debug_family_names,
    c2_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(&c2_temp, 0U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_tu, 1U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_year, 2U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_leapyrs, 3U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_days, 4U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c2_lmonth, 5U, c2_c_sf_marshallOut,
    c2_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_dayofyr, 6U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_i, 7U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_inttemp, 8U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_mon, 9U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_day, 10U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_hr, 11U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_min, 12U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_sec, 13U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_nargin, 14U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_nargout, 15U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c2_jd, 16U, c2_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(c2_y, 17U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 5);
  c2_temp = ((c2_jd - 2.4150195E+6) + 1.7210445E+6) + 14.0;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 6);
  c2_A = c2_temp;
  c2_x = c2_A;
  c2_b_x = c2_x;
  c2_c_x = c2_b_x;
  c2_tu = c2_c_x / 365.25;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 7);
  c2_d_x = c2_tu;
  c2_e_x = c2_d_x;
  c2_e_x = muDoubleScalarFloor(c2_e_x);
  c2_year = 1900.0 + c2_e_x;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 8);
  c2_a = c2_year - 1901.0;
  c2_b_y = c2_a * 0.25;
  c2_f_x = c2_b_y;
  c2_leapyrs = c2_f_x;
  c2_g_x = c2_leapyrs;
  c2_leapyrs = c2_g_x;
  c2_leapyrs = muDoubleScalarFloor(c2_leapyrs);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 10);
  c2_b_a = c2_year - 1900.0;
  c2_c_y = c2_b_a * 365.0;
  c2_days = c2_temp - (c2_c_y + c2_leapyrs);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 13);
  if (CV_EML_IF(0, 0, c2_days < 1.0)) {
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 14);
    c2_year--;
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 15);
    c2_c_a = c2_year - 1901.0;
    c2_d_y = c2_c_a * 0.25;
    c2_h_x = c2_d_y;
    c2_leapyrs = c2_h_x;
    c2_i_x = c2_leapyrs;
    c2_leapyrs = c2_i_x;
    c2_leapyrs = muDoubleScalarFloor(c2_leapyrs);
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 16);
    c2_d_a = c2_year - 1900.0;
    c2_e_y = c2_d_a * 365.0;
    c2_days = c2_temp - (c2_e_y + c2_leapyrs);
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 22);
  for (c2_i3 = 0; c2_i3 < 12; c2_i3++) {
    c2_lmonth[c2_i3] = c2_dv1[c2_i3];
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 24);
  c2_j_x = c2_days;
  c2_dayofyr = c2_j_x;
  c2_k_x = c2_dayofyr;
  c2_dayofyr = c2_k_x;
  c2_dayofyr = muDoubleScalarFloor(c2_dayofyr);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 27);
  c2_l_x = c2_year - 1900.0;
  c2_xv = 4.0;
  sf_debug_symbol_scope_push_eml(0U, 5U, 5U, c2_b_debug_family_names,
    c2_b_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(&c2_b_nargin, 0U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_b_nargout, 1U,
    c2_b_sf_marshallOut, c2_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_l_x, 2U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_xv, 3U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_f_y, 4U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 33);
  c2_b_A = c2_l_x;
  c2_B = c2_xv;
  c2_m_x = c2_b_A;
  c2_g_y = c2_B;
  c2_n_x = c2_m_x;
  c2_h_y = c2_g_y;
  c2_o_x = c2_n_x;
  c2_i_y = c2_h_y;
  c2_j_y = c2_o_x / c2_i_y;
  c2_p_x = c2_j_y;
  c2_q_x = c2_p_x;
  if (c2_q_x > 0.0) {
    c2_q_x = muDoubleScalarFloor(c2_q_x);
  } else {
    c2_q_x = muDoubleScalarCeil(c2_q_x);
  }

  c2_e_a = c2_xv;
  c2_b = c2_q_x;
  c2_k_y = c2_e_a * c2_b;
  c2_f_y = c2_l_x - c2_k_y;
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, -33);
  sf_debug_symbol_scope_pop();
  if (CV_EML_IF(0, 1, c2_f_y == 0.0)) {
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 28);
    c2_lmonth[1] = 29.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 31);
  c2_i = 1.0;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 32);
  c2_inttemp = 0.0;
  exitg1 = 0U;
  while ((exitg1 == 0U) && (c2_dayofyr > c2_inttemp +
          c2_lmonth[_SFD_EML_ARRAY_BOUNDS_CHECK("lmonth", (int32_T)
           _SFD_INTEGER_CHECK("i", c2_i), 1, 12, 1, 0) - 1])) {
    if (c2_i < 12.0) {
      CV_EML_WHILE(0, 0, TRUE);
      _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 34);
      c2_inttemp += c2_lmonth[_SFD_EML_ARRAY_BOUNDS_CHECK("lmonth", (int32_T)
        _SFD_INTEGER_CHECK("i", c2_i), 1, 12, 1, 0) - 1];
      _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 35);
      c2_i++;
      sf_mex_listen_for_ctrl_c(chartInstance->S);
    } else {
      exitg1 = 1U;
    }
  }

  CV_EML_WHILE(0, 0, FALSE);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 38);
  c2_mon = c2_i;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 39);
  c2_day = c2_dayofyr - c2_inttemp;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 42);
  c2_f_a = c2_days - c2_dayofyr;
  c2_temp = c2_f_a * 24.0;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 43);
  c2_r_x = c2_temp;
  c2_hr = c2_r_x;
  c2_s_x = c2_hr;
  c2_hr = c2_s_x;
  c2_t_x = c2_hr;
  c2_hr = c2_t_x;
  if (c2_hr > 0.0) {
    c2_hr = muDoubleScalarFloor(c2_hr);
  } else {
    c2_hr = muDoubleScalarCeil(c2_hr);
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 44);
  c2_g_a = c2_temp - c2_hr;
  c2_temp = c2_g_a * 60.0;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 45);
  c2_u_x = c2_temp;
  c2_min = c2_u_x;
  c2_v_x = c2_min;
  c2_min = c2_v_x;
  c2_w_x = c2_min;
  c2_min = c2_w_x;
  if (c2_min > 0.0) {
    c2_min = muDoubleScalarFloor(c2_min);
  } else {
    c2_min = muDoubleScalarCeil(c2_min);
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 46);
  c2_h_a = c2_temp - c2_min;
  c2_sec = c2_h_a * 60.0;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 50);
  c2_y[0] = c2_year;
  c2_y[1] = c2_mon;
  c2_y[2] = c2_day;
  c2_y[3] = c2_hr;
  c2_y[4] = c2_min;
  c2_y[5] = c2_sec;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, -50);
  sf_debug_symbol_scope_pop();
  for (c2_i4 = 0; c2_i4 < 6; c2_i4++) {
    (*c2_l_y)[c2_i4] = c2_y[c2_i4];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c2_sfEvent);
}

static void initSimStructsc2_SatDinModel_3_TES_RW_OL_2
  (SFc2_SatDinModel_3_TES_RW_OL_2InstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber)
{
  _SFD_SCRIPT_TRANSLATION(c2_chartNumber, 0U, sf_debug_get_script_id(
    "F:/PROJECTS/SimulatorSatelit_with_STEI/WORK/Rid/Satelit_Dyn_Model_3/modulo.m"));
}

static const mxArray *c2_sf_marshallOut(void *chartInstanceVoid, void *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i5;
  real_T c2_b_inData[6];
  int32_T c2_i6;
  real_T c2_u[6];
  const mxArray *c2_y = NULL;
  SFc2_SatDinModel_3_TES_RW_OL_2InstanceStruct *chartInstance;
  chartInstance = (SFc2_SatDinModel_3_TES_RW_OL_2InstanceStruct *)
    chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  for (c2_i5 = 0; c2_i5 < 6; c2_i5++) {
    c2_b_inData[c2_i5] = (*(real_T (*)[6])c2_inData)[c2_i5];
  }

  for (c2_i6 = 0; c2_i6 < 6; c2_i6++) {
    c2_u[c2_i6] = c2_b_inData[c2_i6];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 1, 6));
  sf_mex_assign(&c2_mxArrayOutData, c2_y);
  return c2_mxArrayOutData;
}

static void c2_emlrt_marshallIn(SFc2_SatDinModel_3_TES_RW_OL_2InstanceStruct
  *chartInstance, const mxArray *c2_y, const char_T *c2_identifier, real_T
  c2_b_y[6])
{
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_y), &c2_thisId, c2_b_y);
  sf_mex_destroy(&c2_y);
}

static void c2_b_emlrt_marshallIn(SFc2_SatDinModel_3_TES_RW_OL_2InstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_y[6])
{
  real_T c2_dv2[6];
  int32_T c2_i7;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), c2_dv2, 1, 0, 0U, 1, 0U, 1, 6);
  for (c2_i7 = 0; c2_i7 < 6; c2_i7++) {
    c2_y[c2_i7] = c2_dv2[c2_i7];
  }

  sf_mex_destroy(&c2_u);
}

static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_y;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_b_y[6];
  int32_T c2_i8;
  SFc2_SatDinModel_3_TES_RW_OL_2InstanceStruct *chartInstance;
  chartInstance = (SFc2_SatDinModel_3_TES_RW_OL_2InstanceStruct *)
    chartInstanceVoid;
  c2_y = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_y), &c2_thisId, c2_b_y);
  sf_mex_destroy(&c2_y);
  for (c2_i8 = 0; c2_i8 < 6; c2_i8++) {
    (*(real_T (*)[6])c2_outData)[c2_i8] = c2_b_y[c2_i8];
  }

  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  real_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_SatDinModel_3_TES_RW_OL_2InstanceStruct *chartInstance;
  chartInstance = (SFc2_SatDinModel_3_TES_RW_OL_2InstanceStruct *)
    chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(real_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 0, 0U, 0U, 0U, 0));
  sf_mex_assign(&c2_mxArrayOutData, c2_y);
  return c2_mxArrayOutData;
}

static real_T c2_c_emlrt_marshallIn(SFc2_SatDinModel_3_TES_RW_OL_2InstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  real_T c2_y;
  real_T c2_d0;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_d0, 1, 0, 0U, 0, 0U, 0);
  c2_y = c2_d0;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_nargout;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y;
  SFc2_SatDinModel_3_TES_RW_OL_2InstanceStruct *chartInstance;
  chartInstance = (SFc2_SatDinModel_3_TES_RW_OL_2InstanceStruct *)
    chartInstanceVoid;
  c2_nargout = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_nargout), &c2_thisId);
  sf_mex_destroy(&c2_nargout);
  *(real_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_c_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i9;
  real_T c2_b_inData[12];
  int32_T c2_i10;
  real_T c2_u[12];
  const mxArray *c2_y = NULL;
  SFc2_SatDinModel_3_TES_RW_OL_2InstanceStruct *chartInstance;
  chartInstance = (SFc2_SatDinModel_3_TES_RW_OL_2InstanceStruct *)
    chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  for (c2_i9 = 0; c2_i9 < 12; c2_i9++) {
    c2_b_inData[c2_i9] = (*(real_T (*)[12])c2_inData)[c2_i9];
  }

  for (c2_i10 = 0; c2_i10 < 12; c2_i10++) {
    c2_u[c2_i10] = c2_b_inData[c2_i10];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 1, 12));
  sf_mex_assign(&c2_mxArrayOutData, c2_y);
  return c2_mxArrayOutData;
}

static void c2_d_emlrt_marshallIn(SFc2_SatDinModel_3_TES_RW_OL_2InstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_y[12])
{
  real_T c2_dv3[12];
  int32_T c2_i11;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), c2_dv3, 1, 0, 0U, 1, 0U, 1, 12);
  for (c2_i11 = 0; c2_i11 < 12; c2_i11++) {
    c2_y[c2_i11] = c2_dv3[c2_i11];
  }

  sf_mex_destroy(&c2_u);
}

static void c2_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_lmonth;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y[12];
  int32_T c2_i12;
  SFc2_SatDinModel_3_TES_RW_OL_2InstanceStruct *chartInstance;
  chartInstance = (SFc2_SatDinModel_3_TES_RW_OL_2InstanceStruct *)
    chartInstanceVoid;
  c2_lmonth = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_lmonth), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_lmonth);
  for (c2_i12 = 0; c2_i12 < 12; c2_i12++) {
    (*(real_T (*)[12])c2_outData)[c2_i12] = c2_y[c2_i12];
  }

  sf_mex_destroy(&c2_mxArrayInData);
}

const mxArray *sf_c2_SatDinModel_3_TES_RW_OL_2_get_eml_resolved_functions_info
  (void)
{
  const mxArray *c2_nameCaptureInfo;
  c2_ResolvedFunctionInfo c2_info[9];
  c2_ResolvedFunctionInfo (*c2_b_info)[9];
  const mxArray *c2_m0 = NULL;
  int32_T c2_i13;
  c2_ResolvedFunctionInfo *c2_r0;
  c2_nameCaptureInfo = NULL;
  c2_nameCaptureInfo = NULL;
  c2_b_info = (c2_ResolvedFunctionInfo (*)[9])c2_info;
  (*c2_b_info)[0].context = "";
  (*c2_b_info)[0].name = "mrdivide";
  (*c2_b_info)[0].dominantType = "double";
  (*c2_b_info)[0].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  (*c2_b_info)[0].fileTimeLo = 865463040U;
  (*c2_b_info)[0].fileTimeHi = 30130885U;
  (*c2_b_info)[0].mFileTimeLo = 2321399296U;
  (*c2_b_info)[0].mFileTimeHi = 30114249U;
  (*c2_b_info)[1].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  (*c2_b_info)[1].name = "rdivide";
  (*c2_b_info)[1].dominantType = "double";
  (*c2_b_info)[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  (*c2_b_info)[1].fileTimeLo = 2236018176U;
  (*c2_b_info)[1].fileTimeHi = 30107969U;
  (*c2_b_info)[1].mFileTimeLo = 0U;
  (*c2_b_info)[1].mFileTimeHi = 0U;
  (*c2_b_info)[2].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  (*c2_b_info)[2].name = "eml_div";
  (*c2_b_info)[2].dominantType = "double";
  (*c2_b_info)[2].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  (*c2_b_info)[2].fileTimeLo = 776018176U;
  (*c2_b_info)[2].fileTimeHi = 30107969U;
  (*c2_b_info)[2].mFileTimeLo = 0U;
  (*c2_b_info)[2].mFileTimeHi = 0U;
  (*c2_b_info)[3].context = "";
  (*c2_b_info)[3].name = "floor";
  (*c2_b_info)[3].dominantType = "double";
  (*c2_b_info)[3].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m";
  (*c2_b_info)[3].fileTimeLo = 1216018176U;
  (*c2_b_info)[3].fileTimeHi = 30107969U;
  (*c2_b_info)[3].mFileTimeLo = 0U;
  (*c2_b_info)[3].mFileTimeHi = 0U;
  (*c2_b_info)[4].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m";
  (*c2_b_info)[4].name = "eml_scalar_floor";
  (*c2_b_info)[4].dominantType = "double";
  (*c2_b_info)[4].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m";
  (*c2_b_info)[4].fileTimeLo = 1056018176U;
  (*c2_b_info)[4].fileTimeHi = 30107969U;
  (*c2_b_info)[4].mFileTimeLo = 0U;
  (*c2_b_info)[4].mFileTimeHi = 0U;
  (*c2_b_info)[5].context = "";
  (*c2_b_info)[5].name = "mtimes";
  (*c2_b_info)[5].dominantType = "double";
  (*c2_b_info)[5].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  (*c2_b_info)[5].fileTimeLo = 2321399296U;
  (*c2_b_info)[5].fileTimeHi = 30114249U;
  (*c2_b_info)[5].mFileTimeLo = 0U;
  (*c2_b_info)[5].mFileTimeHi = 0U;
  (*c2_b_info)[6].context = "";
  (*c2_b_info)[6].name = "modulo";
  (*c2_b_info)[6].dominantType = "double";
  (*c2_b_info)[6].resolved =
    "[E]F:/PROJECTS/SimulatorSatelit_with_STEI/WORK/Rid/Satelit_Dyn_Model_3/modulo.m";
  (*c2_b_info)[6].fileTimeLo = 1879014962U;
  (*c2_b_info)[6].fileTimeHi = 30307092U;
  (*c2_b_info)[6].mFileTimeLo = 0U;
  (*c2_b_info)[6].mFileTimeHi = 0U;
  (*c2_b_info)[7].context =
    "[E]F:/PROJECTS/SimulatorSatelit_with_STEI/WORK/Rid/Satelit_Dyn_Model_3/modulo.m";
  (*c2_b_info)[7].name = "fix";
  (*c2_b_info)[7].dominantType = "double";
  (*c2_b_info)[7].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/fix.m";
  (*c2_b_info)[7].fileTimeLo = 1216018176U;
  (*c2_b_info)[7].fileTimeHi = 30107969U;
  (*c2_b_info)[7].mFileTimeLo = 0U;
  (*c2_b_info)[7].mFileTimeHi = 0U;
  (*c2_b_info)[8].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/fix.m";
  (*c2_b_info)[8].name = "eml_scalar_fix";
  (*c2_b_info)[8].dominantType = "double";
  (*c2_b_info)[8].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_fix.m";
  (*c2_b_info)[8].fileTimeLo = 1056018176U;
  (*c2_b_info)[8].fileTimeHi = 30107969U;
  (*c2_b_info)[8].mFileTimeLo = 0U;
  (*c2_b_info)[8].mFileTimeHi = 0U;
  sf_mex_assign(&c2_m0, sf_mex_createstruct("nameCaptureInfo", 1, 9));
  for (c2_i13 = 0; c2_i13 < 9; c2_i13++) {
    c2_r0 = &c2_info[c2_i13];
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c2_r0->context)), "context", "nameCaptureInfo",
                    c2_i13);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c2_r0->name)), "name", "nameCaptureInfo", c2_i13);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c2_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c2_i13);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c2_r0->resolved)), "resolved", "nameCaptureInfo",
                    c2_i13);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c2_i13);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c2_i13);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c2_i13);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c2_i13);
  }

  sf_mex_assign(&c2_nameCaptureInfo, c2_m0);
  return c2_nameCaptureInfo;
}

static const mxArray *c2_d_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_SatDinModel_3_TES_RW_OL_2InstanceStruct *chartInstance;
  chartInstance = (SFc2_SatDinModel_3_TES_RW_OL_2InstanceStruct *)
    chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(int32_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 6, 0U, 0U, 0U, 0));
  sf_mex_assign(&c2_mxArrayOutData, c2_y);
  return c2_mxArrayOutData;
}

static int32_T c2_e_emlrt_marshallIn
  (SFc2_SatDinModel_3_TES_RW_OL_2InstanceStruct *chartInstance, const mxArray
   *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  int32_T c2_y;
  int32_T c2_i14;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_i14, 1, 6, 0U, 0, 0U, 0);
  c2_y = c2_i14;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_sfEvent;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  int32_T c2_y;
  SFc2_SatDinModel_3_TES_RW_OL_2InstanceStruct *chartInstance;
  chartInstance = (SFc2_SatDinModel_3_TES_RW_OL_2InstanceStruct *)
    chartInstanceVoid;
  c2_b_sfEvent = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_sfEvent),
    &c2_thisId);
  sf_mex_destroy(&c2_b_sfEvent);
  *(int32_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static uint8_T c2_f_emlrt_marshallIn
  (SFc2_SatDinModel_3_TES_RW_OL_2InstanceStruct *chartInstance, const mxArray
   *c2_b_is_active_c2_SatDinModel_3_TES_RW_OL_2, const char_T *c2_identifier)
{
  uint8_T c2_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c2_b_is_active_c2_SatDinModel_3_TES_RW_OL_2), &c2_thisId);
  sf_mex_destroy(&c2_b_is_active_c2_SatDinModel_3_TES_RW_OL_2);
  return c2_y;
}

static uint8_T c2_g_emlrt_marshallIn
  (SFc2_SatDinModel_3_TES_RW_OL_2InstanceStruct *chartInstance, const mxArray
   *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  uint8_T c2_y;
  uint8_T c2_u0;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_u0, 1, 3, 0U, 0, 0U, 0);
  c2_y = c2_u0;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void init_dsm_address_info(SFc2_SatDinModel_3_TES_RW_OL_2InstanceStruct
  *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c2_SatDinModel_3_TES_RW_OL_2_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1123708106U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3066554894U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(753943814U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(9903437U);
}

mxArray *sf_c2_SatDinModel_3_TES_RW_OL_2_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(598010203U);
    pr[1] = (double)(2456930015U);
    pr[2] = (double)(3680053373U);
    pr[3] = (double)(1881930435U);
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(6);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

static const mxArray *sf_get_sim_state_info_c2_SatDinModel_3_TES_RW_OL_2(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"y\",},{M[8],M[0],T\"is_active_c2_SatDinModel_3_TES_RW_OL_2\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c2_SatDinModel_3_TES_RW_OL_2_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc2_SatDinModel_3_TES_RW_OL_2InstanceStruct *chartInstance;
    chartInstance = (SFc2_SatDinModel_3_TES_RW_OL_2InstanceStruct *)
      ((ChartInfoStruct *)(ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_SatDinModel_3_TES_RW_OL_2MachineNumber_,
           2,
           1,
           1,
           2,
           0,
           0,
           0,
           0,
           1,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           ssGetPath(S),
           (void *)S);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          init_script_number_translation
            (_SatDinModel_3_TES_RW_OL_2MachineNumber_,chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (_SatDinModel_3_TES_RW_OL_2MachineNumber_,chartInstance->chartNumber,
             1);
          sf_debug_set_chart_event_thresholds
            (_SatDinModel_3_TES_RW_OL_2MachineNumber_,
             chartInstance->chartNumber,
             0,
             0,
             0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"jd");
          _SFD_SET_DATA_PROPS(1,2,0,1,"y");
          _SFD_STATE_INFO(0,0,2);
          _SFD_CH_SUBSTATE_COUNT(0);
          _SFD_CH_SUBSTATE_DECOMP(0);
        }

        _SFD_CV_INIT_CHART(0,0,0,0);

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(0,1,2,0,0,0,1,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,1549);
        _SFD_CV_INIT_EML_IF(0,0,489,502,-1,645);
        _SFD_CV_INIT_EML_IF(0,1,965,992,-1,1033);
        _SFD_CV_INIT_EML_WHILE(0,0,1077,1130,1205);
        _SFD_CV_INIT_SCRIPT(0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(0,0,"modulo",744,-1,813);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_b_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[1];
          dimVector[0]= 6;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)
            c2_sf_marshallIn);
        }

        {
          real_T *c2_jd;
          real_T (*c2_y)[6];
          c2_y = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S, 1);
          c2_jd = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c2_jd);
          _SFD_SET_DATA_VALUE_PTR(1U, *c2_y);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration
        (_SatDinModel_3_TES_RW_OL_2MachineNumber_,chartInstance->chartNumber,
         chartInstance->instanceNumber);
    }
  }
}

static void sf_opaque_initialize_c2_SatDinModel_3_TES_RW_OL_2(void
  *chartInstanceVar)
{
  chart_debug_initialization(((SFc2_SatDinModel_3_TES_RW_OL_2InstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c2_SatDinModel_3_TES_RW_OL_2
    ((SFc2_SatDinModel_3_TES_RW_OL_2InstanceStruct*) chartInstanceVar);
  initialize_c2_SatDinModel_3_TES_RW_OL_2
    ((SFc2_SatDinModel_3_TES_RW_OL_2InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c2_SatDinModel_3_TES_RW_OL_2(void *chartInstanceVar)
{
  enable_c2_SatDinModel_3_TES_RW_OL_2
    ((SFc2_SatDinModel_3_TES_RW_OL_2InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c2_SatDinModel_3_TES_RW_OL_2(void
  *chartInstanceVar)
{
  disable_c2_SatDinModel_3_TES_RW_OL_2
    ((SFc2_SatDinModel_3_TES_RW_OL_2InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c2_SatDinModel_3_TES_RW_OL_2(void
  *chartInstanceVar)
{
  sf_c2_SatDinModel_3_TES_RW_OL_2((SFc2_SatDinModel_3_TES_RW_OL_2InstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c2_SatDinModel_3_TES_RW_OL_2
  (SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c2_SatDinModel_3_TES_RW_OL_2
    ((SFc2_SatDinModel_3_TES_RW_OL_2InstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c2_SatDinModel_3_TES_RW_OL_2();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_raw2high'.\n");
  }

  return plhs[0];
}

extern void sf_internal_set_sim_state_c2_SatDinModel_3_TES_RW_OL_2(SimStruct* S,
  const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c2_SatDinModel_3_TES_RW_OL_2();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c2_SatDinModel_3_TES_RW_OL_2
    ((SFc2_SatDinModel_3_TES_RW_OL_2InstanceStruct*)chartInfo->chartInstance,
     mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c2_SatDinModel_3_TES_RW_OL_2
  (SimStruct* S)
{
  return sf_internal_get_sim_state_c2_SatDinModel_3_TES_RW_OL_2(S);
}

static void sf_opaque_set_sim_state_c2_SatDinModel_3_TES_RW_OL_2(SimStruct* S,
  const mxArray *st)
{
  sf_internal_set_sim_state_c2_SatDinModel_3_TES_RW_OL_2(S, st);
}

static void sf_opaque_terminate_c2_SatDinModel_3_TES_RW_OL_2(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc2_SatDinModel_3_TES_RW_OL_2InstanceStruct*)
                    chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c2_SatDinModel_3_TES_RW_OL_2
      ((SFc2_SatDinModel_3_TES_RW_OL_2InstanceStruct*) chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc2_SatDinModel_3_TES_RW_OL_2
    ((SFc2_SatDinModel_3_TES_RW_OL_2InstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c2_SatDinModel_3_TES_RW_OL_2(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c2_SatDinModel_3_TES_RW_OL_2
      ((SFc2_SatDinModel_3_TES_RW_OL_2InstanceStruct*)(((ChartInfoStruct *)
         ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c2_SatDinModel_3_TES_RW_OL_2(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,"SatDinModel_3_TES_RW_OL_2",
      "SatDinModel_3_TES_RW_OL_2",2);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,"SatDinModel_3_TES_RW_OL_2",
                "SatDinModel_3_TES_RW_OL_2",2,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      "SatDinModel_3_TES_RW_OL_2","SatDinModel_3_TES_RW_OL_2",2,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,"SatDinModel_3_TES_RW_OL_2",
        "SatDinModel_3_TES_RW_OL_2",2,1);
      sf_mark_chart_reusable_outputs(S,"SatDinModel_3_TES_RW_OL_2",
        "SatDinModel_3_TES_RW_OL_2",2,1);
    }

    sf_set_rtw_dwork_info(S,"SatDinModel_3_TES_RW_OL_2",
                          "SatDinModel_3_TES_RW_OL_2",2);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(297175441U));
  ssSetChecksum1(S,(3407692429U));
  ssSetChecksum2(S,(388818246U));
  ssSetChecksum3(S,(3389265535U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c2_SatDinModel_3_TES_RW_OL_2(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "SatDinModel_3_TES_RW_OL_2",
      "SatDinModel_3_TES_RW_OL_2",2);
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c2_SatDinModel_3_TES_RW_OL_2(SimStruct *S)
{
  SFc2_SatDinModel_3_TES_RW_OL_2InstanceStruct *chartInstance;
  chartInstance = (SFc2_SatDinModel_3_TES_RW_OL_2InstanceStruct *)malloc(sizeof
    (SFc2_SatDinModel_3_TES_RW_OL_2InstanceStruct));
  memset(chartInstance, 0, sizeof(SFc2_SatDinModel_3_TES_RW_OL_2InstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c2_SatDinModel_3_TES_RW_OL_2;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c2_SatDinModel_3_TES_RW_OL_2;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c2_SatDinModel_3_TES_RW_OL_2;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c2_SatDinModel_3_TES_RW_OL_2;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c2_SatDinModel_3_TES_RW_OL_2;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c2_SatDinModel_3_TES_RW_OL_2;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c2_SatDinModel_3_TES_RW_OL_2;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c2_SatDinModel_3_TES_RW_OL_2;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c2_SatDinModel_3_TES_RW_OL_2;
  chartInstance->chartInfo.mdlStart = mdlStart_c2_SatDinModel_3_TES_RW_OL_2;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c2_SatDinModel_3_TES_RW_OL_2;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->S = S;
  ssSetUserData(S,(void *)(&(chartInstance->chartInfo)));/* register the chart instance with simstruct */
  init_dsm_address_info(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  sf_opaque_init_subchart_simstructs(chartInstance->chartInfo.chartInstance);
  chart_debug_initialization(S,1);
}

void c2_SatDinModel_3_TES_RW_OL_2_method_dispatcher(SimStruct *S, int_T method,
  void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c2_SatDinModel_3_TES_RW_OL_2(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c2_SatDinModel_3_TES_RW_OL_2(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c2_SatDinModel_3_TES_RW_OL_2(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c2_SatDinModel_3_TES_RW_OL_2_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
