import numpy as np
import pandas as pd

excel_file = '//Users//suryaraj//Desktop/git//PythonProjects//SearchStringsUsingExcel//Pandas_Workbook.csv'
df = pd.read_csv(excel_file)
print(df)

print(df['Name'].where(df['Occupation'] == 'Programmer'))
programmers = df['Name'].where(df['Occupation'] == 'Programmer')
print(programmers.dropna())

excel_files = ['//Users//suryaraj//Desktop/git//PythonProjects//SearchStringsUsingExcel//Pandas_Workbook.csv','//Users//suryaraj//Desktop/git//PythonProjects//SearchStringsUsingExcel//Pandas_Workbook_copy.csv','//Users//suryaraj//Desktop/git//PythonProjects//SearchStringsUsingExcel//Pandas_Workbook_copy_2.csv']

for individual_excel_file in excel_files:
    df = pd.read_csv(individual_excel_file)
    programmers = df['Name'].where(df['Occupation'] == 'Programmer').dropna()
    print("File Name" + individual_excel_file)
    print(programmers)