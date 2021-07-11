import matplotlib.pyplot as plt
import pandas as pd
import csv

headers = ['Time', 'Price']

df = pd.read_csv('RandomWalk.csv', names=headers)
print(df)

x = df['Time']
y = df['Price']

plt.plot(x, y)

plt.title('A simple Random Walk')

plt.xlabel('Time')
plt.ylabel('Price')

plt.show()
