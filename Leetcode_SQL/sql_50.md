### 1193. Monthly Transactions I
``` mysql
SELECT SUBSTR(trans_date,1,7) AS month,
        country,
        COUNT(id) AS trans_count,
        SUM(IF(state = "approved",1 ,0)) AS approved_count,
        SUM(amount) AS trans_total_amount,
        SUM(IF(state = "approved",amount ,0)) AS approved_total_amount
FROM Transactions
GROUP BY 1, 2
```

**提取日期的年，月：**
方法1：SUBSTR(trans_date,1,7) 
方法2：left(trans_date,7)
方法3：DATE_FORMAT(trans_date, '%Y-%m')
**count 内容为approved的数量**
用SUM和IF,IF判断内容为approved，就设置为1，total amount也是如此，如果为approved就设置为amount。

### 1174. Immediate Food Delivery II
``` mysql
SELECT ROUND(AVG(order_date = customer_pref_delivery_date)*100, 2) AS immediate_percentage
FROM Delivery
WHERE  (customer_id, order_date) IN(
                                SELECT customer_id,min(order_date)
                                FROM Delivery
                                GROUP BY 1
                                )
```
**思路**: 我们要在满足特定条件的数据中，再进行一次判断，最简便的方法就是在where里面把特定条件筛选出来。上面这一题用了subquary和in来筛选出特定条件的rows。

### 550. Game Play Analysis IV
``` mysql
SELECT ROUND(COUNT(DISTINCT player_id)/(SELECT COUNT(DISTINCT player_id) 
                                            FROM Activity) 
            , 2) AS fraction
FROM Activity
WHERE (player_id, DATE_SUB(event_date, INTERVAL 1 DAY)) IN(
                    SELECT player_id, MIN(event_date)
                    FROM Activity
                    GROUP BY 1)
```
**tips:**SELECT里面用一个subquary，这样可以获取两张表里的数据。
**日期隔一天的写法**：DATE_SUB(event_date, INTERVAL 1 DAY)
**方法2：用Join**
``` mysql
SELECT ROUND(COUNT(t2.player_id)/COUNT(t1.player_id),2) AS fraction
FROM
        (SELECT player_id, MIN(event_date) AS first_login 
        FROM Activity 
        GROUP BY player_id) t1 
LEFT JOIN Activity t2
        ON t1.player_id = t2.player_id 
        AND t1.first_login = t2.event_date - 1
```
**tips**: 一张表里是第一天登录的row，第二张表里是首次登陆的第二天的row，再通LEFT join合起来，select里的内容和上面一个方法一个意思。

### Interview Query July 11，Exam Scores
题目是一张表格是每个学生和四个考试成绩，column 1 student_id, column 2 student name, column 3, exam 1 score... 然后exam 2, 3, 4.要求是转化成一个学生和他的四个成绩为一row。
``` mysql
SELECT student_name,
        SUM(CASE WHEN exam_id = 1 THEN score ELSE NULL END) AS exam_1,
        SUM(CASE WHEN exam_id = 2 THEN score ELSE NULL END) AS exam_2,
        SUM(CASE WHEN exam_id = 3 THEN score ELSE NULL END) AS exam_3,
        SUM(CASE WHEN exam_id = 4 THEN score ELSE NULL END) AS exam_4
FROM exam_scores
GROUP BY student_id;
```
以上的方法使用了case when，因为需要每个学生在一个row里面，所以用了group by，而为了用group by，在select里面就需要用sum。
以下是使用if的方法，其他逻辑不变。
``` mysql
SELECT student_name,
  SUM(IF(exam_id=1, score, NULL)) AS exam_1,
  SUM(IF(exam_id=2, score, NULL)) AS exam_2,
  SUM(IF(exam_id=3, score, NULL)) AS exam_3,
  SUM(IF(exam_id=4, score, NULL)) AS exam_4
FROM exam_scores
GROUP BY student_id;
```
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

### Interview Query Empty Neighborhoods
![alt text](image.png)

``` mysql
SELECT name
FROM neighborhoods
WHERE id NOT IN (
    SELECT neighborhood_id
    FROM users
)
```
**TIPS**:上面的方法会好理解，两张表用NOT IN和一个subquery选出出现在一张图而不再第二张图的row，但是由于要query一边找出所有的id，所以不够有效率。以下的方法是用left join，应该是一个更efficient的方法。
``` mysql
SELECT n.name   
FROM neighborhoods AS n 
LEFT JOIN users AS u
    ON n.id = u.neighborhood_id
WHERE u.id IS NULL
```
LEFT JOIN会保留所有的左边表的row，在这里也就是neighborhoods。然后最后用where IS NULL来筛选出没有出现在右边表里的row。

### Interview Query Good Grades and Favorite Colors
![alt text](image-1.png)
``` python
import pandas as pd

def grades_colors(students_df):
    students_df = students_df[(students_df['grade']>90) &
        students_df['favorite_color'].isin(['red', 'green'])]
    return students_df
```
**tips**:def 和 return一起，[]表示df里取一部分，()可以说明and的优先级，也是isin()调用function。

### Interview Query Monthly Customer Report
![alt text](image-2.png)
``` mysql
SELECT MONTH(created_at) AS month,
    COUNT(DISTINCT user_id) AS num_customers,
    COUNT(DISTINCT t.id) AS num_orders,
    SUM(quantity*price) AS order_amt
FROM transactions t
LEFT JOIN products p
    ON t.product_id = p.id
WHERE YEAR(created_at) ='2020'
GROUP BY 1
```
### Interview Query Closest SAT Scores
![alt text](image-4.png)
``` mysql
SELECT s1.student AS one_student,
    s2.student AS other_student,
    ABS(s1.score - s2.score) AS score_diff
FROM scores s1
INNER JOIN scores s2
    WHERE s1.id != s2.id
    AND s1.id < s2.id
ORDER BY 3, 1
LIMIT 1
```
**如何cross join**
在这道题里面，我们要找成绩相差最小的两个学生，所以我们将所有学生两两配对。INNER JOIN scores s2 WHERE s1.id != s2.id
第二个重点，因为用上面这个方法同样两个人会出现两遍，所以用AND s1.id < s2.id来筛选出第一组，消除重复

### Interview Query Estimating D
**Question**：Given 𝑁 samples from a uniform distribution [0,𝑑], how would you estimate 𝑑?
**Answer** Because it's uniformly distribute, average of all the sample would close to the half of d, bigger sample size, more accurate result. Thus, the answer would be 2*AVG(n)


### Interview Query Employee Salaries
![alt text](image-5.png)
``` mysql
SELECT name AS department_name,
        AVG(CASE WHEN salary > 100000
            THEN 1 ELSE 0 END) AS percentage_over_100k,
        COUNT(DISTINCT e.id) AS number_of_employees
FROM departments d
LEFT JOIN employees e
    ON d.id = e.department_id
GROUP BY 1
HAVING COUNT(DISTINCT e.id) >= 10
ORDER BY 2 DESC
LIMIT 3
```
**tip:**最重要的一个，当要算percentage的时候，一定要想到case when，用AVG（0，1）来计算percentage。
这里筛选id人数大于10时用了count，所以必须在group后面，所以要用having。

### Interview Query Employee Salaries
![alt text](image-6.png)
``` mysql
SELECT name, IFNULL(SUM(distance),0) AS distance_traveled
FROM users u
LEFT JOIN rides r
    ON u.id = r.passenger_user_id
GROUP BY u.id
ORDER BY 2 DESC
```
**tips**可以注意一下这种问题怎么处理0，把null变成0会更准确。

### 1633.Percentage of Users Attended a Contest
``` mysql
SELECT contest_id,
        ROUND(COUNT(user_id)/(SELECT COUNT(user_id)
                        FROM Users)*100, 2) AS percentage
FROM Register
GROUP BY 1
ORDER BY 2 DESC, 1
```
**python方法**
``` python
total_users = users["user_id"].unique()

register_grouped = (
    register.groupby("contest_id")["user_id"]
    .nunique()
    .reset_index(name="count_unique_users")
)

register_grouped["percentage"] = (
    register_grouped["count_unique_users"] / total_users
) * 100

register_grouped["percentage"] = register_grouped["percentage"].round(2)
```
小注意事项，表里的column name要加引号。

### 1211. Queries Quality and Percentage
``` mysql
SELECT query_name, 
        ROUND(AVG(rating/position),2) AS quality,
        ROUND(AVG(CASE WHEN rating < 3 THEN 1 ELSE 0 END)*100,2) AS poor_query_percentage
FROM Queries
GROUP BY query_name
```
**方法2：用 window function**
``` mysql
SELECT DISTINCT query_name,
        ROUND(AVG(rating/position) OVER(PARTITION BY query_name), 2) AS quality,
        ROUND(AVG(CASE WHEN rating < 3 THEN 1 ELSE 0 END) OVER(PARTITION BY query_name)*100, 2) AS poor_query_percentage
FROM Queries
```
### 2356. Number of Unique Subjects Taught by Each Teacher
![alt text](image-7.png)
``` mysql
SELECT teacher_id, COUNT(DISTINCT subject_id) AS cnt
FROM Teacher
GROUP BY 1
```
比较简单的一道sql题，可以主要练习一下pandas做法。
``` python
teacher_grouped = (
    teacher.groupby("teacher_id")[subject_id]
    .unique()
    .reset_index(name = "cnt")
)
```
**.numique**出来是count的结果，直接**unique**出来是给一个list，包含了unique的结果。
下面是包装成function的写法：
``` python
def count_unique_subjects(teacher: pd.DataFrame) -> pd.DataFrame:
    # Group by teacher_id and count the number of unique subject_ids
    result = teacher.groupby('teacher_id')['subject_id'].nunique().reset_index()
    result.rename(columns={'subject_id': 'cnt'}, inplace=True)
    
    return result
```
OR
``` python
def count_unique_subjects(teacher: pd.DataFrame) -> pd.DataFrame:
    return teacher.groupby('teacher_id')['subject_id'].nunique().reset_index(name='cnt')
```

### 1141. User Activity for the Past 30 Days I
![alt text](image-8.png)
``` mysql
SELECT activity_date AS day, COUNT(DISTINCT user_id) AS active_users
FROM Activity
WHERE activity_date BETWEEN '2019-06-28' AND '2019-07-27'
GROUP BY 1
```
日期30天的另一种写法：BETWEEN date_add('2019-07-27' , INTERVAL -29 DAY) and '2019-07-27'
``` python
import pandas as pd

def user_activity(activity: pd.DataFrame) -> pd.DataFrame:

    return (activity[activity
                    .activity_date.between("2019-06-28", "2019-07-27")]

                    .rename(columns = {'activity_date': 'day',
                                       'user_id': 'active_users'})

                    .groupby('day')['active_users']
                    .nunique().reset_index())
```

### 1070. Product Sales Analysis III
``` mysql
SELECT product_id, year AS first_year, quantity, price
FROM Sales
WHERE (product_id, year) IN
                    (SELECT product_id, MIN(year) AS year
                    FROM Sales
                    GROUP BY 1)
```
