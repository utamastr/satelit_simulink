/* Include files */

#include "blascompat32.h"
#include "SatDinModel_3_sfun.h"
#include "c2_SatDinModel_3.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "SatDinModel_3_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
static const char *c2_debug_family_names[18] = { "temp", "tu", "year", "leapyrs",
  "days", "lmonth", "dayofyr", "i", "inttemp", "mon", "day", "hr", "min", "sec",
  "nargin", "nargout", "jd", "y" };

static const char *c2_b_debug_family_names[5] = { "nargin", "nargout", "x", "xv",
  "y" };

/* Function Declarations */
static void initialize_c2_SatDinModel_3(SFc2_SatDinModel_3InstanceStruct
  *chartInstance);
static void initialize_params_c2_SatDinModel_3(SFc2_SatDinModel_3InstanceStruct *
  chartInstance);
static void enable_c2_SatDinModel_3(SFc2_SatDinModel_3InstanceStruct
  *chartInstance);
static void disable_c2_SatDinModel_3(SFc2_SatDinModel_3InstanceStruct
  *chartInstance);
static void c2_update_debugger_state_c2_SatDinModel_3
  (SFc2_SatDinModel_3InstanceStruct *chartInstance);
static const mxArray *get_sim_state_c2_SatDinModel_3
  (SFc2_SatDinModel_3InstanceStruct *chartInstance);
static void set_sim_state_c2_SatDinModel_3(SFc2_SatDinModel_3InstanceStruct
  *chartInstance, const mxArray *c2_st);
static void finalize_c2_SatDinModel_3(SFc2_SatDinModel_3InstanceStruct
  *chartInstance);
static void sf_c2_SatDinModel_3(SFc2_SatDinModel_3InstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber);
static const mxArray *c2_sf_marshall(void *chartInstanceVoid, void *c2_u);
static const mxArray *c2_b_sf_marshall(void *chartInstanceVoid, void *c2_u);
static const mxArray *c2_c_sf_marshall(void *chartInstanceVoid, void *c2_u);
static void c2_info_helper(c2_ResolvedFunctionInfo c2_info[25]);
static const mxArray *c2_d_sf_marshall(void *chartInstanceVoid, void *c2_u);
static void c2_emlrt_marshallIn(SFc2_SatDinModel_3InstanceStruct *chartInstance,
  const mxArray *c2_y, const char_T *c2_name, real_T c2_b_y[6]);
static uint8_T c2_b_emlrt_marshallIn(SFc2_SatDinModel_3InstanceStruct
  *chartInstance, const mxArray *c2_b_is_active_c2_SatDinModel_3, const char_T
  *c2_name);
static void init_dsm_address_info(SFc2_SatDinModel_3InstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c2_SatDinModel_3(SFc2_SatDinModel_3InstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c2_is_active_c2_SatDinModel_3 = 0U;
}

static void initialize_params_c2_SatDinModel_3(SFc2_SatDinModel_3InstanceStruct *
  chartInstance)
{
}

static void enable_c2_SatDinModel_3(SFc2_SatDinModel_3InstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c2_SatDinModel_3(SFc2_SatDinModel_3InstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c2_update_debugger_state_c2_SatDinModel_3
  (SFc2_SatDinModel_3InstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c2_SatDinModel_3
  (SFc2_SatDinModel_3InstanceStruct *chartInstance)
{
  const mxArray *c2_st = NULL;
  const mxArray *c2_y = NULL;
  int32_T c2_i0;
  real_T c2_hoistedGlobal[6];
  int32_T c2_i1;
  real_T c2_u[6];
  const mxArray *c2_b_y = NULL;
  uint8_T c2_b_hoistedGlobal;
  uint8_T c2_b_u;
  const mxArray *c2_c_y = NULL;
  real_T (*c2_d_y)[6];
  c2_d_y = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S, 1);
  c2_st = NULL;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_createcellarray(2));
  for (c2_i0 = 0; c2_i0 < 6; c2_i0 = c2_i0 + 1) {
    c2_hoistedGlobal[c2_i0] = (*c2_d_y)[c2_i0];
  }

  for (c2_i1 = 0; c2_i1 < 6; c2_i1 = c2_i1 + 1) {
    c2_u[c2_i1] = c2_hoistedGlobal[c2_i1];
  }

  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", &c2_u, 0, 0U, 1U, 0U, 1, 6));
  sf_mex_setcell(c2_y, 0, c2_b_y);
  c2_b_hoistedGlobal = chartInstance->c2_is_active_c2_SatDinModel_3;
  c2_b_u = c2_b_hoistedGlobal;
  c2_c_y = NULL;
  sf_mex_assign(&c2_c_y, sf_mex_create("y", &c2_b_u, 3, 0U, 0U, 0U, 0));
  sf_mex_setcell(c2_y, 1, c2_c_y);
  sf_mex_assign(&c2_st, c2_y);
  return c2_st;
}

static void set_sim_state_c2_SatDinModel_3(SFc2_SatDinModel_3InstanceStruct
  *chartInstance, const mxArray *c2_st)
{
  const mxArray *c2_u;
  real_T c2_dv0[6];
  int32_T c2_i2;
  real_T (*c2_y)[6];
  c2_y = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c2_doneDoubleBufferReInit = TRUE;
  c2_u = sf_mex_dup(c2_st);
  c2_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 0)), "y",
                      c2_dv0);
  for (c2_i2 = 0; c2_i2 < 6; c2_i2 = c2_i2 + 1) {
    (*c2_y)[c2_i2] = c2_dv0[c2_i2];
  }

  chartInstance->c2_is_active_c2_SatDinModel_3 = c2_b_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 1)),
     "is_active_c2_SatDinModel_3");
  sf_mex_destroy(&c2_u);
  c2_update_debugger_state_c2_SatDinModel_3(chartInstance);
  sf_mex_destroy(&c2_st);
}

static void finalize_c2_SatDinModel_3(SFc2_SatDinModel_3InstanceStruct
  *chartInstance)
{
}

static void sf_c2_SatDinModel_3(SFc2_SatDinModel_3InstanceStruct *chartInstance)
{
  int32_T c2_i3;
  int32_T c2_previousEvent;
  real_T c2_hoistedGlobal;
  real_T c2_jd;
  uint32_T c2_debug_family_var_map[18];
  static const char *c2_sv0[18] = { "temp", "tu", "year", "leapyrs", "days",
    "lmonth", "dayofyr", "i", "inttemp", "mon", "day", "hr",
    "min", "sec", "nargin", "nargout", "jd", "y" };

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
  real_T c2_f_x;
  real_T c2_a;
  real_T c2_b_y;
  real_T c2_g_x;
  real_T c2_h_x;
  real_T c2_b_a;
  real_T c2_c_y;
  real_T c2_c_a;
  real_T c2_d_y;
  real_T c2_i_x;
  real_T c2_j_x;
  real_T c2_d_a;
  real_T c2_e_y;
  int32_T c2_i4;
  static real_T c2_dv1[12] = { 31.0, 28.0, 31.0, 30.0, 31.0, 30.0, 31.0, 31.0,
    30.0, 31.0, 30.0, 31.0 };

  real_T c2_k_x;
  real_T c2_l_x;
  real_T c2_m_x;
  real_T c2_xv;
  uint32_T c2_b_debug_family_var_map[5];
  static const char *c2_sv1[5] = { "nargin", "nargout", "x", "xv", "y" };

  real_T c2_b_nargin = 2.0;
  real_T c2_b_nargout = 1.0;
  real_T c2_f_y;
  real_T c2_b_A;
  real_T c2_B;
  real_T c2_n_x;
  real_T c2_g_y;
  real_T c2_o_x;
  real_T c2_h_y;
  real_T c2_p_x;
  real_T c2_i_y;
  real_T c2_j_y;
  real_T c2_q_x;
  real_T c2_r_x;
  real_T c2_s_x;
  real_T c2_t_x;
  real_T c2_e_a;
  real_T c2_b;
  real_T c2_k_y;
  real_T c2_f_a;
  real_T c2_u_x;
  real_T c2_v_x;
  real_T c2_w_x;
  real_T c2_g_a;
  real_T c2_x_x;
  real_T c2_y_x;
  real_T c2_ab_x;
  real_T c2_h_a;
  int32_T c2_i5;
  real_T *c2_b_jd;
  real_T (*c2_l_y)[6];
  c2_l_y = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S, 1);
  c2_b_jd = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG,0);
  _SFD_DATA_RANGE_CHECK(*c2_b_jd, 0U);
  for (c2_i3 = 0; c2_i3 < 6; c2_i3 = c2_i3 + 1) {
    _SFD_DATA_RANGE_CHECK((*c2_l_y)[c2_i3], 1U);
  }

  c2_previousEvent = _sfEvent_;
  _sfEvent_ = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG,0);
  c2_hoistedGlobal = *c2_b_jd;
  c2_jd = c2_hoistedGlobal;
  sf_debug_symbol_scope_push_eml(0U, 18U, 18U, c2_sv0, c2_debug_family_var_map);
  sf_debug_symbol_scope_add_eml(&c2_temp, c2_b_sf_marshall, 0U);
  sf_debug_symbol_scope_add_eml(&c2_tu, c2_b_sf_marshall, 1U);
  sf_debug_symbol_scope_add_eml(&c2_year, c2_b_sf_marshall, 2U);
  sf_debug_symbol_scope_add_eml(&c2_leapyrs, c2_b_sf_marshall, 3U);
  sf_debug_symbol_scope_add_eml(&c2_days, c2_b_sf_marshall, 4U);
  sf_debug_symbol_scope_add_eml(&c2_lmonth, c2_c_sf_marshall, 5U);
  sf_debug_symbol_scope_add_eml(&c2_dayofyr, c2_b_sf_marshall, 6U);
  sf_debug_symbol_scope_add_eml(&c2_i, c2_b_sf_marshall, 7U);
  sf_debug_symbol_scope_add_eml(&c2_inttemp, c2_b_sf_marshall, 8U);
  sf_debug_symbol_scope_add_eml(&c2_mon, c2_b_sf_marshall, 9U);
  sf_debug_symbol_scope_add_eml(&c2_day, c2_b_sf_marshall, 10U);
  sf_debug_symbol_scope_add_eml(&c2_hr, c2_b_sf_marshall, 11U);
  sf_debug_symbol_scope_add_eml(&c2_min, c2_b_sf_marshall, 12U);
  sf_debug_symbol_scope_add_eml(&c2_sec, c2_b_sf_marshall, 13U);
  sf_debug_symbol_scope_add_eml(&c2_nargin, c2_b_sf_marshall, 14U);
  sf_debug_symbol_scope_add_eml(&c2_nargout, c2_b_sf_marshall, 15U);
  sf_debug_symbol_scope_add_eml(&c2_jd, c2_b_sf_marshall, 16U);
  sf_debug_symbol_scope_add_eml(&c2_y, c2_sf_marshall, 17U);
  CV_EML_FCN(0, 0);

  /*  ----------------- find year and days of the year --------------- */
  _SFD_EML_CALL(0,5);
  c2_temp = ((c2_jd - 2.4150195E+006) + 1.7210445E+006) + 14.0;
  _SFD_EML_CALL(0,6);
  c2_A = c2_temp;
  c2_x = c2_A;
  c2_b_x = c2_x;
  c2_c_x = c2_b_x;
  c2_tu = c2_c_x / 365.25;
  _SFD_EML_CALL(0,7);
  c2_d_x = c2_tu;
  c2_e_x = c2_d_x;
  c2_f_x = c2_e_x;
  c2_e_x = c2_f_x;
  c2_e_x = muDoubleScalarFloor(c2_e_x);
  c2_year = 1900.0 + c2_e_x;
  _SFD_EML_CALL(0,8);
  c2_a = c2_year - 1901.0;
  c2_b_y = c2_a * 0.25;
  c2_g_x = c2_b_y;
  c2_leapyrs = c2_g_x;
  c2_h_x = c2_leapyrs;
  c2_leapyrs = c2_h_x;
  c2_leapyrs = muDoubleScalarFloor(c2_leapyrs);

  /*      days   = temp - ((year-1900)*365.0 + leapyrs ) + 0.00000000001; % nudge by 8.64x10-7 sec to get even outputs */
  _SFD_EML_CALL(0,10);
  c2_b_a = c2_year - 1900.0;
  c2_c_y = c2_b_a * 365.0;
  c2_days = c2_temp - (c2_c_y + c2_leapyrs);

  /*  ------------ check for case of beginning of a year ------------- */
  _SFD_EML_CALL(0,13);
  if (CV_EML_IF(0, 0, c2_days < 1.0)) {
    _SFD_EML_CALL(0,14);
    c2_year = c2_year - 1.0;
    _SFD_EML_CALL(0,15);
    c2_c_a = c2_year - 1901.0;
    c2_d_y = c2_c_a * 0.25;
    c2_i_x = c2_d_y;
    c2_leapyrs = c2_i_x;
    c2_j_x = c2_leapyrs;
    c2_leapyrs = c2_j_x;
    c2_leapyrs = muDoubleScalarFloor(c2_leapyrs);
    _SFD_EML_CALL(0,16);
    c2_d_a = c2_year - 1900.0;
    c2_e_y = c2_d_a * 365.0;
    c2_days = c2_temp - (c2_e_y + c2_leapyrs);
  }

  /*  ------------------- find remaining data  ----------------------- */
  /*  --------------- set up array of days in month  -------------- */
  _SFD_EML_CALL(0,22);
  for (c2_i4 = 0; c2_i4 < 12; c2_i4 = c2_i4 + 1) {
    c2_lmonth[c2_i4] = c2_dv1[c2_i4];
  }

  _SFD_EML_CALL(0,24);
  c2_k_x = c2_days;
  c2_dayofyr = c2_k_x;
  c2_l_x = c2_dayofyr;
  c2_dayofyr = c2_l_x;
  c2_dayofyr = muDoubleScalarFloor(c2_dayofyr);

  /*  ----------------- find month and day of month --------------- */
  _SFD_EML_CALL(0,27);
  c2_m_x = c2_year - 1900.0;
  c2_xv = 4.0;
  sf_debug_symbol_scope_push_eml(0U, 5U, 5U, c2_sv1, c2_b_debug_family_var_map);
  sf_debug_symbol_scope_add_eml(&c2_b_nargin, c2_b_sf_marshall, 0U);
  sf_debug_symbol_scope_add_eml(&c2_b_nargout, c2_b_sf_marshall, 1U);
  sf_debug_symbol_scope_add_eml(&c2_m_x, c2_b_sf_marshall, 2U);
  sf_debug_symbol_scope_add_eml(&c2_xv, c2_b_sf_marshall, 3U);
  sf_debug_symbol_scope_add_eml(&c2_f_y, c2_b_sf_marshall, 4U);
  CV_SCRIPT_FCN(0, 0);

  /*  ---------------------------------------------------------------------------- */
  /*  */
  /*                            function modulo */
  /*  */
  /*   this function finds the modulous value. The result is positive or negative. */
  /*  */
  /*   author        : david vallado                  719-573-2600    4 jun 2002 */
  /*  */
  /*   revisions */
  /*                 - */
  /*  */
  /*   inputs          description                    range / units */
  /*     x           - input argument */
  /*     xv          - input argument to mod with */
  /*  */
  /*   outputs       : */
  /*     y           - answer */
  /*  */
  /*   locals        : */
  /*     none        - */
  /*  */
  /*   coupling      : */
  /*     none        - */
  /*  */
  /*   references    : */
  /*     vallado       2001, xx */
  /*  */
  /*  y = modulo (x,xv); */
  /*  ---------------------------------------------------------------------------- */
  _SFD_SCRIPT_CALL(0,33);
  c2_b_A = c2_m_x;
  c2_B = c2_xv;
  c2_n_x = c2_b_A;
  c2_g_y = c2_B;
  c2_o_x = c2_n_x;
  c2_h_y = c2_g_y;
  c2_p_x = c2_o_x;
  c2_i_y = c2_h_y;
  c2_j_y = c2_p_x / c2_i_y;
  c2_q_x = c2_j_y;
  c2_r_x = c2_q_x;
  c2_s_x = c2_r_x;
  c2_r_x = c2_s_x;
  c2_t_x = c2_r_x;
  c2_r_x = c2_t_x;
  if (c2_r_x > 0.0) {
    c2_r_x = muDoubleScalarFloor(c2_r_x);
  } else {
    c2_r_x = muDoubleScalarCeil(c2_r_x);
  }

  c2_e_a = c2_xv;
  c2_b = c2_r_x;
  c2_k_y = c2_e_a * c2_b;
  c2_f_y = c2_m_x - c2_k_y;
  _SFD_SCRIPT_CALL(0,-33);
  sf_debug_symbol_scope_pop();
  if (CV_EML_IF(0, 1, c2_f_y == 0.0)) {
    _SFD_EML_CALL(0,28);
    c2_lmonth[1] = 29.0;
  }

  _SFD_EML_CALL(0,31);
  c2_i = 1.0;
  _SFD_EML_CALL(0,32);
  c2_inttemp = 0.0;
 label_1:
  ;
  if (c2_dayofyr > c2_inttemp + c2_lmonth[_SFD_EML_ARRAY_BOUNDS_CHECK("lmonth",
       (int32_T)_SFD_INTEGER_CHECK("i", c2_i), 1, 12, 1, 0) -
      1]) {
    if (c2_i < 12.0) {
      CV_EML_WHILE(0, 0, TRUE);
      _SFD_EML_CALL(0,34);
      c2_inttemp = c2_inttemp + c2_lmonth[_SFD_EML_ARRAY_BOUNDS_CHECK("lmonth",
        (int32_T)_SFD_INTEGER_CHECK("i", c2_i), 1, 12, 1, 0) - 1];
      _SFD_EML_CALL(0,35);
      c2_i = c2_i + 1.0;
      sf_mex_listen_for_ctrl_c(chartInstance->S);
      goto label_1;
    }
  }

  CV_EML_WHILE(0, 0, FALSE);
  _SFD_EML_CALL(0,38);
  c2_mon = c2_i;
  _SFD_EML_CALL(0,39);
  c2_day = c2_dayofyr - c2_inttemp;

  /*  ----------------- find hours minutes and seconds ------------ */
  _SFD_EML_CALL(0,42);
  c2_f_a = c2_days - c2_dayofyr;
  c2_temp = c2_f_a * 24.0;
  _SFD_EML_CALL(0,43);
  c2_u_x = c2_temp;
  c2_hr = c2_u_x;
  c2_v_x = c2_hr;
  c2_hr = c2_v_x;
  c2_w_x = c2_hr;
  c2_hr = c2_w_x;
  if (c2_hr > 0.0) {
    c2_hr = muDoubleScalarFloor(c2_hr);
  } else {
    c2_hr = muDoubleScalarCeil(c2_hr);
  }

  _SFD_EML_CALL(0,44);
  c2_g_a = c2_temp - c2_hr;
  c2_temp = c2_g_a * 60.0;
  _SFD_EML_CALL(0,45);
  c2_x_x = c2_temp;
  c2_min = c2_x_x;
  c2_y_x = c2_min;
  c2_min = c2_y_x;
  c2_ab_x = c2_min;
  c2_min = c2_ab_x;
  if (c2_min > 0.0) {
    c2_min = muDoubleScalarFloor(c2_min);
  } else {
    c2_min = muDoubleScalarCeil(c2_min);
  }

  _SFD_EML_CALL(0,46);
  c2_h_a = c2_temp - c2_min;
  c2_sec = c2_h_a * 60.0;

  /*      sec= sec - 0.00000086400; */
  _SFD_EML_CALL(0,50);
  c2_y[0] = c2_year;
  c2_y[1] = c2_mon;
  c2_y[2] = c2_day;
  c2_y[3] = c2_hr;
  c2_y[4] = c2_min;
  c2_y[5] = c2_sec;
  _SFD_EML_CALL(0,-50);
  sf_debug_symbol_scope_pop();
  for (c2_i5 = 0; c2_i5 < 6; c2_i5 = c2_i5 + 1) {
    (*c2_l_y)[c2_i5] = c2_y[c2_i5];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG,0);
  _sfEvent_ = c2_previousEvent;
  sf_debug_check_for_state_inconsistency(_SatDinModel_3MachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber)
{
  _SFD_SCRIPT_TRANSLATION(c2_chartNumber, 0U, sf_debug_get_script_id(
    "H:/Satelit_Dyn_Model_3/modulo.m"));
}

static const mxArray *c2_sf_marshall(void *chartInstanceVoid, void *c2_u)
{
  const mxArray *c2_y = NULL;
  int32_T c2_i6;
  real_T c2_b_u[6];
  const mxArray *c2_b_y = NULL;
  SFc2_SatDinModel_3InstanceStruct *chartInstance;
  chartInstance = (SFc2_SatDinModel_3InstanceStruct *)chartInstanceVoid;
  c2_y = NULL;
  for (c2_i6 = 0; c2_i6 < 6; c2_i6 = c2_i6 + 1) {
    c2_b_u[c2_i6] = (*((real_T (*)[6])c2_u))[c2_i6];
  }

  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", &c2_b_u, 0, 0U, 1U, 0U, 1, 6));
  sf_mex_assign(&c2_y, c2_b_y);
  return c2_y;
}

static const mxArray *c2_b_sf_marshall(void *chartInstanceVoid, void *c2_u)
{
  const mxArray *c2_y = NULL;
  real_T c2_b_u;
  const mxArray *c2_b_y = NULL;
  SFc2_SatDinModel_3InstanceStruct *chartInstance;
  chartInstance = (SFc2_SatDinModel_3InstanceStruct *)chartInstanceVoid;
  c2_y = NULL;
  c2_b_u = *((real_T *)c2_u);
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", &c2_b_u, 0, 0U, 0U, 0U, 0));
  sf_mex_assign(&c2_y, c2_b_y);
  return c2_y;
}

static const mxArray *c2_c_sf_marshall(void *chartInstanceVoid, void *c2_u)
{
  const mxArray *c2_y = NULL;
  int32_T c2_i7;
  real_T c2_b_u[12];
  const mxArray *c2_b_y = NULL;
  SFc2_SatDinModel_3InstanceStruct *chartInstance;
  chartInstance = (SFc2_SatDinModel_3InstanceStruct *)chartInstanceVoid;
  c2_y = NULL;
  for (c2_i7 = 0; c2_i7 < 12; c2_i7 = c2_i7 + 1) {
    c2_b_u[c2_i7] = (*((real_T (*)[12])c2_u))[c2_i7];
  }

  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", &c2_b_u, 0, 0U, 1U, 0U, 1, 12));
  sf_mex_assign(&c2_y, c2_b_y);
  return c2_y;
}

const mxArray *sf_c2_SatDinModel_3_get_eml_resolved_functions_info(void)
{
  const mxArray *c2_nameCaptureInfo = NULL;
  c2_ResolvedFunctionInfo c2_info[25];
  const mxArray *c2_m0 = NULL;
  int32_T c2_i8;
  c2_ResolvedFunctionInfo *c2_r0;
  c2_nameCaptureInfo = NULL;
  c2_info_helper(c2_info);
  sf_mex_assign(&c2_m0, sf_mex_createstruct("nameCaptureInfo", 1, 25));
  for (c2_i8 = 0; c2_i8 < 25; c2_i8 = c2_i8 + 1) {
    c2_r0 = &c2_info[c2_i8];
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c2_r0->context)), "context",
                    "nameCaptureInfo", c2_i8);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c2_r0->name)), "name",
                    "nameCaptureInfo", c2_i8);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c2_r0->dominantType)),
                    "dominantType", "nameCaptureInfo", c2_i8);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c2_r0->resolved)), "resolved"
                    , "nameCaptureInfo", c2_i8);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->fileLength,
      7, 0U, 0U, 0U, 0), "fileLength", "nameCaptureInfo",
                    c2_i8);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->fileTime1, 7,
      0U, 0U, 0U, 0), "fileTime1", "nameCaptureInfo", c2_i8);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->fileTime2, 7,
      0U, 0U, 0U, 0), "fileTime2", "nameCaptureInfo", c2_i8);
  }

  sf_mex_assign(&c2_nameCaptureInfo, c2_m0);
  return c2_nameCaptureInfo;
}

static void c2_info_helper(c2_ResolvedFunctionInfo c2_info[25])
{
  c2_info[0].context = "";
  c2_info[0].name = "minus";
  c2_info[0].dominantType = "double";
  c2_info[0].resolved = "[B]minus";
  c2_info[0].fileLength = 0U;
  c2_info[0].fileTime1 = 0U;
  c2_info[0].fileTime2 = 0U;
  c2_info[1].context = "";
  c2_info[1].name = "plus";
  c2_info[1].dominantType = "double";
  c2_info[1].resolved = "[B]plus";
  c2_info[1].fileLength = 0U;
  c2_info[1].fileTime1 = 0U;
  c2_info[1].fileTime2 = 0U;
  c2_info[2].context = "";
  c2_info[2].name = "mrdivide";
  c2_info[2].dominantType = "double";
  c2_info[2].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c2_info[2].fileLength = 800U;
  c2_info[2].fileTime1 = 1238466690U;
  c2_info[2].fileTime2 = 0U;
  c2_info[3].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c2_info[3].name = "nargin";
  c2_info[3].dominantType = "";
  c2_info[3].resolved = "[B]nargin";
  c2_info[3].fileLength = 0U;
  c2_info[3].fileTime1 = 0U;
  c2_info[3].fileTime2 = 0U;
  c2_info[4].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c2_info[4].name = "ge";
  c2_info[4].dominantType = "double";
  c2_info[4].resolved = "[B]ge";
  c2_info[4].fileLength = 0U;
  c2_info[4].fileTime1 = 0U;
  c2_info[4].fileTime2 = 0U;
  c2_info[5].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c2_info[5].name = "isscalar";
  c2_info[5].dominantType = "double";
  c2_info[5].resolved = "[B]isscalar";
  c2_info[5].fileLength = 0U;
  c2_info[5].fileTime1 = 0U;
  c2_info[5].fileTime2 = 0U;
  c2_info[6].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c2_info[6].name = "rdivide";
  c2_info[6].dominantType = "double";
  c2_info[6].resolved = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c2_info[6].fileLength = 403U;
  c2_info[6].fileTime1 = 1244767952U;
  c2_info[6].fileTime2 = 0U;
  c2_info[7].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c2_info[7].name = "gt";
  c2_info[7].dominantType = "double";
  c2_info[7].resolved = "[B]gt";
  c2_info[7].fileLength = 0U;
  c2_info[7].fileTime1 = 0U;
  c2_info[7].fileTime2 = 0U;
  c2_info[8].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c2_info[8].name = "isa";
  c2_info[8].dominantType = "double";
  c2_info[8].resolved = "[B]isa";
  c2_info[8].fileLength = 0U;
  c2_info[8].fileTime1 = 0U;
  c2_info[8].fileTime2 = 0U;
  c2_info[9].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c2_info[9].name = "eml_div";
  c2_info[9].dominantType = "double";
  c2_info[9].resolved = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c2_info[9].fileLength = 4269U;
  c2_info[9].fileTime1 = 1228126226U;
  c2_info[9].fileTime2 = 0U;
  c2_info[10].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c2_info[10].name = "isinteger";
  c2_info[10].dominantType = "double";
  c2_info[10].resolved = "[B]isinteger";
  c2_info[10].fileLength = 0U;
  c2_info[10].fileTime1 = 0U;
  c2_info[10].fileTime2 = 0U;
  c2_info[11].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m/eml_fldiv";
  c2_info[11].name = "isreal";
  c2_info[11].dominantType = "double";
  c2_info[11].resolved = "[B]isreal";
  c2_info[11].fileLength = 0U;
  c2_info[11].fileTime1 = 0U;
  c2_info[11].fileTime2 = 0U;
  c2_info[12].context = "";
  c2_info[12].name = "floor";
  c2_info[12].dominantType = "double";
  c2_info[12].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m";
  c2_info[12].fileLength = 332U;
  c2_info[12].fileTime1 = 1203480422U;
  c2_info[12].fileTime2 = 0U;
  c2_info[13].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m";
  c2_info[13].name = "eml_scalar_floor";
  c2_info[13].dominantType = "double";
  c2_info[13].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m";
  c2_info[13].fileLength = 260U;
  c2_info[13].fileTime1 = 1209363190U;
  c2_info[13].fileTime2 = 0U;
  c2_info[14].context = "";
  c2_info[14].name = "mtimes";
  c2_info[14].dominantType = "double";
  c2_info[14].resolved = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c2_info[14].fileLength = 3425U;
  c2_info[14].fileTime1 = 1250705166U;
  c2_info[14].fileTime2 = 0U;
  c2_info[15].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c2_info[15].name = "strcmp";
  c2_info[15].dominantType = "char";
  c2_info[15].resolved = "[B]strcmp";
  c2_info[15].fileLength = 0U;
  c2_info[15].fileTime1 = 0U;
  c2_info[15].fileTime2 = 0U;
  c2_info[16].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c2_info[16].name = "size";
  c2_info[16].dominantType = "double";
  c2_info[16].resolved = "[B]size";
  c2_info[16].fileLength = 0U;
  c2_info[16].fileTime1 = 0U;
  c2_info[16].fileTime2 = 0U;
  c2_info[17].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c2_info[17].name = "eq";
  c2_info[17].dominantType = "double";
  c2_info[17].resolved = "[B]eq";
  c2_info[17].fileLength = 0U;
  c2_info[17].fileTime1 = 0U;
  c2_info[17].fileTime2 = 0U;
  c2_info[18].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c2_info[18].name = "class";
  c2_info[18].dominantType = "double";
  c2_info[18].resolved = "[B]class";
  c2_info[18].fileLength = 0U;
  c2_info[18].fileTime1 = 0U;
  c2_info[18].fileTime2 = 0U;
  c2_info[19].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c2_info[19].name = "not";
  c2_info[19].dominantType = "logical";
  c2_info[19].resolved = "[B]not";
  c2_info[19].fileLength = 0U;
  c2_info[19].fileTime1 = 0U;
  c2_info[19].fileTime2 = 0U;
  c2_info[20].context = "";
  c2_info[20].name = "lt";
  c2_info[20].dominantType = "double";
  c2_info[20].resolved = "[B]lt";
  c2_info[20].fileLength = 0U;
  c2_info[20].fileTime1 = 0U;
  c2_info[20].fileTime2 = 0U;
  c2_info[21].context = "";
  c2_info[21].name = "modulo";
  c2_info[21].dominantType = "double";
  c2_info[21].resolved = "[]H:/Satelit_Dyn_Model_3/modulo.m";
  c2_info[21].fileLength = 847U;
  c2_info[21].fileTime1 = 1372323486U;
  c2_info[21].fileTime2 = 0U;
  c2_info[22].context = "[]H:/Satelit_Dyn_Model_3/modulo.m";
  c2_info[22].name = "fix";
  c2_info[22].dominantType = "double";
  c2_info[22].resolved = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/fix.m";
  c2_info[22].fileLength = 326U;
  c2_info[22].fileTime1 = 1203480422U;
  c2_info[22].fileTime2 = 0U;
  c2_info[23].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/fix.m";
  c2_info[23].name = "eml_scalar_fix";
  c2_info[23].dominantType = "double";
  c2_info[23].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_fix.m";
  c2_info[23].fileLength = 501U;
  c2_info[23].fileTime1 = 1203480392U;
  c2_info[23].fileTime2 = 0U;
  c2_info[24].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_fix.m";
  c2_info[24].name = "isfloat";
  c2_info[24].dominantType = "double";
  c2_info[24].resolved = "[B]isfloat";
  c2_info[24].fileLength = 0U;
  c2_info[24].fileTime1 = 0U;
  c2_info[24].fileTime2 = 0U;
}

static const mxArray *c2_d_sf_marshall(void *chartInstanceVoid, void *c2_u)
{
  const mxArray *c2_y = NULL;
  boolean_T c2_b_u;
  const mxArray *c2_b_y = NULL;
  SFc2_SatDinModel_3InstanceStruct *chartInstance;
  chartInstance = (SFc2_SatDinModel_3InstanceStruct *)chartInstanceVoid;
  c2_y = NULL;
  c2_b_u = *((boolean_T *)c2_u);
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", &c2_b_u, 11, 0U, 0U, 0U, 0));
  sf_mex_assign(&c2_y, c2_b_y);
  return c2_y;
}

static void c2_emlrt_marshallIn(SFc2_SatDinModel_3InstanceStruct *chartInstance,
  const mxArray *c2_y, const char_T *c2_name, real_T
  c2_b_y[6])
{
  real_T c2_dv2[6];
  int32_T c2_i9;
  sf_mex_import(c2_name, sf_mex_dup(c2_y), &c2_dv2, 1, 0, 0U, 1, 0U, 1, 6);
  for (c2_i9 = 0; c2_i9 < 6; c2_i9 = c2_i9 + 1) {
    c2_b_y[c2_i9] = c2_dv2[c2_i9];
  }

  sf_mex_destroy(&c2_y);
}

static uint8_T c2_b_emlrt_marshallIn(SFc2_SatDinModel_3InstanceStruct
  *chartInstance, const mxArray *c2_b_is_active_c2_SatDinModel_3
  , const char_T *c2_name)
{
  uint8_T c2_y;
  uint8_T c2_u0;
  sf_mex_import(c2_name, sf_mex_dup(c2_b_is_active_c2_SatDinModel_3), &c2_u0, 1,
                3, 0U, 0, 0U, 0);
  c2_y = c2_u0;
  sf_mex_destroy(&c2_b_is_active_c2_SatDinModel_3);
  return c2_y;
}

static void init_dsm_address_info(SFc2_SatDinModel_3InstanceStruct
  *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c2_SatDinModel_3_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3811403478U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1020032521U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2494629248U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3464922115U);
}

mxArray *sf_c2_SatDinModel_3_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,4,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(3637400034U);
    pr[1] = (double)(71475212U);
    pr[2] = (double)(81863449U);
    pr[3] = (double)(1037042626U);
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

  return(mxAutoinheritanceInfo);
}

static mxArray *sf_get_sim_state_info_c2_SatDinModel_3(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"y\",},{M[8],M[0],T\"is_active_c2_SatDinModel_3\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c2_SatDinModel_3_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc2_SatDinModel_3InstanceStruct *chartInstance;
    chartInstance = (SFc2_SatDinModel_3InstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_SatDinModel_3MachineNumber_,
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
          init_script_number_translation(_SatDinModel_3MachineNumber_,
            chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (_SatDinModel_3MachineNumber_,chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(_SatDinModel_3MachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"jd",0,
                              (MexFcnForType)c2_b_sf_marshall);

          {
            unsigned int dimVector[1];
            dimVector[0]= 6;
            _SFD_SET_DATA_PROPS(1,2,0,1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"y",0,(MexFcnForType)c2_sf_marshall);
          }

          _SFD_STATE_INFO(0,0,2);
          _SFD_CH_SUBSTATE_COUNT(0);
          _SFD_CH_SUBSTATE_DECOMP(0);
        }

        _SFD_CV_INIT_CHART(0,0,0,0);

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);

        /* Initialization of EML Model Coverage */
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

        {
          real_T *c2_jd;
          real_T (*c2_y)[6];
          c2_y = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S, 1);
          c2_jd = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c2_jd);
          _SFD_SET_DATA_VALUE_PTR(1U, c2_y);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(_SatDinModel_3MachineNumber_,
        chartInstance->chartNumber,chartInstance->instanceNumber);
    }
  }
}

static void sf_opaque_initialize_c2_SatDinModel_3(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc2_SatDinModel_3InstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c2_SatDinModel_3((SFc2_SatDinModel_3InstanceStruct*)
    chartInstanceVar);
  initialize_c2_SatDinModel_3((SFc2_SatDinModel_3InstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c2_SatDinModel_3(void *chartInstanceVar)
{
  enable_c2_SatDinModel_3((SFc2_SatDinModel_3InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c2_SatDinModel_3(void *chartInstanceVar)
{
  disable_c2_SatDinModel_3((SFc2_SatDinModel_3InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c2_SatDinModel_3(void *chartInstanceVar)
{
  sf_c2_SatDinModel_3((SFc2_SatDinModel_3InstanceStruct*) chartInstanceVar);
}

static mxArray* sf_internal_get_sim_state_c2_SatDinModel_3(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c2_SatDinModel_3
    ((SFc2_SatDinModel_3InstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = sf_get_sim_state_info_c2_SatDinModel_3();/* state var info */
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

static void sf_internal_set_sim_state_c2_SatDinModel_3(SimStruct* S, const
  mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c2_SatDinModel_3();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c2_SatDinModel_3((SFc2_SatDinModel_3InstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static mxArray* sf_opaque_get_sim_state_c2_SatDinModel_3(SimStruct* S)
{
  return sf_internal_get_sim_state_c2_SatDinModel_3(S);
}

static void sf_opaque_set_sim_state_c2_SatDinModel_3(SimStruct* S, const mxArray
  *st)
{
  sf_internal_set_sim_state_c2_SatDinModel_3(S, st);
}

static void sf_opaque_terminate_c2_SatDinModel_3(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc2_SatDinModel_3InstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c2_SatDinModel_3((SFc2_SatDinModel_3InstanceStruct*)
      chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c2_SatDinModel_3(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c2_SatDinModel_3((SFc2_SatDinModel_3InstanceStruct*)
      (((ChartInfoStruct *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c2_SatDinModel_3(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable("SatDinModel_3","SatDinModel_3",2);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop("SatDinModel_3","SatDinModel_3",2,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop("SatDinModel_3",
      "SatDinModel_3",2,"gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,"SatDinModel_3","SatDinModel_3",2,1);
      sf_mark_chart_reusable_outputs(S,"SatDinModel_3","SatDinModel_3",2,1);
    }

    sf_set_rtw_dwork_info(S,"SatDinModel_3","SatDinModel_3",2);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
    ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  }

  ssSetChecksum0(S,(3526895171U));
  ssSetChecksum1(S,(1668268310U));
  ssSetChecksum2(S,(1713830573U));
  ssSetChecksum3(S,(2309876159U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c2_SatDinModel_3(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "SatDinModel_3", "SatDinModel_3",2);
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c2_SatDinModel_3(SimStruct *S)
{
  SFc2_SatDinModel_3InstanceStruct *chartInstance;
  chartInstance = (SFc2_SatDinModel_3InstanceStruct *)malloc(sizeof
    (SFc2_SatDinModel_3InstanceStruct));
  memset(chartInstance, 0, sizeof(SFc2_SatDinModel_3InstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c2_SatDinModel_3;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c2_SatDinModel_3;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c2_SatDinModel_3;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c2_SatDinModel_3;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c2_SatDinModel_3;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c2_SatDinModel_3;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c2_SatDinModel_3;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c2_SatDinModel_3;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c2_SatDinModel_3;
  chartInstance->chartInfo.mdlStart = mdlStart_c2_SatDinModel_3;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c2_SatDinModel_3;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->S = S;
  ssSetUserData(S,(void *)(&(chartInstance->chartInfo)));/* register the chart instance with simstruct */
  if (!sim_mode_is_rtw_gen(S)) {
    init_dsm_address_info(chartInstance);
  }

  chart_debug_initialization(S,1);
}

void c2_SatDinModel_3_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c2_SatDinModel_3(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c2_SatDinModel_3(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c2_SatDinModel_3(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c2_SatDinModel_3_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
