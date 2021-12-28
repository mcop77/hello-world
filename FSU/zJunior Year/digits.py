# Marshall Copeland
# mtc19a
# Due Date: 12/8/2021
# The program in this file is the individual work of Marshall Copeland

import matplotlib.pyplot as plt
import matplotlib as mpl
from sklearn import datasets
from sklearn.cluster import KMeans
import sklearn.metrics as sm
from sklearn.decomposition import PCA

import pandas as pd
import numpy as np


if __name__ == "__main__":
    digits = datasets.load_digits()

    x = pd.DataFrame(digits.data)
    pca = PCA(n_components=2)
    digits_components = pca.fit_transform(x)
    digits_DataFrame = pd.DataFrame(data = digits_components, 
    	columns = ['PC1', 'PC2'])

    y = pd.DataFrame(digits.target)
    y.columns = ['Targets']

    kmeans = KMeans(n_clusters=10)
    kmeans.fit(digits_DataFrame)

    colormap = np.array(["purple", "darkblue", "blue", "aqua", "lawngreen", "yellow", "black", "orange", "red", "darkred"])

    plt.scatter(digits_DataFrame.PC1,digits_DataFrame.PC2, c=colormap[kmeans.labels_], s=40)
    plt.show()
