import numpy as np
import pandas as pd
import seaborn as sns
import subprocess
from matplotlib import pyplot as plt


print("Fetching Data")
data_array__unoptimized = []
for i in range (0,10):
    data_array__unoptimized.append(int(subprocess.check_output(['./phods-unoptimized.o']).decode('utf-8')))



data_array__optimized = []
for i in range (0,10):
    data_array__optimized.append(int(subprocess.check_output(['./phods-optimized.o']).decode('utf-8')))



data_array__bestB = []
beta = subprocess.check_output(["./plotter_bestBeta.sh"]).decode('utf-8')
for i in range (0,10):
    data_array__bestB.append(int(subprocess.check_output(['./phods-beta.o',beta]).decode('utf-8')))



data_array__bestBxBy = []
betaX, betaY = subprocess.check_output(["./plotter_betax_betay.sh"]).decode('utf-8').split(" ")
for i in range (0,10):
    data_array__bestBxBy.append(int(subprocess.check_output(['./phods-bxy.o',betaX,betaY]).decode('utf-8')))



print("Fetching Done")


time_df_unoptimized = pd.DataFrame({'Time (usec)':data_array__unoptimized,'Mode':'unoptimized'})
time_df_optimized = pd.DataFrame({'Time (usec)':data_array__optimized,'Mode':'Optimized'})
time_df_bestB = pd.DataFrame({'Time (usec)':data_array__bestB,'Mode':'Optimized B: {}'.format(beta).replace("\n","")})
time_df_bestBxBy = pd.DataFrame({'Time (usec)':data_array__bestBxBy,'Mode':'Optimized Bx:{} By:{}'.format(betaX,betaY).replace("\n","")})

program_dataframe = pd.concat([time_df_unoptimized,time_df_optimized,time_df_bestB,time_df_bestBxBy],ignore_index=True)
sns.set()
sns.boxplot(data=program_dataframe, x="Time (usec)", y="Mode")
plt.show()