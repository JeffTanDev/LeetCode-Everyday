## Tech problem
### talk about normal distribution
The normal distribution(also known as the Gaussian distribution) is a statistics and probability theory. It refers to a set of number distribute in a shape of bell curve and is symmetrical around its mean.

The normal distribution is defined by two parameters: the mean (μ) and the standard deviation (σ). The mean determines the center of the distribution, while the standard deviation measures the spread or dispersion of the data around the mean. In a normal distribution, about 68% of the data falls within one standard deviation of the mean, about 95% falls within two standard deviations, and about 99.7% falls within three standard deviations. This is known as the **Empirical Rule** or the 68-95-99.7 rule.

Another important theory is **Central Limit Theorem (CLT)**. The CLT states that if you take the sum or average of a large number of independent, identically distributed, random variables, the result will tend to be normally distributed, regardless of the original distribution of the variables. 也可以说：When the sample size increase, the distribution will tent to be normal.

### Talk about linear regression
Linear Regression is a statistical method used to model the relationship between a dependent variable and one or more independent variables by fitting a linear equation to observed data.  Linear regression helps you figure out how changes in 𝑋 are associated with changes in 𝑌.
For example, if we want to predict a person’s weight based on their height, linear regression will help us find the best straight line that tells us, "**for every centimeter increase in height, how much will the weight increase?"**

### What id Power Analysis
Power analysis is a way to figure out how many people or samples we need in a study to be sure we can detect an effect if there is one. It helps us plan our studies better so we don’t miss any real effects.

There are a few key parts to power analysis:
**Effect Size:** This tells us how big the difference we are looking for is. For example, in a drug test, it could be the difference in recovery rates between two groups.
**Significance Level (Alpha):** This is the cutoff for deciding if our results are real or just by chance. It's usually set at 0.05, meaning there's a 5% chance the results are due to random variation.
**Power:** This is the chance that our study will detect a real effect. We usually aim for 80% power, meaning there's an 80% chance of finding a true effect if it exists.
**Sample Size:** This is how many people or samples we need in our study. Power analysis helps us find the right number so our study is accurate.
For example, if we're testing a new medicine, power analysis tells us how many patients we need to include in our study to confidently see if the medicine works.

### What is K-mean and how do you select K?
K-means is a popular clustering algorithm used in unsupervised machine learning. It aims to partition a set of data points into K clusters, where each data point belongs to the cluster with the nearest mean. The algorithm works iteratively to assign data points to clusters and update the cluster centroids until the cluster don't change much.

It's not easy to get the optimal number of K. One common method is the Elbow Method, which involves running the K-means algorithm for a range of K values and plotting the within-cluster sum of squares (WCSS) or Sum of Squared Errors against K. The plot typically shows a clear 'elbow' point where the rate of decrease sharply slows, indicating the optimal K.

### What is feature vectors?
Feature vectors are numerical representations of data features. In machine learning and data science, feature vectors are used to describe the attributes or characteristics of the input data. They convert the data into a numerical format that models can process.
For example, suppose we have a database of houses, and each house has data such as area, number of bedrooms, number of bathrooms, and price. We can represent each house's data as a feature vector like area, number of bedrooms, number of bathrooms, price. Models can use these feature vectors for training and prediction.

### Explain the steps in making a decision tree
**1. Select the Best Feature:**
Identify the feature that best splits the data. This is typically done using criteria like Gini impurity, information gain, or chi-square, which measure the purity of the resulting subsets.
**2. Split the Data:**
Divide the dataset into subsets based on the selected feature. Each subset should ideally have a higher purity (i.e., be more homogeneous).
**3. Create Decision Nodes:**
For each subset, create a decision node that represents the feature used for the split and the corresponding condition.
**4. Repeat the Process:**
Recursively apply steps 1-3 to each subset. Continue splitting the data and creating nodes until one of the stopping criteria is met, such as reaching a maximum tree depth, having a subset with a single class, or having a subset too small to split further.
**5. Build Leaf Nodes:**
Once no further splits are possible or beneficial, create leaf nodes. These nodes represent the final output or prediction for the subset of data.

### explain cross-validation.
Cross-validation is a technique used to assess the performance and generalizability of a machine learning model. It involves the following steps:
**Split the Data:**
Divide the dataset into multiple subsets or "folds." A common approach is k-fold cross-validation, where the data is split into k equal-sized folds.
**Train and Validate:**
Train the model on k−1 folds and validate it on the remaining fold. Repeat this process k times, each time using a different fold as the validation set and the rest as the training set.
**Average the Results:**
Calculate the performance metric (e.g., accuracy, precision, recall) for each fold and then average these results. This provides an overall performance estimate of the model.

### A/B test


### What is S&OP?
The S&OP process is a cross-functional activity that integrates sales, supply chain, finance, and product management to create a cohesive operational plan. The goal is to balance demand and supply in a way that supports the company’s financial, marketing, and customer service objectives

typically involved several element:
Demand Plan, Supply Plan, Integration and Collaboration, review meeting.

### What are time series models? Why do we need them when we have less complicated regression models?
Time series models are specialized statistical models designed to analyze and forecast data points that are collected over time at regular intervals. Unlike standard regression models, which assume that observations are independent, time series models account for the fact that data points in a time series are often dependent on previous values (i.e., they have autocorrelation).

Key Differences and Why We Need Time Series Models:
**Temporal Dependence:** Time series data often exhibits trends, seasonality, or patterns over time, which regression models may not handle well because they assume independence between observations. Time series models like ARIMA, Exponential Smoothing, or Seasonal Decomposition explicitly account for these temporal patterns.

**Lag Features:** Time series models incorporate "lagged" values of the data, meaning they consider previous time steps when predicting future values. Regression models usually don't handle this lag structure effectively.

**Stationarity:** Many time series models deal with non-stationary data (where statistical properties change over time) by transforming the data (e.g., differencing). Traditional regression models typically require stationary data to produce reliable results.

**Forecasting:** Time series models are specifically designed for forecasting future data points based on historical trends, while regression models are generally used for understanding relationships between variables in a static context.
