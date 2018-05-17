
#if (defined ComHandlerType_START_SEC_CODE)
  #undef ComHandlerType_START_SEC_CODE
  #undef MEMMAP_ERROR

#elif (defined ComHandlerType_STOP_SEC_CODE)
  #undef ComHandlerType_STOP_SEC_CODE
  #undef MEMMAP_ERROR

#elif (defined ComHandlerType_START_SEC_CONST_UNSPECIFIED)
  #undef ComHandlerType_START_SEC_CONST_UNSPECIFIED
  #undef MEMMAP_ERROR

#elif (defined ComHandlerType_STOP_SEC_CONST_UNSPECIFIED)
  #undef ComHandlerType_STOP_SEC_CONST_UNSPECIFIED
  #undef MEMMAP_ERROR

#elif (defined ComHandlerType_START_SEC_VAR_INIT_UNSPECIFIED)
  #undef ComHandlerType_START_SEC_VAR_INIT_UNSPECIFIED
  #undef MEMMAP_ERROR

#elif (defined ComHandlerType_STOP_SEC_VAR_INIT_UNSPECIFIED)
  #undef ComHandlerType_STOP_SEC_VAR_INIT_UNSPECIFIED
  #undef MEMMAP_ERROR

#elif (defined ComHandlerType_START_SEC_VAR_NOINIT_UNSPECIFIED)
  #undef ComHandlerType_START_SEC_VAR_NOINIT_UNSPECIFIED
  #undef MEMMAP_ERROR

#elif (defined ComHandlerType_STOP_SEC_VAR_NOINIT_UNSPECIFIED)
  #undef ComHandlerType_STOP_SEC_VAR_NOINIT_UNSPECIFIED
  #undef MEMMAP_ERROR

#elif (defined DEFAULT_START_SEC_VAR_NOINIT_UNSPECIFIED)
  #undef DEFAULT_START_SEC_VAR_NOINIT_UNSPECIFIED
  #undef MEMMAP_ERROR

#elif (defined DEFAULT_STOP_SEC_VAR_NOINIT_UNSPECIFIED)
  #undef DEFAULT_STOP_SEC_VAR_NOINIT_UNSPECIFIED
  #undef MEMMAP_ERROR

#elif (defined RTE_START_SEC_CAL_PARAM)
  #undef RTE_START_SEC_CAL_PARAM
  #undef MEMMAP_ERROR

#elif (defined RTE_STOP_SEC_CAL_PARAM)
  #undef RTE_STOP_SEC_CAL_PARAM
  #undef MEMMAP_ERROR

#endif