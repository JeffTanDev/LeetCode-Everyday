### Interview Query Pre-Launching Shows
Let’s say that you are working as a data scientist at Amazon Prime Video, and they are about to launch a new show, but first want to test the launch on only 10,000 customers first

How do we go about selecting the best 10,000 customers for the pre-launch?

What would the process look like for pre-launching the TV show on Amazon Prime to measure how it performs?
**Answer:**
To select the best 10,000 customers, the first things we wanna do is to recognizing our goals. 
**Step 1 recognizing our goals**
    1. Test the performance of the new show, eg.user engagement, viewer number, tecnical performance...
    2. estimate the impact of the show of the whole amazon prime users.
   
**Step 2 customer segmentation**
    1. If our goal is to test the performance of the new show, to get sufficient data, we can use historical data and choose the group people who are the target customer of this type of show. Within such group of people, we would like to randomly select from the whole group to avoid any bias.
    2. If our goal is to estimate the impact on whole prime users, we can use Strategy Sampling to make sure the sample could represent the who population.
   
**Step 3 A/B testing**
    1. after selecting our sample, we could conduct a A/B test, we would divide the 10,000 selected customers into control and test groups, and we will make sure the two group are independent.
   
**Step 4 metrics**
We would measure KPIs such as viewership numbers, engagement rates and technical performance. We could also conduct some survey to get some feedback.To compare the key performance indicators (KPIs) between the test group and the control group, we would use statistical tests such as z-test or t-test. These tests help us determine if there are significant differences in the metrics, providing insights into the show's potential success.

Define Comparison Method:
We would employ z-test or t-test to compare the KPIs such as viewership numbers, engagement rates, customer feedback, and technical performance between the test and control groups.

    Z-test: This test is suitable when we have a large sample size (n > 30) and the population variance is known. It helps in comparing the means of two groups.
    T-test: This test is used when the sample size is smaller (n <= 30) or the population variance is unknown. It also compares the means of two groups but is more appropriate for smaller samples.

### Interview Query Estimating D
**Question**：Given 𝑁 samples from a uniform distribution [0,𝑑], how would you estimate 𝑑?
**Answer** Because it's uniformly distribute, average of all the sample would close to the half of d, bigger sample size, more accurate result. Thus, the answer would be 2*AVG(n)

### Interview Query
**Question:**
Let’s say that you’re a data scientist working on the marketing team of a B2B SAAS business.

We’re nearing the end of the quarter and are missing revenue expectations by 10%. An executive asks the email marketing person to send out a huge email blast to your entire customer list asking them to buy more products.

Is this a good idea? Why or why not?

**Answer**
