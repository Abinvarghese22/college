import numpy as np
import pandas as pd
from sklearn.model_selection import train_test_split
from sklearn.neighbors import KNeighborsClassifier
from sklearn.metrics import classification_report, accuracy_score

# Load the dataset
dataset = pd.read_csv("iris.csv", header=None)  # Assuming no header in the CSV
X = dataset.iloc[:, :-1].values
y = dataset.iloc[:, 4].values

# Split the dataset into training and test sets
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.20)

# Create and train the KNN classifier
classifier = KNeighborsClassifier(n_neighbors=5)
classifier.fit(X_train, y_train)

# Make predictions
y_pred = classifier.predict(X_test)

# Evaluate the model
print(classification_report(y_test, y_pred))
print("Accuracy : ", accuracy_score(y_test, y_pred))

# Create a DataFrame for comparison
df = pd.DataFrame({'Real Values': y_test, 'Predicted Values': y_pred})
print(df)

# Make a prediction on a new data point
new_test_point = np.array([[5.1, 3.5, 1.4, 0.2]])
prediction = classifier.predict(new_test_point)
print(f"\n Predicted class: {prediction[0]}")
