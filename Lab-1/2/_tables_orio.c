/*@ begin PerfTuning (
 def build {
  arg build_command = 'gcc -O0';
 }
 def performance_counter {
  arg method = 'basic timer';
  arg repetitions = 10;
 }
 def performance_params {
  param UF[] = range(1,33);
 }

 def input_params {
  param N[] = [1000,10000000];
 }

 def input_vars {
  decl static double y[N] = random;
  decl double a1 = random;
  decl double a2 = random;
  decl double a3 = random;
  decl double a4 = random;
  decl static double x1[N] = random;
  decl static double x2[N] = random;
  decl static double x3[N] = random;
  decl static double x4[N] = random; 
}

 def search {
  arg algorithm = 'Randomsearch';
  arg time_limit = 10;
  arg total_runs = 10;
  }
) @*/
if ((N<=1000)) {

/**-- (Generated by Orio) 
Best performance cost: 
  [5.921e-06, 4.917e-06, 4.681e-06, 4.666e-06, 4.659e-06, 4.639e-06, 4.638e-06, 4.651e-06, 4.659e-06, 4.622e-06] 
Tuned for specific problem sizes: 
  N = 1000 
Best performance parameters: 
  UF = 8 
--**/


int i;

/*@ begin Loop ( 
    transform Unroll(ufactor=UF) 
    for (i=0; i<=N-1; i++)
      y[i] = a1*x1[i]*a2*x2[i] - a3*x3[i] - a4*x4[i];
) @*/
{
  for (int i = 0; i <= N - 8; i = i + 8) {
    y[i] = a1 * x1[i] * a2 * x2[i] - a3 * x3[i] - a4 * x4[i];
    y[(i + 1)] = a1 * x1[(i + 1)] * a2 * x2[(i + 1)] - a3 * x3[(i + 1)] - a4 * x4[(i + 1)];
    y[(i + 2)] = a1 * x1[(i + 2)] * a2 * x2[(i + 2)] - a3 * x3[(i + 2)] - a4 * x4[(i + 2)];
    y[(i + 3)] = a1 * x1[(i + 3)] * a2 * x2[(i + 3)] - a3 * x3[(i + 3)] - a4 * x4[(i + 3)];
    y[(i + 4)] = a1 * x1[(i + 4)] * a2 * x2[(i + 4)] - a3 * x3[(i + 4)] - a4 * x4[(i + 4)];
    y[(i + 5)] = a1 * x1[(i + 5)] * a2 * x2[(i + 5)] - a3 * x3[(i + 5)] - a4 * x4[(i + 5)];
    y[(i + 6)] = a1 * x1[(i + 6)] * a2 * x2[(i + 6)] - a3 * x3[(i + 6)] - a4 * x4[(i + 6)];
    y[(i + 7)] = a1 * x1[(i + 7)] * a2 * x2[(i + 7)] - a3 * x3[(i + 7)] - a4 * x4[(i + 7)];
  }
  for (int i = N - ((N - (0)) % 8); i <= N - 1; i = i + 1) 
    y[i] = a1 * x1[i] * a2 * x2[i] - a3 * x3[i] - a4 * x4[i];
}
/*@ end @*/

} else if ((N<=10000000)) {

/**-- (Generated by Orio) 
Best performance cost: 
  [0.0563972, 0.0500825, 0.0499018, 0.0486496, 0.0483722, 0.0448996, 0.0440151, 0.0448312, 0.0447317, 0.0446354] 
Tuned for specific problem sizes: 
  N = 10000000 
Best performance parameters: 
  UF = 8 
--**/


int i;

/*@ begin Loop ( 
    transform Unroll(ufactor=UF) 
    for (i=0; i<=N-1; i++)
      y[i] = a1*x1[i]*a2*x2[i] - a3*x3[i] - a4*x4[i];
) @*/
{
  for (int i = 0; i <= N - 8; i = i + 8) {
    y[i] = a1 * x1[i] * a2 * x2[i] - a3 * x3[i] - a4 * x4[i];
    y[(i + 1)] = a1 * x1[(i + 1)] * a2 * x2[(i + 1)] - a3 * x3[(i + 1)] - a4 * x4[(i + 1)];
    y[(i + 2)] = a1 * x1[(i + 2)] * a2 * x2[(i + 2)] - a3 * x3[(i + 2)] - a4 * x4[(i + 2)];
    y[(i + 3)] = a1 * x1[(i + 3)] * a2 * x2[(i + 3)] - a3 * x3[(i + 3)] - a4 * x4[(i + 3)];
    y[(i + 4)] = a1 * x1[(i + 4)] * a2 * x2[(i + 4)] - a3 * x3[(i + 4)] - a4 * x4[(i + 4)];
    y[(i + 5)] = a1 * x1[(i + 5)] * a2 * x2[(i + 5)] - a3 * x3[(i + 5)] - a4 * x4[(i + 5)];
    y[(i + 6)] = a1 * x1[(i + 6)] * a2 * x2[(i + 6)] - a3 * x3[(i + 6)] - a4 * x4[(i + 6)];
    y[(i + 7)] = a1 * x1[(i + 7)] * a2 * x2[(i + 7)] - a3 * x3[(i + 7)] - a4 * x4[(i + 7)];
  }
  for (int i = N - ((N - (0)) % 8); i <= N - 1; i = i + 1) 
    y[i] = a1 * x1[i] * a2 * x2[i] - a3 * x3[i] - a4 * x4[i];
}
/*@ end @*/

}
/*@ end @*/

