import matplotlib.pyplot as plt
import pandas as pd

df = pd.read_csv('./data.csv', header=None)
plt.hist(df[0], bins=30)
plt.show()
