#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include "ompvv.h"
#include "ompvv_timing.h"

// Test for OpenMP 4.5 target data with if
int main() {
  OMPVV_INIT_TIMERS;
  int a_map_var = 0;
  //target teams distribute
  OMPVV_INIT_TEST;
  for (int i = 0; i < NUM_REP; ++i){
      OMPVV_START_TIMER;
      #pragma omp target teams distribute parallel for
      for (int x = 0; x < 1024; ++x){
          OMPVV_TIMING_LOAD;
      }
      OMPVV_STOP_TIMER;
      OMPVV_REGISTER_TEST;
  }
  OMPVV_TIMER_RESULT("target teams distribute parallel for");

  //target teams distribute collapse
  OMPVV_INIT_TEST;
  for (int i = 0; i < NUM_REP; ++i){
      OMPVV_START_TIMER;
      #pragma omp target teams distribute parallel for collapse(1)
      for (int x = 0; x < 1024; ++x){
          OMPVV_TIMING_LOAD;
      }
      OMPVV_STOP_TIMER;
      OMPVV_REGISTER_TEST;
  }
  OMPVV_TIMER_RESULT("target teams distribute parallel for collapse");

  //target teams distribute defaultmap
  OMPVV_INIT_TEST;
  for (int i = 0; i < NUM_REP; ++i){
      OMPVV_START_TIMER;
      #pragma omp target teams distribute parallel for defaultmap(tofrom: scalar)
      for (int x = 0; x < 1024; ++x){
          OMPVV_TIMING_LOAD;
      }
      OMPVV_STOP_TIMER;
      OMPVV_REGISTER_TEST;
  }
  OMPVV_TIMER_RESULT("target teams distribute parallel for defaultmap");

  //target teams distribute default(none)
  OMPVV_INIT_TEST;
  for (int i = 0; i < NUM_REP; ++i){
      OMPVV_START_TIMER;
      #pragma omp target teams distribute parallel for default(none)
      for (int x = 0; x < 1024; ++x){
          OMPVV_TIMING_LOAD;
      }
      OMPVV_STOP_TIMER;
      OMPVV_REGISTER_TEST;
  }
  OMPVV_TIMER_RESULT("target teams distribute parallel for default(none)");

  //target teams distribute default(shared)
  OMPVV_INIT_TEST;
  for (int i = 0; i < NUM_REP; ++i){
      OMPVV_START_TIMER;
      #pragma omp target teams distribute parallel for default(shared)
      for (int x = 0; x < 1024; ++x){
          OMPVV_TIMING_LOAD;
      }
      OMPVV_STOP_TIMER;
      OMPVV_REGISTER_TEST;
  }
  OMPVV_TIMER_RESULT("target teams distribute parallel for default(shared)");
  /*
  //target teams distribute depend
  OMPVV_INIT_TEST;
  for (int i = 0; i < NUM_REP; ++i){
      OMPVV_START_TIMER;
      #pragma omp target teams distribute parallel for depend(inout:a_map_var)
      for (int x = 0; x < 1024; ++x){
          OMPVV_TIMING_LOAD;
      }
      OMPVV_STOP_TIMER;
      OMPVV_REGISTER_TEST;
  }
  OMPVV_TIMER_RESULT("target teams distribute parallel for depend");
  */
  //target teams distribute device
  a_map_var = omp_get_default_device();
  OMPVV_INIT_TEST;
  for (int i = 0; i < NUM_REP; ++i){
      OMPVV_START_TIMER;
      #pragma omp target teams distribute parallel for device(a_map_var)
      for (int x = 0; x < 1024; ++x){
          OMPVV_TIMING_LOAD;
      }
      OMPVV_STOP_TIMER;
      OMPVV_REGISTER_TEST;
  }
  OMPVV_TIMER_RESULT("target teams distribute parallel for device");

  //target teams distribute firstprivate
  OMPVV_INIT_TEST;
  for (int i = 0; i < NUM_REP; ++i){
      OMPVV_START_TIMER;
      #pragma omp target teams distribute parallel for firstprivate(a_map_var)
      for (int x = 0; x < 1024; ++x){
          a_map_var = 0;
          OMPVV_TIMING_LOAD;
      }
      OMPVV_STOP_TIMER;
      OMPVV_REGISTER_TEST;
  }
  OMPVV_TIMER_RESULT("target teams distribute parallel for firstprivate");

  //target teams distribute if(true)
  OMPVV_INIT_TEST;
  for (int i = 0; i < NUM_REP; ++i){
      OMPVV_START_TIMER;
      #pragma omp target teams distribute parallel for if(1)
      for (int x = 0; x < 1024; ++x){
          OMPVV_TIMING_LOAD;
      }
      OMPVV_STOP_TIMER;
      OMPVV_REGISTER_TEST;
  }
  OMPVV_TIMER_RESULT("target teams distribute parallel for if(true)");

  //target teams distribute if(false)
  OMPVV_INIT_TEST;
  for (int i = 0; i < NUM_REP; ++i){
      OMPVV_START_TIMER;
      #pragma omp target teams distribute parallel for if(0)
      for (int x = 0; x < 1024; ++x){
          OMPVV_TIMING_LOAD;
      }
      OMPVV_STOP_TIMER;
      OMPVV_REGISTER_TEST;
  }
  OMPVV_TIMER_RESULT("target teams distribute parallel for if(false)");

  //target teams distribute lastprivate
  OMPVV_INIT_TEST;
  for (int i = 0; i < NUM_REP; ++i){
      OMPVV_START_TIMER;
      #pragma omp target teams distribute parallel for lastprivate(a_map_var)
      for (int x = 0; x < 1024; ++x){
          a_map_var = 0;
          OMPVV_TIMING_LOAD;
      }
      OMPVV_STOP_TIMER;
      OMPVV_REGISTER_TEST;
  }
  OMPVV_TIMER_RESULT("target teams distribute parallel for lastprivate");

  //target teams distribute map(to)
  OMPVV_INIT_TEST;
  for (int i = 0; i < NUM_REP; ++i){
      OMPVV_START_TIMER;
      #pragma omp target teams distribute parallel for map(to: a_map_var)
      for (int x = 0; x < 1024; ++x){
          a_map_var = 0;
          OMPVV_TIMING_LOAD;
      }
      OMPVV_STOP_TIMER;
      OMPVV_REGISTER_TEST;
  }
  OMPVV_TIMER_RESULT("target teams distribute parallel for map(to)");

  //target teams distribute map(from)
  OMPVV_INIT_TEST;
  for (int i = 0; i < NUM_REP; ++i){
      OMPVV_START_TIMER;
      #pragma omp target teams distribute parallel for map(from: a_map_var)
      for (int x = 0; x < 1024; ++x){
          a_map_var = 0;
          OMPVV_TIMING_LOAD;
      }
      OMPVV_STOP_TIMER;
      OMPVV_REGISTER_TEST;
  }
  OMPVV_TIMER_RESULT("target teams distribute parallel for map(from)");

  //target teams distribute map(tofrom)
  OMPVV_INIT_TEST;
  for (int i = 0; i < NUM_REP; ++i){
      OMPVV_START_TIMER;
      #pragma omp target teams distribute parallel for map(tofrom: a_map_var)
      for (int x = 0; x < 1024; ++x){
          a_map_var = 0;
          OMPVV_TIMING_LOAD;
      }
      OMPVV_STOP_TIMER;
      OMPVV_REGISTER_TEST;
  }
  OMPVV_TIMER_RESULT("target teams distribute parallel for map(tofrom)");

  //target teams distribute map(alloc)
  OMPVV_INIT_TEST;
  for (int i = 0; i < NUM_REP; ++i){
      OMPVV_START_TIMER;
      #pragma omp target teams distribute parallel for map(alloc: a_map_var)
      for (int x = 0; x < 1024; ++x){
          a_map_var = 0;
          OMPVV_TIMING_LOAD;
      }
      OMPVV_STOP_TIMER;
      OMPVV_REGISTER_TEST;
  }
  OMPVV_TIMER_RESULT("target teams distribute parallel for map(alloc)");

  //target teams distribute private
  OMPVV_INIT_TEST;
  for (int i = 0; i < NUM_REP; ++i){
      OMPVV_START_TIMER;
      #pragma omp target teams distribute parallel for private(a_map_var)
      for (int x = 0; x < 1024; ++x){
          a_map_var = 0;
          OMPVV_TIMING_LOAD;
      }
      OMPVV_STOP_TIMER;
      OMPVV_REGISTER_TEST;
  }
  OMPVV_TIMER_RESULT("target teams distribute parallel for private");

  //target teams distribute shared
  OMPVV_INIT_TEST;
  for (int i = 0; i < NUM_REP; ++i){
      OMPVV_START_TIMER;
      #pragma omp target teams distribute parallel for shared(a_map_var)
      for (int x = 0; x < 1024; ++x){
          a_map_var = 0;
          OMPVV_TIMING_LOAD;
      }
      OMPVV_STOP_TIMER;
      OMPVV_REGISTER_TEST;
  }
  OMPVV_TIMER_RESULT("target teams distribute parallel for shared");

  return 0;
}
