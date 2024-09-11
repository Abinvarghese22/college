import matplotlib.pyplot as plt
import seaborn as sns
import pandas as pd
iris = pd.read_csv("iris.csv")
print("Shape of the data set:", iris.shape)
print("First five rows:")
print(iris.head())
print("**********************")
print("Last five rows:")
print(iris.tail())
print("Number Of Samples Available For Each Variety:")
print(iris["variety"].value_counts())
print("Description Of The Dataset:")
print(iris.describe())
sns.pairplot(iris, hue="variety", kind="scatter", diag_kind="hist")
plt.style.use("dark_background")
sns.histplot(iris["sepal_length"], bins=10, color="g")  
plt.title("Distribution Of Sepal Length", fontsize=10, color="white")
plt.show()

